/*
	Copyright 2016 Matt Williams/NitroGL
	Simple (?) OpenGL 3.3+ (CORE) Font/Text printing function
	Uses two VBOs, one for a single triangle strip making up
	a quad, the other contains instancing data for character
	position, texture altas lookup and color.
*/
#include "opengl.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "math.h"
#include "font.h"

// Font texture data, this does bloat the EXE quite a bit.
// This can also be external data.
#include "fontdata.h"

// Various shader/texture/VBO object IDs
unsigned int Font_Texture=0;
unsigned int Font_Shader=0;
unsigned int Font_Shader_Texture=0;
unsigned int Font_Shader_Viewport=0;
unsigned int Font_VBO=0;
unsigned int Font_Instanced=0;

// Initialization flag
unsigned char Font_Init=1;

// Window width/height from main app.
extern int Width, Height;

// Fragment shader source
// This is real simple, just sample texture into alpha channel with instance color
const char *FragmentSrc[]=
{
	"#version 330\n"
	"in vec2 UV;\n"
	"in vec3 Color;\n"
	"uniform sampler2D Texture;\n"
	"layout(location=0) out vec4 Output;\n"
	"void main()\n"
	"{\n"
		"Output=vec4(Color, texture(Texture, UV));\n"
	"}\n\0"
};

// Vertex shader source
const char *VertexSrc[]=
{
	"#version 330\n"
	"layout(location=0) in vec4 vVert;\n"			// Incoming vertex position
	"layout(location=1) in vec4 InstancePos;\n"		// Instanced data position
	"layout(location=2) in vec3 InstanceColor;\n"	// Instanced data color
	"uniform ivec2 Viewport;\n"		// Window width/height
	"out vec2 UV;\n"		// Output texture coords
	"out vec3 Color;\n"		// Output color
	"void main()\n"
	"{\n"
		"gl_Position=vec4((vVert.xy+InstancePos.xy)/(Viewport*0.5)-1, -1.0, 1.0);\n"	// Transform vertex from window coords to NDC
		"UV=vVert.zw+InstancePos.zw;\n"		// Offset texture coords to position in texture atlas
		"Color=InstanceColor;\n"			// Pass color
	"}\n\0"
};

void Font_Print(float x, float y, char *string, ...)
{
	// float pointer for VBO mappings (both vertex and instance data)
	float *verts=NULL;
	// pointer and buffer for formatted text
	char *ptr, text[4096];
	// variable arguments list
	va_list	ap;
	// some misc variables
	int sx=(int)x, numchar, i;
	// current text color
	float r=1.0f, g=1.0f, b=1.0f;

	// Check if the string is even valid first
	if(string==NULL)
		return;

	// Format string, including variable arguments
	va_start(ap, string);
	vsprintf(text, string, ap);
	va_end(ap);

	// Find how many characters were need to deal with
	numchar=strlen(text);

	// Generate texture, shaders, etc once
	if(Font_Init)
	{
		GLuint Vertex, Fragment;
		GLint Status;

		// Upload font texture data, single 8bit red, no longer have alpha texture support :(
		glGenTextures(1, &Font_Texture);
		glBindTexture(GL_TEXTURE_2D, Font_Texture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_R8, 256, 256, 0, GL_RED, GL_UNSIGNED_BYTE, _FontData);

		// Load and compile GLSL shaders, get uniform locations
		Font_Shader=glCreateProgram();

		Vertex=glCreateShader(GL_VERTEX_SHADER);

		glShaderSource(Vertex, 1, (const char **)&VertexSrc, NULL);

		glCompileShader(Vertex);
		glGetShaderiv(Vertex, GL_COMPILE_STATUS, &Status);

		if(Status)
			glAttachShader(Font_Shader, Vertex);

		glDeleteShader(Vertex);

		Fragment=glCreateShader(GL_FRAGMENT_SHADER);

		glShaderSource(Fragment, 1, (const char **)&FragmentSrc, NULL);

		glCompileShader(Fragment);
		glGetShaderiv(Fragment, GL_COMPILE_STATUS, &Status);

		if(Status)
			glAttachShader(Font_Shader, Fragment);

		glDeleteShader(Fragment);

		glLinkProgram(Font_Shader);
		glGetProgramiv(Font_Shader, GL_LINK_STATUS, &Status);

		if(!Status)
			return;

		glUseProgram(Font_Shader);
		Font_Shader_Texture=glGetUniformLocation(Font_Shader, "Texture");
		Font_Shader_Viewport=glGetUniformLocation(Font_Shader, "Viewport");

		// Build triangle strip for the font quad
		// 4 floats per vertex, 4 vertices
		glGenBuffers(1, &Font_VBO);
		glBindBuffer(GL_ARRAY_BUFFER, Font_VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(float)*4*4, NULL, GL_STATIC_DRAW);

		// Map the buffer to avoid system memory transfers
		verts=(float *)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);

		if(verts==NULL)
			return;

		// Since this is only 2D data, just using a single attrib with 4 floats is enough
		*verts++=4.0f;		// X
		*verts++=16.0f;		// Y
		*verts++=0.0125f;	// U
		*verts++=0.0f;		// V

		*verts++=4.0f;
		*verts++=0.0f;
		*verts++=0.0125f;
		*verts++=-0.0625f;

		*verts++=12.0f;
		*verts++=16.0f;
		*verts++=0.05f;
		*verts++=0.0f;

		*verts++=12.0f;
		*verts++=0.0f;
		*verts++=0.05f;
		*verts++=-0.0625f;

		// Unmap buffer
		glUnmapBuffer(GL_ARRAY_BUFFER);

		// Allocate buffer for instance data
		glGenBuffers(1, &Font_Instanced);
		glBindBuffer(GL_ARRAY_BUFFER, Font_Instanced);
		glBufferData(GL_ARRAY_BUFFER, sizeof(float)*7*numchar, NULL, GL_DYNAMIC_DRAW);

		// Done with init
		Font_Init=0;
	}

	// Update instance data
	glBindBuffer(GL_ARRAY_BUFFER, Font_Instanced);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float)*7*numchar, NULL, GL_DYNAMIC_DRAW);
	verts=(float *)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);

	if(verts==NULL)
		return;

	// Loop through the text string until EOL
	for(ptr=text, i=0;*ptr!='\0';ptr++)
	{
		// Decrement 'y' for any CR's
		if(*ptr=='\n')
		{
			x=(float)sx;
			y-=12;
			continue;
		}

		// Just advance spaces instead of rendering empty quads
		if(*ptr==' ')
		{
			x+=8;
			numchar--;
			continue;
		}

		// ANSI color escape codes
		// I'm sure there's a better way to do this!
		// But it works, so whatever.
		if(*ptr=='\x1B')
		{
			ptr++;
			     if(*(ptr+0)=='['&&*(ptr+1)=='3'&&*(ptr+2)=='0'&&*(ptr+3)=='m')	{	r=0.0f;	g=0.0f;	b=0.0f;	}	// BLACK
			else if(*(ptr+0)=='['&&*(ptr+1)=='3'&&*(ptr+2)=='1'&&*(ptr+3)=='m')	{	r=0.5f;	g=0.0f;	b=0.0f;	}	// DARK RED
			else if(*(ptr+0)=='['&&*(ptr+1)=='3'&&*(ptr+2)=='2'&&*(ptr+3)=='m')	{	r=0.0f;	g=0.5f;	b=0.0f;	}	// DARK GREEN
			else if(*(ptr+0)=='['&&*(ptr+1)=='3'&&*(ptr+2)=='3'&&*(ptr+3)=='m')	{	r=0.5f;	g=0.5f;	b=0.0f;	}	// DARK YELLOW
			else if(*(ptr+0)=='['&&*(ptr+1)=='3'&&*(ptr+2)=='4'&&*(ptr+3)=='m')	{	r=0.0f;	g=0.0f;	b=0.5f;	}	// DARK BLUE
			else if(*(ptr+0)=='['&&*(ptr+1)=='3'&&*(ptr+2)=='5'&&*(ptr+3)=='m')	{	r=0.5f;	g=0.0f;	b=0.5f;	}	// DARK MAGENTA
			else if(*(ptr+0)=='['&&*(ptr+1)=='3'&&*(ptr+2)=='6'&&*(ptr+3)=='m')	{	r=0.0f;	g=0.5f;	b=0.5f;	}	// DARK CYAN
			else if(*(ptr+0)=='['&&*(ptr+1)=='3'&&*(ptr+2)=='7'&&*(ptr+3)=='m')	{	r=0.5f;	g=0.5f;	b=0.5f;	}	// GREY
			else if(*(ptr+0)=='['&&*(ptr+1)=='9'&&*(ptr+2)=='0'&&*(ptr+3)=='m')	{	r=0.5f;	g=0.5f;	b=0.5f;	}	// GREY
			else if(*(ptr+0)=='['&&*(ptr+1)=='9'&&*(ptr+2)=='1'&&*(ptr+3)=='m')	{	r=1.0f;	g=0.0f;	b=0.0f;	}	// RED
			else if(*(ptr+0)=='['&&*(ptr+1)=='9'&&*(ptr+2)=='2'&&*(ptr+3)=='m')	{	r=0.0f;	g=1.0f;	b=0.0f;	}	// GREEN
			else if(*(ptr+0)=='['&&*(ptr+1)=='9'&&*(ptr+2)=='3'&&*(ptr+3)=='m')	{	r=1.0f;	g=1.0f;	b=0.0f;	}	// YELLOW
			else if(*(ptr+0)=='['&&*(ptr+1)=='9'&&*(ptr+2)=='4'&&*(ptr+3)=='m')	{	r=0.0f;	g=0.0f;	b=1.0f;	}	// BLUE
			else if(*(ptr+0)=='['&&*(ptr+1)=='9'&&*(ptr+2)=='5'&&*(ptr+3)=='m')	{	r=1.0f;	g=0.0f;	b=1.0f;	}	// MAGENTA
			else if(*(ptr+0)=='['&&*(ptr+1)=='9'&&*(ptr+2)=='6'&&*(ptr+3)=='m')	{	r=0.0f;	g=1.0f;	b=1.0f;	}	// CYAN
			else if(*(ptr+0)=='['&&*(ptr+1)=='9'&&*(ptr+2)=='7'&&*(ptr+3)=='m')	{	r=1.0f;	g=1.0f;	b=1.0f;	}	// WHITE
			ptr+=4;
		}

		// Emit position, atlas offset, and color for this character
		*verts++=x;
		*verts++=y;
		*verts++=     (float)(*ptr%16)*0.0625f;
		*verts++=1.0f-(float)(*ptr/16)*0.0625f;
		*verts++=r;
		*verts++=g;
		*verts++=b;

		// Advance one character
		x+=8;
	}

	// Unmap instance data buffer
	glUnmapBuffer(GL_ARRAY_BUFFER);

	// Set program and uniforms
	glUseProgram(Font_Shader);
	glUniform1i(Font_Shader_Texture, 0);
	glUniform2i(Font_Shader_Viewport, Width, Height);

	// Bind texture
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, Font_Texture);

	// Bind quad VBO
	glBindBuffer(GL_ARRAY_BUFFER, Font_VBO);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, (void *)0);
	glEnableVertexAttribArray(0);

	// Bind/set instance data
	glBindBuffer(GL_ARRAY_BUFFER, Font_Instanced);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(float)*7, (char *)0);
	glVertexAttribDivisor(1, 1);
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(float)*7, (char *)(0+sizeof(float)*4));
	glVertexAttribDivisor(2, 1);
	glEnableVertexAttribArray(2);

	// Draw characters!
	glDrawArraysInstanced(GL_TRIANGLE_STRIP, 0, 4, numchar);

	// Unset
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glVertexAttribDivisor(1, 0);
	glVertexAttribDivisor(2, 0);
}
