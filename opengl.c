#include "opengl.h"
#include <stdio.h>
#include <string.h>

#ifdef __linux__
extern Display *dpy;
#endif

#ifdef WIN32
GLboolean WGL_ARB_create_context_Flag=0;
HGLRC (WINAPI *wglCreateContextAttribsARB)(HDC hDC, HGLRC hShareContext, const int *attribList)=NULL;

GLboolean WGL_ARB_create_context_profile_Flag=0;

GLboolean WGL_ARB_create_context_robustness_Flag=0;

GLboolean WGL_ARB_extensions_string_Flag=0;
const char *(WINAPI *wglGetExtensionsStringARB)(HDC hdc)=NULL;

GLboolean WGL_ARB_framebuffer_sRGB_Flag=0;

GLboolean WGL_ARB_make_current_read_Flag=0;

GLboolean WGL_ARB_multisample_Flag=0;

BOOL (WINAPI *wglMakeContextCurrentARB)(HDC hDrawDC, HDC hReadDC, HGLRC hglrc)=NULL;
HDC (WINAPI *wglGetCurrentReadDCARB)(void)=NULL;

GLboolean WGL_ARB_pixel_format_Flag=0;
BOOL (WINAPI *wglGetPixelFormatAttribivARB)(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int *piAttributes, int *piValues)=NULL;
BOOL (WINAPI *wglGetPixelFormatAttribfvARB)(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int *piAttributes, FLOAT *pfValues)=NULL;
BOOL (WINAPI *wglChoosePixelFormatARB)(HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats)=NULL;
#else
GLXContext (APIENTRY *glXCreateContextAttribsARB)(Display *dpy, GLXFBConfig config, GLXContext share_context, Bool direct, const int *attrib_list)=NULL;

GLboolean GLX_ARB_create_context_Flag=0;

GLboolean GLX_ARB_create_context_profile_Flag=0;

GLboolean GLX_ARB_create_context_robustness_Flag=0;

GLboolean GLX_ARB_framebuffer_sRGB_Flag=0;

GLboolean GLX_ARB_multisample_Flag=0;
#endif

/* Already defined by opengl32.lib
GLvoid (APIENTRY *glCullFace)(GLenum mode)=NULL;
GLvoid (APIENTRY *glFrontFace)(GLenum mode)=NULL;
GLvoid (APIENTRY *glHint)(GLenum target, GLenum mode)=NULL;
GLvoid (APIENTRY *glLineWidth)(GLfloat width)=NULL;
GLvoid (APIENTRY *glPointSize)(GLfloat size)=NULL;
GLvoid (APIENTRY *glPolygonMode)(GLenum face, GLenum mode)=NULL;
GLvoid (APIENTRY *glScissor)(GLint x, GLint y, GLsizei width, GLsizei height)=NULL;
GLvoid (APIENTRY *glTexParameterf)(GLenum target, GLenum pname, GLfloat param)=NULL;
GLvoid (APIENTRY *glTexParameterfv)(GLenum target, GLenum pname, const GLfloat *params)=NULL;
GLvoid (APIENTRY *glTexParameteri)(GLenum target, GLenum pname, GLint param)=NULL;
GLvoid (APIENTRY *glTexParameteriv)(GLenum target, GLenum pname, const GLint *params)=NULL;
GLvoid (APIENTRY *glTexImage1D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels)=NULL;
GLvoid (APIENTRY *glTexImage2D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels)=NULL;
GLvoid (APIENTRY *glDrawBuffer)(GLenum buf)=NULL;
GLvoid (APIENTRY *glClear)(GLbitfield mask)=NULL;
GLvoid (APIENTRY *glClearColor)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)=NULL;
GLvoid (APIENTRY *glClearStencil)(GLint s)=NULL;
GLvoid (APIENTRY *glClearDepth)(GLdouble depth)=NULL;
GLvoid (APIENTRY *glStencilMask)(GLuint mask)=NULL;
GLvoid (APIENTRY *glColorMask)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha)=NULL;
GLvoid (APIENTRY *glDepthMask)(GLboolean flag)=NULL;
GLvoid (APIENTRY *glDisable)(GLenum cap)=NULL;
GLvoid (APIENTRY *glEnable)(GLenum cap)=NULL;
GLvoid (APIENTRY *glFinish)(GLvoid);
GLvoid (APIENTRY *glFlush)(GLvoid);
GLvoid (APIENTRY *glBlendFunc)(GLenum sfactor, GLenum dfactor)=NULL;
GLvoid (APIENTRY *glLogicOp)(GLenum opcode)=NULL;
GLvoid (APIENTRY *glStencilFunc)(GLenum func, GLint ref, GLuint mask)=NULL;
GLvoid (APIENTRY *glStencilOp)(GLenum fail, GLenum zfail, GLenum zpass)=NULL;
GLvoid (APIENTRY *glDepthFunc)(GLenum func)=NULL;
GLvoid (APIENTRY *glPixelStoref)(GLenum pname, GLfloat param)=NULL;
GLvoid (APIENTRY *glPixelStorei)(GLenum pname, GLint param)=NULL;
GLvoid (APIENTRY *glReadBuffer)(GLenum src)=NULL;
GLvoid (APIENTRY *glReadPixels)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels)=NULL;
GLvoid (APIENTRY *glGetBooleanv)(GLenum pname, GLboolean *data)=NULL;
GLvoid (APIENTRY *glGetDoublev)(GLenum pname, GLdouble *data)=NULL;
GLenum (APIENTRY *glGetError)(GLvoid);
GLvoid (APIENTRY *glGetFloatv)(GLenum pname, GLfloat *data)=NULL;
GLvoid (APIENTRY *glGetIntegerv)(GLenum pname, GLint *data)=NULL;
const GLubyte *(APIENTRY *glGetString)(GLenum name)=NULL;
GLvoid (APIENTRY *glGetTexImage)(GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels)=NULL;
GLvoid (APIENTRY *glGetTexParameterfv)(GLenum target, GLenum pname, GLfloat *params)=NULL;
GLvoid (APIENTRY *glGetTexParameteriv)(GLenum target, GLenum pname, GLint *params)=NULL;
GLvoid (APIENTRY *glGetTexLevelParameterfv)(GLenum target, GLint level, GLenum pname, GLfloat *params)=NULL;
GLvoid (APIENTRY *glGetTexLevelParameteriv)(GLenum target, GLint level, GLenum pname, GLint *params)=NULL;
GLboolean (APIENTRY *glIsEnabled)(GLenum cap)=NULL;
GLvoid (APIENTRY *glDepthRange)(GLdouble near, GLdouble far)=NULL;
GLvoid (APIENTRY *glViewport)(GLint x, GLint y, GLsizei width, GLsizei height)=NULL;
GLvoid (APIENTRY *glDrawArrays)(GLenum mode, GLint first, GLsizei count)=NULL;
GLvoid (APIENTRY *glDrawElements)(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices)=NULL;
GLvoid (APIENTRY *glGetPointerv)(GLenum pname, GLvoid **params)=NULL;
GLvoid (APIENTRY *glPolygonOffset)(GLfloat factor, GLfloat units)=NULL;
GLvoid (APIENTRY *glCopyTexImage1D)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border)=NULL;
GLvoid (APIENTRY *glCopyTexImage2D)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border)=NULL;
GLvoid (APIENTRY *glCopyTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width)=NULL;
GLvoid (APIENTRY *glCopyTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height)=NULL;
GLvoid (APIENTRY *glTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels)=NULL;
GLvoid (APIENTRY *glTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels)=NULL;
GLvoid (APIENTRY *glBindTexture)(GLenum target, GLuint texture)=NULL;
GLvoid (APIENTRY *glDeleteTextures)(GLsizei n, const GLuint *textures)=NULL;
GLvoid (APIENTRY *glGenTextures)(GLsizei n, GLuint *textures)=NULL;
GLboolean (APIENTRY *glIsTexture)(GLuint texture)=NULL;*/
GLvoid (APIENTRY *glDrawRangeElements)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices)=NULL;
GLvoid (APIENTRY *glTexImage3D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels)=NULL;
GLvoid (APIENTRY *glTexSubImage3D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels)=NULL;
GLvoid (APIENTRY *glCopyTexSubImage3D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height)=NULL;
GLvoid (APIENTRY *glActiveTexture)(GLenum texture)=NULL;
GLvoid (APIENTRY *glSampleCoverage)(GLfloat value, GLboolean invert)=NULL;
GLvoid (APIENTRY *glCompressedTexImage3D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *data)=NULL;
GLvoid (APIENTRY *glCompressedTexImage2D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data)=NULL;
GLvoid (APIENTRY *glCompressedTexImage1D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *data)=NULL;
GLvoid (APIENTRY *glCompressedTexSubImage3D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data)=NULL;
GLvoid (APIENTRY *glCompressedTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data)=NULL;
GLvoid (APIENTRY *glCompressedTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *data)=NULL;
GLvoid (APIENTRY *glGetCompressedTexImage)(GLenum target, GLint level, GLvoid *img)=NULL;
GLvoid (APIENTRY *glBlendFuncSeparate)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha)=NULL;
GLvoid (APIENTRY *glMultiDrawArrays)(GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount)=NULL;
GLvoid (APIENTRY *glMultiDrawElements)(GLenum mode, const GLsizei *count, GLenum type, const GLvoid *const*indices, GLsizei drawcount)=NULL;
GLvoid (APIENTRY *glPointParameterf)(GLenum pname, GLfloat param)=NULL;
GLvoid (APIENTRY *glPointParameterfv)(GLenum pname, const GLfloat *params)=NULL;
GLvoid (APIENTRY *glPointParameteri)(GLenum pname, GLint param)=NULL;
GLvoid (APIENTRY *glPointParameteriv)(GLenum pname, const GLint *params)=NULL;
GLvoid (APIENTRY *glBlendColor)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)=NULL;
GLvoid (APIENTRY *glBlendEquation)(GLenum mode)=NULL;
GLvoid (APIENTRY *glGenQueries)(GLsizei n, GLuint *ids)=NULL;
GLvoid (APIENTRY *glDeleteQueries)(GLsizei n, const GLuint *ids)=NULL;
GLboolean (APIENTRY *glIsQuery)(GLuint id)=NULL;
GLvoid (APIENTRY *glBeginQuery)(GLenum target, GLuint id)=NULL;
GLvoid (APIENTRY *glEndQuery)(GLenum target)=NULL;
GLvoid (APIENTRY *glGetQueryiv)(GLenum target, GLenum pname, GLint *params)=NULL;
GLvoid (APIENTRY *glGetQueryObjectiv)(GLuint id, GLenum pname, GLint *params)=NULL;
GLvoid (APIENTRY *glGetQueryObjectuiv)(GLuint id, GLenum pname, GLuint *params)=NULL;
GLvoid (APIENTRY *glBindBuffer)(GLenum target, GLuint buffer)=NULL;
GLvoid (APIENTRY *glDeleteBuffers)(GLsizei n, const GLuint *buffers)=NULL;
GLvoid (APIENTRY *glGenBuffers)(GLsizei n, GLuint *buffers)=NULL;
GLboolean (APIENTRY *glIsBuffer)(GLuint buffer)=NULL;
GLvoid (APIENTRY *glBufferData)(GLenum target, GLsizeiptr size, const GLvoid *data, GLenum usage)=NULL;
GLvoid (APIENTRY *glBufferSubData)(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid *data)=NULL;
GLvoid (APIENTRY *glGetBufferSubData)(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid *data)=NULL;
GLvoid *(APIENTRY *glMapBuffer)(GLenum target, GLenum access)=NULL;
GLboolean (APIENTRY *glUnmapBuffer)(GLenum target)=NULL;
GLvoid (APIENTRY *glGetBufferParameteriv)(GLenum target, GLenum pname, GLint *params)=NULL;
GLvoid (APIENTRY *glGetBufferPointerv)(GLenum target, GLenum pname, GLvoid **params)=NULL;
GLvoid (APIENTRY *glBlendEquationSeparate)(GLenum modeRGB, GLenum modeAlpha)=NULL;
GLvoid (APIENTRY *glDrawBuffers)(GLsizei n, const GLenum *bufs)=NULL;
GLvoid (APIENTRY *glStencilOpSeparate)(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass)=NULL;
GLvoid (APIENTRY *glStencilFuncSeparate)(GLenum face, GLenum func, GLint ref, GLuint mask)=NULL;
GLvoid (APIENTRY *glStencilMaskSeparate)(GLenum face, GLuint mask)=NULL;
GLvoid (APIENTRY *glAttachShader)(GLuint program, GLuint shader)=NULL;
GLvoid (APIENTRY *glBindAttribLocation)(GLuint program, GLuint index, const GLchar *name)=NULL;
GLvoid (APIENTRY *glCompileShader)(GLuint shader)=NULL;
GLuint (APIENTRY *glCreateProgram)(GLvoid);
GLuint (APIENTRY *glCreateShader)(GLenum type)=NULL;
GLvoid (APIENTRY *glDeleteProgram)(GLuint program)=NULL;
GLvoid (APIENTRY *glDeleteShader)(GLuint shader)=NULL;
GLvoid (APIENTRY *glDetachShader)(GLuint program, GLuint shader)=NULL;
GLvoid (APIENTRY *glDisableVertexAttribArray)(GLuint index)=NULL;
GLvoid (APIENTRY *glEnableVertexAttribArray)(GLuint index)=NULL;
GLvoid (APIENTRY *glGetActiveAttrib)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name)=NULL;
GLvoid (APIENTRY *glGetActiveUniform)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name)=NULL;
GLvoid (APIENTRY *glGetAttachedShaders)(GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders)=NULL;
GLint (APIENTRY *glGetAttribLocation)(GLuint program, const GLchar *name)=NULL;
GLvoid (APIENTRY *glGetProgramiv)(GLuint program, GLenum pname, GLint *params)=NULL;
GLvoid (APIENTRY *glGetProgramInfoLog)(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog)=NULL;
GLvoid (APIENTRY *glGetShaderiv)(GLuint shader, GLenum pname, GLint *params)=NULL;
GLvoid (APIENTRY *glGetShaderInfoLog)(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog)=NULL;
GLvoid (APIENTRY *glGetShaderSource)(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source)=NULL;
GLint (APIENTRY *glGetUniformLocation)(GLuint program, const GLchar *name)=NULL;
GLvoid (APIENTRY *glGetUniformfv)(GLuint program, GLint location, GLfloat *params)=NULL;
GLvoid (APIENTRY *glGetUniformiv)(GLuint program, GLint location, GLint *params)=NULL;
GLvoid (APIENTRY *glGetVertexAttribdv)(GLuint index, GLenum pname, GLdouble *params)=NULL;
GLvoid (APIENTRY *glGetVertexAttribfv)(GLuint index, GLenum pname, GLfloat *params)=NULL;
GLvoid (APIENTRY *glGetVertexAttribiv)(GLuint index, GLenum pname, GLint *params)=NULL;
GLvoid (APIENTRY *glGetVertexAttribPointerv)(GLuint index, GLenum pname, GLvoid **pointer)=NULL;
GLboolean (APIENTRY *glIsProgram)(GLuint program)=NULL;
GLboolean (APIENTRY *glIsShader)(GLuint shader)=NULL;
GLvoid (APIENTRY *glLinkProgram)(GLuint program)=NULL;
GLvoid (APIENTRY *glShaderSource)(GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length)=NULL;
GLvoid (APIENTRY *glUseProgram)(GLuint program)=NULL;
GLvoid (APIENTRY *glUniform1f)(GLint location, GLfloat v0)=NULL;
GLvoid (APIENTRY *glUniform2f)(GLint location, GLfloat v0, GLfloat v1)=NULL;
GLvoid (APIENTRY *glUniform3f)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2)=NULL;
GLvoid (APIENTRY *glUniform4f)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3)=NULL;
GLvoid (APIENTRY *glUniform1i)(GLint location, GLint v0)=NULL;
GLvoid (APIENTRY *glUniform2i)(GLint location, GLint v0, GLint v1)=NULL;
GLvoid (APIENTRY *glUniform3i)(GLint location, GLint v0, GLint v1, GLint v2)=NULL;
GLvoid (APIENTRY *glUniform4i)(GLint location, GLint v0, GLint v1, GLint v2, GLint v3)=NULL;
GLvoid (APIENTRY *glUniform1fv)(GLint location, GLsizei count, const GLfloat *value)=NULL;
GLvoid (APIENTRY *glUniform2fv)(GLint location, GLsizei count, const GLfloat *value)=NULL;
GLvoid (APIENTRY *glUniform3fv)(GLint location, GLsizei count, const GLfloat *value)=NULL;
GLvoid (APIENTRY *glUniform4fv)(GLint location, GLsizei count, const GLfloat *value)=NULL;
GLvoid (APIENTRY *glUniform1iv)(GLint location, GLsizei count, const GLint *value)=NULL;
GLvoid (APIENTRY *glUniform2iv)(GLint location, GLsizei count, const GLint *value)=NULL;
GLvoid (APIENTRY *glUniform3iv)(GLint location, GLsizei count, const GLint *value)=NULL;
GLvoid (APIENTRY *glUniform4iv)(GLint location, GLsizei count, const GLint *value)=NULL;
GLvoid (APIENTRY *glUniformMatrix2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)=NULL;
GLvoid (APIENTRY *glUniformMatrix3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)=NULL;
GLvoid (APIENTRY *glUniformMatrix4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)=NULL;
GLvoid (APIENTRY *glValidateProgram)(GLuint program)=NULL;
GLvoid (APIENTRY *glVertexAttrib1d)(GLuint index, GLdouble x)=NULL;
GLvoid (APIENTRY *glVertexAttrib1dv)(GLuint index, const GLdouble *v)=NULL;
GLvoid (APIENTRY *glVertexAttrib1f)(GLuint index, GLfloat x)=NULL;
GLvoid (APIENTRY *glVertexAttrib1fv)(GLuint index, const GLfloat *v)=NULL;
GLvoid (APIENTRY *glVertexAttrib1s)(GLuint index, GLshort x)=NULL;
GLvoid (APIENTRY *glVertexAttrib1sv)(GLuint index, const GLshort *v)=NULL;
GLvoid (APIENTRY *glVertexAttrib2d)(GLuint index, GLdouble x, GLdouble y)=NULL;
GLvoid (APIENTRY *glVertexAttrib2dv)(GLuint index, const GLdouble *v)=NULL;
GLvoid (APIENTRY *glVertexAttrib2f)(GLuint index, GLfloat x, GLfloat y)=NULL;
GLvoid (APIENTRY *glVertexAttrib2fv)(GLuint index, const GLfloat *v)=NULL;
GLvoid (APIENTRY *glVertexAttrib2s)(GLuint index, GLshort x, GLshort y)=NULL;
GLvoid (APIENTRY *glVertexAttrib2sv)(GLuint index, const GLshort *v)=NULL;
GLvoid (APIENTRY *glVertexAttrib3d)(GLuint index, GLdouble x, GLdouble y, GLdouble z)=NULL;
GLvoid (APIENTRY *glVertexAttrib3dv)(GLuint index, const GLdouble *v)=NULL;
GLvoid (APIENTRY *glVertexAttrib3f)(GLuint index, GLfloat x, GLfloat y, GLfloat z)=NULL;
GLvoid (APIENTRY *glVertexAttrib3fv)(GLuint index, const GLfloat *v)=NULL;
GLvoid (APIENTRY *glVertexAttrib3s)(GLuint index, GLshort x, GLshort y, GLshort z)=NULL;
GLvoid (APIENTRY *glVertexAttrib3sv)(GLuint index, const GLshort *v)=NULL;
GLvoid (APIENTRY *glVertexAttrib4Nbv)(GLuint index, const GLbyte *v)=NULL;
GLvoid (APIENTRY *glVertexAttrib4Niv)(GLuint index, const GLint *v)=NULL;
GLvoid (APIENTRY *glVertexAttrib4Nsv)(GLuint index, const GLshort *v)=NULL;
GLvoid (APIENTRY *glVertexAttrib4Nub)(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w)=NULL;
GLvoid (APIENTRY *glVertexAttrib4Nubv)(GLuint index, const GLubyte *v)=NULL;
GLvoid (APIENTRY *glVertexAttrib4Nuiv)(GLuint index, const GLuint *v)=NULL;
GLvoid (APIENTRY *glVertexAttrib4Nusv)(GLuint index, const GLushort *v)=NULL;
GLvoid (APIENTRY *glVertexAttrib4bv)(GLuint index, const GLbyte *v)=NULL;
GLvoid (APIENTRY *glVertexAttrib4d)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w)=NULL;
GLvoid (APIENTRY *glVertexAttrib4dv)(GLuint index, const GLdouble *v)=NULL;
GLvoid (APIENTRY *glVertexAttrib4f)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w)=NULL;
GLvoid (APIENTRY *glVertexAttrib4fv)(GLuint index, const GLfloat *v)=NULL;
GLvoid (APIENTRY *glVertexAttrib4iv)(GLuint index, const GLint *v)=NULL;
GLvoid (APIENTRY *glVertexAttrib4s)(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w)=NULL;
GLvoid (APIENTRY *glVertexAttrib4sv)(GLuint index, const GLshort *v)=NULL;
GLvoid (APIENTRY *glVertexAttrib4ubv)(GLuint index, const GLubyte *v)=NULL;
GLvoid (APIENTRY *glVertexAttrib4uiv)(GLuint index, const GLuint *v)=NULL;
GLvoid (APIENTRY *glVertexAttrib4usv)(GLuint index, const GLushort *v)=NULL;
GLvoid (APIENTRY *glVertexAttribPointer)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid *pointer)=NULL;
GLvoid (APIENTRY *glUniformMatrix2x3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)=NULL;
GLvoid (APIENTRY *glUniformMatrix3x2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)=NULL;
GLvoid (APIENTRY *glUniformMatrix2x4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)=NULL;
GLvoid (APIENTRY *glUniformMatrix4x2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)=NULL;
GLvoid (APIENTRY *glUniformMatrix3x4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)=NULL;
GLvoid (APIENTRY *glUniformMatrix4x3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)=NULL;

/* OpenGL 3.3 */
GLvoid (APIENTRY *glColorMaski)(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a)=NULL;
GLvoid (APIENTRY *glGetBooleani_v)(GLenum target, GLuint index, GLboolean *data)=NULL;
GLvoid (APIENTRY *glGetIntegeri_v)(GLenum target, GLuint index, GLint *data)=NULL;
GLvoid (APIENTRY *glEnablei)(GLenum target, GLuint index)=NULL;
GLvoid (APIENTRY *glDisablei)(GLenum target, GLuint index)=NULL;
GLboolean (APIENTRY *glIsEnabledi)(GLenum target, GLuint index)=NULL;
GLvoid (APIENTRY *glBeginTransformFeedback)(GLenum primitiveMode)=NULL;
GLvoid (APIENTRY *glEndTransformFeedback)(GLvoid)=NULL;
GLvoid (APIENTRY *glBindBufferRange)(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size)=NULL;
GLvoid (APIENTRY *glBindBufferBase)(GLenum target, GLuint index, GLuint buffer)=NULL;
GLvoid (APIENTRY *glTransformFeedbackVaryings)(GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode)=NULL;
GLvoid (APIENTRY *glGetTransformFeedbackVarying)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name)=NULL;
GLvoid (APIENTRY *glClampColor)(GLenum target, GLenum clamp)=NULL;
GLvoid (APIENTRY *glBeginConditionalRender)(GLuint id, GLenum mode)=NULL;
GLvoid (APIENTRY *glEndConditionalRender)(GLvoid)=NULL;
GLvoid (APIENTRY *glVertexAttribIPointer)(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer)=NULL;
GLvoid (APIENTRY *glGetVertexAttribIiv)(GLuint index, GLenum pname, GLint *params)=NULL;
GLvoid (APIENTRY *glGetVertexAttribIuiv)(GLuint index, GLenum pname, GLuint *params)=NULL;
GLvoid (APIENTRY *glVertexAttribI1i)(GLuint index, GLint x)=NULL;
GLvoid (APIENTRY *glVertexAttribI2i)(GLuint index, GLint x, GLint y)=NULL;
GLvoid (APIENTRY *glVertexAttribI3i)(GLuint index, GLint x, GLint y, GLint z)=NULL;
GLvoid (APIENTRY *glVertexAttribI4i)(GLuint index, GLint x, GLint y, GLint z, GLint w)=NULL;
GLvoid (APIENTRY *glVertexAttribI1ui)(GLuint index, GLuint x)=NULL;
GLvoid (APIENTRY *glVertexAttribI2ui)(GLuint index, GLuint x, GLuint y)=NULL;
GLvoid (APIENTRY *glVertexAttribI3ui)(GLuint index, GLuint x, GLuint y, GLuint z)=NULL;
GLvoid (APIENTRY *glVertexAttribI4ui)(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w)=NULL;
GLvoid (APIENTRY *glVertexAttribI1iv)(GLuint index, const GLint *v)=NULL;
GLvoid (APIENTRY *glVertexAttribI2iv)(GLuint index, const GLint *v)=NULL;
GLvoid (APIENTRY *glVertexAttribI3iv)(GLuint index, const GLint *v)=NULL;
GLvoid (APIENTRY *glVertexAttribI4iv)(GLuint index, const GLint *v)=NULL;
GLvoid (APIENTRY *glVertexAttribI1uiv)(GLuint index, const GLuint *v)=NULL;
GLvoid (APIENTRY *glVertexAttribI2uiv)(GLuint index, const GLuint *v)=NULL;
GLvoid (APIENTRY *glVertexAttribI3uiv)(GLuint index, const GLuint *v)=NULL;
GLvoid (APIENTRY *glVertexAttribI4uiv)(GLuint index, const GLuint *v)=NULL;
GLvoid (APIENTRY *glVertexAttribI4bv)(GLuint index, const GLbyte *v)=NULL;
GLvoid (APIENTRY *glVertexAttribI4sv)(GLuint index, const GLshort *v)=NULL;
GLvoid (APIENTRY *glVertexAttribI4ubv)(GLuint index, const GLubyte *v)=NULL;
GLvoid (APIENTRY *glVertexAttribI4usv)(GLuint index, const GLushort *v)=NULL;
GLvoid (APIENTRY *glGetUniformuiv)(GLuint program, GLint location, GLuint *params)=NULL;
GLvoid (APIENTRY *glBindFragDataLocation)(GLuint program, GLuint color, const GLchar *name)=NULL;
GLint (APIENTRY *glGetFragDataLocation)(GLuint program, const GLchar *name)=NULL;
GLvoid (APIENTRY *glUniform1ui)(GLint location, GLuint v0)=NULL;
GLvoid (APIENTRY *glUniform2ui)(GLint location, GLuint v0, GLuint v1)=NULL;
GLvoid (APIENTRY *glUniform3ui)(GLint location, GLuint v0, GLuint v1, GLuint v2)=NULL;
GLvoid (APIENTRY *glUniform4ui)(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3)=NULL;
GLvoid (APIENTRY *glUniform1uiv)(GLint location, GLsizei count, const GLuint *value)=NULL;
GLvoid (APIENTRY *glUniform2uiv)(GLint location, GLsizei count, const GLuint *value)=NULL;
GLvoid (APIENTRY *glUniform3uiv)(GLint location, GLsizei count, const GLuint *value)=NULL;
GLvoid (APIENTRY *glUniform4uiv)(GLint location, GLsizei count, const GLuint *value)=NULL;
GLvoid (APIENTRY *glTexParameterIiv)(GLenum target, GLenum pname, const GLint *params)=NULL;
GLvoid (APIENTRY *glTexParameterIuiv)(GLenum target, GLenum pname, const GLuint *params)=NULL;
GLvoid (APIENTRY *glGetTexParameterIiv)(GLenum target, GLenum pname, GLint *params)=NULL;
GLvoid (APIENTRY *glGetTexParameterIuiv)(GLenum target, GLenum pname, GLuint *params)=NULL;
GLvoid (APIENTRY *glClearBufferiv)(GLenum buffer, GLint drawbuffer, const GLint *value)=NULL;
GLvoid (APIENTRY *glClearBufferuiv)(GLenum buffer, GLint drawbuffer, const GLuint *value)=NULL;
GLvoid (APIENTRY *glClearBufferfv)(GLenum buffer, GLint drawbuffer, const GLfloat *value)=NULL;
GLvoid (APIENTRY *glClearBufferfi)(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil)=NULL;
const GLubyte *(APIENTRY *glGetStringi)(GLenum name, GLuint index)=NULL;
GLboolean (APIENTRY *glIsRenderbuffer)(GLuint renderbuffer)=NULL;
GLvoid (APIENTRY *glBindRenderbuffer)(GLenum target, GLuint renderbuffer)=NULL;
GLvoid (APIENTRY *glDeleteRenderbuffers)(GLsizei n, const GLuint *renderbuffers)=NULL;
GLvoid (APIENTRY *glGenRenderbuffers)(GLsizei n, GLuint *renderbuffers)=NULL;
GLvoid (APIENTRY *glRenderbufferStorage)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height)=NULL;
GLvoid (APIENTRY *glGetRenderbufferParameteriv)(GLenum target, GLenum pname, GLint *params)=NULL;
GLboolean (APIENTRY *glIsFramebuffer)(GLuint framebuffer)=NULL;
GLvoid (APIENTRY *glBindFramebuffer)(GLenum target, GLuint framebuffer)=NULL;
GLvoid (APIENTRY *glDeleteFramebuffers)(GLsizei n, const GLuint *framebuffers)=NULL;
GLvoid (APIENTRY *glGenFramebuffers)(GLsizei n, GLuint *framebuffers)=NULL;
GLenum (APIENTRY *glCheckFramebufferStatus)(GLenum target)=NULL;
GLvoid (APIENTRY *glFramebufferTexture1D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)=NULL;
GLvoid (APIENTRY *glFramebufferTexture2D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)=NULL;
GLvoid (APIENTRY *glFramebufferTexture3D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset)=NULL;
GLvoid (APIENTRY *glFramebufferRenderbuffer)(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer)=NULL;
GLvoid (APIENTRY *glGetFramebufferAttachmentParameteriv)(GLenum target, GLenum attachment, GLenum pname, GLint *params)=NULL;
GLvoid (APIENTRY *glGenerateMipmap)(GLenum target)=NULL;
GLvoid (APIENTRY *glBlitFramebuffer)(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter)=NULL;
GLvoid (APIENTRY *glRenderbufferStorageMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height)=NULL;
GLvoid (APIENTRY *glFramebufferTextureLayer)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer)=NULL;
GLvoid *(APIENTRY *glMapBufferRange)(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access)=NULL;
GLvoid (APIENTRY *glFlushMappedBufferRange)(GLenum target, GLintptr offset, GLsizeiptr length)=NULL;
GLvoid (APIENTRY *glBindVertexArray)(GLuint array)=NULL;
GLvoid (APIENTRY *glDeleteVertexArrays)(GLsizei n, const GLuint *arrays)=NULL;
GLvoid (APIENTRY *glGenVertexArrays)(GLsizei n, GLuint *arrays)=NULL;
GLboolean (APIENTRY *glIsVertexArray)(GLuint array)=NULL;
GLvoid (APIENTRY *glDrawArraysInstanced)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount)=NULL;
GLvoid (APIENTRY *glDrawElementsInstanced)(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLsizei instancecount)=NULL;
GLvoid (APIENTRY *glTexBuffer)(GLenum target, GLenum internalformat, GLuint buffer)=NULL;
GLvoid (APIENTRY *glPrimitiveRestartIndex)(GLuint index)=NULL;
GLvoid (APIENTRY *glCopyBufferSubData)(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size)=NULL;
GLvoid (APIENTRY *glGetUniformIndices)(GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices)=NULL;
GLvoid (APIENTRY *glGetActiveUniformsiv)(GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params)=NULL;
GLvoid (APIENTRY *glGetActiveUniformName)(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName)=NULL;
GLuint (APIENTRY *glGetUniformBlockIndex)(GLuint program, const GLchar *uniformBlockName)=NULL;
GLvoid (APIENTRY *glGetActiveUniformBlockiv)(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params)=NULL;
GLvoid (APIENTRY *glGetActiveUniformBlockName)(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName)=NULL;
GLvoid (APIENTRY *glUniformBlockBinding)(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding)=NULL;
GLvoid (APIENTRY *glDrawElementsBaseVertex)(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLint basevertex)=NULL;
GLvoid (APIENTRY *glDrawRangeElementsBaseVertex)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices, GLint basevertex)=NULL;
GLvoid (APIENTRY *glDrawElementsInstancedBaseVertex)(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLsizei instancecount, GLint basevertex)=NULL;
GLvoid (APIENTRY *glMultiDrawElementsBaseVertex)(GLenum mode, const GLsizei *count, GLenum type, const GLvoid *const*indices, GLsizei drawcount, const GLint *basevertex)=NULL;
GLvoid (APIENTRY *glProvokingVertex)(GLenum mode)=NULL;
GLsync (APIENTRY *glFenceSync)(GLenum condition, GLbitfield flags)=NULL;
GLboolean (APIENTRY *glIsSync)(GLsync sync)=NULL;
GLvoid (APIENTRY *glDeleteSync)(GLsync sync)=NULL;
GLenum (APIENTRY *glClientWaitSync)(GLsync sync, GLbitfield flags, GLuint64 timeout)=NULL;
GLvoid (APIENTRY *glWaitSync)(GLsync sync, GLbitfield flags, GLuint64 timeout)=NULL;
GLvoid (APIENTRY *glGetInteger64v)(GLenum pname, GLint64 *data)=NULL;
GLvoid (APIENTRY *glGetSynciv)(GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values)=NULL;
GLvoid (APIENTRY *glGetInteger64i_v)(GLenum target, GLuint index, GLint64 *data)=NULL;
GLvoid (APIENTRY *glGetBufferParameteri64v)(GLenum target, GLenum pname, GLint64 *params)=NULL;
GLvoid (APIENTRY *glFramebufferTexture)(GLenum target, GLenum attachment, GLuint texture, GLint level)=NULL;
GLvoid (APIENTRY *glTexImage2DMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations)=NULL;
GLvoid (APIENTRY *glTexImage3DMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations)=NULL;
GLvoid (APIENTRY *glGetMultisamplefv)(GLenum pname, GLuint index, GLfloat *val)=NULL;
GLvoid (APIENTRY *glSampleMaski)(GLuint maskNumber, GLbitfield mask)=NULL;
GLvoid (APIENTRY *glBindFragDataLocationIndexed)(GLuint program, GLuint colorNumber, GLuint index, const GLchar *name)=NULL;
GLint (APIENTRY *glGetFragDataIndex)(GLuint program, const GLchar *name)=NULL;
GLvoid (APIENTRY *glGenSamplers)(GLsizei count, GLuint *samplers)=NULL;
GLvoid (APIENTRY *glDeleteSamplers)(GLsizei count, const GLuint *samplers)=NULL;
GLboolean (APIENTRY *glIsSampler)(GLuint sampler)=NULL;
GLvoid (APIENTRY *glBindSampler)(GLuint unit, GLuint sampler)=NULL;
GLvoid (APIENTRY *glSamplerParameteri)(GLuint sampler, GLenum pname, GLint param)=NULL;
GLvoid (APIENTRY *glSamplerParameteriv)(GLuint sampler, GLenum pname, const GLint *param)=NULL;
GLvoid (APIENTRY *glSamplerParameterf)(GLuint sampler, GLenum pname, GLfloat param)=NULL;
GLvoid (APIENTRY *glSamplerParameterfv)(GLuint sampler, GLenum pname, const GLfloat *param)=NULL;
GLvoid (APIENTRY *glSamplerParameterIiv)(GLuint sampler, GLenum pname, const GLint *param)=NULL;
GLvoid (APIENTRY *glSamplerParameterIuiv)(GLuint sampler, GLenum pname, const GLuint *param)=NULL;
GLvoid (APIENTRY *glGetSamplerParameteriv)(GLuint sampler, GLenum pname, GLint *params)=NULL;
GLvoid (APIENTRY *glGetSamplerParameterIiv)(GLuint sampler, GLenum pname, GLint *params)=NULL;
GLvoid (APIENTRY *glGetSamplerParameterfv)(GLuint sampler, GLenum pname, GLfloat *params)=NULL;
GLvoid (APIENTRY *glGetSamplerParameterIuiv)(GLuint sampler, GLenum pname, GLuint *params)=NULL;
GLvoid (APIENTRY *glQueryCounter)(GLuint id, GLenum target)=NULL;
GLvoid (APIENTRY *glGetQueryObjecti64v)(GLuint id, GLenum pname, GLint64 *params)=NULL;
GLvoid (APIENTRY *glGetQueryObjectui64v)(GLuint id, GLenum pname, GLuint64 *params)=NULL;
GLvoid (APIENTRY *glVertexAttribDivisor)(GLuint index, GLuint divisor)=NULL;
GLvoid (APIENTRY *glVertexAttribP1ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value)=NULL;
GLvoid (APIENTRY *glVertexAttribP1uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint *value)=NULL;
GLvoid (APIENTRY *glVertexAttribP2ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value)=NULL;
GLvoid (APIENTRY *glVertexAttribP2uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint *value)=NULL;
GLvoid (APIENTRY *glVertexAttribP3ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value)=NULL;
GLvoid (APIENTRY *glVertexAttribP3uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint *value)=NULL;
GLvoid (APIENTRY *glVertexAttribP4ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value)=NULL;
GLvoid (APIENTRY *glVertexAttribP4uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint *value)=NULL;

GLboolean GL_ARB_texture_rectangle_Flag=0;

int GLExtensionsInitialized_Flag=0;

#ifdef WIN32
int WGLExtensionsInitialized_Flag=0;
#else
int GLXExtensionsInitialized_Flag=0;
#endif

void *glGetProcAddress(char *Name, int *Return)
{
	void *FuncPtr=NULL;

#ifdef WIN32
	FuncPtr=(void *)wglGetProcAddress(Name);
#else
	FuncPtr=(void *)glXGetProcAddressARB(Name);
#endif

	if(FuncPtr!=NULL)
		*Return&=1;
	else
		*Return&=0;

	return FuncPtr;
}

int FindSubString(char *string, char *substring)
{
	if(string)
	{
		char *str=string;
		size_t len=strlen(substring);

		while((str=strstr(str, substring))!=NULL)
		{
			str+=len;

			if(*str==' '||*str=='\0')
				return 1;
		}
	}

	return 0;
}

void GLSetupExtensions(void)
{
	int Return=1;
	char *GLExtensionString=NULL;

/*	glCullFace=glGetProcAddress("glCullFace", &Return);
	glFrontFace=glGetProcAddress("glFrontFace", &Return);
	glHint=glGetProcAddress("glHint", &Return);
	glLineWidth=glGetProcAddress("glLineWidth", &Return);
	glPointSize=glGetProcAddress("glPointSize", &Return);
	glPolygonMode=glGetProcAddress("glPolygonMode", &Return);
	glScissor=glGetProcAddress("glScissor", &Return);
	glTexParameterf=glGetProcAddress("glTexParameterf", &Return);
	glTexParameterfv=glGetProcAddress("glTexParameterfv", &Return);
	glTexParameteri=glGetProcAddress("glTexParameteri", &Return);
	glTexParameteriv=glGetProcAddress("glTexParameteriv", &Return);
	glTexImage1D=glGetProcAddress("glTexImage1D", &Return);
	glTexImage2D=glGetProcAddress("glTexImage2D", &Return);
	glDrawBuffer=glGetProcAddress("glDrawBuffer", &Return);
	glClear=glGetProcAddress("glClear", &Return);
	glClearColor=glGetProcAddress("glClearColor", &Return);
	glClearStencil=glGetProcAddress("glClearStencil", &Return);
	glClearDepth=glGetProcAddress("glClearDepth", &Return);
	glStencilMask=glGetProcAddress("glStencilMask", &Return);
	glColorMask=glGetProcAddress("glColorMask", &Return);
	glDepthMask=glGetProcAddress("glDepthMask", &Return);
	glDisable=glGetProcAddress("glDisable", &Return);
	glEnable=glGetProcAddress("glEnable", &Return);
	glFinish=glGetProcAddress("glFinish", &Return);
	glFlush=glGetProcAddress("glFlush", &Return);
	glBlendFunc=glGetProcAddress("glBlendFunc", &Return);
	glLogicOp=glGetProcAddress("glLogicOp", &Return);
	glStencilFunc=glGetProcAddress("glStencilFunc", &Return);
	glStencilOp=glGetProcAddress("glStencilOp", &Return);
	glDepthFunc=glGetProcAddress("glDepthFunc", &Return);
	glPixelStoref=glGetProcAddress("glPixelStoref", &Return);
	glPixelStorei=glGetProcAddress("glPixelStorei", &Return);
	glReadBuffer=glGetProcAddress("glReadBuffer", &Return);
	glReadPixels=glGetProcAddress("glReadPixels", &Return);
	glGetBooleanv=glGetProcAddress("glGetBooleanv", &Return);
	glGetDoublev=glGetProcAddress("glGetDoublev", &Return);
	glGetError=glGetProcAddress("glGetError", &Return);
	glGetFloatv=glGetProcAddress("glGetFloatv", &Return);
	glGetIntegerv=glGetProcAddress("glGetIntegerv", &Return);
	glGetString=glGetProcAddress("glGetString", &Return);
	glGetTexImage=glGetProcAddress("glGetTexImage", &Return);
	glGetTexParameterfv=glGetProcAddress("glGetTexParameterfv", &Return);
	glGetTexParameteriv=glGetProcAddress("glGetTexParameteriv", &Return);
	glGetTexLevelParameterfv=glGetProcAddress("glGetTexLevelParameterfv", &Return);
	glGetTexLevelParameteriv=glGetProcAddress("glGetTexLevelParameteriv", &Return);
	glIsEnabled=glGetProcAddress("glIsEnabled", &Return);
	glDepthRange=glGetProcAddress("glDepthRange", &Return);
	glViewport=glGetProcAddress("glViewport", &Return);
	glDrawArrays=glGetProcAddress("glDrawArrays", &Return);
	glDrawElements=glGetProcAddress("glDrawElements", &Return);
	glGetPointerv=glGetProcAddress("glGetPointerv", &Return);
	glPolygonOffset=glGetProcAddress("glPolygonOffset", &Return);
	glCopyTexImage1D=glGetProcAddress("glCopyTexImage1D", &Return);
	glCopyTexImage2D=glGetProcAddress("glCopyTexImage2D", &Return);
	glCopyTexSubImage1D=glGetProcAddress("glCopyTexSubImage1D", &Return);
	glCopyTexSubImage2D=glGetProcAddress("glCopyTexSubImage2D", &Return);
	glTexSubImage1D=glGetProcAddress("glTexSubImage1D", &Return);
	glTexSubImage2D=glGetProcAddress("glTexSubImage2D", &Return);
	glBindTexture=glGetProcAddress("glBindTexture", &Return);
	glDeleteTextures=glGetProcAddress("glDeleteTextures", &Return);
	glGenTextures=glGetProcAddress("glGenTextures", &Return);
	glIsTexture=glGetProcAddress("glIsTexture", &Return);*/
	glDrawRangeElements=glGetProcAddress("glDrawRangeElements", &Return);
	glTexImage3D=glGetProcAddress("glTexImage3D", &Return);
	glTexSubImage3D=glGetProcAddress("glTexSubImage3D", &Return);
	glCopyTexSubImage3D=glGetProcAddress("glCopyTexSubImage3D", &Return);
	glActiveTexture=glGetProcAddress("glActiveTexture", &Return);
	glSampleCoverage=glGetProcAddress("glSampleCoverage", &Return);
	glCompressedTexImage3D=glGetProcAddress("glCompressedTexImage3D", &Return);
	glCompressedTexImage2D=glGetProcAddress("glCompressedTexImage2D", &Return);
	glCompressedTexImage1D=glGetProcAddress("glCompressedTexImage1D", &Return);
	glCompressedTexSubImage3D=glGetProcAddress("glCompressedTexSubImage3D", &Return);
	glCompressedTexSubImage2D=glGetProcAddress("glCompressedTexSubImage2D", &Return);
	glCompressedTexSubImage1D=glGetProcAddress("glCompressedTexSubImage1D", &Return);
	glGetCompressedTexImage=glGetProcAddress("glGetCompressedTexImage", &Return);
	glBlendFuncSeparate=glGetProcAddress("glBlendFuncSeparate", &Return);
	glMultiDrawArrays=glGetProcAddress("glMultiDrawArrays", &Return);
	glMultiDrawElements=glGetProcAddress("glMultiDrawElements", &Return);
	glPointParameterf=glGetProcAddress("glPointParameterf", &Return);
	glPointParameterfv=glGetProcAddress("glPointParameterfv", &Return);
	glPointParameteri=glGetProcAddress("glPointParameteri", &Return);
	glPointParameteriv=glGetProcAddress("glPointParameteriv", &Return);
	glBlendColor=glGetProcAddress("glBlendColor", &Return);
	glBlendEquation=glGetProcAddress("glBlendEquation", &Return);
	glGenQueries=glGetProcAddress("glGenQueries", &Return);
	glDeleteQueries=glGetProcAddress("glDeleteQueries", &Return);
	glIsQuery=glGetProcAddress("glIsQuery", &Return);
	glBeginQuery=glGetProcAddress("glIsQuery", &Return);
	glEndQuery=glGetProcAddress("glEndQuery", &Return);
	glGetQueryiv=glGetProcAddress("glGetQueryiv", &Return);
	glGetQueryObjectiv=glGetProcAddress("glGetQueryObjectiv", &Return);
	glGetQueryObjectuiv=glGetProcAddress("glGetQueryObjectuiv", &Return);
	glBindBuffer=glGetProcAddress("glBindBuffer", &Return);
	glDeleteBuffers=glGetProcAddress("glDeleteBuffers", &Return);
	glGenBuffers=glGetProcAddress("glGenBuffers", &Return);
	glIsBuffer=glGetProcAddress("glIsBuffer", &Return);
	glBufferData=glGetProcAddress("glBufferData", &Return);
	glBufferSubData=glGetProcAddress("glBufferSubData", &Return);
	glGetBufferSubData=glGetProcAddress("glGetBufferSubData", &Return);
	glMapBuffer=glGetProcAddress("glMapBuffer", &Return);
	glUnmapBuffer=glGetProcAddress("glUnmapBuffer", &Return);
	glGetBufferParameteriv=glGetProcAddress("glGetBufferParameteriv", &Return);
	glGetBufferPointerv=glGetProcAddress("glGetBufferPointerv", &Return);
	glBlendEquationSeparate=glGetProcAddress("glBlendEquationSeparate", &Return);
	glDrawBuffers=glGetProcAddress("glDrawBuffers", &Return);
	glStencilOpSeparate=glGetProcAddress("glStencilOpSeparate", &Return);
	glStencilFuncSeparate=glGetProcAddress("glStencilFuncSeparate", &Return);
	glStencilMaskSeparate=glGetProcAddress("glStencilMaskSeparate", &Return);
	glAttachShader=glGetProcAddress("glAttachShader", &Return);
	glBindAttribLocation=glGetProcAddress("glBindAttribLocation", &Return);
	glCompileShader=glGetProcAddress("glCompileShader", &Return);
	glCreateProgram=glGetProcAddress("glCreateProgram", &Return);
	glCreateShader=glGetProcAddress("glCreateShader", &Return);
	glDeleteProgram=glGetProcAddress("glDeleteProgram", &Return);
	glDeleteShader=glGetProcAddress("glDeleteShader", &Return);
	glDetachShader=glGetProcAddress("glDetachShader", &Return);
	glDisableVertexAttribArray=glGetProcAddress("glDisableVertexAttribArray", &Return);
	glEnableVertexAttribArray=glGetProcAddress("glEnableVertexAttribArray", &Return);
	glGetActiveAttrib=glGetProcAddress("glGetActiveAttrib", &Return);
	glGetActiveUniform=glGetProcAddress("glGetActiveUniform", &Return);
	glGetAttachedShaders=glGetProcAddress("glGetAttachedShaders", &Return);
	glGetAttribLocation=glGetProcAddress("glGetAttribLocation", &Return);
	glGetProgramiv=glGetProcAddress("glGetProgramiv", &Return);
	glGetProgramInfoLog=glGetProcAddress("glGetProgramInfoLog", &Return);
	glGetShaderiv=glGetProcAddress("glGetShaderiv", &Return);
	glGetShaderInfoLog=glGetProcAddress("glGetShaderInfoLog", &Return);
	glGetShaderSource=glGetProcAddress("glGetShaderSource", &Return);
	glGetUniformLocation=glGetProcAddress("glGetUniformLocation", &Return);
	glGetUniformfv=glGetProcAddress("glGetUniformfv", &Return);
	glGetUniformiv=glGetProcAddress("glGetUniformiv", &Return);
	glGetVertexAttribdv=glGetProcAddress("glGetVertexAttribdv", &Return);
	glGetVertexAttribfv=glGetProcAddress("glGetVertexAttribfv", &Return);
	glGetVertexAttribiv=glGetProcAddress("glGetVertexAttribiv", &Return);
	glGetVertexAttribPointerv=glGetProcAddress("glGetVertexAttribPointerv", &Return);
	glIsProgram=glGetProcAddress("glIsProgram", &Return);
	glIsShader=glGetProcAddress("glIsShader", &Return);
	glLinkProgram=glGetProcAddress("glLinkProgram", &Return);
	glShaderSource=glGetProcAddress("glShaderSource", &Return);
	glUseProgram=glGetProcAddress("glUseProgram", &Return);
	glUniform1f=glGetProcAddress("glUniform1f", &Return);
	glUniform2f=glGetProcAddress("glUniform2f", &Return);
	glUniform3f=glGetProcAddress("glUniform3f", &Return);
	glUniform4f=glGetProcAddress("glUniform4f", &Return);
	glUniform1i=glGetProcAddress("glUniform1i", &Return);
	glUniform2i=glGetProcAddress("glUniform2i", &Return);
	glUniform3i=glGetProcAddress("glUniform3i", &Return);
	glUniform4i=glGetProcAddress("glUniform4i", &Return);
	glUniform1fv=glGetProcAddress("glUniform1fv", &Return);
	glUniform2fv=glGetProcAddress("glUniform2fv", &Return);
	glUniform3fv=glGetProcAddress("glUniform3fv", &Return);
	glUniform4fv=glGetProcAddress("glUniform4fv", &Return);
	glUniform1iv=glGetProcAddress("glUniform1iv", &Return);
	glUniform2iv=glGetProcAddress("glUniform2iv", &Return);
	glUniform3iv=glGetProcAddress("glUniform3iv", &Return);
	glUniform4iv=glGetProcAddress("glUniform4iv", &Return);
	glUniformMatrix2fv=glGetProcAddress("glUniformMatrix2fv", &Return);
	glUniformMatrix3fv=glGetProcAddress("glUniformMatrix3fv", &Return);
	glUniformMatrix4fv=glGetProcAddress("glUniformMatrix4fv", &Return);
	glValidateProgram=glGetProcAddress("glValidateProgram", &Return);
	glVertexAttrib1d=glGetProcAddress("glVertexAttrib1d", &Return);
	glVertexAttrib1dv=glGetProcAddress("glVertexAttrib1dv", &Return);
	glVertexAttrib1f=glGetProcAddress("glVertexAttrib1f", &Return);
	glVertexAttrib1fv=glGetProcAddress("glVertexAttrib1fv", &Return);
	glVertexAttrib1s=glGetProcAddress("glVertexAttrib1s", &Return);
	glVertexAttrib1sv=glGetProcAddress("glVertexAttrib1sv", &Return);
	glVertexAttrib2d=glGetProcAddress("glVertexAttrib2d", &Return);
	glVertexAttrib2dv=glGetProcAddress("glVertexAttrib2dv", &Return);
	glVertexAttrib2f=glGetProcAddress("glVertexAttrib2f", &Return);
	glVertexAttrib2fv=glGetProcAddress("glVertexAttrib2fv", &Return);
	glVertexAttrib2s=glGetProcAddress("glVertexAttrib2s", &Return);
	glVertexAttrib2sv=glGetProcAddress("glVertexAttrib2sv", &Return);
	glVertexAttrib3d=glGetProcAddress("glVertexAttrib3d", &Return);
	glVertexAttrib3dv=glGetProcAddress("glVertexAttrib3dv", &Return);
	glVertexAttrib3f=glGetProcAddress("glVertexAttrib3f", &Return);
	glVertexAttrib3fv=glGetProcAddress("glVertexAttrib3fv", &Return);
	glVertexAttrib3s=glGetProcAddress("glVertexAttrib3s", &Return);
	glVertexAttrib3sv=glGetProcAddress("glVertexAttrib3sv", &Return);
	glVertexAttrib4Nbv=glGetProcAddress("glVertexAttrib4Nbv", &Return);
	glVertexAttrib4Niv=glGetProcAddress("glVertexAttrib4Niv", &Return);
	glVertexAttrib4Nsv=glGetProcAddress("glVertexAttrib4Nsv", &Return);
	glVertexAttrib4Nub=glGetProcAddress("glVertexAttrib4Nub", &Return);
	glVertexAttrib4Nubv=glGetProcAddress("glVertexAttrib4Nubv", &Return);
	glVertexAttrib4Nuiv=glGetProcAddress("glVertexAttrib4Nuiv", &Return);
	glVertexAttrib4Nusv=glGetProcAddress("glVertexAttrib4Nusv", &Return);
	glVertexAttrib4bv=glGetProcAddress("glVertexAttrib4bv", &Return);
	glVertexAttrib4d=glGetProcAddress("glVertexAttrib4d", &Return);
	glVertexAttrib4dv=glGetProcAddress("glVertexAttrib4dv", &Return);
	glVertexAttrib4f=glGetProcAddress("glVertexAttrib4f", &Return);
	glVertexAttrib4fv=glGetProcAddress("glVertexAttrib4fv", &Return);
	glVertexAttrib4iv=glGetProcAddress("glVertexAttrib4iv", &Return);
	glVertexAttrib4s=glGetProcAddress("glVertexAttrib4s", &Return);
	glVertexAttrib4sv=glGetProcAddress("glVertexAttrib4sv", &Return);
	glVertexAttrib4ubv=glGetProcAddress("glVertexAttrib4ubv", &Return);
	glVertexAttrib4uiv=glGetProcAddress("glVertexAttrib4uiv", &Return);
	glVertexAttrib4usv=glGetProcAddress("glVertexAttrib4usv", &Return);
	glVertexAttribPointer=glGetProcAddress("glVertexAttribPointer", &Return);
	glUniformMatrix2x3fv=glGetProcAddress("glUniformMatrix2x3fv", &Return);
	glUniformMatrix3x2fv=glGetProcAddress("glUniformMatrix3x2fv", &Return);
	glUniformMatrix2x4fv=glGetProcAddress("glUniformMatrix2x4fv", &Return);
	glUniformMatrix4x2fv=glGetProcAddress("glUniformMatrix4x2fv", &Return);
	glUniformMatrix3x4fv=glGetProcAddress("glUniformMatrix3x4fv", &Return);
	glUniformMatrix4x3fv=glGetProcAddress("glUniformMatrix4x3fv", &Return);

	// Something went horribly wrong, or incomplete GL2.1 support
	if(!Return)
		return;

	// GL Extensions
	GLExtensionString=(char *)glGetString(GL_EXTENSIONS);

	if(FindSubString(GLExtensionString, "GL_ARB_texture_rectangle"))
		GL_ARB_texture_rectangle_Flag=1;

	glColorMaski=glGetProcAddress("glColorMaski", &Return);
	glGetBooleani_v=glGetProcAddress("glGetBooleani_v", &Return);
	glGetIntegeri_v=glGetProcAddress("glGetIntegeri_v", &Return);
	glEnablei=glGetProcAddress("glEnablei", &Return);
	glDisablei=glGetProcAddress("glDisablei", &Return);
	glIsEnabledi=glGetProcAddress("glIsEnabledi", &Return);
	glBeginTransformFeedback=glGetProcAddress("glBeginTransformFeedback", &Return);
	glEndTransformFeedback=glGetProcAddress("glEndTransformFeedback", &Return);
	glBindBufferRange=glGetProcAddress("glBindBufferRange", &Return);
	glBindBufferBase=glGetProcAddress("glBindBufferBase", &Return);
	glTransformFeedbackVaryings=glGetProcAddress("glTransformFeedbackVaryings", &Return);
	glGetTransformFeedbackVarying=glGetProcAddress("glGetTransformFeedbackVarying", &Return);
	glClampColor=glGetProcAddress("glClampColor", &Return);
	glBeginConditionalRender=glGetProcAddress("glBeginConditionalRender", &Return);
	glEndConditionalRender=glGetProcAddress("glEndConditionalRender", &Return);
	glVertexAttribIPointer=glGetProcAddress("glVertexAttribIPointer", &Return);
	glGetVertexAttribIiv=glGetProcAddress("glGetVertexAttribIiv", &Return);
	glGetVertexAttribIuiv=glGetProcAddress("glGetVertexAttribIuiv", &Return);
	glVertexAttribI1i=glGetProcAddress("glVertexAttribI1i", &Return);
	glVertexAttribI2i=glGetProcAddress("glVertexAttribI2i", &Return);
	glVertexAttribI3i=glGetProcAddress("glVertexAttribI3i", &Return);
	glVertexAttribI4i=glGetProcAddress("glVertexAttribI4i", &Return);
	glVertexAttribI1ui=glGetProcAddress("glVertexAttribI1ui", &Return);
	glVertexAttribI2ui=glGetProcAddress("glVertexAttribI2ui", &Return);
	glVertexAttribI3ui=glGetProcAddress("glVertexAttribI3ui", &Return);
	glVertexAttribI4ui=glGetProcAddress("glVertexAttribI4ui", &Return);
	glVertexAttribI1iv=glGetProcAddress("glVertexAttribI1iv", &Return);
	glVertexAttribI2iv=glGetProcAddress("glVertexAttribI2iv", &Return);
	glVertexAttribI3iv=glGetProcAddress("glVertexAttribI3iv", &Return);
	glVertexAttribI4iv=glGetProcAddress("glVertexAttribI4iv", &Return);
	glVertexAttribI1uiv=glGetProcAddress("glVertexAttribI1uiv", &Return);
	glVertexAttribI2uiv=glGetProcAddress("glVertexAttribI2uiv", &Return);
	glVertexAttribI3uiv=glGetProcAddress("glVertexAttribI3uiv", &Return);
	glVertexAttribI4uiv=glGetProcAddress("glVertexAttribI4uiv", &Return);
	glVertexAttribI4bv=glGetProcAddress("glVertexAttribI4bv", &Return);
	glVertexAttribI4sv=glGetProcAddress("glVertexAttribI4sv", &Return);
	glVertexAttribI4ubv=glGetProcAddress("glVertexAttribI4ubv", &Return);
	glVertexAttribI4usv=glGetProcAddress("glVertexAttribI4usv", &Return);
	glGetUniformuiv=glGetProcAddress("glGetUniformuiv", &Return);
	glBindFragDataLocation=glGetProcAddress("glBindFragDataLocation", &Return);
	glGetFragDataLocation=glGetProcAddress("glGetFragDataLocation", &Return);
	glUniform1ui=glGetProcAddress("glUniform1ui", &Return);
	glUniform2ui=glGetProcAddress("glUniform2ui", &Return);
	glUniform3ui=glGetProcAddress("glUniform3ui", &Return);
	glUniform4ui=glGetProcAddress("glUniform4ui", &Return);
	glUniform1uiv=glGetProcAddress("glUniform1uiv", &Return);
	glUniform2uiv=glGetProcAddress("glUniform2uiv", &Return);
	glUniform3uiv=glGetProcAddress("glUniform3uiv", &Return);
	glUniform4uiv=glGetProcAddress("glUniform4uiv", &Return);
	glTexParameterIiv=glGetProcAddress("glTexParameterIiv", &Return);
	glTexParameterIuiv=glGetProcAddress("glTexParameterIuiv", &Return);
	glGetTexParameterIiv=glGetProcAddress("glGetTexParameterIiv", &Return);
	glGetTexParameterIuiv=glGetProcAddress("glGetTexParameterIuiv", &Return);
	glClearBufferiv=glGetProcAddress("glClearBufferiv", &Return);
	glClearBufferuiv=glGetProcAddress("glClearBufferuiv", &Return);
	glClearBufferfv=glGetProcAddress("glClearBufferfv", &Return);
	glClearBufferfi=glGetProcAddress("glClearBufferfi", &Return);
	glGetStringi=glGetProcAddress("glGetStringi", &Return);
	glIsRenderbuffer=glGetProcAddress("glIsRenderbuffer", &Return);
	glBindRenderbuffer=glGetProcAddress("glBindRenderbuffer", &Return);
	glDeleteRenderbuffers=glGetProcAddress("glDeleteRenderbuffers", &Return);
	glGenRenderbuffers=glGetProcAddress("glGenRenderbuffers", &Return);
	glRenderbufferStorage=glGetProcAddress("glRenderbufferStorage", &Return);
	glGetRenderbufferParameteriv=glGetProcAddress("glGetRenderbufferParameteriv", &Return);
	glIsFramebuffer=glGetProcAddress("glIsFramebuffer", &Return);
	glBindFramebuffer=glGetProcAddress("glBindFramebuffer", &Return);
	glDeleteFramebuffers=glGetProcAddress("glDeleteFramebuffers", &Return);
	glGenFramebuffers=glGetProcAddress("glGenFramebuffers", &Return);
	glCheckFramebufferStatus=glGetProcAddress("glCheckFramebufferStatus", &Return);
	glFramebufferTexture1D=glGetProcAddress("glFramebufferTexture1D", &Return);
	glFramebufferTexture2D=glGetProcAddress("glFramebufferTexture2D", &Return);
	glFramebufferTexture3D=glGetProcAddress("glFramebufferTexture3D", &Return);
	glFramebufferRenderbuffer=glGetProcAddress("glFramebufferRenderbuffer", &Return);
	glGetFramebufferAttachmentParameteriv=glGetProcAddress("glGetFramebufferAttachmentParameteriv", &Return);
	glGenerateMipmap=glGetProcAddress("glGenerateMipmap", &Return);
	glBlitFramebuffer=glGetProcAddress("glBlitFramebuffer", &Return);
	glRenderbufferStorageMultisample=glGetProcAddress("glRenderbufferStorageMultisample", &Return);
	glFramebufferTextureLayer=glGetProcAddress("glFramebufferTextureLayer", &Return);
	glMapBufferRange=glGetProcAddress("glMapBufferRange", &Return);
	glFlushMappedBufferRange=glGetProcAddress("glFlushMappedBufferRange", &Return);
	glBindVertexArray=glGetProcAddress("glBindVertexArray", &Return);
	glDeleteVertexArrays=glGetProcAddress("glDeleteVertexArrays", &Return);
	glGenVertexArrays=glGetProcAddress("glGenVertexArrays", &Return);
	glIsVertexArray=glGetProcAddress("glIsVertexArray", &Return);
	glDrawArraysInstanced=glGetProcAddress("glDrawArraysInstanced", &Return);
	glDrawElementsInstanced=glGetProcAddress("glDrawElementsInstanced", &Return);
	glTexBuffer=glGetProcAddress("glTexBuffer", &Return);
	glPrimitiveRestartIndex=glGetProcAddress("glPrimitiveRestartIndex", &Return);
	glCopyBufferSubData=glGetProcAddress("glCopyBufferSubData", &Return);
	glGetUniformIndices=glGetProcAddress("glGetUniformIndices", &Return);
	glGetActiveUniformsiv=glGetProcAddress("glGetActiveUniformsiv", &Return);
	glGetActiveUniformName=glGetProcAddress("glGetActiveUniformName", &Return);
	glGetUniformBlockIndex=glGetProcAddress("glGetUniformBlockIndex", &Return);
	glGetActiveUniformBlockiv=glGetProcAddress("glGetActiveUniformBlockiv", &Return);
	glGetActiveUniformBlockName=glGetProcAddress("glGetActiveUniformBlockName", &Return);
	glUniformBlockBinding=glGetProcAddress("glUniformBlockBinding", &Return);
	glDrawElementsBaseVertex=glGetProcAddress("glDrawElementsBaseVertex", &Return);
	glDrawRangeElementsBaseVertex=glGetProcAddress("glDrawRangeElementsBaseVertex", &Return);
	glDrawElementsInstancedBaseVertex=glGetProcAddress("glDrawElementsInstancedBaseVertex", &Return);
	glMultiDrawElementsBaseVertex=glGetProcAddress("glMultiDrawElementsBaseVertex", &Return);
	glProvokingVertex=glGetProcAddress("glProvokingVertex", &Return);
	glFenceSync=glGetProcAddress("glFenceSync", &Return);
	glIsSync=glGetProcAddress("glIsSync", &Return);
	glDeleteSync=glGetProcAddress("glDeleteSync", &Return);
	glClientWaitSync=glGetProcAddress("glClientWaitSync", &Return);
	glWaitSync=glGetProcAddress("glWaitSync", &Return);
	glGetInteger64v=glGetProcAddress("glGetInteger64v", &Return);
	glGetSynciv=glGetProcAddress("glGetSynciv", &Return);
	glGetInteger64i_v=glGetProcAddress("glGetInteger64i_v", &Return);
	glGetBufferParameteri64v=glGetProcAddress("glGetBufferParameteri64v", &Return);
	glFramebufferTexture=glGetProcAddress("glFramebufferTexture", &Return);
	glTexImage2DMultisample=glGetProcAddress("glTexImage2DMultisample", &Return);
	glTexImage3DMultisample=glGetProcAddress("glTexImage3DMultisample", &Return);
	glGetMultisamplefv=glGetProcAddress("glGetMultisamplefv", &Return);
	glSampleMaski=glGetProcAddress("glSampleMaski", &Return);
	glBindFragDataLocationIndexed=glGetProcAddress("glBindFragDataLocationIndexed", &Return);
	glGetFragDataIndex=glGetProcAddress("glGetFragDataIndex", &Return);
	glGenSamplers=glGetProcAddress("glGenSamplers", &Return);
	glDeleteSamplers=glGetProcAddress("glDeleteSamplers", &Return);
	glIsSampler=glGetProcAddress("glIsSampler", &Return);
	glBindSampler=glGetProcAddress("glBindSampler", &Return);
	glSamplerParameteri=glGetProcAddress("glSamplerParameteri", &Return);
	glSamplerParameteriv=glGetProcAddress("glSamplerParameteriv", &Return);
	glSamplerParameterf=glGetProcAddress("glSamplerParameterf", &Return);
	glSamplerParameterfv=glGetProcAddress("glSamplerParameterfv", &Return);
	glSamplerParameterIiv=glGetProcAddress("glSamplerParameterIiv", &Return);
	glSamplerParameterIuiv=glGetProcAddress("glSamplerParameterIuiv", &Return);
	glGetSamplerParameteriv=glGetProcAddress("glGetSamplerParameteriv", &Return);
	glGetSamplerParameterIiv=glGetProcAddress("glGetSamplerParameterIiv", &Return);
	glGetSamplerParameterfv=glGetProcAddress("glGetSamplerParameterfv", &Return);
	glGetSamplerParameterIuiv=glGetProcAddress("glGetSamplerParameterIuiv", &Return);
	glQueryCounter=glGetProcAddress("glQueryCounter", &Return);
	glGetQueryObjecti64v=glGetProcAddress("glGetQueryObjecti64v", &Return);
	glGetQueryObjectui64v=glGetProcAddress("glGetQueryObjectui64v", &Return);
	glVertexAttribDivisor=glGetProcAddress("glVertexAttribDivisor", &Return);
	glVertexAttribP1ui=glGetProcAddress("glVertexAttribP1ui", &Return);
	glVertexAttribP1uiv=glGetProcAddress("glVertexAttribP1uiv", &Return);
	glVertexAttribP2ui=glGetProcAddress("glVertexAttribP2ui", &Return);
	glVertexAttribP2uiv=glGetProcAddress("glVertexAttribP2uiv", &Return);
	glVertexAttribP3ui=glGetProcAddress("glVertexAttribP3ui", &Return);
	glVertexAttribP3uiv=glGetProcAddress("glVertexAttribP3uiv", &Return);
	glVertexAttribP4ui=glGetProcAddress("glVertexAttribP4ui", &Return);
	glVertexAttribP4uiv=glGetProcAddress("glVertexAttribP4uiv", &Return);

	// Something went horribly wrong, or incomplete GL3.3 support
	if(!Return)
		return;

	GLExtensionsInitialized_Flag=1;
}

#ifdef WIN32
void WGLSetupExtensions(void)
{
	int Return=1;
	char *WGLExtensionString=NULL;

	wglGetExtensionsStringARB=glGetProcAddress("wglGetExtensionsStringARB", &Return);

	if(Return)
		WGLExtensionString=(char *)wglGetExtensionsStringARB(wglGetCurrentDC());

	if(FindSubString(WGLExtensionString, "WGL_ARB_create_context_profile"))
		WGL_ARB_create_context_profile_Flag=1;

	if(FindSubString(WGLExtensionString, "WGL_ARB_create_context_robustness"))
		WGL_ARB_create_context_robustness_Flag=1;

	if(FindSubString(WGLExtensionString, "WGL_ARB_create_context"))
	{
		Return=1;

		wglCreateContextAttribsARB=glGetProcAddress("wglCreateContextAttribsARB", &Return);

		if(Return)
			WGL_ARB_create_context_Flag=1;
	}

	if(FindSubString(WGLExtensionString, "WGL_ARB_framebuffer_sRGB"))
		WGL_ARB_framebuffer_sRGB_Flag=1;

	if(FindSubString(WGLExtensionString, "WGL_ARB_make_current_read"))
	{
		Return=1;

		wglMakeContextCurrentARB=glGetProcAddress("wglMakeContextCurrentARB", &Return);
		wglGetCurrentReadDCARB=glGetProcAddress("wglGetCurrentReadDCARB", &Return);

		if(Return)
			WGL_ARB_make_current_read_Flag=1;
	}

	if(FindSubString(WGLExtensionString, "WGL_ARB_multisample"))
		WGL_ARB_multisample_Flag=1;

	if(FindSubString(WGLExtensionString, "WGL_ARB_pixel_format"))
	{
		Return=1;

		wglGetPixelFormatAttribivARB=glGetProcAddress("wglGetPixelFormatAttribivARB", &Return);
		wglGetPixelFormatAttribfvARB=glGetProcAddress("wglGetPixelFormatAttribfvARB", &Return);
		wglChoosePixelFormatARB=glGetProcAddress("wglChoosePixelFormatARB", &Return);

		if(Return)
			WGL_ARB_pixel_format_Flag=1;
	}

	WGLExtensionsInitialized_Flag=1;
}
#else
void GLXSetupExtensions(Display *dpy)
{
	int Return=1;
	char *GLXExtensionString=NULL;

	GLXExtensionString=(char *)glXQueryExtensionsString(dpy, DefaultScreen(dpy));

	if(FindSubString(GLXExtensionString, "GLX_ARB_create_context"))
	{
		glXCreateContextAttribsARB=glGetProcAddress("glXCreateContextAttribsARB", &Return);

		if(Return)
			GLX_ARB_create_context_Flag=1;
	}

	if(FindSubString(GLXExtensionString, "GLX_ARB_create_context_profile"))
		GLX_ARB_create_context_profile_Flag=1;

	if(FindSubString(GLXExtensionString, "GLX_ARB_create_context_robustness"))
		GLX_ARB_create_context_robustness_Flag=1;

	if(FindSubString(GLXExtensionString, "GLX_ARB_framebuffer_sRGB"))
		GLX_ARB_framebuffer_sRGB_Flag=1;

	if(FindSubString(GLXExtensionString, "GLX_ARB_multisample"))
		GLX_ARB_multisample_Flag=1;

	GLXExtensionsInitialized_Flag=1;
}
#endif

int CreateContext(GLContext_t *Context, int Color, int Depth, int Stencil, int Accum, unsigned long Flags)
{
#ifdef WIN32
	int PixelFormat;
	unsigned int NumFormats;
	int Attrib[128], i=0;
	int ContextAttribs[8];

	if(!(GLExtensionsInitialized_Flag||WGLExtensionsInitialized_Flag))
	{
		PIXELFORMATDESCRIPTOR pfd;
		HWND hWndTemp=NULL;
		HDC hDCTemp=NULL;
		HGLRC hRCTemp=NULL;

		memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR));
		pfd.nSize=sizeof(PIXELFORMATDESCRIPTOR);
		pfd.nVersion=1;
		pfd.dwFlags=PFD_DRAW_TO_WINDOW|PFD_SUPPORT_OPENGL;
		pfd.iPixelType=PFD_TYPE_RGBA;
		pfd.cColorBits=32;
		pfd.cDepthBits=24;
		pfd.iLayerType=PFD_MAIN_PLANE;
		
		hWndTemp=CreateWindow("static", NULL, WS_POPUP, 0, 0, 1, 1, NULL, NULL, (HINSTANCE)GetModuleHandle(NULL), NULL);
		hDCTemp=GetDC(hWndTemp);

		if(!(PixelFormat=ChoosePixelFormat(hDCTemp, &pfd)))
		{
			MessageBox(Context->hWnd, "ChoosePixelFormat Failed!", NULL, MB_OK);
			return 0;
		}

		if(!SetPixelFormat(hDCTemp, PixelFormat, NULL))
		{
			MessageBox(Context->hWnd, "SetPixelFormat Failed!", NULL, MB_OK);
			return 0;
		}

		if(!(hRCTemp=wglCreateContext(hDCTemp)))
		{
			MessageBox(Context->hWnd, "wglCreateContext Failed!", NULL, MB_OK);
			return 0;
		}


		if(!wglMakeCurrent(hDCTemp, hRCTemp))
		{
			MessageBox(Context->hWnd, "wglMakeCurrent Failed!", NULL, MB_OK);
			return 0;
		}

		if(!GLExtensionsInitialized_Flag)
			GLSetupExtensions();

		if(!WGLExtensionsInitialized_Flag)
			WGLSetupExtensions();

		wglMakeCurrent(NULL, NULL);
		wglDeleteContext(hRCTemp);
		ReleaseDC(hWndTemp, hDCTemp);
		DestroyWindow(hWndTemp);
	}

	if(!WGL_ARB_pixel_format_Flag)
		return 0;

	Context->hDC=GetDC(Context->hWnd);

	Attrib[i++]=WGL_DRAW_TO_WINDOW_ARB;
	Attrib[i++]=TRUE;
	Attrib[i++]=WGL_SUPPORT_OPENGL_ARB;
	Attrib[i++]=TRUE;

	if(Flags&OGL_SINGLEBUFFER)
	{
		Attrib[i++]=WGL_DOUBLE_BUFFER_ARB;
		Attrib[i++]=FALSE;
	}

	if(Flags&OGL_DOUBLEBUFFER)
	{
		Attrib[i++]=WGL_DOUBLE_BUFFER_ARB;
		Attrib[i++]=TRUE;
	}

	Attrib[i++]=WGL_PIXEL_TYPE_ARB;
	Attrib[i++]=WGL_TYPE_RGBA_ARB;

	Attrib[i++]=WGL_COLOR_BITS_ARB;
	Attrib[i++]=Color;
	Attrib[i++]=WGL_ACCUM_BITS_ARB;
	Attrib[i++]=Accum;
	Attrib[i++]=WGL_DEPTH_BITS_ARB;
	Attrib[i++]=Depth;
	Attrib[i++]=WGL_STENCIL_BITS_ARB;
	Attrib[i++]=Stencil;

	if(Flags&OGL_AUXBUFFERS1)
	{
		Attrib[i++]=WGL_AUX_BUFFERS_ARB;
		Attrib[i++]=1;
	}

	if(Flags&OGL_AUXBUFFERS2)
	{
		Attrib[i++]=WGL_AUX_BUFFERS_ARB;
		Attrib[i++]=2;
	}

	if(Flags&OGL_AUXBUFFERS3)
	{
		Attrib[i++]=WGL_AUX_BUFFERS_ARB;
		Attrib[i++]=3;
	}

	if(Flags&OGL_AUXBUFFERS4)
	{
		Attrib[i++]=WGL_AUX_BUFFERS_ARB;
		Attrib[i++]=4;
	}

	if(WGL_ARB_multisample_Flag)
	{
		if(Flags&OGL_SAMPLES2X)
		{
			Attrib[i++]=WGL_SAMPLE_BUFFERS_ARB;
			Attrib[i++]=TRUE;
			Attrib[i++]=WGL_SAMPLES_ARB;
			Attrib[i++]=2;
		}

		if(Flags&OGL_SAMPLES4X)
		{
			Attrib[i++]=WGL_SAMPLE_BUFFERS_ARB;
			Attrib[i++]=TRUE;
			Attrib[i++]=WGL_SAMPLES_ARB;
			Attrib[i++]=4;
		}

		if(Flags&OGL_SAMPLES6X)
		{
			Attrib[i++]=WGL_SAMPLE_BUFFERS_ARB;
			Attrib[i++]=TRUE;
			Attrib[i++]=WGL_SAMPLES_ARB;
			Attrib[i++]=6;
		}

		if(Flags&OGL_SAMPLES8X)
		{
			Attrib[i++]=WGL_SAMPLE_BUFFERS_ARB;
			Attrib[i++]=TRUE;
			Attrib[i++]=WGL_SAMPLES_ARB;
			Attrib[i++]=8;
		}
	}

	Attrib[i++]=0;

	if(!wglChoosePixelFormatARB(Context->hDC, Attrib, NULL, 1, &PixelFormat, &NumFormats))
	{
		MessageBox(Context->hWnd, "wglChoosePixelFormatARB failed!", NULL, MB_OK);
		return 0;
	}

	if(!SetPixelFormat(Context->hDC, PixelFormat, NULL))
	{
		MessageBox(Context->hWnd, "SetPixelFormat Failed!", NULL, MB_OK);
		return 0;
	}

	if(Flags&OGL_CORE33)
	{
		if(WGL_ARB_create_context_Flag)
		{
			i=0;
			ContextAttribs[i++]=WGL_CONTEXT_MAJOR_VERSION_ARB;
			ContextAttribs[i++]=3;
			ContextAttribs[i++]=WGL_CONTEXT_MINOR_VERSION_ARB;
			ContextAttribs[i++]=3;
			ContextAttribs[i++]=WGL_CONTEXT_FLAGS_ARB;
			ContextAttribs[i++]=WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB;
			ContextAttribs[i++]=0;

			if(!(Context->hRC=wglCreateContextAttribsARB(Context->hDC, 0, ContextAttribs)))
			{
				MessageBox(Context->hWnd, "wglCreateContextAttribsARB Failed!", NULL, MB_OK);
				return 0;
			}
		}
		else
		{
			MessageBox(Context->hWnd, "Requested OpenGL 3.3 CORE, WGL_ARB_create_context not supported!", NULL, MB_OK);
			return 0;
		}
	}
	else
	{
		if(!(Context->hRC=wglCreateContext(Context->hDC)))
		{
			MessageBox(Context->hWnd, "wglCreateContext Failed!", NULL, MB_OK);
			return 0;
		}
	}

	if(!wglMakeCurrent(Context->hDC, Context->hRC))
	{
		MessageBox(Context->hWnd, "wglMakeCurrent Failed!", NULL, MB_OK);
		return 0;
	}

	return 1;
#else
	int i, Attrib[128];
	int ContextAttribs[8];
	GLXFBConfig *fbconfig=NULL;

	if(!GLXExtensionsInitialized_Flag)
		GLXSetupExtensions(dpy);

	i=0;
	Attrib[i++]=GLX_DRAWABLE_TYPE;
	Attrib[i++]=GLX_WINDOW_BIT;
	Attrib[i++]=GLX_RENDER_TYPE;
	Attrib[i++]=GLX_RGBA_BIT;
	Attrib[i++]=GLX_DOUBLEBUFFER;
	Attrib[i++]=DoubleBuffer;
	Attrib[i++]=GLX_BUFFER_SIZE;
	Attrib[i++]=Color;
	Attrib[i++]=GLX_DEPTH_SIZE;
	Attrib[i++]=Depth;
	Attrib[i++]=GLX_STENCIL_SIZE;
	Attrib[i++]=Stencil;

	if(GLX_ARB_multisample_Flag&&SampleBuffers)
	{
		Attrib[i++]=GLX_SAMPLE_BUFFERS_ARB;
		Attrib[i++]=1;
		Attrib[i++]=GLX_SAMPLES_ARB;
		Attrib[i++]=SampleBuffers;
	}

	Attrib[i++]=None;

	if((fbconfig=glXChooseFBConfig(dpy, DefaultScreen(dpy), Attrib, &i))==NULL)
	{
		fprintf(stderr, "Error: glXChooseFBConfig failed\n");
		return 0;
	}

	if(Flags&OGL_CORE33)
	{
		if(GLX_ARB_create_context_Flag)
		{
			ContextAttribs[i++]=GLX_CONTEXT_MAJOR_VERSION_ARB;
			ContextAttribs[i++]=3;
			ContextAttribs[i++]=GLX_CONTEXT_MINOR_VERSION_ARB;
			ContextAttribs[i++]=3;
			ContextAttribs[i++]=GLX_CONTEXT_FLAGS_ARB;
			ContextAttribs[i++]=GLX_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB;
			ContextAttribs[i++]=None;

			Context->ctx=glXCreateContextAttribsARB(dpy, fbconfig[0], 0, GL_TRUE, ContextAttribs);
		}
		else
		{
			fprintf(stderr, "Error: Requested OpenGL 3.3 CORE, GLX_ARB_create_context not supported!\n");
			return 0;
		}
	}
	else
	{
		if((Context->ctx=glXCreateNewContext(dpy, fbconfig[0], GLX_RGBA, NULL, GL_TRUE))==NULL)
		{
			fprintf(stderr, "Error: glXCreateContext failed\n");
			return 0;
		}
	}

	glXGetFBConfigAttrib(dpy, fbconfig[0], GLX_VISUAL_ID, &Context->visualid);

	if(!GLExtensionsInitialized_Flag)
	{
		XVisualInfo *visinfo=glXGetVisualFromFBConfig(dpy, fbconfig[0]);
		Window win=XCreateWindow(dpy, RootWindow(dpy, DefaultScreen(dpy)), 0, 0, 1, 1, 0, 0, 0, 0, 0, 0);

		glXMakeCurrent(dpy, win, Context->ctx);
		GLSetupExtensions();
		glXMakeCurrent(dpy, 0, NULL);

		XDestroyWindow(dpy, win);
		XFree(visinfo);
	}

	return 1;
#endif
}

void DestroyContext(GLContext_t *Context)
{
#ifdef WIN32
	wglMakeCurrent(NULL, NULL);
	wglDeleteContext(Context->hRC);
	ReleaseDC(Context->hWnd, Context->hDC);
#else
	glXDestroyContext(dpy, Context->ctx);
#endif

	memset(Context, 0, sizeof(GLContext_t));
}
