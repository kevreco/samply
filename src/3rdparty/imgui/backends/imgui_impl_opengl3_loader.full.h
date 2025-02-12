//-----------------------------------------------------------------------------
// About imgui_impl_opengl3_loader.h:
//
// We embed our own OpenGL loader to not require user to provide their own or to have to use ours,
// which proved to be endless problems for users.
// Our loader is custom-generated, based on gl3w but automatically filtered to only include
// enums/functions that we use in our imgui_impl_opengl3.cpp source file in order to be small.
//
// YOU SHOULD NOT NEED TO INCLUDE/USE THIS DIRECTLY. THIS IS USED BY imgui_impl_opengl3.cpp ONLY.
// THE REST OF YOUR APP SHOULD USE A DIFFERENT GL LOADER: ANY GL LOADER OF YOUR CHOICE.
//
// IF YOU GET BUILD ERRORS IN THIS FILE (commonly macro redefinitions or function redefinitions):
// IT LIKELY MEANS THAT YOU ARE BUILDING 'imgui_impl_opengl3.cpp' OR INCLUDING 'imgui_impl_opengl3_loader.h'
// IN THE SAME COMPILATION UNIT AS ONE OF YOUR FILE WHICH IS USING A THIRD-PARTY OPENGL LOADER.
// (e.g. COULD HAPPEN IF YOU ARE DOING A UNITY/JUMBO BUILD, OR INCLUDING .CPP FILES FROM OTHERS)
// YOU SHOULD NOT BUILD BOTH IN THE SAME COMPILATION UNIT.
// BUT IF YOU REALLY WANT TO, you can '#define IMGUI_IMPL_OPENGL_LOADER_CUSTOM' and imgui_impl_opengl3.cpp
// WILL NOT BE USING OUR LOADER, AND INSTEAD EXPECT ANOTHER/YOUR LOADER TO BE AVAILABLE IN THE COMPILATION UNIT.
//
// Regenerate with:
//   python3 gl3w_gen.py --output ../imgui/backends/imgui_impl_opengl3_loader.h --ref ../imgui/backends/imgui_impl_opengl3.cpp ./extra_symbols.txt
//
// More info:
//   https://github.com/dearimgui/gl3w_stripped
//   https://github.com/ocornut/imgui/issues/4445
//-----------------------------------------------------------------------------

/*
 * This file was generated with gl3w_gen.py, part of imgl3w
 * (hosted at https://github.com/dearimgui/gl3w_stripped)
 *
 * This is free and unencumbered software released into the public domain.
 *
 * Anyone is free to copy, modify, publish, use, compile, sell, or
 * distribute this software, either in source code form or as a compiled
 * binary, for any purpose, commercial or non-commercial, and by any
 * means.
 *
 * In jurisdictions that recognize copyright laws, the author or authors
 * of this software dedicate any and all copyright interest in the
 * software to the public domain. We make this dedication for the benefit
 * of the public at large and to the detriment of our heirs and
 * successors. We intend this dedication to be an overt act of
 * relinquishment in perpetuity of all present and future rights to this
 * software under copyright law.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef __gl3w_h_
#define __gl3w_h_

// Adapted from KHR/khrplatform.h to avoid including entire file.
#ifndef __khrplatform_h_
typedef          float         khronos_float_t;
typedef signed   char          khronos_int8_t;
typedef unsigned char          khronos_uint8_t;
typedef signed   short int     khronos_int16_t;
typedef unsigned short int     khronos_uint16_t;
#ifdef _WIN64
typedef signed   long long int khronos_intptr_t;
typedef signed   long long int khronos_ssize_t;
#else
typedef signed   long  int     khronos_intptr_t;
typedef signed   long  int     khronos_ssize_t;
#endif

#if defined(_MSC_VER) && !defined(__clang__)
typedef signed   __int64       khronos_int64_t;
typedef unsigned __int64       khronos_uint64_t;
#elif (defined(__clang__) || defined(__GNUC__)) && (__cplusplus < 201100)
#include <stdint.h>
typedef          int64_t       khronos_int64_t;
typedef          uint64_t      khronos_uint64_t;
#else
typedef signed   long long     khronos_int64_t;
typedef unsigned long long     khronos_uint64_t;
#endif
#endif  // __khrplatform_h_

#ifndef __gl_glcorearb_h_
#define __gl_glcorearb_h_ 1
#ifdef __cplusplus
extern "C" {
#endif
/*
** Copyright 2013-2020 The Khronos Group Inc.
** SPDX-License-Identifier: MIT
**
** This header is generated from the Khronos OpenGL / OpenGL ES XML
** API Registry. The current version of the Registry, generator scripts
** used to make the header, and the header can be found at
**   https://github.com/KhronosGroup/OpenGL-Registry
*/
#if defined(_WIN32) && !defined(APIENTRY) && !defined(__CYGWIN__) && !defined(__SCITECH_SNAP__)
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN 1
#endif
#include <windows.h>
#endif
#ifndef APIENTRY
#define APIENTRY
#endif
#ifndef APIENTRYP
#define APIENTRYP APIENTRY *
#endif
#ifndef GLAPI
#define GLAPI extern
#endif
/* glcorearb.h is for use with OpenGL core profile implementations.
** It should should be placed in the same directory as gl.h and
** included as <GL/glcorearb.h>.
**
** glcorearb.h includes only APIs in the latest OpenGL core profile
** implementation together with APIs in newer ARB extensions which 
** can be supported by the core profile. It does not, and never will
** include functionality removed from the core profile, such as
** fixed-function vertex and fragment processing.
**
** Do not #include both <GL/glcorearb.h> and either of <GL/gl.h> or
** <GL/glext.h> in the same source file.
*/
/* Generated C header for:
 * API: gl
 * Profile: core
 * Versions considered: .*
 * Versions emitted: .*
 * Default extensions included: glcore
 * Additional extensions included: _nomatch_^
 * Extensions removed: _nomatch_^
 */
#ifndef GL_VERSION_1_0
#define GL_VERSION_1_0 1
typedef void GLvoid;
typedef unsigned int GLenum;

typedef khronos_float_t GLfloat;
typedef int GLint;
typedef int GLsizei;
typedef unsigned int GLbitfield;
typedef double GLdouble;
typedef unsigned int GLuint;
typedef unsigned char GLboolean;
typedef khronos_uint8_t GLubyte;
#define GL_DEPTH_BUFFER_BIT               0x00000100
#define GL_STENCIL_BUFFER_BIT             0x00000400
#define GL_COLOR_BUFFER_BIT               0x00004000
#define GL_FALSE                          0
#define GL_TRUE                           1
#define GL_POINTS                         0x0000
#define GL_LINES                          0x0001
#define GL_LINE_LOOP                      0x0002
#define GL_LINE_STRIP                     0x0003
#define GL_TRIANGLES                      0x0004
#define GL_TRIANGLE_STRIP                 0x0005
#define GL_TRIANGLE_FAN                   0x0006
#define GL_QUADS                          0x0007
#define GL_NEVER                          0x0200
#define GL_LESS                           0x0201
#define GL_EQUAL                          0x0202
#define GL_LEQUAL                         0x0203
#define GL_GREATER                        0x0204
#define GL_NOTEQUAL                       0x0205
#define GL_GEQUAL                         0x0206
#define GL_ALWAYS                         0x0207
#define GL_ZERO                           0
#define GL_ONE                            1
#define GL_SRC_COLOR                      0x0300
#define GL_ONE_MINUS_SRC_COLOR            0x0301
#define GL_SRC_ALPHA                      0x0302
#define GL_ONE_MINUS_SRC_ALPHA            0x0303
#define GL_DST_ALPHA                      0x0304
#define GL_ONE_MINUS_DST_ALPHA            0x0305
#define GL_DST_COLOR                      0x0306
#define GL_ONE_MINUS_DST_COLOR            0x0307
#define GL_SRC_ALPHA_SATURATE             0x0308
#define GL_NONE                           0
#define GL_FRONT_LEFT                     0x0400
#define GL_FRONT_RIGHT                    0x0401
#define GL_BACK_LEFT                      0x0402
#define GL_BACK_RIGHT                     0x0403
#define GL_FRONT                          0x0404
#define GL_BACK                           0x0405
#define GL_LEFT                           0x0406
#define GL_RIGHT                          0x0407
#define GL_FRONT_AND_BACK                 0x0408
#define GL_NO_ERROR                       0
#define GL_INVALID_ENUM                   0x0500
#define GL_INVALID_VALUE                  0x0501
#define GL_INVALID_OPERATION              0x0502
#define GL_OUT_OF_MEMORY                  0x0505
#define GL_CW                             0x0900
#define GL_CCW                            0x0901
#define GL_POINT_SIZE                     0x0B11
#define GL_POINT_SIZE_RANGE               0x0B12
#define GL_POINT_SIZE_GRANULARITY         0x0B13
#define GL_LINE_SMOOTH                    0x0B20
#define GL_LINE_WIDTH                     0x0B21
#define GL_LINE_WIDTH_RANGE               0x0B22
#define GL_LINE_WIDTH_GRANULARITY         0x0B23
#define GL_POLYGON_MODE                   0x0B40
#define GL_POLYGON_SMOOTH                 0x0B41
#define GL_CULL_FACE                      0x0B44
#define GL_CULL_FACE_MODE                 0x0B45
#define GL_FRONT_FACE                     0x0B46
#define GL_DEPTH_RANGE                    0x0B70
#define GL_DEPTH_TEST                     0x0B71
#define GL_DEPTH_WRITEMASK                0x0B72
#define GL_DEPTH_CLEAR_VALUE              0x0B73
#define GL_DEPTH_FUNC                     0x0B74
#define GL_STENCIL_TEST                   0x0B90
#define GL_STENCIL_CLEAR_VALUE            0x0B91
#define GL_STENCIL_FUNC                   0x0B92
#define GL_STENCIL_VALUE_MASK             0x0B93
#define GL_STENCIL_FAIL                   0x0B94
#define GL_STENCIL_PASS_DEPTH_FAIL        0x0B95
#define GL_STENCIL_PASS_DEPTH_PASS        0x0B96
#define GL_STENCIL_REF                    0x0B97
#define GL_STENCIL_WRITEMASK              0x0B98
#define GL_VIEWPORT                       0x0BA2
#define GL_DITHER                         0x0BD0
#define GL_BLEND_DST                      0x0BE0
#define GL_BLEND_SRC                      0x0BE1
#define GL_BLEND                          0x0BE2
#define GL_LOGIC_OP_MODE                  0x0BF0
#define GL_DRAW_BUFFER                    0x0C01
#define GL_READ_BUFFER                    0x0C02
#define GL_SCISSOR_BOX                    0x0C10
#define GL_SCISSOR_TEST                   0x0C11
#define GL_COLOR_CLEAR_VALUE              0x0C22
#define GL_COLOR_WRITEMASK                0x0C23
#define GL_DOUBLEBUFFER                   0x0C32
#define GL_STEREO                         0x0C33
#define GL_LINE_SMOOTH_HINT               0x0C52
#define GL_POLYGON_SMOOTH_HINT            0x0C53
#define GL_UNPACK_SWAP_BYTES              0x0CF0
#define GL_UNPACK_LSB_FIRST               0x0CF1
#define GL_UNPACK_ROW_LENGTH              0x0CF2
#define GL_UNPACK_SKIP_ROWS               0x0CF3
#define GL_UNPACK_SKIP_PIXELS             0x0CF4
#define GL_UNPACK_ALIGNMENT               0x0CF5
#define GL_PACK_SWAP_BYTES                0x0D00
#define GL_PACK_LSB_FIRST                 0x0D01
#define GL_PACK_ROW_LENGTH                0x0D02
#define GL_PACK_SKIP_ROWS                 0x0D03
#define GL_PACK_SKIP_PIXELS               0x0D04
#define GL_PACK_ALIGNMENT                 0x0D05
#define GL_MAX_TEXTURE_SIZE               0x0D33
#define GL_MAX_VIEWPORT_DIMS              0x0D3A
#define GL_SUBPIXEL_BITS                  0x0D50
#define GL_TEXTURE_1D                     0x0DE0
#define GL_TEXTURE_2D                     0x0DE1
#define GL_TEXTURE_WIDTH                  0x1000
#define GL_TEXTURE_HEIGHT                 0x1001
#define GL_TEXTURE_BORDER_COLOR           0x1004
#define GL_DONT_CARE                      0x1100
#define GL_FASTEST                        0x1101
#define GL_NICEST                         0x1102
#define GL_BYTE                           0x1400
#define GL_UNSIGNED_BYTE                  0x1401
#define GL_SHORT                          0x1402
#define GL_UNSIGNED_SHORT                 0x1403
#define GL_INT                            0x1404
#define GL_UNSIGNED_INT                   0x1405
#define GL_FLOAT                          0x1406
#define GL_STACK_OVERFLOW                 0x0503
#define GL_STACK_UNDERFLOW                0x0504
#define GL_CLEAR                          0x1500
#define GL_AND                            0x1501
#define GL_AND_REVERSE                    0x1502
#define GL_COPY                           0x1503
#define GL_AND_INVERTED                   0x1504
#define GL_NOOP                           0x1505
#define GL_XOR                            0x1506
#define GL_OR                             0x1507
#define GL_NOR                            0x1508
#define GL_EQUIV                          0x1509
#define GL_INVERT                         0x150A
#define GL_OR_REVERSE                     0x150B
#define GL_COPY_INVERTED                  0x150C
#define GL_OR_INVERTED                    0x150D
#define GL_NAND                           0x150E
#define GL_SET                            0x150F
#define GL_TEXTURE                        0x1702
#define GL_COLOR                          0x1800
#define GL_DEPTH                          0x1801
#define GL_STENCIL                        0x1802
#define GL_STENCIL_INDEX                  0x1901
#define GL_DEPTH_COMPONENT                0x1902
#define GL_RED                            0x1903
#define GL_GREEN                          0x1904
#define GL_BLUE                           0x1905
#define GL_ALPHA                          0x1906
#define GL_RGB                            0x1907
#define GL_RGBA                           0x1908
#define GL_POINT                          0x1B00
#define GL_LINE                           0x1B01
#define GL_FILL                           0x1B02
#define GL_KEEP                           0x1E00
#define GL_REPLACE                        0x1E01
#define GL_INCR                           0x1E02
#define GL_DECR                           0x1E03
#define GL_VENDOR                         0x1F00
#define GL_RENDERER                       0x1F01
#define GL_VERSION                        0x1F02
#define GL_EXTENSIONS                     0x1F03
#define GL_NEAREST                        0x2600
#define GL_LINEAR                         0x2601
#define GL_NEAREST_MIPMAP_NEAREST         0x2700
#define GL_LINEAR_MIPMAP_NEAREST          0x2701
#define GL_NEAREST_MIPMAP_LINEAR          0x2702
#define GL_LINEAR_MIPMAP_LINEAR           0x2703
#define GL_TEXTURE_MAG_FILTER             0x2800
#define GL_TEXTURE_MIN_FILTER             0x2801
#define GL_TEXTURE_WRAP_S                 0x2802
#define GL_TEXTURE_WRAP_T                 0x2803
#define GL_REPEAT                         0x2901
typedef void (APIENTRYP PFNGLCULLFACEPROC) (GLenum mode);
typedef void (APIENTRYP PFNGLFRONTFACEPROC) (GLenum mode);
typedef void (APIENTRYP PFNGLHINTPROC) (GLenum target, GLenum mode);
typedef void (APIENTRYP PFNGLLINEWIDTHPROC) (GLfloat width);
typedef void (APIENTRYP PFNGLPOINTSIZEPROC) (GLfloat size);
typedef void (APIENTRYP PFNGLPOLYGONMODEPROC) (GLenum face, GLenum mode);
typedef void (APIENTRYP PFNGLSCISSORPROC) (GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLTEXPARAMETERFPROC) (GLenum target, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLTEXPARAMETERFVPROC) (GLenum target, GLenum pname, const GLfloat *params);
typedef void (APIENTRYP PFNGLTEXPARAMETERIPROC) (GLenum target, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLTEXPARAMETERIVPROC) (GLenum target, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLTEXIMAGE1DPROC) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLTEXIMAGE2DPROC) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLDRAWBUFFERPROC) (GLenum buf);
typedef void (APIENTRYP PFNGLCLEARPROC) (GLbitfield mask);
typedef void (APIENTRYP PFNGLCLEARCOLORPROC) (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
typedef void (APIENTRYP PFNGLCLEARSTENCILPROC) (GLint s);
typedef void (APIENTRYP PFNGLCLEARDEPTHPROC) (GLdouble depth);
typedef void (APIENTRYP PFNGLSTENCILMASKPROC) (GLuint mask);
typedef void (APIENTRYP PFNGLCOLORMASKPROC) (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
typedef void (APIENTRYP PFNGLDEPTHMASKPROC) (GLboolean flag);
typedef void (APIENTRYP PFNGLDISABLEPROC) (GLenum cap);
typedef void (APIENTRYP PFNGLENABLEPROC) (GLenum cap);
typedef void (APIENTRYP PFNGLFINISHPROC) (void);
typedef void (APIENTRYP PFNGLFLUSHPROC) (void);
typedef void (APIENTRYP PFNGLBLENDFUNCPROC) (GLenum sfactor, GLenum dfactor);
typedef void (APIENTRYP PFNGLLOGICOPPROC) (GLenum opcode);
typedef void (APIENTRYP PFNGLSTENCILFUNCPROC) (GLenum func, GLint ref, GLuint mask);
typedef void (APIENTRYP PFNGLSTENCILOPPROC) (GLenum fail, GLenum zfail, GLenum zpass);
typedef void (APIENTRYP PFNGLDEPTHFUNCPROC) (GLenum func);
typedef void (APIENTRYP PFNGLPIXELSTOREFPROC) (GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLPIXELSTOREIPROC) (GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLREADBUFFERPROC) (GLenum src);
typedef void (APIENTRYP PFNGLREADPIXELSPROC) (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels);
typedef void (APIENTRYP PFNGLGETBOOLEANVPROC) (GLenum pname, GLboolean *data);
typedef void (APIENTRYP PFNGLGETDOUBLEVPROC) (GLenum pname, GLdouble *data);
typedef GLenum (APIENTRYP PFNGLGETERRORPROC) (void);
typedef void (APIENTRYP PFNGLGETFLOATVPROC) (GLenum pname, GLfloat *data);
typedef void (APIENTRYP PFNGLGETINTEGERVPROC) (GLenum pname, GLint *data);
typedef const GLubyte *(APIENTRYP PFNGLGETSTRINGPROC) (GLenum name);
typedef void (APIENTRYP PFNGLGETTEXIMAGEPROC) (GLenum target, GLint level, GLenum format, GLenum type, void *pixels);
typedef void (APIENTRYP PFNGLGETTEXPARAMETERFVPROC) (GLenum target, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETTEXPARAMETERIVPROC) (GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETTEXLEVELPARAMETERFVPROC) (GLenum target, GLint level, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETTEXLEVELPARAMETERIVPROC) (GLenum target, GLint level, GLenum pname, GLint *params);
typedef GLboolean (APIENTRYP PFNGLISENABLEDPROC) (GLenum cap);
typedef void (APIENTRYP PFNGLDEPTHRANGEPROC) (GLdouble n, GLdouble f);
typedef void (APIENTRYP PFNGLVIEWPORTPROC) (GLint x, GLint y, GLsizei width, GLsizei height);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glCullFace (GLenum mode);
GLAPI void APIENTRY glFrontFace (GLenum mode);
GLAPI void APIENTRY glHint (GLenum target, GLenum mode);
GLAPI void APIENTRY glLineWidth (GLfloat width);
GLAPI void APIENTRY glPointSize (GLfloat size);
GLAPI void APIENTRY glPolygonMode (GLenum face, GLenum mode);
GLAPI void APIENTRY glScissor (GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI void APIENTRY glTexParameterf (GLenum target, GLenum pname, GLfloat param);
GLAPI void APIENTRY glTexParameterfv (GLenum target, GLenum pname, const GLfloat *params);
GLAPI void APIENTRY glTexParameteri (GLenum target, GLenum pname, GLint param);
GLAPI void APIENTRY glTexParameteriv (GLenum target, GLenum pname, const GLint *params);
GLAPI void APIENTRY glTexImage1D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels);
GLAPI void APIENTRY glTexImage2D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
GLAPI void APIENTRY glDrawBuffer (GLenum buf);
GLAPI void APIENTRY glClear (GLbitfield mask);
GLAPI void APIENTRY glClearColor (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
GLAPI void APIENTRY glClearStencil (GLint s);
GLAPI void APIENTRY glClearDepth (GLdouble depth);
GLAPI void APIENTRY glStencilMask (GLuint mask);
GLAPI void APIENTRY glColorMask (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
GLAPI void APIENTRY glDepthMask (GLboolean flag);
GLAPI void APIENTRY glDisable (GLenum cap);
GLAPI void APIENTRY glEnable (GLenum cap);
GLAPI void APIENTRY glFinish (void);
GLAPI void APIENTRY glFlush (void);
GLAPI void APIENTRY glBlendFunc (GLenum sfactor, GLenum dfactor);
GLAPI void APIENTRY glLogicOp (GLenum opcode);
GLAPI void APIENTRY glStencilFunc (GLenum func, GLint ref, GLuint mask);
GLAPI void APIENTRY glStencilOp (GLenum fail, GLenum zfail, GLenum zpass);
GLAPI void APIENTRY glDepthFunc (GLenum func);
GLAPI void APIENTRY glPixelStoref (GLenum pname, GLfloat param);
GLAPI void APIENTRY glPixelStorei (GLenum pname, GLint param);
GLAPI void APIENTRY glReadBuffer (GLenum src);
GLAPI void APIENTRY glReadPixels (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels);
GLAPI void APIENTRY glGetBooleanv (GLenum pname, GLboolean *data);
GLAPI void APIENTRY glGetDoublev (GLenum pname, GLdouble *data);
GLAPI GLenum APIENTRY glGetError (void);
GLAPI void APIENTRY glGetFloatv (GLenum pname, GLfloat *data);
GLAPI void APIENTRY glGetIntegerv (GLenum pname, GLint *data);
GLAPI const GLubyte *APIENTRY glGetString (GLenum name);
GLAPI void APIENTRY glGetTexImage (GLenum target, GLint level, GLenum format, GLenum type, void *pixels);
GLAPI void APIENTRY glGetTexParameterfv (GLenum target, GLenum pname, GLfloat *params);
GLAPI void APIENTRY glGetTexParameteriv (GLenum target, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetTexLevelParameterfv (GLenum target, GLint level, GLenum pname, GLfloat *params);
GLAPI void APIENTRY glGetTexLevelParameteriv (GLenum target, GLint level, GLenum pname, GLint *params);
GLAPI GLboolean APIENTRY glIsEnabled (GLenum cap);
GLAPI void APIENTRY glDepthRange (GLdouble n, GLdouble f);
GLAPI void APIENTRY glViewport (GLint x, GLint y, GLsizei width, GLsizei height);
#endif
#endif /* GL_VERSION_1_0 */
#ifndef GL_VERSION_1_1
#define GL_VERSION_1_1 1
typedef khronos_float_t GLclampf;
typedef double GLclampd;
#define GL_COLOR_LOGIC_OP                 0x0BF2
#define GL_POLYGON_OFFSET_UNITS           0x2A00
#define GL_POLYGON_OFFSET_POINT           0x2A01
#define GL_POLYGON_OFFSET_LINE            0x2A02
#define GL_POLYGON_OFFSET_FILL            0x8037
#define GL_POLYGON_OFFSET_FACTOR          0x8038
#define GL_TEXTURE_BINDING_1D             0x8068
#define GL_TEXTURE_BINDING_2D             0x8069
#define GL_TEXTURE_INTERNAL_FORMAT        0x1003
#define GL_TEXTURE_RED_SIZE               0x805C
#define GL_TEXTURE_GREEN_SIZE             0x805D
#define GL_TEXTURE_BLUE_SIZE              0x805E
#define GL_TEXTURE_ALPHA_SIZE             0x805F
#define GL_DOUBLE                         0x140A
#define GL_PROXY_TEXTURE_1D               0x8063
#define GL_PROXY_TEXTURE_2D               0x8064
#define GL_R3_G3_B2                       0x2A10
#define GL_RGB4                           0x804F
#define GL_RGB5                           0x8050
#define GL_RGB8                           0x8051
#define GL_RGB10                          0x8052
#define GL_RGB12                          0x8053
#define GL_RGB16                          0x8054
#define GL_RGBA2                          0x8055
#define GL_RGBA4                          0x8056
#define GL_RGB5_A1                        0x8057
#define GL_RGBA8                          0x8058
#define GL_RGB10_A2                       0x8059
#define GL_RGBA12                         0x805A
#define GL_RGBA16                         0x805B
#define GL_VERTEX_ARRAY                   0x8074
typedef void (APIENTRYP PFNGLDRAWARRAYSPROC) (GLenum mode, GLint first, GLsizei count);
typedef void (APIENTRYP PFNGLDRAWELEMENTSPROC) (GLenum mode, GLsizei count, GLenum type, const void *indices);
typedef void (APIENTRYP PFNGLGETPOINTERVPROC) (GLenum pname, void **params);
typedef void (APIENTRYP PFNGLPOLYGONOFFSETPROC) (GLfloat factor, GLfloat units);
typedef void (APIENTRYP PFNGLCOPYTEXIMAGE1DPROC) (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
typedef void (APIENTRYP PFNGLCOPYTEXIMAGE2DPROC) (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE1DPROC) (GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE2DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLTEXSUBIMAGE1DPROC) (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLTEXSUBIMAGE2DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLBINDTEXTUREPROC) (GLenum target, GLuint texture);
typedef void (APIENTRYP PFNGLDELETETEXTURESPROC) (GLsizei n, const GLuint *textures);
typedef void (APIENTRYP PFNGLGENTEXTURESPROC) (GLsizei n, GLuint *textures);
typedef GLboolean (APIENTRYP PFNGLISTEXTUREPROC) (GLuint texture);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glDrawArrays (GLenum mode, GLint first, GLsizei count);
GLAPI void APIENTRY glDrawElements (GLenum mode, GLsizei count, GLenum type, const void *indices);
GLAPI void APIENTRY glGetPointerv (GLenum pname, void **params);
GLAPI void APIENTRY glPolygonOffset (GLfloat factor, GLfloat units);
GLAPI void APIENTRY glCopyTexImage1D (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
GLAPI void APIENTRY glCopyTexImage2D (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
GLAPI void APIENTRY glCopyTexSubImage1D (GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
GLAPI void APIENTRY glCopyTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI void APIENTRY glTexSubImage1D (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
GLAPI void APIENTRY glTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
GLAPI void APIENTRY glBindTexture (GLenum target, GLuint texture);
GLAPI void APIENTRY glDeleteTextures (GLsizei n, const GLuint *textures);
GLAPI void APIENTRY glGenTextures (GLsizei n, GLuint *textures);
GLAPI GLboolean APIENTRY glIsTexture (GLuint texture);
#endif
#endif /* GL_VERSION_1_1 */
#ifndef GL_VERSION_1_2
#define GL_VERSION_1_2 1
#define GL_UNSIGNED_BYTE_3_3_2            0x8032
#define GL_UNSIGNED_SHORT_4_4_4_4         0x8033
#define GL_UNSIGNED_SHORT_5_5_5_1         0x8034
#define GL_UNSIGNED_INT_8_8_8_8           0x8035
#define GL_UNSIGNED_INT_10_10_10_2        0x8036
#define GL_TEXTURE_BINDING_3D             0x806A
#define GL_PACK_SKIP_IMAGES               0x806B
#define GL_PACK_IMAGE_HEIGHT              0x806C
#define GL_UNPACK_SKIP_IMAGES             0x806D
#define GL_UNPACK_IMAGE_HEIGHT            0x806E
#define GL_TEXTURE_3D                     0x806F
#define GL_PROXY_TEXTURE_3D               0x8070
#define GL_TEXTURE_DEPTH                  0x8071
#define GL_TEXTURE_WRAP_R                 0x8072
#define GL_MAX_3D_TEXTURE_SIZE            0x8073
#define GL_UNSIGNED_BYTE_2_3_3_REV        0x8362
#define GL_UNSIGNED_SHORT_5_6_5           0x8363
#define GL_UNSIGNED_SHORT_5_6_5_REV       0x8364
#define GL_UNSIGNED_SHORT_4_4_4_4_REV     0x8365
#define GL_UNSIGNED_SHORT_1_5_5_5_REV     0x8366
#define GL_UNSIGNED_INT_8_8_8_8_REV       0x8367
#define GL_UNSIGNED_INT_2_10_10_10_REV    0x8368
#define GL_BGR                            0x80E0
#define GL_BGRA                           0x80E1
#define GL_MAX_ELEMENTS_VERTICES          0x80E8
#define GL_MAX_ELEMENTS_INDICES           0x80E9
#define GL_CLAMP_TO_EDGE                  0x812F
#define GL_TEXTURE_MIN_LOD                0x813A
#define GL_TEXTURE_MAX_LOD                0x813B
#define GL_TEXTURE_BASE_LEVEL             0x813C
#define GL_TEXTURE_MAX_LEVEL              0x813D
#define GL_SMOOTH_POINT_SIZE_RANGE        0x0B12
#define GL_SMOOTH_POINT_SIZE_GRANULARITY  0x0B13
#define GL_SMOOTH_LINE_WIDTH_RANGE        0x0B22
#define GL_SMOOTH_LINE_WIDTH_GRANULARITY  0x0B23
#define GL_ALIASED_LINE_WIDTH_RANGE       0x846E
typedef void (APIENTRYP PFNGLDRAWRANGEELEMENTSPROC) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices);
typedef void (APIENTRYP PFNGLTEXIMAGE3DPROC) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLTEXSUBIMAGE3DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE3DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glDrawRangeElements (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices);
GLAPI void APIENTRY glTexImage3D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
GLAPI void APIENTRY glTexSubImage3D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
GLAPI void APIENTRY glCopyTexSubImage3D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#endif
#endif /* GL_VERSION_1_2 */
#ifndef GL_VERSION_1_3
#define GL_VERSION_1_3 1
#define GL_TEXTURE0                       0x84C0
#define GL_TEXTURE1                       0x84C1
#define GL_TEXTURE2                       0x84C2
#define GL_TEXTURE3                       0x84C3
#define GL_TEXTURE4                       0x84C4
#define GL_TEXTURE5                       0x84C5
#define GL_TEXTURE6                       0x84C6
#define GL_TEXTURE7                       0x84C7
#define GL_TEXTURE8                       0x84C8
#define GL_TEXTURE9                       0x84C9
#define GL_TEXTURE10                      0x84CA
#define GL_TEXTURE11                      0x84CB
#define GL_TEXTURE12                      0x84CC
#define GL_TEXTURE13                      0x84CD
#define GL_TEXTURE14                      0x84CE
#define GL_TEXTURE15                      0x84CF
#define GL_TEXTURE16                      0x84D0
#define GL_TEXTURE17                      0x84D1
#define GL_TEXTURE18                      0x84D2
#define GL_TEXTURE19                      0x84D3
#define GL_TEXTURE20                      0x84D4
#define GL_TEXTURE21                      0x84D5
#define GL_TEXTURE22                      0x84D6
#define GL_TEXTURE23                      0x84D7
#define GL_TEXTURE24                      0x84D8
#define GL_TEXTURE25                      0x84D9
#define GL_TEXTURE26                      0x84DA
#define GL_TEXTURE27                      0x84DB
#define GL_TEXTURE28                      0x84DC
#define GL_TEXTURE29                      0x84DD
#define GL_TEXTURE30                      0x84DE
#define GL_TEXTURE31                      0x84DF
#define GL_ACTIVE_TEXTURE                 0x84E0
#define GL_MULTISAMPLE                    0x809D
#define GL_SAMPLE_ALPHA_TO_COVERAGE       0x809E
#define GL_SAMPLE_ALPHA_TO_ONE            0x809F
#define GL_SAMPLE_COVERAGE                0x80A0
#define GL_SAMPLE_BUFFERS                 0x80A8
#define GL_SAMPLES                        0x80A9
#define GL_SAMPLE_COVERAGE_VALUE          0x80AA
#define GL_SAMPLE_COVERAGE_INVERT         0x80AB
#define GL_TEXTURE_CUBE_MAP               0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP       0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X    0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X    0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y    0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y    0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z    0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z    0x851A
#define GL_PROXY_TEXTURE_CUBE_MAP         0x851B
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE      0x851C
#define GL_COMPRESSED_RGB                 0x84ED
#define GL_COMPRESSED_RGBA                0x84EE
#define GL_TEXTURE_COMPRESSION_HINT       0x84EF
#define GL_TEXTURE_COMPRESSED_IMAGE_SIZE  0x86A0
#define GL_TEXTURE_COMPRESSED             0x86A1
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS 0x86A2
#define GL_COMPRESSED_TEXTURE_FORMATS     0x86A3
#define GL_CLAMP_TO_BORDER                0x812D
typedef void (APIENTRYP PFNGLACTIVETEXTUREPROC) (GLenum texture);
typedef void (APIENTRYP PFNGLSAMPLECOVERAGEPROC) (GLfloat value, GLboolean invert);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE3DPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE2DPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE1DPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC) (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLGETCOMPRESSEDTEXIMAGEPROC) (GLenum target, GLint level, void *img);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glActiveTexture (GLenum texture);
GLAPI void APIENTRY glSampleCoverage (GLfloat value, GLboolean invert);
GLAPI void APIENTRY glCompressedTexImage3D (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data);
GLAPI void APIENTRY glCompressedTexImage2D (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data);
GLAPI void APIENTRY glCompressedTexImage1D (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data);
GLAPI void APIENTRY glCompressedTexSubImage3D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
GLAPI void APIENTRY glCompressedTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
GLAPI void APIENTRY glCompressedTexSubImage1D (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
GLAPI void APIENTRY glGetCompressedTexImage (GLenum target, GLint level, void *img);
#endif
#endif /* GL_VERSION_1_3 */
#ifndef GL_VERSION_1_4
#define GL_VERSION_1_4 1
#define GL_BLEND_DST_RGB                  0x80C8
#define GL_BLEND_SRC_RGB                  0x80C9
#define GL_BLEND_DST_ALPHA                0x80CA
#define GL_BLEND_SRC_ALPHA                0x80CB
#define GL_POINT_FADE_THRESHOLD_SIZE      0x8128
#define GL_DEPTH_COMPONENT16              0x81A5
#define GL_DEPTH_COMPONENT24              0x81A6
#define GL_DEPTH_COMPONENT32              0x81A7
#define GL_MIRRORED_REPEAT                0x8370
#define GL_MAX_TEXTURE_LOD_BIAS           0x84FD
#define GL_TEXTURE_LOD_BIAS               0x8501
#define GL_INCR_WRAP                      0x8507
#define GL_DECR_WRAP                      0x8508
#define GL_TEXTURE_DEPTH_SIZE             0x884A
#define GL_TEXTURE_COMPARE_MODE           0x884C
#define GL_TEXTURE_COMPARE_FUNC           0x884D
#define GL_BLEND_COLOR                    0x8005
#define GL_BLEND_EQUATION                 0x8009
#define GL_CONSTANT_COLOR                 0x8001
#define GL_ONE_MINUS_CONSTANT_COLOR       0x8002
#define GL_CONSTANT_ALPHA                 0x8003
#define GL_ONE_MINUS_CONSTANT_ALPHA       0x8004
#define GL_FUNC_ADD                       0x8006
#define GL_FUNC_REVERSE_SUBTRACT          0x800B
#define GL_FUNC_SUBTRACT                  0x800A
#define GL_MIN                            0x8007
#define GL_MAX                            0x8008
typedef void (APIENTRYP PFNGLBLENDFUNCSEPARATEPROC) (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSPROC) (GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount);
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSPROC) (GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount);
typedef void (APIENTRYP PFNGLPOINTPARAMETERFPROC) (GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLPOINTPARAMETERFVPROC) (GLenum pname, const GLfloat *params);
typedef void (APIENTRYP PFNGLPOINTPARAMETERIPROC) (GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLPOINTPARAMETERIVPROC) (GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLBLENDCOLORPROC) (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
typedef void (APIENTRYP PFNGLBLENDEQUATIONPROC) (GLenum mode);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glBlendFuncSeparate (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
GLAPI void APIENTRY glMultiDrawArrays (GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount);
GLAPI void APIENTRY glMultiDrawElements (GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount);
GLAPI void APIENTRY glPointParameterf (GLenum pname, GLfloat param);
GLAPI void APIENTRY glPointParameterfv (GLenum pname, const GLfloat *params);
GLAPI void APIENTRY glPointParameteri (GLenum pname, GLint param);
GLAPI void APIENTRY glPointParameteriv (GLenum pname, const GLint *params);
GLAPI void APIENTRY glBlendColor (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
GLAPI void APIENTRY glBlendEquation (GLenum mode);
#endif
#endif /* GL_VERSION_1_4 */
#ifndef GL_VERSION_1_5
#define GL_VERSION_1_5 1
typedef khronos_ssize_t GLsizeiptr;
typedef khronos_intptr_t GLintptr;
#define GL_BUFFER_SIZE                    0x8764
#define GL_BUFFER_USAGE                   0x8765
#define GL_QUERY_COUNTER_BITS             0x8864
#define GL_CURRENT_QUERY                  0x8865
#define GL_QUERY_RESULT                   0x8866
#define GL_QUERY_RESULT_AVAILABLE         0x8867
#define GL_ARRAY_BUFFER                   0x8892
#define GL_ELEMENT_ARRAY_BUFFER           0x8893
#define GL_ARRAY_BUFFER_BINDING           0x8894
#define GL_ELEMENT_ARRAY_BUFFER_BINDING   0x8895
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING 0x889F
#define GL_READ_ONLY                      0x88B8
#define GL_WRITE_ONLY                     0x88B9
#define GL_READ_WRITE                     0x88BA
#define GL_BUFFER_ACCESS                  0x88BB
#define GL_BUFFER_MAPPED                  0x88BC
#define GL_BUFFER_MAP_POINTER             0x88BD
#define GL_STREAM_DRAW                    0x88E0
#define GL_STREAM_READ                    0x88E1
#define GL_STREAM_COPY                    0x88E2
#define GL_STATIC_DRAW                    0x88E4
#define GL_STATIC_READ                    0x88E5
#define GL_STATIC_COPY                    0x88E6
#define GL_DYNAMIC_DRAW                   0x88E8
#define GL_DYNAMIC_READ                   0x88E9
#define GL_DYNAMIC_COPY                   0x88EA
#define GL_SAMPLES_PASSED                 0x8914
#define GL_SRC1_ALPHA                     0x8589
typedef void (APIENTRYP PFNGLGENQUERIESPROC) (GLsizei n, GLuint *ids);
typedef void (APIENTRYP PFNGLDELETEQUERIESPROC) (GLsizei n, const GLuint *ids);
typedef GLboolean (APIENTRYP PFNGLISQUERYPROC) (GLuint id);
typedef void (APIENTRYP PFNGLBEGINQUERYPROC) (GLenum target, GLuint id);
typedef void (APIENTRYP PFNGLENDQUERYPROC) (GLenum target);
typedef void (APIENTRYP PFNGLGETQUERYIVPROC) (GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETQUERYOBJECTIVPROC) (GLuint id, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETQUERYOBJECTUIVPROC) (GLuint id, GLenum pname, GLuint *params);
typedef void (APIENTRYP PFNGLBINDBUFFERPROC) (GLenum target, GLuint buffer);
typedef void (APIENTRYP PFNGLDELETEBUFFERSPROC) (GLsizei n, const GLuint *buffers);
typedef void (APIENTRYP PFNGLGENBUFFERSPROC) (GLsizei n, GLuint *buffers);
typedef GLboolean (APIENTRYP PFNGLISBUFFERPROC) (GLuint buffer);
typedef void (APIENTRYP PFNGLBUFFERDATAPROC) (GLenum target, GLsizeiptr size, const void *data, GLenum usage);
typedef void (APIENTRYP PFNGLBUFFERSUBDATAPROC) (GLenum target, GLintptr offset, GLsizeiptr size, const void *data);
typedef void (APIENTRYP PFNGLGETBUFFERSUBDATAPROC) (GLenum target, GLintptr offset, GLsizeiptr size, void *data);
typedef void *(APIENTRYP PFNGLMAPBUFFERPROC) (GLenum target, GLenum access);
typedef GLboolean (APIENTRYP PFNGLUNMAPBUFFERPROC) (GLenum target);
typedef void (APIENTRYP PFNGLGETBUFFERPARAMETERIVPROC) (GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETBUFFERPOINTERVPROC) (GLenum target, GLenum pname, void **params);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glGenQueries (GLsizei n, GLuint *ids);
GLAPI void APIENTRY glDeleteQueries (GLsizei n, const GLuint *ids);
GLAPI GLboolean APIENTRY glIsQuery (GLuint id);
GLAPI void APIENTRY glBeginQuery (GLenum target, GLuint id);
GLAPI void APIENTRY glEndQuery (GLenum target);
GLAPI void APIENTRY glGetQueryiv (GLenum target, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetQueryObjectiv (GLuint id, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetQueryObjectuiv (GLuint id, GLenum pname, GLuint *params);
GLAPI void APIENTRY glBindBuffer (GLenum target, GLuint buffer);
GLAPI void APIENTRY glDeleteBuffers (GLsizei n, const GLuint *buffers);
GLAPI void APIENTRY glGenBuffers (GLsizei n, GLuint *buffers);
GLAPI GLboolean APIENTRY glIsBuffer (GLuint buffer);
GLAPI void APIENTRY glBufferData (GLenum target, GLsizeiptr size, const void *data, GLenum usage);
GLAPI void APIENTRY glBufferSubData (GLenum target, GLintptr offset, GLsizeiptr size, const void *data);
GLAPI void APIENTRY glGetBufferSubData (GLenum target, GLintptr offset, GLsizeiptr size, void *data);
GLAPI void *APIENTRY glMapBuffer (GLenum target, GLenum access);
GLAPI GLboolean APIENTRY glUnmapBuffer (GLenum target);
GLAPI void APIENTRY glGetBufferParameteriv (GLenum target, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetBufferPointerv (GLenum target, GLenum pname, void **params);
#endif
#endif /* GL_VERSION_1_5 */
#ifndef GL_VERSION_2_0
#define GL_VERSION_2_0 1
typedef char GLchar;
typedef khronos_int16_t GLshort;
typedef khronos_int8_t GLbyte;
typedef khronos_uint16_t GLushort;
#define GL_BLEND_EQUATION_RGB             0x8009
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED    0x8622
#define GL_VERTEX_ATTRIB_ARRAY_SIZE       0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE     0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE       0x8625
#define GL_CURRENT_VERTEX_ATTRIB          0x8626
#define GL_VERTEX_PROGRAM_POINT_SIZE      0x8642
#define GL_VERTEX_ATTRIB_ARRAY_POINTER    0x8645
#define GL_STENCIL_BACK_FUNC              0x8800
#define GL_STENCIL_BACK_FAIL              0x8801
#define GL_STENCIL_BACK_PASS_DEPTH_FAIL   0x8802
#define GL_STENCIL_BACK_PASS_DEPTH_PASS   0x8803
#define GL_MAX_DRAW_BUFFERS               0x8824
#define GL_DRAW_BUFFER0                   0x8825
#define GL_DRAW_BUFFER1                   0x8826
#define GL_DRAW_BUFFER2                   0x8827
#define GL_DRAW_BUFFER3                   0x8828
#define GL_DRAW_BUFFER4                   0x8829
#define GL_DRAW_BUFFER5                   0x882A
#define GL_DRAW_BUFFER6                   0x882B
#define GL_DRAW_BUFFER7                   0x882C
#define GL_DRAW_BUFFER8                   0x882D
#define GL_DRAW_BUFFER9                   0x882E
#define GL_DRAW_BUFFER10                  0x882F
#define GL_DRAW_BUFFER11                  0x8830
#define GL_DRAW_BUFFER12                  0x8831
#define GL_DRAW_BUFFER13                  0x8832
#define GL_DRAW_BUFFER14                  0x8833
#define GL_DRAW_BUFFER15                  0x8834
#define GL_BLEND_EQUATION_ALPHA           0x883D
#define GL_MAX_VERTEX_ATTRIBS             0x8869
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED 0x886A
#define GL_MAX_TEXTURE_IMAGE_UNITS        0x8872
#define GL_FRAGMENT_SHADER                0x8B30
#define GL_VERTEX_SHADER                  0x8B31
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS 0x8B49
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS  0x8B4A
#define GL_MAX_VARYING_FLOATS             0x8B4B
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS 0x8B4C
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS 0x8B4D
#define GL_SHADER_TYPE                    0x8B4F
#define GL_FLOAT_VEC2                     0x8B50
#define GL_FLOAT_VEC3                     0x8B51
#define GL_FLOAT_VEC4                     0x8B52
#define GL_INT_VEC2                       0x8B53
#define GL_INT_VEC3                       0x8B54
#define GL_INT_VEC4                       0x8B55
#define GL_BOOL                           0x8B56
#define GL_BOOL_VEC2                      0x8B57
#define GL_BOOL_VEC3                      0x8B58
#define GL_BOOL_VEC4                      0x8B59
#define GL_FLOAT_MAT2                     0x8B5A
#define GL_FLOAT_MAT3                     0x8B5B
#define GL_FLOAT_MAT4                     0x8B5C
#define GL_SAMPLER_1D                     0x8B5D
#define GL_SAMPLER_2D                     0x8B5E
#define GL_SAMPLER_3D                     0x8B5F
#define GL_SAMPLER_CUBE                   0x8B60
#define GL_SAMPLER_1D_SHADOW              0x8B61
#define GL_SAMPLER_2D_SHADOW              0x8B62
#define GL_DELETE_STATUS                  0x8B80
#define GL_COMPILE_STATUS                 0x8B81
#define GL_LINK_STATUS                    0x8B82
#define GL_VALIDATE_STATUS                0x8B83
#define GL_INFO_LOG_LENGTH                0x8B84
#define GL_ATTACHED_SHADERS               0x8B85
#define GL_ACTIVE_UNIFORMS                0x8B86
#define GL_ACTIVE_UNIFORM_MAX_LENGTH      0x8B87
#define GL_SHADER_SOURCE_LENGTH           0x8B88
#define GL_ACTIVE_ATTRIBUTES              0x8B89
#define GL_ACTIVE_ATTRIBUTE_MAX_LENGTH    0x8B8A
#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT 0x8B8B
#define GL_SHADING_LANGUAGE_VERSION       0x8B8C
#define GL_CURRENT_PROGRAM                0x8B8D
#define GL_POINT_SPRITE_COORD_ORIGIN      0x8CA0
#define GL_LOWER_LEFT                     0x8CA1
#define GL_UPPER_LEFT                     0x8CA2
#define GL_STENCIL_BACK_REF               0x8CA3
#define GL_STENCIL_BACK_VALUE_MASK        0x8CA4
#define GL_STENCIL_BACK_WRITEMASK         0x8CA5
typedef void (APIENTRYP PFNGLBLENDEQUATIONSEPARATEPROC) (GLenum modeRGB, GLenum modeAlpha);
typedef void (APIENTRYP PFNGLDRAWBUFFERSPROC) (GLsizei n, const GLenum *bufs);
typedef void (APIENTRYP PFNGLSTENCILOPSEPARATEPROC) (GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
typedef void (APIENTRYP PFNGLSTENCILFUNCSEPARATEPROC) (GLenum face, GLenum func, GLint ref, GLuint mask);
typedef void (APIENTRYP PFNGLSTENCILMASKSEPARATEPROC) (GLenum face, GLuint mask);
typedef void (APIENTRYP PFNGLATTACHSHADERPROC) (GLuint program, GLuint shader);
typedef void (APIENTRYP PFNGLBINDATTRIBLOCATIONPROC) (GLuint program, GLuint index, const GLchar *name);
typedef void (APIENTRYP PFNGLCOMPILESHADERPROC) (GLuint shader);
typedef GLuint (APIENTRYP PFNGLCREATEPROGRAMPROC) (void);
typedef GLuint (APIENTRYP PFNGLCREATESHADERPROC) (GLenum type);
typedef void (APIENTRYP PFNGLDELETEPROGRAMPROC) (GLuint program);
typedef void (APIENTRYP PFNGLDELETESHADERPROC) (GLuint shader);
typedef void (APIENTRYP PFNGLDETACHSHADERPROC) (GLuint program, GLuint shader);
typedef void (APIENTRYP PFNGLDISABLEVERTEXATTRIBARRAYPROC) (GLuint index);
typedef void (APIENTRYP PFNGLENABLEVERTEXATTRIBARRAYPROC) (GLuint index);
typedef void (APIENTRYP PFNGLGETACTIVEATTRIBPROC) (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMPROC) (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
typedef void (APIENTRYP PFNGLGETATTACHEDSHADERSPROC) (GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders);
typedef GLint (APIENTRYP PFNGLGETATTRIBLOCATIONPROC) (GLuint program, const GLchar *name);
typedef void (APIENTRYP PFNGLGETPROGRAMIVPROC) (GLuint program, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETPROGRAMINFOLOGPROC) (GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
typedef void (APIENTRYP PFNGLGETSHADERIVPROC) (GLuint shader, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETSHADERINFOLOGPROC) (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
typedef void (APIENTRYP PFNGLGETSHADERSOURCEPROC) (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source);
typedef GLint (APIENTRYP PFNGLGETUNIFORMLOCATIONPROC) (GLuint program, const GLchar *name);
typedef void (APIENTRYP PFNGLGETUNIFORMFVPROC) (GLuint program, GLint location, GLfloat *params);
typedef void (APIENTRYP PFNGLGETUNIFORMIVPROC) (GLuint program, GLint location, GLint *params);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBDVPROC) (GLuint index, GLenum pname, GLdouble *params);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBFVPROC) (GLuint index, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIVPROC) (GLuint index, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBPOINTERVPROC) (GLuint index, GLenum pname, void **pointer);
typedef GLboolean (APIENTRYP PFNGLISPROGRAMPROC) (GLuint program);
typedef GLboolean (APIENTRYP PFNGLISSHADERPROC) (GLuint shader);
typedef void (APIENTRYP PFNGLLINKPROGRAMPROC) (GLuint program);
typedef void (APIENTRYP PFNGLSHADERSOURCEPROC) (GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length);
typedef void (APIENTRYP PFNGLUSEPROGRAMPROC) (GLuint program);
typedef void (APIENTRYP PFNGLUNIFORM1FPROC) (GLint location, GLfloat v0);
typedef void (APIENTRYP PFNGLUNIFORM2FPROC) (GLint location, GLfloat v0, GLfloat v1);
typedef void (APIENTRYP PFNGLUNIFORM3FPROC) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
typedef void (APIENTRYP PFNGLUNIFORM4FPROC) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
typedef void (APIENTRYP PFNGLUNIFORM1IPROC) (GLint location, GLint v0);
typedef void (APIENTRYP PFNGLUNIFORM2IPROC) (GLint location, GLint v0, GLint v1);
typedef void (APIENTRYP PFNGLUNIFORM3IPROC) (GLint location, GLint v0, GLint v1, GLint v2);
typedef void (APIENTRYP PFNGLUNIFORM4IPROC) (GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
typedef void (APIENTRYP PFNGLUNIFORM1FVPROC) (GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORM2FVPROC) (GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORM3FVPROC) (GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORM4FVPROC) (GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORM1IVPROC) (GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLUNIFORM2IVPROC) (GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLUNIFORM3IVPROC) (GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLUNIFORM4IVPROC) (GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLVALIDATEPROGRAMPROC) (GLuint program);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1DPROC) (GLuint index, GLdouble x);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1DVPROC) (GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1FPROC) (GLuint index, GLfloat x);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1FVPROC) (GLuint index, const GLfloat *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1SPROC) (GLuint index, GLshort x);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1SVPROC) (GLuint index, const GLshort *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2DPROC) (GLuint index, GLdouble x, GLdouble y);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2DVPROC) (GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2FPROC) (GLuint index, GLfloat x, GLfloat y);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2FVPROC) (GLuint index, const GLfloat *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2SPROC) (GLuint index, GLshort x, GLshort y);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2SVPROC) (GLuint index, const GLshort *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3DPROC) (GLuint index, GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3DVPROC) (GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3FPROC) (GLuint index, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3FVPROC) (GLuint index, const GLfloat *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3SPROC) (GLuint index, GLshort x, GLshort y, GLshort z);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3SVPROC) (GLuint index, const GLshort *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NBVPROC) (GLuint index, const GLbyte *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NIVPROC) (GLuint index, const GLint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NSVPROC) (GLuint index, const GLshort *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUBPROC) (GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUBVPROC) (GLuint index, const GLubyte *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUIVPROC) (GLuint index, const GLuint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUSVPROC) (GLuint index, const GLushort *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4BVPROC) (GLuint index, const GLbyte *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4DPROC) (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4DVPROC) (GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4FPROC) (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4FVPROC) (GLuint index, const GLfloat *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4IVPROC) (GLuint index, const GLint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4SPROC) (GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4SVPROC) (GLuint index, const GLshort *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4UBVPROC) (GLuint index, const GLubyte *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4UIVPROC) (GLuint index, const GLuint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4USVPROC) (GLuint index, const GLushort *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBPOINTERPROC) (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glBlendEquationSeparate (GLenum modeRGB, GLenum modeAlpha);
GLAPI void APIENTRY glDrawBuffers (GLsizei n, const GLenum *bufs);
GLAPI void APIENTRY glStencilOpSeparate (GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
GLAPI void APIENTRY glStencilFuncSeparate (GLenum face, GLenum func, GLint ref, GLuint mask);
GLAPI void APIENTRY glStencilMaskSeparate (GLenum face, GLuint mask);
GLAPI void APIENTRY glAttachShader (GLuint program, GLuint shader);
GLAPI void APIENTRY glBindAttribLocation (GLuint program, GLuint index, const GLchar *name);
GLAPI void APIENTRY glCompileShader (GLuint shader);
GLAPI GLuint APIENTRY glCreateProgram (void);
GLAPI GLuint APIENTRY glCreateShader (GLenum type);
GLAPI void APIENTRY glDeleteProgram (GLuint program);
GLAPI void APIENTRY glDeleteShader (GLuint shader);
GLAPI void APIENTRY glDetachShader (GLuint program, GLuint shader);
GLAPI void APIENTRY glDisableVertexAttribArray (GLuint index);
GLAPI void APIENTRY glEnableVertexAttribArray (GLuint index);
GLAPI void APIENTRY glGetActiveAttrib (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
GLAPI void APIENTRY glGetActiveUniform (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
GLAPI void APIENTRY glGetAttachedShaders (GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders);
GLAPI GLint APIENTRY glGetAttribLocation (GLuint program, const GLchar *name);
GLAPI void APIENTRY glGetProgramiv (GLuint program, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetProgramInfoLog (GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
GLAPI void APIENTRY glGetShaderiv (GLuint shader, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetShaderInfoLog (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
GLAPI void APIENTRY glGetShaderSource (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source);
GLAPI GLint APIENTRY glGetUniformLocation (GLuint program, const GLchar *name);
GLAPI void APIENTRY glGetUniformfv (GLuint program, GLint location, GLfloat *params);
GLAPI void APIENTRY glGetUniformiv (GLuint program, GLint location, GLint *params);
GLAPI void APIENTRY glGetVertexAttribdv (GLuint index, GLenum pname, GLdouble *params);
GLAPI void APIENTRY glGetVertexAttribfv (GLuint index, GLenum pname, GLfloat *params);
GLAPI void APIENTRY glGetVertexAttribiv (GLuint index, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetVertexAttribPointerv (GLuint index, GLenum pname, void **pointer);
GLAPI GLboolean APIENTRY glIsProgram (GLuint program);
GLAPI GLboolean APIENTRY glIsShader (GLuint shader);
GLAPI void APIENTRY glLinkProgram (GLuint program);
GLAPI void APIENTRY glShaderSource (GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length);
GLAPI void APIENTRY glUseProgram (GLuint program);
GLAPI void APIENTRY glUniform1f (GLint location, GLfloat v0);
GLAPI void APIENTRY glUniform2f (GLint location, GLfloat v0, GLfloat v1);
GLAPI void APIENTRY glUniform3f (GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
GLAPI void APIENTRY glUniform4f (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
GLAPI void APIENTRY glUniform1i (GLint location, GLint v0);
GLAPI void APIENTRY glUniform2i (GLint location, GLint v0, GLint v1);
GLAPI void APIENTRY glUniform3i (GLint location, GLint v0, GLint v1, GLint v2);
GLAPI void APIENTRY glUniform4i (GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
GLAPI void APIENTRY glUniform1fv (GLint location, GLsizei count, const GLfloat *value);
GLAPI void APIENTRY glUniform2fv (GLint location, GLsizei count, const GLfloat *value);
GLAPI void APIENTRY glUniform3fv (GLint location, GLsizei count, const GLfloat *value);
GLAPI void APIENTRY glUniform4fv (GLint location, GLsizei count, const GLfloat *value);
GLAPI void APIENTRY glUniform1iv (GLint location, GLsizei count, const GLint *value);
GLAPI void APIENTRY glUniform2iv (GLint location, GLsizei count, const GLint *value);
GLAPI void APIENTRY glUniform3iv (GLint location, GLsizei count, const GLint *value);
GLAPI void APIENTRY glUniform4iv (GLint location, GLsizei count, const GLint *value);
GLAPI void APIENTRY glUniformMatrix2fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glUniformMatrix3fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glUniformMatrix4fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glValidateProgram (GLuint program);
GLAPI void APIENTRY glVertexAttrib1d (GLuint index, GLdouble x);
GLAPI void APIENTRY glVertexAttrib1dv (GLuint index, const GLdouble *v);
GLAPI void APIENTRY glVertexAttrib1f (GLuint index, GLfloat x);
GLAPI void APIENTRY glVertexAttrib1fv (GLuint index, const GLfloat *v);
GLAPI void APIENTRY glVertexAttrib1s (GLuint index, GLshort x);
GLAPI void APIENTRY glVertexAttrib1sv (GLuint index, const GLshort *v);
GLAPI void APIENTRY glVertexAttrib2d (GLuint index, GLdouble x, GLdouble y);
GLAPI void APIENTRY glVertexAttrib2dv (GLuint index, const GLdouble *v);
GLAPI void APIENTRY glVertexAttrib2f (GLuint index, GLfloat x, GLfloat y);
GLAPI void APIENTRY glVertexAttrib2fv (GLuint index, const GLfloat *v);
GLAPI void APIENTRY glVertexAttrib2s (GLuint index, GLshort x, GLshort y);
GLAPI void APIENTRY glVertexAttrib2sv (GLuint index, const GLshort *v);
GLAPI void APIENTRY glVertexAttrib3d (GLuint index, GLdouble x, GLdouble y, GLdouble z);
GLAPI void APIENTRY glVertexAttrib3dv (GLuint index, const GLdouble *v);
GLAPI void APIENTRY glVertexAttrib3f (GLuint index, GLfloat x, GLfloat y, GLfloat z);
GLAPI void APIENTRY glVertexAttrib3fv (GLuint index, const GLfloat *v);
GLAPI void APIENTRY glVertexAttrib3s (GLuint index, GLshort x, GLshort y, GLshort z);
GLAPI void APIENTRY glVertexAttrib3sv (GLuint index, const GLshort *v);
GLAPI void APIENTRY glVertexAttrib4Nbv (GLuint index, const GLbyte *v);
GLAPI void APIENTRY glVertexAttrib4Niv (GLuint index, const GLint *v);
GLAPI void APIENTRY glVertexAttrib4Nsv (GLuint index, const GLshort *v);
GLAPI void APIENTRY glVertexAttrib4Nub (GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
GLAPI void APIENTRY glVertexAttrib4Nubv (GLuint index, const GLubyte *v);
GLAPI void APIENTRY glVertexAttrib4Nuiv (GLuint index, const GLuint *v);
GLAPI void APIENTRY glVertexAttrib4Nusv (GLuint index, const GLushort *v);
GLAPI void APIENTRY glVertexAttrib4bv (GLuint index, const GLbyte *v);
GLAPI void APIENTRY glVertexAttrib4d (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI void APIENTRY glVertexAttrib4dv (GLuint index, const GLdouble *v);
GLAPI void APIENTRY glVertexAttrib4f (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GLAPI void APIENTRY glVertexAttrib4fv (GLuint index, const GLfloat *v);
GLAPI void APIENTRY glVertexAttrib4iv (GLuint index, const GLint *v);
GLAPI void APIENTRY glVertexAttrib4s (GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
GLAPI void APIENTRY glVertexAttrib4sv (GLuint index, const GLshort *v);
GLAPI void APIENTRY glVertexAttrib4ubv (GLuint index, const GLubyte *v);
GLAPI void APIENTRY glVertexAttrib4uiv (GLuint index, const GLuint *v);
GLAPI void APIENTRY glVertexAttrib4usv (GLuint index, const GLushort *v);
GLAPI void APIENTRY glVertexAttribPointer (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);
#endif
#endif /* GL_VERSION_2_0 */
#ifndef GL_VERSION_2_1
#define GL_VERSION_2_1 1
#define GL_PIXEL_PACK_BUFFER              0x88EB
#define GL_PIXEL_UNPACK_BUFFER            0x88EC
#define GL_PIXEL_PACK_BUFFER_BINDING      0x88ED
#define GL_PIXEL_UNPACK_BUFFER_BINDING    0x88EF
#define GL_FLOAT_MAT2x3                   0x8B65
#define GL_FLOAT_MAT2x4                   0x8B66
#define GL_FLOAT_MAT3x2                   0x8B67
#define GL_FLOAT_MAT3x4                   0x8B68
#define GL_FLOAT_MAT4x2                   0x8B69
#define GL_FLOAT_MAT4x3                   0x8B6A
#define GL_SRGB                           0x8C40
#define GL_SRGB8                          0x8C41
#define GL_SRGB_ALPHA                     0x8C42
#define GL_SRGB8_ALPHA8                   0x8C43
#define GL_COMPRESSED_SRGB                0x8C48
#define GL_COMPRESSED_SRGB_ALPHA          0x8C49
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X3FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X2FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X4FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X2FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X4FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X3FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glUniformMatrix2x3fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glUniformMatrix3x2fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glUniformMatrix2x4fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glUniformMatrix4x2fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glUniformMatrix3x4fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glUniformMatrix4x3fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
#endif
#endif /* GL_VERSION_2_1 */
#ifndef GL_VERSION_3_0
#define GL_VERSION_3_0 1
typedef khronos_uint16_t GLhalf;
#define GL_COMPARE_REF_TO_TEXTURE         0x884E
#define GL_CLIP_DISTANCE0                 0x3000
#define GL_CLIP_DISTANCE1                 0x3001
#define GL_CLIP_DISTANCE2                 0x3002
#define GL_CLIP_DISTANCE3                 0x3003
#define GL_CLIP_DISTANCE4                 0x3004
#define GL_CLIP_DISTANCE5                 0x3005
#define GL_CLIP_DISTANCE6                 0x3006
#define GL_CLIP_DISTANCE7                 0x3007
#define GL_MAX_CLIP_DISTANCES             0x0D32
#define GL_MAJOR_VERSION                  0x821B
#define GL_MINOR_VERSION                  0x821C
#define GL_NUM_EXTENSIONS                 0x821D
#define GL_CONTEXT_FLAGS                  0x821E
#define GL_COMPRESSED_RED                 0x8225
#define GL_COMPRESSED_RG                  0x8226
#define GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT 0x00000001
#define GL_RGBA32F                        0x8814
#define GL_RGB32F                         0x8815
#define GL_RGBA16F                        0x881A
#define GL_RGB16F                         0x881B
#define GL_VERTEX_ATTRIB_ARRAY_INTEGER    0x88FD
#define GL_MAX_ARRAY_TEXTURE_LAYERS       0x88FF
#define GL_MIN_PROGRAM_TEXEL_OFFSET       0x8904
#define GL_MAX_PROGRAM_TEXEL_OFFSET       0x8905
#define GL_CLAMP_READ_COLOR               0x891C
#define GL_FIXED_ONLY                     0x891D
#define GL_MAX_VARYING_COMPONENTS         0x8B4B
#define GL_TEXTURE_1D_ARRAY               0x8C18
#define GL_PROXY_TEXTURE_1D_ARRAY         0x8C19
#define GL_TEXTURE_2D_ARRAY               0x8C1A
#define GL_PROXY_TEXTURE_2D_ARRAY         0x8C1B
#define GL_TEXTURE_BINDING_1D_ARRAY       0x8C1C
#define GL_TEXTURE_BINDING_2D_ARRAY       0x8C1D
#define GL_R11F_G11F_B10F                 0x8C3A
#define GL_UNSIGNED_INT_10F_11F_11F_REV   0x8C3B
#define GL_RGB9_E5                        0x8C3D
#define GL_UNSIGNED_INT_5_9_9_9_REV       0x8C3E
#define GL_TEXTURE_SHARED_SIZE            0x8C3F
#define GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH 0x8C76
#define GL_TRANSFORM_FEEDBACK_BUFFER_MODE 0x8C7F
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS 0x8C80
#define GL_TRANSFORM_FEEDBACK_VARYINGS    0x8C83
#define GL_TRANSFORM_FEEDBACK_BUFFER_START 0x8C84
#define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE 0x8C85
#define GL_PRIMITIVES_GENERATED           0x8C87
#define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN 0x8C88
#define GL_RASTERIZER_DISCARD             0x8C89
#define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS 0x8C8A
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS 0x8C8B
#define GL_INTERLEAVED_ATTRIBS            0x8C8C
#define GL_SEPARATE_ATTRIBS               0x8C8D
#define GL_TRANSFORM_FEEDBACK_BUFFER      0x8C8E
#define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING 0x8C8F
#define GL_RGBA32UI                       0x8D70
#define GL_RGB32UI                        0x8D71
#define GL_RGBA16UI                       0x8D76
#define GL_RGB16UI                        0x8D77
#define GL_RGBA8UI                        0x8D7C
#define GL_RGB8UI                         0x8D7D
#define GL_RGBA32I                        0x8D82
#define GL_RGB32I                         0x8D83
#define GL_RGBA16I                        0x8D88
#define GL_RGB16I                         0x8D89
#define GL_RGBA8I                         0x8D8E
#define GL_RGB8I                          0x8D8F
#define GL_RED_INTEGER                    0x8D94
#define GL_GREEN_INTEGER                  0x8D95
#define GL_BLUE_INTEGER                   0x8D96
#define GL_RGB_INTEGER                    0x8D98
#define GL_RGBA_INTEGER                   0x8D99
#define GL_BGR_INTEGER                    0x8D9A
#define GL_BGRA_INTEGER                   0x8D9B
#define GL_SAMPLER_1D_ARRAY               0x8DC0
#define GL_SAMPLER_2D_ARRAY               0x8DC1
#define GL_SAMPLER_1D_ARRAY_SHADOW        0x8DC3
#define GL_SAMPLER_2D_ARRAY_SHADOW        0x8DC4
#define GL_SAMPLER_CUBE_SHADOW            0x8DC5
#define GL_UNSIGNED_INT_VEC2              0x8DC6
#define GL_UNSIGNED_INT_VEC3              0x8DC7
#define GL_UNSIGNED_INT_VEC4              0x8DC8
#define GL_INT_SAMPLER_1D                 0x8DC9
#define GL_INT_SAMPLER_2D                 0x8DCA
#define GL_INT_SAMPLER_3D                 0x8DCB
#define GL_INT_SAMPLER_CUBE               0x8DCC
#define GL_INT_SAMPLER_1D_ARRAY           0x8DCE
#define GL_INT_SAMPLER_2D_ARRAY           0x8DCF
#define GL_UNSIGNED_INT_SAMPLER_1D        0x8DD1
#define GL_UNSIGNED_INT_SAMPLER_2D        0x8DD2
#define GL_UNSIGNED_INT_SAMPLER_3D        0x8DD3
#define GL_UNSIGNED_INT_SAMPLER_CUBE      0x8DD4
#define GL_UNSIGNED_INT_SAMPLER_1D_ARRAY  0x8DD6
#define GL_UNSIGNED_INT_SAMPLER_2D_ARRAY  0x8DD7
#define GL_QUERY_WAIT                     0x8E13
#define GL_QUERY_NO_WAIT                  0x8E14
#define GL_QUERY_BY_REGION_WAIT           0x8E15
#define GL_QUERY_BY_REGION_NO_WAIT        0x8E16
#define GL_BUFFER_ACCESS_FLAGS            0x911F
#define GL_BUFFER_MAP_LENGTH              0x9120
#define GL_BUFFER_MAP_OFFSET              0x9121
#define GL_DEPTH_COMPONENT32F             0x8CAC
#define GL_DEPTH32F_STENCIL8              0x8CAD
#define GL_FLOAT_32_UNSIGNED_INT_24_8_REV 0x8DAD
#define GL_INVALID_FRAMEBUFFER_OPERATION  0x0506
#define GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING 0x8210
#define GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE 0x8211
#define GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE 0x8212
#define GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE 0x8213
#define GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE 0x8214
#define GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE 0x8215
#define GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE 0x8216
#define GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE 0x8217
#define GL_FRAMEBUFFER_DEFAULT            0x8218
#define GL_FRAMEBUFFER_UNDEFINED          0x8219
#define GL_DEPTH_STENCIL_ATTACHMENT       0x821A
#define GL_MAX_RENDERBUFFER_SIZE          0x84E8
#define GL_DEPTH_STENCIL                  0x84F9
#define GL_UNSIGNED_INT_24_8              0x84FA
#define GL_DEPTH24_STENCIL8               0x88F0
#define GL_TEXTURE_STENCIL_SIZE           0x88F1
#define GL_TEXTURE_RED_TYPE               0x8C10
#define GL_TEXTURE_GREEN_TYPE             0x8C11
#define GL_TEXTURE_BLUE_TYPE              0x8C12
#define GL_TEXTURE_ALPHA_TYPE             0x8C13
#define GL_TEXTURE_DEPTH_TYPE             0x8C16
#define GL_UNSIGNED_NORMALIZED            0x8C17
#define GL_FRAMEBUFFER_BINDING            0x8CA6
#define GL_DRAW_FRAMEBUFFER_BINDING       0x8CA6
#define GL_RENDERBUFFER_BINDING           0x8CA7
#define GL_READ_FRAMEBUFFER               0x8CA8
#define GL_DRAW_FRAMEBUFFER               0x8CA9
#define GL_READ_FRAMEBUFFER_BINDING       0x8CAA
#define GL_RENDERBUFFER_SAMPLES           0x8CAB
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE 0x8CD0
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME 0x8CD1
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL 0x8CD2
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE 0x8CD3
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER 0x8CD4
#define GL_FRAMEBUFFER_COMPLETE           0x8CD5
#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT 0x8CD6
#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT 0x8CD7
#define GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER 0x8CDB
#define GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER 0x8CDC
#define GL_FRAMEBUFFER_UNSUPPORTED        0x8CDD
#define GL_MAX_COLOR_ATTACHMENTS          0x8CDF
#define GL_COLOR_ATTACHMENT0              0x8CE0
#define GL_COLOR_ATTACHMENT1              0x8CE1
#define GL_COLOR_ATTACHMENT2              0x8CE2
#define GL_COLOR_ATTACHMENT3              0x8CE3
#define GL_COLOR_ATTACHMENT4              0x8CE4
#define GL_COLOR_ATTACHMENT5              0x8CE5
#define GL_COLOR_ATTACHMENT6              0x8CE6
#define GL_COLOR_ATTACHMENT7              0x8CE7
#define GL_COLOR_ATTACHMENT8              0x8CE8
#define GL_COLOR_ATTACHMENT9              0x8CE9
#define GL_COLOR_ATTACHMENT10             0x8CEA
#define GL_COLOR_ATTACHMENT11             0x8CEB
#define GL_COLOR_ATTACHMENT12             0x8CEC
#define GL_COLOR_ATTACHMENT13             0x8CED
#define GL_COLOR_ATTACHMENT14             0x8CEE
#define GL_COLOR_ATTACHMENT15             0x8CEF
#define GL_COLOR_ATTACHMENT16             0x8CF0
#define GL_COLOR_ATTACHMENT17             0x8CF1
#define GL_COLOR_ATTACHMENT18             0x8CF2
#define GL_COLOR_ATTACHMENT19             0x8CF3
#define GL_COLOR_ATTACHMENT20             0x8CF4
#define GL_COLOR_ATTACHMENT21             0x8CF5
#define GL_COLOR_ATTACHMENT22             0x8CF6
#define GL_COLOR_ATTACHMENT23             0x8CF7
#define GL_COLOR_ATTACHMENT24             0x8CF8
#define GL_COLOR_ATTACHMENT25             0x8CF9
#define GL_COLOR_ATTACHMENT26             0x8CFA
#define GL_COLOR_ATTACHMENT27             0x8CFB
#define GL_COLOR_ATTACHMENT28             0x8CFC
#define GL_COLOR_ATTACHMENT29             0x8CFD
#define GL_COLOR_ATTACHMENT30             0x8CFE
#define GL_COLOR_ATTACHMENT31             0x8CFF
#define GL_DEPTH_ATTACHMENT               0x8D00
#define GL_STENCIL_ATTACHMENT             0x8D20
#define GL_FRAMEBUFFER                    0x8D40
#define GL_RENDERBUFFER                   0x8D41
#define GL_RENDERBUFFER_WIDTH             0x8D42
#define GL_RENDERBUFFER_HEIGHT            0x8D43
#define GL_RENDERBUFFER_INTERNAL_FORMAT   0x8D44
#define GL_STENCIL_INDEX1                 0x8D46
#define GL_STENCIL_INDEX4                 0x8D47
#define GL_STENCIL_INDEX8                 0x8D48
#define GL_STENCIL_INDEX16                0x8D49
#define GL_RENDERBUFFER_RED_SIZE          0x8D50
#define GL_RENDERBUFFER_GREEN_SIZE        0x8D51
#define GL_RENDERBUFFER_BLUE_SIZE         0x8D52
#define GL_RENDERBUFFER_ALPHA_SIZE        0x8D53
#define GL_RENDERBUFFER_DEPTH_SIZE        0x8D54
#define GL_RENDERBUFFER_STENCIL_SIZE      0x8D55
#define GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE 0x8D56
#define GL_MAX_SAMPLES                    0x8D57
#define GL_FRAMEBUFFER_SRGB               0x8DB9
#define GL_HALF_FLOAT                     0x140B
#define GL_MAP_READ_BIT                   0x0001
#define GL_MAP_WRITE_BIT                  0x0002
#define GL_MAP_INVALIDATE_RANGE_BIT       0x0004
#define GL_MAP_INVALIDATE_BUFFER_BIT      0x0008
#define GL_MAP_FLUSH_EXPLICIT_BIT         0x0010
#define GL_MAP_UNSYNCHRONIZED_BIT         0x0020
#define GL_COMPRESSED_RED_RGTC1           0x8DBB
#define GL_COMPRESSED_SIGNED_RED_RGTC1    0x8DBC
#define GL_COMPRESSED_RG_RGTC2            0x8DBD
#define GL_COMPRESSED_SIGNED_RG_RGTC2     0x8DBE
#define GL_RG                             0x8227
#define GL_RG_INTEGER                     0x8228
#define GL_R8                             0x8229
#define GL_R16                            0x822A
#define GL_RG8                            0x822B
#define GL_RG16                           0x822C
#define GL_R16F                           0x822D
#define GL_R32F                           0x822E
#define GL_RG16F                          0x822F
#define GL_RG32F                          0x8230
#define GL_R8I                            0x8231
#define GL_R8UI                           0x8232
#define GL_R16I                           0x8233
#define GL_R16UI                          0x8234
#define GL_R32I                           0x8235
#define GL_R32UI                          0x8236
#define GL_RG8I                           0x8237
#define GL_RG8UI                          0x8238
#define GL_RG16I                          0x8239
#define GL_RG16UI                         0x823A
#define GL_RG32I                          0x823B
#define GL_RG32UI                         0x823C
#define GL_VERTEX_ARRAY_BINDING           0x85B5
typedef void (APIENTRYP PFNGLCOLORMASKIPROC) (GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
typedef void (APIENTRYP PFNGLGETBOOLEANI_VPROC) (GLenum target, GLuint index, GLboolean *data);
typedef void (APIENTRYP PFNGLGETINTEGERI_VPROC) (GLenum target, GLuint index, GLint *data);
typedef void (APIENTRYP PFNGLENABLEIPROC) (GLenum target, GLuint index);
typedef void (APIENTRYP PFNGLDISABLEIPROC) (GLenum target, GLuint index);
typedef GLboolean (APIENTRYP PFNGLISENABLEDIPROC) (GLenum target, GLuint index);
typedef void (APIENTRYP PFNGLBEGINTRANSFORMFEEDBACKPROC) (GLenum primitiveMode);
typedef void (APIENTRYP PFNGLENDTRANSFORMFEEDBACKPROC) (void);
typedef void (APIENTRYP PFNGLBINDBUFFERRANGEPROC) (GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLBINDBUFFERBASEPROC) (GLenum target, GLuint index, GLuint buffer);
typedef void (APIENTRYP PFNGLTRANSFORMFEEDBACKVARYINGSPROC) (GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode);
typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKVARYINGPROC) (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
typedef void (APIENTRYP PFNGLCLAMPCOLORPROC) (GLenum target, GLenum clamp);
typedef void (APIENTRYP PFNGLBEGINCONDITIONALRENDERPROC) (GLuint id, GLenum mode);
typedef void (APIENTRYP PFNGLENDCONDITIONALRENDERPROC) (void);
typedef void (APIENTRYP PFNGLVERTEXATTRIBIPOINTERPROC) (GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIIVPROC) (GLuint index, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIUIVPROC) (GLuint index, GLenum pname, GLuint *params);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1IPROC) (GLuint index, GLint x);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2IPROC) (GLuint index, GLint x, GLint y);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3IPROC) (GLuint index, GLint x, GLint y, GLint z);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4IPROC) (GLuint index, GLint x, GLint y, GLint z, GLint w);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1UIPROC) (GLuint index, GLuint x);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2UIPROC) (GLuint index, GLuint x, GLuint y);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3UIPROC) (GLuint index, GLuint x, GLuint y, GLuint z);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UIPROC) (GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1IVPROC) (GLuint index, const GLint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2IVPROC) (GLuint index, const GLint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3IVPROC) (GLuint index, const GLint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4IVPROC) (GLuint index, const GLint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1UIVPROC) (GLuint index, const GLuint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2UIVPROC) (GLuint index, const GLuint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3UIVPROC) (GLuint index, const GLuint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UIVPROC) (GLuint index, const GLuint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4BVPROC) (GLuint index, const GLbyte *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4SVPROC) (GLuint index, const GLshort *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UBVPROC) (GLuint index, const GLubyte *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4USVPROC) (GLuint index, const GLushort *v);
typedef void (APIENTRYP PFNGLGETUNIFORMUIVPROC) (GLuint program, GLint location, GLuint *params);
typedef void (APIENTRYP PFNGLBINDFRAGDATALOCATIONPROC) (GLuint program, GLuint color, const GLchar *name);
typedef GLint (APIENTRYP PFNGLGETFRAGDATALOCATIONPROC) (GLuint program, const GLchar *name);
typedef void (APIENTRYP PFNGLUNIFORM1UIPROC) (GLint location, GLuint v0);
typedef void (APIENTRYP PFNGLUNIFORM2UIPROC) (GLint location, GLuint v0, GLuint v1);
typedef void (APIENTRYP PFNGLUNIFORM3UIPROC) (GLint location, GLuint v0, GLuint v1, GLuint v2);
typedef void (APIENTRYP PFNGLUNIFORM4UIPROC) (GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
typedef void (APIENTRYP PFNGLUNIFORM1UIVPROC) (GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLUNIFORM2UIVPROC) (GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLUNIFORM3UIVPROC) (GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLUNIFORM4UIVPROC) (GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLTEXPARAMETERIIVPROC) (GLenum target, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLTEXPARAMETERIUIVPROC) (GLenum target, GLenum pname, const GLuint *params);
typedef void (APIENTRYP PFNGLGETTEXPARAMETERIIVPROC) (GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETTEXPARAMETERIUIVPROC) (GLenum target, GLenum pname, GLuint *params);
typedef void (APIENTRYP PFNGLCLEARBUFFERIVPROC) (GLenum buffer, GLint drawbuffer, const GLint *value);
typedef void (APIENTRYP PFNGLCLEARBUFFERUIVPROC) (GLenum buffer, GLint drawbuffer, const GLuint *value);
typedef void (APIENTRYP PFNGLCLEARBUFFERFVPROC) (GLenum buffer, GLint drawbuffer, const GLfloat *value);
typedef void (APIENTRYP PFNGLCLEARBUFFERFIPROC) (GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
typedef const GLubyte *(APIENTRYP PFNGLGETSTRINGIPROC) (GLenum name, GLuint index);
typedef GLboolean (APIENTRYP PFNGLISRENDERBUFFERPROC) (GLuint renderbuffer);
typedef void (APIENTRYP PFNGLBINDRENDERBUFFERPROC) (GLenum target, GLuint renderbuffer);
typedef void (APIENTRYP PFNGLDELETERENDERBUFFERSPROC) (GLsizei n, const GLuint *renderbuffers);
typedef void (APIENTRYP PFNGLGENRENDERBUFFERSPROC) (GLsizei n, GLuint *renderbuffers);
typedef void (APIENTRYP PFNGLRENDERBUFFERSTORAGEPROC) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLGETRENDERBUFFERPARAMETERIVPROC) (GLenum target, GLenum pname, GLint *params);
typedef GLboolean (APIENTRYP PFNGLISFRAMEBUFFERPROC) (GLuint framebuffer);
typedef void (APIENTRYP PFNGLBINDFRAMEBUFFERPROC) (GLenum target, GLuint framebuffer);
typedef void (APIENTRYP PFNGLDELETEFRAMEBUFFERSPROC) (GLsizei n, const GLuint *framebuffers);
typedef void (APIENTRYP PFNGLGENFRAMEBUFFERSPROC) (GLsizei n, GLuint *framebuffers);
typedef GLenum (APIENTRYP PFNGLCHECKFRAMEBUFFERSTATUSPROC) (GLenum target);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE1DPROC) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE2DPROC) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE3DPROC) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
typedef void (APIENTRYP PFNGLFRAMEBUFFERRENDERBUFFERPROC) (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
typedef void (APIENTRYP PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC) (GLenum target, GLenum attachment, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGENERATEMIPMAPPROC) (GLenum target);
typedef void (APIENTRYP PFNGLBLITFRAMEBUFFERPROC) (GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
typedef void (APIENTRYP PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURELAYERPROC) (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
typedef void *(APIENTRYP PFNGLMAPBUFFERRANGEPROC) (GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
typedef void (APIENTRYP PFNGLFLUSHMAPPEDBUFFERRANGEPROC) (GLenum target, GLintptr offset, GLsizeiptr length);
typedef void (APIENTRYP PFNGLBINDVERTEXARRAYPROC) (GLuint array);
typedef void (APIENTRYP PFNGLDELETEVERTEXARRAYSPROC) (GLsizei n, const GLuint *arrays);
typedef void (APIENTRYP PFNGLGENVERTEXARRAYSPROC) (GLsizei n, GLuint *arrays);
typedef GLboolean (APIENTRYP PFNGLISVERTEXARRAYPROC) (GLuint array);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glColorMaski (GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
GLAPI void APIENTRY glGetBooleani_v (GLenum target, GLuint index, GLboolean *data);
GLAPI void APIENTRY glGetIntegeri_v (GLenum target, GLuint index, GLint *data);
GLAPI void APIENTRY glEnablei (GLenum target, GLuint index);
GLAPI void APIENTRY glDisablei (GLenum target, GLuint index);
GLAPI GLboolean APIENTRY glIsEnabledi (GLenum target, GLuint index);
GLAPI void APIENTRY glBeginTransformFeedback (GLenum primitiveMode);
GLAPI void APIENTRY glEndTransformFeedback (void);
GLAPI void APIENTRY glBindBufferRange (GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
GLAPI void APIENTRY glBindBufferBase (GLenum target, GLuint index, GLuint buffer);
GLAPI void APIENTRY glTransformFeedbackVaryings (GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode);
GLAPI void APIENTRY glGetTransformFeedbackVarying (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
GLAPI void APIENTRY glClampColor (GLenum target, GLenum clamp);
GLAPI void APIENTRY glBeginConditionalRender (GLuint id, GLenum mode);
GLAPI void APIENTRY glEndConditionalRender (void);
GLAPI void APIENTRY glVertexAttribIPointer (GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
GLAPI void APIENTRY glGetVertexAttribIiv (GLuint index, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetVertexAttribIuiv (GLuint index, GLenum pname, GLuint *params);
GLAPI void APIENTRY glVertexAttribI1i (GLuint index, GLint x);
GLAPI void APIENTRY glVertexAttribI2i (GLuint index, GLint x, GLint y);
GLAPI void APIENTRY glVertexAttribI3i (GLuint index, GLint x, GLint y, GLint z);
GLAPI void APIENTRY glVertexAttribI4i (GLuint index, GLint x, GLint y, GLint z, GLint w);
GLAPI void APIENTRY glVertexAttribI1ui (GLuint index, GLuint x);
GLAPI void APIENTRY glVertexAttribI2ui (GLuint index, GLuint x, GLuint y);
GLAPI void APIENTRY glVertexAttribI3ui (GLuint index, GLuint x, GLuint y, GLuint z);
GLAPI void APIENTRY glVertexAttribI4ui (GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
GLAPI void APIENTRY glVertexAttribI1iv (GLuint index, const GLint *v);
GLAPI void APIENTRY glVertexAttribI2iv (GLuint index, const GLint *v);
GLAPI void APIENTRY glVertexAttribI3iv (GLuint index, const GLint *v);
GLAPI void APIENTRY glVertexAttribI4iv (GLuint index, const GLint *v);
GLAPI void APIENTRY glVertexAttribI1uiv (GLuint index, const GLuint *v);
GLAPI void APIENTRY glVertexAttribI2uiv (GLuint index, const GLuint *v);
GLAPI void APIENTRY glVertexAttribI3uiv (GLuint index, const GLuint *v);
GLAPI void APIENTRY glVertexAttribI4uiv (GLuint index, const GLuint *v);
GLAPI void APIENTRY glVertexAttribI4bv (GLuint index, const GLbyte *v);
GLAPI void APIENTRY glVertexAttribI4sv (GLuint index, const GLshort *v);
GLAPI void APIENTRY glVertexAttribI4ubv (GLuint index, const GLubyte *v);
GLAPI void APIENTRY glVertexAttribI4usv (GLuint index, const GLushort *v);
GLAPI void APIENTRY glGetUniformuiv (GLuint program, GLint location, GLuint *params);
GLAPI void APIENTRY glBindFragDataLocation (GLuint program, GLuint color, const GLchar *name);
GLAPI GLint APIENTRY glGetFragDataLocation (GLuint program, const GLchar *name);
GLAPI void APIENTRY glUniform1ui (GLint location, GLuint v0);
GLAPI void APIENTRY glUniform2ui (GLint location, GLuint v0, GLuint v1);
GLAPI void APIENTRY glUniform3ui (GLint location, GLuint v0, GLuint v1, GLuint v2);
GLAPI void APIENTRY glUniform4ui (GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
GLAPI void APIENTRY glUniform1uiv (GLint location, GLsizei count, const GLuint *value);
GLAPI void APIENTRY glUniform2uiv (GLint location, GLsizei count, const GLuint *value);
GLAPI void APIENTRY glUniform3uiv (GLint location, GLsizei count, const GLuint *value);
GLAPI void APIENTRY glUniform4uiv (GLint location, GLsizei count, const GLuint *value);
GLAPI void APIENTRY glTexParameterIiv (GLenum target, GLenum pname, const GLint *params);
GLAPI void APIENTRY glTexParameterIuiv (GLenum target, GLenum pname, const GLuint *params);
GLAPI void APIENTRY glGetTexParameterIiv (GLenum target, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetTexParameterIuiv (GLenum target, GLenum pname, GLuint *params);
GLAPI void APIENTRY glClearBufferiv (GLenum buffer, GLint drawbuffer, const GLint *value);
GLAPI void APIENTRY glClearBufferuiv (GLenum buffer, GLint drawbuffer, const GLuint *value);
GLAPI void APIENTRY glClearBufferfv (GLenum buffer, GLint drawbuffer, const GLfloat *value);
GLAPI void APIENTRY glClearBufferfi (GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
GLAPI const GLubyte *APIENTRY glGetStringi (GLenum name, GLuint index);
GLAPI GLboolean APIENTRY glIsRenderbuffer (GLuint renderbuffer);
GLAPI void APIENTRY glBindRenderbuffer (GLenum target, GLuint renderbuffer);
GLAPI void APIENTRY glDeleteRenderbuffers (GLsizei n, const GLuint *renderbuffers);
GLAPI void APIENTRY glGenRenderbuffers (GLsizei n, GLuint *renderbuffers);
GLAPI void APIENTRY glRenderbufferStorage (GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI void APIENTRY glGetRenderbufferParameteriv (GLenum target, GLenum pname, GLint *params);
GLAPI GLboolean APIENTRY glIsFramebuffer (GLuint framebuffer);
GLAPI void APIENTRY glBindFramebuffer (GLenum target, GLuint framebuffer);
GLAPI void APIENTRY glDeleteFramebuffers (GLsizei n, const GLuint *framebuffers);
GLAPI void APIENTRY glGenFramebuffers (GLsizei n, GLuint *framebuffers);
GLAPI GLenum APIENTRY glCheckFramebufferStatus (GLenum target);
GLAPI void APIENTRY glFramebufferTexture1D (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
GLAPI void APIENTRY glFramebufferTexture2D (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
GLAPI void APIENTRY glFramebufferTexture3D (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
GLAPI void APIENTRY glFramebufferRenderbuffer (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
GLAPI void APIENTRY glGetFramebufferAttachmentParameteriv (GLenum target, GLenum attachment, GLenum pname, GLint *params);
GLAPI void APIENTRY glGenerateMipmap (GLenum target);
GLAPI void APIENTRY glBlitFramebuffer (GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
GLAPI void APIENTRY glRenderbufferStorageMultisample (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI void APIENTRY glFramebufferTextureLayer (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
GLAPI void *APIENTRY glMapBufferRange (GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
GLAPI void APIENTRY glFlushMappedBufferRange (GLenum target, GLintptr offset, GLsizeiptr length);
GLAPI void APIENTRY glBindVertexArray (GLuint array);
GLAPI void APIENTRY glDeleteVertexArrays (GLsizei n, const GLuint *arrays);
GLAPI void APIENTRY glGenVertexArrays (GLsizei n, GLuint *arrays);
GLAPI GLboolean APIENTRY glIsVertexArray (GLuint array);
#endif
#endif /* GL_VERSION_3_0 */
#ifndef GL_VERSION_3_1
#define GL_VERSION_3_1 1
#define GL_SAMPLER_2D_RECT                0x8B63
#define GL_SAMPLER_2D_RECT_SHADOW         0x8B64
#define GL_SAMPLER_BUFFER                 0x8DC2
#define GL_INT_SAMPLER_2D_RECT            0x8DCD
#define GL_INT_SAMPLER_BUFFER             0x8DD0
#define GL_UNSIGNED_INT_SAMPLER_2D_RECT   0x8DD5
#define GL_UNSIGNED_INT_SAMPLER_BUFFER    0x8DD8
#define GL_TEXTURE_BUFFER                 0x8C2A
#define GL_MAX_TEXTURE_BUFFER_SIZE        0x8C2B
#define GL_TEXTURE_BINDING_BUFFER         0x8C2C
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING 0x8C2D
#define GL_TEXTURE_RECTANGLE              0x84F5
#define GL_TEXTURE_BINDING_RECTANGLE      0x84F6
#define GL_PROXY_TEXTURE_RECTANGLE        0x84F7
#define GL_MAX_RECTANGLE_TEXTURE_SIZE     0x84F8
#define GL_R8_SNORM                       0x8F94
#define GL_RG8_SNORM                      0x8F95
#define GL_RGB8_SNORM                     0x8F96
#define GL_RGBA8_SNORM                    0x8F97
#define GL_R16_SNORM                      0x8F98
#define GL_RG16_SNORM                     0x8F99
#define GL_RGB16_SNORM                    0x8F9A
#define GL_RGBA16_SNORM                   0x8F9B
#define GL_SIGNED_NORMALIZED              0x8F9C
#define GL_PRIMITIVE_RESTART              0x8F9D
#define GL_PRIMITIVE_RESTART_INDEX        0x8F9E
#define GL_COPY_READ_BUFFER               0x8F36
#define GL_COPY_WRITE_BUFFER              0x8F37
#define GL_UNIFORM_BUFFER                 0x8A11
#define GL_UNIFORM_BUFFER_BINDING         0x8A28
#define GL_UNIFORM_BUFFER_START           0x8A29
#define GL_UNIFORM_BUFFER_SIZE            0x8A2A
#define GL_MAX_VERTEX_UNIFORM_BLOCKS      0x8A2B
#define GL_MAX_GEOMETRY_UNIFORM_BLOCKS    0x8A2C
#define GL_MAX_FRAGMENT_UNIFORM_BLOCKS    0x8A2D
#define GL_MAX_COMBINED_UNIFORM_BLOCKS    0x8A2E
#define GL_MAX_UNIFORM_BUFFER_BINDINGS    0x8A2F
#define GL_MAX_UNIFORM_BLOCK_SIZE         0x8A30
#define GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS 0x8A31
#define GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS 0x8A32
#define GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS 0x8A33
#define GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT 0x8A34
#define GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH 0x8A35
#define GL_ACTIVE_UNIFORM_BLOCKS          0x8A36
#define GL_UNIFORM_TYPE                   0x8A37
#define GL_UNIFORM_SIZE                   0x8A38
#define GL_UNIFORM_NAME_LENGTH            0x8A39
#define GL_UNIFORM_BLOCK_INDEX            0x8A3A
#define GL_UNIFORM_OFFSET                 0x8A3B
#define GL_UNIFORM_ARRAY_STRIDE           0x8A3C
#define GL_UNIFORM_MATRIX_STRIDE          0x8A3D
#define GL_UNIFORM_IS_ROW_MAJOR           0x8A3E
#define GL_UNIFORM_BLOCK_BINDING          0x8A3F
#define GL_UNIFORM_BLOCK_DATA_SIZE        0x8A40
#define GL_UNIFORM_BLOCK_NAME_LENGTH      0x8A41
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS  0x8A42
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES 0x8A43
#define GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER 0x8A44
#define GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER 0x8A45
#define GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER 0x8A46
#define GL_INVALID_INDEX                  0xFFFFFFFFu
typedef void (APIENTRYP PFNGLDRAWARRAYSINSTANCEDPROC) (GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDPROC) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount);
typedef void (APIENTRYP PFNGLTEXBUFFERPROC) (GLenum target, GLenum internalformat, GLuint buffer);
typedef void (APIENTRYP PFNGLPRIMITIVERESTARTINDEXPROC) (GLuint index);
typedef void (APIENTRYP PFNGLCOPYBUFFERSUBDATAPROC) (GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLGETUNIFORMINDICESPROC) (GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices);
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMSIVPROC) (GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMNAMEPROC) (GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName);
typedef GLuint (APIENTRYP PFNGLGETUNIFORMBLOCKINDEXPROC) (GLuint program, const GLchar *uniformBlockName);
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMBLOCKIVPROC) (GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC) (GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName);
typedef void (APIENTRYP PFNGLUNIFORMBLOCKBINDINGPROC) (GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glDrawArraysInstanced (GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
GLAPI void APIENTRY glDrawElementsInstanced (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount);
GLAPI void APIENTRY glTexBuffer (GLenum target, GLenum internalformat, GLuint buffer);
GLAPI void APIENTRY glPrimitiveRestartIndex (GLuint index);
GLAPI void APIENTRY glCopyBufferSubData (GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
GLAPI void APIENTRY glGetUniformIndices (GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices);
GLAPI void APIENTRY glGetActiveUniformsiv (GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetActiveUniformName (GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName);
GLAPI GLuint APIENTRY glGetUniformBlockIndex (GLuint program, const GLchar *uniformBlockName);
GLAPI void APIENTRY glGetActiveUniformBlockiv (GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetActiveUniformBlockName (GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName);
GLAPI void APIENTRY glUniformBlockBinding (GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
#endif
#endif /* GL_VERSION_3_1 */
#ifndef GL_VERSION_3_2
#define GL_VERSION_3_2 1
typedef struct __GLsync *GLsync;
typedef khronos_uint64_t GLuint64;
typedef khronos_int64_t GLint64;
#define GL_CONTEXT_CORE_PROFILE_BIT       0x00000001
#define GL_CONTEXT_COMPATIBILITY_PROFILE_BIT 0x00000002
#define GL_LINES_ADJACENCY                0x000A
#define GL_LINE_STRIP_ADJACENCY           0x000B
#define GL_TRIANGLES_ADJACENCY            0x000C
#define GL_TRIANGLE_STRIP_ADJACENCY       0x000D
#define GL_PROGRAM_POINT_SIZE             0x8642
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS 0x8C29
#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED 0x8DA7
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS 0x8DA8
#define GL_GEOMETRY_SHADER                0x8DD9
#define GL_GEOMETRY_VERTICES_OUT          0x8916
#define GL_GEOMETRY_INPUT_TYPE            0x8917
#define GL_GEOMETRY_OUTPUT_TYPE           0x8918
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS 0x8DDF
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES   0x8DE0
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS 0x8DE1
#define GL_MAX_VERTEX_OUTPUT_COMPONENTS   0x9122
#define GL_MAX_GEOMETRY_INPUT_COMPONENTS  0x9123
#define GL_MAX_GEOMETRY_OUTPUT_COMPONENTS 0x9124
#define GL_MAX_FRAGMENT_INPUT_COMPONENTS  0x9125
#define GL_CONTEXT_PROFILE_MASK           0x9126
#define GL_DEPTH_CLAMP                    0x864F
#define GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION 0x8E4C
#define GL_FIRST_VERTEX_CONVENTION        0x8E4D
#define GL_LAST_VERTEX_CONVENTION         0x8E4E
#define GL_PROVOKING_VERTEX               0x8E4F
#define GL_TEXTURE_CUBE_MAP_SEAMLESS      0x884F
#define GL_MAX_SERVER_WAIT_TIMEOUT        0x9111
#define GL_OBJECT_TYPE                    0x9112
#define GL_SYNC_CONDITION                 0x9113
#define GL_SYNC_STATUS                    0x9114
#define GL_SYNC_FLAGS                     0x9115
#define GL_SYNC_FENCE                     0x9116
#define GL_SYNC_GPU_COMMANDS_COMPLETE     0x9117
#define GL_UNSIGNALED                     0x9118
#define GL_SIGNALED                       0x9119
#define GL_ALREADY_SIGNALED               0x911A
#define GL_TIMEOUT_EXPIRED                0x911B
#define GL_CONDITION_SATISFIED            0x911C
#define GL_WAIT_FAILED                    0x911D
#define GL_TIMEOUT_IGNORED                0xFFFFFFFFFFFFFFFFull
#define GL_SYNC_FLUSH_COMMANDS_BIT        0x00000001
#define GL_SAMPLE_POSITION                0x8E50
#define GL_SAMPLE_MASK                    0x8E51
#define GL_SAMPLE_MASK_VALUE              0x8E52
#define GL_MAX_SAMPLE_MASK_WORDS          0x8E59
#define GL_TEXTURE_2D_MULTISAMPLE         0x9100
#define GL_PROXY_TEXTURE_2D_MULTISAMPLE   0x9101
#define GL_TEXTURE_2D_MULTISAMPLE_ARRAY   0x9102
#define GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY 0x9103
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE 0x9104
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY 0x9105
#define GL_TEXTURE_SAMPLES                0x9106
#define GL_TEXTURE_FIXED_SAMPLE_LOCATIONS 0x9107
#define GL_SAMPLER_2D_MULTISAMPLE         0x9108
#define GL_INT_SAMPLER_2D_MULTISAMPLE     0x9109
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE 0x910A
#define GL_SAMPLER_2D_MULTISAMPLE_ARRAY   0x910B
#define GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910C
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910D
#define GL_MAX_COLOR_TEXTURE_SAMPLES      0x910E
#define GL_MAX_DEPTH_TEXTURE_SAMPLES      0x910F
#define GL_MAX_INTEGER_SAMPLES            0x9110
typedef void (APIENTRYP PFNGLDRAWELEMENTSBASEVERTEXPROC) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex);
typedef void (APIENTRYP PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex);
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex);
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC) (GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount, const GLint *basevertex);
typedef void (APIENTRYP PFNGLPROVOKINGVERTEXPROC) (GLenum mode);
typedef GLsync (APIENTRYP PFNGLFENCESYNCPROC) (GLenum condition, GLbitfield flags);
typedef GLboolean (APIENTRYP PFNGLISSYNCPROC) (GLsync sync);
typedef void (APIENTRYP PFNGLDELETESYNCPROC) (GLsync sync);
typedef GLenum (APIENTRYP PFNGLCLIENTWAITSYNCPROC) (GLsync sync, GLbitfield flags, GLuint64 timeout);
typedef void (APIENTRYP PFNGLWAITSYNCPROC) (GLsync sync, GLbitfield flags, GLuint64 timeout);
typedef void (APIENTRYP PFNGLGETINTEGER64VPROC) (GLenum pname, GLint64 *data);
typedef void (APIENTRYP PFNGLGETSYNCIVPROC) (GLsync sync, GLenum pname, GLsizei count, GLsizei *length, GLint *values);
typedef void (APIENTRYP PFNGLGETINTEGER64I_VPROC) (GLenum target, GLuint index, GLint64 *data);
typedef void (APIENTRYP PFNGLGETBUFFERPARAMETERI64VPROC) (GLenum target, GLenum pname, GLint64 *params);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTUREPROC) (GLenum target, GLenum attachment, GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLTEXIMAGE2DMULTISAMPLEPROC) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFNGLTEXIMAGE3DMULTISAMPLEPROC) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFNGLGETMULTISAMPLEFVPROC) (GLenum pname, GLuint index, GLfloat *val);
typedef void (APIENTRYP PFNGLSAMPLEMASKIPROC) (GLuint maskNumber, GLbitfield mask);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glDrawElementsBaseVertex (GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex);
GLAPI void APIENTRY glDrawRangeElementsBaseVertex (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex);
GLAPI void APIENTRY glDrawElementsInstancedBaseVertex (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex);
GLAPI void APIENTRY glMultiDrawElementsBaseVertex (GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount, const GLint *basevertex);
GLAPI void APIENTRY glProvokingVertex (GLenum mode);
GLAPI GLsync APIENTRY glFenceSync (GLenum condition, GLbitfield flags);
GLAPI GLboolean APIENTRY glIsSync (GLsync sync);
GLAPI void APIENTRY glDeleteSync (GLsync sync);
GLAPI GLenum APIENTRY glClientWaitSync (GLsync sync, GLbitfield flags, GLuint64 timeout);
GLAPI void APIENTRY glWaitSync (GLsync sync, GLbitfield flags, GLuint64 timeout);
GLAPI void APIENTRY glGetInteger64v (GLenum pname, GLint64 *data);
GLAPI void APIENTRY glGetSynciv (GLsync sync, GLenum pname, GLsizei count, GLsizei *length, GLint *values);
GLAPI void APIENTRY glGetInteger64i_v (GLenum target, GLuint index, GLint64 *data);
GLAPI void APIENTRY glGetBufferParameteri64v (GLenum target, GLenum pname, GLint64 *params);
GLAPI void APIENTRY glFramebufferTexture (GLenum target, GLenum attachment, GLuint texture, GLint level);
GLAPI void APIENTRY glTexImage2DMultisample (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
GLAPI void APIENTRY glTexImage3DMultisample (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
GLAPI void APIENTRY glGetMultisamplefv (GLenum pname, GLuint index, GLfloat *val);
GLAPI void APIENTRY glSampleMaski (GLuint maskNumber, GLbitfield mask);
#endif
#endif /* GL_VERSION_3_2 */
#ifndef GL_VERSION_3_3
#define GL_VERSION_3_3 1
#define GL_VERTEX_ATTRIB_ARRAY_DIVISOR    0x88FE
#define GL_SRC1_COLOR                     0x88F9
#define GL_ONE_MINUS_SRC1_COLOR           0x88FA
#define GL_ONE_MINUS_SRC1_ALPHA           0x88FB
#define GL_MAX_DUAL_SOURCE_DRAW_BUFFERS   0x88FC
#define GL_ANY_SAMPLES_PASSED             0x8C2F
#define GL_SAMPLER_BINDING                0x8919
#define GL_RGB10_A2UI                     0x906F
#define GL_TEXTURE_SWIZZLE_R              0x8E42
#define GL_TEXTURE_SWIZZLE_G              0x8E43
#define GL_TEXTURE_SWIZZLE_B              0x8E44
#define GL_TEXTURE_SWIZZLE_A              0x8E45
#define GL_TEXTURE_SWIZZLE_RGBA           0x8E46
#define GL_TIME_ELAPSED                   0x88BF
#define GL_TIMESTAMP                      0x8E28
#define GL_INT_2_10_10_10_REV             0x8D9F
typedef void (APIENTRYP PFNGLBINDFRAGDATALOCATIONINDEXEDPROC) (GLuint program, GLuint colorNumber, GLuint index, const GLchar *name);
typedef GLint (APIENTRYP PFNGLGETFRAGDATAINDEXPROC) (GLuint program, const GLchar *name);
typedef void (APIENTRYP PFNGLGENSAMPLERSPROC) (GLsizei count, GLuint *samplers);
typedef void (APIENTRYP PFNGLDELETESAMPLERSPROC) (GLsizei count, const GLuint *samplers);
typedef GLboolean (APIENTRYP PFNGLISSAMPLERPROC) (GLuint sampler);
typedef void (APIENTRYP PFNGLBINDSAMPLERPROC) (GLuint unit, GLuint sampler);
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIPROC) (GLuint sampler, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIVPROC) (GLuint sampler, GLenum pname, const GLint *param);
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERFPROC) (GLuint sampler, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERFVPROC) (GLuint sampler, GLenum pname, const GLfloat *param);
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIIVPROC) (GLuint sampler, GLenum pname, const GLint *param);
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIUIVPROC) (GLuint sampler, GLenum pname, const GLuint *param);
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIVPROC) (GLuint sampler, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIIVPROC) (GLuint sampler, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERFVPROC) (GLuint sampler, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIUIVPROC) (GLuint sampler, GLenum pname, GLuint *params);
typedef void (APIENTRYP PFNGLQUERYCOUNTERPROC) (GLuint id, GLenum target);
typedef void (APIENTRYP PFNGLGETQUERYOBJECTI64VPROC) (GLuint id, GLenum pname, GLint64 *params);
typedef void (APIENTRYP PFNGLGETQUERYOBJECTUI64VPROC) (GLuint id, GLenum pname, GLuint64 *params);
typedef void (APIENTRYP PFNGLVERTEXATTRIBDIVISORPROC) (GLuint index, GLuint divisor);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP1UIPROC) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP1UIVPROC) (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP2UIPROC) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP2UIVPROC) (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP3UIPROC) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP3UIVPROC) (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP4UIPROC) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP4UIVPROC) (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glBindFragDataLocationIndexed (GLuint program, GLuint colorNumber, GLuint index, const GLchar *name);
GLAPI GLint APIENTRY glGetFragDataIndex (GLuint program, const GLchar *name);
GLAPI void APIENTRY glGenSamplers (GLsizei count, GLuint *samplers);
GLAPI void APIENTRY glDeleteSamplers (GLsizei count, const GLuint *samplers);
GLAPI GLboolean APIENTRY glIsSampler (GLuint sampler);
GLAPI void APIENTRY glBindSampler (GLuint unit, GLuint sampler);
GLAPI void APIENTRY glSamplerParameteri (GLuint sampler, GLenum pname, GLint param);
GLAPI void APIENTRY glSamplerParameteriv (GLuint sampler, GLenum pname, const GLint *param);
GLAPI void APIENTRY glSamplerParameterf (GLuint sampler, GLenum pname, GLfloat param);
GLAPI void APIENTRY glSamplerParameterfv (GLuint sampler, GLenum pname, const GLfloat *param);
GLAPI void APIENTRY glSamplerParameterIiv (GLuint sampler, GLenum pname, const GLint *param);
GLAPI void APIENTRY glSamplerParameterIuiv (GLuint sampler, GLenum pname, const GLuint *param);
GLAPI void APIENTRY glGetSamplerParameteriv (GLuint sampler, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetSamplerParameterIiv (GLuint sampler, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetSamplerParameterfv (GLuint sampler, GLenum pname, GLfloat *params);
GLAPI void APIENTRY glGetSamplerParameterIuiv (GLuint sampler, GLenum pname, GLuint *params);
GLAPI void APIENTRY glQueryCounter (GLuint id, GLenum target);
GLAPI void APIENTRY glGetQueryObjecti64v (GLuint id, GLenum pname, GLint64 *params);
GLAPI void APIENTRY glGetQueryObjectui64v (GLuint id, GLenum pname, GLuint64 *params);
GLAPI void APIENTRY glVertexAttribDivisor (GLuint index, GLuint divisor);
GLAPI void APIENTRY glVertexAttribP1ui (GLuint index, GLenum type, GLboolean normalized, GLuint value);
GLAPI void APIENTRY glVertexAttribP1uiv (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
GLAPI void APIENTRY glVertexAttribP2ui (GLuint index, GLenum type, GLboolean normalized, GLuint value);
GLAPI void APIENTRY glVertexAttribP2uiv (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
GLAPI void APIENTRY glVertexAttribP3ui (GLuint index, GLenum type, GLboolean normalized, GLuint value);
GLAPI void APIENTRY glVertexAttribP3uiv (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
GLAPI void APIENTRY glVertexAttribP4ui (GLuint index, GLenum type, GLboolean normalized, GLuint value);
GLAPI void APIENTRY glVertexAttribP4uiv (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
#endif
#endif /* GL_VERSION_3_3 */
#ifndef GL_VERSION_4_0
#define GL_VERSION_4_0 1
#define GL_SAMPLE_SHADING                 0x8C36
#define GL_MIN_SAMPLE_SHADING_VALUE       0x8C37
#define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET 0x8E5E
#define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET 0x8E5F
#define GL_TEXTURE_CUBE_MAP_ARRAY         0x9009
#define GL_TEXTURE_BINDING_CUBE_MAP_ARRAY 0x900A
#define GL_PROXY_TEXTURE_CUBE_MAP_ARRAY   0x900B
#define GL_SAMPLER_CUBE_MAP_ARRAY         0x900C
#define GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW  0x900D
#define GL_INT_SAMPLER_CUBE_MAP_ARRAY     0x900E
#define GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY 0x900F
#define GL_DRAW_INDIRECT_BUFFER           0x8F3F
#define GL_DRAW_INDIRECT_BUFFER_BINDING   0x8F43
#define GL_GEOMETRY_SHADER_INVOCATIONS    0x887F
#define GL_MAX_GEOMETRY_SHADER_INVOCATIONS 0x8E5A
#define GL_MIN_FRAGMENT_INTERPOLATION_OFFSET 0x8E5B
#define GL_MAX_FRAGMENT_INTERPOLATION_OFFSET 0x8E5C
#define GL_FRAGMENT_INTERPOLATION_OFFSET_BITS 0x8E5D
#define GL_MAX_VERTEX_STREAMS             0x8E71
#define GL_DOUBLE_VEC2                    0x8FFC
#define GL_DOUBLE_VEC3                    0x8FFD
#define GL_DOUBLE_VEC4                    0x8FFE
#define GL_DOUBLE_MAT2                    0x8F46
#define GL_DOUBLE_MAT3                    0x8F47
#define GL_DOUBLE_MAT4                    0x8F48
#define GL_DOUBLE_MAT2x3                  0x8F49
#define GL_DOUBLE_MAT2x4                  0x8F4A
#define GL_DOUBLE_MAT3x2                  0x8F4B
#define GL_DOUBLE_MAT3x4                  0x8F4C
#define GL_DOUBLE_MAT4x2                  0x8F4D
#define GL_DOUBLE_MAT4x3                  0x8F4E
#define GL_ACTIVE_SUBROUTINES             0x8DE5
#define GL_ACTIVE_SUBROUTINE_UNIFORMS     0x8DE6
#define GL_ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS 0x8E47
#define GL_ACTIVE_SUBROUTINE_MAX_LENGTH   0x8E48
#define GL_ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH 0x8E49
#define GL_MAX_SUBROUTINES                0x8DE7
#define GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS 0x8DE8
#define GL_NUM_COMPATIBLE_SUBROUTINES     0x8E4A
#define GL_COMPATIBLE_SUBROUTINES         0x8E4B
#define GL_PATCHES                        0x000E
#define GL_PATCH_VERTICES                 0x8E72
#define GL_PATCH_DEFAULT_INNER_LEVEL      0x8E73
#define GL_PATCH_DEFAULT_OUTER_LEVEL      0x8E74
#define GL_TESS_CONTROL_OUTPUT_VERTICES   0x8E75
#define GL_TESS_GEN_MODE                  0x8E76
#define GL_TESS_GEN_SPACING               0x8E77
#define GL_TESS_GEN_VERTEX_ORDER          0x8E78
#define GL_TESS_GEN_POINT_MODE            0x8E79
#define GL_ISOLINES                       0x8E7A
#define GL_FRACTIONAL_ODD                 0x8E7B
#define GL_FRACTIONAL_EVEN                0x8E7C
#define GL_MAX_PATCH_VERTICES             0x8E7D
#define GL_MAX_TESS_GEN_LEVEL             0x8E7E
#define GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS 0x8E7F
#define GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS 0x8E80
#define GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS 0x8E81
#define GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS 0x8E82
#define GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS 0x8E83
#define GL_MAX_TESS_PATCH_COMPONENTS      0x8E84
#define GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS 0x8E85
#define GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS 0x8E86
#define GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS 0x8E89
#define GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS 0x8E8A
#define GL_MAX_TESS_CONTROL_INPUT_COMPONENTS 0x886C
#define GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS 0x886D
#define GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS 0x8E1E
#define GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS 0x8E1F
#define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER 0x84F0
#define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER 0x84F1
#define GL_TESS_EVALUATION_SHADER         0x8E87
#define GL_TESS_CONTROL_SHADER            0x8E88
#define GL_TRANSFORM_FEEDBACK             0x8E22
#define GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED 0x8E23
#define GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE 0x8E24
#define GL_TRANSFORM_FEEDBACK_BINDING     0x8E25
#define GL_MAX_TRANSFORM_FEEDBACK_BUFFERS 0x8E70
typedef void (APIENTRYP PFNGLMINSAMPLESHADINGPROC) (GLfloat value);
typedef void (APIENTRYP PFNGLBLENDEQUATIONIPROC) (GLuint buf, GLenum mode);
typedef void (APIENTRYP PFNGLBLENDEQUATIONSEPARATEIPROC) (GLuint buf, GLenum modeRGB, GLenum modeAlpha);
typedef void (APIENTRYP PFNGLBLENDFUNCIPROC) (GLuint buf, GLenum src, GLenum dst);
typedef void (APIENTRYP PFNGLBLENDFUNCSEPARATEIPROC) (GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
typedef void (APIENTRYP PFNGLDRAWARRAYSINDIRECTPROC) (GLenum mode, const void *indirect);
typedef void (APIENTRYP PFNGLDRAWELEMENTSINDIRECTPROC) (GLenum mode, GLenum type, const void *indirect);
typedef void (APIENTRYP PFNGLUNIFORM1DPROC) (GLint location, GLdouble x);
typedef void (APIENTRYP PFNGLUNIFORM2DPROC) (GLint location, GLdouble x, GLdouble y);
typedef void (APIENTRYP PFNGLUNIFORM3DPROC) (GLint location, GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLUNIFORM4DPROC) (GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFNGLUNIFORM1DVPROC) (GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORM2DVPROC) (GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORM3DVPROC) (GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORM4DVPROC) (GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X3DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X4DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X2DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X4DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X2DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X3DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLGETUNIFORMDVPROC) (GLuint program, GLint location, GLdouble *params);
typedef GLint (APIENTRYP PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC) (GLuint program, GLenum shadertype, const GLchar *name);
typedef GLuint (APIENTRYP PFNGLGETSUBROUTINEINDEXPROC) (GLuint program, GLenum shadertype, const GLchar *name);
typedef void (APIENTRYP PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC) (GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint *values);
typedef void (APIENTRYP PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC) (GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name);
typedef void (APIENTRYP PFNGLGETACTIVESUBROUTINENAMEPROC) (GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name);
typedef void (APIENTRYP PFNGLUNIFORMSUBROUTINESUIVPROC) (GLenum shadertype, GLsizei count, const GLuint *indices);
typedef void (APIENTRYP PFNGLGETUNIFORMSUBROUTINEUIVPROC) (GLenum shadertype, GLint location, GLuint *params);
typedef void (APIENTRYP PFNGLGETPROGRAMSTAGEIVPROC) (GLuint program, GLenum shadertype, GLenum pname, GLint *values);
typedef void (APIENTRYP PFNGLPATCHPARAMETERIPROC) (GLenum pname, GLint value);
typedef void (APIENTRYP PFNGLPATCHPARAMETERFVPROC) (GLenum pname, const GLfloat *values);
typedef void (APIENTRYP PFNGLBINDTRANSFORMFEEDBACKPROC) (GLenum target, GLuint id);
typedef void (APIENTRYP PFNGLDELETETRANSFORMFEEDBACKSPROC) (GLsizei n, const GLuint *ids);
typedef void (APIENTRYP PFNGLGENTRANSFORMFEEDBACKSPROC) (GLsizei n, GLuint *ids);
typedef GLboolean (APIENTRYP PFNGLISTRANSFORMFEEDBACKPROC) (GLuint id);
typedef void (APIENTRYP PFNGLPAUSETRANSFORMFEEDBACKPROC) (void);
typedef void (APIENTRYP PFNGLRESUMETRANSFORMFEEDBACKPROC) (void);
typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKPROC) (GLenum mode, GLuint id);
typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC) (GLenum mode, GLuint id, GLuint stream);
typedef void (APIENTRYP PFNGLBEGINQUERYINDEXEDPROC) (GLenum target, GLuint index, GLuint id);
typedef void (APIENTRYP PFNGLENDQUERYINDEXEDPROC) (GLenum target, GLuint index);
typedef void (APIENTRYP PFNGLGETQUERYINDEXEDIVPROC) (GLenum target, GLuint index, GLenum pname, GLint *params);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glMinSampleShading (GLfloat value);
GLAPI void APIENTRY glBlendEquationi (GLuint buf, GLenum mode);
GLAPI void APIENTRY glBlendEquationSeparatei (GLuint buf, GLenum modeRGB, GLenum modeAlpha);
GLAPI void APIENTRY glBlendFunci (GLuint buf, GLenum src, GLenum dst);
GLAPI void APIENTRY glBlendFuncSeparatei (GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
GLAPI void APIENTRY glDrawArraysIndirect (GLenum mode, const void *indirect);
GLAPI void APIENTRY glDrawElementsIndirect (GLenum mode, GLenum type, const void *indirect);
GLAPI void APIENTRY glUniform1d (GLint location, GLdouble x);
GLAPI void APIENTRY glUniform2d (GLint location, GLdouble x, GLdouble y);
GLAPI void APIENTRY glUniform3d (GLint location, GLdouble x, GLdouble y, GLdouble z);
GLAPI void APIENTRY glUniform4d (GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI void APIENTRY glUniform1dv (GLint location, GLsizei count, const GLdouble *value);
GLAPI void APIENTRY glUniform2dv (GLint location, GLsizei count, const GLdouble *value);
GLAPI void APIENTRY glUniform3dv (GLint location, GLsizei count, const GLdouble *value);
GLAPI void APIENTRY glUniform4dv (GLint location, GLsizei count, const GLdouble *value);
GLAPI void APIENTRY glUniformMatrix2dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glUniformMatrix3dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glUniformMatrix4dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glUniformMatrix2x3dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glUniformMatrix2x4dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glUniformMatrix3x2dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glUniformMatrix3x4dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glUniformMatrix4x2dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glUniformMatrix4x3dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glGetUniformdv (GLuint program, GLint location, GLdouble *params);
GLAPI GLint APIENTRY glGetSubroutineUniformLocation (GLuint program, GLenum shadertype, const GLchar *name);
GLAPI GLuint APIENTRY glGetSubroutineIndex (GLuint program, GLenum shadertype, const GLchar *name);
GLAPI void APIENTRY glGetActiveSubroutineUniformiv (GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint *values);
GLAPI void APIENTRY glGetActiveSubroutineUniformName (GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name);
GLAPI void APIENTRY glGetActiveSubroutineName (GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name);
GLAPI void APIENTRY glUniformSubroutinesuiv (GLenum shadertype, GLsizei count, const GLuint *indices);
GLAPI void APIENTRY glGetUniformSubroutineuiv (GLenum shadertype, GLint location, GLuint *params);
GLAPI void APIENTRY glGetProgramStageiv (GLuint program, GLenum shadertype, GLenum pname, GLint *values);
GLAPI void APIENTRY glPatchParameteri (GLenum pname, GLint value);
GLAPI void APIENTRY glPatchParameterfv (GLenum pname, const GLfloat *values);
GLAPI void APIENTRY glBindTransformFeedback (GLenum target, GLuint id);
GLAPI void APIENTRY glDeleteTransformFeedbacks (GLsizei n, const GLuint *ids);
GLAPI void APIENTRY glGenTransformFeedbacks (GLsizei n, GLuint *ids);
GLAPI GLboolean APIENTRY glIsTransformFeedback (GLuint id);
GLAPI void APIENTRY glPauseTransformFeedback (void);
GLAPI void APIENTRY glResumeTransformFeedback (void);
GLAPI void APIENTRY glDrawTransformFeedback (GLenum mode, GLuint id);
GLAPI void APIENTRY glDrawTransformFeedbackStream (GLenum mode, GLuint id, GLuint stream);
GLAPI void APIENTRY glBeginQueryIndexed (GLenum target, GLuint index, GLuint id);
GLAPI void APIENTRY glEndQueryIndexed (GLenum target, GLuint index);
GLAPI void APIENTRY glGetQueryIndexediv (GLenum target, GLuint index, GLenum pname, GLint *params);
#endif
#endif /* GL_VERSION_4_0 */
#ifndef GL_VERSION_4_1
#define GL_VERSION_4_1 1
#define GL_FIXED                          0x140C
#define GL_IMPLEMENTATION_COLOR_READ_TYPE 0x8B9A
#define GL_IMPLEMENTATION_COLOR_READ_FORMAT 0x8B9B
#define GL_LOW_FLOAT                      0x8DF0
#define GL_MEDIUM_FLOAT                   0x8DF1
#define GL_HIGH_FLOAT                     0x8DF2
#define GL_LOW_INT                        0x8DF3
#define GL_MEDIUM_INT                     0x8DF4
#define GL_HIGH_INT                       0x8DF5
#define GL_SHADER_COMPILER                0x8DFA
#define GL_SHADER_BINARY_FORMATS          0x8DF8
#define GL_NUM_SHADER_BINARY_FORMATS      0x8DF9
#define GL_MAX_VERTEX_UNIFORM_VECTORS     0x8DFB
#define GL_MAX_VARYING_VECTORS            0x8DFC
#define GL_MAX_FRAGMENT_UNIFORM_VECTORS   0x8DFD
#define GL_RGB565                         0x8D62
#define GL_PROGRAM_BINARY_RETRIEVABLE_HINT 0x8257
#define GL_PROGRAM_BINARY_LENGTH          0x8741
#define GL_NUM_PROGRAM_BINARY_FORMATS     0x87FE
#define GL_PROGRAM_BINARY_FORMATS         0x87FF
#define GL_VERTEX_SHADER_BIT              0x00000001
#define GL_FRAGMENT_SHADER_BIT            0x00000002
#define GL_GEOMETRY_SHADER_BIT            0x00000004
#define GL_TESS_CONTROL_SHADER_BIT        0x00000008
#define GL_TESS_EVALUATION_SHADER_BIT     0x00000010
#define GL_ALL_SHADER_BITS                0xFFFFFFFF
#define GL_PROGRAM_SEPARABLE              0x8258
#define GL_ACTIVE_PROGRAM                 0x8259
#define GL_PROGRAM_PIPELINE_BINDING       0x825A
#define GL_MAX_VIEWPORTS                  0x825B
#define GL_VIEWPORT_SUBPIXEL_BITS         0x825C
#define GL_VIEWPORT_BOUNDS_RANGE          0x825D
#define GL_LAYER_PROVOKING_VERTEX         0x825E
#define GL_VIEWPORT_INDEX_PROVOKING_VERTEX 0x825F
#define GL_UNDEFINED_VERTEX               0x8260
typedef void (APIENTRYP PFNGLRELEASESHADERCOMPILERPROC) (void);
typedef void (APIENTRYP PFNGLSHADERBINARYPROC) (GLsizei count, const GLuint *shaders, GLenum binaryFormat, const void *binary, GLsizei length);
typedef void (APIENTRYP PFNGLGETSHADERPRECISIONFORMATPROC) (GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision);
typedef void (APIENTRYP PFNGLDEPTHRANGEFPROC) (GLfloat n, GLfloat f);
typedef void (APIENTRYP PFNGLCLEARDEPTHFPROC) (GLfloat d);
typedef void (APIENTRYP PFNGLGETPROGRAMBINARYPROC) (GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary);
typedef void (APIENTRYP PFNGLPROGRAMBINARYPROC) (GLuint program, GLenum binaryFormat, const void *binary, GLsizei length);
typedef void (APIENTRYP PFNGLPROGRAMPARAMETERIPROC) (GLuint program, GLenum pname, GLint value);
typedef void (APIENTRYP PFNGLUSEPROGRAMSTAGESPROC) (GLuint pipeline, GLbitfield stages, GLuint program);
typedef void (APIENTRYP PFNGLACTIVESHADERPROGRAMPROC) (GLuint pipeline, GLuint program);
typedef GLuint (APIENTRYP PFNGLCREATESHADERPROGRAMVPROC) (GLenum type, GLsizei count, const GLchar *const*strings);
typedef void (APIENTRYP PFNGLBINDPROGRAMPIPELINEPROC) (GLuint pipeline);
typedef void (APIENTRYP PFNGLDELETEPROGRAMPIPELINESPROC) (GLsizei n, const GLuint *pipelines);
typedef void (APIENTRYP PFNGLGENPROGRAMPIPELINESPROC) (GLsizei n, GLuint *pipelines);
typedef GLboolean (APIENTRYP PFNGLISPROGRAMPIPELINEPROC) (GLuint pipeline);
typedef void (APIENTRYP PFNGLGETPROGRAMPIPELINEIVPROC) (GLuint pipeline, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1IPROC) (GLuint program, GLint location, GLint v0);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1IVPROC) (GLuint program, GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1FPROC) (GLuint program, GLint location, GLfloat v0);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1FVPROC) (GLuint program, GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1DPROC) (GLuint program, GLint location, GLdouble v0);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1DVPROC) (GLuint program, GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UIPROC) (GLuint program, GLint location, GLuint v0);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UIVPROC) (GLuint program, GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2IPROC) (GLuint program, GLint location, GLint v0, GLint v1);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2IVPROC) (GLuint program, GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2FPROC) (GLuint program, GLint location, GLfloat v0, GLfloat v1);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2FVPROC) (GLuint program, GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2DPROC) (GLuint program, GLint location, GLdouble v0, GLdouble v1);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2DVPROC) (GLuint program, GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UIPROC) (GLuint program, GLint location, GLuint v0, GLuint v1);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UIVPROC) (GLuint program, GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3IPROC) (GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3IVPROC) (GLuint program, GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3FPROC) (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3FVPROC) (GLuint program, GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3DPROC) (GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3DVPROC) (GLuint program, GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UIPROC) (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UIVPROC) (GLuint program, GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4IPROC) (GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4IVPROC) (GLuint program, GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4FPROC) (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4FVPROC) (GLuint program, GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4DPROC) (GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4DVPROC) (GLuint program, GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UIPROC) (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UIVPROC) (GLuint program, GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLVALIDATEPROGRAMPIPELINEPROC) (GLuint pipeline);
typedef void (APIENTRYP PFNGLGETPROGRAMPIPELINEINFOLOGPROC) (GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1DPROC) (GLuint index, GLdouble x);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL2DPROC) (GLuint index, GLdouble x, GLdouble y);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL3DPROC) (GLuint index, GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL4DPROC) (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1DVPROC) (GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL2DVPROC) (GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL3DVPROC) (GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL4DVPROC) (GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBLPOINTERPROC) (GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBLDVPROC) (GLuint index, GLenum pname, GLdouble *params);
typedef void (APIENTRYP PFNGLVIEWPORTARRAYVPROC) (GLuint first, GLsizei count, const GLfloat *v);
typedef void (APIENTRYP PFNGLVIEWPORTINDEXEDFPROC) (GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
typedef void (APIENTRYP PFNGLVIEWPORTINDEXEDFVPROC) (GLuint index, const GLfloat *v);
typedef void (APIENTRYP PFNGLSCISSORARRAYVPROC) (GLuint first, GLsizei count, const GLint *v);
typedef void (APIENTRYP PFNGLSCISSORINDEXEDPROC) (GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLSCISSORINDEXEDVPROC) (GLuint index, const GLint *v);
typedef void (APIENTRYP PFNGLDEPTHRANGEARRAYVPROC) (GLuint first, GLsizei count, const GLdouble *v);
typedef void (APIENTRYP PFNGLDEPTHRANGEINDEXEDPROC) (GLuint index, GLdouble n, GLdouble f);
typedef void (APIENTRYP PFNGLGETFLOATI_VPROC) (GLenum target, GLuint index, GLfloat *data);
typedef void (APIENTRYP PFNGLGETDOUBLEI_VPROC) (GLenum target, GLuint index, GLdouble *data);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glReleaseShaderCompiler (void);
GLAPI void APIENTRY glShaderBinary (GLsizei count, const GLuint *shaders, GLenum binaryFormat, const void *binary, GLsizei length);
GLAPI void APIENTRY glGetShaderPrecisionFormat (GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision);
GLAPI void APIENTRY glDepthRangef (GLfloat n, GLfloat f);
GLAPI void APIENTRY glClearDepthf (GLfloat d);
GLAPI void APIENTRY glGetProgramBinary (GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary);
GLAPI void APIENTRY glProgramBinary (GLuint program, GLenum binaryFormat, const void *binary, GLsizei length);
GLAPI void APIENTRY glProgramParameteri (GLuint program, GLenum pname, GLint value);
GLAPI void APIENTRY glUseProgramStages (GLuint pipeline, GLbitfield stages, GLuint program);
GLAPI void APIENTRY glActiveShaderProgram (GLuint pipeline, GLuint program);
GLAPI GLuint APIENTRY glCreateShaderProgramv (GLenum type, GLsizei count, const GLchar *const*strings);
GLAPI void APIENTRY glBindProgramPipeline (GLuint pipeline);
GLAPI void APIENTRY glDeleteProgramPipelines (GLsizei n, const GLuint *pipelines);
GLAPI void APIENTRY glGenProgramPipelines (GLsizei n, GLuint *pipelines);
GLAPI GLboolean APIENTRY glIsProgramPipeline (GLuint pipeline);
GLAPI void APIENTRY glGetProgramPipelineiv (GLuint pipeline, GLenum pname, GLint *params);
GLAPI void APIENTRY glProgramUniform1i (GLuint program, GLint location, GLint v0);
GLAPI void APIENTRY glProgramUniform1iv (GLuint program, GLint location, GLsizei count, const GLint *value);
GLAPI void APIENTRY glProgramUniform1f (GLuint program, GLint location, GLfloat v0);
GLAPI void APIENTRY glProgramUniform1fv (GLuint program, GLint location, GLsizei count, const GLfloat *value);
GLAPI void APIENTRY glProgramUniform1d (GLuint program, GLint location, GLdouble v0);
GLAPI void APIENTRY glProgramUniform1dv (GLuint program, GLint location, GLsizei count, const GLdouble *value);
GLAPI void APIENTRY glProgramUniform1ui (GLuint program, GLint location, GLuint v0);
GLAPI void APIENTRY glProgramUniform1uiv (GLuint program, GLint location, GLsizei count, const GLuint *value);
GLAPI void APIENTRY glProgramUniform2i (GLuint program, GLint location, GLint v0, GLint v1);
GLAPI void APIENTRY glProgramUniform2iv (GLuint program, GLint location, GLsizei count, const GLint *value);
GLAPI void APIENTRY glProgramUniform2f (GLuint program, GLint location, GLfloat v0, GLfloat v1);
GLAPI void APIENTRY glProgramUniform2fv (GLuint program, GLint location, GLsizei count, const GLfloat *value);
GLAPI void APIENTRY glProgramUniform2d (GLuint program, GLint location, GLdouble v0, GLdouble v1);
GLAPI void APIENTRY glProgramUniform2dv (GLuint program, GLint location, GLsizei count, const GLdouble *value);
GLAPI void APIENTRY glProgramUniform2ui (GLuint program, GLint location, GLuint v0, GLuint v1);
GLAPI void APIENTRY glProgramUniform2uiv (GLuint program, GLint location, GLsizei count, const GLuint *value);
GLAPI void APIENTRY glProgramUniform3i (GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
GLAPI void APIENTRY glProgramUniform3iv (GLuint program, GLint location, GLsizei count, const GLint *value);
GLAPI void APIENTRY glProgramUniform3f (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
GLAPI void APIENTRY glProgramUniform3fv (GLuint program, GLint location, GLsizei count, const GLfloat *value);
GLAPI void APIENTRY glProgramUniform3d (GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2);
GLAPI void APIENTRY glProgramUniform3dv (GLuint program, GLint location, GLsizei count, const GLdouble *value);
GLAPI void APIENTRY glProgramUniform3ui (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
GLAPI void APIENTRY glProgramUniform3uiv (GLuint program, GLint location, GLsizei count, const GLuint *value);
GLAPI void APIENTRY glProgramUniform4i (GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
GLAPI void APIENTRY glProgramUniform4iv (GLuint program, GLint location, GLsizei count, const GLint *value);
GLAPI void APIENTRY glProgramUniform4f (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
GLAPI void APIENTRY glProgramUniform4fv (GLuint program, GLint location, GLsizei count, const GLfloat *value);
GLAPI void APIENTRY glProgramUniform4d (GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
GLAPI void APIENTRY glProgramUniform4dv (GLuint program, GLint location, GLsizei count, const GLdouble *value);
GLAPI void APIENTRY glProgramUniform4ui (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
GLAPI void APIENTRY glProgramUniform4uiv (GLuint program, GLint location, GLsizei count, const GLuint *value);
GLAPI void APIENTRY glProgramUniformMatrix2fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glProgramUniformMatrix3fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glProgramUniformMatrix4fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glProgramUniformMatrix2dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glProgramUniformMatrix3dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glProgramUniformMatrix4dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glProgramUniformMatrix2x3fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glProgramUniformMatrix3x2fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glProgramUniformMatrix2x4fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glProgramUniformMatrix4x2fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glProgramUniformMatrix3x4fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glProgramUniformMatrix4x3fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glProgramUniformMatrix2x3dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glProgramUniformMatrix3x2dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glProgramUniformMatrix2x4dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glProgramUniformMatrix4x2dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glProgramUniformMatrix3x4dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glProgramUniformMatrix4x3dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glValidateProgramPipeline (GLuint pipeline);
GLAPI void APIENTRY glGetProgramPipelineInfoLog (GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
GLAPI void APIENTRY glVertexAttribL1d (GLuint index, GLdouble x);
GLAPI void APIENTRY glVertexAttribL2d (GLuint index, GLdouble x, GLdouble y);
GLAPI void APIENTRY glVertexAttribL3d (GLuint index, GLdouble x, GLdouble y, GLdouble z);
GLAPI void APIENTRY glVertexAttribL4d (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI void APIENTRY glVertexAttribL1dv (GLuint index, const GLdouble *v);
GLAPI void APIENTRY glVertexAttribL2dv (GLuint index, const GLdouble *v);
GLAPI void APIENTRY glVertexAttribL3dv (GLuint index, const GLdouble *v);
GLAPI void APIENTRY glVertexAttribL4dv (GLuint index, const GLdouble *v);
GLAPI void APIENTRY glVertexAttribLPointer (GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
GLAPI void APIENTRY glGetVertexAttribLdv (GLuint index, GLenum pname, GLdouble *params);
GLAPI void APIENTRY glViewportArrayv (GLuint first, GLsizei count, const GLfloat *v);
GLAPI void APIENTRY glViewportIndexedf (GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
GLAPI void APIENTRY glViewportIndexedfv (GLuint index, const GLfloat *v);
GLAPI void APIENTRY glScissorArrayv (GLuint first, GLsizei count, const GLint *v);
GLAPI void APIENTRY glScissorIndexed (GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
GLAPI void APIENTRY glScissorIndexedv (GLuint index, const GLint *v);
GLAPI void APIENTRY glDepthRangeArrayv (GLuint first, GLsizei count, const GLdouble *v);
GLAPI void APIENTRY glDepthRangeIndexed (GLuint index, GLdouble n, GLdouble f);
GLAPI void APIENTRY glGetFloati_v (GLenum target, GLuint index, GLfloat *data);
GLAPI void APIENTRY glGetDoublei_v (GLenum target, GLuint index, GLdouble *data);
#endif
#endif /* GL_VERSION_4_1 */
#ifndef GL_VERSION_4_2
#define GL_VERSION_4_2 1
#define GL_COPY_READ_BUFFER_BINDING       0x8F36
#define GL_COPY_WRITE_BUFFER_BINDING      0x8F37
#define GL_TRANSFORM_FEEDBACK_ACTIVE      0x8E24
#define GL_TRANSFORM_FEEDBACK_PAUSED      0x8E23
#define GL_UNPACK_COMPRESSED_BLOCK_WIDTH  0x9127
#define GL_UNPACK_COMPRESSED_BLOCK_HEIGHT 0x9128
#define GL_UNPACK_COMPRESSED_BLOCK_DEPTH  0x9129
#define GL_UNPACK_COMPRESSED_BLOCK_SIZE   0x912A
#define GL_PACK_COMPRESSED_BLOCK_WIDTH    0x912B
#define GL_PACK_COMPRESSED_BLOCK_HEIGHT   0x912C
#define GL_PACK_COMPRESSED_BLOCK_DEPTH    0x912D
#define GL_PACK_COMPRESSED_BLOCK_SIZE     0x912E
#define GL_NUM_SAMPLE_COUNTS              0x9380
#define GL_MIN_MAP_BUFFER_ALIGNMENT       0x90BC
#define GL_ATOMIC_COUNTER_BUFFER          0x92C0
#define GL_ATOMIC_COUNTER_BUFFER_BINDING  0x92C1
#define GL_ATOMIC_COUNTER_BUFFER_START    0x92C2
#define GL_ATOMIC_COUNTER_BUFFER_SIZE     0x92C3
#define GL_ATOMIC_COUNTER_BUFFER_DATA_SIZE 0x92C4
#define GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTERS 0x92C5
#define GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTER_INDICES 0x92C6
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_VERTEX_SHADER 0x92C7
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_CONTROL_SHADER 0x92C8
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_EVALUATION_SHADER 0x92C9
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_GEOMETRY_SHADER 0x92CA
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_FRAGMENT_SHADER 0x92CB
#define GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS 0x92CC
#define GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS 0x92CD
#define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS 0x92CE
#define GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS 0x92CF
#define GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS 0x92D0
#define GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS 0x92D1
#define GL_MAX_VERTEX_ATOMIC_COUNTERS     0x92D2
#define GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS 0x92D3
#define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS 0x92D4
#define GL_MAX_GEOMETRY_ATOMIC_COUNTERS   0x92D5
#define GL_MAX_FRAGMENT_ATOMIC_COUNTERS   0x92D6
#define GL_MAX_COMBINED_ATOMIC_COUNTERS   0x92D7
#define GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE 0x92D8
#define GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS 0x92DC
#define GL_ACTIVE_ATOMIC_COUNTER_BUFFERS  0x92D9
#define GL_UNIFORM_ATOMIC_COUNTER_BUFFER_INDEX 0x92DA
#define GL_UNSIGNED_INT_ATOMIC_COUNTER    0x92DB
#define GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT 0x00000001
#define GL_ELEMENT_ARRAY_BARRIER_BIT      0x00000002
#define GL_UNIFORM_BARRIER_BIT            0x00000004
#define GL_TEXTURE_FETCH_BARRIER_BIT      0x00000008
#define GL_SHADER_IMAGE_ACCESS_BARRIER_BIT 0x00000020
#define GL_COMMAND_BARRIER_BIT            0x00000040
#define GL_PIXEL_BUFFER_BARRIER_BIT       0x00000080
#define GL_TEXTURE_UPDATE_BARRIER_BIT     0x00000100
#define GL_BUFFER_UPDATE_BARRIER_BIT      0x00000200
#define GL_FRAMEBUFFER_BARRIER_BIT        0x00000400
#define GL_TRANSFORM_FEEDBACK_BARRIER_BIT 0x00000800
#define GL_ATOMIC_COUNTER_BARRIER_BIT     0x00001000
#define GL_ALL_BARRIER_BITS               0xFFFFFFFF
#define GL_MAX_IMAGE_UNITS                0x8F38
#define GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS 0x8F39
#define GL_IMAGE_BINDING_NAME             0x8F3A
#define GL_IMAGE_BINDING_LEVEL            0x8F3B
#define GL_IMAGE_BINDING_LAYERED          0x8F3C
#define GL_IMAGE_BINDING_LAYER            0x8F3D
#define GL_IMAGE_BINDING_ACCESS           0x8F3E
#define GL_IMAGE_1D                       0x904C
#define GL_IMAGE_2D                       0x904D
#define GL_IMAGE_3D                       0x904E
#define GL_IMAGE_2D_RECT                  0x904F
#define GL_IMAGE_CUBE                     0x9050
#define GL_IMAGE_BUFFER                   0x9051
#define GL_IMAGE_1D_ARRAY                 0x9052
#define GL_IMAGE_2D_ARRAY                 0x9053
#define GL_IMAGE_CUBE_MAP_ARRAY           0x9054
#define GL_IMAGE_2D_MULTISAMPLE           0x9055
#define GL_IMAGE_2D_MULTISAMPLE_ARRAY     0x9056
#define GL_INT_IMAGE_1D                   0x9057
#define GL_INT_IMAGE_2D                   0x9058
#define GL_INT_IMAGE_3D                   0x9059
#define GL_INT_IMAGE_2D_RECT              0x905A
#define GL_INT_IMAGE_CUBE                 0x905B
#define GL_INT_IMAGE_BUFFER               0x905C
#define GL_INT_IMAGE_1D_ARRAY             0x905D
#define GL_INT_IMAGE_2D_ARRAY             0x905E
#define GL_INT_IMAGE_CUBE_MAP_ARRAY       0x905F
#define GL_INT_IMAGE_2D_MULTISAMPLE       0x9060
#define GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY 0x9061
#define GL_UNSIGNED_INT_IMAGE_1D          0x9062
#define GL_UNSIGNED_INT_IMAGE_2D          0x9063
#define GL_UNSIGNED_INT_IMAGE_3D          0x9064
#define GL_UNSIGNED_INT_IMAGE_2D_RECT     0x9065
#define GL_UNSIGNED_INT_IMAGE_CUBE        0x9066
#define GL_UNSIGNED_INT_IMAGE_BUFFER      0x9067
#define GL_UNSIGNED_INT_IMAGE_1D_ARRAY    0x9068
#define GL_UNSIGNED_INT_IMAGE_2D_ARRAY    0x9069
#define GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY 0x906A
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE 0x906B
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY 0x906C
#define GL_MAX_IMAGE_SAMPLES              0x906D
#define GL_IMAGE_BINDING_FORMAT           0x906E
#define GL_IMAGE_FORMAT_COMPATIBILITY_TYPE 0x90C7
#define GL_IMAGE_FORMAT_COMPATIBILITY_BY_SIZE 0x90C8
#define GL_IMAGE_FORMAT_COMPATIBILITY_BY_CLASS 0x90C9
#define GL_MAX_VERTEX_IMAGE_UNIFORMS      0x90CA
#define GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS 0x90CB
#define GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS 0x90CC
#define GL_MAX_GEOMETRY_IMAGE_UNIFORMS    0x90CD
#define GL_MAX_FRAGMENT_IMAGE_UNIFORMS    0x90CE
#define GL_MAX_COMBINED_IMAGE_UNIFORMS    0x90CF
#define GL_COMPRESSED_RGBA_BPTC_UNORM     0x8E8C
#define GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM 0x8E8D
#define GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT 0x8E8E
#define GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT 0x8E8F
#define GL_TEXTURE_IMMUTABLE_FORMAT       0x912F
typedef void (APIENTRYP PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC) (GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance);
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLuint baseinstance);
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);
typedef void (APIENTRYP PFNGLGETINTERNALFORMATIVPROC) (GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint *params);
typedef void (APIENTRYP PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC) (GLuint program, GLuint bufferIndex, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLBINDIMAGETEXTUREPROC) (GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
typedef void (APIENTRYP PFNGLMEMORYBARRIERPROC) (GLbitfield barriers);
typedef void (APIENTRYP PFNGLTEXSTORAGE1DPROC) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
typedef void (APIENTRYP PFNGLTEXSTORAGE2DPROC) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLTEXSTORAGE3DPROC) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC) (GLenum mode, GLuint id, GLsizei instancecount);
typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC) (GLenum mode, GLuint id, GLuint stream, GLsizei instancecount);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glDrawArraysInstancedBaseInstance (GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance);
GLAPI void APIENTRY glDrawElementsInstancedBaseInstance (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLuint baseinstance);
GLAPI void APIENTRY glDrawElementsInstancedBaseVertexBaseInstance (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);
GLAPI void APIENTRY glGetInternalformativ (GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint *params);
GLAPI void APIENTRY glGetActiveAtomicCounterBufferiv (GLuint program, GLuint bufferIndex, GLenum pname, GLint *params);
GLAPI void APIENTRY glBindImageTexture (GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
GLAPI void APIENTRY glMemoryBarrier (GLbitfield barriers);
GLAPI void APIENTRY glTexStorage1D (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
GLAPI void APIENTRY glTexStorage2D (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI void APIENTRY glTexStorage3D (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
GLAPI void APIENTRY glDrawTransformFeedbackInstanced (GLenum mode, GLuint id, GLsizei instancecount);
GLAPI void APIENTRY glDrawTransformFeedbackStreamInstanced (GLenum mode, GLuint id, GLuint stream, GLsizei instancecount);
#endif
#endif /* GL_VERSION_4_2 */
#ifndef GL_VERSION_4_3
#define GL_VERSION_4_3 1
typedef void (APIENTRY  *GLDEBUGPROC)(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,const void *userParam);
#define GL_NUM_SHADING_LANGUAGE_VERSIONS  0x82E9
#define GL_VERTEX_ATTRIB_ARRAY_LONG       0x874E
#define GL_COMPRESSED_RGB8_ETC2           0x9274
#define GL_COMPRESSED_SRGB8_ETC2          0x9275
#define GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2 0x9276
#define GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2 0x9277
#define GL_COMPRESSED_RGBA8_ETC2_EAC      0x9278
#define GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC 0x9279
#define GL_COMPRESSED_R11_EAC             0x9270
#define GL_COMPRESSED_SIGNED_R11_EAC      0x9271
#define GL_COMPRESSED_RG11_EAC            0x9272
#define GL_COMPRESSED_SIGNED_RG11_EAC     0x9273
#define GL_PRIMITIVE_RESTART_FIXED_INDEX  0x8D69
#define GL_ANY_SAMPLES_PASSED_CONSERVATIVE 0x8D6A
#define GL_MAX_ELEMENT_INDEX              0x8D6B
#define GL_COMPUTE_SHADER                 0x91B9
#define GL_MAX_COMPUTE_UNIFORM_BLOCKS     0x91BB
#define GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS 0x91BC
#define GL_MAX_COMPUTE_IMAGE_UNIFORMS     0x91BD
#define GL_MAX_COMPUTE_SHARED_MEMORY_SIZE 0x8262
#define GL_MAX_COMPUTE_UNIFORM_COMPONENTS 0x8263
#define GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS 0x8264
#define GL_MAX_COMPUTE_ATOMIC_COUNTERS    0x8265
#define GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS 0x8266
#define GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS 0x90EB
#define GL_MAX_COMPUTE_WORK_GROUP_COUNT   0x91BE
#define GL_MAX_COMPUTE_WORK_GROUP_SIZE    0x91BF
#define GL_COMPUTE_WORK_GROUP_SIZE        0x8267
#define GL_UNIFORM_BLOCK_REFERENCED_BY_COMPUTE_SHADER 0x90EC
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_COMPUTE_SHADER 0x90ED
#define GL_DISPATCH_INDIRECT_BUFFER       0x90EE
#define GL_DISPATCH_INDIRECT_BUFFER_BINDING 0x90EF
#define GL_COMPUTE_SHADER_BIT             0x00000020
#define GL_DEBUG_OUTPUT_SYNCHRONOUS       0x8242
#define GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH 0x8243
#define GL_DEBUG_CALLBACK_FUNCTION        0x8244
#define GL_DEBUG_CALLBACK_USER_PARAM      0x8245
#define GL_DEBUG_SOURCE_API               0x8246
#define GL_DEBUG_SOURCE_WINDOW_SYSTEM     0x8247
#define GL_DEBUG_SOURCE_SHADER_COMPILER   0x8248
#define GL_DEBUG_SOURCE_THIRD_PARTY       0x8249
#define GL_DEBUG_SOURCE_APPLICATION       0x824A
#define GL_DEBUG_SOURCE_OTHER             0x824B
#define GL_DEBUG_TYPE_ERROR               0x824C
#define GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR 0x824D
#define GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR  0x824E
#define GL_DEBUG_TYPE_PORTABILITY         0x824F
#define GL_DEBUG_TYPE_PERFORMANCE         0x8250
#define GL_DEBUG_TYPE_OTHER               0x8251
#define GL_MAX_DEBUG_MESSAGE_LENGTH       0x9143
#define GL_MAX_DEBUG_LOGGED_MESSAGES      0x9144
#define GL_DEBUG_LOGGED_MESSAGES          0x9145
#define GL_DEBUG_SEVERITY_HIGH            0x9146
#define GL_DEBUG_SEVERITY_MEDIUM          0x9147
#define GL_DEBUG_SEVERITY_LOW             0x9148
#define GL_DEBUG_TYPE_MARKER              0x8268
#define GL_DEBUG_TYPE_PUSH_GROUP          0x8269
#define GL_DEBUG_TYPE_POP_GROUP           0x826A
#define GL_DEBUG_SEVERITY_NOTIFICATION    0x826B
#define GL_MAX_DEBUG_GROUP_STACK_DEPTH    0x826C
#define GL_DEBUG_GROUP_STACK_DEPTH        0x826D
#define GL_BUFFER                         0x82E0
#define GL_SHADER                         0x82E1
#define GL_PROGRAM                        0x82E2
#define GL_QUERY                          0x82E3
#define GL_PROGRAM_PIPELINE               0x82E4
#define GL_SAMPLER                        0x82E6
#define GL_MAX_LABEL_LENGTH               0x82E8
#define GL_DEBUG_OUTPUT                   0x92E0
#define GL_CONTEXT_FLAG_DEBUG_BIT         0x00000002
#define GL_MAX_UNIFORM_LOCATIONS          0x826E
#define GL_FRAMEBUFFER_DEFAULT_WIDTH      0x9310
#define GL_FRAMEBUFFER_DEFAULT_HEIGHT     0x9311
#define GL_FRAMEBUFFER_DEFAULT_LAYERS     0x9312
#define GL_FRAMEBUFFER_DEFAULT_SAMPLES    0x9313
#define GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS 0x9314
#define GL_MAX_FRAMEBUFFER_WIDTH          0x9315
#define GL_MAX_FRAMEBUFFER_HEIGHT         0x9316
#define GL_MAX_FRAMEBUFFER_LAYERS         0x9317
#define GL_MAX_FRAMEBUFFER_SAMPLES        0x9318
#define GL_INTERNALFORMAT_SUPPORTED       0x826F
#define GL_INTERNALFORMAT_PREFERRED       0x8270
#define GL_INTERNALFORMAT_RED_SIZE        0x8271
#define GL_INTERNALFORMAT_GREEN_SIZE      0x8272
#define GL_INTERNALFORMAT_BLUE_SIZE       0x8273
#define GL_INTERNALFORMAT_ALPHA_SIZE      0x8274
#define GL_INTERNALFORMAT_DEPTH_SIZE      0x8275
#define GL_INTERNALFORMAT_STENCIL_SIZE    0x8276
#define GL_INTERNALFORMAT_SHARED_SIZE     0x8277
#define GL_INTERNALFORMAT_RED_TYPE        0x8278
#define GL_INTERNALFORMAT_GREEN_TYPE      0x8279
#define GL_INTERNALFORMAT_BLUE_TYPE       0x827A
#define GL_INTERNALFORMAT_ALPHA_TYPE      0x827B
#define GL_INTERNALFORMAT_DEPTH_TYPE      0x827C
#define GL_INTERNALFORMAT_STENCIL_TYPE    0x827D
#define GL_MAX_WIDTH                      0x827E
#define GL_MAX_HEIGHT                     0x827F
#define GL_MAX_DEPTH                      0x8280
#define GL_MAX_LAYERS                     0x8281
#define GL_MAX_COMBINED_DIMENSIONS        0x8282
#define GL_COLOR_COMPONENTS               0x8283
#define GL_DEPTH_COMPONENTS               0x8284
#define GL_STENCIL_COMPONENTS             0x8285
#define GL_COLOR_RENDERABLE               0x8286
#define GL_DEPTH_RENDERABLE               0x8287
#define GL_STENCIL_RENDERABLE             0x8288
#define GL_FRAMEBUFFER_RENDERABLE         0x8289
#define GL_FRAMEBUFFER_RENDERABLE_LAYERED 0x828A
#define GL_FRAMEBUFFER_BLEND              0x828B
#define GL_READ_PIXELS                    0x828C
#define GL_READ_PIXELS_FORMAT             0x828D
#define GL_READ_PIXELS_TYPE               0x828E
#define GL_TEXTURE_IMAGE_FORMAT           0x828F
#define GL_TEXTURE_IMAGE_TYPE             0x8290
#define GL_GET_TEXTURE_IMAGE_FORMAT       0x8291
#define GL_GET_TEXTURE_IMAGE_TYPE         0x8292
#define GL_MIPMAP                         0x8293
#define GL_MANUAL_GENERATE_MIPMAP         0x8294
#define GL_AUTO_GENERATE_MIPMAP           0x8295
#define GL_COLOR_ENCODING                 0x8296
#define GL_SRGB_READ                      0x8297
#define GL_SRGB_WRITE                     0x8298
#define GL_FILTER                         0x829A
#define GL_VERTEX_TEXTURE                 0x829B
#define GL_TESS_CONTROL_TEXTURE           0x829C
#define GL_TESS_EVALUATION_TEXTURE        0x829D
#define GL_GEOMETRY_TEXTURE               0x829E
#define GL_FRAGMENT_TEXTURE               0x829F
#define GL_COMPUTE_TEXTURE                0x82A0
#define GL_TEXTURE_SHADOW                 0x82A1
#define GL_TEXTURE_GATHER                 0x82A2
#define GL_TEXTURE_GATHER_SHADOW          0x82A3
#define GL_SHADER_IMAGE_LOAD              0x82A4
#define GL_SHADER_IMAGE_STORE             0x82A5
#define GL_SHADER_IMAGE_ATOMIC            0x82A6
#define GL_IMAGE_TEXEL_SIZE               0x82A7
#define GL_IMAGE_COMPATIBILITY_CLASS      0x82A8
#define GL_IMAGE_PIXEL_FORMAT             0x82A9
#define GL_IMAGE_PIXEL_TYPE               0x82AA
#define GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST 0x82AC
#define GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST 0x82AD
#define GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE 0x82AE
#define GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE 0x82AF
#define GL_TEXTURE_COMPRESSED_BLOCK_WIDTH 0x82B1
#define GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT 0x82B2
#define GL_TEXTURE_COMPRESSED_BLOCK_SIZE  0x82B3
#define GL_CLEAR_BUFFER                   0x82B4
#define GL_TEXTURE_VIEW                   0x82B5
#define GL_VIEW_COMPATIBILITY_CLASS       0x82B6
#define GL_FULL_SUPPORT                   0x82B7
#define GL_CAVEAT_SUPPORT                 0x82B8
#define GL_IMAGE_CLASS_4_X_32             0x82B9
#define GL_IMAGE_CLASS_2_X_32             0x82BA
#define GL_IMAGE_CLASS_1_X_32             0x82BB
#define GL_IMAGE_CLASS_4_X_16             0x82BC
#define GL_IMAGE_CLASS_2_X_16             0x82BD
#define GL_IMAGE_CLASS_1_X_16             0x82BE
#define GL_IMAGE_CLASS_4_X_8              0x82BF
#define GL_IMAGE_CLASS_2_X_8              0x82C0
#define GL_IMAGE_CLASS_1_X_8              0x82C1
#define GL_IMAGE_CLASS_11_11_10           0x82C2
#define GL_IMAGE_CLASS_10_10_10_2         0x82C3
#define GL_VIEW_CLASS_128_BITS            0x82C4
#define GL_VIEW_CLASS_96_BITS             0x82C5
#define GL_VIEW_CLASS_64_BITS             0x82C6
#define GL_VIEW_CLASS_48_BITS             0x82C7
#define GL_VIEW_CLASS_32_BITS             0x82C8
#define GL_VIEW_CLASS_24_BITS             0x82C9
#define GL_VIEW_CLASS_16_BITS             0x82CA
#define GL_VIEW_CLASS_8_BITS              0x82CB
#define GL_VIEW_CLASS_S3TC_DXT1_RGB       0x82CC
#define GL_VIEW_CLASS_S3TC_DXT1_RGBA      0x82CD
#define GL_VIEW_CLASS_S3TC_DXT3_RGBA      0x82CE
#define GL_VIEW_CLASS_S3TC_DXT5_RGBA      0x82CF
#define GL_VIEW_CLASS_RGTC1_RED           0x82D0
#define GL_VIEW_CLASS_RGTC2_RG            0x82D1
#define GL_VIEW_CLASS_BPTC_UNORM          0x82D2
#define GL_VIEW_CLASS_BPTC_FLOAT          0x82D3
#define GL_UNIFORM                        0x92E1
#define GL_UNIFORM_BLOCK                  0x92E2
#define GL_PROGRAM_INPUT                  0x92E3
#define GL_PROGRAM_OUTPUT                 0x92E4
#define GL_BUFFER_VARIABLE                0x92E5
#define GL_SHADER_STORAGE_BLOCK           0x92E6
#define GL_VERTEX_SUBROUTINE              0x92E8
#define GL_TESS_CONTROL_SUBROUTINE        0x92E9
#define GL_TESS_EVALUATION_SUBROUTINE     0x92EA
#define GL_GEOMETRY_SUBROUTINE            0x92EB
#define GL_FRAGMENT_SUBROUTINE            0x92EC
#define GL_COMPUTE_SUBROUTINE             0x92ED
#define GL_VERTEX_SUBROUTINE_UNIFORM      0x92EE
#define GL_TESS_CONTROL_SUBROUTINE_UNIFORM 0x92EF
#define GL_TESS_EVALUATION_SUBROUTINE_UNIFORM 0x92F0
#define GL_GEOMETRY_SUBROUTINE_UNIFORM    0x92F1
#define GL_FRAGMENT_SUBROUTINE_UNIFORM    0x92F2
#define GL_COMPUTE_SUBROUTINE_UNIFORM     0x92F3
#define GL_TRANSFORM_FEEDBACK_VARYING     0x92F4
#define GL_ACTIVE_RESOURCES               0x92F5
#define GL_MAX_NAME_LENGTH                0x92F6
#define GL_MAX_NUM_ACTIVE_VARIABLES       0x92F7
#define GL_MAX_NUM_COMPATIBLE_SUBROUTINES 0x92F8
#define GL_NAME_LENGTH                    0x92F9
#define GL_TYPE                           0x92FA
#define GL_ARRAY_SIZE                     0x92FB
#define GL_OFFSET                         0x92FC
#define GL_BLOCK_INDEX                    0x92FD
#define GL_ARRAY_STRIDE                   0x92FE
#define GL_MATRIX_STRIDE                  0x92FF
#define GL_IS_ROW_MAJOR                   0x9300
#define GL_ATOMIC_COUNTER_BUFFER_INDEX    0x9301
#define GL_BUFFER_BINDING                 0x9302
#define GL_BUFFER_DATA_SIZE               0x9303
#define GL_NUM_ACTIVE_VARIABLES           0x9304
#define GL_ACTIVE_VARIABLES               0x9305
#define GL_REFERENCED_BY_VERTEX_SHADER    0x9306
#define GL_REFERENCED_BY_TESS_CONTROL_SHADER 0x9307
#define GL_REFERENCED_BY_TESS_EVALUATION_SHADER 0x9308
#define GL_REFERENCED_BY_GEOMETRY_SHADER  0x9309
#define GL_REFERENCED_BY_FRAGMENT_SHADER  0x930A
#define GL_REFERENCED_BY_COMPUTE_SHADER   0x930B
#define GL_TOP_LEVEL_ARRAY_SIZE           0x930C
#define GL_TOP_LEVEL_ARRAY_STRIDE         0x930D
#define GL_LOCATION                       0x930E
#define GL_LOCATION_INDEX                 0x930F
#define GL_IS_PER_PATCH                   0x92E7
#define GL_SHADER_STORAGE_BUFFER          0x90D2
#define GL_SHADER_STORAGE_BUFFER_BINDING  0x90D3
#define GL_SHADER_STORAGE_BUFFER_START    0x90D4
#define GL_SHADER_STORAGE_BUFFER_SIZE     0x90D5
#define GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS 0x90D6
#define GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS 0x90D7
#define GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS 0x90D8
#define GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS 0x90D9
#define GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS 0x90DA
#define GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS 0x90DB
#define GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS 0x90DC
#define GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS 0x90DD
#define GL_MAX_SHADER_STORAGE_BLOCK_SIZE  0x90DE
#define GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT 0x90DF
#define GL_SHADER_STORAGE_BARRIER_BIT     0x00002000
#define GL_MAX_COMBINED_SHADER_OUTPUT_RESOURCES 0x8F39
#define GL_DEPTH_STENCIL_TEXTURE_MODE     0x90EA
#define GL_TEXTURE_BUFFER_OFFSET          0x919D
#define GL_TEXTURE_BUFFER_SIZE            0x919E
#define GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT 0x919F
#define GL_TEXTURE_VIEW_MIN_LEVEL         0x82DB
#define GL_TEXTURE_VIEW_NUM_LEVELS        0x82DC
#define GL_TEXTURE_VIEW_MIN_LAYER         0x82DD
#define GL_TEXTURE_VIEW_NUM_LAYERS        0x82DE
#define GL_TEXTURE_IMMUTABLE_LEVELS       0x82DF
#define GL_VERTEX_ATTRIB_BINDING          0x82D4
#define GL_VERTEX_ATTRIB_RELATIVE_OFFSET  0x82D5
#define GL_VERTEX_BINDING_DIVISOR         0x82D6
#define GL_VERTEX_BINDING_OFFSET          0x82D7
#define GL_VERTEX_BINDING_STRIDE          0x82D8
#define GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET 0x82D9
#define GL_MAX_VERTEX_ATTRIB_BINDINGS     0x82DA
#define GL_VERTEX_BINDING_BUFFER          0x8F4F
typedef void (APIENTRYP PFNGLCLEARBUFFERDATAPROC) (GLenum target, GLenum internalformat, GLenum format, GLenum type, const void *data);
typedef void (APIENTRYP PFNGLCLEARBUFFERSUBDATAPROC) (GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
typedef void (APIENTRYP PFNGLDISPATCHCOMPUTEPROC) (GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
typedef void (APIENTRYP PFNGLDISPATCHCOMPUTEINDIRECTPROC) (GLintptr indirect);
typedef void (APIENTRYP PFNGLCOPYIMAGESUBDATAPROC) (GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
typedef void (APIENTRYP PFNGLFRAMEBUFFERPARAMETERIPROC) (GLenum target, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLGETFRAMEBUFFERPARAMETERIVPROC) (GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETINTERNALFORMATI64VPROC) (GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint64 *params);
typedef void (APIENTRYP PFNGLINVALIDATETEXSUBIMAGEPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth);
typedef void (APIENTRYP PFNGLINVALIDATETEXIMAGEPROC) (GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLINVALIDATEBUFFERSUBDATAPROC) (GLuint buffer, GLintptr offset, GLsizeiptr length);
typedef void (APIENTRYP PFNGLINVALIDATEBUFFERDATAPROC) (GLuint buffer);
typedef void (APIENTRYP PFNGLINVALIDATEFRAMEBUFFERPROC) (GLenum target, GLsizei numAttachments, const GLenum *attachments);
typedef void (APIENTRYP PFNGLINVALIDATESUBFRAMEBUFFERPROC) (GLenum target, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTPROC) (GLenum mode, const void *indirect, GLsizei drawcount, GLsizei stride);
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTPROC) (GLenum mode, GLenum type, const void *indirect, GLsizei drawcount, GLsizei stride);
typedef void (APIENTRYP PFNGLGETPROGRAMINTERFACEIVPROC) (GLuint program, GLenum programInterface, GLenum pname, GLint *params);
typedef GLuint (APIENTRYP PFNGLGETPROGRAMRESOURCEINDEXPROC) (GLuint program, GLenum programInterface, const GLchar *name);
typedef void (APIENTRYP PFNGLGETPROGRAMRESOURCENAMEPROC) (GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name);
typedef void (APIENTRYP PFNGLGETPROGRAMRESOURCEIVPROC) (GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei count, GLsizei *length, GLint *params);
typedef GLint (APIENTRYP PFNGLGETPROGRAMRESOURCELOCATIONPROC) (GLuint program, GLenum programInterface, const GLchar *name);
typedef GLint (APIENTRYP PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC) (GLuint program, GLenum programInterface, const GLchar *name);
typedef void (APIENTRYP PFNGLSHADERSTORAGEBLOCKBINDINGPROC) (GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);
typedef void (APIENTRYP PFNGLTEXBUFFERRANGEPROC) (GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLTEXSTORAGE2DMULTISAMPLEPROC) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFNGLTEXSTORAGE3DMULTISAMPLEPROC) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFNGLTEXTUREVIEWPROC) (GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
typedef void (APIENTRYP PFNGLBINDVERTEXBUFFERPROC) (GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
typedef void (APIENTRYP PFNGLVERTEXATTRIBFORMATPROC) (GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLVERTEXATTRIBIFORMATPROC) (GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLVERTEXATTRIBLFORMATPROC) (GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLVERTEXATTRIBBINDINGPROC) (GLuint attribindex, GLuint bindingindex);
typedef void (APIENTRYP PFNGLVERTEXBINDINGDIVISORPROC) (GLuint bindingindex, GLuint divisor);
typedef void (APIENTRYP PFNGLDEBUGMESSAGECONTROLPROC) (GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
typedef void (APIENTRYP PFNGLDEBUGMESSAGEINSERTPROC) (GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf);
typedef void (APIENTRYP PFNGLDEBUGMESSAGECALLBACKPROC) (GLDEBUGPROC callback, const void *userParam);
typedef GLuint (APIENTRYP PFNGLGETDEBUGMESSAGELOGPROC) (GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog);
typedef void (APIENTRYP PFNGLPUSHDEBUGGROUPPROC) (GLenum source, GLuint id, GLsizei length, const GLchar *message);
typedef void (APIENTRYP PFNGLPOPDEBUGGROUPPROC) (void);
typedef void (APIENTRYP PFNGLOBJECTLABELPROC) (GLenum identifier, GLuint name, GLsizei length, const GLchar *label);
typedef void (APIENTRYP PFNGLGETOBJECTLABELPROC) (GLenum identifier, GLuint name, GLsizei bufSize, GLsizei *length, GLchar *label);
typedef void (APIENTRYP PFNGLOBJECTPTRLABELPROC) (const void *ptr, GLsizei length, const GLchar *label);
typedef void (APIENTRYP PFNGLGETOBJECTPTRLABELPROC) (const void *ptr, GLsizei bufSize, GLsizei *length, GLchar *label);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glClearBufferData (GLenum target, GLenum internalformat, GLenum format, GLenum type, const void *data);
GLAPI void APIENTRY glClearBufferSubData (GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
GLAPI void APIENTRY glDispatchCompute (GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
GLAPI void APIENTRY glDispatchComputeIndirect (GLintptr indirect);
GLAPI void APIENTRY glCopyImageSubData (GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
GLAPI void APIENTRY glFramebufferParameteri (GLenum target, GLenum pname, GLint param);
GLAPI void APIENTRY glGetFramebufferParameteriv (GLenum target, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetInternalformati64v (GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint64 *params);
GLAPI void APIENTRY glInvalidateTexSubImage (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth);
GLAPI void APIENTRY glInvalidateTexImage (GLuint texture, GLint level);
GLAPI void APIENTRY glInvalidateBufferSubData (GLuint buffer, GLintptr offset, GLsizeiptr length);
GLAPI void APIENTRY glInvalidateBufferData (GLuint buffer);
GLAPI void APIENTRY glInvalidateFramebuffer (GLenum target, GLsizei numAttachments, const GLenum *attachments);
GLAPI void APIENTRY glInvalidateSubFramebuffer (GLenum target, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI void APIENTRY glMultiDrawArraysIndirect (GLenum mode, const void *indirect, GLsizei drawcount, GLsizei stride);
GLAPI void APIENTRY glMultiDrawElementsIndirect (GLenum mode, GLenum type, const void *indirect, GLsizei drawcount, GLsizei stride);
GLAPI void APIENTRY glGetProgramInterfaceiv (GLuint program, GLenum programInterface, GLenum pname, GLint *params);
GLAPI GLuint APIENTRY glGetProgramResourceIndex (GLuint program, GLenum programInterface, const GLchar *name);
GLAPI void APIENTRY glGetProgramResourceName (GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name);
GLAPI void APIENTRY glGetProgramResourceiv (GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei count, GLsizei *length, GLint *params);
GLAPI GLint APIENTRY glGetProgramResourceLocation (GLuint program, GLenum programInterface, const GLchar *name);
GLAPI GLint APIENTRY glGetProgramResourceLocationIndex (GLuint program, GLenum programInterface, const GLchar *name);
GLAPI void APIENTRY glShaderStorageBlockBinding (GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);
GLAPI void APIENTRY glTexBufferRange (GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
GLAPI void APIENTRY glTexStorage2DMultisample (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
GLAPI void APIENTRY glTexStorage3DMultisample (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
GLAPI void APIENTRY glTextureView (GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
GLAPI void APIENTRY glBindVertexBuffer (GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
GLAPI void APIENTRY glVertexAttribFormat (GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
GLAPI void APIENTRY glVertexAttribIFormat (GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
GLAPI void APIENTRY glVertexAttribLFormat (GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
GLAPI void APIENTRY glVertexAttribBinding (GLuint attribindex, GLuint bindingindex);
GLAPI void APIENTRY glVertexBindingDivisor (GLuint bindingindex, GLuint divisor);
GLAPI void APIENTRY glDebugMessageControl (GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
GLAPI void APIENTRY glDebugMessageInsert (GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf);
GLAPI void APIENTRY glDebugMessageCallback (GLDEBUGPROC callback, const void *userParam);
GLAPI GLuint APIENTRY glGetDebugMessageLog (GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog);
GLAPI void APIENTRY glPushDebugGroup (GLenum source, GLuint id, GLsizei length, const GLchar *message);
GLAPI void APIENTRY glPopDebugGroup (void);
GLAPI void APIENTRY glObjectLabel (GLenum identifier, GLuint name, GLsizei length, const GLchar *label);
GLAPI void APIENTRY glGetObjectLabel (GLenum identifier, GLuint name, GLsizei bufSize, GLsizei *length, GLchar *label);
GLAPI void APIENTRY glObjectPtrLabel (const void *ptr, GLsizei length, const GLchar *label);
GLAPI void APIENTRY glGetObjectPtrLabel (const void *ptr, GLsizei bufSize, GLsizei *length, GLchar *label);
#endif
#endif /* GL_VERSION_4_3 */
#ifndef GL_VERSION_4_4
#define GL_VERSION_4_4 1
#define GL_MAX_VERTEX_ATTRIB_STRIDE       0x82E5
#define GL_PRIMITIVE_RESTART_FOR_PATCHES_SUPPORTED 0x8221
#define GL_TEXTURE_BUFFER_BINDING         0x8C2A
#define GL_MAP_PERSISTENT_BIT             0x0040
#define GL_MAP_COHERENT_BIT               0x0080
#define GL_DYNAMIC_STORAGE_BIT            0x0100
#define GL_CLIENT_STORAGE_BIT             0x0200
#define GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT 0x00004000
#define GL_BUFFER_IMMUTABLE_STORAGE       0x821F
#define GL_BUFFER_STORAGE_FLAGS           0x8220
#define GL_CLEAR_TEXTURE                  0x9365
#define GL_LOCATION_COMPONENT             0x934A
#define GL_TRANSFORM_FEEDBACK_BUFFER_INDEX 0x934B
#define GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE 0x934C
#define GL_QUERY_BUFFER                   0x9192
#define GL_QUERY_BUFFER_BARRIER_BIT       0x00008000
#define GL_QUERY_BUFFER_BINDING           0x9193
#define GL_QUERY_RESULT_NO_WAIT           0x9194
#define GL_MIRROR_CLAMP_TO_EDGE           0x8743
typedef void (APIENTRYP PFNGLBUFFERSTORAGEPROC) (GLenum target, GLsizeiptr size, const void *data, GLbitfield flags);
typedef void (APIENTRYP PFNGLCLEARTEXIMAGEPROC) (GLuint texture, GLint level, GLenum format, GLenum type, const void *data);
typedef void (APIENTRYP PFNGLCLEARTEXSUBIMAGEPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *data);
typedef void (APIENTRYP PFNGLBINDBUFFERSBASEPROC) (GLenum target, GLuint first, GLsizei count, const GLuint *buffers);
typedef void (APIENTRYP PFNGLBINDBUFFERSRANGEPROC) (GLenum target, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizeiptr *sizes);
typedef void (APIENTRYP PFNGLBINDTEXTURESPROC) (GLuint first, GLsizei count, const GLuint *textures);
typedef void (APIENTRYP PFNGLBINDSAMPLERSPROC) (GLuint first, GLsizei count, const GLuint *samplers);
typedef void (APIENTRYP PFNGLBINDIMAGETEXTURESPROC) (GLuint first, GLsizei count, const GLuint *textures);
typedef void (APIENTRYP PFNGLBINDVERTEXBUFFERSPROC) (GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glBufferStorage (GLenum target, GLsizeiptr size, const void *data, GLbitfield flags);
GLAPI void APIENTRY glClearTexImage (GLuint texture, GLint level, GLenum format, GLenum type, const void *data);
GLAPI void APIENTRY glClearTexSubImage (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *data);
GLAPI void APIENTRY glBindBuffersBase (GLenum target, GLuint first, GLsizei count, const GLuint *buffers);
GLAPI void APIENTRY glBindBuffersRange (GLenum target, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizeiptr *sizes);
GLAPI void APIENTRY glBindTextures (GLuint first, GLsizei count, const GLuint *textures);
GLAPI void APIENTRY glBindSamplers (GLuint first, GLsizei count, const GLuint *samplers);
GLAPI void APIENTRY glBindImageTextures (GLuint first, GLsizei count, const GLuint *textures);
GLAPI void APIENTRY glBindVertexBuffers (GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);
#endif
#endif /* GL_VERSION_4_4 */
#ifndef GL_VERSION_4_5
#define GL_VERSION_4_5 1
#define GL_CONTEXT_LOST                   0x0507
#define GL_NEGATIVE_ONE_TO_ONE            0x935E
#define GL_ZERO_TO_ONE                    0x935F
#define GL_CLIP_ORIGIN                    0x935C
#define GL_CLIP_DEPTH_MODE                0x935D
#define GL_QUERY_WAIT_INVERTED            0x8E17
#define GL_QUERY_NO_WAIT_INVERTED         0x8E18
#define GL_QUERY_BY_REGION_WAIT_INVERTED  0x8E19
#define GL_QUERY_BY_REGION_NO_WAIT_INVERTED 0x8E1A
#define GL_MAX_CULL_DISTANCES             0x82F9
#define GL_MAX_COMBINED_CLIP_AND_CULL_DISTANCES 0x82FA
#define GL_TEXTURE_TARGET                 0x1006
#define GL_QUERY_TARGET                   0x82EA
#define GL_GUILTY_CONTEXT_RESET           0x8253
#define GL_INNOCENT_CONTEXT_RESET         0x8254
#define GL_UNKNOWN_CONTEXT_RESET          0x8255
#define GL_RESET_NOTIFICATION_STRATEGY    0x8256
#define GL_LOSE_CONTEXT_ON_RESET          0x8252
#define GL_NO_RESET_NOTIFICATION          0x8261
#define GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT 0x00000004
#define GL_CONTEXT_RELEASE_BEHAVIOR       0x82FB
#define GL_CONTEXT_RELEASE_BEHAVIOR_FLUSH 0x82FC
typedef void (APIENTRYP PFNGLCLIPCONTROLPROC) (GLenum origin, GLenum depth);
typedef void (APIENTRYP PFNGLCREATETRANSFORMFEEDBACKSPROC) (GLsizei n, GLuint *ids);
typedef void (APIENTRYP PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC) (GLuint xfb, GLuint index, GLuint buffer);
typedef void (APIENTRYP PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC) (GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKIVPROC) (GLuint xfb, GLenum pname, GLint *param);
typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKI_VPROC) (GLuint xfb, GLenum pname, GLuint index, GLint *param);
typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKI64_VPROC) (GLuint xfb, GLenum pname, GLuint index, GLint64 *param);
typedef void (APIENTRYP PFNGLCREATEBUFFERSPROC) (GLsizei n, GLuint *buffers);
typedef void (APIENTRYP PFNGLNAMEDBUFFERSTORAGEPROC) (GLuint buffer, GLsizeiptr size, const void *data, GLbitfield flags);
typedef void (APIENTRYP PFNGLNAMEDBUFFERDATAPROC) (GLuint buffer, GLsizeiptr size, const void *data, GLenum usage);
typedef void (APIENTRYP PFNGLNAMEDBUFFERSUBDATAPROC) (GLuint buffer, GLintptr offset, GLsizeiptr size, const void *data);
typedef void (APIENTRYP PFNGLCOPYNAMEDBUFFERSUBDATAPROC) (GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLCLEARNAMEDBUFFERDATAPROC) (GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void *data);
typedef void (APIENTRYP PFNGLCLEARNAMEDBUFFERSUBDATAPROC) (GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
typedef void *(APIENTRYP PFNGLMAPNAMEDBUFFERPROC) (GLuint buffer, GLenum access);
typedef void *(APIENTRYP PFNGLMAPNAMEDBUFFERRANGEPROC) (GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
typedef GLboolean (APIENTRYP PFNGLUNMAPNAMEDBUFFERPROC) (GLuint buffer);
typedef void (APIENTRYP PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC) (GLuint buffer, GLintptr offset, GLsizeiptr length);
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPARAMETERIVPROC) (GLuint buffer, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPARAMETERI64VPROC) (GLuint buffer, GLenum pname, GLint64 *params);
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPOINTERVPROC) (GLuint buffer, GLenum pname, void **params);
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERSUBDATAPROC) (GLuint buffer, GLintptr offset, GLsizeiptr size, void *data);
typedef void (APIENTRYP PFNGLCREATEFRAMEBUFFERSPROC) (GLsizei n, GLuint *framebuffers);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC) (GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC) (GLuint framebuffer, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTUREPROC) (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC) (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC) (GLuint framebuffer, GLenum buf);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC) (GLuint framebuffer, GLsizei n, const GLenum *bufs);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC) (GLuint framebuffer, GLenum src);
typedef void (APIENTRYP PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC) (GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments);
typedef void (APIENTRYP PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC) (GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERIVPROC) (GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint *value);
typedef void (APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC) (GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint *value);
typedef void (APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERFVPROC) (GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat *value);
typedef void (APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERFIPROC) (GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
typedef void (APIENTRYP PFNGLBLITNAMEDFRAMEBUFFERPROC) (GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
typedef GLenum (APIENTRYP PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC) (GLuint framebuffer, GLenum target);
typedef void (APIENTRYP PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC) (GLuint framebuffer, GLenum pname, GLint *param);
typedef void (APIENTRYP PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC) (GLuint framebuffer, GLenum attachment, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLCREATERENDERBUFFERSPROC) (GLsizei n, GLuint *renderbuffers);
typedef void (APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEPROC) (GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC) (GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC) (GLuint renderbuffer, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLCREATETEXTURESPROC) (GLenum target, GLsizei n, GLuint *textures);
typedef void (APIENTRYP PFNGLTEXTUREBUFFERPROC) (GLuint texture, GLenum internalformat, GLuint buffer);
typedef void (APIENTRYP PFNGLTEXTUREBUFFERRANGEPROC) (GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE1DPROC) (GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE2DPROC) (GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE3DPROC) (GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC) (GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC) (GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE1DPROC) (GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE2DPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE3DPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC) (GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE1DPROC) (GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE2DPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE3DPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERFPROC) (GLuint texture, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERFVPROC) (GLuint texture, GLenum pname, const GLfloat *param);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIPROC) (GLuint texture, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIIVPROC) (GLuint texture, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIUIVPROC) (GLuint texture, GLenum pname, const GLuint *params);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIVPROC) (GLuint texture, GLenum pname, const GLint *param);
typedef void (APIENTRYP PFNGLGENERATETEXTUREMIPMAPPROC) (GLuint texture);
typedef void (APIENTRYP PFNGLBINDTEXTUREUNITPROC) (GLuint unit, GLuint texture);
typedef void (APIENTRYP PFNGLGETTEXTUREIMAGEPROC) (GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
typedef void (APIENTRYP PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC) (GLuint texture, GLint level, GLsizei bufSize, void *pixels);
typedef void (APIENTRYP PFNGLGETTEXTURELEVELPARAMETERFVPROC) (GLuint texture, GLint level, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETTEXTURELEVELPARAMETERIVPROC) (GLuint texture, GLint level, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERFVPROC) (GLuint texture, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIIVPROC) (GLuint texture, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIUIVPROC) (GLuint texture, GLenum pname, GLuint *params);
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIVPROC) (GLuint texture, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLCREATEVERTEXARRAYSPROC) (GLsizei n, GLuint *arrays);
typedef void (APIENTRYP PFNGLDISABLEVERTEXARRAYATTRIBPROC) (GLuint vaobj, GLuint index);
typedef void (APIENTRYP PFNGLENABLEVERTEXARRAYATTRIBPROC) (GLuint vaobj, GLuint index);
typedef void (APIENTRYP PFNGLVERTEXARRAYELEMENTBUFFERPROC) (GLuint vaobj, GLuint buffer);
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXBUFFERPROC) (GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXBUFFERSPROC) (GLuint vaobj, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);
typedef void (APIENTRYP PFNGLVERTEXARRAYATTRIBBINDINGPROC) (GLuint vaobj, GLuint attribindex, GLuint bindingindex);
typedef void (APIENTRYP PFNGLVERTEXARRAYATTRIBFORMATPROC) (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLVERTEXARRAYATTRIBIFORMATPROC) (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLVERTEXARRAYATTRIBLFORMATPROC) (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLVERTEXARRAYBINDINGDIVISORPROC) (GLuint vaobj, GLuint bindingindex, GLuint divisor);
typedef void (APIENTRYP PFNGLGETVERTEXARRAYIVPROC) (GLuint vaobj, GLenum pname, GLint *param);
typedef void (APIENTRYP PFNGLGETVERTEXARRAYINDEXEDIVPROC) (GLuint vaobj, GLuint index, GLenum pname, GLint *param);
typedef void (APIENTRYP PFNGLGETVERTEXARRAYINDEXED64IVPROC) (GLuint vaobj, GLuint index, GLenum pname, GLint64 *param);
typedef void (APIENTRYP PFNGLCREATESAMPLERSPROC) (GLsizei n, GLuint *samplers);
typedef void (APIENTRYP PFNGLCREATEPROGRAMPIPELINESPROC) (GLsizei n, GLuint *pipelines);
typedef void (APIENTRYP PFNGLCREATEQUERIESPROC) (GLenum target, GLsizei n, GLuint *ids);
typedef void (APIENTRYP PFNGLGETQUERYBUFFEROBJECTI64VPROC) (GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
typedef void (APIENTRYP PFNGLGETQUERYBUFFEROBJECTIVPROC) (GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
typedef void (APIENTRYP PFNGLGETQUERYBUFFEROBJECTUI64VPROC) (GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
typedef void (APIENTRYP PFNGLGETQUERYBUFFEROBJECTUIVPROC) (GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
typedef void (APIENTRYP PFNGLMEMORYBARRIERBYREGIONPROC) (GLbitfield barriers);
typedef void (APIENTRYP PFNGLGETTEXTURESUBIMAGEPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
typedef void (APIENTRYP PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void *pixels);
typedef GLenum (APIENTRYP PFNGLGETGRAPHICSRESETSTATUSPROC) (void);
typedef void (APIENTRYP PFNGLGETNCOMPRESSEDTEXIMAGEPROC) (GLenum target, GLint lod, GLsizei bufSize, void *pixels);
typedef void (APIENTRYP PFNGLGETNTEXIMAGEPROC) (GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
typedef void (APIENTRYP PFNGLGETNUNIFORMDVPROC) (GLuint program, GLint location, GLsizei bufSize, GLdouble *params);
typedef void (APIENTRYP PFNGLGETNUNIFORMFVPROC) (GLuint program, GLint location, GLsizei bufSize, GLfloat *params);
typedef void (APIENTRYP PFNGLGETNUNIFORMIVPROC) (GLuint program, GLint location, GLsizei bufSize, GLint *params);
typedef void (APIENTRYP PFNGLGETNUNIFORMUIVPROC) (GLuint program, GLint location, GLsizei bufSize, GLuint *params);
typedef void (APIENTRYP PFNGLREADNPIXELSPROC) (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data);
typedef void (APIENTRYP PFNGLTEXTUREBARRIERPROC) (void);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glClipControl (GLenum origin, GLenum depth);
GLAPI void APIENTRY glCreateTransformFeedbacks (GLsizei n, GLuint *ids);
GLAPI void APIENTRY glTransformFeedbackBufferBase (GLuint xfb, GLuint index, GLuint buffer);
GLAPI void APIENTRY glTransformFeedbackBufferRange (GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
GLAPI void APIENTRY glGetTransformFeedbackiv (GLuint xfb, GLenum pname, GLint *param);
GLAPI void APIENTRY glGetTransformFeedbacki_v (GLuint xfb, GLenum pname, GLuint index, GLint *param);
GLAPI void APIENTRY glGetTransformFeedbacki64_v (GLuint xfb, GLenum pname, GLuint index, GLint64 *param);
GLAPI void APIENTRY glCreateBuffers (GLsizei n, GLuint *buffers);
GLAPI void APIENTRY glNamedBufferStorage (GLuint buffer, GLsizeiptr size, const void *data, GLbitfield flags);
GLAPI void APIENTRY glNamedBufferData (GLuint buffer, GLsizeiptr size, const void *data, GLenum usage);
GLAPI void APIENTRY glNamedBufferSubData (GLuint buffer, GLintptr offset, GLsizeiptr size, const void *data);
GLAPI void APIENTRY glCopyNamedBufferSubData (GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
GLAPI void APIENTRY glClearNamedBufferData (GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void *data);
GLAPI void APIENTRY glClearNamedBufferSubData (GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
GLAPI void *APIENTRY glMapNamedBuffer (GLuint buffer, GLenum access);
GLAPI void *APIENTRY glMapNamedBufferRange (GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
GLAPI GLboolean APIENTRY glUnmapNamedBuffer (GLuint buffer);
GLAPI void APIENTRY glFlushMappedNamedBufferRange (GLuint buffer, GLintptr offset, GLsizeiptr length);
GLAPI void APIENTRY glGetNamedBufferParameteriv (GLuint buffer, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetNamedBufferParameteri64v (GLuint buffer, GLenum pname, GLint64 *params);
GLAPI void APIENTRY glGetNamedBufferPointerv (GLuint buffer, GLenum pname, void **params);
GLAPI void APIENTRY glGetNamedBufferSubData (GLuint buffer, GLintptr offset, GLsizeiptr size, void *data);
GLAPI void APIENTRY glCreateFramebuffers (GLsizei n, GLuint *framebuffers);
GLAPI void APIENTRY glNamedFramebufferRenderbuffer (GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
GLAPI void APIENTRY glNamedFramebufferParameteri (GLuint framebuffer, GLenum pname, GLint param);
GLAPI void APIENTRY glNamedFramebufferTexture (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
GLAPI void APIENTRY glNamedFramebufferTextureLayer (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
GLAPI void APIENTRY glNamedFramebufferDrawBuffer (GLuint framebuffer, GLenum buf);
GLAPI void APIENTRY glNamedFramebufferDrawBuffers (GLuint framebuffer, GLsizei n, const GLenum *bufs);
GLAPI void APIENTRY glNamedFramebufferReadBuffer (GLuint framebuffer, GLenum src);
GLAPI void APIENTRY glInvalidateNamedFramebufferData (GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments);
GLAPI void APIENTRY glInvalidateNamedFramebufferSubData (GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI void APIENTRY glClearNamedFramebufferiv (GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint *value);
GLAPI void APIENTRY glClearNamedFramebufferuiv (GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint *value);
GLAPI void APIENTRY glClearNamedFramebufferfv (GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat *value);
GLAPI void APIENTRY glClearNamedFramebufferfi (GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
GLAPI void APIENTRY glBlitNamedFramebuffer (GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
GLAPI GLenum APIENTRY glCheckNamedFramebufferStatus (GLuint framebuffer, GLenum target);
GLAPI void APIENTRY glGetNamedFramebufferParameteriv (GLuint framebuffer, GLenum pname, GLint *param);
GLAPI void APIENTRY glGetNamedFramebufferAttachmentParameteriv (GLuint framebuffer, GLenum attachment, GLenum pname, GLint *params);
GLAPI void APIENTRY glCreateRenderbuffers (GLsizei n, GLuint *renderbuffers);
GLAPI void APIENTRY glNamedRenderbufferStorage (GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI void APIENTRY glNamedRenderbufferStorageMultisample (GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI void APIENTRY glGetNamedRenderbufferParameteriv (GLuint renderbuffer, GLenum pname, GLint *params);
GLAPI void APIENTRY glCreateTextures (GLenum target, GLsizei n, GLuint *textures);
GLAPI void APIENTRY glTextureBuffer (GLuint texture, GLenum internalformat, GLuint buffer);
GLAPI void APIENTRY glTextureBufferRange (GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
GLAPI void APIENTRY glTextureStorage1D (GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width);
GLAPI void APIENTRY glTextureStorage2D (GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI void APIENTRY glTextureStorage3D (GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
GLAPI void APIENTRY glTextureStorage2DMultisample (GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
GLAPI void APIENTRY glTextureStorage3DMultisample (GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
GLAPI void APIENTRY glTextureSubImage1D (GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
GLAPI void APIENTRY glTextureSubImage2D (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
GLAPI void APIENTRY glTextureSubImage3D (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
GLAPI void APIENTRY glCompressedTextureSubImage1D (GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
GLAPI void APIENTRY glCompressedTextureSubImage2D (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
GLAPI void APIENTRY glCompressedTextureSubImage3D (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
GLAPI void APIENTRY glCopyTextureSubImage1D (GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
GLAPI void APIENTRY glCopyTextureSubImage2D (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI void APIENTRY glCopyTextureSubImage3D (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI void APIENTRY glTextureParameterf (GLuint texture, GLenum pname, GLfloat param);
GLAPI void APIENTRY glTextureParameterfv (GLuint texture, GLenum pname, const GLfloat *param);
GLAPI void APIENTRY glTextureParameteri (GLuint texture, GLenum pname, GLint param);
GLAPI void APIENTRY glTextureParameterIiv (GLuint texture, GLenum pname, const GLint *params);
GLAPI void APIENTRY glTextureParameterIuiv (GLuint texture, GLenum pname, const GLuint *params);
GLAPI void APIENTRY glTextureParameteriv (GLuint texture, GLenum pname, const GLint *param);
GLAPI void APIENTRY glGenerateTextureMipmap (GLuint texture);
GLAPI void APIENTRY glBindTextureUnit (GLuint unit, GLuint texture);
GLAPI void APIENTRY glGetTextureImage (GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
GLAPI void APIENTRY glGetCompressedTextureImage (GLuint texture, GLint level, GLsizei bufSize, void *pixels);
GLAPI void APIENTRY glGetTextureLevelParameterfv (GLuint texture, GLint level, GLenum pname, GLfloat *params);
GLAPI void APIENTRY glGetTextureLevelParameteriv (GLuint texture, GLint level, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetTextureParameterfv (GLuint texture, GLenum pname, GLfloat *params);
GLAPI void APIENTRY glGetTextureParameterIiv (GLuint texture, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetTextureParameterIuiv (GLuint texture, GLenum pname, GLuint *params);
GLAPI void APIENTRY glGetTextureParameteriv (GLuint texture, GLenum pname, GLint *params);
GLAPI void APIENTRY glCreateVertexArrays (GLsizei n, GLuint *arrays);
GLAPI void APIENTRY glDisableVertexArrayAttrib (GLuint vaobj, GLuint index);
GLAPI void APIENTRY glEnableVertexArrayAttrib (GLuint vaobj, GLuint index);
GLAPI void APIENTRY glVertexArrayElementBuffer (GLuint vaobj, GLuint buffer);
GLAPI void APIENTRY glVertexArrayVertexBuffer (GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
GLAPI void APIENTRY glVertexArrayVertexBuffers (GLuint vaobj, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);
GLAPI void APIENTRY glVertexArrayAttribBinding (GLuint vaobj, GLuint attribindex, GLuint bindingindex);
GLAPI void APIENTRY glVertexArrayAttribFormat (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
GLAPI void APIENTRY glVertexArrayAttribIFormat (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
GLAPI void APIENTRY glVertexArrayAttribLFormat (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
GLAPI void APIENTRY glVertexArrayBindingDivisor (GLuint vaobj, GLuint bindingindex, GLuint divisor);
GLAPI void APIENTRY glGetVertexArrayiv (GLuint vaobj, GLenum pname, GLint *param);
GLAPI void APIENTRY glGetVertexArrayIndexediv (GLuint vaobj, GLuint index, GLenum pname, GLint *param);
GLAPI void APIENTRY glGetVertexArrayIndexed64iv (GLuint vaobj, GLuint index, GLenum pname, GLint64 *param);
GLAPI void APIENTRY glCreateSamplers (GLsizei n, GLuint *samplers);
GLAPI void APIENTRY glCreateProgramPipelines (GLsizei n, GLuint *pipelines);
GLAPI void APIENTRY glCreateQueries (GLenum target, GLsizei n, GLuint *ids);
GLAPI void APIENTRY glGetQueryBufferObjecti64v (GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
GLAPI void APIENTRY glGetQueryBufferObjectiv (GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
GLAPI void APIENTRY glGetQueryBufferObjectui64v (GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
GLAPI void APIENTRY glGetQueryBufferObjectuiv (GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
GLAPI void APIENTRY glMemoryBarrierByRegion (GLbitfield barriers);
GLAPI void APIENTRY glGetTextureSubImage (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
GLAPI void APIENTRY glGetCompressedTextureSubImage (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void *pixels);
GLAPI GLenum APIENTRY glGetGraphicsResetStatus (void);
GLAPI void APIENTRY glGetnCompressedTexImage (GLenum target, GLint lod, GLsizei bufSize, void *pixels);
GLAPI void APIENTRY glGetnTexImage (GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
GLAPI void APIENTRY glGetnUniformdv (GLuint program, GLint location, GLsizei bufSize, GLdouble *params);
GLAPI void APIENTRY glGetnUniformfv (GLuint program, GLint location, GLsizei bufSize, GLfloat *params);
GLAPI void APIENTRY glGetnUniformiv (GLuint program, GLint location, GLsizei bufSize, GLint *params);
GLAPI void APIENTRY glGetnUniformuiv (GLuint program, GLint location, GLsizei bufSize, GLuint *params);
GLAPI void APIENTRY glReadnPixels (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data);
GLAPI void APIENTRY glTextureBarrier (void);
#endif
#endif /* GL_VERSION_4_5 */
#ifndef GL_VERSION_4_6
#define GL_VERSION_4_6 1
#define GL_SHADER_BINARY_FORMAT_SPIR_V    0x9551
#define GL_SPIR_V_BINARY                  0x9552
#define GL_PARAMETER_BUFFER               0x80EE
#define GL_PARAMETER_BUFFER_BINDING       0x80EF
#define GL_CONTEXT_FLAG_NO_ERROR_BIT      0x00000008
#define GL_VERTICES_SUBMITTED             0x82EE
#define GL_PRIMITIVES_SUBMITTED           0x82EF
#define GL_VERTEX_SHADER_INVOCATIONS      0x82F0
#define GL_TESS_CONTROL_SHADER_PATCHES    0x82F1
#define GL_TESS_EVALUATION_SHADER_INVOCATIONS 0x82F2
#define GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED 0x82F3
#define GL_FRAGMENT_SHADER_INVOCATIONS    0x82F4
#define GL_COMPUTE_SHADER_INVOCATIONS     0x82F5
#define GL_CLIPPING_INPUT_PRIMITIVES      0x82F6
#define GL_CLIPPING_OUTPUT_PRIMITIVES     0x82F7
#define GL_POLYGON_OFFSET_CLAMP           0x8E1B
#define GL_SPIR_V_EXTENSIONS              0x9553
#define GL_NUM_SPIR_V_EXTENSIONS          0x9554
#define GL_TEXTURE_MAX_ANISOTROPY         0x84FE
#define GL_MAX_TEXTURE_MAX_ANISOTROPY     0x84FF
#define GL_TRANSFORM_FEEDBACK_OVERFLOW    0x82EC
#define GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW 0x82ED
typedef void (APIENTRYP PFNGLSPECIALIZESHADERPROC) (GLuint shader, const GLchar *pEntryPoint, GLuint numSpecializationConstants, const GLuint *pConstantIndex, const GLuint *pConstantValue);
typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC) (GLenum mode, const void *indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC) (GLenum mode, GLenum type, const void *indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
typedef void (APIENTRYP PFNGLPOLYGONOFFSETCLAMPPROC) (GLfloat factor, GLfloat units, GLfloat clamp);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glSpecializeShader (GLuint shader, const GLchar *pEntryPoint, GLuint numSpecializationConstants, const GLuint *pConstantIndex, const GLuint *pConstantValue);
GLAPI void APIENTRY glMultiDrawArraysIndirectCount (GLenum mode, const void *indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
GLAPI void APIENTRY glMultiDrawElementsIndirectCount (GLenum mode, GLenum type, const void *indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
GLAPI void APIENTRY glPolygonOffsetClamp (GLfloat factor, GLfloat units, GLfloat clamp);
#endif
#endif /* GL_VERSION_4_6 */
#ifndef GL_ARB_ES2_compatibility
#define GL_ARB_ES2_compatibility 1
#endif /* GL_ARB_ES2_compatibility */
#ifndef GL_ARB_ES3_1_compatibility
#define GL_ARB_ES3_1_compatibility 1
#endif /* GL_ARB_ES3_1_compatibility */
#ifndef GL_ARB_ES3_2_compatibility
#define GL_ARB_ES3_2_compatibility 1
#define GL_PRIMITIVE_BOUNDING_BOX_ARB     0x92BE
#define GL_MULTISAMPLE_LINE_WIDTH_RANGE_ARB 0x9381
#define GL_MULTISAMPLE_LINE_WIDTH_GRANULARITY_ARB 0x9382
typedef void (APIENTRYP PFNGLPRIMITIVEBOUNDINGBOXARBPROC) (GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat minW, GLfloat maxX, GLfloat maxY, GLfloat maxZ, GLfloat maxW);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glPrimitiveBoundingBoxARB (GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat minW, GLfloat maxX, GLfloat maxY, GLfloat maxZ, GLfloat maxW);
#endif
#endif /* GL_ARB_ES3_2_compatibility */
#ifndef GL_ARB_ES3_compatibility
#define GL_ARB_ES3_compatibility 1
#endif /* GL_ARB_ES3_compatibility */
#ifndef GL_ARB_arrays_of_arrays
#define GL_ARB_arrays_of_arrays 1
#endif /* GL_ARB_arrays_of_arrays */
#ifndef GL_ARB_base_instance
#define GL_ARB_base_instance 1
#endif /* GL_ARB_base_instance */
#ifndef GL_ARB_bindless_texture
#define GL_ARB_bindless_texture 1
typedef khronos_uint64_t GLuint64EXT;
#define GL_UNSIGNED_INT64_ARB             0x140F
typedef GLuint64 (APIENTRYP PFNGLGETTEXTUREHANDLEARBPROC) (GLuint texture);
typedef GLuint64 (APIENTRYP PFNGLGETTEXTURESAMPLERHANDLEARBPROC) (GLuint texture, GLuint sampler);
typedef void (APIENTRYP PFNGLMAKETEXTUREHANDLERESIDENTARBPROC) (GLuint64 handle);
typedef void (APIENTRYP PFNGLMAKETEXTUREHANDLENONRESIDENTARBPROC) (GLuint64 handle);
typedef GLuint64 (APIENTRYP PFNGLGETIMAGEHANDLEARBPROC) (GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format);
typedef void (APIENTRYP PFNGLMAKEIMAGEHANDLERESIDENTARBPROC) (GLuint64 handle, GLenum access);
typedef void (APIENTRYP PFNGLMAKEIMAGEHANDLENONRESIDENTARBPROC) (GLuint64 handle);
typedef void (APIENTRYP PFNGLUNIFORMHANDLEUI64ARBPROC) (GLint location, GLuint64 value);
typedef void (APIENTRYP PFNGLUNIFORMHANDLEUI64VARBPROC) (GLint location, GLsizei count, const GLuint64 *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMHANDLEUI64ARBPROC) (GLuint program, GLint location, GLuint64 value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMHANDLEUI64VARBPROC) (GLuint program, GLint location, GLsizei count, const GLuint64 *values);
typedef GLboolean (APIENTRYP PFNGLISTEXTUREHANDLERESIDENTARBPROC) (GLuint64 handle);
typedef GLboolean (APIENTRYP PFNGLISIMAGEHANDLERESIDENTARBPROC) (GLuint64 handle);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1UI64ARBPROC) (GLuint index, GLuint64EXT x);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1UI64VARBPROC) (GLuint index, const GLuint64EXT *v);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBLUI64VARBPROC) (GLuint index, GLenum pname, GLuint64EXT *params);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI GLuint64 APIENTRY glGetTextureHandleARB (GLuint texture);
GLAPI GLuint64 APIENTRY glGetTextureSamplerHandleARB (GLuint texture, GLuint sampler);
GLAPI void APIENTRY glMakeTextureHandleResidentARB (GLuint64 handle);
GLAPI void APIENTRY glMakeTextureHandleNonResidentARB (GLuint64 handle);
GLAPI GLuint64 APIENTRY glGetImageHandleARB (GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format);
GLAPI void APIENTRY glMakeImageHandleResidentARB (GLuint64 handle, GLenum access);
GLAPI void APIENTRY glMakeImageHandleNonResidentARB (GLuint64 handle);
GLAPI void APIENTRY glUniformHandleui64ARB (GLint location, GLuint64 value);
GLAPI void APIENTRY glUniformHandleui64vARB (GLint location, GLsizei count, const GLuint64 *value);
GLAPI void APIENTRY glProgramUniformHandleui64ARB (GLuint program, GLint location, GLuint64 value);
GLAPI void APIENTRY glProgramUniformHandleui64vARB (GLuint program, GLint location, GLsizei count, const GLuint64 *values);
GLAPI GLboolean APIENTRY glIsTextureHandleResidentARB (GLuint64 handle);
GLAPI GLboolean APIENTRY glIsImageHandleResidentARB (GLuint64 handle);
GLAPI void APIENTRY glVertexAttribL1ui64ARB (GLuint index, GLuint64EXT x);
GLAPI void APIENTRY glVertexAttribL1ui64vARB (GLuint index, const GLuint64EXT *v);
GLAPI void APIENTRY glGetVertexAttribLui64vARB (GLuint index, GLenum pname, GLuint64EXT *params);
#endif
#endif /* GL_ARB_bindless_texture */
#ifndef GL_ARB_blend_func_extended
#define GL_ARB_blend_func_extended 1
#endif /* GL_ARB_blend_func_extended */
#ifndef GL_ARB_buffer_storage
#define GL_ARB_buffer_storage 1
#endif /* GL_ARB_buffer_storage */
#ifndef GL_ARB_cl_event
#define GL_ARB_cl_event 1
struct _cl_context;
struct _cl_event;
#define GL_SYNC_CL_EVENT_ARB              0x8240
#define GL_SYNC_CL_EVENT_COMPLETE_ARB     0x8241
typedef GLsync (APIENTRYP PFNGLCREATESYNCFROMCLEVENTARBPROC) (struct _cl_context *context, struct _cl_event *event, GLbitfield flags);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI GLsync APIENTRY glCreateSyncFromCLeventARB (struct _cl_context *context, struct _cl_event *event, GLbitfield flags);
#endif
#endif /* GL_ARB_cl_event */
#ifndef GL_ARB_clear_buffer_object
#define GL_ARB_clear_buffer_object 1
#endif /* GL_ARB_clear_buffer_object */
#ifndef GL_ARB_clear_texture
#define GL_ARB_clear_texture 1
#endif /* GL_ARB_clear_texture */
#ifndef GL_ARB_clip_control
#define GL_ARB_clip_control 1
#endif /* GL_ARB_clip_control */
#ifndef GL_ARB_compressed_texture_pixel_storage
#define GL_ARB_compressed_texture_pixel_storage 1
#endif /* GL_ARB_compressed_texture_pixel_storage */
#ifndef GL_ARB_compute_shader
#define GL_ARB_compute_shader 1
#endif /* GL_ARB_compute_shader */
#ifndef GL_ARB_compute_variable_group_size
#define GL_ARB_compute_variable_group_size 1
#define GL_MAX_COMPUTE_VARIABLE_GROUP_INVOCATIONS_ARB 0x9344
#define GL_MAX_COMPUTE_FIXED_GROUP_INVOCATIONS_ARB 0x90EB
#define GL_MAX_COMPUTE_VARIABLE_GROUP_SIZE_ARB 0x9345
#define GL_MAX_COMPUTE_FIXED_GROUP_SIZE_ARB 0x91BF
typedef void (APIENTRYP PFNGLDISPATCHCOMPUTEGROUPSIZEARBPROC) (GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z, GLuint group_size_x, GLuint group_size_y, GLuint group_size_z);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glDispatchComputeGroupSizeARB (GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z, GLuint group_size_x, GLuint group_size_y, GLuint group_size_z);
#endif
#endif /* GL_ARB_compute_variable_group_size */
#ifndef GL_ARB_conditional_render_inverted
#define GL_ARB_conditional_render_inverted 1
#endif /* GL_ARB_conditional_render_inverted */
#ifndef GL_ARB_conservative_depth
#define GL_ARB_conservative_depth 1
#endif /* GL_ARB_conservative_depth */
#ifndef GL_ARB_copy_buffer
#define GL_ARB_copy_buffer 1
#endif /* GL_ARB_copy_buffer */
#ifndef GL_ARB_copy_image
#define GL_ARB_copy_image 1
#endif /* GL_ARB_copy_image */
#ifndef GL_ARB_cull_distance
#define GL_ARB_cull_distance 1
#endif /* GL_ARB_cull_distance */
#ifndef GL_ARB_debug_output
#define GL_ARB_debug_output 1
typedef void (APIENTRY  *GLDEBUGPROCARB)(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,const void *userParam);
#define GL_DEBUG_OUTPUT_SYNCHRONOUS_ARB   0x8242
#define GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH_ARB 0x8243
#define GL_DEBUG_CALLBACK_FUNCTION_ARB    0x8244
#define GL_DEBUG_CALLBACK_USER_PARAM_ARB  0x8245
#define GL_DEBUG_SOURCE_API_ARB           0x8246
#define GL_DEBUG_SOURCE_WINDOW_SYSTEM_ARB 0x8247
#define GL_DEBUG_SOURCE_SHADER_COMPILER_ARB 0x8248
#define GL_DEBUG_SOURCE_THIRD_PARTY_ARB   0x8249
#define GL_DEBUG_SOURCE_APPLICATION_ARB   0x824A
#define GL_DEBUG_SOURCE_OTHER_ARB         0x824B
#define GL_DEBUG_TYPE_ERROR_ARB           0x824C
#define GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR_ARB 0x824D
#define GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR_ARB 0x824E
#define GL_DEBUG_TYPE_PORTABILITY_ARB     0x824F
#define GL_DEBUG_TYPE_PERFORMANCE_ARB     0x8250
#define GL_DEBUG_TYPE_OTHER_ARB           0x8251
#define GL_MAX_DEBUG_MESSAGE_LENGTH_ARB   0x9143
#define GL_MAX_DEBUG_LOGGED_MESSAGES_ARB  0x9144
#define GL_DEBUG_LOGGED_MESSAGES_ARB      0x9145
#define GL_DEBUG_SEVERITY_HIGH_ARB        0x9146
#define GL_DEBUG_SEVERITY_MEDIUM_ARB      0x9147
#define GL_DEBUG_SEVERITY_LOW_ARB         0x9148
typedef void (APIENTRYP PFNGLDEBUGMESSAGECONTROLARBPROC) (GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
typedef void (APIENTRYP PFNGLDEBUGMESSAGEINSERTARBPROC) (GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf);
typedef void (APIENTRYP PFNGLDEBUGMESSAGECALLBACKARBPROC) (GLDEBUGPROCARB callback, const void *userParam);
typedef GLuint (APIENTRYP PFNGLGETDEBUGMESSAGELOGARBPROC) (GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glDebugMessageControlARB (GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
GLAPI void APIENTRY glDebugMessageInsertARB (GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf);
GLAPI void APIENTRY glDebugMessageCallbackARB (GLDEBUGPROCARB callback, const void *userParam);
GLAPI GLuint APIENTRY glGetDebugMessageLogARB (GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog);
#endif
#endif /* GL_ARB_debug_output */
#ifndef GL_ARB_depth_buffer_float
#define GL_ARB_depth_buffer_float 1
#endif /* GL_ARB_depth_buffer_float */
#ifndef GL_ARB_depth_clamp
#define GL_ARB_depth_clamp 1
#endif /* GL_ARB_depth_clamp */
#ifndef GL_ARB_derivative_control
#define GL_ARB_derivative_control 1
#endif /* GL_ARB_derivative_control */
#ifndef GL_ARB_direct_state_access
#define GL_ARB_direct_state_access 1
#endif /* GL_ARB_direct_state_access */
#ifndef GL_ARB_draw_buffers_blend
#define GL_ARB_draw_buffers_blend 1
typedef void (APIENTRYP PFNGLBLENDEQUATIONIARBPROC) (GLuint buf, GLenum mode);
typedef void (APIENTRYP PFNGLBLENDEQUATIONSEPARATEIARBPROC) (GLuint buf, GLenum modeRGB, GLenum modeAlpha);
typedef void (APIENTRYP PFNGLBLENDFUNCIARBPROC) (GLuint buf, GLenum src, GLenum dst);
typedef void (APIENTRYP PFNGLBLENDFUNCSEPARATEIARBPROC) (GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glBlendEquationiARB (GLuint buf, GLenum mode);
GLAPI void APIENTRY glBlendEquationSeparateiARB (GLuint buf, GLenum modeRGB, GLenum modeAlpha);
GLAPI void APIENTRY glBlendFunciARB (GLuint buf, GLenum src, GLenum dst);
GLAPI void APIENTRY glBlendFuncSeparateiARB (GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
#endif
#endif /* GL_ARB_draw_buffers_blend */
#ifndef GL_ARB_draw_elements_base_vertex
#define GL_ARB_draw_elements_base_vertex 1
#endif /* GL_ARB_draw_elements_base_vertex */
#ifndef GL_ARB_draw_indirect
#define GL_ARB_draw_indirect 1
#endif /* GL_ARB_draw_indirect */
#ifndef GL_ARB_draw_instanced
#define GL_ARB_draw_instanced 1
typedef void (APIENTRYP PFNGLDRAWARRAYSINSTANCEDARBPROC) (GLenum mode, GLint first, GLsizei count, GLsizei primcount);
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDARBPROC) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei primcount);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glDrawArraysInstancedARB (GLenum mode, GLint first, GLsizei count, GLsizei primcount);
GLAPI void APIENTRY glDrawElementsInstancedARB (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei primcount);
#endif
#endif /* GL_ARB_draw_instanced */
#ifndef GL_ARB_enhanced_layouts
#define GL_ARB_enhanced_layouts 1
#endif /* GL_ARB_enhanced_layouts */
#ifndef GL_ARB_explicit_attrib_location
#define GL_ARB_explicit_attrib_location 1
#endif /* GL_ARB_explicit_attrib_location */
#ifndef GL_ARB_explicit_uniform_location
#define GL_ARB_explicit_uniform_location 1
#endif /* GL_ARB_explicit_uniform_location */
#ifndef GL_ARB_fragment_coord_conventions
#define GL_ARB_fragment_coord_conventions 1
#endif /* GL_ARB_fragment_coord_conventions */
#ifndef GL_ARB_fragment_layer_viewport
#define GL_ARB_fragment_layer_viewport 1
#endif /* GL_ARB_fragment_layer_viewport */
#ifndef GL_ARB_fragment_shader_interlock
#define GL_ARB_fragment_shader_interlock 1
#endif /* GL_ARB_fragment_shader_interlock */
#ifndef GL_ARB_framebuffer_no_attachments
#define GL_ARB_framebuffer_no_attachments 1
#endif /* GL_ARB_framebuffer_no_attachments */
#ifndef GL_ARB_framebuffer_object
#define GL_ARB_framebuffer_object 1
#endif /* GL_ARB_framebuffer_object */
#ifndef GL_ARB_framebuffer_sRGB
#define GL_ARB_framebuffer_sRGB 1
#endif /* GL_ARB_framebuffer_sRGB */
#ifndef GL_ARB_geometry_shader4
#define GL_ARB_geometry_shader4 1
#define GL_LINES_ADJACENCY_ARB            0x000A
#define GL_LINE_STRIP_ADJACENCY_ARB       0x000B
#define GL_TRIANGLES_ADJACENCY_ARB        0x000C
#define GL_TRIANGLE_STRIP_ADJACENCY_ARB   0x000D
#define GL_PROGRAM_POINT_SIZE_ARB         0x8642
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_ARB 0x8C29
#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED_ARB 0x8DA7
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_ARB 0x8DA8
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_ARB 0x8DA9
#define GL_GEOMETRY_SHADER_ARB            0x8DD9
#define GL_GEOMETRY_VERTICES_OUT_ARB      0x8DDA
#define GL_GEOMETRY_INPUT_TYPE_ARB        0x8DDB
#define GL_GEOMETRY_OUTPUT_TYPE_ARB       0x8DDC
#define GL_MAX_GEOMETRY_VARYING_COMPONENTS_ARB 0x8DDD
#define GL_MAX_VERTEX_VARYING_COMPONENTS_ARB 0x8DDE
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_ARB 0x8DDF
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES_ARB 0x8DE0
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_ARB 0x8DE1
typedef void (APIENTRYP PFNGLPROGRAMPARAMETERIARBPROC) (GLuint program, GLenum pname, GLint value);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTUREARBPROC) (GLenum target, GLenum attachment, GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURELAYERARBPROC) (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTUREFACEARBPROC) (GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glProgramParameteriARB (GLuint program, GLenum pname, GLint value);
GLAPI void APIENTRY glFramebufferTextureARB (GLenum target, GLenum attachment, GLuint texture, GLint level);
GLAPI void APIENTRY glFramebufferTextureLayerARB (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
GLAPI void APIENTRY glFramebufferTextureFaceARB (GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face);
#endif
#endif /* GL_ARB_geometry_shader4 */
#ifndef GL_ARB_get_program_binary
#define GL_ARB_get_program_binary 1
#endif /* GL_ARB_get_program_binary */
#ifndef GL_ARB_get_texture_sub_image
#define GL_ARB_get_texture_sub_image 1
#endif /* GL_ARB_get_texture_sub_image */
#ifndef GL_ARB_gl_spirv
#define GL_ARB_gl_spirv 1
#define GL_SHADER_BINARY_FORMAT_SPIR_V_ARB 0x9551
#define GL_SPIR_V_BINARY_ARB              0x9552
typedef void (APIENTRYP PFNGLSPECIALIZESHADERARBPROC) (GLuint shader, const GLchar *pEntryPoint, GLuint numSpecializationConstants, const GLuint *pConstantIndex, const GLuint *pConstantValue);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glSpecializeShaderARB (GLuint shader, const GLchar *pEntryPoint, GLuint numSpecializationConstants, const GLuint *pConstantIndex, const GLuint *pConstantValue);
#endif
#endif /* GL_ARB_gl_spirv */
#ifndef GL_ARB_gpu_shader5
#define GL_ARB_gpu_shader5 1
#endif /* GL_ARB_gpu_shader5 */
#ifndef GL_ARB_gpu_shader_fp64
#define GL_ARB_gpu_shader_fp64 1
#endif /* GL_ARB_gpu_shader_fp64 */
#ifndef GL_ARB_gpu_shader_int64
#define GL_ARB_gpu_shader_int64 1
#define GL_INT64_ARB                      0x140E
#define GL_INT64_VEC2_ARB                 0x8FE9
#define GL_INT64_VEC3_ARB                 0x8FEA
#define GL_INT64_VEC4_ARB                 0x8FEB
#define GL_UNSIGNED_INT64_VEC2_ARB        0x8FF5
#define GL_UNSIGNED_INT64_VEC3_ARB        0x8FF6
#define GL_UNSIGNED_INT64_VEC4_ARB        0x8FF7
typedef void (APIENTRYP PFNGLUNIFORM1I64ARBPROC) (GLint location, GLint64 x);
typedef void (APIENTRYP PFNGLUNIFORM2I64ARBPROC) (GLint location, GLint64 x, GLint64 y);
typedef void (APIENTRYP PFNGLUNIFORM3I64ARBPROC) (GLint location, GLint64 x, GLint64 y, GLint64 z);
typedef void (APIENTRYP PFNGLUNIFORM4I64ARBPROC) (GLint location, GLint64 x, GLint64 y, GLint64 z, GLint64 w);
typedef void (APIENTRYP PFNGLUNIFORM1I64VARBPROC) (GLint location, GLsizei count, const GLint64 *value);
typedef void (APIENTRYP PFNGLUNIFORM2I64VARBPROC) (GLint location, GLsizei count, const GLint64 *value);
typedef void (APIENTRYP PFNGLUNIFORM3I64VARBPROC) (GLint location, GLsizei count, const GLint64 *value);
typedef void (APIENTRYP PFNGLUNIFORM4I64VARBPROC) (GLint location, GLsizei count, const GLint64 *value);
typedef void (APIENTRYP PFNGLUNIFORM1UI64ARBPROC) (GLint location, GLuint64 x);
typedef void (APIENTRYP PFNGLUNIFORM2UI64ARBPROC) (GLint location, GLuint64 x, GLuint64 y);
typedef void (APIENTRYP PFNGLUNIFORM3UI64ARBPROC) (GLint location, GLuint64 x, GLuint64 y, GLuint64 z);
typedef void (APIENTRYP PFNGLUNIFORM4UI64ARBPROC) (GLint location, GLuint64 x, GLuint64 y, GLuint64 z, GLuint64 w);
typedef void (APIENTRYP PFNGLUNIFORM1UI64VARBPROC) (GLint location, GLsizei count, const GLuint64 *value);
typedef void (APIENTRYP PFNGLUNIFORM2UI64VARBPROC) (GLint location, GLsizei count, const GLuint64 *value);
typedef void (APIENTRYP PFNGLUNIFORM3UI64VARBPROC) (GLint location, GLsizei count, const GLuint64 *value);
typedef void (APIENTRYP PFNGLUNIFORM4UI64VARBPROC) (GLint location, GLsizei count, const GLuint64 *value);
typedef void (APIENTRYP PFNGLGETUNIFORMI64VARBPROC) (GLuint program, GLint location, GLint64 *params);
typedef void (APIENTRYP PFNGLGETUNIFORMUI64VARBPROC) (GLuint program, GLint location, GLuint64 *params);
typedef void (APIENTRYP PFNGLGETNUNIFORMI64VARBPROC) (GLuint program, GLint location, GLsizei bufSize, GLint64 *params);
typedef void (APIENTRYP PFNGLGETNUNIFORMUI64VARBPROC) (GLuint program, GLint location, GLsizei bufSize, GLuint64 *params);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1I64ARBPROC) (GLuint program, GLint location, GLint64 x);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2I64ARBPROC) (GLuint program, GLint location, GLint64 x, GLint64 y);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3I64ARBPROC) (GLuint program, GLint location, GLint64 x, GLint64 y, GLint64 z);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4I64ARBPROC) (GLuint program, GLint location, GLint64 x, GLint64 y, GLint64 z, GLint64 w);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1I64VARBPROC) (GLuint program, GLint location, GLsizei count, const GLint64 *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2I64VARBPROC) (GLuint program, GLint location, GLsizei count, const GLint64 *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3I64VARBPROC) (GLuint program, GLint location, GLsizei count, const GLint64 *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4I64VARBPROC) (GLuint program, GLint location, GLsizei count, const GLint64 *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UI64ARBPROC) (GLuint program, GLint location, GLuint64 x);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UI64ARBPROC) (GLuint program, GLint location, GLuint64 x, GLuint64 y);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UI64ARBPROC) (GLuint program, GLint location, GLuint64 x, GLuint64 y, GLuint64 z);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UI64ARBPROC) (GLuint program, GLint location, GLuint64 x, GLuint64 y, GLuint64 z, GLuint64 w);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UI64VARBPROC) (GLuint program, GLint location, GLsizei count, const GLuint64 *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UI64VARBPROC) (GLuint program, GLint location, GLsizei count, const GLuint64 *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UI64VARBPROC) (GLuint program, GLint location, GLsizei count, const GLuint64 *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UI64VARBPROC) (GLuint program, GLint location, GLsizei count, const GLuint64 *value);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glUniform1i64ARB (GLint location, GLint64 x);
GLAPI void APIENTRY glUniform2i64ARB (GLint location, GLint64 x, GLint64 y);
GLAPI void APIENTRY glUniform3i64ARB (GLint location, GLint64 x, GLint64 y, GLint64 z);
GLAPI void APIENTRY glUniform4i64ARB (GLint location, GLint64 x, GLint64 y, GLint64 z, GLint64 w);
GLAPI void APIENTRY glUniform1i64vARB (GLint location, GLsizei count, const GLint64 *value);
GLAPI void APIENTRY glUniform2i64vARB (GLint location, GLsizei count, const GLint64 *value);
GLAPI void APIENTRY glUniform3i64vARB (GLint location, GLsizei count, const GLint64 *value);
GLAPI void APIENTRY glUniform4i64vARB (GLint location, GLsizei count, const GLint64 *value);
GLAPI void APIENTRY glUniform1ui64ARB (GLint location, GLuint64 x);
GLAPI void APIENTRY glUniform2ui64ARB (GLint location, GLuint64 x, GLuint64 y);
GLAPI void APIENTRY glUniform3ui64ARB (GLint location, GLuint64 x, GLuint64 y, GLuint64 z);
GLAPI void APIENTRY glUniform4ui64ARB (GLint location, GLuint64 x, GLuint64 y, GLuint64 z, GLuint64 w);
GLAPI void APIENTRY glUniform1ui64vARB (GLint location, GLsizei count, const GLuint64 *value);
GLAPI void APIENTRY glUniform2ui64vARB (GLint location, GLsizei count, const GLuint64 *value);
GLAPI void APIENTRY glUniform3ui64vARB (GLint location, GLsizei count, const GLuint64 *value);
GLAPI void APIENTRY glUniform4ui64vARB (GLint location, GLsizei count, const GLuint64 *value);
GLAPI void APIENTRY glGetUniformi64vARB (GLuint program, GLint location, GLint64 *params);
GLAPI void APIENTRY glGetUniformui64vARB (GLuint program, GLint location, GLuint64 *params);
GLAPI void APIENTRY glGetnUniformi64vARB (GLuint program, GLint location, GLsizei bufSize, GLint64 *params);
GLAPI void APIENTRY glGetnUniformui64vARB (GLuint program, GLint location, GLsizei bufSize, GLuint64 *params);
GLAPI void APIENTRY glProgramUniform1i64ARB (GLuint program, GLint location, GLint64 x);
GLAPI void APIENTRY glProgramUniform2i64ARB (GLuint program, GLint location, GLint64 x, GLint64 y);
GLAPI void APIENTRY glProgramUniform3i64ARB (GLuint program, GLint location, GLint64 x, GLint64 y, GLint64 z);
GLAPI void APIENTRY glProgramUniform4i64ARB (GLuint program, GLint location, GLint64 x, GLint64 y, GLint64 z, GLint64 w);
GLAPI void APIENTRY glProgramUniform1i64vARB (GLuint program, GLint location, GLsizei count, const GLint64 *value);
GLAPI void APIENTRY glProgramUniform2i64vARB (GLuint program, GLint location, GLsizei count, const GLint64 *value);
GLAPI void APIENTRY glProgramUniform3i64vARB (GLuint program, GLint location, GLsizei count, const GLint64 *value);
GLAPI void APIENTRY glProgramUniform4i64vARB (GLuint program, GLint location, GLsizei count, const GLint64 *value);
GLAPI void APIENTRY glProgramUniform1ui64ARB (GLuint program, GLint location, GLuint64 x);
GLAPI void APIENTRY glProgramUniform2ui64ARB (GLuint program, GLint location, GLuint64 x, GLuint64 y);
GLAPI void APIENTRY glProgramUniform3ui64ARB (GLuint program, GLint location, GLuint64 x, GLuint64 y, GLuint64 z);
GLAPI void APIENTRY glProgramUniform4ui64ARB (GLuint program, GLint location, GLuint64 x, GLuint64 y, GLuint64 z, GLuint64 w);
GLAPI void APIENTRY glProgramUniform1ui64vARB (GLuint program, GLint location, GLsizei count, const GLuint64 *value);
GLAPI void APIENTRY glProgramUniform2ui64vARB (GLuint program, GLint location, GLsizei count, const GLuint64 *value);
GLAPI void APIENTRY glProgramUniform3ui64vARB (GLuint program, GLint location, GLsizei count, const GLuint64 *value);
GLAPI void APIENTRY glProgramUniform4ui64vARB (GLuint program, GLint location, GLsizei count, const GLuint64 *value);
#endif
#endif /* GL_ARB_gpu_shader_int64 */
#ifndef GL_ARB_half_float_vertex
#define GL_ARB_half_float_vertex 1
#endif /* GL_ARB_half_float_vertex */
#ifndef GL_ARB_imaging
#define GL_ARB_imaging 1
#endif /* GL_ARB_imaging */
#ifndef GL_ARB_indirect_parameters
#define GL_ARB_indirect_parameters 1
#define GL_PARAMETER_BUFFER_ARB           0x80EE
#define GL_PARAMETER_BUFFER_BINDING_ARB   0x80EF
typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTCOUNTARBPROC) (GLenum mode, const void *indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTARBPROC) (GLenum mode, GLenum type, const void *indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glMultiDrawArraysIndirectCountARB (GLenum mode, const void *indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
GLAPI void APIENTRY glMultiDrawElementsIndirectCountARB (GLenum mode, GLenum type, const void *indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
#endif
#endif /* GL_ARB_indirect_parameters */
#ifndef GL_ARB_instanced_arrays
#define GL_ARB_instanced_arrays 1
#define GL_VERTEX_ATTRIB_ARRAY_DIVISOR_ARB 0x88FE
typedef void (APIENTRYP PFNGLVERTEXATTRIBDIVISORARBPROC) (GLuint index, GLuint divisor);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glVertexAttribDivisorARB (GLuint index, GLuint divisor);
#endif
#endif /* GL_ARB_instanced_arrays */
#ifndef GL_ARB_internalformat_query
#define GL_ARB_internalformat_query 1
#endif /* GL_ARB_internalformat_query */
#ifndef GL_ARB_internalformat_query2
#define GL_ARB_internalformat_query2 1
#define GL_SRGB_DECODE_ARB                0x8299
#define GL_VIEW_CLASS_EAC_R11             0x9383
#define GL_VIEW_CLASS_EAC_RG11            0x9384
#define GL_VIEW_CLASS_ETC2_RGB            0x9385
#define GL_VIEW_CLASS_ETC2_RGBA           0x9386
#define GL_VIEW_CLASS_ETC2_EAC_RGBA       0x9387
#define GL_VIEW_CLASS_ASTC_4x4_RGBA       0x9388
#define GL_VIEW_CLASS_ASTC_5x4_RGBA       0x9389
#define GL_VIEW_CLASS_ASTC_5x5_RGBA       0x938A
#define GL_VIEW_CLASS_ASTC_6x5_RGBA       0x938B
#define GL_VIEW_CLASS_ASTC_6x6_RGBA       0x938C
#define GL_VIEW_CLASS_ASTC_8x5_RGBA       0x938D
#define GL_VIEW_CLASS_ASTC_8x6_RGBA       0x938E
#define GL_VIEW_CLASS_ASTC_8x8_RGBA       0x938F
#define GL_VIEW_CLASS_ASTC_10x5_RGBA      0x9390
#define GL_VIEW_CLASS_ASTC_10x6_RGBA      0x9391
#define GL_VIEW_CLASS_ASTC_10x8_RGBA      0x9392
#define GL_VIEW_CLASS_ASTC_10x10_RGBA     0x9393
#define GL_VIEW_CLASS_ASTC_12x10_RGBA     0x9394
#define GL_VIEW_CLASS_ASTC_12x12_RGBA     0x9395
#endif /* GL_ARB_internalformat_query2 */
#ifndef GL_ARB_invalidate_subdata
#define GL_ARB_invalidate_subdata 1
#endif /* GL_ARB_invalidate_subdata */
#ifndef GL_ARB_map_buffer_alignment
#define GL_ARB_map_buffer_alignment 1
#endif /* GL_ARB_map_buffer_alignment */
#ifndef GL_ARB_map_buffer_range
#define GL_ARB_map_buffer_range 1
#endif /* GL_ARB_map_buffer_range */
#ifndef GL_ARB_multi_bind
#define GL_ARB_multi_bind 1
#endif /* GL_ARB_multi_bind */
#ifndef GL_ARB_multi_draw_indirect
#define GL_ARB_multi_draw_indirect 1
#endif /* GL_ARB_multi_draw_indirect */
#ifndef GL_ARB_occlusion_query2
#define GL_ARB_occlusion_query2 1
#endif /* GL_ARB_occlusion_query2 */
#ifndef GL_ARB_parallel_shader_compile
#define GL_ARB_parallel_shader_compile 1
#define GL_MAX_SHADER_COMPILER_THREADS_ARB 0x91B0
#define GL_COMPLETION_STATUS_ARB          0x91B1
typedef void (APIENTRYP PFNGLMAXSHADERCOMPILERTHREADSARBPROC) (GLuint count);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glMaxShaderCompilerThreadsARB (GLuint count);
#endif
#endif /* GL_ARB_parallel_shader_compile */
#ifndef GL_ARB_pipeline_statistics_query
#define GL_ARB_pipeline_statistics_query 1
#define GL_VERTICES_SUBMITTED_ARB         0x82EE
#define GL_PRIMITIVES_SUBMITTED_ARB       0x82EF
#define GL_VERTEX_SHADER_INVOCATIONS_ARB  0x82F0
#define GL_TESS_CONTROL_SHADER_PATCHES_ARB 0x82F1
#define GL_TESS_EVALUATION_SHADER_INVOCATIONS_ARB 0x82F2
#define GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED_ARB 0x82F3
#define GL_FRAGMENT_SHADER_INVOCATIONS_ARB 0x82F4
#define GL_COMPUTE_SHADER_INVOCATIONS_ARB 0x82F5
#define GL_CLIPPING_INPUT_PRIMITIVES_ARB  0x82F6
#define GL_CLIPPING_OUTPUT_PRIMITIVES_ARB 0x82F7
#endif /* GL_ARB_pipeline_statistics_query */
#ifndef GL_ARB_pixel_buffer_object
#define GL_ARB_pixel_buffer_object 1
#define GL_PIXEL_PACK_BUFFER_ARB          0x88EB
#define GL_PIXEL_UNPACK_BUFFER_ARB        0x88EC
#define GL_PIXEL_PACK_BUFFER_BINDING_ARB  0x88ED
#define GL_PIXEL_UNPACK_BUFFER_BINDING_ARB 0x88EF
#endif /* GL_ARB_pixel_buffer_object */
#ifndef GL_ARB_polygon_offset_clamp
#define GL_ARB_polygon_offset_clamp 1
#endif /* GL_ARB_polygon_offset_clamp */
#ifndef GL_ARB_post_depth_coverage
#define GL_ARB_post_depth_coverage 1
#endif /* GL_ARB_post_depth_coverage */
#ifndef GL_ARB_program_interface_query
#define GL_ARB_program_interface_query 1
#endif /* GL_ARB_program_interface_query */
#ifndef GL_ARB_provoking_vertex
#define GL_ARB_provoking_vertex 1
#endif /* GL_ARB_provoking_vertex */
#ifndef GL_ARB_query_buffer_object
#define GL_ARB_query_buffer_object 1
#endif /* GL_ARB_query_buffer_object */
#ifndef GL_ARB_robust_buffer_access_behavior
#define GL_ARB_robust_buffer_access_behavior 1
#endif /* GL_ARB_robust_buffer_access_behavior */
#ifndef GL_ARB_robustness
#define GL_ARB_robustness 1
#define GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT_ARB 0x00000004
#define GL_LOSE_CONTEXT_ON_RESET_ARB      0x8252
#define GL_GUILTY_CONTEXT_RESET_ARB       0x8253
#define GL_INNOCENT_CONTEXT_RESET_ARB     0x8254
#define GL_UNKNOWN_CONTEXT_RESET_ARB      0x8255
#define GL_RESET_NOTIFICATION_STRATEGY_ARB 0x8256
#define GL_NO_RESET_NOTIFICATION_ARB      0x8261
typedef GLenum (APIENTRYP PFNGLGETGRAPHICSRESETSTATUSARBPROC) (void);
typedef void (APIENTRYP PFNGLGETNTEXIMAGEARBPROC) (GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *img);
typedef void (APIENTRYP PFNGLREADNPIXELSARBPROC) (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data);
typedef void (APIENTRYP PFNGLGETNCOMPRESSEDTEXIMAGEARBPROC) (GLenum target, GLint lod, GLsizei bufSize, void *img);
typedef void (APIENTRYP PFNGLGETNUNIFORMFVARBPROC) (GLuint program, GLint location, GLsizei bufSize, GLfloat *params);
typedef void (APIENTRYP PFNGLGETNUNIFORMIVARBPROC) (GLuint program, GLint location, GLsizei bufSize, GLint *params);
typedef void (APIENTRYP PFNGLGETNUNIFORMUIVARBPROC) (GLuint program, GLint location, GLsizei bufSize, GLuint *params);
typedef void (APIENTRYP PFNGLGETNUNIFORMDVARBPROC) (GLuint program, GLint location, GLsizei bufSize, GLdouble *params);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI GLenum APIENTRY glGetGraphicsResetStatusARB (void);
GLAPI void APIENTRY glGetnTexImageARB (GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *img);
GLAPI void APIENTRY glReadnPixelsARB (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data);
GLAPI void APIENTRY glGetnCompressedTexImageARB (GLenum target, GLint lod, GLsizei bufSize, void *img);
GLAPI void APIENTRY glGetnUniformfvARB (GLuint program, GLint location, GLsizei bufSize, GLfloat *params);
GLAPI void APIENTRY glGetnUniformivARB (GLuint program, GLint location, GLsizei bufSize, GLint *params);
GLAPI void APIENTRY glGetnUniformuivARB (GLuint program, GLint location, GLsizei bufSize, GLuint *params);
GLAPI void APIENTRY glGetnUniformdvARB (GLuint program, GLint location, GLsizei bufSize, GLdouble *params);
#endif
#endif /* GL_ARB_robustness */
#ifndef GL_ARB_robustness_isolation
#define GL_ARB_robustness_isolation 1
#endif /* GL_ARB_robustness_isolation */
#ifndef GL_ARB_sample_locations
#define GL_ARB_sample_locations 1
#define GL_SAMPLE_LOCATION_SUBPIXEL_BITS_ARB 0x933D
#define GL_SAMPLE_LOCATION_PIXEL_GRID_WIDTH_ARB 0x933E
#define GL_SAMPLE_LOCATION_PIXEL_GRID_HEIGHT_ARB 0x933F
#define GL_PROGRAMMABLE_SAMPLE_LOCATION_TABLE_SIZE_ARB 0x9340
#define GL_SAMPLE_LOCATION_ARB            0x8E50
#define GL_PROGRAMMABLE_SAMPLE_LOCATION_ARB 0x9341
#define GL_FRAMEBUFFER_PROGRAMMABLE_SAMPLE_LOCATIONS_ARB 0x9342
#define GL_FRAMEBUFFER_SAMPLE_LOCATION_PIXEL_GRID_ARB 0x9343
typedef void (APIENTRYP PFNGLFRAMEBUFFERSAMPLELOCATIONSFVARBPROC) (GLenum target, GLuint start, GLsizei count, const GLfloat *v);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVARBPROC) (GLuint framebuffer, GLuint start, GLsizei count, const GLfloat *v);
typedef void (APIENTRYP PFNGLEVALUATEDEPTHVALUESARBPROC) (void);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glFramebufferSampleLocationsfvARB (GLenum target, GLuint start, GLsizei count, const GLfloat *v);
GLAPI void APIENTRY glNamedFramebufferSampleLocationsfvARB (GLuint framebuffer, GLuint start, GLsizei count, const GLfloat *v);
GLAPI void APIENTRY glEvaluateDepthValuesARB (void);
#endif
#endif /* GL_ARB_sample_locations */
#ifndef GL_ARB_sample_shading
#define GL_ARB_sample_shading 1
#define GL_SAMPLE_SHADING_ARB             0x8C36
#define GL_MIN_SAMPLE_SHADING_VALUE_ARB   0x8C37
typedef void (APIENTRYP PFNGLMINSAMPLESHADINGARBPROC) (GLfloat value);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glMinSampleShadingARB (GLfloat value);
#endif
#endif /* GL_ARB_sample_shading */
#ifndef GL_ARB_sampler_objects
#define GL_ARB_sampler_objects 1
#endif /* GL_ARB_sampler_objects */
#ifndef GL_ARB_seamless_cube_map
#define GL_ARB_seamless_cube_map 1
#endif /* GL_ARB_seamless_cube_map */
#ifndef GL_ARB_seamless_cubemap_per_texture
#define GL_ARB_seamless_cubemap_per_texture 1
#endif /* GL_ARB_seamless_cubemap_per_texture */
#ifndef GL_ARB_separate_shader_objects
#define GL_ARB_separate_shader_objects 1
#endif /* GL_ARB_separate_shader_objects */
#ifndef GL_ARB_shader_atomic_counter_ops
#define GL_ARB_shader_atomic_counter_ops 1
#endif /* GL_ARB_shader_atomic_counter_ops */
#ifndef GL_ARB_shader_atomic_counters
#define GL_ARB_shader_atomic_counters 1
#endif /* GL_ARB_shader_atomic_counters */
#ifndef GL_ARB_shader_ballot
#define GL_ARB_shader_ballot 1
#endif /* GL_ARB_shader_ballot */
#ifndef GL_ARB_shader_bit_encoding
#define GL_ARB_shader_bit_encoding 1
#endif /* GL_ARB_shader_bit_encoding */
#ifndef GL_ARB_shader_clock
#define GL_ARB_shader_clock 1
#endif /* GL_ARB_shader_clock */
#ifndef GL_ARB_shader_draw_parameters
#define GL_ARB_shader_draw_parameters 1
#endif /* GL_ARB_shader_draw_parameters */
#ifndef GL_ARB_shader_group_vote
#define GL_ARB_shader_group_vote 1
#endif /* GL_ARB_shader_group_vote */
#ifndef GL_ARB_shader_image_load_store
#define GL_ARB_shader_image_load_store 1
#endif /* GL_ARB_shader_image_load_store */
#ifndef GL_ARB_shader_image_size
#define GL_ARB_shader_image_size 1
#endif /* GL_ARB_shader_image_size */
#ifndef GL_ARB_shader_precision
#define GL_ARB_shader_precision 1
#endif /* GL_ARB_shader_precision */
#ifndef GL_ARB_shader_stencil_export
#define GL_ARB_shader_stencil_export 1
#endif /* GL_ARB_shader_stencil_export */
#ifndef GL_ARB_shader_storage_buffer_object
#define GL_ARB_shader_storage_buffer_object 1
#endif /* GL_ARB_shader_storage_buffer_object */
#ifndef GL_ARB_shader_subroutine
#define GL_ARB_shader_subroutine 1
#endif /* GL_ARB_shader_subroutine */
#ifndef GL_ARB_shader_texture_image_samples
#define GL_ARB_shader_texture_image_samples 1
#endif /* GL_ARB_shader_texture_image_samples */
#ifndef GL_ARB_shader_viewport_layer_array
#define GL_ARB_shader_viewport_layer_array 1
#endif /* GL_ARB_shader_viewport_layer_array */
#ifndef GL_ARB_shading_language_420pack
#define GL_ARB_shading_language_420pack 1
#endif /* GL_ARB_shading_language_420pack */
#ifndef GL_ARB_shading_language_include
#define GL_ARB_shading_language_include 1
#define GL_SHADER_INCLUDE_ARB             0x8DAE
#define GL_NAMED_STRING_LENGTH_ARB        0x8DE9
#define GL_NAMED_STRING_TYPE_ARB          0x8DEA
typedef void (APIENTRYP PFNGLNAMEDSTRINGARBPROC) (GLenum type, GLint namelen, const GLchar *name, GLint stringlen, const GLchar *string);
typedef void (APIENTRYP PFNGLDELETENAMEDSTRINGARBPROC) (GLint namelen, const GLchar *name);
typedef void (APIENTRYP PFNGLCOMPILESHADERINCLUDEARBPROC) (GLuint shader, GLsizei count, const GLchar *const*path, const GLint *length);
typedef GLboolean (APIENTRYP PFNGLISNAMEDSTRINGARBPROC) (GLint namelen, const GLchar *name);
typedef void (APIENTRYP PFNGLGETNAMEDSTRINGARBPROC) (GLint namelen, const GLchar *name, GLsizei bufSize, GLint *stringlen, GLchar *string);
typedef void (APIENTRYP PFNGLGETNAMEDSTRINGIVARBPROC) (GLint namelen, const GLchar *name, GLenum pname, GLint *params);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glNamedStringARB (GLenum type, GLint namelen, const GLchar *name, GLint stringlen, const GLchar *string);
GLAPI void APIENTRY glDeleteNamedStringARB (GLint namelen, const GLchar *name);
GLAPI void APIENTRY glCompileShaderIncludeARB (GLuint shader, GLsizei count, const GLchar *const*path, const GLint *length);
GLAPI GLboolean APIENTRY glIsNamedStringARB (GLint namelen, const GLchar *name);
GLAPI void APIENTRY glGetNamedStringARB (GLint namelen, const GLchar *name, GLsizei bufSize, GLint *stringlen, GLchar *string);
GLAPI void APIENTRY glGetNamedStringivARB (GLint namelen, const GLchar *name, GLenum pname, GLint *params);
#endif
#endif /* GL_ARB_shading_language_include */
#ifndef GL_ARB_shading_language_packing
#define GL_ARB_shading_language_packing 1
#endif /* GL_ARB_shading_language_packing */
#ifndef GL_ARB_sparse_buffer
#define GL_ARB_sparse_buffer 1
#define GL_SPARSE_STORAGE_BIT_ARB         0x0400
#define GL_SPARSE_BUFFER_PAGE_SIZE_ARB    0x82F8
typedef void (APIENTRYP PFNGLBUFFERPAGECOMMITMENTARBPROC) (GLenum target, GLintptr offset, GLsizeiptr size, GLboolean commit);
typedef void (APIENTRYP PFNGLNAMEDBUFFERPAGECOMMITMENTEXTPROC) (GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit);
typedef void (APIENTRYP PFNGLNAMEDBUFFERPAGECOMMITMENTARBPROC) (GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glBufferPageCommitmentARB (GLenum target, GLintptr offset, GLsizeiptr size, GLboolean commit);
GLAPI void APIENTRY glNamedBufferPageCommitmentEXT (GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit);
GLAPI void APIENTRY glNamedBufferPageCommitmentARB (GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit);
#endif
#endif /* GL_ARB_sparse_buffer */
#ifndef GL_ARB_sparse_texture
#define GL_ARB_sparse_texture 1
#define GL_TEXTURE_SPARSE_ARB             0x91A6
#define GL_VIRTUAL_PAGE_SIZE_INDEX_ARB    0x91A7
#define GL_NUM_SPARSE_LEVELS_ARB          0x91AA
#define GL_NUM_VIRTUAL_PAGE_SIZES_ARB     0x91A8
#define GL_VIRTUAL_PAGE_SIZE_X_ARB        0x9195
#define GL_VIRTUAL_PAGE_SIZE_Y_ARB        0x9196
#define GL_VIRTUAL_PAGE_SIZE_Z_ARB        0x9197
#define GL_MAX_SPARSE_TEXTURE_SIZE_ARB    0x9198
#define GL_MAX_SPARSE_3D_TEXTURE_SIZE_ARB 0x9199
#define GL_MAX_SPARSE_ARRAY_TEXTURE_LAYERS_ARB 0x919A
#define GL_SPARSE_TEXTURE_FULL_ARRAY_CUBE_MIPMAPS_ARB 0x91A9
typedef void (APIENTRYP PFNGLTEXPAGECOMMITMENTARBPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glTexPageCommitmentARB (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit);
#endif
#endif /* GL_ARB_sparse_texture */
#ifndef GL_ARB_sparse_texture2
#define GL_ARB_sparse_texture2 1
#endif /* GL_ARB_sparse_texture2 */
#ifndef GL_ARB_sparse_texture_clamp
#define GL_ARB_sparse_texture_clamp 1
#endif /* GL_ARB_sparse_texture_clamp */
#ifndef GL_ARB_spirv_extensions
#define GL_ARB_spirv_extensions 1
#endif /* GL_ARB_spirv_extensions */
#ifndef GL_ARB_stencil_texturing
#define GL_ARB_stencil_texturing 1
#endif /* GL_ARB_stencil_texturing */
#ifndef GL_ARB_sync
#define GL_ARB_sync 1
#endif /* GL_ARB_sync */
#ifndef GL_ARB_tessellation_shader
#define GL_ARB_tessellation_shader 1
#endif /* GL_ARB_tessellation_shader */
#ifndef GL_ARB_texture_barrier
#define GL_ARB_texture_barrier 1
#endif /* GL_ARB_texture_barrier */
#ifndef GL_ARB_texture_border_clamp
#define GL_ARB_texture_border_clamp 1
#define GL_CLAMP_TO_BORDER_ARB            0x812D
#endif /* GL_ARB_texture_border_clamp */
#ifndef GL_ARB_texture_buffer_object
#define GL_ARB_texture_buffer_object 1
#define GL_TEXTURE_BUFFER_ARB             0x8C2A
#define GL_MAX_TEXTURE_BUFFER_SIZE_ARB    0x8C2B
#define GL_TEXTURE_BINDING_BUFFER_ARB     0x8C2C
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING_ARB 0x8C2D
#define GL_TEXTURE_BUFFER_FORMAT_ARB      0x8C2E
typedef void (APIENTRYP PFNGLTEXBUFFERARBPROC) (GLenum target, GLenum internalformat, GLuint buffer);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glTexBufferARB (GLenum target, GLenum internalformat, GLuint buffer);
#endif
#endif /* GL_ARB_texture_buffer_object */
#ifndef GL_ARB_texture_buffer_object_rgb32
#define GL_ARB_texture_buffer_object_rgb32 1
#endif /* GL_ARB_texture_buffer_object_rgb32 */
#ifndef GL_ARB_texture_buffer_range
#define GL_ARB_texture_buffer_range 1
#endif /* GL_ARB_texture_buffer_range */
#ifndef GL_ARB_texture_compression_bptc
#define GL_ARB_texture_compression_bptc 1
#define GL_COMPRESSED_RGBA_BPTC_UNORM_ARB 0x8E8C
#define GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM_ARB 0x8E8D
#define GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT_ARB 0x8E8E
#define GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT_ARB 0x8E8F
#endif /* GL_ARB_texture_compression_bptc */
#ifndef GL_ARB_texture_compression_rgtc
#define GL_ARB_texture_compression_rgtc 1
#endif /* GL_ARB_texture_compression_rgtc */
#ifndef GL_ARB_texture_cube_map_array
#define GL_ARB_texture_cube_map_array 1
#define GL_TEXTURE_CUBE_MAP_ARRAY_ARB     0x9009
#define GL_TEXTURE_BINDING_CUBE_MAP_ARRAY_ARB 0x900A
#define GL_PROXY_TEXTURE_CUBE_MAP_ARRAY_ARB 0x900B
#define GL_SAMPLER_CUBE_MAP_ARRAY_ARB     0x900C
#define GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW_ARB 0x900D
#define GL_INT_SAMPLER_CUBE_MAP_ARRAY_ARB 0x900E
#define GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY_ARB 0x900F
#endif /* GL_ARB_texture_cube_map_array */
#ifndef GL_ARB_texture_filter_anisotropic
#define GL_ARB_texture_filter_anisotropic 1
#endif /* GL_ARB_texture_filter_anisotropic */
#ifndef GL_ARB_texture_filter_minmax
#define GL_ARB_texture_filter_minmax 1
#define GL_TEXTURE_REDUCTION_MODE_ARB     0x9366
#define GL_WEIGHTED_AVERAGE_ARB           0x9367
#endif /* GL_ARB_texture_filter_minmax */
#ifndef GL_ARB_texture_gather
#define GL_ARB_texture_gather 1
#define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET_ARB 0x8E5E
#define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET_ARB 0x8E5F
#define GL_MAX_PROGRAM_TEXTURE_GATHER_COMPONENTS_ARB 0x8F9F
#endif /* GL_ARB_texture_gather */
#ifndef GL_ARB_texture_mirror_clamp_to_edge
#define GL_ARB_texture_mirror_clamp_to_edge 1
#endif /* GL_ARB_texture_mirror_clamp_to_edge */
#ifndef GL_ARB_texture_mirrored_repeat
#define GL_ARB_texture_mirrored_repeat 1
#define GL_MIRRORED_REPEAT_ARB            0x8370
#endif /* GL_ARB_texture_mirrored_repeat */
#ifndef GL_ARB_texture_multisample
#define GL_ARB_texture_multisample 1
#endif /* GL_ARB_texture_multisample */
#ifndef GL_ARB_texture_non_power_of_two
#define GL_ARB_texture_non_power_of_two 1
#endif /* GL_ARB_texture_non_power_of_two */
#ifndef GL_ARB_texture_query_levels
#define GL_ARB_texture_query_levels 1
#endif /* GL_ARB_texture_query_levels */
#ifndef GL_ARB_texture_query_lod
#define GL_ARB_texture_query_lod 1
#endif /* GL_ARB_texture_query_lod */
#ifndef GL_ARB_texture_rg
#define GL_ARB_texture_rg 1
#endif /* GL_ARB_texture_rg */
#ifndef GL_ARB_texture_rgb10_a2ui
#define GL_ARB_texture_rgb10_a2ui 1
#endif /* GL_ARB_texture_rgb10_a2ui */
#ifndef GL_ARB_texture_stencil8
#define GL_ARB_texture_stencil8 1
#endif /* GL_ARB_texture_stencil8 */
#ifndef GL_ARB_texture_storage
#define GL_ARB_texture_storage 1
#endif /* GL_ARB_texture_storage */
#ifndef GL_ARB_texture_storage_multisample
#define GL_ARB_texture_storage_multisample 1
#endif /* GL_ARB_texture_storage_multisample */
#ifndef GL_ARB_texture_swizzle
#define GL_ARB_texture_swizzle 1
#endif /* GL_ARB_texture_swizzle */
#ifndef GL_ARB_texture_view
#define GL_ARB_texture_view 1
#endif /* GL_ARB_texture_view */
#ifndef GL_ARB_timer_query
#define GL_ARB_timer_query 1
#endif /* GL_ARB_timer_query */
#ifndef GL_ARB_transform_feedback2
#define GL_ARB_transform_feedback2 1
#endif /* GL_ARB_transform_feedback2 */
#ifndef GL_ARB_transform_feedback3
#define GL_ARB_transform_feedback3 1
#endif /* GL_ARB_transform_feedback3 */
#ifndef GL_ARB_transform_feedback_instanced
#define GL_ARB_transform_feedback_instanced 1
#endif /* GL_ARB_transform_feedback_instanced */
#ifndef GL_ARB_transform_feedback_overflow_query
#define GL_ARB_transform_feedback_overflow_query 1
#define GL_TRANSFORM_FEEDBACK_OVERFLOW_ARB 0x82EC
#define GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW_ARB 0x82ED
#endif /* GL_ARB_transform_feedback_overflow_query */
#ifndef GL_ARB_uniform_buffer_object
#define GL_ARB_uniform_buffer_object 1
#endif /* GL_ARB_uniform_buffer_object */
#ifndef GL_ARB_vertex_array_bgra
#define GL_ARB_vertex_array_bgra 1
#endif /* GL_ARB_vertex_array_bgra */
#ifndef GL_ARB_vertex_array_object
#define GL_ARB_vertex_array_object 1
#endif /* GL_ARB_vertex_array_object */
#ifndef GL_ARB_vertex_attrib_64bit
#define GL_ARB_vertex_attrib_64bit 1
#endif /* GL_ARB_vertex_attrib_64bit */
#ifndef GL_ARB_vertex_attrib_binding
#define GL_ARB_vertex_attrib_binding 1
#endif /* GL_ARB_vertex_attrib_binding */
#ifndef GL_ARB_vertex_type_10f_11f_11f_rev
#define GL_ARB_vertex_type_10f_11f_11f_rev 1
#endif /* GL_ARB_vertex_type_10f_11f_11f_rev */
#ifndef GL_ARB_vertex_type_2_10_10_10_rev
#define GL_ARB_vertex_type_2_10_10_10_rev 1
#endif /* GL_ARB_vertex_type_2_10_10_10_rev */
#ifndef GL_ARB_viewport_array
#define GL_ARB_viewport_array 1
typedef void (APIENTRYP PFNGLDEPTHRANGEARRAYDVNVPROC) (GLuint first, GLsizei count, const GLdouble *v);
typedef void (APIENTRYP PFNGLDEPTHRANGEINDEXEDDNVPROC) (GLuint index, GLdouble n, GLdouble f);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glDepthRangeArraydvNV (GLuint first, GLsizei count, const GLdouble *v);
GLAPI void APIENTRY glDepthRangeIndexeddNV (GLuint index, GLdouble n, GLdouble f);
#endif
#endif /* GL_ARB_viewport_array */
#ifndef GL_KHR_blend_equation_advanced
#define GL_KHR_blend_equation_advanced 1
#define GL_MULTIPLY_KHR                   0x9294
#define GL_SCREEN_KHR                     0x9295
#define GL_OVERLAY_KHR                    0x9296
#define GL_DARKEN_KHR                     0x9297
#define GL_LIGHTEN_KHR                    0x9298
#define GL_COLORDODGE_KHR                 0x9299
#define GL_COLORBURN_KHR                  0x929A
#define GL_HARDLIGHT_KHR                  0x929B
#define GL_SOFTLIGHT_KHR                  0x929C
#define GL_DIFFERENCE_KHR                 0x929E
#define GL_EXCLUSION_KHR                  0x92A0
#define GL_HSL_HUE_KHR                    0x92AD
#define GL_HSL_SATURATION_KHR             0x92AE
#define GL_HSL_COLOR_KHR                  0x92AF
#define GL_HSL_LUMINOSITY_KHR             0x92B0
typedef void (APIENTRYP PFNGLBLENDBARRIERKHRPROC) (void);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glBlendBarrierKHR (void);
#endif
#endif /* GL_KHR_blend_equation_advanced */
#ifndef GL_KHR_blend_equation_advanced_coherent
#define GL_KHR_blend_equation_advanced_coherent 1
#define GL_BLEND_ADVANCED_COHERENT_KHR    0x9285
#endif /* GL_KHR_blend_equation_advanced_coherent */
#ifndef GL_KHR_context_flush_control
#define GL_KHR_context_flush_control 1
#endif /* GL_KHR_context_flush_control */
#ifndef GL_KHR_debug
#define GL_KHR_debug 1
#endif /* GL_KHR_debug */
#ifndef GL_KHR_no_error
#define GL_KHR_no_error 1
#define GL_CONTEXT_FLAG_NO_ERROR_BIT_KHR  0x00000008
#endif /* GL_KHR_no_error */
#ifndef GL_KHR_parallel_shader_compile
#define GL_KHR_parallel_shader_compile 1
#define GL_MAX_SHADER_COMPILER_THREADS_KHR 0x91B0
#define GL_COMPLETION_STATUS_KHR          0x91B1
typedef void (APIENTRYP PFNGLMAXSHADERCOMPILERTHREADSKHRPROC) (GLuint count);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glMaxShaderCompilerThreadsKHR (GLuint count);
#endif
#endif /* GL_KHR_parallel_shader_compile */
#ifndef GL_KHR_robust_buffer_access_behavior
#define GL_KHR_robust_buffer_access_behavior 1
#endif /* GL_KHR_robust_buffer_access_behavior */
#ifndef GL_KHR_robustness
#define GL_KHR_robustness 1
#define GL_CONTEXT_ROBUST_ACCESS          0x90F3
#endif /* GL_KHR_robustness */
#ifndef GL_KHR_shader_subgroup
#define GL_KHR_shader_subgroup 1
#define GL_SUBGROUP_SIZE_KHR              0x9532
#define GL_SUBGROUP_SUPPORTED_STAGES_KHR  0x9533
#define GL_SUBGROUP_SUPPORTED_FEATURES_KHR 0x9534
#define GL_SUBGROUP_QUAD_ALL_STAGES_KHR   0x9535
#define GL_SUBGROUP_FEATURE_BASIC_BIT_KHR 0x00000001
#define GL_SUBGROUP_FEATURE_VOTE_BIT_KHR  0x00000002
#define GL_SUBGROUP_FEATURE_ARITHMETIC_BIT_KHR 0x00000004
#define GL_SUBGROUP_FEATURE_BALLOT_BIT_KHR 0x00000008
#define GL_SUBGROUP_FEATURE_SHUFFLE_BIT_KHR 0x00000010
#define GL_SUBGROUP_FEATURE_SHUFFLE_RELATIVE_BIT_KHR 0x00000020
#define GL_SUBGROUP_FEATURE_CLUSTERED_BIT_KHR 0x00000040
#define GL_SUBGROUP_FEATURE_QUAD_BIT_KHR  0x00000080
#endif /* GL_KHR_shader_subgroup */
#ifndef GL_KHR_texture_compression_astc_hdr
#define GL_KHR_texture_compression_astc_hdr 1
#define GL_COMPRESSED_RGBA_ASTC_4x4_KHR   0x93B0
#define GL_COMPRESSED_RGBA_ASTC_5x4_KHR   0x93B1
#define GL_COMPRESSED_RGBA_ASTC_5x5_KHR   0x93B2
#define GL_COMPRESSED_RGBA_ASTC_6x5_KHR   0x93B3
#define GL_COMPRESSED_RGBA_ASTC_6x6_KHR   0x93B4
#define GL_COMPRESSED_RGBA_ASTC_8x5_KHR   0x93B5
#define GL_COMPRESSED_RGBA_ASTC_8x6_KHR   0x93B6
#define GL_COMPRESSED_RGBA_ASTC_8x8_KHR   0x93B7
#define GL_COMPRESSED_RGBA_ASTC_10x5_KHR  0x93B8
#define GL_COMPRESSED_RGBA_ASTC_10x6_KHR  0x93B9
#define GL_COMPRESSED_RGBA_ASTC_10x8_KHR  0x93BA
#define GL_COMPRESSED_RGBA_ASTC_10x10_KHR 0x93BB
#define GL_COMPRESSED_RGBA_ASTC_12x10_KHR 0x93BC
#define GL_COMPRESSED_RGBA_ASTC_12x12_KHR 0x93BD
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_4x4_KHR 0x93D0
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x4_KHR 0x93D1
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x5_KHR 0x93D2
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x5_KHR 0x93D3
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x6_KHR 0x93D4
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x5_KHR 0x93D5
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x6_KHR 0x93D6
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x8_KHR 0x93D7
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x5_KHR 0x93D8
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x6_KHR 0x93D9
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x8_KHR 0x93DA
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x10_KHR 0x93DB
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x10_KHR 0x93DC
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x12_KHR 0x93DD
#endif /* GL_KHR_texture_compression_astc_hdr */
#ifndef GL_KHR_texture_compression_astc_ldr
#define GL_KHR_texture_compression_astc_ldr 1
#endif /* GL_KHR_texture_compression_astc_ldr */
#ifndef GL_KHR_texture_compression_astc_sliced_3d
#define GL_KHR_texture_compression_astc_sliced_3d 1
#endif /* GL_KHR_texture_compression_astc_sliced_3d */
#ifndef GL_AMD_framebuffer_multisample_advanced
#define GL_AMD_framebuffer_multisample_advanced 1
#define GL_RENDERBUFFER_STORAGE_SAMPLES_AMD 0x91B2
#define GL_MAX_COLOR_FRAMEBUFFER_SAMPLES_AMD 0x91B3
#define GL_MAX_COLOR_FRAMEBUFFER_STORAGE_SAMPLES_AMD 0x91B4
#define GL_MAX_DEPTH_STENCIL_FRAMEBUFFER_SAMPLES_AMD 0x91B5
#define GL_NUM_SUPPORTED_MULTISAMPLE_MODES_AMD 0x91B6
#define GL_SUPPORTED_MULTISAMPLE_MODES_AMD 0x91B7
typedef void (APIENTRYP PFNGLRENDERBUFFERSTORAGEMULTISAMPLEADVANCEDAMDPROC) (GLenum target, GLsizei samples, GLsizei storageSamples, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEADVANCEDAMDPROC) (GLuint renderbuffer, GLsizei samples, GLsizei storageSamples, GLenum internalformat, GLsizei width, GLsizei height);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glRenderbufferStorageMultisampleAdvancedAMD (GLenum target, GLsizei samples, GLsizei storageSamples, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI void APIENTRY glNamedRenderbufferStorageMultisampleAdvancedAMD (GLuint renderbuffer, GLsizei samples, GLsizei storageSamples, GLenum internalformat, GLsizei width, GLsizei height);
#endif
#endif /* GL_AMD_framebuffer_multisample_advanced */
#ifndef GL_AMD_performance_monitor
#define GL_AMD_performance_monitor 1
#define GL_COUNTER_TYPE_AMD               0x8BC0
#define GL_COUNTER_RANGE_AMD              0x8BC1
#define GL_UNSIGNED_INT64_AMD             0x8BC2
#define GL_PERCENTAGE_AMD                 0x8BC3
#define GL_PERFMON_RESULT_AVAILABLE_AMD   0x8BC4
#define GL_PERFMON_RESULT_SIZE_AMD        0x8BC5
#define GL_PERFMON_RESULT_AMD             0x8BC6
typedef void (APIENTRYP PFNGLGETPERFMONITORGROUPSAMDPROC) (GLint *numGroups, GLsizei groupsSize, GLuint *groups);
typedef void (APIENTRYP PFNGLGETPERFMONITORCOUNTERSAMDPROC) (GLuint group, GLint *numCounters, GLint *maxActiveCounters, GLsizei counterSize, GLuint *counters);
typedef void (APIENTRYP PFNGLGETPERFMONITORGROUPSTRINGAMDPROC) (GLuint group, GLsizei bufSize, GLsizei *length, GLchar *groupString);
typedef void (APIENTRYP PFNGLGETPERFMONITORCOUNTERSTRINGAMDPROC) (GLuint group, GLuint counter, GLsizei bufSize, GLsizei *length, GLchar *counterString);
typedef void (APIENTRYP PFNGLGETPERFMONITORCOUNTERINFOAMDPROC) (GLuint group, GLuint counter, GLenum pname, void *data);
typedef void (APIENTRYP PFNGLGENPERFMONITORSAMDPROC) (GLsizei n, GLuint *monitors);
typedef void (APIENTRYP PFNGLDELETEPERFMONITORSAMDPROC) (GLsizei n, GLuint *monitors);
typedef void (APIENTRYP PFNGLSELECTPERFMONITORCOUNTERSAMDPROC) (GLuint monitor, GLboolean enable, GLuint group, GLint numCounters, GLuint *counterList);
typedef void (APIENTRYP PFNGLBEGINPERFMONITORAMDPROC) (GLuint monitor);
typedef void (APIENTRYP PFNGLENDPERFMONITORAMDPROC) (GLuint monitor);
typedef void (APIENTRYP PFNGLGETPERFMONITORCOUNTERDATAAMDPROC) (GLuint monitor, GLenum pname, GLsizei dataSize, GLuint *data, GLint *bytesWritten);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glGetPerfMonitorGroupsAMD (GLint *numGroups, GLsizei groupsSize, GLuint *groups);
GLAPI void APIENTRY glGetPerfMonitorCountersAMD (GLuint group, GLint *numCounters, GLint *maxActiveCounters, GLsizei counterSize, GLuint *counters);
GLAPI void APIENTRY glGetPerfMonitorGroupStringAMD (GLuint group, GLsizei bufSize, GLsizei *length, GLchar *groupString);
GLAPI void APIENTRY glGetPerfMonitorCounterStringAMD (GLuint group, GLuint counter, GLsizei bufSize, GLsizei *length, GLchar *counterString);
GLAPI void APIENTRY glGetPerfMonitorCounterInfoAMD (GLuint group, GLuint counter, GLenum pname, void *data);
GLAPI void APIENTRY glGenPerfMonitorsAMD (GLsizei n, GLuint *monitors);
GLAPI void APIENTRY glDeletePerfMonitorsAMD (GLsizei n, GLuint *monitors);
GLAPI void APIENTRY glSelectPerfMonitorCountersAMD (GLuint monitor, GLboolean enable, GLuint group, GLint numCounters, GLuint *counterList);
GLAPI void APIENTRY glBeginPerfMonitorAMD (GLuint monitor);
GLAPI void APIENTRY glEndPerfMonitorAMD (GLuint monitor);
GLAPI void APIENTRY glGetPerfMonitorCounterDataAMD (GLuint monitor, GLenum pname, GLsizei dataSize, GLuint *data, GLint *bytesWritten);
#endif
#endif /* GL_AMD_performance_monitor */
#ifndef GL_APPLE_rgb_422
#define GL_APPLE_rgb_422 1
#define GL_RGB_422_APPLE                  0x8A1F
#define GL_UNSIGNED_SHORT_8_8_APPLE       0x85BA
#define GL_UNSIGNED_SHORT_8_8_REV_APPLE   0x85BB
#define GL_RGB_RAW_422_APPLE              0x8A51
#endif /* GL_APPLE_rgb_422 */
#ifndef GL_EXT_EGL_image_storage
#define GL_EXT_EGL_image_storage 1
typedef void *GLeglImageOES;
typedef void (APIENTRYP PFNGLEGLIMAGETARGETTEXSTORAGEEXTPROC) (GLenum target, GLeglImageOES image, const GLint* attrib_list);
typedef void (APIENTRYP PFNGLEGLIMAGETARGETTEXTURESTORAGEEXTPROC) (GLuint texture, GLeglImageOES image, const GLint* attrib_list);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glEGLImageTargetTexStorageEXT (GLenum target, GLeglImageOES image, const GLint* attrib_list);
GLAPI void APIENTRY glEGLImageTargetTextureStorageEXT (GLuint texture, GLeglImageOES image, const GLint* attrib_list);
#endif
#endif /* GL_EXT_EGL_image_storage */
#ifndef GL_EXT_EGL_sync
#define GL_EXT_EGL_sync 1
#endif /* GL_EXT_EGL_sync */
#ifndef GL_EXT_debug_label
#define GL_EXT_debug_label 1
#define GL_PROGRAM_PIPELINE_OBJECT_EXT    0x8A4F
#define GL_PROGRAM_OBJECT_EXT             0x8B40
#define GL_SHADER_OBJECT_EXT              0x8B48
#define GL_BUFFER_OBJECT_EXT              0x9151
#define GL_QUERY_OBJECT_EXT               0x9153
#define GL_VERTEX_ARRAY_OBJECT_EXT        0x9154
typedef void (APIENTRYP PFNGLLABELOBJECTEXTPROC) (GLenum type, GLuint object, GLsizei length, const GLchar *label);
typedef void (APIENTRYP PFNGLGETOBJECTLABELEXTPROC) (GLenum type, GLuint object, GLsizei bufSize, GLsizei *length, GLchar *label);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glLabelObjectEXT (GLenum type, GLuint object, GLsizei length, const GLchar *label);
GLAPI void APIENTRY glGetObjectLabelEXT (GLenum type, GLuint object, GLsizei bufSize, GLsizei *length, GLchar *label);
#endif
#endif /* GL_EXT_debug_label */
#ifndef GL_EXT_debug_marker
#define GL_EXT_debug_marker 1
typedef void (APIENTRYP PFNGLINSERTEVENTMARKEREXTPROC) (GLsizei length, const GLchar *marker);
typedef void (APIENTRYP PFNGLPUSHGROUPMARKEREXTPROC) (GLsizei length, const GLchar *marker);
typedef void (APIENTRYP PFNGLPOPGROUPMARKEREXTPROC) (void);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glInsertEventMarkerEXT (GLsizei length, const GLchar *marker);
GLAPI void APIENTRY glPushGroupMarkerEXT (GLsizei length, const GLchar *marker);
GLAPI void APIENTRY glPopGroupMarkerEXT (void);
#endif
#endif /* GL_EXT_debug_marker */
#ifndef GL_EXT_direct_state_access
#define GL_EXT_direct_state_access 1
#define GL_PROGRAM_MATRIX_EXT             0x8E2D
#define GL_TRANSPOSE_PROGRAM_MATRIX_EXT   0x8E2E
#define GL_PROGRAM_MATRIX_STACK_DEPTH_EXT 0x8E2F
typedef void (APIENTRYP PFNGLMATRIXLOADFEXTPROC) (GLenum mode, const GLfloat *m);
typedef void (APIENTRYP PFNGLMATRIXLOADDEXTPROC) (GLenum mode, const GLdouble *m);
typedef void (APIENTRYP PFNGLMATRIXMULTFEXTPROC) (GLenum mode, const GLfloat *m);
typedef void (APIENTRYP PFNGLMATRIXMULTDEXTPROC) (GLenum mode, const GLdouble *m);
typedef void (APIENTRYP PFNGLMATRIXLOADIDENTITYEXTPROC) (GLenum mode);
typedef void (APIENTRYP PFNGLMATRIXROTATEFEXTPROC) (GLenum mode, GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLMATRIXROTATEDEXTPROC) (GLenum mode, GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLMATRIXSCALEFEXTPROC) (GLenum mode, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLMATRIXSCALEDEXTPROC) (GLenum mode, GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLMATRIXTRANSLATEFEXTPROC) (GLenum mode, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLMATRIXTRANSLATEDEXTPROC) (GLenum mode, GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLMATRIXFRUSTUMEXTPROC) (GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
typedef void (APIENTRYP PFNGLMATRIXORTHOEXTPROC) (GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
typedef void (APIENTRYP PFNGLMATRIXPOPEXTPROC) (GLenum mode);
typedef void (APIENTRYP PFNGLMATRIXPUSHEXTPROC) (GLenum mode);
typedef void (APIENTRYP PFNGLCLIENTATTRIBDEFAULTEXTPROC) (GLbitfield mask);
typedef void (APIENTRYP PFNGLPUSHCLIENTATTRIBDEFAULTEXTPROC) (GLbitfield mask);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERFEXTPROC) (GLuint texture, GLenum target, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERFVEXTPROC) (GLuint texture, GLenum target, GLenum pname, const GLfloat *params);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIEXTPROC) (GLuint texture, GLenum target, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIVEXTPROC) (GLuint texture, GLenum target, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLTEXTUREIMAGE1DEXTPROC) (GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLTEXTUREIMAGE2DEXTPROC) (GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE1DEXTPROC) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE2DEXTPROC) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLCOPYTEXTUREIMAGE1DEXTPROC) (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
typedef void (APIENTRYP PFNGLCOPYTEXTUREIMAGE2DEXTPROC) (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE1DEXTPROC) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE2DEXTPROC) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLGETTEXTUREIMAGEEXTPROC) (GLuint texture, GLenum target, GLint level, GLenum format, GLenum type, void *pixels);
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERFVEXTPROC) (GLuint texture, GLenum target, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIVEXTPROC) (GLuint texture, GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETTEXTURELEVELPARAMETERFVEXTPROC) (GLuint texture, GLenum target, GLint level, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETTEXTURELEVELPARAMETERIVEXTPROC) (GLuint texture, GLenum target, GLint level, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLTEXTUREIMAGE3DEXTPROC) (GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE3DEXTPROC) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE3DEXTPROC) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLBINDMULTITEXTUREEXTPROC) (GLenum texunit, GLenum target, GLuint texture);
typedef void (APIENTRYP PFNGLMULTITEXCOORDPOINTEREXTPROC) (GLenum texunit, GLint size, GLenum type, GLsizei stride, const void *pointer);
typedef void (APIENTRYP PFNGLMULTITEXENVFEXTPROC) (GLenum texunit, GLenum target, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLMULTITEXENVFVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, const GLfloat *params);
typedef void (APIENTRYP PFNGLMULTITEXENVIEXTPROC) (GLenum texunit, GLenum target, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLMULTITEXENVIVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLMULTITEXGENDEXTPROC) (GLenum texunit, GLenum coord, GLenum pname, GLdouble param);
typedef void (APIENTRYP PFNGLMULTITEXGENDVEXTPROC) (GLenum texunit, GLenum coord, GLenum pname, const GLdouble *params);
typedef void (APIENTRYP PFNGLMULTITEXGENFEXTPROC) (GLenum texunit, GLenum coord, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLMULTITEXGENFVEXTPROC) (GLenum texunit, GLenum coord, GLenum pname, const GLfloat *params);
typedef void (APIENTRYP PFNGLMULTITEXGENIEXTPROC) (GLenum texunit, GLenum coord, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLMULTITEXGENIVEXTPROC) (GLenum texunit, GLenum coord, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLGETMULTITEXENVFVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETMULTITEXENVIVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETMULTITEXGENDVEXTPROC) (GLenum texunit, GLenum coord, GLenum pname, GLdouble *params);
typedef void (APIENTRYP PFNGLGETMULTITEXGENFVEXTPROC) (GLenum texunit, GLenum coord, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETMULTITEXGENIVEXTPROC) (GLenum texunit, GLenum coord, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLMULTITEXPARAMETERIEXTPROC) (GLenum texunit, GLenum target, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLMULTITEXPARAMETERIVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLMULTITEXPARAMETERFEXTPROC) (GLenum texunit, GLenum target, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLMULTITEXPARAMETERFVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, const GLfloat *params);
typedef void (APIENTRYP PFNGLMULTITEXIMAGE1DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLMULTITEXIMAGE2DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLMULTITEXSUBIMAGE1DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLMULTITEXSUBIMAGE2DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLCOPYMULTITEXIMAGE1DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
typedef void (APIENTRYP PFNGLCOPYMULTITEXIMAGE2DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
typedef void (APIENTRYP PFNGLCOPYMULTITEXSUBIMAGE1DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
typedef void (APIENTRYP PFNGLCOPYMULTITEXSUBIMAGE2DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLGETMULTITEXIMAGEEXTPROC) (GLenum texunit, GLenum target, GLint level, GLenum format, GLenum type, void *pixels);
typedef void (APIENTRYP PFNGLGETMULTITEXPARAMETERFVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETMULTITEXPARAMETERIVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETMULTITEXLEVELPARAMETERFVEXTPROC) (GLenum texunit, GLenum target, GLint level, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETMULTITEXLEVELPARAMETERIVEXTPROC) (GLenum texunit, GLenum target, GLint level, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLMULTITEXIMAGE3DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLMULTITEXSUBIMAGE3DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLCOPYMULTITEXSUBIMAGE3DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLENABLECLIENTSTATEINDEXEDEXTPROC) (GLenum array, GLuint index);
typedef void (APIENTRYP PFNGLDISABLECLIENTSTATEINDEXEDEXTPROC) (GLenum array, GLuint index);
typedef void (APIENTRYP PFNGLGETFLOATINDEXEDVEXTPROC) (GLenum target, GLuint index, GLfloat *data);
typedef void (APIENTRYP PFNGLGETDOUBLEINDEXEDVEXTPROC) (GLenum target, GLuint index, GLdouble *data);
typedef void (APIENTRYP PFNGLGETPOINTERINDEXEDVEXTPROC) (GLenum target, GLuint index, void **data);
typedef void (APIENTRYP PFNGLENABLEINDEXEDEXTPROC) (GLenum target, GLuint index);
typedef void (APIENTRYP PFNGLDISABLEINDEXEDEXTPROC) (GLenum target, GLuint index);
typedef GLboolean (APIENTRYP PFNGLISENABLEDINDEXEDEXTPROC) (GLenum target, GLuint index);
typedef void (APIENTRYP PFNGLGETINTEGERINDEXEDVEXTPROC) (GLenum target, GLuint index, GLint *data);
typedef void (APIENTRYP PFNGLGETBOOLEANINDEXEDVEXTPROC) (GLenum target, GLuint index, GLboolean *data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTUREIMAGE3DEXTPROC) (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *bits);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTUREIMAGE2DEXTPROC) (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *bits);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTUREIMAGE1DEXTPROC) (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *bits);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE3DEXTPROC) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *bits);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE2DEXTPROC) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *bits);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE1DEXTPROC) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *bits);
typedef void (APIENTRYP PFNGLGETCOMPRESSEDTEXTUREIMAGEEXTPROC) (GLuint texture, GLenum target, GLint lod, void *img);
typedef void (APIENTRYP PFNGLCOMPRESSEDMULTITEXIMAGE3DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *bits);
typedef void (APIENTRYP PFNGLCOMPRESSEDMULTITEXIMAGE2DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *bits);
typedef void (APIENTRYP PFNGLCOMPRESSEDMULTITEXIMAGE1DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *bits);
typedef void (APIENTRYP PFNGLCOMPRESSEDMULTITEXSUBIMAGE3DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *bits);
typedef void (APIENTRYP PFNGLCOMPRESSEDMULTITEXSUBIMAGE2DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *bits);
typedef void (APIENTRYP PFNGLCOMPRESSEDMULTITEXSUBIMAGE1DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *bits);
typedef void (APIENTRYP PFNGLGETCOMPRESSEDMULTITEXIMAGEEXTPROC) (GLenum texunit, GLenum target, GLint lod, void *img);
typedef void (APIENTRYP PFNGLMATRIXLOADTRANSPOSEFEXTPROC) (GLenum mode, const GLfloat *m);
typedef void (APIENTRYP PFNGLMATRIXLOADTRANSPOSEDEXTPROC) (GLenum mode, const GLdouble *m);
typedef void (APIENTRYP PFNGLMATRIXMULTTRANSPOSEFEXTPROC) (GLenum mode, const GLfloat *m);
typedef void (APIENTRYP PFNGLMATRIXMULTTRANSPOSEDEXTPROC) (GLenum mode, const GLdouble *m);
typedef void (APIENTRYP PFNGLNAMEDBUFFERDATAEXTPROC) (GLuint buffer, GLsizeiptr size, const void *data, GLenum usage);
typedef void (APIENTRYP PFNGLNAMEDBUFFERSUBDATAEXTPROC) (GLuint buffer, GLintptr offset, GLsizeiptr size, const void *data);
typedef void *(APIENTRYP PFNGLMAPNAMEDBUFFEREXTPROC) (GLuint buffer, GLenum access);
typedef GLboolean (APIENTRYP PFNGLUNMAPNAMEDBUFFEREXTPROC) (GLuint buffer);
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPARAMETERIVEXTPROC) (GLuint buffer, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPOINTERVEXTPROC) (GLuint buffer, GLenum pname, void **params);
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERSUBDATAEXTPROC) (GLuint buffer, GLintptr offset, GLsizeiptr size, void *data);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1FEXTPROC) (GLuint program, GLint location, GLfloat v0);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2FEXTPROC) (GLuint program, GLint location, GLfloat v0, GLfloat v1);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3FEXTPROC) (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4FEXTPROC) (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1IEXTPROC) (GLuint program, GLint location, GLint v0);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2IEXTPROC) (GLuint program, GLint location, GLint v0, GLint v1);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3IEXTPROC) (GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4IEXTPROC) (GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1FVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2FVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3FVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4FVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1IVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2IVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3IVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4IVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2FVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3FVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4FVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3FVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2FVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4FVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2FVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4FVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3FVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLTEXTUREBUFFEREXTPROC) (GLuint texture, GLenum target, GLenum internalformat, GLuint buffer);
typedef void (APIENTRYP PFNGLMULTITEXBUFFEREXTPROC) (GLenum texunit, GLenum target, GLenum internalformat, GLuint buffer);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIIVEXTPROC) (GLuint texture, GLenum target, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIUIVEXTPROC) (GLuint texture, GLenum target, GLenum pname, const GLuint *params);
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIIVEXTPROC) (GLuint texture, GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIUIVEXTPROC) (GLuint texture, GLenum target, GLenum pname, GLuint *params);
typedef void (APIENTRYP PFNGLMULTITEXPARAMETERIIVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLMULTITEXPARAMETERIUIVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, const GLuint *params);
typedef void (APIENTRYP PFNGLGETMULTITEXPARAMETERIIVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETMULTITEXPARAMETERIUIVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, GLuint *params);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UIEXTPROC) (GLuint program, GLint location, GLuint v0);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UIEXTPROC) (GLuint program, GLint location, GLuint v0, GLuint v1);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UIEXTPROC) (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UIEXTPROC) (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UIVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UIVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UIVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UIVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETERS4FVEXTPROC) (GLuint program, GLenum target, GLuint index, GLsizei count, const GLfloat *params);
typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETERI4IEXTPROC) (GLuint program, GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETERI4IVEXTPROC) (GLuint program, GLenum target, GLuint index, const GLint *params);
typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETERSI4IVEXTPROC) (GLuint program, GLenum target, GLuint index, GLsizei count, const GLint *params);
typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIEXTPROC) (GLuint program, GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIVEXTPROC) (GLuint program, GLenum target, GLuint index, const GLuint *params);
typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETERSI4UIVEXTPROC) (GLuint program, GLenum target, GLuint index, GLsizei count, const GLuint *params);
typedef void (APIENTRYP PFNGLGETNAMEDPROGRAMLOCALPARAMETERIIVEXTPROC) (GLuint program, GLenum target, GLuint index, GLint *params);
typedef void (APIENTRYP PFNGLGETNAMEDPROGRAMLOCALPARAMETERIUIVEXTPROC) (GLuint program, GLenum target, GLuint index, GLuint *params);
typedef void (APIENTRYP PFNGLENABLECLIENTSTATEIEXTPROC) (GLenum array, GLuint index);
typedef void (APIENTRYP PFNGLDISABLECLIENTSTATEIEXTPROC) (GLenum array, GLuint index);
typedef void (APIENTRYP PFNGLGETFLOATI_VEXTPROC) (GLenum pname, GLuint index, GLfloat *params);
typedef void (APIENTRYP PFNGLGETDOUBLEI_VEXTPROC) (GLenum pname, GLuint index, GLdouble *params);
typedef void (APIENTRYP PFNGLGETPOINTERI_VEXTPROC) (GLenum pname, GLuint index, void **params);
typedef void (APIENTRYP PFNGLNAMEDPROGRAMSTRINGEXTPROC) (GLuint program, GLenum target, GLenum format, GLsizei len, const void *string);
typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETER4DEXTPROC) (GLuint program, GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETER4DVEXTPROC) (GLuint program, GLenum target, GLuint index, const GLdouble *params);
typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETER4FEXTPROC) (GLuint program, GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETER4FVEXTPROC) (GLuint program, GLenum target, GLuint index, const GLfloat *params);
typedef void (APIENTRYP PFNGLGETNAMEDPROGRAMLOCALPARAMETERDVEXTPROC) (GLuint program, GLenum target, GLuint index, GLdouble *params);
typedef void (APIENTRYP PFNGLGETNAMEDPROGRAMLOCALPARAMETERFVEXTPROC) (GLuint program, GLenum target, GLuint index, GLfloat *params);
typedef void (APIENTRYP PFNGLGETNAMEDPROGRAMIVEXTPROC) (GLuint program, GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETNAMEDPROGRAMSTRINGEXTPROC) (GLuint program, GLenum target, GLenum pname, void *string);
typedef void (APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEEXTPROC) (GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLGETNAMEDRENDERBUFFERPARAMETERIVEXTPROC) (GLuint renderbuffer, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC) (GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLECOVERAGEEXTPROC) (GLuint renderbuffer, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height);
typedef GLenum (APIENTRYP PFNGLCHECKNAMEDFRAMEBUFFERSTATUSEXTPROC) (GLuint framebuffer, GLenum target);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTURE1DEXTPROC) (GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTURE2DEXTPROC) (GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTURE3DEXTPROC) (GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERRENDERBUFFEREXTPROC) (GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
typedef void (APIENTRYP PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC) (GLuint framebuffer, GLenum attachment, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGENERATETEXTUREMIPMAPEXTPROC) (GLuint texture, GLenum target);
typedef void (APIENTRYP PFNGLGENERATEMULTITEXMIPMAPEXTPROC) (GLenum texunit, GLenum target);
typedef void (APIENTRYP PFNGLFRAMEBUFFERDRAWBUFFEREXTPROC) (GLuint framebuffer, GLenum mode);
typedef void (APIENTRYP PFNGLFRAMEBUFFERDRAWBUFFERSEXTPROC) (GLuint framebuffer, GLsizei n, const GLenum *bufs);
typedef void (APIENTRYP PFNGLFRAMEBUFFERREADBUFFEREXTPROC) (GLuint framebuffer, GLenum mode);
typedef void (APIENTRYP PFNGLGETFRAMEBUFFERPARAMETERIVEXTPROC) (GLuint framebuffer, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLNAMEDCOPYBUFFERSUBDATAEXTPROC) (GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTUREEXTPROC) (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTURELAYEREXTPROC) (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTUREFACEEXTPROC) (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLenum face);
typedef void (APIENTRYP PFNGLTEXTURERENDERBUFFEREXTPROC) (GLuint texture, GLenum target, GLuint renderbuffer);
typedef void (APIENTRYP PFNGLMULTITEXRENDERBUFFEREXTPROC) (GLenum texunit, GLenum target, GLuint renderbuffer);
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXOFFSETEXTPROC) (GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
typedef void (APIENTRYP PFNGLVERTEXARRAYCOLOROFFSETEXTPROC) (GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
typedef void (APIENTRYP PFNGLVERTEXARRAYEDGEFLAGOFFSETEXTPROC) (GLuint vaobj, GLuint buffer, GLsizei stride, GLintptr offset);
typedef void (APIENTRYP PFNGLVERTEXARRAYINDEXOFFSETEXTPROC) (GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
typedef void (APIENTRYP PFNGLVERTEXARRAYNORMALOFFSETEXTPROC) (GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
typedef void (APIENTRYP PFNGLVERTEXARRAYTEXCOORDOFFSETEXTPROC) (GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
typedef void (APIENTRYP PFNGLVERTEXARRAYMULTITEXCOORDOFFSETEXTPROC) (GLuint vaobj, GLuint buffer, GLenum texunit, GLint size, GLenum type, GLsizei stride, GLintptr offset);
typedef void (APIENTRYP PFNGLVERTEXARRAYFOGCOORDOFFSETEXTPROC) (GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
typedef void (APIENTRYP PFNGLVERTEXARRAYSECONDARYCOLOROFFSETEXTPROC) (GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBOFFSETEXTPROC) (GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLintptr offset);
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBIOFFSETEXTPROC) (GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset);
typedef void (APIENTRYP PFNGLENABLEVERTEXARRAYEXTPROC) (GLuint vaobj, GLenum array);
typedef void (APIENTRYP PFNGLDISABLEVERTEXARRAYEXTPROC) (GLuint vaobj, GLenum array);
typedef void (APIENTRYP PFNGLENABLEVERTEXARRAYATTRIBEXTPROC) (GLuint vaobj, GLuint index);
typedef void (APIENTRYP PFNGLDISABLEVERTEXARRAYATTRIBEXTPROC) (GLuint vaobj, GLuint index);
typedef void (APIENTRYP PFNGLGETVERTEXARRAYINTEGERVEXTPROC) (GLuint vaobj, GLenum pname, GLint *param);
typedef void (APIENTRYP PFNGLGETVERTEXARRAYPOINTERVEXTPROC) (GLuint vaobj, GLenum pname, void **param);
typedef void (APIENTRYP PFNGLGETVERTEXARRAYINTEGERI_VEXTPROC) (GLuint vaobj, GLuint index, GLenum pname, GLint *param);
typedef void (APIENTRYP PFNGLGETVERTEXARRAYPOINTERI_VEXTPROC) (GLuint vaobj, GLuint index, GLenum pname, void **param);
typedef void *(APIENTRYP PFNGLMAPNAMEDBUFFERRANGEEXTPROC) (GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
typedef void (APIENTRYP PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEEXTPROC) (GLuint buffer, GLintptr offset, GLsizeiptr length);
typedef void (APIENTRYP PFNGLNAMEDBUFFERSTORAGEEXTPROC) (GLuint buffer, GLsizeiptr size, const void *data, GLbitfield flags);
typedef void (APIENTRYP PFNGLCLEARNAMEDBUFFERDATAEXTPROC) (GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void *data);
typedef void (APIENTRYP PFNGLCLEARNAMEDBUFFERSUBDATAEXTPROC) (GLuint buffer, GLenum internalformat, GLsizeiptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERPARAMETERIEXTPROC) (GLuint framebuffer, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVEXTPROC) (GLuint framebuffer, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1DEXTPROC) (GLuint program, GLint location, GLdouble x);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2DEXTPROC) (GLuint program, GLint location, GLdouble x, GLdouble y);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3DEXTPROC) (GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4DEXTPROC) (GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1DVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2DVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3DVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4DVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2DVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3DVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4DVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3DVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4DVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2DVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4DVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2DVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3DVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLTEXTUREBUFFERRANGEEXTPROC) (GLuint texture, GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE1DEXTPROC) (GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE2DEXTPROC) (GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE3DEXTPROC) (GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE2DMULTISAMPLEEXTPROC) (GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE3DMULTISAMPLEEXTPROC) (GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFNGLVERTEXARRAYBINDVERTEXBUFFEREXTPROC) (GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBFORMATEXTPROC) (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBIFORMATEXTPROC) (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBLFORMATEXTPROC) (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBBINDINGEXTPROC) (GLuint vaobj, GLuint attribindex, GLuint bindingindex);
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXBINDINGDIVISOREXTPROC) (GLuint vaobj, GLuint bindingindex, GLuint divisor);
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBLOFFSETEXTPROC) (GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset);
typedef void (APIENTRYP PFNGLTEXTUREPAGECOMMITMENTEXTPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit);
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBDIVISOREXTPROC) (GLuint vaobj, GLuint index, GLuint divisor);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glMatrixLoadfEXT (GLenum mode, const GLfloat *m);
GLAPI void APIENTRY glMatrixLoaddEXT (GLenum mode, const GLdouble *m);
GLAPI void APIENTRY glMatrixMultfEXT (GLenum mode, const GLfloat *m);
GLAPI void APIENTRY glMatrixMultdEXT (GLenum mode, const GLdouble *m);
GLAPI void APIENTRY glMatrixLoadIdentityEXT (GLenum mode);
GLAPI void APIENTRY glMatrixRotatefEXT (GLenum mode, GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
GLAPI void APIENTRY glMatrixRotatedEXT (GLenum mode, GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
GLAPI void APIENTRY glMatrixScalefEXT (GLenum mode, GLfloat x, GLfloat y, GLfloat z);
GLAPI void APIENTRY glMatrixScaledEXT (GLenum mode, GLdouble x, GLdouble y, GLdouble z);
GLAPI void APIENTRY glMatrixTranslatefEXT (GLenum mode, GLfloat x, GLfloat y, GLfloat z);
GLAPI void APIENTRY glMatrixTranslatedEXT (GLenum mode, GLdouble x, GLdouble y, GLdouble z);
GLAPI void APIENTRY glMatrixFrustumEXT (GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
GLAPI void APIENTRY glMatrixOrthoEXT (GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
GLAPI void APIENTRY glMatrixPopEXT (GLenum mode);
GLAPI void APIENTRY glMatrixPushEXT (GLenum mode);
GLAPI void APIENTRY glClientAttribDefaultEXT (GLbitfield mask);
GLAPI void APIENTRY glPushClientAttribDefaultEXT (GLbitfield mask);
GLAPI void APIENTRY glTextureParameterfEXT (GLuint texture, GLenum target, GLenum pname, GLfloat param);
GLAPI void APIENTRY glTextureParameterfvEXT (GLuint texture, GLenum target, GLenum pname, const GLfloat *params);
GLAPI void APIENTRY glTextureParameteriEXT (GLuint texture, GLenum target, GLenum pname, GLint param);
GLAPI void APIENTRY glTextureParameterivEXT (GLuint texture, GLenum target, GLenum pname, const GLint *params);
GLAPI void APIENTRY glTextureImage1DEXT (GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels);
GLAPI void APIENTRY glTextureImage2DEXT (GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
GLAPI void APIENTRY glTextureSubImage1DEXT (GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
GLAPI void APIENTRY glTextureSubImage2DEXT (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
GLAPI void APIENTRY glCopyTextureImage1DEXT (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
GLAPI void APIENTRY glCopyTextureImage2DEXT (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
GLAPI void APIENTRY glCopyTextureSubImage1DEXT (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
GLAPI void APIENTRY glCopyTextureSubImage2DEXT (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI void APIENTRY glGetTextureImageEXT (GLuint texture, GLenum target, GLint level, GLenum format, GLenum type, void *pixels);
GLAPI void APIENTRY glGetTextureParameterfvEXT (GLuint texture, GLenum target, GLenum pname, GLfloat *params);
GLAPI void APIENTRY glGetTextureParameterivEXT (GLuint texture, GLenum target, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetTextureLevelParameterfvEXT (GLuint texture, GLenum target, GLint level, GLenum pname, GLfloat *params);
GLAPI void APIENTRY glGetTextureLevelParameterivEXT (GLuint texture, GLenum target, GLint level, GLenum pname, GLint *params);
GLAPI void APIENTRY glTextureImage3DEXT (GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
GLAPI void APIENTRY glTextureSubImage3DEXT (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
GLAPI void APIENTRY glCopyTextureSubImage3DEXT (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI void APIENTRY glBindMultiTextureEXT (GLenum texunit, GLenum target, GLuint texture);
GLAPI void APIENTRY glMultiTexCoordPointerEXT (GLenum texunit, GLint size, GLenum type, GLsizei stride, const void *pointer);
GLAPI void APIENTRY glMultiTexEnvfEXT (GLenum texunit, GLenum target, GLenum pname, GLfloat param);
GLAPI void APIENTRY glMultiTexEnvfvEXT (GLenum texunit, GLenum target, GLenum pname, const GLfloat *params);
GLAPI void APIENTRY glMultiTexEnviEXT (GLenum texunit, GLenum target, GLenum pname, GLint param);
GLAPI void APIENTRY glMultiTexEnvivEXT (GLenum texunit, GLenum target, GLenum pname, const GLint *params);
GLAPI void APIENTRY glMultiTexGendEXT (GLenum texunit, GLenum coord, GLenum pname, GLdouble param);
GLAPI void APIENTRY glMultiTexGendvEXT (GLenum texunit, GLenum coord, GLenum pname, const GLdouble *params);
GLAPI void APIENTRY glMultiTexGenfEXT (GLenum texunit, GLenum coord, GLenum pname, GLfloat param);
GLAPI void APIENTRY glMultiTexGenfvEXT (GLenum texunit, GLenum coord, GLenum pname, const GLfloat *params);
GLAPI void APIENTRY glMultiTexGeniEXT (GLenum texunit, GLenum coord, GLenum pname, GLint param);
GLAPI void APIENTRY glMultiTexGenivEXT (GLenum texunit, GLenum coord, GLenum pname, const GLint *params);
GLAPI void APIENTRY glGetMultiTexEnvfvEXT (GLenum texunit, GLenum target, GLenum pname, GLfloat *params);
GLAPI void APIENTRY glGetMultiTexEnvivEXT (GLenum texunit, GLenum target, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetMultiTexGendvEXT (GLenum texunit, GLenum coord, GLenum pname, GLdouble *params);
GLAPI void APIENTRY glGetMultiTexGenfvEXT (GLenum texunit, GLenum coord, GLenum pname, GLfloat *params);
GLAPI void APIENTRY glGetMultiTexGenivEXT (GLenum texunit, GLenum coord, GLenum pname, GLint *params);
GLAPI void APIENTRY glMultiTexParameteriEXT (GLenum texunit, GLenum target, GLenum pname, GLint param);
GLAPI void APIENTRY glMultiTexParameterivEXT (GLenum texunit, GLenum target, GLenum pname, const GLint *params);
GLAPI void APIENTRY glMultiTexParameterfEXT (GLenum texunit, GLenum target, GLenum pname, GLfloat param);
GLAPI void APIENTRY glMultiTexParameterfvEXT (GLenum texunit, GLenum target, GLenum pname, const GLfloat *params);
GLAPI void APIENTRY glMultiTexImage1DEXT (GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels);
GLAPI void APIENTRY glMultiTexImage2DEXT (GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
GLAPI void APIENTRY glMultiTexSubImage1DEXT (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
GLAPI void APIENTRY glMultiTexSubImage2DEXT (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
GLAPI void APIENTRY glCopyMultiTexImage1DEXT (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
GLAPI void APIENTRY glCopyMultiTexImage2DEXT (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
GLAPI void APIENTRY glCopyMultiTexSubImage1DEXT (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
GLAPI void APIENTRY glCopyMultiTexSubImage2DEXT (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI void APIENTRY glGetMultiTexImageEXT (GLenum texunit, GLenum target, GLint level, GLenum format, GLenum type, void *pixels);
GLAPI void APIENTRY glGetMultiTexParameterfvEXT (GLenum texunit, GLenum target, GLenum pname, GLfloat *params);
GLAPI void APIENTRY glGetMultiTexParameterivEXT (GLenum texunit, GLenum target, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetMultiTexLevelParameterfvEXT (GLenum texunit, GLenum target, GLint level, GLenum pname, GLfloat *params);
GLAPI void APIENTRY glGetMultiTexLevelParameterivEXT (GLenum texunit, GLenum target, GLint level, GLenum pname, GLint *params);
GLAPI void APIENTRY glMultiTexImage3DEXT (GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
GLAPI void APIENTRY glMultiTexSubImage3DEXT (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
GLAPI void APIENTRY glCopyMultiTexSubImage3DEXT (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI void APIENTRY glEnableClientStateIndexedEXT (GLenum array, GLuint index);
GLAPI void APIENTRY glDisableClientStateIndexedEXT (GLenum array, GLuint index);
GLAPI void APIENTRY glGetFloatIndexedvEXT (GLenum target, GLuint index, GLfloat *data);
GLAPI void APIENTRY glGetDoubleIndexedvEXT (GLenum target, GLuint index, GLdouble *data);
GLAPI void APIENTRY glGetPointerIndexedvEXT (GLenum target, GLuint index, void **data);
GLAPI void APIENTRY glEnableIndexedEXT (GLenum target, GLuint index);
GLAPI void APIENTRY glDisableIndexedEXT (GLenum target, GLuint index);
GLAPI GLboolean APIENTRY glIsEnabledIndexedEXT (GLenum target, GLuint index);
GLAPI void APIENTRY glGetIntegerIndexedvEXT (GLenum target, GLuint index, GLint *data);
GLAPI void APIENTRY glGetBooleanIndexedvEXT (GLenum target, GLuint index, GLboolean *data);
GLAPI void APIENTRY glCompressedTextureImage3DEXT (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *bits);
GLAPI void APIENTRY glCompressedTextureImage2DEXT (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *bits);
GLAPI void APIENTRY glCompressedTextureImage1DEXT (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *bits);
GLAPI void APIENTRY glCompressedTextureSubImage3DEXT (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *bits);
GLAPI void APIENTRY glCompressedTextureSubImage2DEXT (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *bits);
GLAPI void APIENTRY glCompressedTextureSubImage1DEXT (GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *bits);
GLAPI void APIENTRY glGetCompressedTextureImageEXT (GLuint texture, GLenum target, GLint lod, void *img);
GLAPI void APIENTRY glCompressedMultiTexImage3DEXT (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *bits);
GLAPI void APIENTRY glCompressedMultiTexImage2DEXT (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *bits);
GLAPI void APIENTRY glCompressedMultiTexImage1DEXT (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *bits);
GLAPI void APIENTRY glCompressedMultiTexSubImage3DEXT (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *bits);
GLAPI void APIENTRY glCompressedMultiTexSubImage2DEXT (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *bits);
GLAPI void APIENTRY glCompressedMultiTexSubImage1DEXT (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *bits);
GLAPI void APIENTRY glGetCompressedMultiTexImageEXT (GLenum texunit, GLenum target, GLint lod, void *img);
GLAPI void APIENTRY glMatrixLoadTransposefEXT (GLenum mode, const GLfloat *m);
GLAPI void APIENTRY glMatrixLoadTransposedEXT (GLenum mode, const GLdouble *m);
GLAPI void APIENTRY glMatrixMultTransposefEXT (GLenum mode, const GLfloat *m);
GLAPI void APIENTRY glMatrixMultTransposedEXT (GLenum mode, const GLdouble *m);
GLAPI void APIENTRY glNamedBufferDataEXT (GLuint buffer, GLsizeiptr size, const void *data, GLenum usage);
GLAPI void APIENTRY glNamedBufferSubDataEXT (GLuint buffer, GLintptr offset, GLsizeiptr size, const void *data);
GLAPI void *APIENTRY glMapNamedBufferEXT (GLuint buffer, GLenum access);
GLAPI GLboolean APIENTRY glUnmapNamedBufferEXT (GLuint buffer);
GLAPI void APIENTRY glGetNamedBufferParameterivEXT (GLuint buffer, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetNamedBufferPointervEXT (GLuint buffer, GLenum pname, void **params);
GLAPI void APIENTRY glGetNamedBufferSubDataEXT (GLuint buffer, GLintptr offset, GLsizeiptr size, void *data);
GLAPI void APIENTRY glProgramUniform1fEXT (GLuint program, GLint location, GLfloat v0);
GLAPI void APIENTRY glProgramUniform2fEXT (GLuint program, GLint location, GLfloat v0, GLfloat v1);
GLAPI void APIENTRY glProgramUniform3fEXT (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
GLAPI void APIENTRY glProgramUniform4fEXT (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
GLAPI void APIENTRY glProgramUniform1iEXT (GLuint program, GLint location, GLint v0);
GLAPI void APIENTRY glProgramUniform2iEXT (GLuint program, GLint location, GLint v0, GLint v1);
GLAPI void APIENTRY glProgramUniform3iEXT (GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
GLAPI void APIENTRY glProgramUniform4iEXT (GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
GLAPI void APIENTRY glProgramUniform1fvEXT (GLuint program, GLint location, GLsizei count, const GLfloat *value);
GLAPI void APIENTRY glProgramUniform2fvEXT (GLuint program, GLint location, GLsizei count, const GLfloat *value);
GLAPI void APIENTRY glProgramUniform3fvEXT (GLuint program, GLint location, GLsizei count, const GLfloat *value);
GLAPI void APIENTRY glProgramUniform4fvEXT (GLuint program, GLint location, GLsizei count, const GLfloat *value);
GLAPI void APIENTRY glProgramUniform1ivEXT (GLuint program, GLint location, GLsizei count, const GLint *value);
GLAPI void APIENTRY glProgramUniform2ivEXT (GLuint program, GLint location, GLsizei count, const GLint *value);
GLAPI void APIENTRY glProgramUniform3ivEXT (GLuint program, GLint location, GLsizei count, const GLint *value);
GLAPI void APIENTRY glProgramUniform4ivEXT (GLuint program, GLint location, GLsizei count, const GLint *value);
GLAPI void APIENTRY glProgramUniformMatrix2fvEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glProgramUniformMatrix3fvEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glProgramUniformMatrix4fvEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glProgramUniformMatrix2x3fvEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glProgramUniformMatrix3x2fvEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glProgramUniformMatrix2x4fvEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glProgramUniformMatrix4x2fvEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glProgramUniformMatrix3x4fvEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glProgramUniformMatrix4x3fvEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glTextureBufferEXT (GLuint texture, GLenum target, GLenum internalformat, GLuint buffer);
GLAPI void APIENTRY glMultiTexBufferEXT (GLenum texunit, GLenum target, GLenum internalformat, GLuint buffer);
GLAPI void APIENTRY glTextureParameterIivEXT (GLuint texture, GLenum target, GLenum pname, const GLint *params);
GLAPI void APIENTRY glTextureParameterIuivEXT (GLuint texture, GLenum target, GLenum pname, const GLuint *params);
GLAPI void APIENTRY glGetTextureParameterIivEXT (GLuint texture, GLenum target, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetTextureParameterIuivEXT (GLuint texture, GLenum target, GLenum pname, GLuint *params);
GLAPI void APIENTRY glMultiTexParameterIivEXT (GLenum texunit, GLenum target, GLenum pname, const GLint *params);
GLAPI void APIENTRY glMultiTexParameterIuivEXT (GLenum texunit, GLenum target, GLenum pname, const GLuint *params);
GLAPI void APIENTRY glGetMultiTexParameterIivEXT (GLenum texunit, GLenum target, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetMultiTexParameterIuivEXT (GLenum texunit, GLenum target, GLenum pname, GLuint *params);
GLAPI void APIENTRY glProgramUniform1uiEXT (GLuint program, GLint location, GLuint v0);
GLAPI void APIENTRY glProgramUniform2uiEXT (GLuint program, GLint location, GLuint v0, GLuint v1);
GLAPI void APIENTRY glProgramUniform3uiEXT (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
GLAPI void APIENTRY glProgramUniform4uiEXT (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
GLAPI void APIENTRY glProgramUniform1uivEXT (GLuint program, GLint location, GLsizei count, const GLuint *value);
GLAPI void APIENTRY glProgramUniform2uivEXT (GLuint program, GLint location, GLsizei count, const GLuint *value);
GLAPI void APIENTRY glProgramUniform3uivEXT (GLuint program, GLint location, GLsizei count, const GLuint *value);
GLAPI void APIENTRY glProgramUniform4uivEXT (GLuint program, GLint location, GLsizei count, const GLuint *value);
GLAPI void APIENTRY glNamedProgramLocalParameters4fvEXT (GLuint program, GLenum target, GLuint index, GLsizei count, const GLfloat *params);
GLAPI void APIENTRY glNamedProgramLocalParameterI4iEXT (GLuint program, GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
GLAPI void APIENTRY glNamedProgramLocalParameterI4ivEXT (GLuint program, GLenum target, GLuint index, const GLint *params);
GLAPI void APIENTRY glNamedProgramLocalParametersI4ivEXT (GLuint program, GLenum target, GLuint index, GLsizei count, const GLint *params);
GLAPI void APIENTRY glNamedProgramLocalParameterI4uiEXT (GLuint program, GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
GLAPI void APIENTRY glNamedProgramLocalParameterI4uivEXT (GLuint program, GLenum target, GLuint index, const GLuint *params);
GLAPI void APIENTRY glNamedProgramLocalParametersI4uivEXT (GLuint program, GLenum target, GLuint index, GLsizei count, const GLuint *params);
GLAPI void APIENTRY glGetNamedProgramLocalParameterIivEXT (GLuint program, GLenum target, GLuint index, GLint *params);
GLAPI void APIENTRY glGetNamedProgramLocalParameterIuivEXT (GLuint program, GLenum target, GLuint index, GLuint *params);
GLAPI void APIENTRY glEnableClientStateiEXT (GLenum array, GLuint index);
GLAPI void APIENTRY glDisableClientStateiEXT (GLenum array, GLuint index);
GLAPI void APIENTRY glGetFloati_vEXT (GLenum pname, GLuint index, GLfloat *params);
GLAPI void APIENTRY glGetDoublei_vEXT (GLenum pname, GLuint index, GLdouble *params);
GLAPI void APIENTRY glGetPointeri_vEXT (GLenum pname, GLuint index, void **params);
GLAPI void APIENTRY glNamedProgramStringEXT (GLuint program, GLenum target, GLenum format, GLsizei len, const void *string);
GLAPI void APIENTRY glNamedProgramLocalParameter4dEXT (GLuint program, GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI void APIENTRY glNamedProgramLocalParameter4dvEXT (GLuint program, GLenum target, GLuint index, const GLdouble *params);
GLAPI void APIENTRY glNamedProgramLocalParameter4fEXT (GLuint program, GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GLAPI void APIENTRY glNamedProgramLocalParameter4fvEXT (GLuint program, GLenum target, GLuint index, const GLfloat *params);
GLAPI void APIENTRY glGetNamedProgramLocalParameterdvEXT (GLuint program, GLenum target, GLuint index, GLdouble *params);
GLAPI void APIENTRY glGetNamedProgramLocalParameterfvEXT (GLuint program, GLenum target, GLuint index, GLfloat *params);
GLAPI void APIENTRY glGetNamedProgramivEXT (GLuint program, GLenum target, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetNamedProgramStringEXT (GLuint program, GLenum target, GLenum pname, void *string);
GLAPI void APIENTRY glNamedRenderbufferStorageEXT (GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI void APIENTRY glGetNamedRenderbufferParameterivEXT (GLuint renderbuffer, GLenum pname, GLint *params);
GLAPI void APIENTRY glNamedRenderbufferStorageMultisampleEXT (GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI void APIENTRY glNamedRenderbufferStorageMultisampleCoverageEXT (GLuint renderbuffer, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI GLenum APIENTRY glCheckNamedFramebufferStatusEXT (GLuint framebuffer, GLenum target);
GLAPI void APIENTRY glNamedFramebufferTexture1DEXT (GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
GLAPI void APIENTRY glNamedFramebufferTexture2DEXT (GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
GLAPI void APIENTRY glNamedFramebufferTexture3DEXT (GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
GLAPI void APIENTRY glNamedFramebufferRenderbufferEXT (GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
GLAPI void APIENTRY glGetNamedFramebufferAttachmentParameterivEXT (GLuint framebuffer, GLenum attachment, GLenum pname, GLint *params);
GLAPI void APIENTRY glGenerateTextureMipmapEXT (GLuint texture, GLenum target);
GLAPI void APIENTRY glGenerateMultiTexMipmapEXT (GLenum texunit, GLenum target);
GLAPI void APIENTRY glFramebufferDrawBufferEXT (GLuint framebuffer, GLenum mode);
GLAPI void APIENTRY glFramebufferDrawBuffersEXT (GLuint framebuffer, GLsizei n, const GLenum *bufs);
GLAPI void APIENTRY glFramebufferReadBufferEXT (GLuint framebuffer, GLenum mode);
GLAPI void APIENTRY glGetFramebufferParameterivEXT (GLuint framebuffer, GLenum pname, GLint *params);
GLAPI void APIENTRY glNamedCopyBufferSubDataEXT (GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
GLAPI void APIENTRY glNamedFramebufferTextureEXT (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
GLAPI void APIENTRY glNamedFramebufferTextureLayerEXT (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
GLAPI void APIENTRY glNamedFramebufferTextureFaceEXT (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLenum face);
GLAPI void APIENTRY glTextureRenderbufferEXT (GLuint texture, GLenum target, GLuint renderbuffer);
GLAPI void APIENTRY glMultiTexRenderbufferEXT (GLenum texunit, GLenum target, GLuint renderbuffer);
GLAPI void APIENTRY glVertexArrayVertexOffsetEXT (GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
GLAPI void APIENTRY glVertexArrayColorOffsetEXT (GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
GLAPI void APIENTRY glVertexArrayEdgeFlagOffsetEXT (GLuint vaobj, GLuint buffer, GLsizei stride, GLintptr offset);
GLAPI void APIENTRY glVertexArrayIndexOffsetEXT (GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
GLAPI void APIENTRY glVertexArrayNormalOffsetEXT (GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
GLAPI void APIENTRY glVertexArrayTexCoordOffsetEXT (GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
GLAPI void APIENTRY glVertexArrayMultiTexCoordOffsetEXT (GLuint vaobj, GLuint buffer, GLenum texunit, GLint size, GLenum type, GLsizei stride, GLintptr offset);
GLAPI void APIENTRY glVertexArrayFogCoordOffsetEXT (GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
GLAPI void APIENTRY glVertexArraySecondaryColorOffsetEXT (GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
GLAPI void APIENTRY glVertexArrayVertexAttribOffsetEXT (GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLintptr offset);
GLAPI void APIENTRY glVertexArrayVertexAttribIOffsetEXT (GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset);
GLAPI void APIENTRY glEnableVertexArrayEXT (GLuint vaobj, GLenum array);
GLAPI void APIENTRY glDisableVertexArrayEXT (GLuint vaobj, GLenum array);
GLAPI void APIENTRY glEnableVertexArrayAttribEXT (GLuint vaobj, GLuint index);
GLAPI void APIENTRY glDisableVertexArrayAttribEXT (GLuint vaobj, GLuint index);
GLAPI void APIENTRY glGetVertexArrayIntegervEXT (GLuint vaobj, GLenum pname, GLint *param);
GLAPI void APIENTRY glGetVertexArrayPointervEXT (GLuint vaobj, GLenum pname, void **param);
GLAPI void APIENTRY glGetVertexArrayIntegeri_vEXT (GLuint vaobj, GLuint index, GLenum pname, GLint *param);
GLAPI void APIENTRY glGetVertexArrayPointeri_vEXT (GLuint vaobj, GLuint index, GLenum pname, void **param);
GLAPI void *APIENTRY glMapNamedBufferRangeEXT (GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
GLAPI void APIENTRY glFlushMappedNamedBufferRangeEXT (GLuint buffer, GLintptr offset, GLsizeiptr length);
GLAPI void APIENTRY glNamedBufferStorageEXT (GLuint buffer, GLsizeiptr size, const void *data, GLbitfield flags);
GLAPI void APIENTRY glClearNamedBufferDataEXT (GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void *data);
GLAPI void APIENTRY glClearNamedBufferSubDataEXT (GLuint buffer, GLenum internalformat, GLsizeiptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
GLAPI void APIENTRY glNamedFramebufferParameteriEXT (GLuint framebuffer, GLenum pname, GLint param);
GLAPI void APIENTRY glGetNamedFramebufferParameterivEXT (GLuint framebuffer, GLenum pname, GLint *params);
GLAPI void APIENTRY glProgramUniform1dEXT (GLuint program, GLint location, GLdouble x);
GLAPI void APIENTRY glProgramUniform2dEXT (GLuint program, GLint location, GLdouble x, GLdouble y);
GLAPI void APIENTRY glProgramUniform3dEXT (GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z);
GLAPI void APIENTRY glProgramUniform4dEXT (GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI void APIENTRY glProgramUniform1dvEXT (GLuint program, GLint location, GLsizei count, const GLdouble *value);
GLAPI void APIENTRY glProgramUniform2dvEXT (GLuint program, GLint location, GLsizei count, const GLdouble *value);
GLAPI void APIENTRY glProgramUniform3dvEXT (GLuint program, GLint location, GLsizei count, const GLdouble *value);
GLAPI void APIENTRY glProgramUniform4dvEXT (GLuint program, GLint location, GLsizei count, const GLdouble *value);
GLAPI void APIENTRY glProgramUniformMatrix2dvEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glProgramUniformMatrix3dvEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glProgramUniformMatrix4dvEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glProgramUniformMatrix2x3dvEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glProgramUniformMatrix2x4dvEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glProgramUniformMatrix3x2dvEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glProgramUniformMatrix3x4dvEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glProgramUniformMatrix4x2dvEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glProgramUniformMatrix4x3dvEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glTextureBufferRangeEXT (GLuint texture, GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
GLAPI void APIENTRY glTextureStorage1DEXT (GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
GLAPI void APIENTRY glTextureStorage2DEXT (GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI void APIENTRY glTextureStorage3DEXT (GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
GLAPI void APIENTRY glTextureStorage2DMultisampleEXT (GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
GLAPI void APIENTRY glTextureStorage3DMultisampleEXT (GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
GLAPI void APIENTRY glVertexArrayBindVertexBufferEXT (GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
GLAPI void APIENTRY glVertexArrayVertexAttribFormatEXT (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
GLAPI void APIENTRY glVertexArrayVertexAttribIFormatEXT (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
GLAPI void APIENTRY glVertexArrayVertexAttribLFormatEXT (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
GLAPI void APIENTRY glVertexArrayVertexAttribBindingEXT (GLuint vaobj, GLuint attribindex, GLuint bindingindex);
GLAPI void APIENTRY glVertexArrayVertexBindingDivisorEXT (GLuint vaobj, GLuint bindingindex, GLuint divisor);
GLAPI void APIENTRY glVertexArrayVertexAttribLOffsetEXT (GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset);
GLAPI void APIENTRY glTexturePageCommitmentEXT (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit);
GLAPI void APIENTRY glVertexArrayVertexAttribDivisorEXT (GLuint vaobj, GLuint index, GLuint divisor);
#endif
#endif /* GL_EXT_direct_state_access */
#ifndef GL_EXT_draw_instanced
#define GL_EXT_draw_instanced 1
typedef void (APIENTRYP PFNGLDRAWARRAYSINSTANCEDEXTPROC) (GLenum mode, GLint start, GLsizei count, GLsizei primcount);
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDEXTPROC) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei primcount);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glDrawArraysInstancedEXT (GLenum mode, GLint start, GLsizei count, GLsizei primcount);
GLAPI void APIENTRY glDrawElementsInstancedEXT (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei primcount);
#endif
#endif /* GL_EXT_draw_instanced */
#ifndef GL_EXT_multiview_tessellation_geometry_shader
#define GL_EXT_multiview_tessellation_geometry_shader 1
#endif /* GL_EXT_multiview_tessellation_geometry_shader */
#ifndef GL_EXT_multiview_texture_multisample
#define GL_EXT_multiview_texture_multisample 1
#endif /* GL_EXT_multiview_texture_multisample */
#ifndef GL_EXT_multiview_timer_query
#define GL_EXT_multiview_timer_query 1
#endif /* GL_EXT_multiview_timer_query */
#ifndef GL_EXT_polygon_offset_clamp
#define GL_EXT_polygon_offset_clamp 1
#define GL_POLYGON_OFFSET_CLAMP_EXT       0x8E1B
typedef void (APIENTRYP PFNGLPOLYGONOFFSETCLAMPEXTPROC) (GLfloat factor, GLfloat units, GLfloat clamp);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glPolygonOffsetClampEXT (GLfloat factor, GLfloat units, GLfloat clamp);
#endif
#endif /* GL_EXT_polygon_offset_clamp */
#ifndef GL_EXT_post_depth_coverage
#define GL_EXT_post_depth_coverage 1
#endif /* GL_EXT_post_depth_coverage */
#ifndef GL_EXT_raster_multisample
#define GL_EXT_raster_multisample 1
#define GL_RASTER_MULTISAMPLE_EXT         0x9327
#define GL_RASTER_SAMPLES_EXT             0x9328
#define GL_MAX_RASTER_SAMPLES_EXT         0x9329
#define GL_RASTER_FIXED_SAMPLE_LOCATIONS_EXT 0x932A
#define GL_MULTISAMPLE_RASTERIZATION_ALLOWED_EXT 0x932B
#define GL_EFFECTIVE_RASTER_SAMPLES_EXT   0x932C
typedef void (APIENTRYP PFNGLRASTERSAMPLESEXTPROC) (GLuint samples, GLboolean fixedsamplelocations);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glRasterSamplesEXT (GLuint samples, GLboolean fixedsamplelocations);
#endif
#endif /* GL_EXT_raster_multisample */
#ifndef GL_EXT_separate_shader_objects
#define GL_EXT_separate_shader_objects 1
#define GL_ACTIVE_PROGRAM_EXT             0x8B8D
typedef void (APIENTRYP PFNGLUSESHADERPROGRAMEXTPROC) (GLenum type, GLuint program);
typedef void (APIENTRYP PFNGLACTIVEPROGRAMEXTPROC) (GLuint program);
typedef GLuint (APIENTRYP PFNGLCREATESHADERPROGRAMEXTPROC) (GLenum type, const GLchar *string);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glUseShaderProgramEXT (GLenum type, GLuint program);
GLAPI void APIENTRY glActiveProgramEXT (GLuint program);
GLAPI GLuint APIENTRY glCreateShaderProgramEXT (GLenum type, const GLchar *string);
#endif
#endif /* GL_EXT_separate_shader_objects */
#ifndef GL_EXT_shader_framebuffer_fetch
#define GL_EXT_shader_framebuffer_fetch 1
#define GL_FRAGMENT_SHADER_DISCARDS_SAMPLES_EXT 0x8A52
#endif /* GL_EXT_shader_framebuffer_fetch */
#ifndef GL_EXT_shader_framebuffer_fetch_non_coherent
#define GL_EXT_shader_framebuffer_fetch_non_coherent 1
typedef void (APIENTRYP PFNGLFRAMEBUFFERFETCHBARRIEREXTPROC) (void);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glFramebufferFetchBarrierEXT (void);
#endif
#endif /* GL_EXT_shader_framebuffer_fetch_non_coherent */
#ifndef GL_EXT_shader_integer_mix
#define GL_EXT_shader_integer_mix 1
#endif /* GL_EXT_shader_integer_mix */
#ifndef GL_EXT_texture_compression_s3tc
#define GL_EXT_texture_compression_s3tc 1
#define GL_COMPRESSED_RGB_S3TC_DXT1_EXT   0x83F0
#define GL_COMPRESSED_RGBA_S3TC_DXT1_EXT  0x83F1
#define GL_COMPRESSED_RGBA_S3TC_DXT3_EXT  0x83F2
#define GL_COMPRESSED_RGBA_S3TC_DXT5_EXT  0x83F3
#endif /* GL_EXT_texture_compression_s3tc */
#ifndef GL_EXT_texture_filter_minmax
#define GL_EXT_texture_filter_minmax 1
#define GL_TEXTURE_REDUCTION_MODE_EXT     0x9366
#define GL_WEIGHTED_AVERAGE_EXT           0x9367
#endif /* GL_EXT_texture_filter_minmax */
#ifndef GL_EXT_texture_sRGB_R8
#define GL_EXT_texture_sRGB_R8 1
#define GL_SR8_EXT                        0x8FBD
#endif /* GL_EXT_texture_sRGB_R8 */
#ifndef GL_EXT_texture_sRGB_RG8
#define GL_EXT_texture_sRGB_RG8 1
#define GL_SRG8_EXT                       0x8FBE
#endif /* GL_EXT_texture_sRGB_RG8 */
#ifndef GL_EXT_texture_sRGB_decode
#define GL_EXT_texture_sRGB_decode 1
#define GL_TEXTURE_SRGB_DECODE_EXT        0x8A48
#define GL_DECODE_EXT                     0x8A49
#define GL_SKIP_DECODE_EXT                0x8A4A
#endif /* GL_EXT_texture_sRGB_decode */
#ifndef GL_EXT_texture_shadow_lod
#define GL_EXT_texture_shadow_lod 1
#endif /* GL_EXT_texture_shadow_lod */
#ifndef GL_EXT_texture_storage
#define GL_EXT_texture_storage 1
#define GL_TEXTURE_IMMUTABLE_FORMAT_EXT   0x912F
#define GL_ALPHA8_EXT                     0x803C
#define GL_LUMINANCE8_EXT                 0x8040
#define GL_LUMINANCE8_ALPHA8_EXT          0x8045
#define GL_RGBA32F_EXT                    0x8814
#define GL_RGB32F_EXT                     0x8815
#define GL_ALPHA32F_EXT                   0x8816
#define GL_LUMINANCE32F_EXT               0x8818
#define GL_LUMINANCE_ALPHA32F_EXT         0x8819
#define GL_RGBA16F_EXT                    0x881A
#define GL_RGB16F_EXT                     0x881B
#define GL_ALPHA16F_EXT                   0x881C
#define GL_LUMINANCE16F_EXT               0x881E
#define GL_LUMINANCE_ALPHA16F_EXT         0x881F
#define GL_RGB10_A2_EXT                   0x8059
#define GL_RGB10_EXT                      0x8052
#define GL_BGRA8_EXT                      0x93A1
#define GL_R8_EXT                         0x8229
#define GL_RG8_EXT                        0x822B
#define GL_R32F_EXT                       0x822E
#define GL_RG32F_EXT                      0x8230
#define GL_R16F_EXT                       0x822D
#define GL_RG16F_EXT                      0x822F
typedef void (APIENTRYP PFNGLTEXSTORAGE1DEXTPROC) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
typedef void (APIENTRYP PFNGLTEXSTORAGE2DEXTPROC) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLTEXSTORAGE3DEXTPROC) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glTexStorage1DEXT (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
GLAPI void APIENTRY glTexStorage2DEXT (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI void APIENTRY glTexStorage3DEXT (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
#endif
#endif /* GL_EXT_texture_storage */
#ifndef GL_EXT_window_rectangles
#define GL_EXT_window_rectangles 1
#define GL_INCLUSIVE_EXT                  0x8F10
#define GL_EXCLUSIVE_EXT                  0x8F11
#define GL_WINDOW_RECTANGLE_EXT           0x8F12
#define GL_WINDOW_RECTANGLE_MODE_EXT      0x8F13
#define GL_MAX_WINDOW_RECTANGLES_EXT      0x8F14
#define GL_NUM_WINDOW_RECTANGLES_EXT      0x8F15
typedef void (APIENTRYP PFNGLWINDOWRECTANGLESEXTPROC) (GLenum mode, GLsizei count, const GLint *box);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glWindowRectanglesEXT (GLenum mode, GLsizei count, const GLint *box);
#endif
#endif /* GL_EXT_window_rectangles */
#ifndef GL_INTEL_blackhole_render
#define GL_INTEL_blackhole_render 1
#define GL_BLACKHOLE_RENDER_INTEL         0x83FC
#endif /* GL_INTEL_blackhole_render */
#ifndef GL_INTEL_conservative_rasterization
#define GL_INTEL_conservative_rasterization 1
#define GL_CONSERVATIVE_RASTERIZATION_INTEL 0x83FE
#endif /* GL_INTEL_conservative_rasterization */
#ifndef GL_INTEL_framebuffer_CMAA
#define GL_INTEL_framebuffer_CMAA 1
typedef void (APIENTRYP PFNGLAPPLYFRAMEBUFFERATTACHMENTCMAAINTELPROC) (void);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glApplyFramebufferAttachmentCMAAINTEL (void);
#endif
#endif /* GL_INTEL_framebuffer_CMAA */
#ifndef GL_INTEL_performance_query
#define GL_INTEL_performance_query 1
#define GL_PERFQUERY_SINGLE_CONTEXT_INTEL 0x00000000
#define GL_PERFQUERY_GLOBAL_CONTEXT_INTEL 0x00000001
#define GL_PERFQUERY_WAIT_INTEL           0x83FB
#define GL_PERFQUERY_FLUSH_INTEL          0x83FA
#define GL_PERFQUERY_DONOT_FLUSH_INTEL    0x83F9
#define GL_PERFQUERY_COUNTER_EVENT_INTEL  0x94F0
#define GL_PERFQUERY_COUNTER_DURATION_NORM_INTEL 0x94F1
#define GL_PERFQUERY_COUNTER_DURATION_RAW_INTEL 0x94F2
#define GL_PERFQUERY_COUNTER_THROUGHPUT_INTEL 0x94F3
#define GL_PERFQUERY_COUNTER_RAW_INTEL    0x94F4
#define GL_PERFQUERY_COUNTER_TIMESTAMP_INTEL 0x94F5
#define GL_PERFQUERY_COUNTER_DATA_UINT32_INTEL 0x94F8
#define GL_PERFQUERY_COUNTER_DATA_UINT64_INTEL 0x94F9
#define GL_PERFQUERY_COUNTER_DATA_FLOAT_INTEL 0x94FA
#define GL_PERFQUERY_COUNTER_DATA_DOUBLE_INTEL 0x94FB
#define GL_PERFQUERY_COUNTER_DATA_BOOL32_INTEL 0x94FC
#define GL_PERFQUERY_QUERY_NAME_LENGTH_MAX_INTEL 0x94FD
#define GL_PERFQUERY_COUNTER_NAME_LENGTH_MAX_INTEL 0x94FE
#define GL_PERFQUERY_COUNTER_DESC_LENGTH_MAX_INTEL 0x94FF
#define GL_PERFQUERY_GPA_EXTENDED_COUNTERS_INTEL 0x9500
typedef void (APIENTRYP PFNGLBEGINPERFQUERYINTELPROC) (GLuint queryHandle);
typedef void (APIENTRYP PFNGLCREATEPERFQUERYINTELPROC) (GLuint queryId, GLuint *queryHandle);
typedef void (APIENTRYP PFNGLDELETEPERFQUERYINTELPROC) (GLuint queryHandle);
typedef void (APIENTRYP PFNGLENDPERFQUERYINTELPROC) (GLuint queryHandle);
typedef void (APIENTRYP PFNGLGETFIRSTPERFQUERYIDINTELPROC) (GLuint *queryId);
typedef void (APIENTRYP PFNGLGETNEXTPERFQUERYIDINTELPROC) (GLuint queryId, GLuint *nextQueryId);
typedef void (APIENTRYP PFNGLGETPERFCOUNTERINFOINTELPROC) (GLuint queryId, GLuint counterId, GLuint counterNameLength, GLchar *counterName, GLuint counterDescLength, GLchar *counterDesc, GLuint *counterOffset, GLuint *counterDataSize, GLuint *counterTypeEnum, GLuint *counterDataTypeEnum, GLuint64 *rawCounterMaxValue);
typedef void (APIENTRYP PFNGLGETPERFQUERYDATAINTELPROC) (GLuint queryHandle, GLuint flags, GLsizei dataSize, void *data, GLuint *bytesWritten);
typedef void (APIENTRYP PFNGLGETPERFQUERYIDBYNAMEINTELPROC) (GLchar *queryName, GLuint *queryId);
typedef void (APIENTRYP PFNGLGETPERFQUERYINFOINTELPROC) (GLuint queryId, GLuint queryNameLength, GLchar *queryName, GLuint *dataSize, GLuint *noCounters, GLuint *noInstances, GLuint *capsMask);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glBeginPerfQueryINTEL (GLuint queryHandle);
GLAPI void APIENTRY glCreatePerfQueryINTEL (GLuint queryId, GLuint *queryHandle);
GLAPI void APIENTRY glDeletePerfQueryINTEL (GLuint queryHandle);
GLAPI void APIENTRY glEndPerfQueryINTEL (GLuint queryHandle);
GLAPI void APIENTRY glGetFirstPerfQueryIdINTEL (GLuint *queryId);
GLAPI void APIENTRY glGetNextPerfQueryIdINTEL (GLuint queryId, GLuint *nextQueryId);
GLAPI void APIENTRY glGetPerfCounterInfoINTEL (GLuint queryId, GLuint counterId, GLuint counterNameLength, GLchar *counterName, GLuint counterDescLength, GLchar *counterDesc, GLuint *counterOffset, GLuint *counterDataSize, GLuint *counterTypeEnum, GLuint *counterDataTypeEnum, GLuint64 *rawCounterMaxValue);
GLAPI void APIENTRY glGetPerfQueryDataINTEL (GLuint queryHandle, GLuint flags, GLsizei dataSize, void *data, GLuint *bytesWritten);
GLAPI void APIENTRY glGetPerfQueryIdByNameINTEL (GLchar *queryName, GLuint *queryId);
GLAPI void APIENTRY glGetPerfQueryInfoINTEL (GLuint queryId, GLuint queryNameLength, GLchar *queryName, GLuint *dataSize, GLuint *noCounters, GLuint *noInstances, GLuint *capsMask);
#endif
#endif /* GL_INTEL_performance_query */
#ifndef GL_MESA_framebuffer_flip_x
#define GL_MESA_framebuffer_flip_x 1
#define GL_FRAMEBUFFER_FLIP_X_MESA        0x8BBC
#endif /* GL_MESA_framebuffer_flip_x */
#ifndef GL_MESA_framebuffer_flip_y
#define GL_MESA_framebuffer_flip_y 1
#define GL_FRAMEBUFFER_FLIP_Y_MESA        0x8BBB
typedef void (APIENTRYP PFNGLFRAMEBUFFERPARAMETERIMESAPROC) (GLenum target, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLGETFRAMEBUFFERPARAMETERIVMESAPROC) (GLenum target, GLenum pname, GLint *params);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glFramebufferParameteriMESA (GLenum target, GLenum pname, GLint param);
GLAPI void APIENTRY glGetFramebufferParameterivMESA (GLenum target, GLenum pname, GLint *params);
#endif
#endif /* GL_MESA_framebuffer_flip_y */
#ifndef GL_MESA_framebuffer_swap_xy
#define GL_MESA_framebuffer_swap_xy 1
#define GL_FRAMEBUFFER_SWAP_XY_MESA       0x8BBD
#endif /* GL_MESA_framebuffer_swap_xy */
#ifndef GL_NV_bindless_multi_draw_indirect
#define GL_NV_bindless_multi_draw_indirect 1
typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSNVPROC) (GLenum mode, const void *indirect, GLsizei drawCount, GLsizei stride, GLint vertexBufferCount);
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSNVPROC) (GLenum mode, GLenum type, const void *indirect, GLsizei drawCount, GLsizei stride, GLint vertexBufferCount);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glMultiDrawArraysIndirectBindlessNV (GLenum mode, const void *indirect, GLsizei drawCount, GLsizei stride, GLint vertexBufferCount);
GLAPI void APIENTRY glMultiDrawElementsIndirectBindlessNV (GLenum mode, GLenum type, const void *indirect, GLsizei drawCount, GLsizei stride, GLint vertexBufferCount);
#endif
#endif /* GL_NV_bindless_multi_draw_indirect */
#ifndef GL_NV_bindless_multi_draw_indirect_count
#define GL_NV_bindless_multi_draw_indirect_count 1
typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSCOUNTNVPROC) (GLenum mode, const void *indirect, GLsizei drawCount, GLsizei maxDrawCount, GLsizei stride, GLint vertexBufferCount);
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSCOUNTNVPROC) (GLenum mode, GLenum type, const void *indirect, GLsizei drawCount, GLsizei maxDrawCount, GLsizei stride, GLint vertexBufferCount);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glMultiDrawArraysIndirectBindlessCountNV (GLenum mode, const void *indirect, GLsizei drawCount, GLsizei maxDrawCount, GLsizei stride, GLint vertexBufferCount);
GLAPI void APIENTRY glMultiDrawElementsIndirectBindlessCountNV (GLenum mode, GLenum type, const void *indirect, GLsizei drawCount, GLsizei maxDrawCount, GLsizei stride, GLint vertexBufferCount);
#endif
#endif /* GL_NV_bindless_multi_draw_indirect_count */
#ifndef GL_NV_bindless_texture
#define GL_NV_bindless_texture 1
typedef GLuint64 (APIENTRYP PFNGLGETTEXTUREHANDLENVPROC) (GLuint texture);
typedef GLuint64 (APIENTRYP PFNGLGETTEXTURESAMPLERHANDLENVPROC) (GLuint texture, GLuint sampler);
typedef void (APIENTRYP PFNGLMAKETEXTUREHANDLERESIDENTNVPROC) (GLuint64 handle);
typedef void (APIENTRYP PFNGLMAKETEXTUREHANDLENONRESIDENTNVPROC) (GLuint64 handle);
typedef GLuint64 (APIENTRYP PFNGLGETIMAGEHANDLENVPROC) (GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format);
typedef void (APIENTRYP PFNGLMAKEIMAGEHANDLERESIDENTNVPROC) (GLuint64 handle, GLenum access);
typedef void (APIENTRYP PFNGLMAKEIMAGEHANDLENONRESIDENTNVPROC) (GLuint64 handle);
typedef void (APIENTRYP PFNGLUNIFORMHANDLEUI64NVPROC) (GLint location, GLuint64 value);
typedef void (APIENTRYP PFNGLUNIFORMHANDLEUI64VNVPROC) (GLint location, GLsizei count, const GLuint64 *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMHANDLEUI64NVPROC) (GLuint program, GLint location, GLuint64 value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMHANDLEUI64VNVPROC) (GLuint program, GLint location, GLsizei count, const GLuint64 *values);
typedef GLboolean (APIENTRYP PFNGLISTEXTUREHANDLERESIDENTNVPROC) (GLuint64 handle);
typedef GLboolean (APIENTRYP PFNGLISIMAGEHANDLERESIDENTNVPROC) (GLuint64 handle);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI GLuint64 APIENTRY glGetTextureHandleNV (GLuint texture);
GLAPI GLuint64 APIENTRY glGetTextureSamplerHandleNV (GLuint texture, GLuint sampler);
GLAPI void APIENTRY glMakeTextureHandleResidentNV (GLuint64 handle);
GLAPI void APIENTRY glMakeTextureHandleNonResidentNV (GLuint64 handle);
GLAPI GLuint64 APIENTRY glGetImageHandleNV (GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format);
GLAPI void APIENTRY glMakeImageHandleResidentNV (GLuint64 handle, GLenum access);
GLAPI void APIENTRY glMakeImageHandleNonResidentNV (GLuint64 handle);
GLAPI void APIENTRY glUniformHandleui64NV (GLint location, GLuint64 value);
GLAPI void APIENTRY glUniformHandleui64vNV (GLint location, GLsizei count, const GLuint64 *value);
GLAPI void APIENTRY glProgramUniformHandleui64NV (GLuint program, GLint location, GLuint64 value);
GLAPI void APIENTRY glProgramUniformHandleui64vNV (GLuint program, GLint location, GLsizei count, const GLuint64 *values);
GLAPI GLboolean APIENTRY glIsTextureHandleResidentNV (GLuint64 handle);
GLAPI GLboolean APIENTRY glIsImageHandleResidentNV (GLuint64 handle);
#endif
#endif /* GL_NV_bindless_texture */
#ifndef GL_NV_blend_equation_advanced
#define GL_NV_blend_equation_advanced 1
#define GL_BLEND_OVERLAP_NV               0x9281
#define GL_BLEND_PREMULTIPLIED_SRC_NV     0x9280
#define GL_BLUE_NV                        0x1905
#define GL_COLORBURN_NV                   0x929A
#define GL_COLORDODGE_NV                  0x9299
#define GL_CONJOINT_NV                    0x9284
#define GL_CONTRAST_NV                    0x92A1
#define GL_DARKEN_NV                      0x9297
#define GL_DIFFERENCE_NV                  0x929E
#define GL_DISJOINT_NV                    0x9283
#define GL_DST_ATOP_NV                    0x928F
#define GL_DST_IN_NV                      0x928B
#define GL_DST_NV                         0x9287
#define GL_DST_OUT_NV                     0x928D
#define GL_DST_OVER_NV                    0x9289
#define GL_EXCLUSION_NV                   0x92A0
#define GL_GREEN_NV                       0x1904
#define GL_HARDLIGHT_NV                   0x929B
#define GL_HARDMIX_NV                     0x92A9
#define GL_HSL_COLOR_NV                   0x92AF
#define GL_HSL_HUE_NV                     0x92AD
#define GL_HSL_LUMINOSITY_NV              0x92B0
#define GL_HSL_SATURATION_NV              0x92AE
#define GL_INVERT_OVG_NV                  0x92B4
#define GL_INVERT_RGB_NV                  0x92A3
#define GL_LIGHTEN_NV                     0x9298
#define GL_LINEARBURN_NV                  0x92A5
#define GL_LINEARDODGE_NV                 0x92A4
#define GL_LINEARLIGHT_NV                 0x92A7
#define GL_MINUS_CLAMPED_NV               0x92B3
#define GL_MINUS_NV                       0x929F
#define GL_MULTIPLY_NV                    0x9294
#define GL_OVERLAY_NV                     0x9296
#define GL_PINLIGHT_NV                    0x92A8
#define GL_PLUS_CLAMPED_ALPHA_NV          0x92B2
#define GL_PLUS_CLAMPED_NV                0x92B1
#define GL_PLUS_DARKER_NV                 0x9292
#define GL_PLUS_NV                        0x9291
#define GL_RED_NV                         0x1903
#define GL_SCREEN_NV                      0x9295
#define GL_SOFTLIGHT_NV                   0x929C
#define GL_SRC_ATOP_NV                    0x928E
#define GL_SRC_IN_NV                      0x928A
#define GL_SRC_NV                         0x9286
#define GL_SRC_OUT_NV                     0x928C
#define GL_SRC_OVER_NV                    0x9288
#define GL_UNCORRELATED_NV                0x9282
#define GL_VIVIDLIGHT_NV                  0x92A6
#define GL_XOR_NV                         0x1506
typedef void (APIENTRYP PFNGLBLENDPARAMETERINVPROC) (GLenum pname, GLint value);
typedef void (APIENTRYP PFNGLBLENDBARRIERNVPROC) (void);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glBlendParameteriNV (GLenum pname, GLint value);
GLAPI void APIENTRY glBlendBarrierNV (void);
#endif
#endif /* GL_NV_blend_equation_advanced */
#ifndef GL_NV_blend_equation_advanced_coherent
#define GL_NV_blend_equation_advanced_coherent 1
#define GL_BLEND_ADVANCED_COHERENT_NV     0x9285
#endif /* GL_NV_blend_equation_advanced_coherent */
#ifndef GL_NV_blend_minmax_factor
#define GL_NV_blend_minmax_factor 1
#define GL_FACTOR_MIN_AMD                 0x901C
#define GL_FACTOR_MAX_AMD                 0x901D
#endif /* GL_NV_blend_minmax_factor */
#ifndef GL_NV_clip_space_w_scaling
#define GL_NV_clip_space_w_scaling 1
#define GL_VIEWPORT_POSITION_W_SCALE_NV   0x937C
#define GL_VIEWPORT_POSITION_W_SCALE_X_COEFF_NV 0x937D
#define GL_VIEWPORT_POSITION_W_SCALE_Y_COEFF_NV 0x937E
typedef void (APIENTRYP PFNGLVIEWPORTPOSITIONWSCALENVPROC) (GLuint index, GLfloat xcoeff, GLfloat ycoeff);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glViewportPositionWScaleNV (GLuint index, GLfloat xcoeff, GLfloat ycoeff);
#endif
#endif /* GL_NV_clip_space_w_scaling */
#ifndef GL_NV_command_list
#define GL_NV_command_list 1
#define GL_TERMINATE_SEQUENCE_COMMAND_NV  0x0000
#define GL_NOP_COMMAND_NV                 0x0001
#define GL_DRAW_ELEMENTS_COMMAND_NV       0x0002
#define GL_DRAW_ARRAYS_COMMAND_NV         0x0003
#define GL_DRAW_ELEMENTS_STRIP_COMMAND_NV 0x0004
#define GL_DRAW_ARRAYS_STRIP_COMMAND_NV   0x0005
#define GL_DRAW_ELEMENTS_INSTANCED_COMMAND_NV 0x0006
#define GL_DRAW_ARRAYS_INSTANCED_COMMAND_NV 0x0007
#define GL_ELEMENT_ADDRESS_COMMAND_NV     0x0008
#define GL_ATTRIBUTE_ADDRESS_COMMAND_NV   0x0009
#define GL_UNIFORM_ADDRESS_COMMAND_NV     0x000A
#define GL_BLEND_COLOR_COMMAND_NV         0x000B
#define GL_STENCIL_REF_COMMAND_NV         0x000C
#define GL_LINE_WIDTH_COMMAND_NV          0x000D
#define GL_POLYGON_OFFSET_COMMAND_NV      0x000E
#define GL_ALPHA_REF_COMMAND_NV           0x000F
#define GL_VIEWPORT_COMMAND_NV            0x0010
#define GL_SCISSOR_COMMAND_NV             0x0011
#define GL_FRONT_FACE_COMMAND_NV          0x0012
typedef void (APIENTRYP PFNGLCREATESTATESNVPROC) (GLsizei n, GLuint *states);
typedef void (APIENTRYP PFNGLDELETESTATESNVPROC) (GLsizei n, const GLuint *states);
typedef GLboolean (APIENTRYP PFNGLISSTATENVPROC) (GLuint state);
typedef void (APIENTRYP PFNGLSTATECAPTURENVPROC) (GLuint state, GLenum mode);
typedef GLuint (APIENTRYP PFNGLGETCOMMANDHEADERNVPROC) (GLenum tokenID, GLuint size);
typedef GLushort (APIENTRYP PFNGLGETSTAGEINDEXNVPROC) (GLenum shadertype);
typedef void (APIENTRYP PFNGLDRAWCOMMANDSNVPROC) (GLenum primitiveMode, GLuint buffer, const GLintptr *indirects, const GLsizei *sizes, GLuint count);
typedef void (APIENTRYP PFNGLDRAWCOMMANDSADDRESSNVPROC) (GLenum primitiveMode, const GLuint64 *indirects, const GLsizei *sizes, GLuint count);
typedef void (APIENTRYP PFNGLDRAWCOMMANDSSTATESNVPROC) (GLuint buffer, const GLintptr *indirects, const GLsizei *sizes, const GLuint *states, const GLuint *fbos, GLuint count);
typedef void (APIENTRYP PFNGLDRAWCOMMANDSSTATESADDRESSNVPROC) (const GLuint64 *indirects, const GLsizei *sizes, const GLuint *states, const GLuint *fbos, GLuint count);
typedef void (APIENTRYP PFNGLCREATECOMMANDLISTSNVPROC) (GLsizei n, GLuint *lists);
typedef void (APIENTRYP PFNGLDELETECOMMANDLISTSNVPROC) (GLsizei n, const GLuint *lists);
typedef GLboolean (APIENTRYP PFNGLISCOMMANDLISTNVPROC) (GLuint list);
typedef void (APIENTRYP PFNGLLISTDRAWCOMMANDSSTATESCLIENTNVPROC) (GLuint list, GLuint segment, const void **indirects, const GLsizei *sizes, const GLuint *states, const GLuint *fbos, GLuint count);
typedef void (APIENTRYP PFNGLCOMMANDLISTSEGMENTSNVPROC) (GLuint list, GLuint segments);
typedef void (APIENTRYP PFNGLCOMPILECOMMANDLISTNVPROC) (GLuint list);
typedef void (APIENTRYP PFNGLCALLCOMMANDLISTNVPROC) (GLuint list);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glCreateStatesNV (GLsizei n, GLuint *states);
GLAPI void APIENTRY glDeleteStatesNV (GLsizei n, const GLuint *states);
GLAPI GLboolean APIENTRY glIsStateNV (GLuint state);
GLAPI void APIENTRY glStateCaptureNV (GLuint state, GLenum mode);
GLAPI GLuint APIENTRY glGetCommandHeaderNV (GLenum tokenID, GLuint size);
GLAPI GLushort APIENTRY glGetStageIndexNV (GLenum shadertype);
GLAPI void APIENTRY glDrawCommandsNV (GLenum primitiveMode, GLuint buffer, const GLintptr *indirects, const GLsizei *sizes, GLuint count);
GLAPI void APIENTRY glDrawCommandsAddressNV (GLenum primitiveMode, const GLuint64 *indirects, const GLsizei *sizes, GLuint count);
GLAPI void APIENTRY glDrawCommandsStatesNV (GLuint buffer, const GLintptr *indirects, const GLsizei *sizes, const GLuint *states, const GLuint *fbos, GLuint count);
GLAPI void APIENTRY glDrawCommandsStatesAddressNV (const GLuint64 *indirects, const GLsizei *sizes, const GLuint *states, const GLuint *fbos, GLuint count);
GLAPI void APIENTRY glCreateCommandListsNV (GLsizei n, GLuint *lists);
GLAPI void APIENTRY glDeleteCommandListsNV (GLsizei n, const GLuint *lists);
GLAPI GLboolean APIENTRY glIsCommandListNV (GLuint list);
GLAPI void APIENTRY glListDrawCommandsStatesClientNV (GLuint list, GLuint segment, const void **indirects, const GLsizei *sizes, const GLuint *states, const GLuint *fbos, GLuint count);
GLAPI void APIENTRY glCommandListSegmentsNV (GLuint list, GLuint segments);
GLAPI void APIENTRY glCompileCommandListNV (GLuint list);
GLAPI void APIENTRY glCallCommandListNV (GLuint list);
#endif
#endif /* GL_NV_command_list */
#ifndef GL_NV_compute_shader_derivatives
#define GL_NV_compute_shader_derivatives 1
#endif /* GL_NV_compute_shader_derivatives */
#ifndef GL_NV_conditional_render
#define GL_NV_conditional_render 1
#define GL_QUERY_WAIT_NV                  0x8E13
#define GL_QUERY_NO_WAIT_NV               0x8E14
#define GL_QUERY_BY_REGION_WAIT_NV        0x8E15
#define GL_QUERY_BY_REGION_NO_WAIT_NV     0x8E16
typedef void (APIENTRYP PFNGLBEGINCONDITIONALRENDERNVPROC) (GLuint id, GLenum mode);
typedef void (APIENTRYP PFNGLENDCONDITIONALRENDERNVPROC) (void);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glBeginConditionalRenderNV (GLuint id, GLenum mode);
GLAPI void APIENTRY glEndConditionalRenderNV (void);
#endif
#endif /* GL_NV_conditional_render */
#ifndef GL_NV_conservative_raster
#define GL_NV_conservative_raster 1
#define GL_CONSERVATIVE_RASTERIZATION_NV  0x9346
#define GL_SUBPIXEL_PRECISION_BIAS_X_BITS_NV 0x9347
#define GL_SUBPIXEL_PRECISION_BIAS_Y_BITS_NV 0x9348
#define GL_MAX_SUBPIXEL_PRECISION_BIAS_BITS_NV 0x9349
typedef void (APIENTRYP PFNGLSUBPIXELPRECISIONBIASNVPROC) (GLuint xbits, GLuint ybits);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glSubpixelPrecisionBiasNV (GLuint xbits, GLuint ybits);
#endif
#endif /* GL_NV_conservative_raster */
#ifndef GL_NV_conservative_raster_dilate
#define GL_NV_conservative_raster_dilate 1
#define GL_CONSERVATIVE_RASTER_DILATE_NV  0x9379
#define GL_CONSERVATIVE_RASTER_DILATE_RANGE_NV 0x937A
#define GL_CONSERVATIVE_RASTER_DILATE_GRANULARITY_NV 0x937B
typedef void (APIENTRYP PFNGLCONSERVATIVERASTERPARAMETERFNVPROC) (GLenum pname, GLfloat value);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glConservativeRasterParameterfNV (GLenum pname, GLfloat value);
#endif
#endif /* GL_NV_conservative_raster_dilate */
#ifndef GL_NV_conservative_raster_pre_snap
#define GL_NV_conservative_raster_pre_snap 1
#define GL_CONSERVATIVE_RASTER_MODE_PRE_SNAP_NV 0x9550
#endif /* GL_NV_conservative_raster_pre_snap */
#ifndef GL_NV_conservative_raster_pre_snap_triangles
#define GL_NV_conservative_raster_pre_snap_triangles 1
#define GL_CONSERVATIVE_RASTER_MODE_NV    0x954D
#define GL_CONSERVATIVE_RASTER_MODE_POST_SNAP_NV 0x954E
#define GL_CONSERVATIVE_RASTER_MODE_PRE_SNAP_TRIANGLES_NV 0x954F
typedef void (APIENTRYP PFNGLCONSERVATIVERASTERPARAMETERINVPROC) (GLenum pname, GLint param);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glConservativeRasterParameteriNV (GLenum pname, GLint param);
#endif
#endif /* GL_NV_conservative_raster_pre_snap_triangles */
#ifndef GL_NV_conservative_raster_underestimation
#define GL_NV_conservative_raster_underestimation 1
#endif /* GL_NV_conservative_raster_underestimation */
#ifndef GL_NV_depth_buffer_float
#define GL_NV_depth_buffer_float 1
#define GL_DEPTH_COMPONENT32F_NV          0x8DAB
#define GL_DEPTH32F_STENCIL8_NV           0x8DAC
#define GL_FLOAT_32_UNSIGNED_INT_24_8_REV_NV 0x8DAD
#define GL_DEPTH_BUFFER_FLOAT_MODE_NV     0x8DAF
typedef void (APIENTRYP PFNGLDEPTHRANGEDNVPROC) (GLdouble zNear, GLdouble zFar);
typedef void (APIENTRYP PFNGLCLEARDEPTHDNVPROC) (GLdouble depth);
typedef void (APIENTRYP PFNGLDEPTHBOUNDSDNVPROC) (GLdouble zmin, GLdouble zmax);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glDepthRangedNV (GLdouble zNear, GLdouble zFar);
GLAPI void APIENTRY glClearDepthdNV (GLdouble depth);
GLAPI void APIENTRY glDepthBoundsdNV (GLdouble zmin, GLdouble zmax);
#endif
#endif /* GL_NV_depth_buffer_float */
#ifndef GL_NV_draw_vulkan_image
#define GL_NV_draw_vulkan_image 1
typedef void (APIENTRY  *GLVULKANPROCNV)(void);
typedef void (APIENTRYP PFNGLDRAWVKIMAGENVPROC) (GLuint64 vkImage, GLuint sampler, GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat z, GLfloat s0, GLfloat t0, GLfloat s1, GLfloat t1);
typedef GLVULKANPROCNV (APIENTRYP PFNGLGETVKPROCADDRNVPROC) (const GLchar *name);
typedef void (APIENTRYP PFNGLWAITVKSEMAPHORENVPROC) (GLuint64 vkSemaphore);
typedef void (APIENTRYP PFNGLSIGNALVKSEMAPHORENVPROC) (GLuint64 vkSemaphore);
typedef void (APIENTRYP PFNGLSIGNALVKFENCENVPROC) (GLuint64 vkFence);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glDrawVkImageNV (GLuint64 vkImage, GLuint sampler, GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat z, GLfloat s0, GLfloat t0, GLfloat s1, GLfloat t1);
GLAPI GLVULKANPROCNV APIENTRY glGetVkProcAddrNV (const GLchar *name);
GLAPI void APIENTRY glWaitVkSemaphoreNV (GLuint64 vkSemaphore);
GLAPI void APIENTRY glSignalVkSemaphoreNV (GLuint64 vkSemaphore);
GLAPI void APIENTRY glSignalVkFenceNV (GLuint64 vkFence);
#endif
#endif /* GL_NV_draw_vulkan_image */
#ifndef GL_NV_fill_rectangle
#define GL_NV_fill_rectangle 1
#define GL_FILL_RECTANGLE_NV              0x933C
#endif /* GL_NV_fill_rectangle */
#ifndef GL_NV_fragment_coverage_to_color
#define GL_NV_fragment_coverage_to_color 1
#define GL_FRAGMENT_COVERAGE_TO_COLOR_NV  0x92DD
#define GL_FRAGMENT_COVERAGE_COLOR_NV     0x92DE
typedef void (APIENTRYP PFNGLFRAGMENTCOVERAGECOLORNVPROC) (GLuint color);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glFragmentCoverageColorNV (GLuint color);
#endif
#endif /* GL_NV_fragment_coverage_to_color */
#ifndef GL_NV_fragment_shader_barycentric
#define GL_NV_fragment_shader_barycentric 1
#endif /* GL_NV_fragment_shader_barycentric */
#ifndef GL_NV_fragment_shader_interlock
#define GL_NV_fragment_shader_interlock 1
#endif /* GL_NV_fragment_shader_interlock */
#ifndef GL_NV_framebuffer_mixed_samples
#define GL_NV_framebuffer_mixed_samples 1
#define GL_COVERAGE_MODULATION_TABLE_NV   0x9331
#define GL_COLOR_SAMPLES_NV               0x8E20
#define GL_DEPTH_SAMPLES_NV               0x932D
#define GL_STENCIL_SAMPLES_NV             0x932E
#define GL_MIXED_DEPTH_SAMPLES_SUPPORTED_NV 0x932F
#define GL_MIXED_STENCIL_SAMPLES_SUPPORTED_NV 0x9330
#define GL_COVERAGE_MODULATION_NV         0x9332
#define GL_COVERAGE_MODULATION_TABLE_SIZE_NV 0x9333
typedef void (APIENTRYP PFNGLCOVERAGEMODULATIONTABLENVPROC) (GLsizei n, const GLfloat *v);
typedef void (APIENTRYP PFNGLGETCOVERAGEMODULATIONTABLENVPROC) (GLsizei bufSize, GLfloat *v);
typedef void (APIENTRYP PFNGLCOVERAGEMODULATIONNVPROC) (GLenum components);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glCoverageModulationTableNV (GLsizei n, const GLfloat *v);
GLAPI void APIENTRY glGetCoverageModulationTableNV (GLsizei bufSize, GLfloat *v);
GLAPI void APIENTRY glCoverageModulationNV (GLenum components);
#endif
#endif /* GL_NV_framebuffer_mixed_samples */
#ifndef GL_NV_framebuffer_multisample_coverage
#define GL_NV_framebuffer_multisample_coverage 1
#define GL_RENDERBUFFER_COVERAGE_SAMPLES_NV 0x8CAB
#define GL_RENDERBUFFER_COLOR_SAMPLES_NV  0x8E10
#define GL_MAX_MULTISAMPLE_COVERAGE_MODES_NV 0x8E11
#define GL_MULTISAMPLE_COVERAGE_MODES_NV  0x8E12
typedef void (APIENTRYP PFNGLRENDERBUFFERSTORAGEMULTISAMPLECOVERAGENVPROC) (GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glRenderbufferStorageMultisampleCoverageNV (GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height);
#endif
#endif /* GL_NV_framebuffer_multisample_coverage */
#ifndef GL_NV_geometry_shader_passthrough
#define GL_NV_geometry_shader_passthrough 1
#endif /* GL_NV_geometry_shader_passthrough */
#ifndef GL_NV_gpu_shader5
#define GL_NV_gpu_shader5 1
typedef khronos_int64_t GLint64EXT;
#define GL_INT64_NV                       0x140E
#define GL_UNSIGNED_INT64_NV              0x140F
#define GL_INT8_NV                        0x8FE0
#define GL_INT8_VEC2_NV                   0x8FE1
#define GL_INT8_VEC3_NV                   0x8FE2
#define GL_INT8_VEC4_NV                   0x8FE3
#define GL_INT16_NV                       0x8FE4
#define GL_INT16_VEC2_NV                  0x8FE5
#define GL_INT16_VEC3_NV                  0x8FE6
#define GL_INT16_VEC4_NV                  0x8FE7
#define GL_INT64_VEC2_NV                  0x8FE9
#define GL_INT64_VEC3_NV                  0x8FEA
#define GL_INT64_VEC4_NV                  0x8FEB
#define GL_UNSIGNED_INT8_NV               0x8FEC
#define GL_UNSIGNED_INT8_VEC2_NV          0x8FED
#define GL_UNSIGNED_INT8_VEC3_NV          0x8FEE
#define GL_UNSIGNED_INT8_VEC4_NV          0x8FEF
#define GL_UNSIGNED_INT16_NV              0x8FF0
#define GL_UNSIGNED_INT16_VEC2_NV         0x8FF1
#define GL_UNSIGNED_INT16_VEC3_NV         0x8FF2
#define GL_UNSIGNED_INT16_VEC4_NV         0x8FF3
#define GL_UNSIGNED_INT64_VEC2_NV         0x8FF5
#define GL_UNSIGNED_INT64_VEC3_NV         0x8FF6
#define GL_UNSIGNED_INT64_VEC4_NV         0x8FF7
#define GL_FLOAT16_NV                     0x8FF8
#define GL_FLOAT16_VEC2_NV                0x8FF9
#define GL_FLOAT16_VEC3_NV                0x8FFA
#define GL_FLOAT16_VEC4_NV                0x8FFB
typedef void (APIENTRYP PFNGLUNIFORM1I64NVPROC) (GLint location, GLint64EXT x);
typedef void (APIENTRYP PFNGLUNIFORM2I64NVPROC) (GLint location, GLint64EXT x, GLint64EXT y);
typedef void (APIENTRYP PFNGLUNIFORM3I64NVPROC) (GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z);
typedef void (APIENTRYP PFNGLUNIFORM4I64NVPROC) (GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
typedef void (APIENTRYP PFNGLUNIFORM1I64VNVPROC) (GLint location, GLsizei count, const GLint64EXT *value);
typedef void (APIENTRYP PFNGLUNIFORM2I64VNVPROC) (GLint location, GLsizei count, const GLint64EXT *value);
typedef void (APIENTRYP PFNGLUNIFORM3I64VNVPROC) (GLint location, GLsizei count, const GLint64EXT *value);
typedef void (APIENTRYP PFNGLUNIFORM4I64VNVPROC) (GLint location, GLsizei count, const GLint64EXT *value);
typedef void (APIENTRYP PFNGLUNIFORM1UI64NVPROC) (GLint location, GLuint64EXT x);
typedef void (APIENTRYP PFNGLUNIFORM2UI64NVPROC) (GLint location, GLuint64EXT x, GLuint64EXT y);
typedef void (APIENTRYP PFNGLUNIFORM3UI64NVPROC) (GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
typedef void (APIENTRYP PFNGLUNIFORM4UI64NVPROC) (GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
typedef void (APIENTRYP PFNGLUNIFORM1UI64VNVPROC) (GLint location, GLsizei count, const GLuint64EXT *value);
typedef void (APIENTRYP PFNGLUNIFORM2UI64VNVPROC) (GLint location, GLsizei count, const GLuint64EXT *value);
typedef void (APIENTRYP PFNGLUNIFORM3UI64VNVPROC) (GLint location, GLsizei count, const GLuint64EXT *value);
typedef void (APIENTRYP PFNGLUNIFORM4UI64VNVPROC) (GLint location, GLsizei count, const GLuint64EXT *value);
typedef void (APIENTRYP PFNGLGETUNIFORMI64VNVPROC) (GLuint program, GLint location, GLint64EXT *params);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1I64NVPROC) (GLuint program, GLint location, GLint64EXT x);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2I64NVPROC) (GLuint program, GLint location, GLint64EXT x, GLint64EXT y);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3I64NVPROC) (GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4I64NVPROC) (GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1I64VNVPROC) (GLuint program, GLint location, GLsizei count, const GLint64EXT *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2I64VNVPROC) (GLuint program, GLint location, GLsizei count, const GLint64EXT *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3I64VNVPROC) (GLuint program, GLint location, GLsizei count, const GLint64EXT *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4I64VNVPROC) (GLuint program, GLint location, GLsizei count, const GLint64EXT *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UI64NVPROC) (GLuint program, GLint location, GLuint64EXT x);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UI64NVPROC) (GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UI64NVPROC) (GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UI64NVPROC) (GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UI64VNVPROC) (GLuint program, GLint location, GLsizei count, const GLuint64EXT *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UI64VNVPROC) (GLuint program, GLint location, GLsizei count, const GLuint64EXT *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UI64VNVPROC) (GLuint program, GLint location, GLsizei count, const GLuint64EXT *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UI64VNVPROC) (GLuint program, GLint location, GLsizei count, const GLuint64EXT *value);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glUniform1i64NV (GLint location, GLint64EXT x);
GLAPI void APIENTRY glUniform2i64NV (GLint location, GLint64EXT x, GLint64EXT y);
GLAPI void APIENTRY glUniform3i64NV (GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z);
GLAPI void APIENTRY glUniform4i64NV (GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
GLAPI void APIENTRY glUniform1i64vNV (GLint location, GLsizei count, const GLint64EXT *value);
GLAPI void APIENTRY glUniform2i64vNV (GLint location, GLsizei count, const GLint64EXT *value);
GLAPI void APIENTRY glUniform3i64vNV (GLint location, GLsizei count, const GLint64EXT *value);
GLAPI void APIENTRY glUniform4i64vNV (GLint location, GLsizei count, const GLint64EXT *value);
GLAPI void APIENTRY glUniform1ui64NV (GLint location, GLuint64EXT x);
GLAPI void APIENTRY glUniform2ui64NV (GLint location, GLuint64EXT x, GLuint64EXT y);
GLAPI void APIENTRY glUniform3ui64NV (GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
GLAPI void APIENTRY glUniform4ui64NV (GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
GLAPI void APIENTRY glUniform1ui64vNV (GLint location, GLsizei count, const GLuint64EXT *value);
GLAPI void APIENTRY glUniform2ui64vNV (GLint location, GLsizei count, const GLuint64EXT *value);
GLAPI void APIENTRY glUniform3ui64vNV (GLint location, GLsizei count, const GLuint64EXT *value);
GLAPI void APIENTRY glUniform4ui64vNV (GLint location, GLsizei count, const GLuint64EXT *value);
GLAPI void APIENTRY glGetUniformi64vNV (GLuint program, GLint location, GLint64EXT *params);
GLAPI void APIENTRY glProgramUniform1i64NV (GLuint program, GLint location, GLint64EXT x);
GLAPI void APIENTRY glProgramUniform2i64NV (GLuint program, GLint location, GLint64EXT x, GLint64EXT y);
GLAPI void APIENTRY glProgramUniform3i64NV (GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z);
GLAPI void APIENTRY glProgramUniform4i64NV (GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
GLAPI void APIENTRY glProgramUniform1i64vNV (GLuint program, GLint location, GLsizei count, const GLint64EXT *value);
GLAPI void APIENTRY glProgramUniform2i64vNV (GLuint program, GLint location, GLsizei count, const GLint64EXT *value);
GLAPI void APIENTRY glProgramUniform3i64vNV (GLuint program, GLint location, GLsizei count, const GLint64EXT *value);
GLAPI void APIENTRY glProgramUniform4i64vNV (GLuint program, GLint location, GLsizei count, const GLint64EXT *value);
GLAPI void APIENTRY glProgramUniform1ui64NV (GLuint program, GLint location, GLuint64EXT x);
GLAPI void APIENTRY glProgramUniform2ui64NV (GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y);
GLAPI void APIENTRY glProgramUniform3ui64NV (GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
GLAPI void APIENTRY glProgramUniform4ui64NV (GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
GLAPI void APIENTRY glProgramUniform1ui64vNV (GLuint program, GLint location, GLsizei count, const GLuint64EXT *value);
GLAPI void APIENTRY glProgramUniform2ui64vNV (GLuint program, GLint location, GLsizei count, const GLuint64EXT *value);
GLAPI void APIENTRY glProgramUniform3ui64vNV (GLuint program, GLint location, GLsizei count, const GLuint64EXT *value);
GLAPI void APIENTRY glProgramUniform4ui64vNV (GLuint program, GLint location, GLsizei count, const GLuint64EXT *value);
#endif
#endif /* GL_NV_gpu_shader5 */
#ifndef GL_NV_internalformat_sample_query
#define GL_NV_internalformat_sample_query 1
#define GL_MULTISAMPLES_NV                0x9371
#define GL_SUPERSAMPLE_SCALE_X_NV         0x9372
#define GL_SUPERSAMPLE_SCALE_Y_NV         0x9373
#define GL_CONFORMANT_NV                  0x9374
typedef void (APIENTRYP PFNGLGETINTERNALFORMATSAMPLEIVNVPROC) (GLenum target, GLenum internalformat, GLsizei samples, GLenum pname, GLsizei count, GLint *params);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glGetInternalformatSampleivNV (GLenum target, GLenum internalformat, GLsizei samples, GLenum pname, GLsizei count, GLint *params);
#endif
#endif /* GL_NV_internalformat_sample_query */
#ifndef GL_NV_memory_attachment
#define GL_NV_memory_attachment 1
#define GL_ATTACHED_MEMORY_OBJECT_NV      0x95A4
#define GL_ATTACHED_MEMORY_OFFSET_NV      0x95A5
#define GL_MEMORY_ATTACHABLE_ALIGNMENT_NV 0x95A6
#define GL_MEMORY_ATTACHABLE_SIZE_NV      0x95A7
#define GL_MEMORY_ATTACHABLE_NV           0x95A8
#define GL_DETACHED_MEMORY_INCARNATION_NV 0x95A9
#define GL_DETACHED_TEXTURES_NV           0x95AA
#define GL_DETACHED_BUFFERS_NV            0x95AB
#define GL_MAX_DETACHED_TEXTURES_NV       0x95AC
#define GL_MAX_DETACHED_BUFFERS_NV        0x95AD
typedef void (APIENTRYP PFNGLGETMEMORYOBJECTDETACHEDRESOURCESUIVNVPROC) (GLuint memory, GLenum pname, GLint first, GLsizei count, GLuint *params);
typedef void (APIENTRYP PFNGLRESETMEMORYOBJECTPARAMETERNVPROC) (GLuint memory, GLenum pname);
typedef void (APIENTRYP PFNGLTEXATTACHMEMORYNVPROC) (GLenum target, GLuint memory, GLuint64 offset);
typedef void (APIENTRYP PFNGLBUFFERATTACHMEMORYNVPROC) (GLenum target, GLuint memory, GLuint64 offset);
typedef void (APIENTRYP PFNGLTEXTUREATTACHMEMORYNVPROC) (GLuint texture, GLuint memory, GLuint64 offset);
typedef void (APIENTRYP PFNGLNAMEDBUFFERATTACHMEMORYNVPROC) (GLuint buffer, GLuint memory, GLuint64 offset);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glGetMemoryObjectDetachedResourcesuivNV (GLuint memory, GLenum pname, GLint first, GLsizei count, GLuint *params);
GLAPI void APIENTRY glResetMemoryObjectParameterNV (GLuint memory, GLenum pname);
GLAPI void APIENTRY glTexAttachMemoryNV (GLenum target, GLuint memory, GLuint64 offset);
GLAPI void APIENTRY glBufferAttachMemoryNV (GLenum target, GLuint memory, GLuint64 offset);
GLAPI void APIENTRY glTextureAttachMemoryNV (GLuint texture, GLuint memory, GLuint64 offset);
GLAPI void APIENTRY glNamedBufferAttachMemoryNV (GLuint buffer, GLuint memory, GLuint64 offset);
#endif
#endif /* GL_NV_memory_attachment */
#ifndef GL_NV_memory_object_sparse
#define GL_NV_memory_object_sparse 1
typedef void (APIENTRYP PFNGLBUFFERPAGECOMMITMENTMEMNVPROC) (GLenum target, GLintptr offset, GLsizeiptr size, GLuint memory, GLuint64 memOffset, GLboolean commit);
typedef void (APIENTRYP PFNGLTEXPAGECOMMITMENTMEMNVPROC) (GLenum target, GLint layer, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLuint memory, GLuint64 offset, GLboolean commit);
typedef void (APIENTRYP PFNGLNAMEDBUFFERPAGECOMMITMENTMEMNVPROC) (GLuint buffer, GLintptr offset, GLsizeiptr size, GLuint memory, GLuint64 memOffset, GLboolean commit);
typedef void (APIENTRYP PFNGLTEXTUREPAGECOMMITMENTMEMNVPROC) (GLuint texture, GLint layer, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLuint memory, GLuint64 offset, GLboolean commit);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glBufferPageCommitmentMemNV (GLenum target, GLintptr offset, GLsizeiptr size, GLuint memory, GLuint64 memOffset, GLboolean commit);
GLAPI void APIENTRY glTexPageCommitmentMemNV (GLenum target, GLint layer, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLuint memory, GLuint64 offset, GLboolean commit);
GLAPI void APIENTRY glNamedBufferPageCommitmentMemNV (GLuint buffer, GLintptr offset, GLsizeiptr size, GLuint memory, GLuint64 memOffset, GLboolean commit);
GLAPI void APIENTRY glTexturePageCommitmentMemNV (GLuint texture, GLint layer, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLuint memory, GLuint64 offset, GLboolean commit);
#endif
#endif /* GL_NV_memory_object_sparse */
#ifndef GL_NV_mesh_shader
#define GL_NV_mesh_shader 1
#define GL_MESH_SHADER_NV                 0x9559
#define GL_TASK_SHADER_NV                 0x955A
#define GL_MAX_MESH_UNIFORM_BLOCKS_NV     0x8E60
#define GL_MAX_MESH_TEXTURE_IMAGE_UNITS_NV 0x8E61
#define GL_MAX_MESH_IMAGE_UNIFORMS_NV     0x8E62
#define GL_MAX_MESH_UNIFORM_COMPONENTS_NV 0x8E63
#define GL_MAX_MESH_ATOMIC_COUNTER_BUFFERS_NV 0x8E64
#define GL_MAX_MESH_ATOMIC_COUNTERS_NV    0x8E65
#define GL_MAX_MESH_SHADER_STORAGE_BLOCKS_NV 0x8E66
#define GL_MAX_COMBINED_MESH_UNIFORM_COMPONENTS_NV 0x8E67
#define GL_MAX_TASK_UNIFORM_BLOCKS_NV     0x8E68
#define GL_MAX_TASK_TEXTURE_IMAGE_UNITS_NV 0x8E69
#define GL_MAX_TASK_IMAGE_UNIFORMS_NV     0x8E6A
#define GL_MAX_TASK_UNIFORM_COMPONENTS_NV 0x8E6B
#define GL_MAX_TASK_ATOMIC_COUNTER_BUFFERS_NV 0x8E6C
#define GL_MAX_TASK_ATOMIC_COUNTERS_NV    0x8E6D
#define GL_MAX_TASK_SHADER_STORAGE_BLOCKS_NV 0x8E6E
#define GL_MAX_COMBINED_TASK_UNIFORM_COMPONENTS_NV 0x8E6F
#define GL_MAX_MESH_WORK_GROUP_INVOCATIONS_NV 0x95A2
#define GL_MAX_TASK_WORK_GROUP_INVOCATIONS_NV 0x95A3
#define GL_MAX_MESH_TOTAL_MEMORY_SIZE_NV  0x9536
#define GL_MAX_TASK_TOTAL_MEMORY_SIZE_NV  0x9537
#define GL_MAX_MESH_OUTPUT_VERTICES_NV    0x9538
#define GL_MAX_MESH_OUTPUT_PRIMITIVES_NV  0x9539
#define GL_MAX_TASK_OUTPUT_COUNT_NV       0x953A
#define GL_MAX_DRAW_MESH_TASKS_COUNT_NV   0x953D
#define GL_MAX_MESH_VIEWS_NV              0x9557
#define GL_MESH_OUTPUT_PER_VERTEX_GRANULARITY_NV 0x92DF
#define GL_MESH_OUTPUT_PER_PRIMITIVE_GRANULARITY_NV 0x9543
#define GL_MAX_MESH_WORK_GROUP_SIZE_NV    0x953B
#define GL_MAX_TASK_WORK_GROUP_SIZE_NV    0x953C
#define GL_MESH_WORK_GROUP_SIZE_NV        0x953E
#define GL_TASK_WORK_GROUP_SIZE_NV        0x953F
#define GL_MESH_VERTICES_OUT_NV           0x9579
#define GL_MESH_PRIMITIVES_OUT_NV         0x957A
#define GL_MESH_OUTPUT_TYPE_NV            0x957B
#define GL_UNIFORM_BLOCK_REFERENCED_BY_MESH_SHADER_NV 0x959C
#define GL_UNIFORM_BLOCK_REFERENCED_BY_TASK_SHADER_NV 0x959D
#define GL_REFERENCED_BY_MESH_SHADER_NV   0x95A0
#define GL_REFERENCED_BY_TASK_SHADER_NV   0x95A1
#define GL_MESH_SHADER_BIT_NV             0x00000040
#define GL_TASK_SHADER_BIT_NV             0x00000080
#define GL_MESH_SUBROUTINE_NV             0x957C
#define GL_TASK_SUBROUTINE_NV             0x957D
#define GL_MESH_SUBROUTINE_UNIFORM_NV     0x957E
#define GL_TASK_SUBROUTINE_UNIFORM_NV     0x957F
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_MESH_SHADER_NV 0x959E
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TASK_SHADER_NV 0x959F
typedef void (APIENTRYP PFNGLDRAWMESHTASKSNVPROC) (GLuint first, GLuint count);
typedef void (APIENTRYP PFNGLDRAWMESHTASKSINDIRECTNVPROC) (GLintptr indirect);
typedef void (APIENTRYP PFNGLMULTIDRAWMESHTASKSINDIRECTNVPROC) (GLintptr indirect, GLsizei drawcount, GLsizei stride);
typedef void (APIENTRYP PFNGLMULTIDRAWMESHTASKSINDIRECTCOUNTNVPROC) (GLintptr indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glDrawMeshTasksNV (GLuint first, GLuint count);
GLAPI void APIENTRY glDrawMeshTasksIndirectNV (GLintptr indirect);
GLAPI void APIENTRY glMultiDrawMeshTasksIndirectNV (GLintptr indirect, GLsizei drawcount, GLsizei stride);
GLAPI void APIENTRY glMultiDrawMeshTasksIndirectCountNV (GLintptr indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
#endif
#endif /* GL_NV_mesh_shader */
#ifndef GL_NV_path_rendering
#define GL_NV_path_rendering 1
#define GL_PATH_FORMAT_SVG_NV             0x9070
#define GL_PATH_FORMAT_PS_NV              0x9071
#define GL_STANDARD_FONT_NAME_NV          0x9072
#define GL_SYSTEM_FONT_NAME_NV            0x9073
#define GL_FILE_NAME_NV                   0x9074
#define GL_PATH_STROKE_WIDTH_NV           0x9075
#define GL_PATH_END_CAPS_NV               0x9076
#define GL_PATH_INITIAL_END_CAP_NV        0x9077
#define GL_PATH_TERMINAL_END_CAP_NV       0x9078
#define GL_PATH_JOIN_STYLE_NV             0x9079
#define GL_PATH_MITER_LIMIT_NV            0x907A
#define GL_PATH_DASH_CAPS_NV              0x907B
#define GL_PATH_INITIAL_DASH_CAP_NV       0x907C
#define GL_PATH_TERMINAL_DASH_CAP_NV      0x907D
#define GL_PATH_DASH_OFFSET_NV            0x907E
#define GL_PATH_CLIENT_LENGTH_NV          0x907F
#define GL_PATH_FILL_MODE_NV              0x9080
#define GL_PATH_FILL_MASK_NV              0x9081
#define GL_PATH_FILL_COVER_MODE_NV        0x9082
#define GL_PATH_STROKE_COVER_MODE_NV      0x9083
#define GL_PATH_STROKE_MASK_NV            0x9084
#define GL_COUNT_UP_NV                    0x9088
#define GL_COUNT_DOWN_NV                  0x9089
#define GL_PATH_OBJECT_BOUNDING_BOX_NV    0x908A
#define GL_CONVEX_HULL_NV                 0x908B
#define GL_BOUNDING_BOX_NV                0x908D
#define GL_TRANSLATE_X_NV                 0x908E
#define GL_TRANSLATE_Y_NV                 0x908F
#define GL_TRANSLATE_2D_NV                0x9090
#define GL_TRANSLATE_3D_NV                0x9091
#define GL_AFFINE_2D_NV                   0x9092
#define GL_AFFINE_3D_NV                   0x9094
#define GL_TRANSPOSE_AFFINE_2D_NV         0x9096
#define GL_TRANSPOSE_AFFINE_3D_NV         0x9098
#define GL_UTF8_NV                        0x909A
#define GL_UTF16_NV                       0x909B
#define GL_BOUNDING_BOX_OF_BOUNDING_BOXES_NV 0x909C
#define GL_PATH_COMMAND_COUNT_NV          0x909D
#define GL_PATH_COORD_COUNT_NV            0x909E
#define GL_PATH_DASH_ARRAY_COUNT_NV       0x909F
#define GL_PATH_COMPUTED_LENGTH_NV        0x90A0
#define GL_PATH_FILL_BOUNDING_BOX_NV      0x90A1
#define GL_PATH_STROKE_BOUNDING_BOX_NV    0x90A2
#define GL_SQUARE_NV                      0x90A3
#define GL_ROUND_NV                       0x90A4
#define GL_TRIANGULAR_NV                  0x90A5
#define GL_BEVEL_NV                       0x90A6
#define GL_MITER_REVERT_NV                0x90A7
#define GL_MITER_TRUNCATE_NV              0x90A8
#define GL_SKIP_MISSING_GLYPH_NV          0x90A9
#define GL_USE_MISSING_GLYPH_NV           0x90AA
#define GL_PATH_ERROR_POSITION_NV         0x90AB
#define GL_ACCUM_ADJACENT_PAIRS_NV        0x90AD
#define GL_ADJACENT_PAIRS_NV              0x90AE
#define GL_FIRST_TO_REST_NV               0x90AF
#define GL_PATH_GEN_MODE_NV               0x90B0
#define GL_PATH_GEN_COEFF_NV              0x90B1
#define GL_PATH_GEN_COMPONENTS_NV         0x90B3
#define GL_PATH_STENCIL_FUNC_NV           0x90B7
#define GL_PATH_STENCIL_REF_NV            0x90B8
#define GL_PATH_STENCIL_VALUE_MASK_NV     0x90B9
#define GL_PATH_STENCIL_DEPTH_OFFSET_FACTOR_NV 0x90BD
#define GL_PATH_STENCIL_DEPTH_OFFSET_UNITS_NV 0x90BE
#define GL_PATH_COVER_DEPTH_FUNC_NV       0x90BF
#define GL_PATH_DASH_OFFSET_RESET_NV      0x90B4
#define GL_MOVE_TO_RESETS_NV              0x90B5
#define GL_MOVE_TO_CONTINUES_NV           0x90B6
#define GL_CLOSE_PATH_NV                  0x00
#define GL_MOVE_TO_NV                     0x02
#define GL_RELATIVE_MOVE_TO_NV            0x03
#define GL_LINE_TO_NV                     0x04
#define GL_RELATIVE_LINE_TO_NV            0x05
#define GL_HORIZONTAL_LINE_TO_NV          0x06
#define GL_RELATIVE_HORIZONTAL_LINE_TO_NV 0x07
#define GL_VERTICAL_LINE_TO_NV            0x08
#define GL_RELATIVE_VERTICAL_LINE_TO_NV   0x09
#define GL_QUADRATIC_CURVE_TO_NV          0x0A
#define GL_RELATIVE_QUADRATIC_CURVE_TO_NV 0x0B
#define GL_CUBIC_CURVE_TO_NV              0x0C
#define GL_RELATIVE_CUBIC_CURVE_TO_NV     0x0D
#define GL_SMOOTH_QUADRATIC_CURVE_TO_NV   0x0E
#define GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV 0x0F
#define GL_SMOOTH_CUBIC_CURVE_TO_NV       0x10
#define GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV 0x11
#define GL_SMALL_CCW_ARC_TO_NV            0x12
#define GL_RELATIVE_SMALL_CCW_ARC_TO_NV   0x13
#define GL_SMALL_CW_ARC_TO_NV             0x14
#define GL_RELATIVE_SMALL_CW_ARC_TO_NV    0x15
#define GL_LARGE_CCW_ARC_TO_NV            0x16
#define GL_RELATIVE_LARGE_CCW_ARC_TO_NV   0x17
#define GL_LARGE_CW_ARC_TO_NV             0x18
#define GL_RELATIVE_LARGE_CW_ARC_TO_NV    0x19
#define GL_RESTART_PATH_NV                0xF0
#define GL_DUP_FIRST_CUBIC_CURVE_TO_NV    0xF2
#define GL_DUP_LAST_CUBIC_CURVE_TO_NV     0xF4
#define GL_RECT_NV                        0xF6
#define GL_CIRCULAR_CCW_ARC_TO_NV         0xF8
#define GL_CIRCULAR_CW_ARC_TO_NV          0xFA
#define GL_CIRCULAR_TANGENT_ARC_TO_NV     0xFC
#define GL_ARC_TO_NV                      0xFE
#define GL_RELATIVE_ARC_TO_NV             0xFF
#define GL_BOLD_BIT_NV                    0x01
#define GL_ITALIC_BIT_NV                  0x02
#define GL_GLYPH_WIDTH_BIT_NV             0x01
#define GL_GLYPH_HEIGHT_BIT_NV            0x02
#define GL_GLYPH_HORIZONTAL_BEARING_X_BIT_NV 0x04
#define GL_GLYPH_HORIZONTAL_BEARING_Y_BIT_NV 0x08
#define GL_GLYPH_HORIZONTAL_BEARING_ADVANCE_BIT_NV 0x10
#define GL_GLYPH_VERTICAL_BEARING_X_BIT_NV 0x20
#define GL_GLYPH_VERTICAL_BEARING_Y_BIT_NV 0x40
#define GL_GLYPH_VERTICAL_BEARING_ADVANCE_BIT_NV 0x80
#define GL_GLYPH_HAS_KERNING_BIT_NV       0x100
#define GL_FONT_X_MIN_BOUNDS_BIT_NV       0x00010000
#define GL_FONT_Y_MIN_BOUNDS_BIT_NV       0x00020000
#define GL_FONT_X_MAX_BOUNDS_BIT_NV       0x00040000
#define GL_FONT_Y_MAX_BOUNDS_BIT_NV       0x00080000
#define GL_FONT_UNITS_PER_EM_BIT_NV       0x00100000
#define GL_FONT_ASCENDER_BIT_NV           0x00200000
#define GL_FONT_DESCENDER_BIT_NV          0x00400000
#define GL_FONT_HEIGHT_BIT_NV             0x00800000
#define GL_FONT_MAX_ADVANCE_WIDTH_BIT_NV  0x01000000
#define GL_FONT_MAX_ADVANCE_HEIGHT_BIT_NV 0x02000000
#define GL_FONT_UNDERLINE_POSITION_BIT_NV 0x04000000
#define GL_FONT_UNDERLINE_THICKNESS_BIT_NV 0x08000000
#define GL_FONT_HAS_KERNING_BIT_NV        0x10000000
#define GL_ROUNDED_RECT_NV                0xE8
#define GL_RELATIVE_ROUNDED_RECT_NV       0xE9
#define GL_ROUNDED_RECT2_NV               0xEA
#define GL_RELATIVE_ROUNDED_RECT2_NV      0xEB
#define GL_ROUNDED_RECT4_NV               0xEC
#define GL_RELATIVE_ROUNDED_RECT4_NV      0xED
#define GL_ROUNDED_RECT8_NV               0xEE
#define GL_RELATIVE_ROUNDED_RECT8_NV      0xEF
#define GL_RELATIVE_RECT_NV               0xF7
#define GL_FONT_GLYPHS_AVAILABLE_NV       0x9368
#define GL_FONT_TARGET_UNAVAILABLE_NV     0x9369
#define GL_FONT_UNAVAILABLE_NV            0x936A
#define GL_FONT_UNINTELLIGIBLE_NV         0x936B
#define GL_CONIC_CURVE_TO_NV              0x1A
#define GL_RELATIVE_CONIC_CURVE_TO_NV     0x1B
#define GL_FONT_NUM_GLYPH_INDICES_BIT_NV  0x20000000
#define GL_STANDARD_FONT_FORMAT_NV        0x936C
#define GL_PATH_PROJECTION_NV             0x1701
#define GL_PATH_MODELVIEW_NV              0x1700
#define GL_PATH_MODELVIEW_STACK_DEPTH_NV  0x0BA3
#define GL_PATH_MODELVIEW_MATRIX_NV       0x0BA6
#define GL_PATH_MAX_MODELVIEW_STACK_DEPTH_NV 0x0D36
#define GL_PATH_TRANSPOSE_MODELVIEW_MATRIX_NV 0x84E3
#define GL_PATH_PROJECTION_STACK_DEPTH_NV 0x0BA4
#define GL_PATH_PROJECTION_MATRIX_NV      0x0BA7
#define GL_PATH_MAX_PROJECTION_STACK_DEPTH_NV 0x0D38
#define GL_PATH_TRANSPOSE_PROJECTION_MATRIX_NV 0x84E4
#define GL_FRAGMENT_INPUT_NV              0x936D
typedef GLuint (APIENTRYP PFNGLGENPATHSNVPROC) (GLsizei range);
typedef void (APIENTRYP PFNGLDELETEPATHSNVPROC) (GLuint path, GLsizei range);
typedef GLboolean (APIENTRYP PFNGLISPATHNVPROC) (GLuint path);
typedef void (APIENTRYP PFNGLPATHCOMMANDSNVPROC) (GLuint path, GLsizei numCommands, const GLubyte *commands, GLsizei numCoords, GLenum coordType, const void *coords);
typedef void (APIENTRYP PFNGLPATHCOORDSNVPROC) (GLuint path, GLsizei numCoords, GLenum coordType, const void *coords);
typedef void (APIENTRYP PFNGLPATHSUBCOMMANDSNVPROC) (GLuint path, GLsizei commandStart, GLsizei commandsToDelete, GLsizei numCommands, const GLubyte *commands, GLsizei numCoords, GLenum coordType, const void *coords);
typedef void (APIENTRYP PFNGLPATHSUBCOORDSNVPROC) (GLuint path, GLsizei coordStart, GLsizei numCoords, GLenum coordType, const void *coords);
typedef void (APIENTRYP PFNGLPATHSTRINGNVPROC) (GLuint path, GLenum format, GLsizei length, const void *pathString);
typedef void (APIENTRYP PFNGLPATHGLYPHSNVPROC) (GLuint firstPathName, GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLsizei numGlyphs, GLenum type, const void *charcodes, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
typedef void (APIENTRYP PFNGLPATHGLYPHRANGENVPROC) (GLuint firstPathName, GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLuint firstGlyph, GLsizei numGlyphs, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
typedef void (APIENTRYP PFNGLWEIGHTPATHSNVPROC) (GLuint resultPath, GLsizei numPaths, const GLuint *paths, const GLfloat *weights);
typedef void (APIENTRYP PFNGLCOPYPATHNVPROC) (GLuint resultPath, GLuint srcPath);
typedef void (APIENTRYP PFNGLINTERPOLATEPATHSNVPROC) (GLuint resultPath, GLuint pathA, GLuint pathB, GLfloat weight);
typedef void (APIENTRYP PFNGLTRANSFORMPATHNVPROC) (GLuint resultPath, GLuint srcPath, GLenum transformType, const GLfloat *transformValues);
typedef void (APIENTRYP PFNGLPATHPARAMETERIVNVPROC) (GLuint path, GLenum pname, const GLint *value);
typedef void (APIENTRYP PFNGLPATHPARAMETERINVPROC) (GLuint path, GLenum pname, GLint value);
typedef void (APIENTRYP PFNGLPATHPARAMETERFVNVPROC) (GLuint path, GLenum pname, const GLfloat *value);
typedef void (APIENTRYP PFNGLPATHPARAMETERFNVPROC) (GLuint path, GLenum pname, GLfloat value);
typedef void (APIENTRYP PFNGLPATHDASHARRAYNVPROC) (GLuint path, GLsizei dashCount, const GLfloat *dashArray);
typedef void (APIENTRYP PFNGLPATHSTENCILFUNCNVPROC) (GLenum func, GLint ref, GLuint mask);
typedef void (APIENTRYP PFNGLPATHSTENCILDEPTHOFFSETNVPROC) (GLfloat factor, GLfloat units);
typedef void (APIENTRYP PFNGLSTENCILFILLPATHNVPROC) (GLuint path, GLenum fillMode, GLuint mask);
typedef void (APIENTRYP PFNGLSTENCILSTROKEPATHNVPROC) (GLuint path, GLint reference, GLuint mask);
typedef void (APIENTRYP PFNGLSTENCILFILLPATHINSTANCEDNVPROC) (GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum transformType, const GLfloat *transformValues);
typedef void (APIENTRYP PFNGLSTENCILSTROKEPATHINSTANCEDNVPROC) (GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLint reference, GLuint mask, GLenum transformType, const GLfloat *transformValues);
typedef void (APIENTRYP PFNGLPATHCOVERDEPTHFUNCNVPROC) (GLenum func);
typedef void (APIENTRYP PFNGLCOVERFILLPATHNVPROC) (GLuint path, GLenum coverMode);
typedef void (APIENTRYP PFNGLCOVERSTROKEPATHNVPROC) (GLuint path, GLenum coverMode);
typedef void (APIENTRYP PFNGLCOVERFILLPATHINSTANCEDNVPROC) (GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum coverMode, GLenum transformType, const GLfloat *transformValues);
typedef void (APIENTRYP PFNGLCOVERSTROKEPATHINSTANCEDNVPROC) (GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum coverMode, GLenum transformType, const GLfloat *transformValues);
typedef void (APIENTRYP PFNGLGETPATHPARAMETERIVNVPROC) (GLuint path, GLenum pname, GLint *value);
typedef void (APIENTRYP PFNGLGETPATHPARAMETERFVNVPROC) (GLuint path, GLenum pname, GLfloat *value);
typedef void (APIENTRYP PFNGLGETPATHCOMMANDSNVPROC) (GLuint path, GLubyte *commands);
typedef void (APIENTRYP PFNGLGETPATHCOORDSNVPROC) (GLuint path, GLfloat *coords);
typedef void (APIENTRYP PFNGLGETPATHDASHARRAYNVPROC) (GLuint path, GLfloat *dashArray);
typedef void (APIENTRYP PFNGLGETPATHMETRICSNVPROC) (GLbitfield metricQueryMask, GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLsizei stride, GLfloat *metrics);
typedef void (APIENTRYP PFNGLGETPATHMETRICRANGENVPROC) (GLbitfield metricQueryMask, GLuint firstPathName, GLsizei numPaths, GLsizei stride, GLfloat *metrics);
typedef void (APIENTRYP PFNGLGETPATHSPACINGNVPROC) (GLenum pathListMode, GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLfloat advanceScale, GLfloat kerningScale, GLenum transformType, GLfloat *returnedSpacing);
typedef GLboolean (APIENTRYP PFNGLISPOINTINFILLPATHNVPROC) (GLuint path, GLuint mask, GLfloat x, GLfloat y);
typedef GLboolean (APIENTRYP PFNGLISPOINTINSTROKEPATHNVPROC) (GLuint path, GLfloat x, GLfloat y);
typedef GLfloat (APIENTRYP PFNGLGETPATHLENGTHNVPROC) (GLuint path, GLsizei startSegment, GLsizei numSegments);
typedef GLboolean (APIENTRYP PFNGLPOINTALONGPATHNVPROC) (GLuint path, GLsizei startSegment, GLsizei numSegments, GLfloat distance, GLfloat *x, GLfloat *y, GLfloat *tangentX, GLfloat *tangentY);
typedef void (APIENTRYP PFNGLMATRIXLOAD3X2FNVPROC) (GLenum matrixMode, const GLfloat *m);
typedef void (APIENTRYP PFNGLMATRIXLOAD3X3FNVPROC) (GLenum matrixMode, const GLfloat *m);
typedef void (APIENTRYP PFNGLMATRIXLOADTRANSPOSE3X3FNVPROC) (GLenum matrixMode, const GLfloat *m);
typedef void (APIENTRYP PFNGLMATRIXMULT3X2FNVPROC) (GLenum matrixMode, const GLfloat *m);
typedef void (APIENTRYP PFNGLMATRIXMULT3X3FNVPROC) (GLenum matrixMode, const GLfloat *m);
typedef void (APIENTRYP PFNGLMATRIXMULTTRANSPOSE3X3FNVPROC) (GLenum matrixMode, const GLfloat *m);
typedef void (APIENTRYP PFNGLSTENCILTHENCOVERFILLPATHNVPROC) (GLuint path, GLenum fillMode, GLuint mask, GLenum coverMode);
typedef void (APIENTRYP PFNGLSTENCILTHENCOVERSTROKEPATHNVPROC) (GLuint path, GLint reference, GLuint mask, GLenum coverMode);
typedef void (APIENTRYP PFNGLSTENCILTHENCOVERFILLPATHINSTANCEDNVPROC) (GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum coverMode, GLenum transformType, const GLfloat *transformValues);
typedef void (APIENTRYP PFNGLSTENCILTHENCOVERSTROKEPATHINSTANCEDNVPROC) (GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLint reference, GLuint mask, GLenum coverMode, GLenum transformType, const GLfloat *transformValues);
typedef GLenum (APIENTRYP PFNGLPATHGLYPHINDEXRANGENVPROC) (GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLuint pathParameterTemplate, GLfloat emScale, GLuint *baseAndCount);
typedef GLenum (APIENTRYP PFNGLPATHGLYPHINDEXARRAYNVPROC) (GLuint firstPathName, GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLuint firstGlyphIndex, GLsizei numGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
typedef GLenum (APIENTRYP PFNGLPATHMEMORYGLYPHINDEXARRAYNVPROC) (GLuint firstPathName, GLenum fontTarget, GLsizeiptr fontSize, const void *fontData, GLsizei faceIndex, GLuint firstGlyphIndex, GLsizei numGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
typedef void (APIENTRYP PFNGLPROGRAMPATHFRAGMENTINPUTGENNVPROC) (GLuint program, GLint location, GLenum genMode, GLint components, const GLfloat *coeffs);
typedef void (APIENTRYP PFNGLGETPROGRAMRESOURCEFVNVPROC) (GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei count, GLsizei *length, GLfloat *params);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI GLuint APIENTRY glGenPathsNV (GLsizei range);
GLAPI void APIENTRY glDeletePathsNV (GLuint path, GLsizei range);
GLAPI GLboolean APIENTRY glIsPathNV (GLuint path);
GLAPI void APIENTRY glPathCommandsNV (GLuint path, GLsizei numCommands, const GLubyte *commands, GLsizei numCoords, GLenum coordType, const void *coords);
GLAPI void APIENTRY glPathCoordsNV (GLuint path, GLsizei numCoords, GLenum coordType, const void *coords);
GLAPI void APIENTRY glPathSubCommandsNV (GLuint path, GLsizei commandStart, GLsizei commandsToDelete, GLsizei numCommands, const GLubyte *commands, GLsizei numCoords, GLenum coordType, const void *coords);
GLAPI void APIENTRY glPathSubCoordsNV (GLuint path, GLsizei coordStart, GLsizei numCoords, GLenum coordType, const void *coords);
GLAPI void APIENTRY glPathStringNV (GLuint path, GLenum format, GLsizei length, const void *pathString);
GLAPI void APIENTRY glPathGlyphsNV (GLuint firstPathName, GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLsizei numGlyphs, GLenum type, const void *charcodes, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
GLAPI void APIENTRY glPathGlyphRangeNV (GLuint firstPathName, GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLuint firstGlyph, GLsizei numGlyphs, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
GLAPI void APIENTRY glWeightPathsNV (GLuint resultPath, GLsizei numPaths, const GLuint *paths, const GLfloat *weights);
GLAPI void APIENTRY glCopyPathNV (GLuint resultPath, GLuint srcPath);
GLAPI void APIENTRY glInterpolatePathsNV (GLuint resultPath, GLuint pathA, GLuint pathB, GLfloat weight);
GLAPI void APIENTRY glTransformPathNV (GLuint resultPath, GLuint srcPath, GLenum transformType, const GLfloat *transformValues);
GLAPI void APIENTRY glPathParameterivNV (GLuint path, GLenum pname, const GLint *value);
GLAPI void APIENTRY glPathParameteriNV (GLuint path, GLenum pname, GLint value);
GLAPI void APIENTRY glPathParameterfvNV (GLuint path, GLenum pname, const GLfloat *value);
GLAPI void APIENTRY glPathParameterfNV (GLuint path, GLenum pname, GLfloat value);
GLAPI void APIENTRY glPathDashArrayNV (GLuint path, GLsizei dashCount, const GLfloat *dashArray);
GLAPI void APIENTRY glPathStencilFuncNV (GLenum func, GLint ref, GLuint mask);
GLAPI void APIENTRY glPathStencilDepthOffsetNV (GLfloat factor, GLfloat units);
GLAPI void APIENTRY glStencilFillPathNV (GLuint path, GLenum fillMode, GLuint mask);
GLAPI void APIENTRY glStencilStrokePathNV (GLuint path, GLint reference, GLuint mask);
GLAPI void APIENTRY glStencilFillPathInstancedNV (GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum transformType, const GLfloat *transformValues);
GLAPI void APIENTRY glStencilStrokePathInstancedNV (GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLint reference, GLuint mask, GLenum transformType, const GLfloat *transformValues);
GLAPI void APIENTRY glPathCoverDepthFuncNV (GLenum func);
GLAPI void APIENTRY glCoverFillPathNV (GLuint path, GLenum coverMode);
GLAPI void APIENTRY glCoverStrokePathNV (GLuint path, GLenum coverMode);
GLAPI void APIENTRY glCoverFillPathInstancedNV (GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum coverMode, GLenum transformType, const GLfloat *transformValues);
GLAPI void APIENTRY glCoverStrokePathInstancedNV (GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum coverMode, GLenum transformType, const GLfloat *transformValues);
GLAPI void APIENTRY glGetPathParameterivNV (GLuint path, GLenum pname, GLint *value);
GLAPI void APIENTRY glGetPathParameterfvNV (GLuint path, GLenum pname, GLfloat *value);
GLAPI void APIENTRY glGetPathCommandsNV (GLuint path, GLubyte *commands);
GLAPI void APIENTRY glGetPathCoordsNV (GLuint path, GLfloat *coords);
GLAPI void APIENTRY glGetPathDashArrayNV (GLuint path, GLfloat *dashArray);
GLAPI void APIENTRY glGetPathMetricsNV (GLbitfield metricQueryMask, GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLsizei stride, GLfloat *metrics);
GLAPI void APIENTRY glGetPathMetricRangeNV (GLbitfield metricQueryMask, GLuint firstPathName, GLsizei numPaths, GLsizei stride, GLfloat *metrics);
GLAPI void APIENTRY glGetPathSpacingNV (GLenum pathListMode, GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLfloat advanceScale, GLfloat kerningScale, GLenum transformType, GLfloat *returnedSpacing);
GLAPI GLboolean APIENTRY glIsPointInFillPathNV (GLuint path, GLuint mask, GLfloat x, GLfloat y);
GLAPI GLboolean APIENTRY glIsPointInStrokePathNV (GLuint path, GLfloat x, GLfloat y);
GLAPI GLfloat APIENTRY glGetPathLengthNV (GLuint path, GLsizei startSegment, GLsizei numSegments);
GLAPI GLboolean APIENTRY glPointAlongPathNV (GLuint path, GLsizei startSegment, GLsizei numSegments, GLfloat distance, GLfloat *x, GLfloat *y, GLfloat *tangentX, GLfloat *tangentY);
GLAPI void APIENTRY glMatrixLoad3x2fNV (GLenum matrixMode, const GLfloat *m);
GLAPI void APIENTRY glMatrixLoad3x3fNV (GLenum matrixMode, const GLfloat *m);
GLAPI void APIENTRY glMatrixLoadTranspose3x3fNV (GLenum matrixMode, const GLfloat *m);
GLAPI void APIENTRY glMatrixMult3x2fNV (GLenum matrixMode, const GLfloat *m);
GLAPI void APIENTRY glMatrixMult3x3fNV (GLenum matrixMode, const GLfloat *m);
GLAPI void APIENTRY glMatrixMultTranspose3x3fNV (GLenum matrixMode, const GLfloat *m);
GLAPI void APIENTRY glStencilThenCoverFillPathNV (GLuint path, GLenum fillMode, GLuint mask, GLenum coverMode);
GLAPI void APIENTRY glStencilThenCoverStrokePathNV (GLuint path, GLint reference, GLuint mask, GLenum coverMode);
GLAPI void APIENTRY glStencilThenCoverFillPathInstancedNV (GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum coverMode, GLenum transformType, const GLfloat *transformValues);
GLAPI void APIENTRY glStencilThenCoverStrokePathInstancedNV (GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLint reference, GLuint mask, GLenum coverMode, GLenum transformType, const GLfloat *transformValues);
GLAPI GLenum APIENTRY glPathGlyphIndexRangeNV (GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLuint pathParameterTemplate, GLfloat emScale, GLuint *baseAndCount);
GLAPI GLenum APIENTRY glPathGlyphIndexArrayNV (GLuint firstPathName, GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLuint firstGlyphIndex, GLsizei numGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
GLAPI GLenum APIENTRY glPathMemoryGlyphIndexArrayNV (GLuint firstPathName, GLenum fontTarget, GLsizeiptr fontSize, const void *fontData, GLsizei faceIndex, GLuint firstGlyphIndex, GLsizei numGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
GLAPI void APIENTRY glProgramPathFragmentInputGenNV (GLuint program, GLint location, GLenum genMode, GLint components, const GLfloat *coeffs);
GLAPI void APIENTRY glGetProgramResourcefvNV (GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei count, GLsizei *length, GLfloat *params);
#endif
#endif /* GL_NV_path_rendering */
#ifndef GL_NV_path_rendering_shared_edge
#define GL_NV_path_rendering_shared_edge 1
#define GL_SHARED_EDGE_NV                 0xC0
#endif /* GL_NV_path_rendering_shared_edge */
#ifndef GL_NV_primitive_shading_rate
#define GL_NV_primitive_shading_rate 1
#define GL_SHADING_RATE_IMAGE_PER_PRIMITIVE_NV 0x95B1
#define GL_SHADING_RATE_IMAGE_PALETTE_COUNT_NV 0x95B2
#endif /* GL_NV_primitive_shading_rate */
#ifndef GL_NV_representative_fragment_test
#define GL_NV_representative_fragment_test 1
#define GL_REPRESENTATIVE_FRAGMENT_TEST_NV 0x937F
#endif /* GL_NV_representative_fragment_test */
#ifndef GL_NV_sample_locations
#define GL_NV_sample_locations 1
#define GL_SAMPLE_LOCATION_SUBPIXEL_BITS_NV 0x933D
#define GL_SAMPLE_LOCATION_PIXEL_GRID_WIDTH_NV 0x933E
#define GL_SAMPLE_LOCATION_PIXEL_GRID_HEIGHT_NV 0x933F
#define GL_PROGRAMMABLE_SAMPLE_LOCATION_TABLE_SIZE_NV 0x9340
#define GL_SAMPLE_LOCATION_NV             0x8E50
#define GL_PROGRAMMABLE_SAMPLE_LOCATION_NV 0x9341
#define GL_FRAMEBUFFER_PROGRAMMABLE_SAMPLE_LOCATIONS_NV 0x9342
#define GL_FRAMEBUFFER_SAMPLE_LOCATION_PIXEL_GRID_NV 0x9343
typedef void (APIENTRYP PFNGLFRAMEBUFFERSAMPLELOCATIONSFVNVPROC) (GLenum target, GLuint start, GLsizei count, const GLfloat *v);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVNVPROC) (GLuint framebuffer, GLuint start, GLsizei count, const GLfloat *v);
typedef void (APIENTRYP PFNGLRESOLVEDEPTHVALUESNVPROC) (void);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glFramebufferSampleLocationsfvNV (GLenum target, GLuint start, GLsizei count, const GLfloat *v);
GLAPI void APIENTRY glNamedFramebufferSampleLocationsfvNV (GLuint framebuffer, GLuint start, GLsizei count, const GLfloat *v);
GLAPI void APIENTRY glResolveDepthValuesNV (void);
#endif
#endif /* GL_NV_sample_locations */
#ifndef GL_NV_sample_mask_override_coverage
#define GL_NV_sample_mask_override_coverage 1
#endif /* GL_NV_sample_mask_override_coverage */
#ifndef GL_NV_scissor_exclusive
#define GL_NV_scissor_exclusive 1
#define GL_SCISSOR_TEST_EXCLUSIVE_NV      0x9555
#define GL_SCISSOR_BOX_EXCLUSIVE_NV       0x9556
typedef void (APIENTRYP PFNGLSCISSOREXCLUSIVENVPROC) (GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLSCISSOREXCLUSIVEARRAYVNVPROC) (GLuint first, GLsizei count, const GLint *v);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glScissorExclusiveNV (GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI void APIENTRY glScissorExclusiveArrayvNV (GLuint first, GLsizei count, const GLint *v);
#endif
#endif /* GL_NV_scissor_exclusive */
#ifndef GL_NV_shader_atomic_counters
#define GL_NV_shader_atomic_counters 1
#endif /* GL_NV_shader_atomic_counters */
#ifndef GL_NV_shader_atomic_float
#define GL_NV_shader_atomic_float 1
#endif /* GL_NV_shader_atomic_float */
#ifndef GL_NV_shader_atomic_float64
#define GL_NV_shader_atomic_float64 1
#endif /* GL_NV_shader_atomic_float64 */
#ifndef GL_NV_shader_atomic_fp16_vector
#define GL_NV_shader_atomic_fp16_vector 1
#endif /* GL_NV_shader_atomic_fp16_vector */
#ifndef GL_NV_shader_atomic_int64
#define GL_NV_shader_atomic_int64 1
#endif /* GL_NV_shader_atomic_int64 */
#ifndef GL_NV_shader_buffer_load
#define GL_NV_shader_buffer_load 1
#define GL_BUFFER_GPU_ADDRESS_NV          0x8F1D
#define GL_GPU_ADDRESS_NV                 0x8F34
#define GL_MAX_SHADER_BUFFER_ADDRESS_NV   0x8F35
typedef void (APIENTRYP PFNGLMAKEBUFFERRESIDENTNVPROC) (GLenum target, GLenum access);
typedef void (APIENTRYP PFNGLMAKEBUFFERNONRESIDENTNVPROC) (GLenum target);
typedef GLboolean (APIENTRYP PFNGLISBUFFERRESIDENTNVPROC) (GLenum target);
typedef void (APIENTRYP PFNGLMAKENAMEDBUFFERRESIDENTNVPROC) (GLuint buffer, GLenum access);
typedef void (APIENTRYP PFNGLMAKENAMEDBUFFERNONRESIDENTNVPROC) (GLuint buffer);
typedef GLboolean (APIENTRYP PFNGLISNAMEDBUFFERRESIDENTNVPROC) (GLuint buffer);
typedef void (APIENTRYP PFNGLGETBUFFERPARAMETERUI64VNVPROC) (GLenum target, GLenum pname, GLuint64EXT *params);
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPARAMETERUI64VNVPROC) (GLuint buffer, GLenum pname, GLuint64EXT *params);
typedef void (APIENTRYP PFNGLGETINTEGERUI64VNVPROC) (GLenum value, GLuint64EXT *result);
typedef void (APIENTRYP PFNGLUNIFORMUI64NVPROC) (GLint location, GLuint64EXT value);
typedef void (APIENTRYP PFNGLUNIFORMUI64VNVPROC) (GLint location, GLsizei count, const GLuint64EXT *value);
typedef void (APIENTRYP PFNGLGETUNIFORMUI64VNVPROC) (GLuint program, GLint location, GLuint64EXT *params);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMUI64NVPROC) (GLuint program, GLint location, GLuint64EXT value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMUI64VNVPROC) (GLuint program, GLint location, GLsizei count, const GLuint64EXT *value);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glMakeBufferResidentNV (GLenum target, GLenum access);
GLAPI void APIENTRY glMakeBufferNonResidentNV (GLenum target);
GLAPI GLboolean APIENTRY glIsBufferResidentNV (GLenum target);
GLAPI void APIENTRY glMakeNamedBufferResidentNV (GLuint buffer, GLenum access);
GLAPI void APIENTRY glMakeNamedBufferNonResidentNV (GLuint buffer);
GLAPI GLboolean APIENTRY glIsNamedBufferResidentNV (GLuint buffer);
GLAPI void APIENTRY glGetBufferParameterui64vNV (GLenum target, GLenum pname, GLuint64EXT *params);
GLAPI void APIENTRY glGetNamedBufferParameterui64vNV (GLuint buffer, GLenum pname, GLuint64EXT *params);
GLAPI void APIENTRY glGetIntegerui64vNV (GLenum value, GLuint64EXT *result);
GLAPI void APIENTRY glUniformui64NV (GLint location, GLuint64EXT value);
GLAPI void APIENTRY glUniformui64vNV (GLint location, GLsizei count, const GLuint64EXT *value);
GLAPI void APIENTRY glGetUniformui64vNV (GLuint program, GLint location, GLuint64EXT *params);
GLAPI void APIENTRY glProgramUniformui64NV (GLuint program, GLint location, GLuint64EXT value);
GLAPI void APIENTRY glProgramUniformui64vNV (GLuint program, GLint location, GLsizei count, const GLuint64EXT *value);
#endif
#endif /* GL_NV_shader_buffer_load */
#ifndef GL_NV_shader_buffer_store
#define GL_NV_shader_buffer_store 1
#define GL_SHADER_GLOBAL_ACCESS_BARRIER_BIT_NV 0x00000010
#endif /* GL_NV_shader_buffer_store */
#ifndef GL_NV_shader_subgroup_partitioned
#define GL_NV_shader_subgroup_partitioned 1
#define GL_SUBGROUP_FEATURE_PARTITIONED_BIT_NV 0x00000100
#endif /* GL_NV_shader_subgroup_partitioned */
#ifndef GL_NV_shader_texture_footprint
#define GL_NV_shader_texture_footprint 1
#endif /* GL_NV_shader_texture_footprint */
#ifndef GL_NV_shader_thread_group
#define GL_NV_shader_thread_group 1
#define GL_WARP_SIZE_NV                   0x9339
#define GL_WARPS_PER_SM_NV                0x933A
#define GL_SM_COUNT_NV                    0x933B
#endif /* GL_NV_shader_thread_group */
#ifndef GL_NV_shader_thread_shuffle
#define GL_NV_shader_thread_shuffle 1
#endif /* GL_NV_shader_thread_shuffle */
#ifndef GL_NV_shading_rate_image
#define GL_NV_shading_rate_image 1
#define GL_SHADING_RATE_IMAGE_NV          0x9563
#define GL_SHADING_RATE_NO_INVOCATIONS_NV 0x9564
#define GL_SHADING_RATE_1_INVOCATION_PER_PIXEL_NV 0x9565
#define GL_SHADING_RATE_1_INVOCATION_PER_1X2_PIXELS_NV 0x9566
#define GL_SHADING_RATE_1_INVOCATION_PER_2X1_PIXELS_NV 0x9567
#define GL_SHADING_RATE_1_INVOCATION_PER_2X2_PIXELS_NV 0x9568
#define GL_SHADING_RATE_1_INVOCATION_PER_2X4_PIXELS_NV 0x9569
#define GL_SHADING_RATE_1_INVOCATION_PER_4X2_PIXELS_NV 0x956A
#define GL_SHADING_RATE_1_INVOCATION_PER_4X4_PIXELS_NV 0x956B
#define GL_SHADING_RATE_2_INVOCATIONS_PER_PIXEL_NV 0x956C
#define GL_SHADING_RATE_4_INVOCATIONS_PER_PIXEL_NV 0x956D
#define GL_SHADING_RATE_8_INVOCATIONS_PER_PIXEL_NV 0x956E
#define GL_SHADING_RATE_16_INVOCATIONS_PER_PIXEL_NV 0x956F
#define GL_SHADING_RATE_IMAGE_BINDING_NV  0x955B
#define GL_SHADING_RATE_IMAGE_TEXEL_WIDTH_NV 0x955C
#define GL_SHADING_RATE_IMAGE_TEXEL_HEIGHT_NV 0x955D
#define GL_SHADING_RATE_IMAGE_PALETTE_SIZE_NV 0x955E
#define GL_MAX_COARSE_FRAGMENT_SAMPLES_NV 0x955F
#define GL_SHADING_RATE_SAMPLE_ORDER_DEFAULT_NV 0x95AE
#define GL_SHADING_RATE_SAMPLE_ORDER_PIXEL_MAJOR_NV 0x95AF
#define GL_SHADING_RATE_SAMPLE_ORDER_SAMPLE_MAJOR_NV 0x95B0
typedef void (APIENTRYP PFNGLBINDSHADINGRATEIMAGENVPROC) (GLuint texture);
typedef void (APIENTRYP PFNGLGETSHADINGRATEIMAGEPALETTENVPROC) (GLuint viewport, GLuint entry, GLenum *rate);
typedef void (APIENTRYP PFNGLGETSHADINGRATESAMPLELOCATIONIVNVPROC) (GLenum rate, GLuint samples, GLuint index, GLint *location);
typedef void (APIENTRYP PFNGLSHADINGRATEIMAGEBARRIERNVPROC) (GLboolean synchronize);
typedef void (APIENTRYP PFNGLSHADINGRATEIMAGEPALETTENVPROC) (GLuint viewport, GLuint first, GLsizei count, const GLenum *rates);
typedef void (APIENTRYP PFNGLSHADINGRATESAMPLEORDERNVPROC) (GLenum order);
typedef void (APIENTRYP PFNGLSHADINGRATESAMPLEORDERCUSTOMNVPROC) (GLenum rate, GLuint samples, const GLint *locations);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glBindShadingRateImageNV (GLuint texture);
GLAPI void APIENTRY glGetShadingRateImagePaletteNV (GLuint viewport, GLuint entry, GLenum *rate);
GLAPI void APIENTRY glGetShadingRateSampleLocationivNV (GLenum rate, GLuint samples, GLuint index, GLint *location);
GLAPI void APIENTRY glShadingRateImageBarrierNV (GLboolean synchronize);
GLAPI void APIENTRY glShadingRateImagePaletteNV (GLuint viewport, GLuint first, GLsizei count, const GLenum *rates);
GLAPI void APIENTRY glShadingRateSampleOrderNV (GLenum order);
GLAPI void APIENTRY glShadingRateSampleOrderCustomNV (GLenum rate, GLuint samples, const GLint *locations);
#endif
#endif /* GL_NV_shading_rate_image */
#ifndef GL_NV_stereo_view_rendering
#define GL_NV_stereo_view_rendering 1
#endif /* GL_NV_stereo_view_rendering */
#ifndef GL_NV_texture_barrier
#define GL_NV_texture_barrier 1
typedef void (APIENTRYP PFNGLTEXTUREBARRIERNVPROC) (void);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glTextureBarrierNV (void);
#endif
#endif /* GL_NV_texture_barrier */
#ifndef GL_NV_texture_rectangle_compressed
#define GL_NV_texture_rectangle_compressed 1
#endif /* GL_NV_texture_rectangle_compressed */
#ifndef GL_NV_uniform_buffer_std430_layout
#define GL_NV_uniform_buffer_std430_layout 1
#endif /* GL_NV_uniform_buffer_std430_layout */
#ifndef GL_NV_uniform_buffer_unified_memory
#define GL_NV_uniform_buffer_unified_memory 1
#define GL_UNIFORM_BUFFER_UNIFIED_NV      0x936E
#define GL_UNIFORM_BUFFER_ADDRESS_NV      0x936F
#define GL_UNIFORM_BUFFER_LENGTH_NV       0x9370
#endif /* GL_NV_uniform_buffer_unified_memory */
#ifndef GL_NV_vertex_attrib_integer_64bit
#define GL_NV_vertex_attrib_integer_64bit 1
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1I64NVPROC) (GLuint index, GLint64EXT x);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL2I64NVPROC) (GLuint index, GLint64EXT x, GLint64EXT y);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL3I64NVPROC) (GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL4I64NVPROC) (GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1I64VNVPROC) (GLuint index, const GLint64EXT *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL2I64VNVPROC) (GLuint index, const GLint64EXT *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL3I64VNVPROC) (GLuint index, const GLint64EXT *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL4I64VNVPROC) (GLuint index, const GLint64EXT *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1UI64NVPROC) (GLuint index, GLuint64EXT x);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL2UI64NVPROC) (GLuint index, GLuint64EXT x, GLuint64EXT y);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL3UI64NVPROC) (GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL4UI64NVPROC) (GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1UI64VNVPROC) (GLuint index, const GLuint64EXT *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL2UI64VNVPROC) (GLuint index, const GLuint64EXT *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL3UI64VNVPROC) (GLuint index, const GLuint64EXT *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL4UI64VNVPROC) (GLuint index, const GLuint64EXT *v);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBLI64VNVPROC) (GLuint index, GLenum pname, GLint64EXT *params);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBLUI64VNVPROC) (GLuint index, GLenum pname, GLuint64EXT *params);
typedef void (APIENTRYP PFNGLVERTEXATTRIBLFORMATNVPROC) (GLuint index, GLint size, GLenum type, GLsizei stride);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glVertexAttribL1i64NV (GLuint index, GLint64EXT x);
GLAPI void APIENTRY glVertexAttribL2i64NV (GLuint index, GLint64EXT x, GLint64EXT y);
GLAPI void APIENTRY glVertexAttribL3i64NV (GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z);
GLAPI void APIENTRY glVertexAttribL4i64NV (GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
GLAPI void APIENTRY glVertexAttribL1i64vNV (GLuint index, const GLint64EXT *v);
GLAPI void APIENTRY glVertexAttribL2i64vNV (GLuint index, const GLint64EXT *v);
GLAPI void APIENTRY glVertexAttribL3i64vNV (GLuint index, const GLint64EXT *v);
GLAPI void APIENTRY glVertexAttribL4i64vNV (GLuint index, const GLint64EXT *v);
GLAPI void APIENTRY glVertexAttribL1ui64NV (GLuint index, GLuint64EXT x);
GLAPI void APIENTRY glVertexAttribL2ui64NV (GLuint index, GLuint64EXT x, GLuint64EXT y);
GLAPI void APIENTRY glVertexAttribL3ui64NV (GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
GLAPI void APIENTRY glVertexAttribL4ui64NV (GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
GLAPI void APIENTRY glVertexAttribL1ui64vNV (GLuint index, const GLuint64EXT *v);
GLAPI void APIENTRY glVertexAttribL2ui64vNV (GLuint index, const GLuint64EXT *v);
GLAPI void APIENTRY glVertexAttribL3ui64vNV (GLuint index, const GLuint64EXT *v);
GLAPI void APIENTRY glVertexAttribL4ui64vNV (GLuint index, const GLuint64EXT *v);
GLAPI void APIENTRY glGetVertexAttribLi64vNV (GLuint index, GLenum pname, GLint64EXT *params);
GLAPI void APIENTRY glGetVertexAttribLui64vNV (GLuint index, GLenum pname, GLuint64EXT *params);
GLAPI void APIENTRY glVertexAttribLFormatNV (GLuint index, GLint size, GLenum type, GLsizei stride);
#endif
#endif /* GL_NV_vertex_attrib_integer_64bit */
#ifndef GL_NV_vertex_buffer_unified_memory
#define GL_NV_vertex_buffer_unified_memory 1
#define GL_VERTEX_ATTRIB_ARRAY_UNIFIED_NV 0x8F1E
#define GL_ELEMENT_ARRAY_UNIFIED_NV       0x8F1F
#define GL_VERTEX_ATTRIB_ARRAY_ADDRESS_NV 0x8F20
#define GL_VERTEX_ARRAY_ADDRESS_NV        0x8F21
#define GL_NORMAL_ARRAY_ADDRESS_NV        0x8F22
#define GL_COLOR_ARRAY_ADDRESS_NV         0x8F23
#define GL_INDEX_ARRAY_ADDRESS_NV         0x8F24
#define GL_TEXTURE_COORD_ARRAY_ADDRESS_NV 0x8F25
#define GL_EDGE_FLAG_ARRAY_ADDRESS_NV     0x8F26
#define GL_SECONDARY_COLOR_ARRAY_ADDRESS_NV 0x8F27
#define GL_FOG_COORD_ARRAY_ADDRESS_NV     0x8F28
#define GL_ELEMENT_ARRAY_ADDRESS_NV       0x8F29
#define GL_VERTEX_ATTRIB_ARRAY_LENGTH_NV  0x8F2A
#define GL_VERTEX_ARRAY_LENGTH_NV         0x8F2B
#define GL_NORMAL_ARRAY_LENGTH_NV         0x8F2C
#define GL_COLOR_ARRAY_LENGTH_NV          0x8F2D
#define GL_INDEX_ARRAY_LENGTH_NV          0x8F2E
#define GL_TEXTURE_COORD_ARRAY_LENGTH_NV  0x8F2F
#define GL_EDGE_FLAG_ARRAY_LENGTH_NV      0x8F30
#define GL_SECONDARY_COLOR_ARRAY_LENGTH_NV 0x8F31
#define GL_FOG_COORD_ARRAY_LENGTH_NV      0x8F32
#define GL_ELEMENT_ARRAY_LENGTH_NV        0x8F33
#define GL_DRAW_INDIRECT_UNIFIED_NV       0x8F40
#define GL_DRAW_INDIRECT_ADDRESS_NV       0x8F41
#define GL_DRAW_INDIRECT_LENGTH_NV        0x8F42
typedef void (APIENTRYP PFNGLBUFFERADDRESSRANGENVPROC) (GLenum pname, GLuint index, GLuint64EXT address, GLsizeiptr length);
typedef void (APIENTRYP PFNGLVERTEXFORMATNVPROC) (GLint size, GLenum type, GLsizei stride);
typedef void (APIENTRYP PFNGLNORMALFORMATNVPROC) (GLenum type, GLsizei stride);
typedef void (APIENTRYP PFNGLCOLORFORMATNVPROC) (GLint size, GLenum type, GLsizei stride);
typedef void (APIENTRYP PFNGLINDEXFORMATNVPROC) (GLenum type, GLsizei stride);
typedef void (APIENTRYP PFNGLTEXCOORDFORMATNVPROC) (GLint size, GLenum type, GLsizei stride);
typedef void (APIENTRYP PFNGLEDGEFLAGFORMATNVPROC) (GLsizei stride);
typedef void (APIENTRYP PFNGLSECONDARYCOLORFORMATNVPROC) (GLint size, GLenum type, GLsizei stride);
typedef void (APIENTRYP PFNGLFOGCOORDFORMATNVPROC) (GLenum type, GLsizei stride);
typedef void (APIENTRYP PFNGLVERTEXATTRIBFORMATNVPROC) (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride);
typedef void (APIENTRYP PFNGLVERTEXATTRIBIFORMATNVPROC) (GLuint index, GLint size, GLenum type, GLsizei stride);
typedef void (APIENTRYP PFNGLGETINTEGERUI64I_VNVPROC) (GLenum value, GLuint index, GLuint64EXT *result);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glBufferAddressRangeNV (GLenum pname, GLuint index, GLuint64EXT address, GLsizeiptr length);
GLAPI void APIENTRY glVertexFormatNV (GLint size, GLenum type, GLsizei stride);
GLAPI void APIENTRY glNormalFormatNV (GLenum type, GLsizei stride);
GLAPI void APIENTRY glColorFormatNV (GLint size, GLenum type, GLsizei stride);
GLAPI void APIENTRY glIndexFormatNV (GLenum type, GLsizei stride);
GLAPI void APIENTRY glTexCoordFormatNV (GLint size, GLenum type, GLsizei stride);
GLAPI void APIENTRY glEdgeFlagFormatNV (GLsizei stride);
GLAPI void APIENTRY glSecondaryColorFormatNV (GLint size, GLenum type, GLsizei stride);
GLAPI void APIENTRY glFogCoordFormatNV (GLenum type, GLsizei stride);
GLAPI void APIENTRY glVertexAttribFormatNV (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride);
GLAPI void APIENTRY glVertexAttribIFormatNV (GLuint index, GLint size, GLenum type, GLsizei stride);
GLAPI void APIENTRY glGetIntegerui64i_vNV (GLenum value, GLuint index, GLuint64EXT *result);
#endif
#endif /* GL_NV_vertex_buffer_unified_memory */
#ifndef GL_NV_viewport_array2
#define GL_NV_viewport_array2 1
#endif /* GL_NV_viewport_array2 */
#ifndef GL_NV_viewport_swizzle
#define GL_NV_viewport_swizzle 1
#define GL_VIEWPORT_SWIZZLE_POSITIVE_X_NV 0x9350
#define GL_VIEWPORT_SWIZZLE_NEGATIVE_X_NV 0x9351
#define GL_VIEWPORT_SWIZZLE_POSITIVE_Y_NV 0x9352
#define GL_VIEWPORT_SWIZZLE_NEGATIVE_Y_NV 0x9353
#define GL_VIEWPORT_SWIZZLE_POSITIVE_Z_NV 0x9354
#define GL_VIEWPORT_SWIZZLE_NEGATIVE_Z_NV 0x9355
#define GL_VIEWPORT_SWIZZLE_POSITIVE_W_NV 0x9356
#define GL_VIEWPORT_SWIZZLE_NEGATIVE_W_NV 0x9357
#define GL_VIEWPORT_SWIZZLE_X_NV          0x9358
#define GL_VIEWPORT_SWIZZLE_Y_NV          0x9359
#define GL_VIEWPORT_SWIZZLE_Z_NV          0x935A
#define GL_VIEWPORT_SWIZZLE_W_NV          0x935B
typedef void (APIENTRYP PFNGLVIEWPORTSWIZZLENVPROC) (GLuint index, GLenum swizzlex, GLenum swizzley, GLenum swizzlez, GLenum swizzlew);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glViewportSwizzleNV (GLuint index, GLenum swizzlex, GLenum swizzley, GLenum swizzlez, GLenum swizzlew);
#endif
#endif /* GL_NV_viewport_swizzle */
#ifndef GL_OVR_multiview
#define GL_OVR_multiview 1
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_NUM_VIEWS_OVR 0x9630
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_BASE_VIEW_INDEX_OVR 0x9632
#define GL_MAX_VIEWS_OVR                  0x9631
#define GL_FRAMEBUFFER_INCOMPLETE_VIEW_TARGETS_OVR 0x9633
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTUREMULTIVIEWOVRPROC) (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint baseViewIndex, GLsizei numViews);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTUREMULTIVIEWOVRPROC) (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint baseViewIndex, GLsizei numViews);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glFramebufferTextureMultiviewOVR (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint baseViewIndex, GLsizei numViews);
GLAPI void APIENTRY glNamedFramebufferTextureMultiviewOVR (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint baseViewIndex, GLsizei numViews);
#endif
#endif /* GL_OVR_multiview */
#ifndef GL_OVR_multiview2
#define GL_OVR_multiview2 1
#endif /* GL_OVR_multiview2 */
#ifdef __cplusplus
}
#endif
#endif

#ifndef GL3W_API
#define GL3W_API
#endif

#ifndef __gl_h_
#define __gl_h_
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define GL3W_OK 0
#define GL3W_ERROR_INIT -1
#define GL3W_ERROR_LIBRARY_OPEN -2
#define GL3W_ERROR_OPENGL_VERSION -3

typedef void (*GL3WglProc)(void);
typedef GL3WglProc (*GL3WGetProcAddressProc)(const char *proc);

/* gl3w api */
GL3W_API int imgl3wInit(void);
GL3W_API int imgl3wInit2(GL3WGetProcAddressProc proc);
GL3W_API int imgl3wIsSupported(int major, int minor);
GL3W_API GL3WglProc imgl3wGetProcAddress(const char *proc);

/* gl3w internal state */
union ImGL3WProcs {
    GL3WglProc ptr[1279];
    struct {
        PFNGLACTIVEPROGRAMEXTPROC                               ActiveProgramEXT;
        PFNGLACTIVESHADERPROGRAMPROC                            ActiveShaderProgram;
        PFNGLACTIVETEXTUREPROC                                  ActiveTexture;
        PFNGLAPPLYFRAMEBUFFERATTACHMENTCMAAINTELPROC            ApplyFramebufferAttachmentCMAAINTEL;
        PFNGLATTACHSHADERPROC                                   AttachShader;
        PFNGLBEGINCONDITIONALRENDERPROC                         BeginConditionalRender;
        PFNGLBEGINCONDITIONALRENDERNVPROC                       BeginConditionalRenderNV;
        PFNGLBEGINPERFMONITORAMDPROC                            BeginPerfMonitorAMD;
        PFNGLBEGINPERFQUERYINTELPROC                            BeginPerfQueryINTEL;
        PFNGLBEGINQUERYPROC                                     BeginQuery;
        PFNGLBEGINQUERYINDEXEDPROC                              BeginQueryIndexed;
        PFNGLBEGINTRANSFORMFEEDBACKPROC                         BeginTransformFeedback;
        PFNGLBINDATTRIBLOCATIONPROC                             BindAttribLocation;
        PFNGLBINDBUFFERPROC                                     BindBuffer;
        PFNGLBINDBUFFERBASEPROC                                 BindBufferBase;
        PFNGLBINDBUFFERRANGEPROC                                BindBufferRange;
        PFNGLBINDBUFFERSBASEPROC                                BindBuffersBase;
        PFNGLBINDBUFFERSRANGEPROC                               BindBuffersRange;
        PFNGLBINDFRAGDATALOCATIONPROC                           BindFragDataLocation;
        PFNGLBINDFRAGDATALOCATIONINDEXEDPROC                    BindFragDataLocationIndexed;
        PFNGLBINDFRAMEBUFFERPROC                                BindFramebuffer;
        PFNGLBINDIMAGETEXTUREPROC                               BindImageTexture;
        PFNGLBINDIMAGETEXTURESPROC                              BindImageTextures;
        PFNGLBINDMULTITEXTUREEXTPROC                            BindMultiTextureEXT;
        PFNGLBINDPROGRAMPIPELINEPROC                            BindProgramPipeline;
        PFNGLBINDRENDERBUFFERPROC                               BindRenderbuffer;
        PFNGLBINDSAMPLERPROC                                    BindSampler;
        PFNGLBINDSAMPLERSPROC                                   BindSamplers;
        PFNGLBINDSHADINGRATEIMAGENVPROC                         BindShadingRateImageNV;
        PFNGLBINDTEXTUREPROC                                    BindTexture;
        PFNGLBINDTEXTUREUNITPROC                                BindTextureUnit;
        PFNGLBINDTEXTURESPROC                                   BindTextures;
        PFNGLBINDTRANSFORMFEEDBACKPROC                          BindTransformFeedback;
        PFNGLBINDVERTEXARRAYPROC                                BindVertexArray;
        PFNGLBINDVERTEXBUFFERPROC                               BindVertexBuffer;
        PFNGLBINDVERTEXBUFFERSPROC                              BindVertexBuffers;
        PFNGLBLENDBARRIERKHRPROC                                BlendBarrierKHR;
        PFNGLBLENDBARRIERNVPROC                                 BlendBarrierNV;
        PFNGLBLENDCOLORPROC                                     BlendColor;
        PFNGLBLENDEQUATIONPROC                                  BlendEquation;
        PFNGLBLENDEQUATIONSEPARATEPROC                          BlendEquationSeparate;
        PFNGLBLENDEQUATIONSEPARATEIPROC                         BlendEquationSeparatei;
        PFNGLBLENDEQUATIONSEPARATEIARBPROC                      BlendEquationSeparateiARB;
        PFNGLBLENDEQUATIONIPROC                                 BlendEquationi;
        PFNGLBLENDEQUATIONIARBPROC                              BlendEquationiARB;
        PFNGLBLENDFUNCPROC                                      BlendFunc;
        PFNGLBLENDFUNCSEPARATEPROC                              BlendFuncSeparate;
        PFNGLBLENDFUNCSEPARATEIPROC                             BlendFuncSeparatei;
        PFNGLBLENDFUNCSEPARATEIARBPROC                          BlendFuncSeparateiARB;
        PFNGLBLENDFUNCIPROC                                     BlendFunci;
        PFNGLBLENDFUNCIARBPROC                                  BlendFunciARB;
        PFNGLBLENDPARAMETERINVPROC                              BlendParameteriNV;
        PFNGLBLITFRAMEBUFFERPROC                                BlitFramebuffer;
        PFNGLBLITNAMEDFRAMEBUFFERPROC                           BlitNamedFramebuffer;
        PFNGLBUFFERADDRESSRANGENVPROC                           BufferAddressRangeNV;
        PFNGLBUFFERATTACHMEMORYNVPROC                           BufferAttachMemoryNV;
        PFNGLBUFFERDATAPROC                                     BufferData;
        PFNGLBUFFERPAGECOMMITMENTARBPROC                        BufferPageCommitmentARB;
        PFNGLBUFFERPAGECOMMITMENTMEMNVPROC                      BufferPageCommitmentMemNV;
        PFNGLBUFFERSTORAGEPROC                                  BufferStorage;
        PFNGLBUFFERSUBDATAPROC                                  BufferSubData;
        PFNGLCALLCOMMANDLISTNVPROC                              CallCommandListNV;
        PFNGLCHECKFRAMEBUFFERSTATUSPROC                         CheckFramebufferStatus;
        PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC                    CheckNamedFramebufferStatus;
        PFNGLCHECKNAMEDFRAMEBUFFERSTATUSEXTPROC                 CheckNamedFramebufferStatusEXT;
        PFNGLCLAMPCOLORPROC                                     ClampColor;
        PFNGLCLEARPROC                                          Clear;
        PFNGLCLEARBUFFERDATAPROC                                ClearBufferData;
        PFNGLCLEARBUFFERSUBDATAPROC                             ClearBufferSubData;
        PFNGLCLEARBUFFERFIPROC                                  ClearBufferfi;
        PFNGLCLEARBUFFERFVPROC                                  ClearBufferfv;
        PFNGLCLEARBUFFERIVPROC                                  ClearBufferiv;
        PFNGLCLEARBUFFERUIVPROC                                 ClearBufferuiv;
        PFNGLCLEARCOLORPROC                                     ClearColor;
        PFNGLCLEARDEPTHPROC                                     ClearDepth;
        PFNGLCLEARDEPTHDNVPROC                                  ClearDepthdNV;
        PFNGLCLEARDEPTHFPROC                                    ClearDepthf;
        PFNGLCLEARNAMEDBUFFERDATAPROC                           ClearNamedBufferData;
        PFNGLCLEARNAMEDBUFFERDATAEXTPROC                        ClearNamedBufferDataEXT;
        PFNGLCLEARNAMEDBUFFERSUBDATAPROC                        ClearNamedBufferSubData;
        PFNGLCLEARNAMEDBUFFERSUBDATAEXTPROC                     ClearNamedBufferSubDataEXT;
        PFNGLCLEARNAMEDFRAMEBUFFERFIPROC                        ClearNamedFramebufferfi;
        PFNGLCLEARNAMEDFRAMEBUFFERFVPROC                        ClearNamedFramebufferfv;
        PFNGLCLEARNAMEDFRAMEBUFFERIVPROC                        ClearNamedFramebufferiv;
        PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC                       ClearNamedFramebufferuiv;
        PFNGLCLEARSTENCILPROC                                   ClearStencil;
        PFNGLCLEARTEXIMAGEPROC                                  ClearTexImage;
        PFNGLCLEARTEXSUBIMAGEPROC                               ClearTexSubImage;
        PFNGLCLIENTATTRIBDEFAULTEXTPROC                         ClientAttribDefaultEXT;
        PFNGLCLIENTWAITSYNCPROC                                 ClientWaitSync;
        PFNGLCLIPCONTROLPROC                                    ClipControl;
        PFNGLCOLORFORMATNVPROC                                  ColorFormatNV;
        PFNGLCOLORMASKPROC                                      ColorMask;
        PFNGLCOLORMASKIPROC                                     ColorMaski;
        PFNGLCOMMANDLISTSEGMENTSNVPROC                          CommandListSegmentsNV;
        PFNGLCOMPILECOMMANDLISTNVPROC                           CompileCommandListNV;
        PFNGLCOMPILESHADERPROC                                  CompileShader;
        PFNGLCOMPILESHADERINCLUDEARBPROC                        CompileShaderIncludeARB;
        PFNGLCOMPRESSEDMULTITEXIMAGE1DEXTPROC                   CompressedMultiTexImage1DEXT;
        PFNGLCOMPRESSEDMULTITEXIMAGE2DEXTPROC                   CompressedMultiTexImage2DEXT;
        PFNGLCOMPRESSEDMULTITEXIMAGE3DEXTPROC                   CompressedMultiTexImage3DEXT;
        PFNGLCOMPRESSEDMULTITEXSUBIMAGE1DEXTPROC                CompressedMultiTexSubImage1DEXT;
        PFNGLCOMPRESSEDMULTITEXSUBIMAGE2DEXTPROC                CompressedMultiTexSubImage2DEXT;
        PFNGLCOMPRESSEDMULTITEXSUBIMAGE3DEXTPROC                CompressedMultiTexSubImage3DEXT;
        PFNGLCOMPRESSEDTEXIMAGE1DPROC                           CompressedTexImage1D;
        PFNGLCOMPRESSEDTEXIMAGE2DPROC                           CompressedTexImage2D;
        PFNGLCOMPRESSEDTEXIMAGE3DPROC                           CompressedTexImage3D;
        PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC                        CompressedTexSubImage1D;
        PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC                        CompressedTexSubImage2D;
        PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC                        CompressedTexSubImage3D;
        PFNGLCOMPRESSEDTEXTUREIMAGE1DEXTPROC                    CompressedTextureImage1DEXT;
        PFNGLCOMPRESSEDTEXTUREIMAGE2DEXTPROC                    CompressedTextureImage2DEXT;
        PFNGLCOMPRESSEDTEXTUREIMAGE3DEXTPROC                    CompressedTextureImage3DEXT;
        PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC                    CompressedTextureSubImage1D;
        PFNGLCOMPRESSEDTEXTURESUBIMAGE1DEXTPROC                 CompressedTextureSubImage1DEXT;
        PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC                    CompressedTextureSubImage2D;
        PFNGLCOMPRESSEDTEXTURESUBIMAGE2DEXTPROC                 CompressedTextureSubImage2DEXT;
        PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC                    CompressedTextureSubImage3D;
        PFNGLCOMPRESSEDTEXTURESUBIMAGE3DEXTPROC                 CompressedTextureSubImage3DEXT;
        PFNGLCONSERVATIVERASTERPARAMETERFNVPROC                 ConservativeRasterParameterfNV;
        PFNGLCONSERVATIVERASTERPARAMETERINVPROC                 ConservativeRasterParameteriNV;
        PFNGLCOPYBUFFERSUBDATAPROC                              CopyBufferSubData;
        PFNGLCOPYIMAGESUBDATAPROC                               CopyImageSubData;
        PFNGLCOPYMULTITEXIMAGE1DEXTPROC                         CopyMultiTexImage1DEXT;
        PFNGLCOPYMULTITEXIMAGE2DEXTPROC                         CopyMultiTexImage2DEXT;
        PFNGLCOPYMULTITEXSUBIMAGE1DEXTPROC                      CopyMultiTexSubImage1DEXT;
        PFNGLCOPYMULTITEXSUBIMAGE2DEXTPROC                      CopyMultiTexSubImage2DEXT;
        PFNGLCOPYMULTITEXSUBIMAGE3DEXTPROC                      CopyMultiTexSubImage3DEXT;
        PFNGLCOPYNAMEDBUFFERSUBDATAPROC                         CopyNamedBufferSubData;
        PFNGLCOPYPATHNVPROC                                     CopyPathNV;
        PFNGLCOPYTEXIMAGE1DPROC                                 CopyTexImage1D;
        PFNGLCOPYTEXIMAGE2DPROC                                 CopyTexImage2D;
        PFNGLCOPYTEXSUBIMAGE1DPROC                              CopyTexSubImage1D;
        PFNGLCOPYTEXSUBIMAGE2DPROC                              CopyTexSubImage2D;
        PFNGLCOPYTEXSUBIMAGE3DPROC                              CopyTexSubImage3D;
        PFNGLCOPYTEXTUREIMAGE1DEXTPROC                          CopyTextureImage1DEXT;
        PFNGLCOPYTEXTUREIMAGE2DEXTPROC                          CopyTextureImage2DEXT;
        PFNGLCOPYTEXTURESUBIMAGE1DPROC                          CopyTextureSubImage1D;
        PFNGLCOPYTEXTURESUBIMAGE1DEXTPROC                       CopyTextureSubImage1DEXT;
        PFNGLCOPYTEXTURESUBIMAGE2DPROC                          CopyTextureSubImage2D;
        PFNGLCOPYTEXTURESUBIMAGE2DEXTPROC                       CopyTextureSubImage2DEXT;
        PFNGLCOPYTEXTURESUBIMAGE3DPROC                          CopyTextureSubImage3D;
        PFNGLCOPYTEXTURESUBIMAGE3DEXTPROC                       CopyTextureSubImage3DEXT;
        PFNGLCOVERFILLPATHINSTANCEDNVPROC                       CoverFillPathInstancedNV;
        PFNGLCOVERFILLPATHNVPROC                                CoverFillPathNV;
        PFNGLCOVERSTROKEPATHINSTANCEDNVPROC                     CoverStrokePathInstancedNV;
        PFNGLCOVERSTROKEPATHNVPROC                              CoverStrokePathNV;
        PFNGLCOVERAGEMODULATIONNVPROC                           CoverageModulationNV;
        PFNGLCOVERAGEMODULATIONTABLENVPROC                      CoverageModulationTableNV;
        PFNGLCREATEBUFFERSPROC                                  CreateBuffers;
        PFNGLCREATECOMMANDLISTSNVPROC                           CreateCommandListsNV;
        PFNGLCREATEFRAMEBUFFERSPROC                             CreateFramebuffers;
        PFNGLCREATEPERFQUERYINTELPROC                           CreatePerfQueryINTEL;
        PFNGLCREATEPROGRAMPROC                                  CreateProgram;
        PFNGLCREATEPROGRAMPIPELINESPROC                         CreateProgramPipelines;
        PFNGLCREATEQUERIESPROC                                  CreateQueries;
        PFNGLCREATERENDERBUFFERSPROC                            CreateRenderbuffers;
        PFNGLCREATESAMPLERSPROC                                 CreateSamplers;
        PFNGLCREATESHADERPROC                                   CreateShader;
        PFNGLCREATESHADERPROGRAMEXTPROC                         CreateShaderProgramEXT;
        PFNGLCREATESHADERPROGRAMVPROC                           CreateShaderProgramv;
        PFNGLCREATESTATESNVPROC                                 CreateStatesNV;
        PFNGLCREATESYNCFROMCLEVENTARBPROC                       CreateSyncFromCLeventARB;
        PFNGLCREATETEXTURESPROC                                 CreateTextures;
        PFNGLCREATETRANSFORMFEEDBACKSPROC                       CreateTransformFeedbacks;
        PFNGLCREATEVERTEXARRAYSPROC                             CreateVertexArrays;
        PFNGLCULLFACEPROC                                       CullFace;
        PFNGLDEBUGMESSAGECALLBACKPROC                           DebugMessageCallback;
        PFNGLDEBUGMESSAGECALLBACKARBPROC                        DebugMessageCallbackARB;
        PFNGLDEBUGMESSAGECONTROLPROC                            DebugMessageControl;
        PFNGLDEBUGMESSAGECONTROLARBPROC                         DebugMessageControlARB;
        PFNGLDEBUGMESSAGEINSERTPROC                             DebugMessageInsert;
        PFNGLDEBUGMESSAGEINSERTARBPROC                          DebugMessageInsertARB;
        PFNGLDELETEBUFFERSPROC                                  DeleteBuffers;
        PFNGLDELETECOMMANDLISTSNVPROC                           DeleteCommandListsNV;
        PFNGLDELETEFRAMEBUFFERSPROC                             DeleteFramebuffers;
        PFNGLDELETENAMEDSTRINGARBPROC                           DeleteNamedStringARB;
        PFNGLDELETEPATHSNVPROC                                  DeletePathsNV;
        PFNGLDELETEPERFMONITORSAMDPROC                          DeletePerfMonitorsAMD;
        PFNGLDELETEPERFQUERYINTELPROC                           DeletePerfQueryINTEL;
        PFNGLDELETEPROGRAMPROC                                  DeleteProgram;
        PFNGLDELETEPROGRAMPIPELINESPROC                         DeleteProgramPipelines;
        PFNGLDELETEQUERIESPROC                                  DeleteQueries;
        PFNGLDELETERENDERBUFFERSPROC                            DeleteRenderbuffers;
        PFNGLDELETESAMPLERSPROC                                 DeleteSamplers;
        PFNGLDELETESHADERPROC                                   DeleteShader;
        PFNGLDELETESTATESNVPROC                                 DeleteStatesNV;
        PFNGLDELETESYNCPROC                                     DeleteSync;
        PFNGLDELETETEXTURESPROC                                 DeleteTextures;
        PFNGLDELETETRANSFORMFEEDBACKSPROC                       DeleteTransformFeedbacks;
        PFNGLDELETEVERTEXARRAYSPROC                             DeleteVertexArrays;
        PFNGLDEPTHBOUNDSDNVPROC                                 DepthBoundsdNV;
        PFNGLDEPTHFUNCPROC                                      DepthFunc;
        PFNGLDEPTHMASKPROC                                      DepthMask;
        PFNGLDEPTHRANGEPROC                                     DepthRange;
        PFNGLDEPTHRANGEARRAYDVNVPROC                            DepthRangeArraydvNV;
        PFNGLDEPTHRANGEARRAYVPROC                               DepthRangeArrayv;
        PFNGLDEPTHRANGEINDEXEDPROC                              DepthRangeIndexed;
        PFNGLDEPTHRANGEINDEXEDDNVPROC                           DepthRangeIndexeddNV;
        PFNGLDEPTHRANGEDNVPROC                                  DepthRangedNV;
        PFNGLDEPTHRANGEFPROC                                    DepthRangef;
        PFNGLDETACHSHADERPROC                                   DetachShader;
        PFNGLDISABLEPROC                                        Disable;
        PFNGLDISABLECLIENTSTATEINDEXEDEXTPROC                   DisableClientStateIndexedEXT;
        PFNGLDISABLECLIENTSTATEIEXTPROC                         DisableClientStateiEXT;
        PFNGLDISABLEINDEXEDEXTPROC                              DisableIndexedEXT;
        PFNGLDISABLEVERTEXARRAYATTRIBPROC                       DisableVertexArrayAttrib;
        PFNGLDISABLEVERTEXARRAYATTRIBEXTPROC                    DisableVertexArrayAttribEXT;
        PFNGLDISABLEVERTEXARRAYEXTPROC                          DisableVertexArrayEXT;
        PFNGLDISABLEVERTEXATTRIBARRAYPROC                       DisableVertexAttribArray;
        PFNGLDISABLEIPROC                                       Disablei;
        PFNGLDISPATCHCOMPUTEPROC                                DispatchCompute;
        PFNGLDISPATCHCOMPUTEGROUPSIZEARBPROC                    DispatchComputeGroupSizeARB;
        PFNGLDISPATCHCOMPUTEINDIRECTPROC                        DispatchComputeIndirect;
        PFNGLDRAWARRAYSPROC                                     DrawArrays;
        PFNGLDRAWARRAYSINDIRECTPROC                             DrawArraysIndirect;
        PFNGLDRAWARRAYSINSTANCEDPROC                            DrawArraysInstanced;
        PFNGLDRAWARRAYSINSTANCEDARBPROC                         DrawArraysInstancedARB;
        PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC                DrawArraysInstancedBaseInstance;
        PFNGLDRAWARRAYSINSTANCEDEXTPROC                         DrawArraysInstancedEXT;
        PFNGLDRAWBUFFERPROC                                     DrawBuffer;
        PFNGLDRAWBUFFERSPROC                                    DrawBuffers;
        PFNGLDRAWCOMMANDSADDRESSNVPROC                          DrawCommandsAddressNV;
        PFNGLDRAWCOMMANDSNVPROC                                 DrawCommandsNV;
        PFNGLDRAWCOMMANDSSTATESADDRESSNVPROC                    DrawCommandsStatesAddressNV;
        PFNGLDRAWCOMMANDSSTATESNVPROC                           DrawCommandsStatesNV;
        PFNGLDRAWELEMENTSPROC                                   DrawElements;
        PFNGLDRAWELEMENTSBASEVERTEXPROC                         DrawElementsBaseVertex;
        PFNGLDRAWELEMENTSINDIRECTPROC                           DrawElementsIndirect;
        PFNGLDRAWELEMENTSINSTANCEDPROC                          DrawElementsInstanced;
        PFNGLDRAWELEMENTSINSTANCEDARBPROC                       DrawElementsInstancedARB;
        PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC              DrawElementsInstancedBaseInstance;
        PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC                DrawElementsInstancedBaseVertex;
        PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC    DrawElementsInstancedBaseVertexBaseInstance;
        PFNGLDRAWELEMENTSINSTANCEDEXTPROC                       DrawElementsInstancedEXT;
        PFNGLDRAWMESHTASKSINDIRECTNVPROC                        DrawMeshTasksIndirectNV;
        PFNGLDRAWMESHTASKSNVPROC                                DrawMeshTasksNV;
        PFNGLDRAWRANGEELEMENTSPROC                              DrawRangeElements;
        PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC                    DrawRangeElementsBaseVertex;
        PFNGLDRAWTRANSFORMFEEDBACKPROC                          DrawTransformFeedback;
        PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC                 DrawTransformFeedbackInstanced;
        PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC                    DrawTransformFeedbackStream;
        PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC           DrawTransformFeedbackStreamInstanced;
        PFNGLDRAWVKIMAGENVPROC                                  DrawVkImageNV;
        PFNGLEGLIMAGETARGETTEXSTORAGEEXTPROC                    EGLImageTargetTexStorageEXT;
        PFNGLEGLIMAGETARGETTEXTURESTORAGEEXTPROC                EGLImageTargetTextureStorageEXT;
        PFNGLEDGEFLAGFORMATNVPROC                               EdgeFlagFormatNV;
        PFNGLENABLEPROC                                         Enable;
        PFNGLENABLECLIENTSTATEINDEXEDEXTPROC                    EnableClientStateIndexedEXT;
        PFNGLENABLECLIENTSTATEIEXTPROC                          EnableClientStateiEXT;
        PFNGLENABLEINDEXEDEXTPROC                               EnableIndexedEXT;
        PFNGLENABLEVERTEXARRAYATTRIBPROC                        EnableVertexArrayAttrib;
        PFNGLENABLEVERTEXARRAYATTRIBEXTPROC                     EnableVertexArrayAttribEXT;
        PFNGLENABLEVERTEXARRAYEXTPROC                           EnableVertexArrayEXT;
        PFNGLENABLEVERTEXATTRIBARRAYPROC                        EnableVertexAttribArray;
        PFNGLENABLEIPROC                                        Enablei;
        PFNGLENDCONDITIONALRENDERPROC                           EndConditionalRender;
        PFNGLENDCONDITIONALRENDERNVPROC                         EndConditionalRenderNV;
        PFNGLENDPERFMONITORAMDPROC                              EndPerfMonitorAMD;
        PFNGLENDPERFQUERYINTELPROC                              EndPerfQueryINTEL;
        PFNGLENDQUERYPROC                                       EndQuery;
        PFNGLENDQUERYINDEXEDPROC                                EndQueryIndexed;
        PFNGLENDTRANSFORMFEEDBACKPROC                           EndTransformFeedback;
        PFNGLEVALUATEDEPTHVALUESARBPROC                         EvaluateDepthValuesARB;
        PFNGLFENCESYNCPROC                                      FenceSync;
        PFNGLFINISHPROC                                         Finish;
        PFNGLFLUSHPROC                                          Flush;
        PFNGLFLUSHMAPPEDBUFFERRANGEPROC                         FlushMappedBufferRange;
        PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC                    FlushMappedNamedBufferRange;
        PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEEXTPROC                 FlushMappedNamedBufferRangeEXT;
        PFNGLFOGCOORDFORMATNVPROC                               FogCoordFormatNV;
        PFNGLFRAGMENTCOVERAGECOLORNVPROC                        FragmentCoverageColorNV;
        PFNGLFRAMEBUFFERDRAWBUFFEREXTPROC                       FramebufferDrawBufferEXT;
        PFNGLFRAMEBUFFERDRAWBUFFERSEXTPROC                      FramebufferDrawBuffersEXT;
        PFNGLFRAMEBUFFERFETCHBARRIEREXTPROC                     FramebufferFetchBarrierEXT;
        PFNGLFRAMEBUFFERPARAMETERIPROC                          FramebufferParameteri;
        PFNGLFRAMEBUFFERPARAMETERIMESAPROC                      FramebufferParameteriMESA;
        PFNGLFRAMEBUFFERREADBUFFEREXTPROC                       FramebufferReadBufferEXT;
        PFNGLFRAMEBUFFERRENDERBUFFERPROC                        FramebufferRenderbuffer;
        PFNGLFRAMEBUFFERSAMPLELOCATIONSFVARBPROC                FramebufferSampleLocationsfvARB;
        PFNGLFRAMEBUFFERSAMPLELOCATIONSFVNVPROC                 FramebufferSampleLocationsfvNV;
        PFNGLFRAMEBUFFERTEXTUREPROC                             FramebufferTexture;
        PFNGLFRAMEBUFFERTEXTURE1DPROC                           FramebufferTexture1D;
        PFNGLFRAMEBUFFERTEXTURE2DPROC                           FramebufferTexture2D;
        PFNGLFRAMEBUFFERTEXTURE3DPROC                           FramebufferTexture3D;
        PFNGLFRAMEBUFFERTEXTUREARBPROC                          FramebufferTextureARB;
        PFNGLFRAMEBUFFERTEXTUREFACEARBPROC                      FramebufferTextureFaceARB;
        PFNGLFRAMEBUFFERTEXTURELAYERPROC                        FramebufferTextureLayer;
        PFNGLFRAMEBUFFERTEXTURELAYERARBPROC                     FramebufferTextureLayerARB;
        PFNGLFRAMEBUFFERTEXTUREMULTIVIEWOVRPROC                 FramebufferTextureMultiviewOVR;
        PFNGLFRONTFACEPROC                                      FrontFace;
        PFNGLGENBUFFERSPROC                                     GenBuffers;
        PFNGLGENFRAMEBUFFERSPROC                                GenFramebuffers;
        PFNGLGENPATHSNVPROC                                     GenPathsNV;
        PFNGLGENPERFMONITORSAMDPROC                             GenPerfMonitorsAMD;
        PFNGLGENPROGRAMPIPELINESPROC                            GenProgramPipelines;
        PFNGLGENQUERIESPROC                                     GenQueries;
        PFNGLGENRENDERBUFFERSPROC                               GenRenderbuffers;
        PFNGLGENSAMPLERSPROC                                    GenSamplers;
        PFNGLGENTEXTURESPROC                                    GenTextures;
        PFNGLGENTRANSFORMFEEDBACKSPROC                          GenTransformFeedbacks;
        PFNGLGENVERTEXARRAYSPROC                                GenVertexArrays;
        PFNGLGENERATEMIPMAPPROC                                 GenerateMipmap;
        PFNGLGENERATEMULTITEXMIPMAPEXTPROC                      GenerateMultiTexMipmapEXT;
        PFNGLGENERATETEXTUREMIPMAPPROC                          GenerateTextureMipmap;
        PFNGLGENERATETEXTUREMIPMAPEXTPROC                       GenerateTextureMipmapEXT;
        PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC                 GetActiveAtomicCounterBufferiv;
        PFNGLGETACTIVEATTRIBPROC                                GetActiveAttrib;
        PFNGLGETACTIVESUBROUTINENAMEPROC                        GetActiveSubroutineName;
        PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC                 GetActiveSubroutineUniformName;
        PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC                   GetActiveSubroutineUniformiv;
        PFNGLGETACTIVEUNIFORMPROC                               GetActiveUniform;
        PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC                      GetActiveUniformBlockName;
        PFNGLGETACTIVEUNIFORMBLOCKIVPROC                        GetActiveUniformBlockiv;
        PFNGLGETACTIVEUNIFORMNAMEPROC                           GetActiveUniformName;
        PFNGLGETACTIVEUNIFORMSIVPROC                            GetActiveUniformsiv;
        PFNGLGETATTACHEDSHADERSPROC                             GetAttachedShaders;
        PFNGLGETATTRIBLOCATIONPROC                              GetAttribLocation;
        PFNGLGETBOOLEANINDEXEDVEXTPROC                          GetBooleanIndexedvEXT;
        PFNGLGETBOOLEANI_VPROC                                  GetBooleani_v;
        PFNGLGETBOOLEANVPROC                                    GetBooleanv;
        PFNGLGETBUFFERPARAMETERI64VPROC                         GetBufferParameteri64v;
        PFNGLGETBUFFERPARAMETERIVPROC                           GetBufferParameteriv;
        PFNGLGETBUFFERPARAMETERUI64VNVPROC                      GetBufferParameterui64vNV;
        PFNGLGETBUFFERPOINTERVPROC                              GetBufferPointerv;
        PFNGLGETBUFFERSUBDATAPROC                               GetBufferSubData;
        PFNGLGETCOMMANDHEADERNVPROC                             GetCommandHeaderNV;
        PFNGLGETCOMPRESSEDMULTITEXIMAGEEXTPROC                  GetCompressedMultiTexImageEXT;
        PFNGLGETCOMPRESSEDTEXIMAGEPROC                          GetCompressedTexImage;
        PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC                      GetCompressedTextureImage;
        PFNGLGETCOMPRESSEDTEXTUREIMAGEEXTPROC                   GetCompressedTextureImageEXT;
        PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC                   GetCompressedTextureSubImage;
        PFNGLGETCOVERAGEMODULATIONTABLENVPROC                   GetCoverageModulationTableNV;
        PFNGLGETDEBUGMESSAGELOGPROC                             GetDebugMessageLog;
        PFNGLGETDEBUGMESSAGELOGARBPROC                          GetDebugMessageLogARB;
        PFNGLGETDOUBLEINDEXEDVEXTPROC                           GetDoubleIndexedvEXT;
        PFNGLGETDOUBLEI_VPROC                                   GetDoublei_v;
        PFNGLGETDOUBLEI_VEXTPROC                                GetDoublei_vEXT;
        PFNGLGETDOUBLEVPROC                                     GetDoublev;
        PFNGLGETERRORPROC                                       GetError;
        PFNGLGETFIRSTPERFQUERYIDINTELPROC                       GetFirstPerfQueryIdINTEL;
        PFNGLGETFLOATINDEXEDVEXTPROC                            GetFloatIndexedvEXT;
        PFNGLGETFLOATI_VPROC                                    GetFloati_v;
        PFNGLGETFLOATI_VEXTPROC                                 GetFloati_vEXT;
        PFNGLGETFLOATVPROC                                      GetFloatv;
        PFNGLGETFRAGDATAINDEXPROC                               GetFragDataIndex;
        PFNGLGETFRAGDATALOCATIONPROC                            GetFragDataLocation;
        PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC            GetFramebufferAttachmentParameteriv;
        PFNGLGETFRAMEBUFFERPARAMETERIVPROC                      GetFramebufferParameteriv;
        PFNGLGETFRAMEBUFFERPARAMETERIVEXTPROC                   GetFramebufferParameterivEXT;
        PFNGLGETFRAMEBUFFERPARAMETERIVMESAPROC                  GetFramebufferParameterivMESA;
        PFNGLGETGRAPHICSRESETSTATUSPROC                         GetGraphicsResetStatus;
        PFNGLGETGRAPHICSRESETSTATUSARBPROC                      GetGraphicsResetStatusARB;
        PFNGLGETIMAGEHANDLEARBPROC                              GetImageHandleARB;
        PFNGLGETIMAGEHANDLENVPROC                               GetImageHandleNV;
        PFNGLGETINTEGER64I_VPROC                                GetInteger64i_v;
        PFNGLGETINTEGER64VPROC                                  GetInteger64v;
        PFNGLGETINTEGERINDEXEDVEXTPROC                          GetIntegerIndexedvEXT;
        PFNGLGETINTEGERI_VPROC                                  GetIntegeri_v;
        PFNGLGETINTEGERUI64I_VNVPROC                            GetIntegerui64i_vNV;
        PFNGLGETINTEGERUI64VNVPROC                              GetIntegerui64vNV;
        PFNGLGETINTEGERVPROC                                    GetIntegerv;
        PFNGLGETINTERNALFORMATSAMPLEIVNVPROC                    GetInternalformatSampleivNV;
        PFNGLGETINTERNALFORMATI64VPROC                          GetInternalformati64v;
        PFNGLGETINTERNALFORMATIVPROC                            GetInternalformativ;
        PFNGLGETMEMORYOBJECTDETACHEDRESOURCESUIVNVPROC          GetMemoryObjectDetachedResourcesuivNV;
        PFNGLGETMULTITEXENVFVEXTPROC                            GetMultiTexEnvfvEXT;
        PFNGLGETMULTITEXENVIVEXTPROC                            GetMultiTexEnvivEXT;
        PFNGLGETMULTITEXGENDVEXTPROC                            GetMultiTexGendvEXT;
        PFNGLGETMULTITEXGENFVEXTPROC                            GetMultiTexGenfvEXT;
        PFNGLGETMULTITEXGENIVEXTPROC                            GetMultiTexGenivEXT;
        PFNGLGETMULTITEXIMAGEEXTPROC                            GetMultiTexImageEXT;
        PFNGLGETMULTITEXLEVELPARAMETERFVEXTPROC                 GetMultiTexLevelParameterfvEXT;
        PFNGLGETMULTITEXLEVELPARAMETERIVEXTPROC                 GetMultiTexLevelParameterivEXT;
        PFNGLGETMULTITEXPARAMETERIIVEXTPROC                     GetMultiTexParameterIivEXT;
        PFNGLGETMULTITEXPARAMETERIUIVEXTPROC                    GetMultiTexParameterIuivEXT;
        PFNGLGETMULTITEXPARAMETERFVEXTPROC                      GetMultiTexParameterfvEXT;
        PFNGLGETMULTITEXPARAMETERIVEXTPROC                      GetMultiTexParameterivEXT;
        PFNGLGETMULTISAMPLEFVPROC                               GetMultisamplefv;
        PFNGLGETNAMEDBUFFERPARAMETERI64VPROC                    GetNamedBufferParameteri64v;
        PFNGLGETNAMEDBUFFERPARAMETERIVPROC                      GetNamedBufferParameteriv;
        PFNGLGETNAMEDBUFFERPARAMETERIVEXTPROC                   GetNamedBufferParameterivEXT;
        PFNGLGETNAMEDBUFFERPARAMETERUI64VNVPROC                 GetNamedBufferParameterui64vNV;
        PFNGLGETNAMEDBUFFERPOINTERVPROC                         GetNamedBufferPointerv;
        PFNGLGETNAMEDBUFFERPOINTERVEXTPROC                      GetNamedBufferPointervEXT;
        PFNGLGETNAMEDBUFFERSUBDATAPROC                          GetNamedBufferSubData;
        PFNGLGETNAMEDBUFFERSUBDATAEXTPROC                       GetNamedBufferSubDataEXT;
        PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC       GetNamedFramebufferAttachmentParameteriv;
        PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC    GetNamedFramebufferAttachmentParameterivEXT;
        PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC                 GetNamedFramebufferParameteriv;
        PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVEXTPROC              GetNamedFramebufferParameterivEXT;
        PFNGLGETNAMEDPROGRAMLOCALPARAMETERIIVEXTPROC            GetNamedProgramLocalParameterIivEXT;
        PFNGLGETNAMEDPROGRAMLOCALPARAMETERIUIVEXTPROC           GetNamedProgramLocalParameterIuivEXT;
        PFNGLGETNAMEDPROGRAMLOCALPARAMETERDVEXTPROC             GetNamedProgramLocalParameterdvEXT;
        PFNGLGETNAMEDPROGRAMLOCALPARAMETERFVEXTPROC             GetNamedProgramLocalParameterfvEXT;
        PFNGLGETNAMEDPROGRAMSTRINGEXTPROC                       GetNamedProgramStringEXT;
        PFNGLGETNAMEDPROGRAMIVEXTPROC                           GetNamedProgramivEXT;
        PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC                GetNamedRenderbufferParameteriv;
        PFNGLGETNAMEDRENDERBUFFERPARAMETERIVEXTPROC             GetNamedRenderbufferParameterivEXT;
        PFNGLGETNAMEDSTRINGARBPROC                              GetNamedStringARB;
        PFNGLGETNAMEDSTRINGIVARBPROC                            GetNamedStringivARB;
        PFNGLGETNEXTPERFQUERYIDINTELPROC                        GetNextPerfQueryIdINTEL;
        PFNGLGETOBJECTLABELPROC                                 GetObjectLabel;
        PFNGLGETOBJECTLABELEXTPROC                              GetObjectLabelEXT;
        PFNGLGETOBJECTPTRLABELPROC                              GetObjectPtrLabel;
        PFNGLGETPATHCOMMANDSNVPROC                              GetPathCommandsNV;
        PFNGLGETPATHCOORDSNVPROC                                GetPathCoordsNV;
        PFNGLGETPATHDASHARRAYNVPROC                             GetPathDashArrayNV;
        PFNGLGETPATHLENGTHNVPROC                                GetPathLengthNV;
        PFNGLGETPATHMETRICRANGENVPROC                           GetPathMetricRangeNV;
        PFNGLGETPATHMETRICSNVPROC                               GetPathMetricsNV;
        PFNGLGETPATHPARAMETERFVNVPROC                           GetPathParameterfvNV;
        PFNGLGETPATHPARAMETERIVNVPROC                           GetPathParameterivNV;
        PFNGLGETPATHSPACINGNVPROC                               GetPathSpacingNV;
        PFNGLGETPERFCOUNTERINFOINTELPROC                        GetPerfCounterInfoINTEL;
        PFNGLGETPERFMONITORCOUNTERDATAAMDPROC                   GetPerfMonitorCounterDataAMD;
        PFNGLGETPERFMONITORCOUNTERINFOAMDPROC                   GetPerfMonitorCounterInfoAMD;
        PFNGLGETPERFMONITORCOUNTERSTRINGAMDPROC                 GetPerfMonitorCounterStringAMD;
        PFNGLGETPERFMONITORCOUNTERSAMDPROC                      GetPerfMonitorCountersAMD;
        PFNGLGETPERFMONITORGROUPSTRINGAMDPROC                   GetPerfMonitorGroupStringAMD;
        PFNGLGETPERFMONITORGROUPSAMDPROC                        GetPerfMonitorGroupsAMD;
        PFNGLGETPERFQUERYDATAINTELPROC                          GetPerfQueryDataINTEL;
        PFNGLGETPERFQUERYIDBYNAMEINTELPROC                      GetPerfQueryIdByNameINTEL;
        PFNGLGETPERFQUERYINFOINTELPROC                          GetPerfQueryInfoINTEL;
        PFNGLGETPOINTERINDEXEDVEXTPROC                          GetPointerIndexedvEXT;
        PFNGLGETPOINTERI_VEXTPROC                               GetPointeri_vEXT;
        PFNGLGETPOINTERVPROC                                    GetPointerv;
        PFNGLGETPROGRAMBINARYPROC                               GetProgramBinary;
        PFNGLGETPROGRAMINFOLOGPROC                              GetProgramInfoLog;
        PFNGLGETPROGRAMINTERFACEIVPROC                          GetProgramInterfaceiv;
        PFNGLGETPROGRAMPIPELINEINFOLOGPROC                      GetProgramPipelineInfoLog;
        PFNGLGETPROGRAMPIPELINEIVPROC                           GetProgramPipelineiv;
        PFNGLGETPROGRAMRESOURCEINDEXPROC                        GetProgramResourceIndex;
        PFNGLGETPROGRAMRESOURCELOCATIONPROC                     GetProgramResourceLocation;
        PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC                GetProgramResourceLocationIndex;
        PFNGLGETPROGRAMRESOURCENAMEPROC                         GetProgramResourceName;
        PFNGLGETPROGRAMRESOURCEFVNVPROC                         GetProgramResourcefvNV;
        PFNGLGETPROGRAMRESOURCEIVPROC                           GetProgramResourceiv;
        PFNGLGETPROGRAMSTAGEIVPROC                              GetProgramStageiv;
        PFNGLGETPROGRAMIVPROC                                   GetProgramiv;
        PFNGLGETQUERYBUFFEROBJECTI64VPROC                       GetQueryBufferObjecti64v;
        PFNGLGETQUERYBUFFEROBJECTIVPROC                         GetQueryBufferObjectiv;
        PFNGLGETQUERYBUFFEROBJECTUI64VPROC                      GetQueryBufferObjectui64v;
        PFNGLGETQUERYBUFFEROBJECTUIVPROC                        GetQueryBufferObjectuiv;
        PFNGLGETQUERYINDEXEDIVPROC                              GetQueryIndexediv;
        PFNGLGETQUERYOBJECTI64VPROC                             GetQueryObjecti64v;
        PFNGLGETQUERYOBJECTIVPROC                               GetQueryObjectiv;
        PFNGLGETQUERYOBJECTUI64VPROC                            GetQueryObjectui64v;
        PFNGLGETQUERYOBJECTUIVPROC                              GetQueryObjectuiv;
        PFNGLGETQUERYIVPROC                                     GetQueryiv;
        PFNGLGETRENDERBUFFERPARAMETERIVPROC                     GetRenderbufferParameteriv;
        PFNGLGETSAMPLERPARAMETERIIVPROC                         GetSamplerParameterIiv;
        PFNGLGETSAMPLERPARAMETERIUIVPROC                        GetSamplerParameterIuiv;
        PFNGLGETSAMPLERPARAMETERFVPROC                          GetSamplerParameterfv;
        PFNGLGETSAMPLERPARAMETERIVPROC                          GetSamplerParameteriv;
        PFNGLGETSHADERINFOLOGPROC                               GetShaderInfoLog;
        PFNGLGETSHADERPRECISIONFORMATPROC                       GetShaderPrecisionFormat;
        PFNGLGETSHADERSOURCEPROC                                GetShaderSource;
        PFNGLGETSHADERIVPROC                                    GetShaderiv;
        PFNGLGETSHADINGRATEIMAGEPALETTENVPROC                   GetShadingRateImagePaletteNV;
        PFNGLGETSHADINGRATESAMPLELOCATIONIVNVPROC               GetShadingRateSampleLocationivNV;
        PFNGLGETSTAGEINDEXNVPROC                                GetStageIndexNV;
        PFNGLGETSTRINGPROC                                      GetString;
        PFNGLGETSTRINGIPROC                                     GetStringi;
        PFNGLGETSUBROUTINEINDEXPROC                             GetSubroutineIndex;
        PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC                   GetSubroutineUniformLocation;
        PFNGLGETSYNCIVPROC                                      GetSynciv;
        PFNGLGETTEXIMAGEPROC                                    GetTexImage;
        PFNGLGETTEXLEVELPARAMETERFVPROC                         GetTexLevelParameterfv;
        PFNGLGETTEXLEVELPARAMETERIVPROC                         GetTexLevelParameteriv;
        PFNGLGETTEXPARAMETERIIVPROC                             GetTexParameterIiv;
        PFNGLGETTEXPARAMETERIUIVPROC                            GetTexParameterIuiv;
        PFNGLGETTEXPARAMETERFVPROC                              GetTexParameterfv;
        PFNGLGETTEXPARAMETERIVPROC                              GetTexParameteriv;
        PFNGLGETTEXTUREHANDLEARBPROC                            GetTextureHandleARB;
        PFNGLGETTEXTUREHANDLENVPROC                             GetTextureHandleNV;
        PFNGLGETTEXTUREIMAGEPROC                                GetTextureImage;
        PFNGLGETTEXTUREIMAGEEXTPROC                             GetTextureImageEXT;
        PFNGLGETTEXTURELEVELPARAMETERFVPROC                     GetTextureLevelParameterfv;
        PFNGLGETTEXTURELEVELPARAMETERFVEXTPROC                  GetTextureLevelParameterfvEXT;
        PFNGLGETTEXTURELEVELPARAMETERIVPROC                     GetTextureLevelParameteriv;
        PFNGLGETTEXTURELEVELPARAMETERIVEXTPROC                  GetTextureLevelParameterivEXT;
        PFNGLGETTEXTUREPARAMETERIIVPROC                         GetTextureParameterIiv;
        PFNGLGETTEXTUREPARAMETERIIVEXTPROC                      GetTextureParameterIivEXT;
        PFNGLGETTEXTUREPARAMETERIUIVPROC                        GetTextureParameterIuiv;
        PFNGLGETTEXTUREPARAMETERIUIVEXTPROC                     GetTextureParameterIuivEXT;
        PFNGLGETTEXTUREPARAMETERFVPROC                          GetTextureParameterfv;
        PFNGLGETTEXTUREPARAMETERFVEXTPROC                       GetTextureParameterfvEXT;
        PFNGLGETTEXTUREPARAMETERIVPROC                          GetTextureParameteriv;
        PFNGLGETTEXTUREPARAMETERIVEXTPROC                       GetTextureParameterivEXT;
        PFNGLGETTEXTURESAMPLERHANDLEARBPROC                     GetTextureSamplerHandleARB;
        PFNGLGETTEXTURESAMPLERHANDLENVPROC                      GetTextureSamplerHandleNV;
        PFNGLGETTEXTURESUBIMAGEPROC                             GetTextureSubImage;
        PFNGLGETTRANSFORMFEEDBACKVARYINGPROC                    GetTransformFeedbackVarying;
        PFNGLGETTRANSFORMFEEDBACKI64_VPROC                      GetTransformFeedbacki64_v;
        PFNGLGETTRANSFORMFEEDBACKI_VPROC                        GetTransformFeedbacki_v;
        PFNGLGETTRANSFORMFEEDBACKIVPROC                         GetTransformFeedbackiv;
        PFNGLGETUNIFORMBLOCKINDEXPROC                           GetUniformBlockIndex;
        PFNGLGETUNIFORMINDICESPROC                              GetUniformIndices;
        PFNGLGETUNIFORMLOCATIONPROC                             GetUniformLocation;
        PFNGLGETUNIFORMSUBROUTINEUIVPROC                        GetUniformSubroutineuiv;
        PFNGLGETUNIFORMDVPROC                                   GetUniformdv;
        PFNGLGETUNIFORMFVPROC                                   GetUniformfv;
        PFNGLGETUNIFORMI64VARBPROC                              GetUniformi64vARB;
        PFNGLGETUNIFORMI64VNVPROC                               GetUniformi64vNV;
        PFNGLGETUNIFORMIVPROC                                   GetUniformiv;
        PFNGLGETUNIFORMUI64VARBPROC                             GetUniformui64vARB;
        PFNGLGETUNIFORMUI64VNVPROC                              GetUniformui64vNV;
        PFNGLGETUNIFORMUIVPROC                                  GetUniformuiv;
        PFNGLGETVERTEXARRAYINDEXED64IVPROC                      GetVertexArrayIndexed64iv;
        PFNGLGETVERTEXARRAYINDEXEDIVPROC                        GetVertexArrayIndexediv;
        PFNGLGETVERTEXARRAYINTEGERI_VEXTPROC                    GetVertexArrayIntegeri_vEXT;
        PFNGLGETVERTEXARRAYINTEGERVEXTPROC                      GetVertexArrayIntegervEXT;
        PFNGLGETVERTEXARRAYPOINTERI_VEXTPROC                    GetVertexArrayPointeri_vEXT;
        PFNGLGETVERTEXARRAYPOINTERVEXTPROC                      GetVertexArrayPointervEXT;
        PFNGLGETVERTEXARRAYIVPROC                               GetVertexArrayiv;
        PFNGLGETVERTEXATTRIBIIVPROC                             GetVertexAttribIiv;
        PFNGLGETVERTEXATTRIBIUIVPROC                            GetVertexAttribIuiv;
        PFNGLGETVERTEXATTRIBLDVPROC                             GetVertexAttribLdv;
        PFNGLGETVERTEXATTRIBLI64VNVPROC                         GetVertexAttribLi64vNV;
        PFNGLGETVERTEXATTRIBLUI64VARBPROC                       GetVertexAttribLui64vARB;
        PFNGLGETVERTEXATTRIBLUI64VNVPROC                        GetVertexAttribLui64vNV;
        PFNGLGETVERTEXATTRIBPOINTERVPROC                        GetVertexAttribPointerv;
        PFNGLGETVERTEXATTRIBDVPROC                              GetVertexAttribdv;
        PFNGLGETVERTEXATTRIBFVPROC                              GetVertexAttribfv;
        PFNGLGETVERTEXATTRIBIVPROC                              GetVertexAttribiv;
        PFNGLGETVKPROCADDRNVPROC                                GetVkProcAddrNV;
        PFNGLGETNCOMPRESSEDTEXIMAGEPROC                         GetnCompressedTexImage;
        PFNGLGETNCOMPRESSEDTEXIMAGEARBPROC                      GetnCompressedTexImageARB;
        PFNGLGETNTEXIMAGEPROC                                   GetnTexImage;
        PFNGLGETNTEXIMAGEARBPROC                                GetnTexImageARB;
        PFNGLGETNUNIFORMDVPROC                                  GetnUniformdv;
        PFNGLGETNUNIFORMDVARBPROC                               GetnUniformdvARB;
        PFNGLGETNUNIFORMFVPROC                                  GetnUniformfv;
        PFNGLGETNUNIFORMFVARBPROC                               GetnUniformfvARB;
        PFNGLGETNUNIFORMI64VARBPROC                             GetnUniformi64vARB;
        PFNGLGETNUNIFORMIVPROC                                  GetnUniformiv;
        PFNGLGETNUNIFORMIVARBPROC                               GetnUniformivARB;
        PFNGLGETNUNIFORMUI64VARBPROC                            GetnUniformui64vARB;
        PFNGLGETNUNIFORMUIVPROC                                 GetnUniformuiv;
        PFNGLGETNUNIFORMUIVARBPROC                              GetnUniformuivARB;
        PFNGLHINTPROC                                           Hint;
        PFNGLINDEXFORMATNVPROC                                  IndexFormatNV;
        PFNGLINSERTEVENTMARKEREXTPROC                           InsertEventMarkerEXT;
        PFNGLINTERPOLATEPATHSNVPROC                             InterpolatePathsNV;
        PFNGLINVALIDATEBUFFERDATAPROC                           InvalidateBufferData;
        PFNGLINVALIDATEBUFFERSUBDATAPROC                        InvalidateBufferSubData;
        PFNGLINVALIDATEFRAMEBUFFERPROC                          InvalidateFramebuffer;
        PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC                 InvalidateNamedFramebufferData;
        PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC              InvalidateNamedFramebufferSubData;
        PFNGLINVALIDATESUBFRAMEBUFFERPROC                       InvalidateSubFramebuffer;
        PFNGLINVALIDATETEXIMAGEPROC                             InvalidateTexImage;
        PFNGLINVALIDATETEXSUBIMAGEPROC                          InvalidateTexSubImage;
        PFNGLISBUFFERPROC                                       IsBuffer;
        PFNGLISBUFFERRESIDENTNVPROC                             IsBufferResidentNV;
        PFNGLISCOMMANDLISTNVPROC                                IsCommandListNV;
        PFNGLISENABLEDPROC                                      IsEnabled;
        PFNGLISENABLEDINDEXEDEXTPROC                            IsEnabledIndexedEXT;
        PFNGLISENABLEDIPROC                                     IsEnabledi;
        PFNGLISFRAMEBUFFERPROC                                  IsFramebuffer;
        PFNGLISIMAGEHANDLERESIDENTARBPROC                       IsImageHandleResidentARB;
        PFNGLISIMAGEHANDLERESIDENTNVPROC                        IsImageHandleResidentNV;
        PFNGLISNAMEDBUFFERRESIDENTNVPROC                        IsNamedBufferResidentNV;
        PFNGLISNAMEDSTRINGARBPROC                               IsNamedStringARB;
        PFNGLISPATHNVPROC                                       IsPathNV;
        PFNGLISPOINTINFILLPATHNVPROC                            IsPointInFillPathNV;
        PFNGLISPOINTINSTROKEPATHNVPROC                          IsPointInStrokePathNV;
        PFNGLISPROGRAMPROC                                      IsProgram;
        PFNGLISPROGRAMPIPELINEPROC                              IsProgramPipeline;
        PFNGLISQUERYPROC                                        IsQuery;
        PFNGLISRENDERBUFFERPROC                                 IsRenderbuffer;
        PFNGLISSAMPLERPROC                                      IsSampler;
        PFNGLISSHADERPROC                                       IsShader;
        PFNGLISSTATENVPROC                                      IsStateNV;
        PFNGLISSYNCPROC                                         IsSync;
        PFNGLISTEXTUREPROC                                      IsTexture;
        PFNGLISTEXTUREHANDLERESIDENTARBPROC                     IsTextureHandleResidentARB;
        PFNGLISTEXTUREHANDLERESIDENTNVPROC                      IsTextureHandleResidentNV;
        PFNGLISTRANSFORMFEEDBACKPROC                            IsTransformFeedback;
        PFNGLISVERTEXARRAYPROC                                  IsVertexArray;
        PFNGLLABELOBJECTEXTPROC                                 LabelObjectEXT;
        PFNGLLINEWIDTHPROC                                      LineWidth;
        PFNGLLINKPROGRAMPROC                                    LinkProgram;
        PFNGLLISTDRAWCOMMANDSSTATESCLIENTNVPROC                 ListDrawCommandsStatesClientNV;
        PFNGLLOGICOPPROC                                        LogicOp;
        PFNGLMAKEBUFFERNONRESIDENTNVPROC                        MakeBufferNonResidentNV;
        PFNGLMAKEBUFFERRESIDENTNVPROC                           MakeBufferResidentNV;
        PFNGLMAKEIMAGEHANDLENONRESIDENTARBPROC                  MakeImageHandleNonResidentARB;
        PFNGLMAKEIMAGEHANDLENONRESIDENTNVPROC                   MakeImageHandleNonResidentNV;
        PFNGLMAKEIMAGEHANDLERESIDENTARBPROC                     MakeImageHandleResidentARB;
        PFNGLMAKEIMAGEHANDLERESIDENTNVPROC                      MakeImageHandleResidentNV;
        PFNGLMAKENAMEDBUFFERNONRESIDENTNVPROC                   MakeNamedBufferNonResidentNV;
        PFNGLMAKENAMEDBUFFERRESIDENTNVPROC                      MakeNamedBufferResidentNV;
        PFNGLMAKETEXTUREHANDLENONRESIDENTARBPROC                MakeTextureHandleNonResidentARB;
        PFNGLMAKETEXTUREHANDLENONRESIDENTNVPROC                 MakeTextureHandleNonResidentNV;
        PFNGLMAKETEXTUREHANDLERESIDENTARBPROC                   MakeTextureHandleResidentARB;
        PFNGLMAKETEXTUREHANDLERESIDENTNVPROC                    MakeTextureHandleResidentNV;
        PFNGLMAPBUFFERPROC                                      MapBuffer;
        PFNGLMAPBUFFERRANGEPROC                                 MapBufferRange;
        PFNGLMAPNAMEDBUFFERPROC                                 MapNamedBuffer;
        PFNGLMAPNAMEDBUFFEREXTPROC                              MapNamedBufferEXT;
        PFNGLMAPNAMEDBUFFERRANGEPROC                            MapNamedBufferRange;
        PFNGLMAPNAMEDBUFFERRANGEEXTPROC                         MapNamedBufferRangeEXT;
        PFNGLMATRIXFRUSTUMEXTPROC                               MatrixFrustumEXT;
        PFNGLMATRIXLOAD3X2FNVPROC                               MatrixLoad3x2fNV;
        PFNGLMATRIXLOAD3X3FNVPROC                               MatrixLoad3x3fNV;
        PFNGLMATRIXLOADIDENTITYEXTPROC                          MatrixLoadIdentityEXT;
        PFNGLMATRIXLOADTRANSPOSE3X3FNVPROC                      MatrixLoadTranspose3x3fNV;
        PFNGLMATRIXLOADTRANSPOSEDEXTPROC                        MatrixLoadTransposedEXT;
        PFNGLMATRIXLOADTRANSPOSEFEXTPROC                        MatrixLoadTransposefEXT;
        PFNGLMATRIXLOADDEXTPROC                                 MatrixLoaddEXT;
        PFNGLMATRIXLOADFEXTPROC                                 MatrixLoadfEXT;
        PFNGLMATRIXMULT3X2FNVPROC                               MatrixMult3x2fNV;
        PFNGLMATRIXMULT3X3FNVPROC                               MatrixMult3x3fNV;
        PFNGLMATRIXMULTTRANSPOSE3X3FNVPROC                      MatrixMultTranspose3x3fNV;
        PFNGLMATRIXMULTTRANSPOSEDEXTPROC                        MatrixMultTransposedEXT;
        PFNGLMATRIXMULTTRANSPOSEFEXTPROC                        MatrixMultTransposefEXT;
        PFNGLMATRIXMULTDEXTPROC                                 MatrixMultdEXT;
        PFNGLMATRIXMULTFEXTPROC                                 MatrixMultfEXT;
        PFNGLMATRIXORTHOEXTPROC                                 MatrixOrthoEXT;
        PFNGLMATRIXPOPEXTPROC                                   MatrixPopEXT;
        PFNGLMATRIXPUSHEXTPROC                                  MatrixPushEXT;
        PFNGLMATRIXROTATEDEXTPROC                               MatrixRotatedEXT;
        PFNGLMATRIXROTATEFEXTPROC                               MatrixRotatefEXT;
        PFNGLMATRIXSCALEDEXTPROC                                MatrixScaledEXT;
        PFNGLMATRIXSCALEFEXTPROC                                MatrixScalefEXT;
        PFNGLMATRIXTRANSLATEDEXTPROC                            MatrixTranslatedEXT;
        PFNGLMATRIXTRANSLATEFEXTPROC                            MatrixTranslatefEXT;
        PFNGLMAXSHADERCOMPILERTHREADSARBPROC                    MaxShaderCompilerThreadsARB;
        PFNGLMAXSHADERCOMPILERTHREADSKHRPROC                    MaxShaderCompilerThreadsKHR;
        PFNGLMEMORYBARRIERPROC                                  MemoryBarrier;
        PFNGLMEMORYBARRIERBYREGIONPROC                          MemoryBarrierByRegion;
        PFNGLMINSAMPLESHADINGPROC                               MinSampleShading;
        PFNGLMINSAMPLESHADINGARBPROC                            MinSampleShadingARB;
        PFNGLMULTIDRAWARRAYSPROC                                MultiDrawArrays;
        PFNGLMULTIDRAWARRAYSINDIRECTPROC                        MultiDrawArraysIndirect;
        PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSCOUNTNVPROC         MultiDrawArraysIndirectBindlessCountNV;
        PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSNVPROC              MultiDrawArraysIndirectBindlessNV;
        PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC                   MultiDrawArraysIndirectCount;
        PFNGLMULTIDRAWARRAYSINDIRECTCOUNTARBPROC                MultiDrawArraysIndirectCountARB;
        PFNGLMULTIDRAWELEMENTSPROC                              MultiDrawElements;
        PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC                    MultiDrawElementsBaseVertex;
        PFNGLMULTIDRAWELEMENTSINDIRECTPROC                      MultiDrawElementsIndirect;
        PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSCOUNTNVPROC       MultiDrawElementsIndirectBindlessCountNV;
        PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSNVPROC            MultiDrawElementsIndirectBindlessNV;
        PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC                 MultiDrawElementsIndirectCount;
        PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTARBPROC              MultiDrawElementsIndirectCountARB;
        PFNGLMULTIDRAWMESHTASKSINDIRECTCOUNTNVPROC              MultiDrawMeshTasksIndirectCountNV;
        PFNGLMULTIDRAWMESHTASKSINDIRECTNVPROC                   MultiDrawMeshTasksIndirectNV;
        PFNGLMULTITEXBUFFEREXTPROC                              MultiTexBufferEXT;
        PFNGLMULTITEXCOORDPOINTEREXTPROC                        MultiTexCoordPointerEXT;
        PFNGLMULTITEXENVFEXTPROC                                MultiTexEnvfEXT;
        PFNGLMULTITEXENVFVEXTPROC                               MultiTexEnvfvEXT;
        PFNGLMULTITEXENVIEXTPROC                                MultiTexEnviEXT;
        PFNGLMULTITEXENVIVEXTPROC                               MultiTexEnvivEXT;
        PFNGLMULTITEXGENDEXTPROC                                MultiTexGendEXT;
        PFNGLMULTITEXGENDVEXTPROC                               MultiTexGendvEXT;
        PFNGLMULTITEXGENFEXTPROC                                MultiTexGenfEXT;
        PFNGLMULTITEXGENFVEXTPROC                               MultiTexGenfvEXT;
        PFNGLMULTITEXGENIEXTPROC                                MultiTexGeniEXT;
        PFNGLMULTITEXGENIVEXTPROC                               MultiTexGenivEXT;
        PFNGLMULTITEXIMAGE1DEXTPROC                             MultiTexImage1DEXT;
        PFNGLMULTITEXIMAGE2DEXTPROC                             MultiTexImage2DEXT;
        PFNGLMULTITEXIMAGE3DEXTPROC                             MultiTexImage3DEXT;
        PFNGLMULTITEXPARAMETERIIVEXTPROC                        MultiTexParameterIivEXT;
        PFNGLMULTITEXPARAMETERIUIVEXTPROC                       MultiTexParameterIuivEXT;
        PFNGLMULTITEXPARAMETERFEXTPROC                          MultiTexParameterfEXT;
        PFNGLMULTITEXPARAMETERFVEXTPROC                         MultiTexParameterfvEXT;
        PFNGLMULTITEXPARAMETERIEXTPROC                          MultiTexParameteriEXT;
        PFNGLMULTITEXPARAMETERIVEXTPROC                         MultiTexParameterivEXT;
        PFNGLMULTITEXRENDERBUFFEREXTPROC                        MultiTexRenderbufferEXT;
        PFNGLMULTITEXSUBIMAGE1DEXTPROC                          MultiTexSubImage1DEXT;
        PFNGLMULTITEXSUBIMAGE2DEXTPROC                          MultiTexSubImage2DEXT;
        PFNGLMULTITEXSUBIMAGE3DEXTPROC                          MultiTexSubImage3DEXT;
        PFNGLNAMEDBUFFERATTACHMEMORYNVPROC                      NamedBufferAttachMemoryNV;
        PFNGLNAMEDBUFFERDATAPROC                                NamedBufferData;
        PFNGLNAMEDBUFFERDATAEXTPROC                             NamedBufferDataEXT;
        PFNGLNAMEDBUFFERPAGECOMMITMENTARBPROC                   NamedBufferPageCommitmentARB;
        PFNGLNAMEDBUFFERPAGECOMMITMENTEXTPROC                   NamedBufferPageCommitmentEXT;
        PFNGLNAMEDBUFFERPAGECOMMITMENTMEMNVPROC                 NamedBufferPageCommitmentMemNV;
        PFNGLNAMEDBUFFERSTORAGEPROC                             NamedBufferStorage;
        PFNGLNAMEDBUFFERSTORAGEEXTPROC                          NamedBufferStorageEXT;
        PFNGLNAMEDBUFFERSUBDATAPROC                             NamedBufferSubData;
        PFNGLNAMEDBUFFERSUBDATAEXTPROC                          NamedBufferSubDataEXT;
        PFNGLNAMEDCOPYBUFFERSUBDATAEXTPROC                      NamedCopyBufferSubDataEXT;
        PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC                     NamedFramebufferDrawBuffer;
        PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC                    NamedFramebufferDrawBuffers;
        PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC                     NamedFramebufferParameteri;
        PFNGLNAMEDFRAMEBUFFERPARAMETERIEXTPROC                  NamedFramebufferParameteriEXT;
        PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC                     NamedFramebufferReadBuffer;
        PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC                   NamedFramebufferRenderbuffer;
        PFNGLNAMEDFRAMEBUFFERRENDERBUFFEREXTPROC                NamedFramebufferRenderbufferEXT;
        PFNGLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVARBPROC           NamedFramebufferSampleLocationsfvARB;
        PFNGLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVNVPROC            NamedFramebufferSampleLocationsfvNV;
        PFNGLNAMEDFRAMEBUFFERTEXTUREPROC                        NamedFramebufferTexture;
        PFNGLNAMEDFRAMEBUFFERTEXTURE1DEXTPROC                   NamedFramebufferTexture1DEXT;
        PFNGLNAMEDFRAMEBUFFERTEXTURE2DEXTPROC                   NamedFramebufferTexture2DEXT;
        PFNGLNAMEDFRAMEBUFFERTEXTURE3DEXTPROC                   NamedFramebufferTexture3DEXT;
        PFNGLNAMEDFRAMEBUFFERTEXTUREEXTPROC                     NamedFramebufferTextureEXT;
        PFNGLNAMEDFRAMEBUFFERTEXTUREFACEEXTPROC                 NamedFramebufferTextureFaceEXT;
        PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC                   NamedFramebufferTextureLayer;
        PFNGLNAMEDFRAMEBUFFERTEXTURELAYEREXTPROC                NamedFramebufferTextureLayerEXT;
        PFNGLNAMEDFRAMEBUFFERTEXTUREMULTIVIEWOVRPROC            NamedFramebufferTextureMultiviewOVR;
        PFNGLNAMEDPROGRAMLOCALPARAMETER4DEXTPROC                NamedProgramLocalParameter4dEXT;
        PFNGLNAMEDPROGRAMLOCALPARAMETER4DVEXTPROC               NamedProgramLocalParameter4dvEXT;
        PFNGLNAMEDPROGRAMLOCALPARAMETER4FEXTPROC                NamedProgramLocalParameter4fEXT;
        PFNGLNAMEDPROGRAMLOCALPARAMETER4FVEXTPROC               NamedProgramLocalParameter4fvEXT;
        PFNGLNAMEDPROGRAMLOCALPARAMETERI4IEXTPROC               NamedProgramLocalParameterI4iEXT;
        PFNGLNAMEDPROGRAMLOCALPARAMETERI4IVEXTPROC              NamedProgramLocalParameterI4ivEXT;
        PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIEXTPROC              NamedProgramLocalParameterI4uiEXT;
        PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIVEXTPROC             NamedProgramLocalParameterI4uivEXT;
        PFNGLNAMEDPROGRAMLOCALPARAMETERS4FVEXTPROC              NamedProgramLocalParameters4fvEXT;
        PFNGLNAMEDPROGRAMLOCALPARAMETERSI4IVEXTPROC             NamedProgramLocalParametersI4ivEXT;
        PFNGLNAMEDPROGRAMLOCALPARAMETERSI4UIVEXTPROC            NamedProgramLocalParametersI4uivEXT;
        PFNGLNAMEDPROGRAMSTRINGEXTPROC                          NamedProgramStringEXT;
        PFNGLNAMEDRENDERBUFFERSTORAGEPROC                       NamedRenderbufferStorage;
        PFNGLNAMEDRENDERBUFFERSTORAGEEXTPROC                    NamedRenderbufferStorageEXT;
        PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC            NamedRenderbufferStorageMultisample;
        PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEADVANCEDAMDPROC NamedRenderbufferStorageMultisampleAdvancedAMD;
        PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLECOVERAGEEXTPROC NamedRenderbufferStorageMultisampleCoverageEXT;
        PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC         NamedRenderbufferStorageMultisampleEXT;
        PFNGLNAMEDSTRINGARBPROC                                 NamedStringARB;
        PFNGLNORMALFORMATNVPROC                                 NormalFormatNV;
        PFNGLOBJECTLABELPROC                                    ObjectLabel;
        PFNGLOBJECTPTRLABELPROC                                 ObjectPtrLabel;
        PFNGLPATCHPARAMETERFVPROC                               PatchParameterfv;
        PFNGLPATCHPARAMETERIPROC                                PatchParameteri;
        PFNGLPATHCOMMANDSNVPROC                                 PathCommandsNV;
        PFNGLPATHCOORDSNVPROC                                   PathCoordsNV;
        PFNGLPATHCOVERDEPTHFUNCNVPROC                           PathCoverDepthFuncNV;
        PFNGLPATHDASHARRAYNVPROC                                PathDashArrayNV;
        PFNGLPATHGLYPHINDEXARRAYNVPROC                          PathGlyphIndexArrayNV;
        PFNGLPATHGLYPHINDEXRANGENVPROC                          PathGlyphIndexRangeNV;
        PFNGLPATHGLYPHRANGENVPROC                               PathGlyphRangeNV;
        PFNGLPATHGLYPHSNVPROC                                   PathGlyphsNV;
        PFNGLPATHMEMORYGLYPHINDEXARRAYNVPROC                    PathMemoryGlyphIndexArrayNV;
        PFNGLPATHPARAMETERFNVPROC                               PathParameterfNV;
        PFNGLPATHPARAMETERFVNVPROC                              PathParameterfvNV;
        PFNGLPATHPARAMETERINVPROC                               PathParameteriNV;
        PFNGLPATHPARAMETERIVNVPROC                              PathParameterivNV;
        PFNGLPATHSTENCILDEPTHOFFSETNVPROC                       PathStencilDepthOffsetNV;
        PFNGLPATHSTENCILFUNCNVPROC                              PathStencilFuncNV;
        PFNGLPATHSTRINGNVPROC                                   PathStringNV;
        PFNGLPATHSUBCOMMANDSNVPROC                              PathSubCommandsNV;
        PFNGLPATHSUBCOORDSNVPROC                                PathSubCoordsNV;
        PFNGLPAUSETRANSFORMFEEDBACKPROC                         PauseTransformFeedback;
        PFNGLPIXELSTOREFPROC                                    PixelStoref;
        PFNGLPIXELSTOREIPROC                                    PixelStorei;
        PFNGLPOINTALONGPATHNVPROC                               PointAlongPathNV;
        PFNGLPOINTPARAMETERFPROC                                PointParameterf;
        PFNGLPOINTPARAMETERFVPROC                               PointParameterfv;
        PFNGLPOINTPARAMETERIPROC                                PointParameteri;
        PFNGLPOINTPARAMETERIVPROC                               PointParameteriv;
        PFNGLPOINTSIZEPROC                                      PointSize;
        PFNGLPOLYGONMODEPROC                                    PolygonMode;
        PFNGLPOLYGONOFFSETPROC                                  PolygonOffset;
        PFNGLPOLYGONOFFSETCLAMPPROC                             PolygonOffsetClamp;
        PFNGLPOLYGONOFFSETCLAMPEXTPROC                          PolygonOffsetClampEXT;
        PFNGLPOPDEBUGGROUPPROC                                  PopDebugGroup;
        PFNGLPOPGROUPMARKEREXTPROC                              PopGroupMarkerEXT;
        PFNGLPRIMITIVEBOUNDINGBOXARBPROC                        PrimitiveBoundingBoxARB;
        PFNGLPRIMITIVERESTARTINDEXPROC                          PrimitiveRestartIndex;
        PFNGLPROGRAMBINARYPROC                                  ProgramBinary;
        PFNGLPROGRAMPARAMETERIPROC                              ProgramParameteri;
        PFNGLPROGRAMPARAMETERIARBPROC                           ProgramParameteriARB;
        PFNGLPROGRAMPATHFRAGMENTINPUTGENNVPROC                  ProgramPathFragmentInputGenNV;
        PFNGLPROGRAMUNIFORM1DPROC                               ProgramUniform1d;
        PFNGLPROGRAMUNIFORM1DEXTPROC                            ProgramUniform1dEXT;
        PFNGLPROGRAMUNIFORM1DVPROC                              ProgramUniform1dv;
        PFNGLPROGRAMUNIFORM1DVEXTPROC                           ProgramUniform1dvEXT;
        PFNGLPROGRAMUNIFORM1FPROC                               ProgramUniform1f;
        PFNGLPROGRAMUNIFORM1FEXTPROC                            ProgramUniform1fEXT;
        PFNGLPROGRAMUNIFORM1FVPROC                              ProgramUniform1fv;
        PFNGLPROGRAMUNIFORM1FVEXTPROC                           ProgramUniform1fvEXT;
        PFNGLPROGRAMUNIFORM1IPROC                               ProgramUniform1i;
        PFNGLPROGRAMUNIFORM1I64ARBPROC                          ProgramUniform1i64ARB;
        PFNGLPROGRAMUNIFORM1I64NVPROC                           ProgramUniform1i64NV;
        PFNGLPROGRAMUNIFORM1I64VARBPROC                         ProgramUniform1i64vARB;
        PFNGLPROGRAMUNIFORM1I64VNVPROC                          ProgramUniform1i64vNV;
        PFNGLPROGRAMUNIFORM1IEXTPROC                            ProgramUniform1iEXT;
        PFNGLPROGRAMUNIFORM1IVPROC                              ProgramUniform1iv;
        PFNGLPROGRAMUNIFORM1IVEXTPROC                           ProgramUniform1ivEXT;
        PFNGLPROGRAMUNIFORM1UIPROC                              ProgramUniform1ui;
        PFNGLPROGRAMUNIFORM1UI64ARBPROC                         ProgramUniform1ui64ARB;
        PFNGLPROGRAMUNIFORM1UI64NVPROC                          ProgramUniform1ui64NV;
        PFNGLPROGRAMUNIFORM1UI64VARBPROC                        ProgramUniform1ui64vARB;
        PFNGLPROGRAMUNIFORM1UI64VNVPROC                         ProgramUniform1ui64vNV;
        PFNGLPROGRAMUNIFORM1UIEXTPROC                           ProgramUniform1uiEXT;
        PFNGLPROGRAMUNIFORM1UIVPROC                             ProgramUniform1uiv;
        PFNGLPROGRAMUNIFORM1UIVEXTPROC                          ProgramUniform1uivEXT;
        PFNGLPROGRAMUNIFORM2DPROC                               ProgramUniform2d;
        PFNGLPROGRAMUNIFORM2DEXTPROC                            ProgramUniform2dEXT;
        PFNGLPROGRAMUNIFORM2DVPROC                              ProgramUniform2dv;
        PFNGLPROGRAMUNIFORM2DVEXTPROC                           ProgramUniform2dvEXT;
        PFNGLPROGRAMUNIFORM2FPROC                               ProgramUniform2f;
        PFNGLPROGRAMUNIFORM2FEXTPROC                            ProgramUniform2fEXT;
        PFNGLPROGRAMUNIFORM2FVPROC                              ProgramUniform2fv;
        PFNGLPROGRAMUNIFORM2FVEXTPROC                           ProgramUniform2fvEXT;
        PFNGLPROGRAMUNIFORM2IPROC                               ProgramUniform2i;
        PFNGLPROGRAMUNIFORM2I64ARBPROC                          ProgramUniform2i64ARB;
        PFNGLPROGRAMUNIFORM2I64NVPROC                           ProgramUniform2i64NV;
        PFNGLPROGRAMUNIFORM2I64VARBPROC                         ProgramUniform2i64vARB;
        PFNGLPROGRAMUNIFORM2I64VNVPROC                          ProgramUniform2i64vNV;
        PFNGLPROGRAMUNIFORM2IEXTPROC                            ProgramUniform2iEXT;
        PFNGLPROGRAMUNIFORM2IVPROC                              ProgramUniform2iv;
        PFNGLPROGRAMUNIFORM2IVEXTPROC                           ProgramUniform2ivEXT;
        PFNGLPROGRAMUNIFORM2UIPROC                              ProgramUniform2ui;
        PFNGLPROGRAMUNIFORM2UI64ARBPROC                         ProgramUniform2ui64ARB;
        PFNGLPROGRAMUNIFORM2UI64NVPROC                          ProgramUniform2ui64NV;
        PFNGLPROGRAMUNIFORM2UI64VARBPROC                        ProgramUniform2ui64vARB;
        PFNGLPROGRAMUNIFORM2UI64VNVPROC                         ProgramUniform2ui64vNV;
        PFNGLPROGRAMUNIFORM2UIEXTPROC                           ProgramUniform2uiEXT;
        PFNGLPROGRAMUNIFORM2UIVPROC                             ProgramUniform2uiv;
        PFNGLPROGRAMUNIFORM2UIVEXTPROC                          ProgramUniform2uivEXT;
        PFNGLPROGRAMUNIFORM3DPROC                               ProgramUniform3d;
        PFNGLPROGRAMUNIFORM3DEXTPROC                            ProgramUniform3dEXT;
        PFNGLPROGRAMUNIFORM3DVPROC                              ProgramUniform3dv;
        PFNGLPROGRAMUNIFORM3DVEXTPROC                           ProgramUniform3dvEXT;
        PFNGLPROGRAMUNIFORM3FPROC                               ProgramUniform3f;
        PFNGLPROGRAMUNIFORM3FEXTPROC                            ProgramUniform3fEXT;
        PFNGLPROGRAMUNIFORM3FVPROC                              ProgramUniform3fv;
        PFNGLPROGRAMUNIFORM3FVEXTPROC                           ProgramUniform3fvEXT;
        PFNGLPROGRAMUNIFORM3IPROC                               ProgramUniform3i;
        PFNGLPROGRAMUNIFORM3I64ARBPROC                          ProgramUniform3i64ARB;
        PFNGLPROGRAMUNIFORM3I64NVPROC                           ProgramUniform3i64NV;
        PFNGLPROGRAMUNIFORM3I64VARBPROC                         ProgramUniform3i64vARB;
        PFNGLPROGRAMUNIFORM3I64VNVPROC                          ProgramUniform3i64vNV;
        PFNGLPROGRAMUNIFORM3IEXTPROC                            ProgramUniform3iEXT;
        PFNGLPROGRAMUNIFORM3IVPROC                              ProgramUniform3iv;
        PFNGLPROGRAMUNIFORM3IVEXTPROC                           ProgramUniform3ivEXT;
        PFNGLPROGRAMUNIFORM3UIPROC                              ProgramUniform3ui;
        PFNGLPROGRAMUNIFORM3UI64ARBPROC                         ProgramUniform3ui64ARB;
        PFNGLPROGRAMUNIFORM3UI64NVPROC                          ProgramUniform3ui64NV;
        PFNGLPROGRAMUNIFORM3UI64VARBPROC                        ProgramUniform3ui64vARB;
        PFNGLPROGRAMUNIFORM3UI64VNVPROC                         ProgramUniform3ui64vNV;
        PFNGLPROGRAMUNIFORM3UIEXTPROC                           ProgramUniform3uiEXT;
        PFNGLPROGRAMUNIFORM3UIVPROC                             ProgramUniform3uiv;
        PFNGLPROGRAMUNIFORM3UIVEXTPROC                          ProgramUniform3uivEXT;
        PFNGLPROGRAMUNIFORM4DPROC                               ProgramUniform4d;
        PFNGLPROGRAMUNIFORM4DEXTPROC                            ProgramUniform4dEXT;
        PFNGLPROGRAMUNIFORM4DVPROC                              ProgramUniform4dv;
        PFNGLPROGRAMUNIFORM4DVEXTPROC                           ProgramUniform4dvEXT;
        PFNGLPROGRAMUNIFORM4FPROC                               ProgramUniform4f;
        PFNGLPROGRAMUNIFORM4FEXTPROC                            ProgramUniform4fEXT;
        PFNGLPROGRAMUNIFORM4FVPROC                              ProgramUniform4fv;
        PFNGLPROGRAMUNIFORM4FVEXTPROC                           ProgramUniform4fvEXT;
        PFNGLPROGRAMUNIFORM4IPROC                               ProgramUniform4i;
        PFNGLPROGRAMUNIFORM4I64ARBPROC                          ProgramUniform4i64ARB;
        PFNGLPROGRAMUNIFORM4I64NVPROC                           ProgramUniform4i64NV;
        PFNGLPROGRAMUNIFORM4I64VARBPROC                         ProgramUniform4i64vARB;
        PFNGLPROGRAMUNIFORM4I64VNVPROC                          ProgramUniform4i64vNV;
        PFNGLPROGRAMUNIFORM4IEXTPROC                            ProgramUniform4iEXT;
        PFNGLPROGRAMUNIFORM4IVPROC                              ProgramUniform4iv;
        PFNGLPROGRAMUNIFORM4IVEXTPROC                           ProgramUniform4ivEXT;
        PFNGLPROGRAMUNIFORM4UIPROC                              ProgramUniform4ui;
        PFNGLPROGRAMUNIFORM4UI64ARBPROC                         ProgramUniform4ui64ARB;
        PFNGLPROGRAMUNIFORM4UI64NVPROC                          ProgramUniform4ui64NV;
        PFNGLPROGRAMUNIFORM4UI64VARBPROC                        ProgramUniform4ui64vARB;
        PFNGLPROGRAMUNIFORM4UI64VNVPROC                         ProgramUniform4ui64vNV;
        PFNGLPROGRAMUNIFORM4UIEXTPROC                           ProgramUniform4uiEXT;
        PFNGLPROGRAMUNIFORM4UIVPROC                             ProgramUniform4uiv;
        PFNGLPROGRAMUNIFORM4UIVEXTPROC                          ProgramUniform4uivEXT;
        PFNGLPROGRAMUNIFORMHANDLEUI64ARBPROC                    ProgramUniformHandleui64ARB;
        PFNGLPROGRAMUNIFORMHANDLEUI64NVPROC                     ProgramUniformHandleui64NV;
        PFNGLPROGRAMUNIFORMHANDLEUI64VARBPROC                   ProgramUniformHandleui64vARB;
        PFNGLPROGRAMUNIFORMHANDLEUI64VNVPROC                    ProgramUniformHandleui64vNV;
        PFNGLPROGRAMUNIFORMMATRIX2DVPROC                        ProgramUniformMatrix2dv;
        PFNGLPROGRAMUNIFORMMATRIX2DVEXTPROC                     ProgramUniformMatrix2dvEXT;
        PFNGLPROGRAMUNIFORMMATRIX2FVPROC                        ProgramUniformMatrix2fv;
        PFNGLPROGRAMUNIFORMMATRIX2FVEXTPROC                     ProgramUniformMatrix2fvEXT;
        PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC                      ProgramUniformMatrix2x3dv;
        PFNGLPROGRAMUNIFORMMATRIX2X3DVEXTPROC                   ProgramUniformMatrix2x3dvEXT;
        PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC                      ProgramUniformMatrix2x3fv;
        PFNGLPROGRAMUNIFORMMATRIX2X3FVEXTPROC                   ProgramUniformMatrix2x3fvEXT;
        PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC                      ProgramUniformMatrix2x4dv;
        PFNGLPROGRAMUNIFORMMATRIX2X4DVEXTPROC                   ProgramUniformMatrix2x4dvEXT;
        PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC                      ProgramUniformMatrix2x4fv;
        PFNGLPROGRAMUNIFORMMATRIX2X4FVEXTPROC                   ProgramUniformMatrix2x4fvEXT;
        PFNGLPROGRAMUNIFORMMATRIX3DVPROC                        ProgramUniformMatrix3dv;
        PFNGLPROGRAMUNIFORMMATRIX3DVEXTPROC                     ProgramUniformMatrix3dvEXT;
        PFNGLPROGRAMUNIFORMMATRIX3FVPROC                        ProgramUniformMatrix3fv;
        PFNGLPROGRAMUNIFORMMATRIX3FVEXTPROC                     ProgramUniformMatrix3fvEXT;
        PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC                      ProgramUniformMatrix3x2dv;
        PFNGLPROGRAMUNIFORMMATRIX3X2DVEXTPROC                   ProgramUniformMatrix3x2dvEXT;
        PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC                      ProgramUniformMatrix3x2fv;
        PFNGLPROGRAMUNIFORMMATRIX3X2FVEXTPROC                   ProgramUniformMatrix3x2fvEXT;
        PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC                      ProgramUniformMatrix3x4dv;
        PFNGLPROGRAMUNIFORMMATRIX3X4DVEXTPROC                   ProgramUniformMatrix3x4dvEXT;
        PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC                      ProgramUniformMatrix3x4fv;
        PFNGLPROGRAMUNIFORMMATRIX3X4FVEXTPROC                   ProgramUniformMatrix3x4fvEXT;
        PFNGLPROGRAMUNIFORMMATRIX4DVPROC                        ProgramUniformMatrix4dv;
        PFNGLPROGRAMUNIFORMMATRIX4DVEXTPROC                     ProgramUniformMatrix4dvEXT;
        PFNGLPROGRAMUNIFORMMATRIX4FVPROC                        ProgramUniformMatrix4fv;
        PFNGLPROGRAMUNIFORMMATRIX4FVEXTPROC                     ProgramUniformMatrix4fvEXT;
        PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC                      ProgramUniformMatrix4x2dv;
        PFNGLPROGRAMUNIFORMMATRIX4X2DVEXTPROC                   ProgramUniformMatrix4x2dvEXT;
        PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC                      ProgramUniformMatrix4x2fv;
        PFNGLPROGRAMUNIFORMMATRIX4X2FVEXTPROC                   ProgramUniformMatrix4x2fvEXT;
        PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC                      ProgramUniformMatrix4x3dv;
        PFNGLPROGRAMUNIFORMMATRIX4X3DVEXTPROC                   ProgramUniformMatrix4x3dvEXT;
        PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC                      ProgramUniformMatrix4x3fv;
        PFNGLPROGRAMUNIFORMMATRIX4X3FVEXTPROC                   ProgramUniformMatrix4x3fvEXT;
        PFNGLPROGRAMUNIFORMUI64NVPROC                           ProgramUniformui64NV;
        PFNGLPROGRAMUNIFORMUI64VNVPROC                          ProgramUniformui64vNV;
        PFNGLPROVOKINGVERTEXPROC                                ProvokingVertex;
        PFNGLPUSHCLIENTATTRIBDEFAULTEXTPROC                     PushClientAttribDefaultEXT;
        PFNGLPUSHDEBUGGROUPPROC                                 PushDebugGroup;
        PFNGLPUSHGROUPMARKEREXTPROC                             PushGroupMarkerEXT;
        PFNGLQUERYCOUNTERPROC                                   QueryCounter;
        PFNGLRASTERSAMPLESEXTPROC                               RasterSamplesEXT;
        PFNGLREADBUFFERPROC                                     ReadBuffer;
        PFNGLREADPIXELSPROC                                     ReadPixels;
        PFNGLREADNPIXELSPROC                                    ReadnPixels;
        PFNGLREADNPIXELSARBPROC                                 ReadnPixelsARB;
        PFNGLRELEASESHADERCOMPILERPROC                          ReleaseShaderCompiler;
        PFNGLRENDERBUFFERSTORAGEPROC                            RenderbufferStorage;
        PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC                 RenderbufferStorageMultisample;
        PFNGLRENDERBUFFERSTORAGEMULTISAMPLEADVANCEDAMDPROC      RenderbufferStorageMultisampleAdvancedAMD;
        PFNGLRENDERBUFFERSTORAGEMULTISAMPLECOVERAGENVPROC       RenderbufferStorageMultisampleCoverageNV;
        PFNGLRESETMEMORYOBJECTPARAMETERNVPROC                   ResetMemoryObjectParameterNV;
        PFNGLRESOLVEDEPTHVALUESNVPROC                           ResolveDepthValuesNV;
        PFNGLRESUMETRANSFORMFEEDBACKPROC                        ResumeTransformFeedback;
        PFNGLSAMPLECOVERAGEPROC                                 SampleCoverage;
        PFNGLSAMPLEMASKIPROC                                    SampleMaski;
        PFNGLSAMPLERPARAMETERIIVPROC                            SamplerParameterIiv;
        PFNGLSAMPLERPARAMETERIUIVPROC                           SamplerParameterIuiv;
        PFNGLSAMPLERPARAMETERFPROC                              SamplerParameterf;
        PFNGLSAMPLERPARAMETERFVPROC                             SamplerParameterfv;
        PFNGLSAMPLERPARAMETERIPROC                              SamplerParameteri;
        PFNGLSAMPLERPARAMETERIVPROC                             SamplerParameteriv;
        PFNGLSCISSORPROC                                        Scissor;
        PFNGLSCISSORARRAYVPROC                                  ScissorArrayv;
        PFNGLSCISSOREXCLUSIVEARRAYVNVPROC                       ScissorExclusiveArrayvNV;
        PFNGLSCISSOREXCLUSIVENVPROC                             ScissorExclusiveNV;
        PFNGLSCISSORINDEXEDPROC                                 ScissorIndexed;
        PFNGLSCISSORINDEXEDVPROC                                ScissorIndexedv;
        PFNGLSECONDARYCOLORFORMATNVPROC                         SecondaryColorFormatNV;
        PFNGLSELECTPERFMONITORCOUNTERSAMDPROC                   SelectPerfMonitorCountersAMD;
        PFNGLSHADERBINARYPROC                                   ShaderBinary;
        PFNGLSHADERSOURCEPROC                                   ShaderSource;
        PFNGLSHADERSTORAGEBLOCKBINDINGPROC                      ShaderStorageBlockBinding;
        PFNGLSHADINGRATEIMAGEBARRIERNVPROC                      ShadingRateImageBarrierNV;
        PFNGLSHADINGRATEIMAGEPALETTENVPROC                      ShadingRateImagePaletteNV;
        PFNGLSHADINGRATESAMPLEORDERCUSTOMNVPROC                 ShadingRateSampleOrderCustomNV;
        PFNGLSHADINGRATESAMPLEORDERNVPROC                       ShadingRateSampleOrderNV;
        PFNGLSIGNALVKFENCENVPROC                                SignalVkFenceNV;
        PFNGLSIGNALVKSEMAPHORENVPROC                            SignalVkSemaphoreNV;
        PFNGLSPECIALIZESHADERPROC                               SpecializeShader;
        PFNGLSPECIALIZESHADERARBPROC                            SpecializeShaderARB;
        PFNGLSTATECAPTURENVPROC                                 StateCaptureNV;
        PFNGLSTENCILFILLPATHINSTANCEDNVPROC                     StencilFillPathInstancedNV;
        PFNGLSTENCILFILLPATHNVPROC                              StencilFillPathNV;
        PFNGLSTENCILFUNCPROC                                    StencilFunc;
        PFNGLSTENCILFUNCSEPARATEPROC                            StencilFuncSeparate;
        PFNGLSTENCILMASKPROC                                    StencilMask;
        PFNGLSTENCILMASKSEPARATEPROC                            StencilMaskSeparate;
        PFNGLSTENCILOPPROC                                      StencilOp;
        PFNGLSTENCILOPSEPARATEPROC                              StencilOpSeparate;
        PFNGLSTENCILSTROKEPATHINSTANCEDNVPROC                   StencilStrokePathInstancedNV;
        PFNGLSTENCILSTROKEPATHNVPROC                            StencilStrokePathNV;
        PFNGLSTENCILTHENCOVERFILLPATHINSTANCEDNVPROC            StencilThenCoverFillPathInstancedNV;
        PFNGLSTENCILTHENCOVERFILLPATHNVPROC                     StencilThenCoverFillPathNV;
        PFNGLSTENCILTHENCOVERSTROKEPATHINSTANCEDNVPROC          StencilThenCoverStrokePathInstancedNV;
        PFNGLSTENCILTHENCOVERSTROKEPATHNVPROC                   StencilThenCoverStrokePathNV;
        PFNGLSUBPIXELPRECISIONBIASNVPROC                        SubpixelPrecisionBiasNV;
        PFNGLTEXATTACHMEMORYNVPROC                              TexAttachMemoryNV;
        PFNGLTEXBUFFERPROC                                      TexBuffer;
        PFNGLTEXBUFFERARBPROC                                   TexBufferARB;
        PFNGLTEXBUFFERRANGEPROC                                 TexBufferRange;
        PFNGLTEXCOORDFORMATNVPROC                               TexCoordFormatNV;
        PFNGLTEXIMAGE1DPROC                                     TexImage1D;
        PFNGLTEXIMAGE2DPROC                                     TexImage2D;
        PFNGLTEXIMAGE2DMULTISAMPLEPROC                          TexImage2DMultisample;
        PFNGLTEXIMAGE3DPROC                                     TexImage3D;
        PFNGLTEXIMAGE3DMULTISAMPLEPROC                          TexImage3DMultisample;
        PFNGLTEXPAGECOMMITMENTARBPROC                           TexPageCommitmentARB;
        PFNGLTEXPAGECOMMITMENTMEMNVPROC                         TexPageCommitmentMemNV;
        PFNGLTEXPARAMETERIIVPROC                                TexParameterIiv;
        PFNGLTEXPARAMETERIUIVPROC                               TexParameterIuiv;
        PFNGLTEXPARAMETERFPROC                                  TexParameterf;
        PFNGLTEXPARAMETERFVPROC                                 TexParameterfv;
        PFNGLTEXPARAMETERIPROC                                  TexParameteri;
        PFNGLTEXPARAMETERIVPROC                                 TexParameteriv;
        PFNGLTEXSTORAGE1DPROC                                   TexStorage1D;
        PFNGLTEXSTORAGE1DEXTPROC                                TexStorage1DEXT;
        PFNGLTEXSTORAGE2DPROC                                   TexStorage2D;
        PFNGLTEXSTORAGE2DEXTPROC                                TexStorage2DEXT;
        PFNGLTEXSTORAGE2DMULTISAMPLEPROC                        TexStorage2DMultisample;
        PFNGLTEXSTORAGE3DPROC                                   TexStorage3D;
        PFNGLTEXSTORAGE3DEXTPROC                                TexStorage3DEXT;
        PFNGLTEXSTORAGE3DMULTISAMPLEPROC                        TexStorage3DMultisample;
        PFNGLTEXSUBIMAGE1DPROC                                  TexSubImage1D;
        PFNGLTEXSUBIMAGE2DPROC                                  TexSubImage2D;
        PFNGLTEXSUBIMAGE3DPROC                                  TexSubImage3D;
        PFNGLTEXTUREATTACHMEMORYNVPROC                          TextureAttachMemoryNV;
        PFNGLTEXTUREBARRIERPROC                                 TextureBarrier;
        PFNGLTEXTUREBARRIERNVPROC                               TextureBarrierNV;
        PFNGLTEXTUREBUFFERPROC                                  TextureBuffer;
        PFNGLTEXTUREBUFFEREXTPROC                               TextureBufferEXT;
        PFNGLTEXTUREBUFFERRANGEPROC                             TextureBufferRange;
        PFNGLTEXTUREBUFFERRANGEEXTPROC                          TextureBufferRangeEXT;
        PFNGLTEXTUREIMAGE1DEXTPROC                              TextureImage1DEXT;
        PFNGLTEXTUREIMAGE2DEXTPROC                              TextureImage2DEXT;
        PFNGLTEXTUREIMAGE3DEXTPROC                              TextureImage3DEXT;
        PFNGLTEXTUREPAGECOMMITMENTEXTPROC                       TexturePageCommitmentEXT;
        PFNGLTEXTUREPAGECOMMITMENTMEMNVPROC                     TexturePageCommitmentMemNV;
        PFNGLTEXTUREPARAMETERIIVPROC                            TextureParameterIiv;
        PFNGLTEXTUREPARAMETERIIVEXTPROC                         TextureParameterIivEXT;
        PFNGLTEXTUREPARAMETERIUIVPROC                           TextureParameterIuiv;
        PFNGLTEXTUREPARAMETERIUIVEXTPROC                        TextureParameterIuivEXT;
        PFNGLTEXTUREPARAMETERFPROC                              TextureParameterf;
        PFNGLTEXTUREPARAMETERFEXTPROC                           TextureParameterfEXT;
        PFNGLTEXTUREPARAMETERFVPROC                             TextureParameterfv;
        PFNGLTEXTUREPARAMETERFVEXTPROC                          TextureParameterfvEXT;
        PFNGLTEXTUREPARAMETERIPROC                              TextureParameteri;
        PFNGLTEXTUREPARAMETERIEXTPROC                           TextureParameteriEXT;
        PFNGLTEXTUREPARAMETERIVPROC                             TextureParameteriv;
        PFNGLTEXTUREPARAMETERIVEXTPROC                          TextureParameterivEXT;
        PFNGLTEXTURERENDERBUFFEREXTPROC                         TextureRenderbufferEXT;
        PFNGLTEXTURESTORAGE1DPROC                               TextureStorage1D;
        PFNGLTEXTURESTORAGE1DEXTPROC                            TextureStorage1DEXT;
        PFNGLTEXTURESTORAGE2DPROC                               TextureStorage2D;
        PFNGLTEXTURESTORAGE2DEXTPROC                            TextureStorage2DEXT;
        PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC                    TextureStorage2DMultisample;
        PFNGLTEXTURESTORAGE2DMULTISAMPLEEXTPROC                 TextureStorage2DMultisampleEXT;
        PFNGLTEXTURESTORAGE3DPROC                               TextureStorage3D;
        PFNGLTEXTURESTORAGE3DEXTPROC                            TextureStorage3DEXT;
        PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC                    TextureStorage3DMultisample;
        PFNGLTEXTURESTORAGE3DMULTISAMPLEEXTPROC                 TextureStorage3DMultisampleEXT;
        PFNGLTEXTURESUBIMAGE1DPROC                              TextureSubImage1D;
        PFNGLTEXTURESUBIMAGE1DEXTPROC                           TextureSubImage1DEXT;
        PFNGLTEXTURESUBIMAGE2DPROC                              TextureSubImage2D;
        PFNGLTEXTURESUBIMAGE2DEXTPROC                           TextureSubImage2DEXT;
        PFNGLTEXTURESUBIMAGE3DPROC                              TextureSubImage3D;
        PFNGLTEXTURESUBIMAGE3DEXTPROC                           TextureSubImage3DEXT;
        PFNGLTEXTUREVIEWPROC                                    TextureView;
        PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC                    TransformFeedbackBufferBase;
        PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC                   TransformFeedbackBufferRange;
        PFNGLTRANSFORMFEEDBACKVARYINGSPROC                      TransformFeedbackVaryings;
        PFNGLTRANSFORMPATHNVPROC                                TransformPathNV;
        PFNGLUNIFORM1DPROC                                      Uniform1d;
        PFNGLUNIFORM1DVPROC                                     Uniform1dv;
        PFNGLUNIFORM1FPROC                                      Uniform1f;
        PFNGLUNIFORM1FVPROC                                     Uniform1fv;
        PFNGLUNIFORM1IPROC                                      Uniform1i;
        PFNGLUNIFORM1I64ARBPROC                                 Uniform1i64ARB;
        PFNGLUNIFORM1I64NVPROC                                  Uniform1i64NV;
        PFNGLUNIFORM1I64VARBPROC                                Uniform1i64vARB;
        PFNGLUNIFORM1I64VNVPROC                                 Uniform1i64vNV;
        PFNGLUNIFORM1IVPROC                                     Uniform1iv;
        PFNGLUNIFORM1UIPROC                                     Uniform1ui;
        PFNGLUNIFORM1UI64ARBPROC                                Uniform1ui64ARB;
        PFNGLUNIFORM1UI64NVPROC                                 Uniform1ui64NV;
        PFNGLUNIFORM1UI64VARBPROC                               Uniform1ui64vARB;
        PFNGLUNIFORM1UI64VNVPROC                                Uniform1ui64vNV;
        PFNGLUNIFORM1UIVPROC                                    Uniform1uiv;
        PFNGLUNIFORM2DPROC                                      Uniform2d;
        PFNGLUNIFORM2DVPROC                                     Uniform2dv;
        PFNGLUNIFORM2FPROC                                      Uniform2f;
        PFNGLUNIFORM2FVPROC                                     Uniform2fv;
        PFNGLUNIFORM2IPROC                                      Uniform2i;
        PFNGLUNIFORM2I64ARBPROC                                 Uniform2i64ARB;
        PFNGLUNIFORM2I64NVPROC                                  Uniform2i64NV;
        PFNGLUNIFORM2I64VARBPROC                                Uniform2i64vARB;
        PFNGLUNIFORM2I64VNVPROC                                 Uniform2i64vNV;
        PFNGLUNIFORM2IVPROC                                     Uniform2iv;
        PFNGLUNIFORM2UIPROC                                     Uniform2ui;
        PFNGLUNIFORM2UI64ARBPROC                                Uniform2ui64ARB;
        PFNGLUNIFORM2UI64NVPROC                                 Uniform2ui64NV;
        PFNGLUNIFORM2UI64VARBPROC                               Uniform2ui64vARB;
        PFNGLUNIFORM2UI64VNVPROC                                Uniform2ui64vNV;
        PFNGLUNIFORM2UIVPROC                                    Uniform2uiv;
        PFNGLUNIFORM3DPROC                                      Uniform3d;
        PFNGLUNIFORM3DVPROC                                     Uniform3dv;
        PFNGLUNIFORM3FPROC                                      Uniform3f;
        PFNGLUNIFORM3FVPROC                                     Uniform3fv;
        PFNGLUNIFORM3IPROC                                      Uniform3i;
        PFNGLUNIFORM3I64ARBPROC                                 Uniform3i64ARB;
        PFNGLUNIFORM3I64NVPROC                                  Uniform3i64NV;
        PFNGLUNIFORM3I64VARBPROC                                Uniform3i64vARB;
        PFNGLUNIFORM3I64VNVPROC                                 Uniform3i64vNV;
        PFNGLUNIFORM3IVPROC                                     Uniform3iv;
        PFNGLUNIFORM3UIPROC                                     Uniform3ui;
        PFNGLUNIFORM3UI64ARBPROC                                Uniform3ui64ARB;
        PFNGLUNIFORM3UI64NVPROC                                 Uniform3ui64NV;
        PFNGLUNIFORM3UI64VARBPROC                               Uniform3ui64vARB;
        PFNGLUNIFORM3UI64VNVPROC                                Uniform3ui64vNV;
        PFNGLUNIFORM3UIVPROC                                    Uniform3uiv;
        PFNGLUNIFORM4DPROC                                      Uniform4d;
        PFNGLUNIFORM4DVPROC                                     Uniform4dv;
        PFNGLUNIFORM4FPROC                                      Uniform4f;
        PFNGLUNIFORM4FVPROC                                     Uniform4fv;
        PFNGLUNIFORM4IPROC                                      Uniform4i;
        PFNGLUNIFORM4I64ARBPROC                                 Uniform4i64ARB;
        PFNGLUNIFORM4I64NVPROC                                  Uniform4i64NV;
        PFNGLUNIFORM4I64VARBPROC                                Uniform4i64vARB;
        PFNGLUNIFORM4I64VNVPROC                                 Uniform4i64vNV;
        PFNGLUNIFORM4IVPROC                                     Uniform4iv;
        PFNGLUNIFORM4UIPROC                                     Uniform4ui;
        PFNGLUNIFORM4UI64ARBPROC                                Uniform4ui64ARB;
        PFNGLUNIFORM4UI64NVPROC                                 Uniform4ui64NV;
        PFNGLUNIFORM4UI64VARBPROC                               Uniform4ui64vARB;
        PFNGLUNIFORM4UI64VNVPROC                                Uniform4ui64vNV;
        PFNGLUNIFORM4UIVPROC                                    Uniform4uiv;
        PFNGLUNIFORMBLOCKBINDINGPROC                            UniformBlockBinding;
        PFNGLUNIFORMHANDLEUI64ARBPROC                           UniformHandleui64ARB;
        PFNGLUNIFORMHANDLEUI64NVPROC                            UniformHandleui64NV;
        PFNGLUNIFORMHANDLEUI64VARBPROC                          UniformHandleui64vARB;
        PFNGLUNIFORMHANDLEUI64VNVPROC                           UniformHandleui64vNV;
        PFNGLUNIFORMMATRIX2DVPROC                               UniformMatrix2dv;
        PFNGLUNIFORMMATRIX2FVPROC                               UniformMatrix2fv;
        PFNGLUNIFORMMATRIX2X3DVPROC                             UniformMatrix2x3dv;
        PFNGLUNIFORMMATRIX2X3FVPROC                             UniformMatrix2x3fv;
        PFNGLUNIFORMMATRIX2X4DVPROC                             UniformMatrix2x4dv;
        PFNGLUNIFORMMATRIX2X4FVPROC                             UniformMatrix2x4fv;
        PFNGLUNIFORMMATRIX3DVPROC                               UniformMatrix3dv;
        PFNGLUNIFORMMATRIX3FVPROC                               UniformMatrix3fv;
        PFNGLUNIFORMMATRIX3X2DVPROC                             UniformMatrix3x2dv;
        PFNGLUNIFORMMATRIX3X2FVPROC                             UniformMatrix3x2fv;
        PFNGLUNIFORMMATRIX3X4DVPROC                             UniformMatrix3x4dv;
        PFNGLUNIFORMMATRIX3X4FVPROC                             UniformMatrix3x4fv;
        PFNGLUNIFORMMATRIX4DVPROC                               UniformMatrix4dv;
        PFNGLUNIFORMMATRIX4FVPROC                               UniformMatrix4fv;
        PFNGLUNIFORMMATRIX4X2DVPROC                             UniformMatrix4x2dv;
        PFNGLUNIFORMMATRIX4X2FVPROC                             UniformMatrix4x2fv;
        PFNGLUNIFORMMATRIX4X3DVPROC                             UniformMatrix4x3dv;
        PFNGLUNIFORMMATRIX4X3FVPROC                             UniformMatrix4x3fv;
        PFNGLUNIFORMSUBROUTINESUIVPROC                          UniformSubroutinesuiv;
        PFNGLUNIFORMUI64NVPROC                                  Uniformui64NV;
        PFNGLUNIFORMUI64VNVPROC                                 Uniformui64vNV;
        PFNGLUNMAPBUFFERPROC                                    UnmapBuffer;
        PFNGLUNMAPNAMEDBUFFERPROC                               UnmapNamedBuffer;
        PFNGLUNMAPNAMEDBUFFEREXTPROC                            UnmapNamedBufferEXT;
        PFNGLUSEPROGRAMPROC                                     UseProgram;
        PFNGLUSEPROGRAMSTAGESPROC                               UseProgramStages;
        PFNGLUSESHADERPROGRAMEXTPROC                            UseShaderProgramEXT;
        PFNGLVALIDATEPROGRAMPROC                                ValidateProgram;
        PFNGLVALIDATEPROGRAMPIPELINEPROC                        ValidateProgramPipeline;
        PFNGLVERTEXARRAYATTRIBBINDINGPROC                       VertexArrayAttribBinding;
        PFNGLVERTEXARRAYATTRIBFORMATPROC                        VertexArrayAttribFormat;
        PFNGLVERTEXARRAYATTRIBIFORMATPROC                       VertexArrayAttribIFormat;
        PFNGLVERTEXARRAYATTRIBLFORMATPROC                       VertexArrayAttribLFormat;
        PFNGLVERTEXARRAYBINDVERTEXBUFFEREXTPROC                 VertexArrayBindVertexBufferEXT;
        PFNGLVERTEXARRAYBINDINGDIVISORPROC                      VertexArrayBindingDivisor;
        PFNGLVERTEXARRAYCOLOROFFSETEXTPROC                      VertexArrayColorOffsetEXT;
        PFNGLVERTEXARRAYEDGEFLAGOFFSETEXTPROC                   VertexArrayEdgeFlagOffsetEXT;
        PFNGLVERTEXARRAYELEMENTBUFFERPROC                       VertexArrayElementBuffer;
        PFNGLVERTEXARRAYFOGCOORDOFFSETEXTPROC                   VertexArrayFogCoordOffsetEXT;
        PFNGLVERTEXARRAYINDEXOFFSETEXTPROC                      VertexArrayIndexOffsetEXT;
        PFNGLVERTEXARRAYMULTITEXCOORDOFFSETEXTPROC              VertexArrayMultiTexCoordOffsetEXT;
        PFNGLVERTEXARRAYNORMALOFFSETEXTPROC                     VertexArrayNormalOffsetEXT;
        PFNGLVERTEXARRAYSECONDARYCOLOROFFSETEXTPROC             VertexArraySecondaryColorOffsetEXT;
        PFNGLVERTEXARRAYTEXCOORDOFFSETEXTPROC                   VertexArrayTexCoordOffsetEXT;
        PFNGLVERTEXARRAYVERTEXATTRIBBINDINGEXTPROC              VertexArrayVertexAttribBindingEXT;
        PFNGLVERTEXARRAYVERTEXATTRIBDIVISOREXTPROC              VertexArrayVertexAttribDivisorEXT;
        PFNGLVERTEXARRAYVERTEXATTRIBFORMATEXTPROC               VertexArrayVertexAttribFormatEXT;
        PFNGLVERTEXARRAYVERTEXATTRIBIFORMATEXTPROC              VertexArrayVertexAttribIFormatEXT;
        PFNGLVERTEXARRAYVERTEXATTRIBIOFFSETEXTPROC              VertexArrayVertexAttribIOffsetEXT;
        PFNGLVERTEXARRAYVERTEXATTRIBLFORMATEXTPROC              VertexArrayVertexAttribLFormatEXT;
        PFNGLVERTEXARRAYVERTEXATTRIBLOFFSETEXTPROC              VertexArrayVertexAttribLOffsetEXT;
        PFNGLVERTEXARRAYVERTEXATTRIBOFFSETEXTPROC               VertexArrayVertexAttribOffsetEXT;
        PFNGLVERTEXARRAYVERTEXBINDINGDIVISOREXTPROC             VertexArrayVertexBindingDivisorEXT;
        PFNGLVERTEXARRAYVERTEXBUFFERPROC                        VertexArrayVertexBuffer;
        PFNGLVERTEXARRAYVERTEXBUFFERSPROC                       VertexArrayVertexBuffers;
        PFNGLVERTEXARRAYVERTEXOFFSETEXTPROC                     VertexArrayVertexOffsetEXT;
        PFNGLVERTEXATTRIB1DPROC                                 VertexAttrib1d;
        PFNGLVERTEXATTRIB1DVPROC                                VertexAttrib1dv;
        PFNGLVERTEXATTRIB1FPROC                                 VertexAttrib1f;
        PFNGLVERTEXATTRIB1FVPROC                                VertexAttrib1fv;
        PFNGLVERTEXATTRIB1SPROC                                 VertexAttrib1s;
        PFNGLVERTEXATTRIB1SVPROC                                VertexAttrib1sv;
        PFNGLVERTEXATTRIB2DPROC                                 VertexAttrib2d;
        PFNGLVERTEXATTRIB2DVPROC                                VertexAttrib2dv;
        PFNGLVERTEXATTRIB2FPROC                                 VertexAttrib2f;
        PFNGLVERTEXATTRIB2FVPROC                                VertexAttrib2fv;
        PFNGLVERTEXATTRIB2SPROC                                 VertexAttrib2s;
        PFNGLVERTEXATTRIB2SVPROC                                VertexAttrib2sv;
        PFNGLVERTEXATTRIB3DPROC                                 VertexAttrib3d;
        PFNGLVERTEXATTRIB3DVPROC                                VertexAttrib3dv;
        PFNGLVERTEXATTRIB3FPROC                                 VertexAttrib3f;
        PFNGLVERTEXATTRIB3FVPROC                                VertexAttrib3fv;
        PFNGLVERTEXATTRIB3SPROC                                 VertexAttrib3s;
        PFNGLVERTEXATTRIB3SVPROC                                VertexAttrib3sv;
        PFNGLVERTEXATTRIB4NBVPROC                               VertexAttrib4Nbv;
        PFNGLVERTEXATTRIB4NIVPROC                               VertexAttrib4Niv;
        PFNGLVERTEXATTRIB4NSVPROC                               VertexAttrib4Nsv;
        PFNGLVERTEXATTRIB4NUBPROC                               VertexAttrib4Nub;
        PFNGLVERTEXATTRIB4NUBVPROC                              VertexAttrib4Nubv;
        PFNGLVERTEXATTRIB4NUIVPROC                              VertexAttrib4Nuiv;
        PFNGLVERTEXATTRIB4NUSVPROC                              VertexAttrib4Nusv;
        PFNGLVERTEXATTRIB4BVPROC                                VertexAttrib4bv;
        PFNGLVERTEXATTRIB4DPROC                                 VertexAttrib4d;
        PFNGLVERTEXATTRIB4DVPROC                                VertexAttrib4dv;
        PFNGLVERTEXATTRIB4FPROC                                 VertexAttrib4f;
        PFNGLVERTEXATTRIB4FVPROC                                VertexAttrib4fv;
        PFNGLVERTEXATTRIB4IVPROC                                VertexAttrib4iv;
        PFNGLVERTEXATTRIB4SPROC                                 VertexAttrib4s;
        PFNGLVERTEXATTRIB4SVPROC                                VertexAttrib4sv;
        PFNGLVERTEXATTRIB4UBVPROC                               VertexAttrib4ubv;
        PFNGLVERTEXATTRIB4UIVPROC                               VertexAttrib4uiv;
        PFNGLVERTEXATTRIB4USVPROC                               VertexAttrib4usv;
        PFNGLVERTEXATTRIBBINDINGPROC                            VertexAttribBinding;
        PFNGLVERTEXATTRIBDIVISORPROC                            VertexAttribDivisor;
        PFNGLVERTEXATTRIBDIVISORARBPROC                         VertexAttribDivisorARB;
        PFNGLVERTEXATTRIBFORMATPROC                             VertexAttribFormat;
        PFNGLVERTEXATTRIBFORMATNVPROC                           VertexAttribFormatNV;
        PFNGLVERTEXATTRIBI1IPROC                                VertexAttribI1i;
        PFNGLVERTEXATTRIBI1IVPROC                               VertexAttribI1iv;
        PFNGLVERTEXATTRIBI1UIPROC                               VertexAttribI1ui;
        PFNGLVERTEXATTRIBI1UIVPROC                              VertexAttribI1uiv;
        PFNGLVERTEXATTRIBI2IPROC                                VertexAttribI2i;
        PFNGLVERTEXATTRIBI2IVPROC                               VertexAttribI2iv;
        PFNGLVERTEXATTRIBI2UIPROC                               VertexAttribI2ui;
        PFNGLVERTEXATTRIBI2UIVPROC                              VertexAttribI2uiv;
        PFNGLVERTEXATTRIBI3IPROC                                VertexAttribI3i;
        PFNGLVERTEXATTRIBI3IVPROC                               VertexAttribI3iv;
        PFNGLVERTEXATTRIBI3UIPROC                               VertexAttribI3ui;
        PFNGLVERTEXATTRIBI3UIVPROC                              VertexAttribI3uiv;
        PFNGLVERTEXATTRIBI4BVPROC                               VertexAttribI4bv;
        PFNGLVERTEXATTRIBI4IPROC                                VertexAttribI4i;
        PFNGLVERTEXATTRIBI4IVPROC                               VertexAttribI4iv;
        PFNGLVERTEXATTRIBI4SVPROC                               VertexAttribI4sv;
        PFNGLVERTEXATTRIBI4UBVPROC                              VertexAttribI4ubv;
        PFNGLVERTEXATTRIBI4UIPROC                               VertexAttribI4ui;
        PFNGLVERTEXATTRIBI4UIVPROC                              VertexAttribI4uiv;
        PFNGLVERTEXATTRIBI4USVPROC                              VertexAttribI4usv;
        PFNGLVERTEXATTRIBIFORMATPROC                            VertexAttribIFormat;
        PFNGLVERTEXATTRIBIFORMATNVPROC                          VertexAttribIFormatNV;
        PFNGLVERTEXATTRIBIPOINTERPROC                           VertexAttribIPointer;
        PFNGLVERTEXATTRIBL1DPROC                                VertexAttribL1d;
        PFNGLVERTEXATTRIBL1DVPROC                               VertexAttribL1dv;
        PFNGLVERTEXATTRIBL1I64NVPROC                            VertexAttribL1i64NV;
        PFNGLVERTEXATTRIBL1I64VNVPROC                           VertexAttribL1i64vNV;
        PFNGLVERTEXATTRIBL1UI64ARBPROC                          VertexAttribL1ui64ARB;
        PFNGLVERTEXATTRIBL1UI64NVPROC                           VertexAttribL1ui64NV;
        PFNGLVERTEXATTRIBL1UI64VARBPROC                         VertexAttribL1ui64vARB;
        PFNGLVERTEXATTRIBL1UI64VNVPROC                          VertexAttribL1ui64vNV;
        PFNGLVERTEXATTRIBL2DPROC                                VertexAttribL2d;
        PFNGLVERTEXATTRIBL2DVPROC                               VertexAttribL2dv;
        PFNGLVERTEXATTRIBL2I64NVPROC                            VertexAttribL2i64NV;
        PFNGLVERTEXATTRIBL2I64VNVPROC                           VertexAttribL2i64vNV;
        PFNGLVERTEXATTRIBL2UI64NVPROC                           VertexAttribL2ui64NV;
        PFNGLVERTEXATTRIBL2UI64VNVPROC                          VertexAttribL2ui64vNV;
        PFNGLVERTEXATTRIBL3DPROC                                VertexAttribL3d;
        PFNGLVERTEXATTRIBL3DVPROC                               VertexAttribL3dv;
        PFNGLVERTEXATTRIBL3I64NVPROC                            VertexAttribL3i64NV;
        PFNGLVERTEXATTRIBL3I64VNVPROC                           VertexAttribL3i64vNV;
        PFNGLVERTEXATTRIBL3UI64NVPROC                           VertexAttribL3ui64NV;
        PFNGLVERTEXATTRIBL3UI64VNVPROC                          VertexAttribL3ui64vNV;
        PFNGLVERTEXATTRIBL4DPROC                                VertexAttribL4d;
        PFNGLVERTEXATTRIBL4DVPROC                               VertexAttribL4dv;
        PFNGLVERTEXATTRIBL4I64NVPROC                            VertexAttribL4i64NV;
        PFNGLVERTEXATTRIBL4I64VNVPROC                           VertexAttribL4i64vNV;
        PFNGLVERTEXATTRIBL4UI64NVPROC                           VertexAttribL4ui64NV;
        PFNGLVERTEXATTRIBL4UI64VNVPROC                          VertexAttribL4ui64vNV;
        PFNGLVERTEXATTRIBLFORMATPROC                            VertexAttribLFormat;
        PFNGLVERTEXATTRIBLFORMATNVPROC                          VertexAttribLFormatNV;
        PFNGLVERTEXATTRIBLPOINTERPROC                           VertexAttribLPointer;
        PFNGLVERTEXATTRIBP1UIPROC                               VertexAttribP1ui;
        PFNGLVERTEXATTRIBP1UIVPROC                              VertexAttribP1uiv;
        PFNGLVERTEXATTRIBP2UIPROC                               VertexAttribP2ui;
        PFNGLVERTEXATTRIBP2UIVPROC                              VertexAttribP2uiv;
        PFNGLVERTEXATTRIBP3UIPROC                               VertexAttribP3ui;
        PFNGLVERTEXATTRIBP3UIVPROC                              VertexAttribP3uiv;
        PFNGLVERTEXATTRIBP4UIPROC                               VertexAttribP4ui;
        PFNGLVERTEXATTRIBP4UIVPROC                              VertexAttribP4uiv;
        PFNGLVERTEXATTRIBPOINTERPROC                            VertexAttribPointer;
        PFNGLVERTEXBINDINGDIVISORPROC                           VertexBindingDivisor;
        PFNGLVERTEXFORMATNVPROC                                 VertexFormatNV;
        PFNGLVIEWPORTPROC                                       Viewport;
        PFNGLVIEWPORTARRAYVPROC                                 ViewportArrayv;
        PFNGLVIEWPORTINDEXEDFPROC                               ViewportIndexedf;
        PFNGLVIEWPORTINDEXEDFVPROC                              ViewportIndexedfv;
        PFNGLVIEWPORTPOSITIONWSCALENVPROC                       ViewportPositionWScaleNV;
        PFNGLVIEWPORTSWIZZLENVPROC                              ViewportSwizzleNV;
        PFNGLWAITSYNCPROC                                       WaitSync;
        PFNGLWAITVKSEMAPHORENVPROC                              WaitVkSemaphoreNV;
        PFNGLWEIGHTPATHSNVPROC                                  WeightPathsNV;
        PFNGLWINDOWRECTANGLESEXTPROC                            WindowRectanglesEXT;
    } gl;
};

GL3W_API extern union ImGL3WProcs imgl3wProcs;

/* OpenGL functions */
#define glActiveProgramEXT                                      imgl3wProcs.gl.ActiveProgramEXT
#define glActiveShaderProgram                                   imgl3wProcs.gl.ActiveShaderProgram
#define glActiveTexture                                         imgl3wProcs.gl.ActiveTexture
#define glApplyFramebufferAttachmentCMAAINTEL                   imgl3wProcs.gl.ApplyFramebufferAttachmentCMAAINTEL
#define glAttachShader                                          imgl3wProcs.gl.AttachShader
#define glBeginConditionalRender                                imgl3wProcs.gl.BeginConditionalRender
#define glBeginConditionalRenderNV                              imgl3wProcs.gl.BeginConditionalRenderNV
#define glBeginPerfMonitorAMD                                   imgl3wProcs.gl.BeginPerfMonitorAMD
#define glBeginPerfQueryINTEL                                   imgl3wProcs.gl.BeginPerfQueryINTEL
#define glBeginQuery                                            imgl3wProcs.gl.BeginQuery
#define glBeginQueryIndexed                                     imgl3wProcs.gl.BeginQueryIndexed
#define glBeginTransformFeedback                                imgl3wProcs.gl.BeginTransformFeedback
#define glBindAttribLocation                                    imgl3wProcs.gl.BindAttribLocation
#define glBindBuffer                                            imgl3wProcs.gl.BindBuffer
#define glBindBufferBase                                        imgl3wProcs.gl.BindBufferBase
#define glBindBufferRange                                       imgl3wProcs.gl.BindBufferRange
#define glBindBuffersBase                                       imgl3wProcs.gl.BindBuffersBase
#define glBindBuffersRange                                      imgl3wProcs.gl.BindBuffersRange
#define glBindFragDataLocation                                  imgl3wProcs.gl.BindFragDataLocation
#define glBindFragDataLocationIndexed                           imgl3wProcs.gl.BindFragDataLocationIndexed
#define glBindFramebuffer                                       imgl3wProcs.gl.BindFramebuffer
#define glBindImageTexture                                      imgl3wProcs.gl.BindImageTexture
#define glBindImageTextures                                     imgl3wProcs.gl.BindImageTextures
#define glBindMultiTextureEXT                                   imgl3wProcs.gl.BindMultiTextureEXT
#define glBindProgramPipeline                                   imgl3wProcs.gl.BindProgramPipeline
#define glBindRenderbuffer                                      imgl3wProcs.gl.BindRenderbuffer
#define glBindSampler                                           imgl3wProcs.gl.BindSampler
#define glBindSamplers                                          imgl3wProcs.gl.BindSamplers
#define glBindShadingRateImageNV                                imgl3wProcs.gl.BindShadingRateImageNV
#define glBindTexture                                           imgl3wProcs.gl.BindTexture
#define glBindTextureUnit                                       imgl3wProcs.gl.BindTextureUnit
#define glBindTextures                                          imgl3wProcs.gl.BindTextures
#define glBindTransformFeedback                                 imgl3wProcs.gl.BindTransformFeedback
#define glBindVertexArray                                       imgl3wProcs.gl.BindVertexArray
#define glBindVertexBuffer                                      imgl3wProcs.gl.BindVertexBuffer
#define glBindVertexBuffers                                     imgl3wProcs.gl.BindVertexBuffers
#define glBlendBarrierKHR                                       imgl3wProcs.gl.BlendBarrierKHR
#define glBlendBarrierNV                                        imgl3wProcs.gl.BlendBarrierNV
#define glBlendColor                                            imgl3wProcs.gl.BlendColor
#define glBlendEquation                                         imgl3wProcs.gl.BlendEquation
#define glBlendEquationSeparate                                 imgl3wProcs.gl.BlendEquationSeparate
#define glBlendEquationSeparatei                                imgl3wProcs.gl.BlendEquationSeparatei
#define glBlendEquationSeparateiARB                             imgl3wProcs.gl.BlendEquationSeparateiARB
#define glBlendEquationi                                        imgl3wProcs.gl.BlendEquationi
#define glBlendEquationiARB                                     imgl3wProcs.gl.BlendEquationiARB
#define glBlendFunc                                             imgl3wProcs.gl.BlendFunc
#define glBlendFuncSeparate                                     imgl3wProcs.gl.BlendFuncSeparate
#define glBlendFuncSeparatei                                    imgl3wProcs.gl.BlendFuncSeparatei
#define glBlendFuncSeparateiARB                                 imgl3wProcs.gl.BlendFuncSeparateiARB
#define glBlendFunci                                            imgl3wProcs.gl.BlendFunci
#define glBlendFunciARB                                         imgl3wProcs.gl.BlendFunciARB
#define glBlendParameteriNV                                     imgl3wProcs.gl.BlendParameteriNV
#define glBlitFramebuffer                                       imgl3wProcs.gl.BlitFramebuffer
#define glBlitNamedFramebuffer                                  imgl3wProcs.gl.BlitNamedFramebuffer
#define glBufferAddressRangeNV                                  imgl3wProcs.gl.BufferAddressRangeNV
#define glBufferAttachMemoryNV                                  imgl3wProcs.gl.BufferAttachMemoryNV
#define glBufferData                                            imgl3wProcs.gl.BufferData
#define glBufferPageCommitmentARB                               imgl3wProcs.gl.BufferPageCommitmentARB
#define glBufferPageCommitmentMemNV                             imgl3wProcs.gl.BufferPageCommitmentMemNV
#define glBufferStorage                                         imgl3wProcs.gl.BufferStorage
#define glBufferSubData                                         imgl3wProcs.gl.BufferSubData
#define glCallCommandListNV                                     imgl3wProcs.gl.CallCommandListNV
#define glCheckFramebufferStatus                                imgl3wProcs.gl.CheckFramebufferStatus
#define glCheckNamedFramebufferStatus                           imgl3wProcs.gl.CheckNamedFramebufferStatus
#define glCheckNamedFramebufferStatusEXT                        imgl3wProcs.gl.CheckNamedFramebufferStatusEXT
#define glClampColor                                            imgl3wProcs.gl.ClampColor
#define glClear                                                 imgl3wProcs.gl.Clear
#define glClearBufferData                                       imgl3wProcs.gl.ClearBufferData
#define glClearBufferSubData                                    imgl3wProcs.gl.ClearBufferSubData
#define glClearBufferfi                                         imgl3wProcs.gl.ClearBufferfi
#define glClearBufferfv                                         imgl3wProcs.gl.ClearBufferfv
#define glClearBufferiv                                         imgl3wProcs.gl.ClearBufferiv
#define glClearBufferuiv                                        imgl3wProcs.gl.ClearBufferuiv
#define glClearColor                                            imgl3wProcs.gl.ClearColor
#define glClearDepth                                            imgl3wProcs.gl.ClearDepth
#define glClearDepthdNV                                         imgl3wProcs.gl.ClearDepthdNV
#define glClearDepthf                                           imgl3wProcs.gl.ClearDepthf
#define glClearNamedBufferData                                  imgl3wProcs.gl.ClearNamedBufferData
#define glClearNamedBufferDataEXT                               imgl3wProcs.gl.ClearNamedBufferDataEXT
#define glClearNamedBufferSubData                               imgl3wProcs.gl.ClearNamedBufferSubData
#define glClearNamedBufferSubDataEXT                            imgl3wProcs.gl.ClearNamedBufferSubDataEXT
#define glClearNamedFramebufferfi                               imgl3wProcs.gl.ClearNamedFramebufferfi
#define glClearNamedFramebufferfv                               imgl3wProcs.gl.ClearNamedFramebufferfv
#define glClearNamedFramebufferiv                               imgl3wProcs.gl.ClearNamedFramebufferiv
#define glClearNamedFramebufferuiv                              imgl3wProcs.gl.ClearNamedFramebufferuiv
#define glClearStencil                                          imgl3wProcs.gl.ClearStencil
#define glClearTexImage                                         imgl3wProcs.gl.ClearTexImage
#define glClearTexSubImage                                      imgl3wProcs.gl.ClearTexSubImage
#define glClientAttribDefaultEXT                                imgl3wProcs.gl.ClientAttribDefaultEXT
#define glClientWaitSync                                        imgl3wProcs.gl.ClientWaitSync
#define glClipControl                                           imgl3wProcs.gl.ClipControl
#define glColorFormatNV                                         imgl3wProcs.gl.ColorFormatNV
#define glColorMask                                             imgl3wProcs.gl.ColorMask
#define glColorMaski                                            imgl3wProcs.gl.ColorMaski
#define glCommandListSegmentsNV                                 imgl3wProcs.gl.CommandListSegmentsNV
#define glCompileCommandListNV                                  imgl3wProcs.gl.CompileCommandListNV
#define glCompileShader                                         imgl3wProcs.gl.CompileShader
#define glCompileShaderIncludeARB                               imgl3wProcs.gl.CompileShaderIncludeARB
#define glCompressedMultiTexImage1DEXT                          imgl3wProcs.gl.CompressedMultiTexImage1DEXT
#define glCompressedMultiTexImage2DEXT                          imgl3wProcs.gl.CompressedMultiTexImage2DEXT
#define glCompressedMultiTexImage3DEXT                          imgl3wProcs.gl.CompressedMultiTexImage3DEXT
#define glCompressedMultiTexSubImage1DEXT                       imgl3wProcs.gl.CompressedMultiTexSubImage1DEXT
#define glCompressedMultiTexSubImage2DEXT                       imgl3wProcs.gl.CompressedMultiTexSubImage2DEXT
#define glCompressedMultiTexSubImage3DEXT                       imgl3wProcs.gl.CompressedMultiTexSubImage3DEXT
#define glCompressedTexImage1D                                  imgl3wProcs.gl.CompressedTexImage1D
#define glCompressedTexImage2D                                  imgl3wProcs.gl.CompressedTexImage2D
#define glCompressedTexImage3D                                  imgl3wProcs.gl.CompressedTexImage3D
#define glCompressedTexSubImage1D                               imgl3wProcs.gl.CompressedTexSubImage1D
#define glCompressedTexSubImage2D                               imgl3wProcs.gl.CompressedTexSubImage2D
#define glCompressedTexSubImage3D                               imgl3wProcs.gl.CompressedTexSubImage3D
#define glCompressedTextureImage1DEXT                           imgl3wProcs.gl.CompressedTextureImage1DEXT
#define glCompressedTextureImage2DEXT                           imgl3wProcs.gl.CompressedTextureImage2DEXT
#define glCompressedTextureImage3DEXT                           imgl3wProcs.gl.CompressedTextureImage3DEXT
#define glCompressedTextureSubImage1D                           imgl3wProcs.gl.CompressedTextureSubImage1D
#define glCompressedTextureSubImage1DEXT                        imgl3wProcs.gl.CompressedTextureSubImage1DEXT
#define glCompressedTextureSubImage2D                           imgl3wProcs.gl.CompressedTextureSubImage2D
#define glCompressedTextureSubImage2DEXT                        imgl3wProcs.gl.CompressedTextureSubImage2DEXT
#define glCompressedTextureSubImage3D                           imgl3wProcs.gl.CompressedTextureSubImage3D
#define glCompressedTextureSubImage3DEXT                        imgl3wProcs.gl.CompressedTextureSubImage3DEXT
#define glConservativeRasterParameterfNV                        imgl3wProcs.gl.ConservativeRasterParameterfNV
#define glConservativeRasterParameteriNV                        imgl3wProcs.gl.ConservativeRasterParameteriNV
#define glCopyBufferSubData                                     imgl3wProcs.gl.CopyBufferSubData
#define glCopyImageSubData                                      imgl3wProcs.gl.CopyImageSubData
#define glCopyMultiTexImage1DEXT                                imgl3wProcs.gl.CopyMultiTexImage1DEXT
#define glCopyMultiTexImage2DEXT                                imgl3wProcs.gl.CopyMultiTexImage2DEXT
#define glCopyMultiTexSubImage1DEXT                             imgl3wProcs.gl.CopyMultiTexSubImage1DEXT
#define glCopyMultiTexSubImage2DEXT                             imgl3wProcs.gl.CopyMultiTexSubImage2DEXT
#define glCopyMultiTexSubImage3DEXT                             imgl3wProcs.gl.CopyMultiTexSubImage3DEXT
#define glCopyNamedBufferSubData                                imgl3wProcs.gl.CopyNamedBufferSubData
#define glCopyPathNV                                            imgl3wProcs.gl.CopyPathNV
#define glCopyTexImage1D                                        imgl3wProcs.gl.CopyTexImage1D
#define glCopyTexImage2D                                        imgl3wProcs.gl.CopyTexImage2D
#define glCopyTexSubImage1D                                     imgl3wProcs.gl.CopyTexSubImage1D
#define glCopyTexSubImage2D                                     imgl3wProcs.gl.CopyTexSubImage2D
#define glCopyTexSubImage3D                                     imgl3wProcs.gl.CopyTexSubImage3D
#define glCopyTextureImage1DEXT                                 imgl3wProcs.gl.CopyTextureImage1DEXT
#define glCopyTextureImage2DEXT                                 imgl3wProcs.gl.CopyTextureImage2DEXT
#define glCopyTextureSubImage1D                                 imgl3wProcs.gl.CopyTextureSubImage1D
#define glCopyTextureSubImage1DEXT                              imgl3wProcs.gl.CopyTextureSubImage1DEXT
#define glCopyTextureSubImage2D                                 imgl3wProcs.gl.CopyTextureSubImage2D
#define glCopyTextureSubImage2DEXT                              imgl3wProcs.gl.CopyTextureSubImage2DEXT
#define glCopyTextureSubImage3D                                 imgl3wProcs.gl.CopyTextureSubImage3D
#define glCopyTextureSubImage3DEXT                              imgl3wProcs.gl.CopyTextureSubImage3DEXT
#define glCoverFillPathInstancedNV                              imgl3wProcs.gl.CoverFillPathInstancedNV
#define glCoverFillPathNV                                       imgl3wProcs.gl.CoverFillPathNV
#define glCoverStrokePathInstancedNV                            imgl3wProcs.gl.CoverStrokePathInstancedNV
#define glCoverStrokePathNV                                     imgl3wProcs.gl.CoverStrokePathNV
#define glCoverageModulationNV                                  imgl3wProcs.gl.CoverageModulationNV
#define glCoverageModulationTableNV                             imgl3wProcs.gl.CoverageModulationTableNV
#define glCreateBuffers                                         imgl3wProcs.gl.CreateBuffers
#define glCreateCommandListsNV                                  imgl3wProcs.gl.CreateCommandListsNV
#define glCreateFramebuffers                                    imgl3wProcs.gl.CreateFramebuffers
#define glCreatePerfQueryINTEL                                  imgl3wProcs.gl.CreatePerfQueryINTEL
#define glCreateProgram                                         imgl3wProcs.gl.CreateProgram
#define glCreateProgramPipelines                                imgl3wProcs.gl.CreateProgramPipelines
#define glCreateQueries                                         imgl3wProcs.gl.CreateQueries
#define glCreateRenderbuffers                                   imgl3wProcs.gl.CreateRenderbuffers
#define glCreateSamplers                                        imgl3wProcs.gl.CreateSamplers
#define glCreateShader                                          imgl3wProcs.gl.CreateShader
#define glCreateShaderProgramEXT                                imgl3wProcs.gl.CreateShaderProgramEXT
#define glCreateShaderProgramv                                  imgl3wProcs.gl.CreateShaderProgramv
#define glCreateStatesNV                                        imgl3wProcs.gl.CreateStatesNV
#define glCreateSyncFromCLeventARB                              imgl3wProcs.gl.CreateSyncFromCLeventARB
#define glCreateTextures                                        imgl3wProcs.gl.CreateTextures
#define glCreateTransformFeedbacks                              imgl3wProcs.gl.CreateTransformFeedbacks
#define glCreateVertexArrays                                    imgl3wProcs.gl.CreateVertexArrays
#define glCullFace                                              imgl3wProcs.gl.CullFace
#define glDebugMessageCallback                                  imgl3wProcs.gl.DebugMessageCallback
#define glDebugMessageCallbackARB                               imgl3wProcs.gl.DebugMessageCallbackARB
#define glDebugMessageControl                                   imgl3wProcs.gl.DebugMessageControl
#define glDebugMessageControlARB                                imgl3wProcs.gl.DebugMessageControlARB
#define glDebugMessageInsert                                    imgl3wProcs.gl.DebugMessageInsert
#define glDebugMessageInsertARB                                 imgl3wProcs.gl.DebugMessageInsertARB
#define glDeleteBuffers                                         imgl3wProcs.gl.DeleteBuffers
#define glDeleteCommandListsNV                                  imgl3wProcs.gl.DeleteCommandListsNV
#define glDeleteFramebuffers                                    imgl3wProcs.gl.DeleteFramebuffers
#define glDeleteNamedStringARB                                  imgl3wProcs.gl.DeleteNamedStringARB
#define glDeletePathsNV                                         imgl3wProcs.gl.DeletePathsNV
#define glDeletePerfMonitorsAMD                                 imgl3wProcs.gl.DeletePerfMonitorsAMD
#define glDeletePerfQueryINTEL                                  imgl3wProcs.gl.DeletePerfQueryINTEL
#define glDeleteProgram                                         imgl3wProcs.gl.DeleteProgram
#define glDeleteProgramPipelines                                imgl3wProcs.gl.DeleteProgramPipelines
#define glDeleteQueries                                         imgl3wProcs.gl.DeleteQueries
#define glDeleteRenderbuffers                                   imgl3wProcs.gl.DeleteRenderbuffers
#define glDeleteSamplers                                        imgl3wProcs.gl.DeleteSamplers
#define glDeleteShader                                          imgl3wProcs.gl.DeleteShader
#define glDeleteStatesNV                                        imgl3wProcs.gl.DeleteStatesNV
#define glDeleteSync                                            imgl3wProcs.gl.DeleteSync
#define glDeleteTextures                                        imgl3wProcs.gl.DeleteTextures
#define glDeleteTransformFeedbacks                              imgl3wProcs.gl.DeleteTransformFeedbacks
#define glDeleteVertexArrays                                    imgl3wProcs.gl.DeleteVertexArrays
#define glDepthBoundsdNV                                        imgl3wProcs.gl.DepthBoundsdNV
#define glDepthFunc                                             imgl3wProcs.gl.DepthFunc
#define glDepthMask                                             imgl3wProcs.gl.DepthMask
#define glDepthRange                                            imgl3wProcs.gl.DepthRange
#define glDepthRangeArraydvNV                                   imgl3wProcs.gl.DepthRangeArraydvNV
#define glDepthRangeArrayv                                      imgl3wProcs.gl.DepthRangeArrayv
#define glDepthRangeIndexed                                     imgl3wProcs.gl.DepthRangeIndexed
#define glDepthRangeIndexeddNV                                  imgl3wProcs.gl.DepthRangeIndexeddNV
#define glDepthRangedNV                                         imgl3wProcs.gl.DepthRangedNV
#define glDepthRangef                                           imgl3wProcs.gl.DepthRangef
#define glDetachShader                                          imgl3wProcs.gl.DetachShader
#define glDisable                                               imgl3wProcs.gl.Disable
#define glDisableClientStateIndexedEXT                          imgl3wProcs.gl.DisableClientStateIndexedEXT
#define glDisableClientStateiEXT                                imgl3wProcs.gl.DisableClientStateiEXT
#define glDisableIndexedEXT                                     imgl3wProcs.gl.DisableIndexedEXT
#define glDisableVertexArrayAttrib                              imgl3wProcs.gl.DisableVertexArrayAttrib
#define glDisableVertexArrayAttribEXT                           imgl3wProcs.gl.DisableVertexArrayAttribEXT
#define glDisableVertexArrayEXT                                 imgl3wProcs.gl.DisableVertexArrayEXT
#define glDisableVertexAttribArray                              imgl3wProcs.gl.DisableVertexAttribArray
#define glDisablei                                              imgl3wProcs.gl.Disablei
#define glDispatchCompute                                       imgl3wProcs.gl.DispatchCompute
#define glDispatchComputeGroupSizeARB                           imgl3wProcs.gl.DispatchComputeGroupSizeARB
#define glDispatchComputeIndirect                               imgl3wProcs.gl.DispatchComputeIndirect
#define glDrawArrays                                            imgl3wProcs.gl.DrawArrays
#define glDrawArraysIndirect                                    imgl3wProcs.gl.DrawArraysIndirect
#define glDrawArraysInstanced                                   imgl3wProcs.gl.DrawArraysInstanced
#define glDrawArraysInstancedARB                                imgl3wProcs.gl.DrawArraysInstancedARB
#define glDrawArraysInstancedBaseInstance                       imgl3wProcs.gl.DrawArraysInstancedBaseInstance
#define glDrawArraysInstancedEXT                                imgl3wProcs.gl.DrawArraysInstancedEXT
#define glDrawBuffer                                            imgl3wProcs.gl.DrawBuffer
#define glDrawBuffers                                           imgl3wProcs.gl.DrawBuffers
#define glDrawCommandsAddressNV                                 imgl3wProcs.gl.DrawCommandsAddressNV
#define glDrawCommandsNV                                        imgl3wProcs.gl.DrawCommandsNV
#define glDrawCommandsStatesAddressNV                           imgl3wProcs.gl.DrawCommandsStatesAddressNV
#define glDrawCommandsStatesNV                                  imgl3wProcs.gl.DrawCommandsStatesNV
#define glDrawElements                                          imgl3wProcs.gl.DrawElements
#define glDrawElementsBaseVertex                                imgl3wProcs.gl.DrawElementsBaseVertex
#define glDrawElementsIndirect                                  imgl3wProcs.gl.DrawElementsIndirect
#define glDrawElementsInstanced                                 imgl3wProcs.gl.DrawElementsInstanced
#define glDrawElementsInstancedARB                              imgl3wProcs.gl.DrawElementsInstancedARB
#define glDrawElementsInstancedBaseInstance                     imgl3wProcs.gl.DrawElementsInstancedBaseInstance
#define glDrawElementsInstancedBaseVertex                       imgl3wProcs.gl.DrawElementsInstancedBaseVertex
#define glDrawElementsInstancedBaseVertexBaseInstance           imgl3wProcs.gl.DrawElementsInstancedBaseVertexBaseInstance
#define glDrawElementsInstancedEXT                              imgl3wProcs.gl.DrawElementsInstancedEXT
#define glDrawMeshTasksIndirectNV                               imgl3wProcs.gl.DrawMeshTasksIndirectNV
#define glDrawMeshTasksNV                                       imgl3wProcs.gl.DrawMeshTasksNV
#define glDrawRangeElements                                     imgl3wProcs.gl.DrawRangeElements
#define glDrawRangeElementsBaseVertex                           imgl3wProcs.gl.DrawRangeElementsBaseVertex
#define glDrawTransformFeedback                                 imgl3wProcs.gl.DrawTransformFeedback
#define glDrawTransformFeedbackInstanced                        imgl3wProcs.gl.DrawTransformFeedbackInstanced
#define glDrawTransformFeedbackStream                           imgl3wProcs.gl.DrawTransformFeedbackStream
#define glDrawTransformFeedbackStreamInstanced                  imgl3wProcs.gl.DrawTransformFeedbackStreamInstanced
#define glDrawVkImageNV                                         imgl3wProcs.gl.DrawVkImageNV
#define glEGLImageTargetTexStorageEXT                           imgl3wProcs.gl.EGLImageTargetTexStorageEXT
#define glEGLImageTargetTextureStorageEXT                       imgl3wProcs.gl.EGLImageTargetTextureStorageEXT
#define glEdgeFlagFormatNV                                      imgl3wProcs.gl.EdgeFlagFormatNV
#define glEnable                                                imgl3wProcs.gl.Enable
#define glEnableClientStateIndexedEXT                           imgl3wProcs.gl.EnableClientStateIndexedEXT
#define glEnableClientStateiEXT                                 imgl3wProcs.gl.EnableClientStateiEXT
#define glEnableIndexedEXT                                      imgl3wProcs.gl.EnableIndexedEXT
#define glEnableVertexArrayAttrib                               imgl3wProcs.gl.EnableVertexArrayAttrib
#define glEnableVertexArrayAttribEXT                            imgl3wProcs.gl.EnableVertexArrayAttribEXT
#define glEnableVertexArrayEXT                                  imgl3wProcs.gl.EnableVertexArrayEXT
#define glEnableVertexAttribArray                               imgl3wProcs.gl.EnableVertexAttribArray
#define glEnablei                                               imgl3wProcs.gl.Enablei
#define glEndConditionalRender                                  imgl3wProcs.gl.EndConditionalRender
#define glEndConditionalRenderNV                                imgl3wProcs.gl.EndConditionalRenderNV
#define glEndPerfMonitorAMD                                     imgl3wProcs.gl.EndPerfMonitorAMD
#define glEndPerfQueryINTEL                                     imgl3wProcs.gl.EndPerfQueryINTEL
#define glEndQuery                                              imgl3wProcs.gl.EndQuery
#define glEndQueryIndexed                                       imgl3wProcs.gl.EndQueryIndexed
#define glEndTransformFeedback                                  imgl3wProcs.gl.EndTransformFeedback
#define glEvaluateDepthValuesARB                                imgl3wProcs.gl.EvaluateDepthValuesARB
#define glFenceSync                                             imgl3wProcs.gl.FenceSync
#define glFinish                                                imgl3wProcs.gl.Finish
#define glFlush                                                 imgl3wProcs.gl.Flush
#define glFlushMappedBufferRange                                imgl3wProcs.gl.FlushMappedBufferRange
#define glFlushMappedNamedBufferRange                           imgl3wProcs.gl.FlushMappedNamedBufferRange
#define glFlushMappedNamedBufferRangeEXT                        imgl3wProcs.gl.FlushMappedNamedBufferRangeEXT
#define glFogCoordFormatNV                                      imgl3wProcs.gl.FogCoordFormatNV
#define glFragmentCoverageColorNV                               imgl3wProcs.gl.FragmentCoverageColorNV
#define glFramebufferDrawBufferEXT                              imgl3wProcs.gl.FramebufferDrawBufferEXT
#define glFramebufferDrawBuffersEXT                             imgl3wProcs.gl.FramebufferDrawBuffersEXT
#define glFramebufferFetchBarrierEXT                            imgl3wProcs.gl.FramebufferFetchBarrierEXT
#define glFramebufferParameteri                                 imgl3wProcs.gl.FramebufferParameteri
#define glFramebufferParameteriMESA                             imgl3wProcs.gl.FramebufferParameteriMESA
#define glFramebufferReadBufferEXT                              imgl3wProcs.gl.FramebufferReadBufferEXT
#define glFramebufferRenderbuffer                               imgl3wProcs.gl.FramebufferRenderbuffer
#define glFramebufferSampleLocationsfvARB                       imgl3wProcs.gl.FramebufferSampleLocationsfvARB
#define glFramebufferSampleLocationsfvNV                        imgl3wProcs.gl.FramebufferSampleLocationsfvNV
#define glFramebufferTexture                                    imgl3wProcs.gl.FramebufferTexture
#define glFramebufferTexture1D                                  imgl3wProcs.gl.FramebufferTexture1D
#define glFramebufferTexture2D                                  imgl3wProcs.gl.FramebufferTexture2D
#define glFramebufferTexture3D                                  imgl3wProcs.gl.FramebufferTexture3D
#define glFramebufferTextureARB                                 imgl3wProcs.gl.FramebufferTextureARB
#define glFramebufferTextureFaceARB                             imgl3wProcs.gl.FramebufferTextureFaceARB
#define glFramebufferTextureLayer                               imgl3wProcs.gl.FramebufferTextureLayer
#define glFramebufferTextureLayerARB                            imgl3wProcs.gl.FramebufferTextureLayerARB
#define glFramebufferTextureMultiviewOVR                        imgl3wProcs.gl.FramebufferTextureMultiviewOVR
#define glFrontFace                                             imgl3wProcs.gl.FrontFace
#define glGenBuffers                                            imgl3wProcs.gl.GenBuffers
#define glGenFramebuffers                                       imgl3wProcs.gl.GenFramebuffers
#define glGenPathsNV                                            imgl3wProcs.gl.GenPathsNV
#define glGenPerfMonitorsAMD                                    imgl3wProcs.gl.GenPerfMonitorsAMD
#define glGenProgramPipelines                                   imgl3wProcs.gl.GenProgramPipelines
#define glGenQueries                                            imgl3wProcs.gl.GenQueries
#define glGenRenderbuffers                                      imgl3wProcs.gl.GenRenderbuffers
#define glGenSamplers                                           imgl3wProcs.gl.GenSamplers
#define glGenTextures                                           imgl3wProcs.gl.GenTextures
#define glGenTransformFeedbacks                                 imgl3wProcs.gl.GenTransformFeedbacks
#define glGenVertexArrays                                       imgl3wProcs.gl.GenVertexArrays
#define glGenerateMipmap                                        imgl3wProcs.gl.GenerateMipmap
#define glGenerateMultiTexMipmapEXT                             imgl3wProcs.gl.GenerateMultiTexMipmapEXT
#define glGenerateTextureMipmap                                 imgl3wProcs.gl.GenerateTextureMipmap
#define glGenerateTextureMipmapEXT                              imgl3wProcs.gl.GenerateTextureMipmapEXT
#define glGetActiveAtomicCounterBufferiv                        imgl3wProcs.gl.GetActiveAtomicCounterBufferiv
#define glGetActiveAttrib                                       imgl3wProcs.gl.GetActiveAttrib
#define glGetActiveSubroutineName                               imgl3wProcs.gl.GetActiveSubroutineName
#define glGetActiveSubroutineUniformName                        imgl3wProcs.gl.GetActiveSubroutineUniformName
#define glGetActiveSubroutineUniformiv                          imgl3wProcs.gl.GetActiveSubroutineUniformiv
#define glGetActiveUniform                                      imgl3wProcs.gl.GetActiveUniform
#define glGetActiveUniformBlockName                             imgl3wProcs.gl.GetActiveUniformBlockName
#define glGetActiveUniformBlockiv                               imgl3wProcs.gl.GetActiveUniformBlockiv
#define glGetActiveUniformName                                  imgl3wProcs.gl.GetActiveUniformName
#define glGetActiveUniformsiv                                   imgl3wProcs.gl.GetActiveUniformsiv
#define glGetAttachedShaders                                    imgl3wProcs.gl.GetAttachedShaders
#define glGetAttribLocation                                     imgl3wProcs.gl.GetAttribLocation
#define glGetBooleanIndexedvEXT                                 imgl3wProcs.gl.GetBooleanIndexedvEXT
#define glGetBooleani_v                                         imgl3wProcs.gl.GetBooleani_v
#define glGetBooleanv                                           imgl3wProcs.gl.GetBooleanv
#define glGetBufferParameteri64v                                imgl3wProcs.gl.GetBufferParameteri64v
#define glGetBufferParameteriv                                  imgl3wProcs.gl.GetBufferParameteriv
#define glGetBufferParameterui64vNV                             imgl3wProcs.gl.GetBufferParameterui64vNV
#define glGetBufferPointerv                                     imgl3wProcs.gl.GetBufferPointerv
#define glGetBufferSubData                                      imgl3wProcs.gl.GetBufferSubData
#define glGetCommandHeaderNV                                    imgl3wProcs.gl.GetCommandHeaderNV
#define glGetCompressedMultiTexImageEXT                         imgl3wProcs.gl.GetCompressedMultiTexImageEXT
#define glGetCompressedTexImage                                 imgl3wProcs.gl.GetCompressedTexImage
#define glGetCompressedTextureImage                             imgl3wProcs.gl.GetCompressedTextureImage
#define glGetCompressedTextureImageEXT                          imgl3wProcs.gl.GetCompressedTextureImageEXT
#define glGetCompressedTextureSubImage                          imgl3wProcs.gl.GetCompressedTextureSubImage
#define glGetCoverageModulationTableNV                          imgl3wProcs.gl.GetCoverageModulationTableNV
#define glGetDebugMessageLog                                    imgl3wProcs.gl.GetDebugMessageLog
#define glGetDebugMessageLogARB                                 imgl3wProcs.gl.GetDebugMessageLogARB
#define glGetDoubleIndexedvEXT                                  imgl3wProcs.gl.GetDoubleIndexedvEXT
#define glGetDoublei_v                                          imgl3wProcs.gl.GetDoublei_v
#define glGetDoublei_vEXT                                       imgl3wProcs.gl.GetDoublei_vEXT
#define glGetDoublev                                            imgl3wProcs.gl.GetDoublev
#define glGetError                                              imgl3wProcs.gl.GetError
#define glGetFirstPerfQueryIdINTEL                              imgl3wProcs.gl.GetFirstPerfQueryIdINTEL
#define glGetFloatIndexedvEXT                                   imgl3wProcs.gl.GetFloatIndexedvEXT
#define glGetFloati_v                                           imgl3wProcs.gl.GetFloati_v
#define glGetFloati_vEXT                                        imgl3wProcs.gl.GetFloati_vEXT
#define glGetFloatv                                             imgl3wProcs.gl.GetFloatv
#define glGetFragDataIndex                                      imgl3wProcs.gl.GetFragDataIndex
#define glGetFragDataLocation                                   imgl3wProcs.gl.GetFragDataLocation
#define glGetFramebufferAttachmentParameteriv                   imgl3wProcs.gl.GetFramebufferAttachmentParameteriv
#define glGetFramebufferParameteriv                             imgl3wProcs.gl.GetFramebufferParameteriv
#define glGetFramebufferParameterivEXT                          imgl3wProcs.gl.GetFramebufferParameterivEXT
#define glGetFramebufferParameterivMESA                         imgl3wProcs.gl.GetFramebufferParameterivMESA
#define glGetGraphicsResetStatus                                imgl3wProcs.gl.GetGraphicsResetStatus
#define glGetGraphicsResetStatusARB                             imgl3wProcs.gl.GetGraphicsResetStatusARB
#define glGetImageHandleARB                                     imgl3wProcs.gl.GetImageHandleARB
#define glGetImageHandleNV                                      imgl3wProcs.gl.GetImageHandleNV
#define glGetInteger64i_v                                       imgl3wProcs.gl.GetInteger64i_v
#define glGetInteger64v                                         imgl3wProcs.gl.GetInteger64v
#define glGetIntegerIndexedvEXT                                 imgl3wProcs.gl.GetIntegerIndexedvEXT
#define glGetIntegeri_v                                         imgl3wProcs.gl.GetIntegeri_v
#define glGetIntegerui64i_vNV                                   imgl3wProcs.gl.GetIntegerui64i_vNV
#define glGetIntegerui64vNV                                     imgl3wProcs.gl.GetIntegerui64vNV
#define glGetIntegerv                                           imgl3wProcs.gl.GetIntegerv
#define glGetInternalformatSampleivNV                           imgl3wProcs.gl.GetInternalformatSampleivNV
#define glGetInternalformati64v                                 imgl3wProcs.gl.GetInternalformati64v
#define glGetInternalformativ                                   imgl3wProcs.gl.GetInternalformativ
#define glGetMemoryObjectDetachedResourcesuivNV                 imgl3wProcs.gl.GetMemoryObjectDetachedResourcesuivNV
#define glGetMultiTexEnvfvEXT                                   imgl3wProcs.gl.GetMultiTexEnvfvEXT
#define glGetMultiTexEnvivEXT                                   imgl3wProcs.gl.GetMultiTexEnvivEXT
#define glGetMultiTexGendvEXT                                   imgl3wProcs.gl.GetMultiTexGendvEXT
#define glGetMultiTexGenfvEXT                                   imgl3wProcs.gl.GetMultiTexGenfvEXT
#define glGetMultiTexGenivEXT                                   imgl3wProcs.gl.GetMultiTexGenivEXT
#define glGetMultiTexImageEXT                                   imgl3wProcs.gl.GetMultiTexImageEXT
#define glGetMultiTexLevelParameterfvEXT                        imgl3wProcs.gl.GetMultiTexLevelParameterfvEXT
#define glGetMultiTexLevelParameterivEXT                        imgl3wProcs.gl.GetMultiTexLevelParameterivEXT
#define glGetMultiTexParameterIivEXT                            imgl3wProcs.gl.GetMultiTexParameterIivEXT
#define glGetMultiTexParameterIuivEXT                           imgl3wProcs.gl.GetMultiTexParameterIuivEXT
#define glGetMultiTexParameterfvEXT                             imgl3wProcs.gl.GetMultiTexParameterfvEXT
#define glGetMultiTexParameterivEXT                             imgl3wProcs.gl.GetMultiTexParameterivEXT
#define glGetMultisamplefv                                      imgl3wProcs.gl.GetMultisamplefv
#define glGetNamedBufferParameteri64v                           imgl3wProcs.gl.GetNamedBufferParameteri64v
#define glGetNamedBufferParameteriv                             imgl3wProcs.gl.GetNamedBufferParameteriv
#define glGetNamedBufferParameterivEXT                          imgl3wProcs.gl.GetNamedBufferParameterivEXT
#define glGetNamedBufferParameterui64vNV                        imgl3wProcs.gl.GetNamedBufferParameterui64vNV
#define glGetNamedBufferPointerv                                imgl3wProcs.gl.GetNamedBufferPointerv
#define glGetNamedBufferPointervEXT                             imgl3wProcs.gl.GetNamedBufferPointervEXT
#define glGetNamedBufferSubData                                 imgl3wProcs.gl.GetNamedBufferSubData
#define glGetNamedBufferSubDataEXT                              imgl3wProcs.gl.GetNamedBufferSubDataEXT
#define glGetNamedFramebufferAttachmentParameteriv              imgl3wProcs.gl.GetNamedFramebufferAttachmentParameteriv
#define glGetNamedFramebufferAttachmentParameterivEXT           imgl3wProcs.gl.GetNamedFramebufferAttachmentParameterivEXT
#define glGetNamedFramebufferParameteriv                        imgl3wProcs.gl.GetNamedFramebufferParameteriv
#define glGetNamedFramebufferParameterivEXT                     imgl3wProcs.gl.GetNamedFramebufferParameterivEXT
#define glGetNamedProgramLocalParameterIivEXT                   imgl3wProcs.gl.GetNamedProgramLocalParameterIivEXT
#define glGetNamedProgramLocalParameterIuivEXT                  imgl3wProcs.gl.GetNamedProgramLocalParameterIuivEXT
#define glGetNamedProgramLocalParameterdvEXT                    imgl3wProcs.gl.GetNamedProgramLocalParameterdvEXT
#define glGetNamedProgramLocalParameterfvEXT                    imgl3wProcs.gl.GetNamedProgramLocalParameterfvEXT
#define glGetNamedProgramStringEXT                              imgl3wProcs.gl.GetNamedProgramStringEXT
#define glGetNamedProgramivEXT                                  imgl3wProcs.gl.GetNamedProgramivEXT
#define glGetNamedRenderbufferParameteriv                       imgl3wProcs.gl.GetNamedRenderbufferParameteriv
#define glGetNamedRenderbufferParameterivEXT                    imgl3wProcs.gl.GetNamedRenderbufferParameterivEXT
#define glGetNamedStringARB                                     imgl3wProcs.gl.GetNamedStringARB
#define glGetNamedStringivARB                                   imgl3wProcs.gl.GetNamedStringivARB
#define glGetNextPerfQueryIdINTEL                               imgl3wProcs.gl.GetNextPerfQueryIdINTEL
#define glGetObjectLabel                                        imgl3wProcs.gl.GetObjectLabel
#define glGetObjectLabelEXT                                     imgl3wProcs.gl.GetObjectLabelEXT
#define glGetObjectPtrLabel                                     imgl3wProcs.gl.GetObjectPtrLabel
#define glGetPathCommandsNV                                     imgl3wProcs.gl.GetPathCommandsNV
#define glGetPathCoordsNV                                       imgl3wProcs.gl.GetPathCoordsNV
#define glGetPathDashArrayNV                                    imgl3wProcs.gl.GetPathDashArrayNV
#define glGetPathLengthNV                                       imgl3wProcs.gl.GetPathLengthNV
#define glGetPathMetricRangeNV                                  imgl3wProcs.gl.GetPathMetricRangeNV
#define glGetPathMetricsNV                                      imgl3wProcs.gl.GetPathMetricsNV
#define glGetPathParameterfvNV                                  imgl3wProcs.gl.GetPathParameterfvNV
#define glGetPathParameterivNV                                  imgl3wProcs.gl.GetPathParameterivNV
#define glGetPathSpacingNV                                      imgl3wProcs.gl.GetPathSpacingNV
#define glGetPerfCounterInfoINTEL                               imgl3wProcs.gl.GetPerfCounterInfoINTEL
#define glGetPerfMonitorCounterDataAMD                          imgl3wProcs.gl.GetPerfMonitorCounterDataAMD
#define glGetPerfMonitorCounterInfoAMD                          imgl3wProcs.gl.GetPerfMonitorCounterInfoAMD
#define glGetPerfMonitorCounterStringAMD                        imgl3wProcs.gl.GetPerfMonitorCounterStringAMD
#define glGetPerfMonitorCountersAMD                             imgl3wProcs.gl.GetPerfMonitorCountersAMD
#define glGetPerfMonitorGroupStringAMD                          imgl3wProcs.gl.GetPerfMonitorGroupStringAMD
#define glGetPerfMonitorGroupsAMD                               imgl3wProcs.gl.GetPerfMonitorGroupsAMD
#define glGetPerfQueryDataINTEL                                 imgl3wProcs.gl.GetPerfQueryDataINTEL
#define glGetPerfQueryIdByNameINTEL                             imgl3wProcs.gl.GetPerfQueryIdByNameINTEL
#define glGetPerfQueryInfoINTEL                                 imgl3wProcs.gl.GetPerfQueryInfoINTEL
#define glGetPointerIndexedvEXT                                 imgl3wProcs.gl.GetPointerIndexedvEXT
#define glGetPointeri_vEXT                                      imgl3wProcs.gl.GetPointeri_vEXT
#define glGetPointerv                                           imgl3wProcs.gl.GetPointerv
#define glGetProgramBinary                                      imgl3wProcs.gl.GetProgramBinary
#define glGetProgramInfoLog                                     imgl3wProcs.gl.GetProgramInfoLog
#define glGetProgramInterfaceiv                                 imgl3wProcs.gl.GetProgramInterfaceiv
#define glGetProgramPipelineInfoLog                             imgl3wProcs.gl.GetProgramPipelineInfoLog
#define glGetProgramPipelineiv                                  imgl3wProcs.gl.GetProgramPipelineiv
#define glGetProgramResourceIndex                               imgl3wProcs.gl.GetProgramResourceIndex
#define glGetProgramResourceLocation                            imgl3wProcs.gl.GetProgramResourceLocation
#define glGetProgramResourceLocationIndex                       imgl3wProcs.gl.GetProgramResourceLocationIndex
#define glGetProgramResourceName                                imgl3wProcs.gl.GetProgramResourceName
#define glGetProgramResourcefvNV                                imgl3wProcs.gl.GetProgramResourcefvNV
#define glGetProgramResourceiv                                  imgl3wProcs.gl.GetProgramResourceiv
#define glGetProgramStageiv                                     imgl3wProcs.gl.GetProgramStageiv
#define glGetProgramiv                                          imgl3wProcs.gl.GetProgramiv
#define glGetQueryBufferObjecti64v                              imgl3wProcs.gl.GetQueryBufferObjecti64v
#define glGetQueryBufferObjectiv                                imgl3wProcs.gl.GetQueryBufferObjectiv
#define glGetQueryBufferObjectui64v                             imgl3wProcs.gl.GetQueryBufferObjectui64v
#define glGetQueryBufferObjectuiv                               imgl3wProcs.gl.GetQueryBufferObjectuiv
#define glGetQueryIndexediv                                     imgl3wProcs.gl.GetQueryIndexediv
#define glGetQueryObjecti64v                                    imgl3wProcs.gl.GetQueryObjecti64v
#define glGetQueryObjectiv                                      imgl3wProcs.gl.GetQueryObjectiv
#define glGetQueryObjectui64v                                   imgl3wProcs.gl.GetQueryObjectui64v
#define glGetQueryObjectuiv                                     imgl3wProcs.gl.GetQueryObjectuiv
#define glGetQueryiv                                            imgl3wProcs.gl.GetQueryiv
#define glGetRenderbufferParameteriv                            imgl3wProcs.gl.GetRenderbufferParameteriv
#define glGetSamplerParameterIiv                                imgl3wProcs.gl.GetSamplerParameterIiv
#define glGetSamplerParameterIuiv                               imgl3wProcs.gl.GetSamplerParameterIuiv
#define glGetSamplerParameterfv                                 imgl3wProcs.gl.GetSamplerParameterfv
#define glGetSamplerParameteriv                                 imgl3wProcs.gl.GetSamplerParameteriv
#define glGetShaderInfoLog                                      imgl3wProcs.gl.GetShaderInfoLog
#define glGetShaderPrecisionFormat                              imgl3wProcs.gl.GetShaderPrecisionFormat
#define glGetShaderSource                                       imgl3wProcs.gl.GetShaderSource
#define glGetShaderiv                                           imgl3wProcs.gl.GetShaderiv
#define glGetShadingRateImagePaletteNV                          imgl3wProcs.gl.GetShadingRateImagePaletteNV
#define glGetShadingRateSampleLocationivNV                      imgl3wProcs.gl.GetShadingRateSampleLocationivNV
#define glGetStageIndexNV                                       imgl3wProcs.gl.GetStageIndexNV
#define glGetString                                             imgl3wProcs.gl.GetString
#define glGetStringi                                            imgl3wProcs.gl.GetStringi
#define glGetSubroutineIndex                                    imgl3wProcs.gl.GetSubroutineIndex
#define glGetSubroutineUniformLocation                          imgl3wProcs.gl.GetSubroutineUniformLocation
#define glGetSynciv                                             imgl3wProcs.gl.GetSynciv
#define glGetTexImage                                           imgl3wProcs.gl.GetTexImage
#define glGetTexLevelParameterfv                                imgl3wProcs.gl.GetTexLevelParameterfv
#define glGetTexLevelParameteriv                                imgl3wProcs.gl.GetTexLevelParameteriv
#define glGetTexParameterIiv                                    imgl3wProcs.gl.GetTexParameterIiv
#define glGetTexParameterIuiv                                   imgl3wProcs.gl.GetTexParameterIuiv
#define glGetTexParameterfv                                     imgl3wProcs.gl.GetTexParameterfv
#define glGetTexParameteriv                                     imgl3wProcs.gl.GetTexParameteriv
#define glGetTextureHandleARB                                   imgl3wProcs.gl.GetTextureHandleARB
#define glGetTextureHandleNV                                    imgl3wProcs.gl.GetTextureHandleNV
#define glGetTextureImage                                       imgl3wProcs.gl.GetTextureImage
#define glGetTextureImageEXT                                    imgl3wProcs.gl.GetTextureImageEXT
#define glGetTextureLevelParameterfv                            imgl3wProcs.gl.GetTextureLevelParameterfv
#define glGetTextureLevelParameterfvEXT                         imgl3wProcs.gl.GetTextureLevelParameterfvEXT
#define glGetTextureLevelParameteriv                            imgl3wProcs.gl.GetTextureLevelParameteriv
#define glGetTextureLevelParameterivEXT                         imgl3wProcs.gl.GetTextureLevelParameterivEXT
#define glGetTextureParameterIiv                                imgl3wProcs.gl.GetTextureParameterIiv
#define glGetTextureParameterIivEXT                             imgl3wProcs.gl.GetTextureParameterIivEXT
#define glGetTextureParameterIuiv                               imgl3wProcs.gl.GetTextureParameterIuiv
#define glGetTextureParameterIuivEXT                            imgl3wProcs.gl.GetTextureParameterIuivEXT
#define glGetTextureParameterfv                                 imgl3wProcs.gl.GetTextureParameterfv
#define glGetTextureParameterfvEXT                              imgl3wProcs.gl.GetTextureParameterfvEXT
#define glGetTextureParameteriv                                 imgl3wProcs.gl.GetTextureParameteriv
#define glGetTextureParameterivEXT                              imgl3wProcs.gl.GetTextureParameterivEXT
#define glGetTextureSamplerHandleARB                            imgl3wProcs.gl.GetTextureSamplerHandleARB
#define glGetTextureSamplerHandleNV                             imgl3wProcs.gl.GetTextureSamplerHandleNV
#define glGetTextureSubImage                                    imgl3wProcs.gl.GetTextureSubImage
#define glGetTransformFeedbackVarying                           imgl3wProcs.gl.GetTransformFeedbackVarying
#define glGetTransformFeedbacki64_v                             imgl3wProcs.gl.GetTransformFeedbacki64_v
#define glGetTransformFeedbacki_v                               imgl3wProcs.gl.GetTransformFeedbacki_v
#define glGetTransformFeedbackiv                                imgl3wProcs.gl.GetTransformFeedbackiv
#define glGetUniformBlockIndex                                  imgl3wProcs.gl.GetUniformBlockIndex
#define glGetUniformIndices                                     imgl3wProcs.gl.GetUniformIndices
#define glGetUniformLocation                                    imgl3wProcs.gl.GetUniformLocation
#define glGetUniformSubroutineuiv                               imgl3wProcs.gl.GetUniformSubroutineuiv
#define glGetUniformdv                                          imgl3wProcs.gl.GetUniformdv
#define glGetUniformfv                                          imgl3wProcs.gl.GetUniformfv
#define glGetUniformi64vARB                                     imgl3wProcs.gl.GetUniformi64vARB
#define glGetUniformi64vNV                                      imgl3wProcs.gl.GetUniformi64vNV
#define glGetUniformiv                                          imgl3wProcs.gl.GetUniformiv
#define glGetUniformui64vARB                                    imgl3wProcs.gl.GetUniformui64vARB
#define glGetUniformui64vNV                                     imgl3wProcs.gl.GetUniformui64vNV
#define glGetUniformuiv                                         imgl3wProcs.gl.GetUniformuiv
#define glGetVertexArrayIndexed64iv                             imgl3wProcs.gl.GetVertexArrayIndexed64iv
#define glGetVertexArrayIndexediv                               imgl3wProcs.gl.GetVertexArrayIndexediv
#define glGetVertexArrayIntegeri_vEXT                           imgl3wProcs.gl.GetVertexArrayIntegeri_vEXT
#define glGetVertexArrayIntegervEXT                             imgl3wProcs.gl.GetVertexArrayIntegervEXT
#define glGetVertexArrayPointeri_vEXT                           imgl3wProcs.gl.GetVertexArrayPointeri_vEXT
#define glGetVertexArrayPointervEXT                             imgl3wProcs.gl.GetVertexArrayPointervEXT
#define glGetVertexArrayiv                                      imgl3wProcs.gl.GetVertexArrayiv
#define glGetVertexAttribIiv                                    imgl3wProcs.gl.GetVertexAttribIiv
#define glGetVertexAttribIuiv                                   imgl3wProcs.gl.GetVertexAttribIuiv
#define glGetVertexAttribLdv                                    imgl3wProcs.gl.GetVertexAttribLdv
#define glGetVertexAttribLi64vNV                                imgl3wProcs.gl.GetVertexAttribLi64vNV
#define glGetVertexAttribLui64vARB                              imgl3wProcs.gl.GetVertexAttribLui64vARB
#define glGetVertexAttribLui64vNV                               imgl3wProcs.gl.GetVertexAttribLui64vNV
#define glGetVertexAttribPointerv                               imgl3wProcs.gl.GetVertexAttribPointerv
#define glGetVertexAttribdv                                     imgl3wProcs.gl.GetVertexAttribdv
#define glGetVertexAttribfv                                     imgl3wProcs.gl.GetVertexAttribfv
#define glGetVertexAttribiv                                     imgl3wProcs.gl.GetVertexAttribiv
#define glGetVkProcAddrNV                                       imgl3wProcs.gl.GetVkProcAddrNV
#define glGetnCompressedTexImage                                imgl3wProcs.gl.GetnCompressedTexImage
#define glGetnCompressedTexImageARB                             imgl3wProcs.gl.GetnCompressedTexImageARB
#define glGetnTexImage                                          imgl3wProcs.gl.GetnTexImage
#define glGetnTexImageARB                                       imgl3wProcs.gl.GetnTexImageARB
#define glGetnUniformdv                                         imgl3wProcs.gl.GetnUniformdv
#define glGetnUniformdvARB                                      imgl3wProcs.gl.GetnUniformdvARB
#define glGetnUniformfv                                         imgl3wProcs.gl.GetnUniformfv
#define glGetnUniformfvARB                                      imgl3wProcs.gl.GetnUniformfvARB
#define glGetnUniformi64vARB                                    imgl3wProcs.gl.GetnUniformi64vARB
#define glGetnUniformiv                                         imgl3wProcs.gl.GetnUniformiv
#define glGetnUniformivARB                                      imgl3wProcs.gl.GetnUniformivARB
#define glGetnUniformui64vARB                                   imgl3wProcs.gl.GetnUniformui64vARB
#define glGetnUniformuiv                                        imgl3wProcs.gl.GetnUniformuiv
#define glGetnUniformuivARB                                     imgl3wProcs.gl.GetnUniformuivARB
#define glHint                                                  imgl3wProcs.gl.Hint
#define glIndexFormatNV                                         imgl3wProcs.gl.IndexFormatNV
#define glInsertEventMarkerEXT                                  imgl3wProcs.gl.InsertEventMarkerEXT
#define glInterpolatePathsNV                                    imgl3wProcs.gl.InterpolatePathsNV
#define glInvalidateBufferData                                  imgl3wProcs.gl.InvalidateBufferData
#define glInvalidateBufferSubData                               imgl3wProcs.gl.InvalidateBufferSubData
#define glInvalidateFramebuffer                                 imgl3wProcs.gl.InvalidateFramebuffer
#define glInvalidateNamedFramebufferData                        imgl3wProcs.gl.InvalidateNamedFramebufferData
#define glInvalidateNamedFramebufferSubData                     imgl3wProcs.gl.InvalidateNamedFramebufferSubData
#define glInvalidateSubFramebuffer                              imgl3wProcs.gl.InvalidateSubFramebuffer
#define glInvalidateTexImage                                    imgl3wProcs.gl.InvalidateTexImage
#define glInvalidateTexSubImage                                 imgl3wProcs.gl.InvalidateTexSubImage
#define glIsBuffer                                              imgl3wProcs.gl.IsBuffer
#define glIsBufferResidentNV                                    imgl3wProcs.gl.IsBufferResidentNV
#define glIsCommandListNV                                       imgl3wProcs.gl.IsCommandListNV
#define glIsEnabled                                             imgl3wProcs.gl.IsEnabled
#define glIsEnabledIndexedEXT                                   imgl3wProcs.gl.IsEnabledIndexedEXT
#define glIsEnabledi                                            imgl3wProcs.gl.IsEnabledi
#define glIsFramebuffer                                         imgl3wProcs.gl.IsFramebuffer
#define glIsImageHandleResidentARB                              imgl3wProcs.gl.IsImageHandleResidentARB
#define glIsImageHandleResidentNV                               imgl3wProcs.gl.IsImageHandleResidentNV
#define glIsNamedBufferResidentNV                               imgl3wProcs.gl.IsNamedBufferResidentNV
#define glIsNamedStringARB                                      imgl3wProcs.gl.IsNamedStringARB
#define glIsPathNV                                              imgl3wProcs.gl.IsPathNV
#define glIsPointInFillPathNV                                   imgl3wProcs.gl.IsPointInFillPathNV
#define glIsPointInStrokePathNV                                 imgl3wProcs.gl.IsPointInStrokePathNV
#define glIsProgram                                             imgl3wProcs.gl.IsProgram
#define glIsProgramPipeline                                     imgl3wProcs.gl.IsProgramPipeline
#define glIsQuery                                               imgl3wProcs.gl.IsQuery
#define glIsRenderbuffer                                        imgl3wProcs.gl.IsRenderbuffer
#define glIsSampler                                             imgl3wProcs.gl.IsSampler
#define glIsShader                                              imgl3wProcs.gl.IsShader
#define glIsStateNV                                             imgl3wProcs.gl.IsStateNV
#define glIsSync                                                imgl3wProcs.gl.IsSync
#define glIsTexture                                             imgl3wProcs.gl.IsTexture
#define glIsTextureHandleResidentARB                            imgl3wProcs.gl.IsTextureHandleResidentARB
#define glIsTextureHandleResidentNV                             imgl3wProcs.gl.IsTextureHandleResidentNV
#define glIsTransformFeedback                                   imgl3wProcs.gl.IsTransformFeedback
#define glIsVertexArray                                         imgl3wProcs.gl.IsVertexArray
#define glLabelObjectEXT                                        imgl3wProcs.gl.LabelObjectEXT
#define glLineWidth                                             imgl3wProcs.gl.LineWidth
#define glLinkProgram                                           imgl3wProcs.gl.LinkProgram
#define glListDrawCommandsStatesClientNV                        imgl3wProcs.gl.ListDrawCommandsStatesClientNV
#define glLogicOp                                               imgl3wProcs.gl.LogicOp
#define glMakeBufferNonResidentNV                               imgl3wProcs.gl.MakeBufferNonResidentNV
#define glMakeBufferResidentNV                                  imgl3wProcs.gl.MakeBufferResidentNV
#define glMakeImageHandleNonResidentARB                         imgl3wProcs.gl.MakeImageHandleNonResidentARB
#define glMakeImageHandleNonResidentNV                          imgl3wProcs.gl.MakeImageHandleNonResidentNV
#define glMakeImageHandleResidentARB                            imgl3wProcs.gl.MakeImageHandleResidentARB
#define glMakeImageHandleResidentNV                             imgl3wProcs.gl.MakeImageHandleResidentNV
#define glMakeNamedBufferNonResidentNV                          imgl3wProcs.gl.MakeNamedBufferNonResidentNV
#define glMakeNamedBufferResidentNV                             imgl3wProcs.gl.MakeNamedBufferResidentNV
#define glMakeTextureHandleNonResidentARB                       imgl3wProcs.gl.MakeTextureHandleNonResidentARB
#define glMakeTextureHandleNonResidentNV                        imgl3wProcs.gl.MakeTextureHandleNonResidentNV
#define glMakeTextureHandleResidentARB                          imgl3wProcs.gl.MakeTextureHandleResidentARB
#define glMakeTextureHandleResidentNV                           imgl3wProcs.gl.MakeTextureHandleResidentNV
#define glMapBuffer                                             imgl3wProcs.gl.MapBuffer
#define glMapBufferRange                                        imgl3wProcs.gl.MapBufferRange
#define glMapNamedBuffer                                        imgl3wProcs.gl.MapNamedBuffer
#define glMapNamedBufferEXT                                     imgl3wProcs.gl.MapNamedBufferEXT
#define glMapNamedBufferRange                                   imgl3wProcs.gl.MapNamedBufferRange
#define glMapNamedBufferRangeEXT                                imgl3wProcs.gl.MapNamedBufferRangeEXT
#define glMatrixFrustumEXT                                      imgl3wProcs.gl.MatrixFrustumEXT
#define glMatrixLoad3x2fNV                                      imgl3wProcs.gl.MatrixLoad3x2fNV
#define glMatrixLoad3x3fNV                                      imgl3wProcs.gl.MatrixLoad3x3fNV
#define glMatrixLoadIdentityEXT                                 imgl3wProcs.gl.MatrixLoadIdentityEXT
#define glMatrixLoadTranspose3x3fNV                             imgl3wProcs.gl.MatrixLoadTranspose3x3fNV
#define glMatrixLoadTransposedEXT                               imgl3wProcs.gl.MatrixLoadTransposedEXT
#define glMatrixLoadTransposefEXT                               imgl3wProcs.gl.MatrixLoadTransposefEXT
#define glMatrixLoaddEXT                                        imgl3wProcs.gl.MatrixLoaddEXT
#define glMatrixLoadfEXT                                        imgl3wProcs.gl.MatrixLoadfEXT
#define glMatrixMult3x2fNV                                      imgl3wProcs.gl.MatrixMult3x2fNV
#define glMatrixMult3x3fNV                                      imgl3wProcs.gl.MatrixMult3x3fNV
#define glMatrixMultTranspose3x3fNV                             imgl3wProcs.gl.MatrixMultTranspose3x3fNV
#define glMatrixMultTransposedEXT                               imgl3wProcs.gl.MatrixMultTransposedEXT
#define glMatrixMultTransposefEXT                               imgl3wProcs.gl.MatrixMultTransposefEXT
#define glMatrixMultdEXT                                        imgl3wProcs.gl.MatrixMultdEXT
#define glMatrixMultfEXT                                        imgl3wProcs.gl.MatrixMultfEXT
#define glMatrixOrthoEXT                                        imgl3wProcs.gl.MatrixOrthoEXT
#define glMatrixPopEXT                                          imgl3wProcs.gl.MatrixPopEXT
#define glMatrixPushEXT                                         imgl3wProcs.gl.MatrixPushEXT
#define glMatrixRotatedEXT                                      imgl3wProcs.gl.MatrixRotatedEXT
#define glMatrixRotatefEXT                                      imgl3wProcs.gl.MatrixRotatefEXT
#define glMatrixScaledEXT                                       imgl3wProcs.gl.MatrixScaledEXT
#define glMatrixScalefEXT                                       imgl3wProcs.gl.MatrixScalefEXT
#define glMatrixTranslatedEXT                                   imgl3wProcs.gl.MatrixTranslatedEXT
#define glMatrixTranslatefEXT                                   imgl3wProcs.gl.MatrixTranslatefEXT
#define glMaxShaderCompilerThreadsARB                           imgl3wProcs.gl.MaxShaderCompilerThreadsARB
#define glMaxShaderCompilerThreadsKHR                           imgl3wProcs.gl.MaxShaderCompilerThreadsKHR
#define glMemoryBarrier                                         imgl3wProcs.gl.MemoryBarrier
#define glMemoryBarrierByRegion                                 imgl3wProcs.gl.MemoryBarrierByRegion
#define glMinSampleShading                                      imgl3wProcs.gl.MinSampleShading
#define glMinSampleShadingARB                                   imgl3wProcs.gl.MinSampleShadingARB
#define glMultiDrawArrays                                       imgl3wProcs.gl.MultiDrawArrays
#define glMultiDrawArraysIndirect                               imgl3wProcs.gl.MultiDrawArraysIndirect
#define glMultiDrawArraysIndirectBindlessCountNV                imgl3wProcs.gl.MultiDrawArraysIndirectBindlessCountNV
#define glMultiDrawArraysIndirectBindlessNV                     imgl3wProcs.gl.MultiDrawArraysIndirectBindlessNV
#define glMultiDrawArraysIndirectCount                          imgl3wProcs.gl.MultiDrawArraysIndirectCount
#define glMultiDrawArraysIndirectCountARB                       imgl3wProcs.gl.MultiDrawArraysIndirectCountARB
#define glMultiDrawElements                                     imgl3wProcs.gl.MultiDrawElements
#define glMultiDrawElementsBaseVertex                           imgl3wProcs.gl.MultiDrawElementsBaseVertex
#define glMultiDrawElementsIndirect                             imgl3wProcs.gl.MultiDrawElementsIndirect
#define glMultiDrawElementsIndirectBindlessCountNV              imgl3wProcs.gl.MultiDrawElementsIndirectBindlessCountNV
#define glMultiDrawElementsIndirectBindlessNV                   imgl3wProcs.gl.MultiDrawElementsIndirectBindlessNV
#define glMultiDrawElementsIndirectCount                        imgl3wProcs.gl.MultiDrawElementsIndirectCount
#define glMultiDrawElementsIndirectCountARB                     imgl3wProcs.gl.MultiDrawElementsIndirectCountARB
#define glMultiDrawMeshTasksIndirectCountNV                     imgl3wProcs.gl.MultiDrawMeshTasksIndirectCountNV
#define glMultiDrawMeshTasksIndirectNV                          imgl3wProcs.gl.MultiDrawMeshTasksIndirectNV
#define glMultiTexBufferEXT                                     imgl3wProcs.gl.MultiTexBufferEXT
#define glMultiTexCoordPointerEXT                               imgl3wProcs.gl.MultiTexCoordPointerEXT
#define glMultiTexEnvfEXT                                       imgl3wProcs.gl.MultiTexEnvfEXT
#define glMultiTexEnvfvEXT                                      imgl3wProcs.gl.MultiTexEnvfvEXT
#define glMultiTexEnviEXT                                       imgl3wProcs.gl.MultiTexEnviEXT
#define glMultiTexEnvivEXT                                      imgl3wProcs.gl.MultiTexEnvivEXT
#define glMultiTexGendEXT                                       imgl3wProcs.gl.MultiTexGendEXT
#define glMultiTexGendvEXT                                      imgl3wProcs.gl.MultiTexGendvEXT
#define glMultiTexGenfEXT                                       imgl3wProcs.gl.MultiTexGenfEXT
#define glMultiTexGenfvEXT                                      imgl3wProcs.gl.MultiTexGenfvEXT
#define glMultiTexGeniEXT                                       imgl3wProcs.gl.MultiTexGeniEXT
#define glMultiTexGenivEXT                                      imgl3wProcs.gl.MultiTexGenivEXT
#define glMultiTexImage1DEXT                                    imgl3wProcs.gl.MultiTexImage1DEXT
#define glMultiTexImage2DEXT                                    imgl3wProcs.gl.MultiTexImage2DEXT
#define glMultiTexImage3DEXT                                    imgl3wProcs.gl.MultiTexImage3DEXT
#define glMultiTexParameterIivEXT                               imgl3wProcs.gl.MultiTexParameterIivEXT
#define glMultiTexParameterIuivEXT                              imgl3wProcs.gl.MultiTexParameterIuivEXT
#define glMultiTexParameterfEXT                                 imgl3wProcs.gl.MultiTexParameterfEXT
#define glMultiTexParameterfvEXT                                imgl3wProcs.gl.MultiTexParameterfvEXT
#define glMultiTexParameteriEXT                                 imgl3wProcs.gl.MultiTexParameteriEXT
#define glMultiTexParameterivEXT                                imgl3wProcs.gl.MultiTexParameterivEXT
#define glMultiTexRenderbufferEXT                               imgl3wProcs.gl.MultiTexRenderbufferEXT
#define glMultiTexSubImage1DEXT                                 imgl3wProcs.gl.MultiTexSubImage1DEXT
#define glMultiTexSubImage2DEXT                                 imgl3wProcs.gl.MultiTexSubImage2DEXT
#define glMultiTexSubImage3DEXT                                 imgl3wProcs.gl.MultiTexSubImage3DEXT
#define glNamedBufferAttachMemoryNV                             imgl3wProcs.gl.NamedBufferAttachMemoryNV
#define glNamedBufferData                                       imgl3wProcs.gl.NamedBufferData
#define glNamedBufferDataEXT                                    imgl3wProcs.gl.NamedBufferDataEXT
#define glNamedBufferPageCommitmentARB                          imgl3wProcs.gl.NamedBufferPageCommitmentARB
#define glNamedBufferPageCommitmentEXT                          imgl3wProcs.gl.NamedBufferPageCommitmentEXT
#define glNamedBufferPageCommitmentMemNV                        imgl3wProcs.gl.NamedBufferPageCommitmentMemNV
#define glNamedBufferStorage                                    imgl3wProcs.gl.NamedBufferStorage
#define glNamedBufferStorageEXT                                 imgl3wProcs.gl.NamedBufferStorageEXT
#define glNamedBufferSubData                                    imgl3wProcs.gl.NamedBufferSubData
#define glNamedBufferSubDataEXT                                 imgl3wProcs.gl.NamedBufferSubDataEXT
#define glNamedCopyBufferSubDataEXT                             imgl3wProcs.gl.NamedCopyBufferSubDataEXT
#define glNamedFramebufferDrawBuffer                            imgl3wProcs.gl.NamedFramebufferDrawBuffer
#define glNamedFramebufferDrawBuffers                           imgl3wProcs.gl.NamedFramebufferDrawBuffers
#define glNamedFramebufferParameteri                            imgl3wProcs.gl.NamedFramebufferParameteri
#define glNamedFramebufferParameteriEXT                         imgl3wProcs.gl.NamedFramebufferParameteriEXT
#define glNamedFramebufferReadBuffer                            imgl3wProcs.gl.NamedFramebufferReadBuffer
#define glNamedFramebufferRenderbuffer                          imgl3wProcs.gl.NamedFramebufferRenderbuffer
#define glNamedFramebufferRenderbufferEXT                       imgl3wProcs.gl.NamedFramebufferRenderbufferEXT
#define glNamedFramebufferSampleLocationsfvARB                  imgl3wProcs.gl.NamedFramebufferSampleLocationsfvARB
#define glNamedFramebufferSampleLocationsfvNV                   imgl3wProcs.gl.NamedFramebufferSampleLocationsfvNV
#define glNamedFramebufferTexture                               imgl3wProcs.gl.NamedFramebufferTexture
#define glNamedFramebufferTexture1DEXT                          imgl3wProcs.gl.NamedFramebufferTexture1DEXT
#define glNamedFramebufferTexture2DEXT                          imgl3wProcs.gl.NamedFramebufferTexture2DEXT
#define glNamedFramebufferTexture3DEXT                          imgl3wProcs.gl.NamedFramebufferTexture3DEXT
#define glNamedFramebufferTextureEXT                            imgl3wProcs.gl.NamedFramebufferTextureEXT
#define glNamedFramebufferTextureFaceEXT                        imgl3wProcs.gl.NamedFramebufferTextureFaceEXT
#define glNamedFramebufferTextureLayer                          imgl3wProcs.gl.NamedFramebufferTextureLayer
#define glNamedFramebufferTextureLayerEXT                       imgl3wProcs.gl.NamedFramebufferTextureLayerEXT
#define glNamedFramebufferTextureMultiviewOVR                   imgl3wProcs.gl.NamedFramebufferTextureMultiviewOVR
#define glNamedProgramLocalParameter4dEXT                       imgl3wProcs.gl.NamedProgramLocalParameter4dEXT
#define glNamedProgramLocalParameter4dvEXT                      imgl3wProcs.gl.NamedProgramLocalParameter4dvEXT
#define glNamedProgramLocalParameter4fEXT                       imgl3wProcs.gl.NamedProgramLocalParameter4fEXT
#define glNamedProgramLocalParameter4fvEXT                      imgl3wProcs.gl.NamedProgramLocalParameter4fvEXT
#define glNamedProgramLocalParameterI4iEXT                      imgl3wProcs.gl.NamedProgramLocalParameterI4iEXT
#define glNamedProgramLocalParameterI4ivEXT                     imgl3wProcs.gl.NamedProgramLocalParameterI4ivEXT
#define glNamedProgramLocalParameterI4uiEXT                     imgl3wProcs.gl.NamedProgramLocalParameterI4uiEXT
#define glNamedProgramLocalParameterI4uivEXT                    imgl3wProcs.gl.NamedProgramLocalParameterI4uivEXT
#define glNamedProgramLocalParameters4fvEXT                     imgl3wProcs.gl.NamedProgramLocalParameters4fvEXT
#define glNamedProgramLocalParametersI4ivEXT                    imgl3wProcs.gl.NamedProgramLocalParametersI4ivEXT
#define glNamedProgramLocalParametersI4uivEXT                   imgl3wProcs.gl.NamedProgramLocalParametersI4uivEXT
#define glNamedProgramStringEXT                                 imgl3wProcs.gl.NamedProgramStringEXT
#define glNamedRenderbufferStorage                              imgl3wProcs.gl.NamedRenderbufferStorage
#define glNamedRenderbufferStorageEXT                           imgl3wProcs.gl.NamedRenderbufferStorageEXT
#define glNamedRenderbufferStorageMultisample                   imgl3wProcs.gl.NamedRenderbufferStorageMultisample
#define glNamedRenderbufferStorageMultisampleAdvancedAMD        imgl3wProcs.gl.NamedRenderbufferStorageMultisampleAdvancedAMD
#define glNamedRenderbufferStorageMultisampleCoverageEXT        imgl3wProcs.gl.NamedRenderbufferStorageMultisampleCoverageEXT
#define glNamedRenderbufferStorageMultisampleEXT                imgl3wProcs.gl.NamedRenderbufferStorageMultisampleEXT
#define glNamedStringARB                                        imgl3wProcs.gl.NamedStringARB
#define glNormalFormatNV                                        imgl3wProcs.gl.NormalFormatNV
#define glObjectLabel                                           imgl3wProcs.gl.ObjectLabel
#define glObjectPtrLabel                                        imgl3wProcs.gl.ObjectPtrLabel
#define glPatchParameterfv                                      imgl3wProcs.gl.PatchParameterfv
#define glPatchParameteri                                       imgl3wProcs.gl.PatchParameteri
#define glPathCommandsNV                                        imgl3wProcs.gl.PathCommandsNV
#define glPathCoordsNV                                          imgl3wProcs.gl.PathCoordsNV
#define glPathCoverDepthFuncNV                                  imgl3wProcs.gl.PathCoverDepthFuncNV
#define glPathDashArrayNV                                       imgl3wProcs.gl.PathDashArrayNV
#define glPathGlyphIndexArrayNV                                 imgl3wProcs.gl.PathGlyphIndexArrayNV
#define glPathGlyphIndexRangeNV                                 imgl3wProcs.gl.PathGlyphIndexRangeNV
#define glPathGlyphRangeNV                                      imgl3wProcs.gl.PathGlyphRangeNV
#define glPathGlyphsNV                                          imgl3wProcs.gl.PathGlyphsNV
#define glPathMemoryGlyphIndexArrayNV                           imgl3wProcs.gl.PathMemoryGlyphIndexArrayNV
#define glPathParameterfNV                                      imgl3wProcs.gl.PathParameterfNV
#define glPathParameterfvNV                                     imgl3wProcs.gl.PathParameterfvNV
#define glPathParameteriNV                                      imgl3wProcs.gl.PathParameteriNV
#define glPathParameterivNV                                     imgl3wProcs.gl.PathParameterivNV
#define glPathStencilDepthOffsetNV                              imgl3wProcs.gl.PathStencilDepthOffsetNV
#define glPathStencilFuncNV                                     imgl3wProcs.gl.PathStencilFuncNV
#define glPathStringNV                                          imgl3wProcs.gl.PathStringNV
#define glPathSubCommandsNV                                     imgl3wProcs.gl.PathSubCommandsNV
#define glPathSubCoordsNV                                       imgl3wProcs.gl.PathSubCoordsNV
#define glPauseTransformFeedback                                imgl3wProcs.gl.PauseTransformFeedback
#define glPixelStoref                                           imgl3wProcs.gl.PixelStoref
#define glPixelStorei                                           imgl3wProcs.gl.PixelStorei
#define glPointAlongPathNV                                      imgl3wProcs.gl.PointAlongPathNV
#define glPointParameterf                                       imgl3wProcs.gl.PointParameterf
#define glPointParameterfv                                      imgl3wProcs.gl.PointParameterfv
#define glPointParameteri                                       imgl3wProcs.gl.PointParameteri
#define glPointParameteriv                                      imgl3wProcs.gl.PointParameteriv
#define glPointSize                                             imgl3wProcs.gl.PointSize
#define glPolygonMode                                           imgl3wProcs.gl.PolygonMode
#define glPolygonOffset                                         imgl3wProcs.gl.PolygonOffset
#define glPolygonOffsetClamp                                    imgl3wProcs.gl.PolygonOffsetClamp
#define glPolygonOffsetClampEXT                                 imgl3wProcs.gl.PolygonOffsetClampEXT
#define glPopDebugGroup                                         imgl3wProcs.gl.PopDebugGroup
#define glPopGroupMarkerEXT                                     imgl3wProcs.gl.PopGroupMarkerEXT
#define glPrimitiveBoundingBoxARB                               imgl3wProcs.gl.PrimitiveBoundingBoxARB
#define glPrimitiveRestartIndex                                 imgl3wProcs.gl.PrimitiveRestartIndex
#define glProgramBinary                                         imgl3wProcs.gl.ProgramBinary
#define glProgramParameteri                                     imgl3wProcs.gl.ProgramParameteri
#define glProgramParameteriARB                                  imgl3wProcs.gl.ProgramParameteriARB
#define glProgramPathFragmentInputGenNV                         imgl3wProcs.gl.ProgramPathFragmentInputGenNV
#define glProgramUniform1d                                      imgl3wProcs.gl.ProgramUniform1d
#define glProgramUniform1dEXT                                   imgl3wProcs.gl.ProgramUniform1dEXT
#define glProgramUniform1dv                                     imgl3wProcs.gl.ProgramUniform1dv
#define glProgramUniform1dvEXT                                  imgl3wProcs.gl.ProgramUniform1dvEXT
#define glProgramUniform1f                                      imgl3wProcs.gl.ProgramUniform1f
#define glProgramUniform1fEXT                                   imgl3wProcs.gl.ProgramUniform1fEXT
#define glProgramUniform1fv                                     imgl3wProcs.gl.ProgramUniform1fv
#define glProgramUniform1fvEXT                                  imgl3wProcs.gl.ProgramUniform1fvEXT
#define glProgramUniform1i                                      imgl3wProcs.gl.ProgramUniform1i
#define glProgramUniform1i64ARB                                 imgl3wProcs.gl.ProgramUniform1i64ARB
#define glProgramUniform1i64NV                                  imgl3wProcs.gl.ProgramUniform1i64NV
#define glProgramUniform1i64vARB                                imgl3wProcs.gl.ProgramUniform1i64vARB
#define glProgramUniform1i64vNV                                 imgl3wProcs.gl.ProgramUniform1i64vNV
#define glProgramUniform1iEXT                                   imgl3wProcs.gl.ProgramUniform1iEXT
#define glProgramUniform1iv                                     imgl3wProcs.gl.ProgramUniform1iv
#define glProgramUniform1ivEXT                                  imgl3wProcs.gl.ProgramUniform1ivEXT
#define glProgramUniform1ui                                     imgl3wProcs.gl.ProgramUniform1ui
#define glProgramUniform1ui64ARB                                imgl3wProcs.gl.ProgramUniform1ui64ARB
#define glProgramUniform1ui64NV                                 imgl3wProcs.gl.ProgramUniform1ui64NV
#define glProgramUniform1ui64vARB                               imgl3wProcs.gl.ProgramUniform1ui64vARB
#define glProgramUniform1ui64vNV                                imgl3wProcs.gl.ProgramUniform1ui64vNV
#define glProgramUniform1uiEXT                                  imgl3wProcs.gl.ProgramUniform1uiEXT
#define glProgramUniform1uiv                                    imgl3wProcs.gl.ProgramUniform1uiv
#define glProgramUniform1uivEXT                                 imgl3wProcs.gl.ProgramUniform1uivEXT
#define glProgramUniform2d                                      imgl3wProcs.gl.ProgramUniform2d
#define glProgramUniform2dEXT                                   imgl3wProcs.gl.ProgramUniform2dEXT
#define glProgramUniform2dv                                     imgl3wProcs.gl.ProgramUniform2dv
#define glProgramUniform2dvEXT                                  imgl3wProcs.gl.ProgramUniform2dvEXT
#define glProgramUniform2f                                      imgl3wProcs.gl.ProgramUniform2f
#define glProgramUniform2fEXT                                   imgl3wProcs.gl.ProgramUniform2fEXT
#define glProgramUniform2fv                                     imgl3wProcs.gl.ProgramUniform2fv
#define glProgramUniform2fvEXT                                  imgl3wProcs.gl.ProgramUniform2fvEXT
#define glProgramUniform2i                                      imgl3wProcs.gl.ProgramUniform2i
#define glProgramUniform2i64ARB                                 imgl3wProcs.gl.ProgramUniform2i64ARB
#define glProgramUniform2i64NV                                  imgl3wProcs.gl.ProgramUniform2i64NV
#define glProgramUniform2i64vARB                                imgl3wProcs.gl.ProgramUniform2i64vARB
#define glProgramUniform2i64vNV                                 imgl3wProcs.gl.ProgramUniform2i64vNV
#define glProgramUniform2iEXT                                   imgl3wProcs.gl.ProgramUniform2iEXT
#define glProgramUniform2iv                                     imgl3wProcs.gl.ProgramUniform2iv
#define glProgramUniform2ivEXT                                  imgl3wProcs.gl.ProgramUniform2ivEXT
#define glProgramUniform2ui                                     imgl3wProcs.gl.ProgramUniform2ui
#define glProgramUniform2ui64ARB                                imgl3wProcs.gl.ProgramUniform2ui64ARB
#define glProgramUniform2ui64NV                                 imgl3wProcs.gl.ProgramUniform2ui64NV
#define glProgramUniform2ui64vARB                               imgl3wProcs.gl.ProgramUniform2ui64vARB
#define glProgramUniform2ui64vNV                                imgl3wProcs.gl.ProgramUniform2ui64vNV
#define glProgramUniform2uiEXT                                  imgl3wProcs.gl.ProgramUniform2uiEXT
#define glProgramUniform2uiv                                    imgl3wProcs.gl.ProgramUniform2uiv
#define glProgramUniform2uivEXT                                 imgl3wProcs.gl.ProgramUniform2uivEXT
#define glProgramUniform3d                                      imgl3wProcs.gl.ProgramUniform3d
#define glProgramUniform3dEXT                                   imgl3wProcs.gl.ProgramUniform3dEXT
#define glProgramUniform3dv                                     imgl3wProcs.gl.ProgramUniform3dv
#define glProgramUniform3dvEXT                                  imgl3wProcs.gl.ProgramUniform3dvEXT
#define glProgramUniform3f                                      imgl3wProcs.gl.ProgramUniform3f
#define glProgramUniform3fEXT                                   imgl3wProcs.gl.ProgramUniform3fEXT
#define glProgramUniform3fv                                     imgl3wProcs.gl.ProgramUniform3fv
#define glProgramUniform3fvEXT                                  imgl3wProcs.gl.ProgramUniform3fvEXT
#define glProgramUniform3i                                      imgl3wProcs.gl.ProgramUniform3i
#define glProgramUniform3i64ARB                                 imgl3wProcs.gl.ProgramUniform3i64ARB
#define glProgramUniform3i64NV                                  imgl3wProcs.gl.ProgramUniform3i64NV
#define glProgramUniform3i64vARB                                imgl3wProcs.gl.ProgramUniform3i64vARB
#define glProgramUniform3i64vNV                                 imgl3wProcs.gl.ProgramUniform3i64vNV
#define glProgramUniform3iEXT                                   imgl3wProcs.gl.ProgramUniform3iEXT
#define glProgramUniform3iv                                     imgl3wProcs.gl.ProgramUniform3iv
#define glProgramUniform3ivEXT                                  imgl3wProcs.gl.ProgramUniform3ivEXT
#define glProgramUniform3ui                                     imgl3wProcs.gl.ProgramUniform3ui
#define glProgramUniform3ui64ARB                                imgl3wProcs.gl.ProgramUniform3ui64ARB
#define glProgramUniform3ui64NV                                 imgl3wProcs.gl.ProgramUniform3ui64NV
#define glProgramUniform3ui64vARB                               imgl3wProcs.gl.ProgramUniform3ui64vARB
#define glProgramUniform3ui64vNV                                imgl3wProcs.gl.ProgramUniform3ui64vNV
#define glProgramUniform3uiEXT                                  imgl3wProcs.gl.ProgramUniform3uiEXT
#define glProgramUniform3uiv                                    imgl3wProcs.gl.ProgramUniform3uiv
#define glProgramUniform3uivEXT                                 imgl3wProcs.gl.ProgramUniform3uivEXT
#define glProgramUniform4d                                      imgl3wProcs.gl.ProgramUniform4d
#define glProgramUniform4dEXT                                   imgl3wProcs.gl.ProgramUniform4dEXT
#define glProgramUniform4dv                                     imgl3wProcs.gl.ProgramUniform4dv
#define glProgramUniform4dvEXT                                  imgl3wProcs.gl.ProgramUniform4dvEXT
#define glProgramUniform4f                                      imgl3wProcs.gl.ProgramUniform4f
#define glProgramUniform4fEXT                                   imgl3wProcs.gl.ProgramUniform4fEXT
#define glProgramUniform4fv                                     imgl3wProcs.gl.ProgramUniform4fv
#define glProgramUniform4fvEXT                                  imgl3wProcs.gl.ProgramUniform4fvEXT
#define glProgramUniform4i                                      imgl3wProcs.gl.ProgramUniform4i
#define glProgramUniform4i64ARB                                 imgl3wProcs.gl.ProgramUniform4i64ARB
#define glProgramUniform4i64NV                                  imgl3wProcs.gl.ProgramUniform4i64NV
#define glProgramUniform4i64vARB                                imgl3wProcs.gl.ProgramUniform4i64vARB
#define glProgramUniform4i64vNV                                 imgl3wProcs.gl.ProgramUniform4i64vNV
#define glProgramUniform4iEXT                                   imgl3wProcs.gl.ProgramUniform4iEXT
#define glProgramUniform4iv                                     imgl3wProcs.gl.ProgramUniform4iv
#define glProgramUniform4ivEXT                                  imgl3wProcs.gl.ProgramUniform4ivEXT
#define glProgramUniform4ui                                     imgl3wProcs.gl.ProgramUniform4ui
#define glProgramUniform4ui64ARB                                imgl3wProcs.gl.ProgramUniform4ui64ARB
#define glProgramUniform4ui64NV                                 imgl3wProcs.gl.ProgramUniform4ui64NV
#define glProgramUniform4ui64vARB                               imgl3wProcs.gl.ProgramUniform4ui64vARB
#define glProgramUniform4ui64vNV                                imgl3wProcs.gl.ProgramUniform4ui64vNV
#define glProgramUniform4uiEXT                                  imgl3wProcs.gl.ProgramUniform4uiEXT
#define glProgramUniform4uiv                                    imgl3wProcs.gl.ProgramUniform4uiv
#define glProgramUniform4uivEXT                                 imgl3wProcs.gl.ProgramUniform4uivEXT
#define glProgramUniformHandleui64ARB                           imgl3wProcs.gl.ProgramUniformHandleui64ARB
#define glProgramUniformHandleui64NV                            imgl3wProcs.gl.ProgramUniformHandleui64NV
#define glProgramUniformHandleui64vARB                          imgl3wProcs.gl.ProgramUniformHandleui64vARB
#define glProgramUniformHandleui64vNV                           imgl3wProcs.gl.ProgramUniformHandleui64vNV
#define glProgramUniformMatrix2dv                               imgl3wProcs.gl.ProgramUniformMatrix2dv
#define glProgramUniformMatrix2dvEXT                            imgl3wProcs.gl.ProgramUniformMatrix2dvEXT
#define glProgramUniformMatrix2fv                               imgl3wProcs.gl.ProgramUniformMatrix2fv
#define glProgramUniformMatrix2fvEXT                            imgl3wProcs.gl.ProgramUniformMatrix2fvEXT
#define glProgramUniformMatrix2x3dv                             imgl3wProcs.gl.ProgramUniformMatrix2x3dv
#define glProgramUniformMatrix2x3dvEXT                          imgl3wProcs.gl.ProgramUniformMatrix2x3dvEXT
#define glProgramUniformMatrix2x3fv                             imgl3wProcs.gl.ProgramUniformMatrix2x3fv
#define glProgramUniformMatrix2x3fvEXT                          imgl3wProcs.gl.ProgramUniformMatrix2x3fvEXT
#define glProgramUniformMatrix2x4dv                             imgl3wProcs.gl.ProgramUniformMatrix2x4dv
#define glProgramUniformMatrix2x4dvEXT                          imgl3wProcs.gl.ProgramUniformMatrix2x4dvEXT
#define glProgramUniformMatrix2x4fv                             imgl3wProcs.gl.ProgramUniformMatrix2x4fv
#define glProgramUniformMatrix2x4fvEXT                          imgl3wProcs.gl.ProgramUniformMatrix2x4fvEXT
#define glProgramUniformMatrix3dv                               imgl3wProcs.gl.ProgramUniformMatrix3dv
#define glProgramUniformMatrix3dvEXT                            imgl3wProcs.gl.ProgramUniformMatrix3dvEXT
#define glProgramUniformMatrix3fv                               imgl3wProcs.gl.ProgramUniformMatrix3fv
#define glProgramUniformMatrix3fvEXT                            imgl3wProcs.gl.ProgramUniformMatrix3fvEXT
#define glProgramUniformMatrix3x2dv                             imgl3wProcs.gl.ProgramUniformMatrix3x2dv
#define glProgramUniformMatrix3x2dvEXT                          imgl3wProcs.gl.ProgramUniformMatrix3x2dvEXT
#define glProgramUniformMatrix3x2fv                             imgl3wProcs.gl.ProgramUniformMatrix3x2fv
#define glProgramUniformMatrix3x2fvEXT                          imgl3wProcs.gl.ProgramUniformMatrix3x2fvEXT
#define glProgramUniformMatrix3x4dv                             imgl3wProcs.gl.ProgramUniformMatrix3x4dv
#define glProgramUniformMatrix3x4dvEXT                          imgl3wProcs.gl.ProgramUniformMatrix3x4dvEXT
#define glProgramUniformMatrix3x4fv                             imgl3wProcs.gl.ProgramUniformMatrix3x4fv
#define glProgramUniformMatrix3x4fvEXT                          imgl3wProcs.gl.ProgramUniformMatrix3x4fvEXT
#define glProgramUniformMatrix4dv                               imgl3wProcs.gl.ProgramUniformMatrix4dv
#define glProgramUniformMatrix4dvEXT                            imgl3wProcs.gl.ProgramUniformMatrix4dvEXT
#define glProgramUniformMatrix4fv                               imgl3wProcs.gl.ProgramUniformMatrix4fv
#define glProgramUniformMatrix4fvEXT                            imgl3wProcs.gl.ProgramUniformMatrix4fvEXT
#define glProgramUniformMatrix4x2dv                             imgl3wProcs.gl.ProgramUniformMatrix4x2dv
#define glProgramUniformMatrix4x2dvEXT                          imgl3wProcs.gl.ProgramUniformMatrix4x2dvEXT
#define glProgramUniformMatrix4x2fv                             imgl3wProcs.gl.ProgramUniformMatrix4x2fv
#define glProgramUniformMatrix4x2fvEXT                          imgl3wProcs.gl.ProgramUniformMatrix4x2fvEXT
#define glProgramUniformMatrix4x3dv                             imgl3wProcs.gl.ProgramUniformMatrix4x3dv
#define glProgramUniformMatrix4x3dvEXT                          imgl3wProcs.gl.ProgramUniformMatrix4x3dvEXT
#define glProgramUniformMatrix4x3fv                             imgl3wProcs.gl.ProgramUniformMatrix4x3fv
#define glProgramUniformMatrix4x3fvEXT                          imgl3wProcs.gl.ProgramUniformMatrix4x3fvEXT
#define glProgramUniformui64NV                                  imgl3wProcs.gl.ProgramUniformui64NV
#define glProgramUniformui64vNV                                 imgl3wProcs.gl.ProgramUniformui64vNV
#define glProvokingVertex                                       imgl3wProcs.gl.ProvokingVertex
#define glPushClientAttribDefaultEXT                            imgl3wProcs.gl.PushClientAttribDefaultEXT
#define glPushDebugGroup                                        imgl3wProcs.gl.PushDebugGroup
#define glPushGroupMarkerEXT                                    imgl3wProcs.gl.PushGroupMarkerEXT
#define glQueryCounter                                          imgl3wProcs.gl.QueryCounter
#define glRasterSamplesEXT                                      imgl3wProcs.gl.RasterSamplesEXT
#define glReadBuffer                                            imgl3wProcs.gl.ReadBuffer
#define glReadPixels                                            imgl3wProcs.gl.ReadPixels
#define glReadnPixels                                           imgl3wProcs.gl.ReadnPixels
#define glReadnPixelsARB                                        imgl3wProcs.gl.ReadnPixelsARB
#define glReleaseShaderCompiler                                 imgl3wProcs.gl.ReleaseShaderCompiler
#define glRenderbufferStorage                                   imgl3wProcs.gl.RenderbufferStorage
#define glRenderbufferStorageMultisample                        imgl3wProcs.gl.RenderbufferStorageMultisample
#define glRenderbufferStorageMultisampleAdvancedAMD             imgl3wProcs.gl.RenderbufferStorageMultisampleAdvancedAMD
#define glRenderbufferStorageMultisampleCoverageNV              imgl3wProcs.gl.RenderbufferStorageMultisampleCoverageNV
#define glResetMemoryObjectParameterNV                          imgl3wProcs.gl.ResetMemoryObjectParameterNV
#define glResolveDepthValuesNV                                  imgl3wProcs.gl.ResolveDepthValuesNV
#define glResumeTransformFeedback                               imgl3wProcs.gl.ResumeTransformFeedback
#define glSampleCoverage                                        imgl3wProcs.gl.SampleCoverage
#define glSampleMaski                                           imgl3wProcs.gl.SampleMaski
#define glSamplerParameterIiv                                   imgl3wProcs.gl.SamplerParameterIiv
#define glSamplerParameterIuiv                                  imgl3wProcs.gl.SamplerParameterIuiv
#define glSamplerParameterf                                     imgl3wProcs.gl.SamplerParameterf
#define glSamplerParameterfv                                    imgl3wProcs.gl.SamplerParameterfv
#define glSamplerParameteri                                     imgl3wProcs.gl.SamplerParameteri
#define glSamplerParameteriv                                    imgl3wProcs.gl.SamplerParameteriv
#define glScissor                                               imgl3wProcs.gl.Scissor
#define glScissorArrayv                                         imgl3wProcs.gl.ScissorArrayv
#define glScissorExclusiveArrayvNV                              imgl3wProcs.gl.ScissorExclusiveArrayvNV
#define glScissorExclusiveNV                                    imgl3wProcs.gl.ScissorExclusiveNV
#define glScissorIndexed                                        imgl3wProcs.gl.ScissorIndexed
#define glScissorIndexedv                                       imgl3wProcs.gl.ScissorIndexedv
#define glSecondaryColorFormatNV                                imgl3wProcs.gl.SecondaryColorFormatNV
#define glSelectPerfMonitorCountersAMD                          imgl3wProcs.gl.SelectPerfMonitorCountersAMD
#define glShaderBinary                                          imgl3wProcs.gl.ShaderBinary
#define glShaderSource                                          imgl3wProcs.gl.ShaderSource
#define glShaderStorageBlockBinding                             imgl3wProcs.gl.ShaderStorageBlockBinding
#define glShadingRateImageBarrierNV                             imgl3wProcs.gl.ShadingRateImageBarrierNV
#define glShadingRateImagePaletteNV                             imgl3wProcs.gl.ShadingRateImagePaletteNV
#define glShadingRateSampleOrderCustomNV                        imgl3wProcs.gl.ShadingRateSampleOrderCustomNV
#define glShadingRateSampleOrderNV                              imgl3wProcs.gl.ShadingRateSampleOrderNV
#define glSignalVkFenceNV                                       imgl3wProcs.gl.SignalVkFenceNV
#define glSignalVkSemaphoreNV                                   imgl3wProcs.gl.SignalVkSemaphoreNV
#define glSpecializeShader                                      imgl3wProcs.gl.SpecializeShader
#define glSpecializeShaderARB                                   imgl3wProcs.gl.SpecializeShaderARB
#define glStateCaptureNV                                        imgl3wProcs.gl.StateCaptureNV
#define glStencilFillPathInstancedNV                            imgl3wProcs.gl.StencilFillPathInstancedNV
#define glStencilFillPathNV                                     imgl3wProcs.gl.StencilFillPathNV
#define glStencilFunc                                           imgl3wProcs.gl.StencilFunc
#define glStencilFuncSeparate                                   imgl3wProcs.gl.StencilFuncSeparate
#define glStencilMask                                           imgl3wProcs.gl.StencilMask
#define glStencilMaskSeparate                                   imgl3wProcs.gl.StencilMaskSeparate
#define glStencilOp                                             imgl3wProcs.gl.StencilOp
#define glStencilOpSeparate                                     imgl3wProcs.gl.StencilOpSeparate
#define glStencilStrokePathInstancedNV                          imgl3wProcs.gl.StencilStrokePathInstancedNV
#define glStencilStrokePathNV                                   imgl3wProcs.gl.StencilStrokePathNV
#define glStencilThenCoverFillPathInstancedNV                   imgl3wProcs.gl.StencilThenCoverFillPathInstancedNV
#define glStencilThenCoverFillPathNV                            imgl3wProcs.gl.StencilThenCoverFillPathNV
#define glStencilThenCoverStrokePathInstancedNV                 imgl3wProcs.gl.StencilThenCoverStrokePathInstancedNV
#define glStencilThenCoverStrokePathNV                          imgl3wProcs.gl.StencilThenCoverStrokePathNV
#define glSubpixelPrecisionBiasNV                               imgl3wProcs.gl.SubpixelPrecisionBiasNV
#define glTexAttachMemoryNV                                     imgl3wProcs.gl.TexAttachMemoryNV
#define glTexBuffer                                             imgl3wProcs.gl.TexBuffer
#define glTexBufferARB                                          imgl3wProcs.gl.TexBufferARB
#define glTexBufferRange                                        imgl3wProcs.gl.TexBufferRange
#define glTexCoordFormatNV                                      imgl3wProcs.gl.TexCoordFormatNV
#define glTexImage1D                                            imgl3wProcs.gl.TexImage1D
#define glTexImage2D                                            imgl3wProcs.gl.TexImage2D
#define glTexImage2DMultisample                                 imgl3wProcs.gl.TexImage2DMultisample
#define glTexImage3D                                            imgl3wProcs.gl.TexImage3D
#define glTexImage3DMultisample                                 imgl3wProcs.gl.TexImage3DMultisample
#define glTexPageCommitmentARB                                  imgl3wProcs.gl.TexPageCommitmentARB
#define glTexPageCommitmentMemNV                                imgl3wProcs.gl.TexPageCommitmentMemNV
#define glTexParameterIiv                                       imgl3wProcs.gl.TexParameterIiv
#define glTexParameterIuiv                                      imgl3wProcs.gl.TexParameterIuiv
#define glTexParameterf                                         imgl3wProcs.gl.TexParameterf
#define glTexParameterfv                                        imgl3wProcs.gl.TexParameterfv
#define glTexParameteri                                         imgl3wProcs.gl.TexParameteri
#define glTexParameteriv                                        imgl3wProcs.gl.TexParameteriv
#define glTexStorage1D                                          imgl3wProcs.gl.TexStorage1D
#define glTexStorage1DEXT                                       imgl3wProcs.gl.TexStorage1DEXT
#define glTexStorage2D                                          imgl3wProcs.gl.TexStorage2D
#define glTexStorage2DEXT                                       imgl3wProcs.gl.TexStorage2DEXT
#define glTexStorage2DMultisample                               imgl3wProcs.gl.TexStorage2DMultisample
#define glTexStorage3D                                          imgl3wProcs.gl.TexStorage3D
#define glTexStorage3DEXT                                       imgl3wProcs.gl.TexStorage3DEXT
#define glTexStorage3DMultisample                               imgl3wProcs.gl.TexStorage3DMultisample
#define glTexSubImage1D                                         imgl3wProcs.gl.TexSubImage1D
#define glTexSubImage2D                                         imgl3wProcs.gl.TexSubImage2D
#define glTexSubImage3D                                         imgl3wProcs.gl.TexSubImage3D
#define glTextureAttachMemoryNV                                 imgl3wProcs.gl.TextureAttachMemoryNV
#define glTextureBarrier                                        imgl3wProcs.gl.TextureBarrier
#define glTextureBarrierNV                                      imgl3wProcs.gl.TextureBarrierNV
#define glTextureBuffer                                         imgl3wProcs.gl.TextureBuffer
#define glTextureBufferEXT                                      imgl3wProcs.gl.TextureBufferEXT
#define glTextureBufferRange                                    imgl3wProcs.gl.TextureBufferRange
#define glTextureBufferRangeEXT                                 imgl3wProcs.gl.TextureBufferRangeEXT
#define glTextureImage1DEXT                                     imgl3wProcs.gl.TextureImage1DEXT
#define glTextureImage2DEXT                                     imgl3wProcs.gl.TextureImage2DEXT
#define glTextureImage3DEXT                                     imgl3wProcs.gl.TextureImage3DEXT
#define glTexturePageCommitmentEXT                              imgl3wProcs.gl.TexturePageCommitmentEXT
#define glTexturePageCommitmentMemNV                            imgl3wProcs.gl.TexturePageCommitmentMemNV
#define glTextureParameterIiv                                   imgl3wProcs.gl.TextureParameterIiv
#define glTextureParameterIivEXT                                imgl3wProcs.gl.TextureParameterIivEXT
#define glTextureParameterIuiv                                  imgl3wProcs.gl.TextureParameterIuiv
#define glTextureParameterIuivEXT                               imgl3wProcs.gl.TextureParameterIuivEXT
#define glTextureParameterf                                     imgl3wProcs.gl.TextureParameterf
#define glTextureParameterfEXT                                  imgl3wProcs.gl.TextureParameterfEXT
#define glTextureParameterfv                                    imgl3wProcs.gl.TextureParameterfv
#define glTextureParameterfvEXT                                 imgl3wProcs.gl.TextureParameterfvEXT
#define glTextureParameteri                                     imgl3wProcs.gl.TextureParameteri
#define glTextureParameteriEXT                                  imgl3wProcs.gl.TextureParameteriEXT
#define glTextureParameteriv                                    imgl3wProcs.gl.TextureParameteriv
#define glTextureParameterivEXT                                 imgl3wProcs.gl.TextureParameterivEXT
#define glTextureRenderbufferEXT                                imgl3wProcs.gl.TextureRenderbufferEXT
#define glTextureStorage1D                                      imgl3wProcs.gl.TextureStorage1D
#define glTextureStorage1DEXT                                   imgl3wProcs.gl.TextureStorage1DEXT
#define glTextureStorage2D                                      imgl3wProcs.gl.TextureStorage2D
#define glTextureStorage2DEXT                                   imgl3wProcs.gl.TextureStorage2DEXT
#define glTextureStorage2DMultisample                           imgl3wProcs.gl.TextureStorage2DMultisample
#define glTextureStorage2DMultisampleEXT                        imgl3wProcs.gl.TextureStorage2DMultisampleEXT
#define glTextureStorage3D                                      imgl3wProcs.gl.TextureStorage3D
#define glTextureStorage3DEXT                                   imgl3wProcs.gl.TextureStorage3DEXT
#define glTextureStorage3DMultisample                           imgl3wProcs.gl.TextureStorage3DMultisample
#define glTextureStorage3DMultisampleEXT                        imgl3wProcs.gl.TextureStorage3DMultisampleEXT
#define glTextureSubImage1D                                     imgl3wProcs.gl.TextureSubImage1D
#define glTextureSubImage1DEXT                                  imgl3wProcs.gl.TextureSubImage1DEXT
#define glTextureSubImage2D                                     imgl3wProcs.gl.TextureSubImage2D
#define glTextureSubImage2DEXT                                  imgl3wProcs.gl.TextureSubImage2DEXT
#define glTextureSubImage3D                                     imgl3wProcs.gl.TextureSubImage3D
#define glTextureSubImage3DEXT                                  imgl3wProcs.gl.TextureSubImage3DEXT
#define glTextureView                                           imgl3wProcs.gl.TextureView
#define glTransformFeedbackBufferBase                           imgl3wProcs.gl.TransformFeedbackBufferBase
#define glTransformFeedbackBufferRange                          imgl3wProcs.gl.TransformFeedbackBufferRange
#define glTransformFeedbackVaryings                             imgl3wProcs.gl.TransformFeedbackVaryings
#define glTransformPathNV                                       imgl3wProcs.gl.TransformPathNV
#define glUniform1d                                             imgl3wProcs.gl.Uniform1d
#define glUniform1dv                                            imgl3wProcs.gl.Uniform1dv
#define glUniform1f                                             imgl3wProcs.gl.Uniform1f
#define glUniform1fv                                            imgl3wProcs.gl.Uniform1fv
#define glUniform1i                                             imgl3wProcs.gl.Uniform1i
#define glUniform1i64ARB                                        imgl3wProcs.gl.Uniform1i64ARB
#define glUniform1i64NV                                         imgl3wProcs.gl.Uniform1i64NV
#define glUniform1i64vARB                                       imgl3wProcs.gl.Uniform1i64vARB
#define glUniform1i64vNV                                        imgl3wProcs.gl.Uniform1i64vNV
#define glUniform1iv                                            imgl3wProcs.gl.Uniform1iv
#define glUniform1ui                                            imgl3wProcs.gl.Uniform1ui
#define glUniform1ui64ARB                                       imgl3wProcs.gl.Uniform1ui64ARB
#define glUniform1ui64NV                                        imgl3wProcs.gl.Uniform1ui64NV
#define glUniform1ui64vARB                                      imgl3wProcs.gl.Uniform1ui64vARB
#define glUniform1ui64vNV                                       imgl3wProcs.gl.Uniform1ui64vNV
#define glUniform1uiv                                           imgl3wProcs.gl.Uniform1uiv
#define glUniform2d                                             imgl3wProcs.gl.Uniform2d
#define glUniform2dv                                            imgl3wProcs.gl.Uniform2dv
#define glUniform2f                                             imgl3wProcs.gl.Uniform2f
#define glUniform2fv                                            imgl3wProcs.gl.Uniform2fv
#define glUniform2i                                             imgl3wProcs.gl.Uniform2i
#define glUniform2i64ARB                                        imgl3wProcs.gl.Uniform2i64ARB
#define glUniform2i64NV                                         imgl3wProcs.gl.Uniform2i64NV
#define glUniform2i64vARB                                       imgl3wProcs.gl.Uniform2i64vARB
#define glUniform2i64vNV                                        imgl3wProcs.gl.Uniform2i64vNV
#define glUniform2iv                                            imgl3wProcs.gl.Uniform2iv
#define glUniform2ui                                            imgl3wProcs.gl.Uniform2ui
#define glUniform2ui64ARB                                       imgl3wProcs.gl.Uniform2ui64ARB
#define glUniform2ui64NV                                        imgl3wProcs.gl.Uniform2ui64NV
#define glUniform2ui64vARB                                      imgl3wProcs.gl.Uniform2ui64vARB
#define glUniform2ui64vNV                                       imgl3wProcs.gl.Uniform2ui64vNV
#define glUniform2uiv                                           imgl3wProcs.gl.Uniform2uiv
#define glUniform3d                                             imgl3wProcs.gl.Uniform3d
#define glUniform3dv                                            imgl3wProcs.gl.Uniform3dv
#define glUniform3f                                             imgl3wProcs.gl.Uniform3f
#define glUniform3fv                                            imgl3wProcs.gl.Uniform3fv
#define glUniform3i                                             imgl3wProcs.gl.Uniform3i
#define glUniform3i64ARB                                        imgl3wProcs.gl.Uniform3i64ARB
#define glUniform3i64NV                                         imgl3wProcs.gl.Uniform3i64NV
#define glUniform3i64vARB                                       imgl3wProcs.gl.Uniform3i64vARB
#define glUniform3i64vNV                                        imgl3wProcs.gl.Uniform3i64vNV
#define glUniform3iv                                            imgl3wProcs.gl.Uniform3iv
#define glUniform3ui                                            imgl3wProcs.gl.Uniform3ui
#define glUniform3ui64ARB                                       imgl3wProcs.gl.Uniform3ui64ARB
#define glUniform3ui64NV                                        imgl3wProcs.gl.Uniform3ui64NV
#define glUniform3ui64vARB                                      imgl3wProcs.gl.Uniform3ui64vARB
#define glUniform3ui64vNV                                       imgl3wProcs.gl.Uniform3ui64vNV
#define glUniform3uiv                                           imgl3wProcs.gl.Uniform3uiv
#define glUniform4d                                             imgl3wProcs.gl.Uniform4d
#define glUniform4dv                                            imgl3wProcs.gl.Uniform4dv
#define glUniform4f                                             imgl3wProcs.gl.Uniform4f
#define glUniform4fv                                            imgl3wProcs.gl.Uniform4fv
#define glUniform4i                                             imgl3wProcs.gl.Uniform4i
#define glUniform4i64ARB                                        imgl3wProcs.gl.Uniform4i64ARB
#define glUniform4i64NV                                         imgl3wProcs.gl.Uniform4i64NV
#define glUniform4i64vARB                                       imgl3wProcs.gl.Uniform4i64vARB
#define glUniform4i64vNV                                        imgl3wProcs.gl.Uniform4i64vNV
#define glUniform4iv                                            imgl3wProcs.gl.Uniform4iv
#define glUniform4ui                                            imgl3wProcs.gl.Uniform4ui
#define glUniform4ui64ARB                                       imgl3wProcs.gl.Uniform4ui64ARB
#define glUniform4ui64NV                                        imgl3wProcs.gl.Uniform4ui64NV
#define glUniform4ui64vARB                                      imgl3wProcs.gl.Uniform4ui64vARB
#define glUniform4ui64vNV                                       imgl3wProcs.gl.Uniform4ui64vNV
#define glUniform4uiv                                           imgl3wProcs.gl.Uniform4uiv
#define glUniformBlockBinding                                   imgl3wProcs.gl.UniformBlockBinding
#define glUniformHandleui64ARB                                  imgl3wProcs.gl.UniformHandleui64ARB
#define glUniformHandleui64NV                                   imgl3wProcs.gl.UniformHandleui64NV
#define glUniformHandleui64vARB                                 imgl3wProcs.gl.UniformHandleui64vARB
#define glUniformHandleui64vNV                                  imgl3wProcs.gl.UniformHandleui64vNV
#define glUniformMatrix2dv                                      imgl3wProcs.gl.UniformMatrix2dv
#define glUniformMatrix2fv                                      imgl3wProcs.gl.UniformMatrix2fv
#define glUniformMatrix2x3dv                                    imgl3wProcs.gl.UniformMatrix2x3dv
#define glUniformMatrix2x3fv                                    imgl3wProcs.gl.UniformMatrix2x3fv
#define glUniformMatrix2x4dv                                    imgl3wProcs.gl.UniformMatrix2x4dv
#define glUniformMatrix2x4fv                                    imgl3wProcs.gl.UniformMatrix2x4fv
#define glUniformMatrix3dv                                      imgl3wProcs.gl.UniformMatrix3dv
#define glUniformMatrix3fv                                      imgl3wProcs.gl.UniformMatrix3fv
#define glUniformMatrix3x2dv                                    imgl3wProcs.gl.UniformMatrix3x2dv
#define glUniformMatrix3x2fv                                    imgl3wProcs.gl.UniformMatrix3x2fv
#define glUniformMatrix3x4dv                                    imgl3wProcs.gl.UniformMatrix3x4dv
#define glUniformMatrix3x4fv                                    imgl3wProcs.gl.UniformMatrix3x4fv
#define glUniformMatrix4dv                                      imgl3wProcs.gl.UniformMatrix4dv
#define glUniformMatrix4fv                                      imgl3wProcs.gl.UniformMatrix4fv
#define glUniformMatrix4x2dv                                    imgl3wProcs.gl.UniformMatrix4x2dv
#define glUniformMatrix4x2fv                                    imgl3wProcs.gl.UniformMatrix4x2fv
#define glUniformMatrix4x3dv                                    imgl3wProcs.gl.UniformMatrix4x3dv
#define glUniformMatrix4x3fv                                    imgl3wProcs.gl.UniformMatrix4x3fv
#define glUniformSubroutinesuiv                                 imgl3wProcs.gl.UniformSubroutinesuiv
#define glUniformui64NV                                         imgl3wProcs.gl.Uniformui64NV
#define glUniformui64vNV                                        imgl3wProcs.gl.Uniformui64vNV
#define glUnmapBuffer                                           imgl3wProcs.gl.UnmapBuffer
#define glUnmapNamedBuffer                                      imgl3wProcs.gl.UnmapNamedBuffer
#define glUnmapNamedBufferEXT                                   imgl3wProcs.gl.UnmapNamedBufferEXT
#define glUseProgram                                            imgl3wProcs.gl.UseProgram
#define glUseProgramStages                                      imgl3wProcs.gl.UseProgramStages
#define glUseShaderProgramEXT                                   imgl3wProcs.gl.UseShaderProgramEXT
#define glValidateProgram                                       imgl3wProcs.gl.ValidateProgram
#define glValidateProgramPipeline                               imgl3wProcs.gl.ValidateProgramPipeline
#define glVertexArrayAttribBinding                              imgl3wProcs.gl.VertexArrayAttribBinding
#define glVertexArrayAttribFormat                               imgl3wProcs.gl.VertexArrayAttribFormat
#define glVertexArrayAttribIFormat                              imgl3wProcs.gl.VertexArrayAttribIFormat
#define glVertexArrayAttribLFormat                              imgl3wProcs.gl.VertexArrayAttribLFormat
#define glVertexArrayBindVertexBufferEXT                        imgl3wProcs.gl.VertexArrayBindVertexBufferEXT
#define glVertexArrayBindingDivisor                             imgl3wProcs.gl.VertexArrayBindingDivisor
#define glVertexArrayColorOffsetEXT                             imgl3wProcs.gl.VertexArrayColorOffsetEXT
#define glVertexArrayEdgeFlagOffsetEXT                          imgl3wProcs.gl.VertexArrayEdgeFlagOffsetEXT
#define glVertexArrayElementBuffer                              imgl3wProcs.gl.VertexArrayElementBuffer
#define glVertexArrayFogCoordOffsetEXT                          imgl3wProcs.gl.VertexArrayFogCoordOffsetEXT
#define glVertexArrayIndexOffsetEXT                             imgl3wProcs.gl.VertexArrayIndexOffsetEXT
#define glVertexArrayMultiTexCoordOffsetEXT                     imgl3wProcs.gl.VertexArrayMultiTexCoordOffsetEXT
#define glVertexArrayNormalOffsetEXT                            imgl3wProcs.gl.VertexArrayNormalOffsetEXT
#define glVertexArraySecondaryColorOffsetEXT                    imgl3wProcs.gl.VertexArraySecondaryColorOffsetEXT
#define glVertexArrayTexCoordOffsetEXT                          imgl3wProcs.gl.VertexArrayTexCoordOffsetEXT
#define glVertexArrayVertexAttribBindingEXT                     imgl3wProcs.gl.VertexArrayVertexAttribBindingEXT
#define glVertexArrayVertexAttribDivisorEXT                     imgl3wProcs.gl.VertexArrayVertexAttribDivisorEXT
#define glVertexArrayVertexAttribFormatEXT                      imgl3wProcs.gl.VertexArrayVertexAttribFormatEXT
#define glVertexArrayVertexAttribIFormatEXT                     imgl3wProcs.gl.VertexArrayVertexAttribIFormatEXT
#define glVertexArrayVertexAttribIOffsetEXT                     imgl3wProcs.gl.VertexArrayVertexAttribIOffsetEXT
#define glVertexArrayVertexAttribLFormatEXT                     imgl3wProcs.gl.VertexArrayVertexAttribLFormatEXT
#define glVertexArrayVertexAttribLOffsetEXT                     imgl3wProcs.gl.VertexArrayVertexAttribLOffsetEXT
#define glVertexArrayVertexAttribOffsetEXT                      imgl3wProcs.gl.VertexArrayVertexAttribOffsetEXT
#define glVertexArrayVertexBindingDivisorEXT                    imgl3wProcs.gl.VertexArrayVertexBindingDivisorEXT
#define glVertexArrayVertexBuffer                               imgl3wProcs.gl.VertexArrayVertexBuffer
#define glVertexArrayVertexBuffers                              imgl3wProcs.gl.VertexArrayVertexBuffers
#define glVertexArrayVertexOffsetEXT                            imgl3wProcs.gl.VertexArrayVertexOffsetEXT
#define glVertexAttrib1d                                        imgl3wProcs.gl.VertexAttrib1d
#define glVertexAttrib1dv                                       imgl3wProcs.gl.VertexAttrib1dv
#define glVertexAttrib1f                                        imgl3wProcs.gl.VertexAttrib1f
#define glVertexAttrib1fv                                       imgl3wProcs.gl.VertexAttrib1fv
#define glVertexAttrib1s                                        imgl3wProcs.gl.VertexAttrib1s
#define glVertexAttrib1sv                                       imgl3wProcs.gl.VertexAttrib1sv
#define glVertexAttrib2d                                        imgl3wProcs.gl.VertexAttrib2d
#define glVertexAttrib2dv                                       imgl3wProcs.gl.VertexAttrib2dv
#define glVertexAttrib2f                                        imgl3wProcs.gl.VertexAttrib2f
#define glVertexAttrib2fv                                       imgl3wProcs.gl.VertexAttrib2fv
#define glVertexAttrib2s                                        imgl3wProcs.gl.VertexAttrib2s
#define glVertexAttrib2sv                                       imgl3wProcs.gl.VertexAttrib2sv
#define glVertexAttrib3d                                        imgl3wProcs.gl.VertexAttrib3d
#define glVertexAttrib3dv                                       imgl3wProcs.gl.VertexAttrib3dv
#define glVertexAttrib3f                                        imgl3wProcs.gl.VertexAttrib3f
#define glVertexAttrib3fv                                       imgl3wProcs.gl.VertexAttrib3fv
#define glVertexAttrib3s                                        imgl3wProcs.gl.VertexAttrib3s
#define glVertexAttrib3sv                                       imgl3wProcs.gl.VertexAttrib3sv
#define glVertexAttrib4Nbv                                      imgl3wProcs.gl.VertexAttrib4Nbv
#define glVertexAttrib4Niv                                      imgl3wProcs.gl.VertexAttrib4Niv
#define glVertexAttrib4Nsv                                      imgl3wProcs.gl.VertexAttrib4Nsv
#define glVertexAttrib4Nub                                      imgl3wProcs.gl.VertexAttrib4Nub
#define glVertexAttrib4Nubv                                     imgl3wProcs.gl.VertexAttrib4Nubv
#define glVertexAttrib4Nuiv                                     imgl3wProcs.gl.VertexAttrib4Nuiv
#define glVertexAttrib4Nusv                                     imgl3wProcs.gl.VertexAttrib4Nusv
#define glVertexAttrib4bv                                       imgl3wProcs.gl.VertexAttrib4bv
#define glVertexAttrib4d                                        imgl3wProcs.gl.VertexAttrib4d
#define glVertexAttrib4dv                                       imgl3wProcs.gl.VertexAttrib4dv
#define glVertexAttrib4f                                        imgl3wProcs.gl.VertexAttrib4f
#define glVertexAttrib4fv                                       imgl3wProcs.gl.VertexAttrib4fv
#define glVertexAttrib4iv                                       imgl3wProcs.gl.VertexAttrib4iv
#define glVertexAttrib4s                                        imgl3wProcs.gl.VertexAttrib4s
#define glVertexAttrib4sv                                       imgl3wProcs.gl.VertexAttrib4sv
#define glVertexAttrib4ubv                                      imgl3wProcs.gl.VertexAttrib4ubv
#define glVertexAttrib4uiv                                      imgl3wProcs.gl.VertexAttrib4uiv
#define glVertexAttrib4usv                                      imgl3wProcs.gl.VertexAttrib4usv
#define glVertexAttribBinding                                   imgl3wProcs.gl.VertexAttribBinding
#define glVertexAttribDivisor                                   imgl3wProcs.gl.VertexAttribDivisor
#define glVertexAttribDivisorARB                                imgl3wProcs.gl.VertexAttribDivisorARB
#define glVertexAttribFormat                                    imgl3wProcs.gl.VertexAttribFormat
#define glVertexAttribFormatNV                                  imgl3wProcs.gl.VertexAttribFormatNV
#define glVertexAttribI1i                                       imgl3wProcs.gl.VertexAttribI1i
#define glVertexAttribI1iv                                      imgl3wProcs.gl.VertexAttribI1iv
#define glVertexAttribI1ui                                      imgl3wProcs.gl.VertexAttribI1ui
#define glVertexAttribI1uiv                                     imgl3wProcs.gl.VertexAttribI1uiv
#define glVertexAttribI2i                                       imgl3wProcs.gl.VertexAttribI2i
#define glVertexAttribI2iv                                      imgl3wProcs.gl.VertexAttribI2iv
#define glVertexAttribI2ui                                      imgl3wProcs.gl.VertexAttribI2ui
#define glVertexAttribI2uiv                                     imgl3wProcs.gl.VertexAttribI2uiv
#define glVertexAttribI3i                                       imgl3wProcs.gl.VertexAttribI3i
#define glVertexAttribI3iv                                      imgl3wProcs.gl.VertexAttribI3iv
#define glVertexAttribI3ui                                      imgl3wProcs.gl.VertexAttribI3ui
#define glVertexAttribI3uiv                                     imgl3wProcs.gl.VertexAttribI3uiv
#define glVertexAttribI4bv                                      imgl3wProcs.gl.VertexAttribI4bv
#define glVertexAttribI4i                                       imgl3wProcs.gl.VertexAttribI4i
#define glVertexAttribI4iv                                      imgl3wProcs.gl.VertexAttribI4iv
#define glVertexAttribI4sv                                      imgl3wProcs.gl.VertexAttribI4sv
#define glVertexAttribI4ubv                                     imgl3wProcs.gl.VertexAttribI4ubv
#define glVertexAttribI4ui                                      imgl3wProcs.gl.VertexAttribI4ui
#define glVertexAttribI4uiv                                     imgl3wProcs.gl.VertexAttribI4uiv
#define glVertexAttribI4usv                                     imgl3wProcs.gl.VertexAttribI4usv
#define glVertexAttribIFormat                                   imgl3wProcs.gl.VertexAttribIFormat
#define glVertexAttribIFormatNV                                 imgl3wProcs.gl.VertexAttribIFormatNV
#define glVertexAttribIPointer                                  imgl3wProcs.gl.VertexAttribIPointer
#define glVertexAttribL1d                                       imgl3wProcs.gl.VertexAttribL1d
#define glVertexAttribL1dv                                      imgl3wProcs.gl.VertexAttribL1dv
#define glVertexAttribL1i64NV                                   imgl3wProcs.gl.VertexAttribL1i64NV
#define glVertexAttribL1i64vNV                                  imgl3wProcs.gl.VertexAttribL1i64vNV
#define glVertexAttribL1ui64ARB                                 imgl3wProcs.gl.VertexAttribL1ui64ARB
#define glVertexAttribL1ui64NV                                  imgl3wProcs.gl.VertexAttribL1ui64NV
#define glVertexAttribL1ui64vARB                                imgl3wProcs.gl.VertexAttribL1ui64vARB
#define glVertexAttribL1ui64vNV                                 imgl3wProcs.gl.VertexAttribL1ui64vNV
#define glVertexAttribL2d                                       imgl3wProcs.gl.VertexAttribL2d
#define glVertexAttribL2dv                                      imgl3wProcs.gl.VertexAttribL2dv
#define glVertexAttribL2i64NV                                   imgl3wProcs.gl.VertexAttribL2i64NV
#define glVertexAttribL2i64vNV                                  imgl3wProcs.gl.VertexAttribL2i64vNV
#define glVertexAttribL2ui64NV                                  imgl3wProcs.gl.VertexAttribL2ui64NV
#define glVertexAttribL2ui64vNV                                 imgl3wProcs.gl.VertexAttribL2ui64vNV
#define glVertexAttribL3d                                       imgl3wProcs.gl.VertexAttribL3d
#define glVertexAttribL3dv                                      imgl3wProcs.gl.VertexAttribL3dv
#define glVertexAttribL3i64NV                                   imgl3wProcs.gl.VertexAttribL3i64NV
#define glVertexAttribL3i64vNV                                  imgl3wProcs.gl.VertexAttribL3i64vNV
#define glVertexAttribL3ui64NV                                  imgl3wProcs.gl.VertexAttribL3ui64NV
#define glVertexAttribL3ui64vNV                                 imgl3wProcs.gl.VertexAttribL3ui64vNV
#define glVertexAttribL4d                                       imgl3wProcs.gl.VertexAttribL4d
#define glVertexAttribL4dv                                      imgl3wProcs.gl.VertexAttribL4dv
#define glVertexAttribL4i64NV                                   imgl3wProcs.gl.VertexAttribL4i64NV
#define glVertexAttribL4i64vNV                                  imgl3wProcs.gl.VertexAttribL4i64vNV
#define glVertexAttribL4ui64NV                                  imgl3wProcs.gl.VertexAttribL4ui64NV
#define glVertexAttribL4ui64vNV                                 imgl3wProcs.gl.VertexAttribL4ui64vNV
#define glVertexAttribLFormat                                   imgl3wProcs.gl.VertexAttribLFormat
#define glVertexAttribLFormatNV                                 imgl3wProcs.gl.VertexAttribLFormatNV
#define glVertexAttribLPointer                                  imgl3wProcs.gl.VertexAttribLPointer
#define glVertexAttribP1ui                                      imgl3wProcs.gl.VertexAttribP1ui
#define glVertexAttribP1uiv                                     imgl3wProcs.gl.VertexAttribP1uiv
#define glVertexAttribP2ui                                      imgl3wProcs.gl.VertexAttribP2ui
#define glVertexAttribP2uiv                                     imgl3wProcs.gl.VertexAttribP2uiv
#define glVertexAttribP3ui                                      imgl3wProcs.gl.VertexAttribP3ui
#define glVertexAttribP3uiv                                     imgl3wProcs.gl.VertexAttribP3uiv
#define glVertexAttribP4ui                                      imgl3wProcs.gl.VertexAttribP4ui
#define glVertexAttribP4uiv                                     imgl3wProcs.gl.VertexAttribP4uiv
#define glVertexAttribPointer                                   imgl3wProcs.gl.VertexAttribPointer
#define glVertexBindingDivisor                                  imgl3wProcs.gl.VertexBindingDivisor
#define glVertexFormatNV                                        imgl3wProcs.gl.VertexFormatNV
#define glViewport                                              imgl3wProcs.gl.Viewport
#define glViewportArrayv                                        imgl3wProcs.gl.ViewportArrayv
#define glViewportIndexedf                                      imgl3wProcs.gl.ViewportIndexedf
#define glViewportIndexedfv                                     imgl3wProcs.gl.ViewportIndexedfv
#define glViewportPositionWScaleNV                              imgl3wProcs.gl.ViewportPositionWScaleNV
#define glViewportSwizzleNV                                     imgl3wProcs.gl.ViewportSwizzleNV
#define glWaitSync                                              imgl3wProcs.gl.WaitSync
#define glWaitVkSemaphoreNV                                     imgl3wProcs.gl.WaitVkSemaphoreNV
#define glWeightPathsNV                                         imgl3wProcs.gl.WeightPathsNV
#define glWindowRectanglesEXT                                   imgl3wProcs.gl.WindowRectanglesEXT

#ifdef __cplusplus
}
#endif

#endif

#ifdef IMGL3W_IMPL
#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>

#define GL3W_ARRAY_SIZE(x)  (sizeof(x) / sizeof((x)[0]))

#if defined(_WIN32)
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN 1
#endif
#include <windows.h>

static HMODULE libgl;
typedef PROC(__stdcall* GL3WglGetProcAddr)(LPCSTR);
static GL3WglGetProcAddr wgl_get_proc_address;

static int open_libgl(void)
{
    libgl = LoadLibraryA("opengl32.dll");
    if (!libgl)
        return GL3W_ERROR_LIBRARY_OPEN;
    wgl_get_proc_address = (GL3WglGetProcAddr)GetProcAddress(libgl, "wglGetProcAddress");
    return GL3W_OK;
}

static void close_libgl(void) { FreeLibrary(libgl); }
static GL3WglProc get_proc(const char *proc)
{
    GL3WglProc res;
    res = (GL3WglProc)wgl_get_proc_address(proc);
    if (!res)
        res = (GL3WglProc)GetProcAddress(libgl, proc);
    return res;
}
#elif defined(__APPLE__)
#include <dlfcn.h>

static void *libgl;
static int open_libgl(void)
{
    libgl = dlopen("/System/Library/Frameworks/OpenGL.framework/OpenGL", RTLD_LAZY | RTLD_LOCAL);
    if (!libgl)
        return GL3W_ERROR_LIBRARY_OPEN;
    return GL3W_OK;
}

static void close_libgl(void) { dlclose(libgl); }

static GL3WglProc get_proc(const char *proc)
{
    GL3WglProc res;
    *(void **)(&res) = dlsym(libgl, proc);
    return res;
}
#else
#include <dlfcn.h>

static void* libgl;  // OpenGL library
static void* libglx;  // GLX library
static void* libegl;  // EGL library
static GL3WGetProcAddressProc gl_get_proc_address;

static void close_libgl(void)
{
    if (libgl) {
        dlclose(libgl);
        libgl = NULL;
    }
    if (libegl) {
        dlclose(libegl);
        libegl = NULL;
    }
    if (libglx) {
        dlclose(libglx);
        libglx = NULL;
    }
}

static int is_library_loaded(const char* name, void** lib)
{
    *lib = dlopen(name, RTLD_LAZY | RTLD_LOCAL | RTLD_NOLOAD);
    return *lib != NULL;
}

static int open_libs(void)
{
    // On Linux we have two APIs to get process addresses: EGL and GLX.
    // EGL is supported under both X11 and Wayland, whereas GLX is X11-specific.

    libgl = NULL;
    libegl = NULL;
    libglx = NULL;

    // First check what's already loaded, the windowing library might have
    // already loaded either EGL or GLX and we want to use the same one.

    if (is_library_loaded("libEGL.so.1", &libegl) ||
        is_library_loaded("libGLX.so.0", &libglx)) {
        libgl = dlopen("libOpenGL.so.0", RTLD_LAZY | RTLD_LOCAL);
        if (libgl)
            return GL3W_OK;
        else
            close_libgl();
    }

    if (is_library_loaded("libGL.so", &libgl))
        return GL3W_OK;
    if (is_library_loaded("libGL.so.1", &libgl))
        return GL3W_OK;
    if (is_library_loaded("libGL.so.3", &libgl))
        return GL3W_OK;

    // Neither is already loaded, so we have to load one.  Try EGL first
    // because it is supported under both X11 and Wayland.

    // Load OpenGL + EGL
    libgl = dlopen("libOpenGL.so.0", RTLD_LAZY | RTLD_LOCAL);
    libegl = dlopen("libEGL.so.1", RTLD_LAZY | RTLD_LOCAL);
    if (libgl && libegl)
        return GL3W_OK;
    else
        close_libgl();

    // Fall back to legacy libGL, which includes GLX
    // While most systems use libGL.so.1, NetBSD seems to use that libGL.so.3. See https://github.com/ocornut/imgui/issues/6983
    libgl = dlopen("libGL.so", RTLD_LAZY | RTLD_LOCAL);
    if (!libgl)
        libgl = dlopen("libGL.so.1", RTLD_LAZY | RTLD_LOCAL);
    if (!libgl)
        libgl = dlopen("libGL.so.3", RTLD_LAZY | RTLD_LOCAL);

    if (libgl)
        return GL3W_OK;

    return GL3W_ERROR_LIBRARY_OPEN;
}

static int open_libgl(void)
{
    int res = open_libs();
    if (res)
        return res;

    if (libegl)
        *(void**)(&gl_get_proc_address) = dlsym(libegl, "eglGetProcAddress");
    else if (libglx)
        *(void**)(&gl_get_proc_address) = dlsym(libglx, "glXGetProcAddressARB");
    else
        *(void**)(&gl_get_proc_address) = dlsym(libgl, "glXGetProcAddressARB");

    if (!gl_get_proc_address) {
        close_libgl();
        return GL3W_ERROR_LIBRARY_OPEN;
    }

    return GL3W_OK;
}

static GL3WglProc get_proc(const char* proc)
{
    GL3WglProc res = NULL;

    // Before EGL version 1.5, eglGetProcAddress doesn't support querying core
    // functions and may return a dummy function if we try, so try to load the
    // function from the GL library directly first.
    if (libegl)
        *(void**)(&res) = dlsym(libgl, proc);

    if (!res)
        res = gl_get_proc_address(proc);

    if (!libegl && !res)
        *(void**)(&res) = dlsym(libgl, proc);

    return res;
}
#endif

static struct { int major, minor; } version;

static int parse_version(void)
{
    if (!glGetIntegerv)
        return GL3W_ERROR_INIT;
    glGetIntegerv(GL_MAJOR_VERSION, &version.major);
    glGetIntegerv(GL_MINOR_VERSION, &version.minor);
    if (version.major == 0 && version.minor == 0)
    {
        // Query GL_VERSION in desktop GL 2.x, the string will start with "<major>.<minor>"
        if (const char* gl_version = (const char*)glGetString(GL_VERSION))
            sscanf(gl_version, "%d.%d", &version.major, &version.minor);
    }
    if (version.major < 2)
        return GL3W_ERROR_OPENGL_VERSION;
    return GL3W_OK;
}

static void load_procs(GL3WGetProcAddressProc proc);

int imgl3wInit(void)
{
    int res = open_libgl();
    if (res)
        return res;
    atexit(close_libgl);
    return imgl3wInit2(get_proc);
}

int imgl3wInit2(GL3WGetProcAddressProc proc)
{
    load_procs(proc);
    return parse_version();
}

int imgl3wIsSupported(int major, int minor)
{
    if (major < 2)
        return 0;
    if (version.major == major)
        return version.minor >= minor;
    return version.major >= major;
}

GL3WglProc imgl3wGetProcAddress(const char *proc) { return get_proc(proc); }

static const char *proc_names[] = {
    "glActiveProgramEXT",
    "glActiveShaderProgram",
    "glActiveTexture",
    "glApplyFramebufferAttachmentCMAAINTEL",
    "glAttachShader",
    "glBeginConditionalRender",
    "glBeginConditionalRenderNV",
    "glBeginPerfMonitorAMD",
    "glBeginPerfQueryINTEL",
    "glBeginQuery",
    "glBeginQueryIndexed",
    "glBeginTransformFeedback",
    "glBindAttribLocation",
    "glBindBuffer",
    "glBindBufferBase",
    "glBindBufferRange",
    "glBindBuffersBase",
    "glBindBuffersRange",
    "glBindFragDataLocation",
    "glBindFragDataLocationIndexed",
    "glBindFramebuffer",
    "glBindImageTexture",
    "glBindImageTextures",
    "glBindMultiTextureEXT",
    "glBindProgramPipeline",
    "glBindRenderbuffer",
    "glBindSampler",
    "glBindSamplers",
    "glBindShadingRateImageNV",
    "glBindTexture",
    "glBindTextureUnit",
    "glBindTextures",
    "glBindTransformFeedback",
    "glBindVertexArray",
    "glBindVertexBuffer",
    "glBindVertexBuffers",
    "glBlendBarrierKHR",
    "glBlendBarrierNV",
    "glBlendColor",
    "glBlendEquation",
    "glBlendEquationSeparate",
    "glBlendEquationSeparatei",
    "glBlendEquationSeparateiARB",
    "glBlendEquationi",
    "glBlendEquationiARB",
    "glBlendFunc",
    "glBlendFuncSeparate",
    "glBlendFuncSeparatei",
    "glBlendFuncSeparateiARB",
    "glBlendFunci",
    "glBlendFunciARB",
    "glBlendParameteriNV",
    "glBlitFramebuffer",
    "glBlitNamedFramebuffer",
    "glBufferAddressRangeNV",
    "glBufferAttachMemoryNV",
    "glBufferData",
    "glBufferPageCommitmentARB",
    "glBufferPageCommitmentMemNV",
    "glBufferStorage",
    "glBufferSubData",
    "glCallCommandListNV",
    "glCheckFramebufferStatus",
    "glCheckNamedFramebufferStatus",
    "glCheckNamedFramebufferStatusEXT",
    "glClampColor",
    "glClear",
    "glClearBufferData",
    "glClearBufferSubData",
    "glClearBufferfi",
    "glClearBufferfv",
    "glClearBufferiv",
    "glClearBufferuiv",
    "glClearColor",
    "glClearDepth",
    "glClearDepthdNV",
    "glClearDepthf",
    "glClearNamedBufferData",
    "glClearNamedBufferDataEXT",
    "glClearNamedBufferSubData",
    "glClearNamedBufferSubDataEXT",
    "glClearNamedFramebufferfi",
    "glClearNamedFramebufferfv",
    "glClearNamedFramebufferiv",
    "glClearNamedFramebufferuiv",
    "glClearStencil",
    "glClearTexImage",
    "glClearTexSubImage",
    "glClientAttribDefaultEXT",
    "glClientWaitSync",
    "glClipControl",
    "glColorFormatNV",
    "glColorMask",
    "glColorMaski",
    "glCommandListSegmentsNV",
    "glCompileCommandListNV",
    "glCompileShader",
    "glCompileShaderIncludeARB",
    "glCompressedMultiTexImage1DEXT",
    "glCompressedMultiTexImage2DEXT",
    "glCompressedMultiTexImage3DEXT",
    "glCompressedMultiTexSubImage1DEXT",
    "glCompressedMultiTexSubImage2DEXT",
    "glCompressedMultiTexSubImage3DEXT",
    "glCompressedTexImage1D",
    "glCompressedTexImage2D",
    "glCompressedTexImage3D",
    "glCompressedTexSubImage1D",
    "glCompressedTexSubImage2D",
    "glCompressedTexSubImage3D",
    "glCompressedTextureImage1DEXT",
    "glCompressedTextureImage2DEXT",
    "glCompressedTextureImage3DEXT",
    "glCompressedTextureSubImage1D",
    "glCompressedTextureSubImage1DEXT",
    "glCompressedTextureSubImage2D",
    "glCompressedTextureSubImage2DEXT",
    "glCompressedTextureSubImage3D",
    "glCompressedTextureSubImage3DEXT",
    "glConservativeRasterParameterfNV",
    "glConservativeRasterParameteriNV",
    "glCopyBufferSubData",
    "glCopyImageSubData",
    "glCopyMultiTexImage1DEXT",
    "glCopyMultiTexImage2DEXT",
    "glCopyMultiTexSubImage1DEXT",
    "glCopyMultiTexSubImage2DEXT",
    "glCopyMultiTexSubImage3DEXT",
    "glCopyNamedBufferSubData",
    "glCopyPathNV",
    "glCopyTexImage1D",
    "glCopyTexImage2D",
    "glCopyTexSubImage1D",
    "glCopyTexSubImage2D",
    "glCopyTexSubImage3D",
    "glCopyTextureImage1DEXT",
    "glCopyTextureImage2DEXT",
    "glCopyTextureSubImage1D",
    "glCopyTextureSubImage1DEXT",
    "glCopyTextureSubImage2D",
    "glCopyTextureSubImage2DEXT",
    "glCopyTextureSubImage3D",
    "glCopyTextureSubImage3DEXT",
    "glCoverFillPathInstancedNV",
    "glCoverFillPathNV",
    "glCoverStrokePathInstancedNV",
    "glCoverStrokePathNV",
    "glCoverageModulationNV",
    "glCoverageModulationTableNV",
    "glCreateBuffers",
    "glCreateCommandListsNV",
    "glCreateFramebuffers",
    "glCreatePerfQueryINTEL",
    "glCreateProgram",
    "glCreateProgramPipelines",
    "glCreateQueries",
    "glCreateRenderbuffers",
    "glCreateSamplers",
    "glCreateShader",
    "glCreateShaderProgramEXT",
    "glCreateShaderProgramv",
    "glCreateStatesNV",
    "glCreateSyncFromCLeventARB",
    "glCreateTextures",
    "glCreateTransformFeedbacks",
    "glCreateVertexArrays",
    "glCullFace",
    "glDebugMessageCallback",
    "glDebugMessageCallbackARB",
    "glDebugMessageControl",
    "glDebugMessageControlARB",
    "glDebugMessageInsert",
    "glDebugMessageInsertARB",
    "glDeleteBuffers",
    "glDeleteCommandListsNV",
    "glDeleteFramebuffers",
    "glDeleteNamedStringARB",
    "glDeletePathsNV",
    "glDeletePerfMonitorsAMD",
    "glDeletePerfQueryINTEL",
    "glDeleteProgram",
    "glDeleteProgramPipelines",
    "glDeleteQueries",
    "glDeleteRenderbuffers",
    "glDeleteSamplers",
    "glDeleteShader",
    "glDeleteStatesNV",
    "glDeleteSync",
    "glDeleteTextures",
    "glDeleteTransformFeedbacks",
    "glDeleteVertexArrays",
    "glDepthBoundsdNV",
    "glDepthFunc",
    "glDepthMask",
    "glDepthRange",
    "glDepthRangeArraydvNV",
    "glDepthRangeArrayv",
    "glDepthRangeIndexed",
    "glDepthRangeIndexeddNV",
    "glDepthRangedNV",
    "glDepthRangef",
    "glDetachShader",
    "glDisable",
    "glDisableClientStateIndexedEXT",
    "glDisableClientStateiEXT",
    "glDisableIndexedEXT",
    "glDisableVertexArrayAttrib",
    "glDisableVertexArrayAttribEXT",
    "glDisableVertexArrayEXT",
    "glDisableVertexAttribArray",
    "glDisablei",
    "glDispatchCompute",
    "glDispatchComputeGroupSizeARB",
    "glDispatchComputeIndirect",
    "glDrawArrays",
    "glDrawArraysIndirect",
    "glDrawArraysInstanced",
    "glDrawArraysInstancedARB",
    "glDrawArraysInstancedBaseInstance",
    "glDrawArraysInstancedEXT",
    "glDrawBuffer",
    "glDrawBuffers",
    "glDrawCommandsAddressNV",
    "glDrawCommandsNV",
    "glDrawCommandsStatesAddressNV",
    "glDrawCommandsStatesNV",
    "glDrawElements",
    "glDrawElementsBaseVertex",
    "glDrawElementsIndirect",
    "glDrawElementsInstanced",
    "glDrawElementsInstancedARB",
    "glDrawElementsInstancedBaseInstance",
    "glDrawElementsInstancedBaseVertex",
    "glDrawElementsInstancedBaseVertexBaseInstance",
    "glDrawElementsInstancedEXT",
    "glDrawMeshTasksIndirectNV",
    "glDrawMeshTasksNV",
    "glDrawRangeElements",
    "glDrawRangeElementsBaseVertex",
    "glDrawTransformFeedback",
    "glDrawTransformFeedbackInstanced",
    "glDrawTransformFeedbackStream",
    "glDrawTransformFeedbackStreamInstanced",
    "glDrawVkImageNV",
    "glEGLImageTargetTexStorageEXT",
    "glEGLImageTargetTextureStorageEXT",
    "glEdgeFlagFormatNV",
    "glEnable",
    "glEnableClientStateIndexedEXT",
    "glEnableClientStateiEXT",
    "glEnableIndexedEXT",
    "glEnableVertexArrayAttrib",
    "glEnableVertexArrayAttribEXT",
    "glEnableVertexArrayEXT",
    "glEnableVertexAttribArray",
    "glEnablei",
    "glEndConditionalRender",
    "glEndConditionalRenderNV",
    "glEndPerfMonitorAMD",
    "glEndPerfQueryINTEL",
    "glEndQuery",
    "glEndQueryIndexed",
    "glEndTransformFeedback",
    "glEvaluateDepthValuesARB",
    "glFenceSync",
    "glFinish",
    "glFlush",
    "glFlushMappedBufferRange",
    "glFlushMappedNamedBufferRange",
    "glFlushMappedNamedBufferRangeEXT",
    "glFogCoordFormatNV",
    "glFragmentCoverageColorNV",
    "glFramebufferDrawBufferEXT",
    "glFramebufferDrawBuffersEXT",
    "glFramebufferFetchBarrierEXT",
    "glFramebufferParameteri",
    "glFramebufferParameteriMESA",
    "glFramebufferReadBufferEXT",
    "glFramebufferRenderbuffer",
    "glFramebufferSampleLocationsfvARB",
    "glFramebufferSampleLocationsfvNV",
    "glFramebufferTexture",
    "glFramebufferTexture1D",
    "glFramebufferTexture2D",
    "glFramebufferTexture3D",
    "glFramebufferTextureARB",
    "glFramebufferTextureFaceARB",
    "glFramebufferTextureLayer",
    "glFramebufferTextureLayerARB",
    "glFramebufferTextureMultiviewOVR",
    "glFrontFace",
    "glGenBuffers",
    "glGenFramebuffers",
    "glGenPathsNV",
    "glGenPerfMonitorsAMD",
    "glGenProgramPipelines",
    "glGenQueries",
    "glGenRenderbuffers",
    "glGenSamplers",
    "glGenTextures",
    "glGenTransformFeedbacks",
    "glGenVertexArrays",
    "glGenerateMipmap",
    "glGenerateMultiTexMipmapEXT",
    "glGenerateTextureMipmap",
    "glGenerateTextureMipmapEXT",
    "glGetActiveAtomicCounterBufferiv",
    "glGetActiveAttrib",
    "glGetActiveSubroutineName",
    "glGetActiveSubroutineUniformName",
    "glGetActiveSubroutineUniformiv",
    "glGetActiveUniform",
    "glGetActiveUniformBlockName",
    "glGetActiveUniformBlockiv",
    "glGetActiveUniformName",
    "glGetActiveUniformsiv",
    "glGetAttachedShaders",
    "glGetAttribLocation",
    "glGetBooleanIndexedvEXT",
    "glGetBooleani_v",
    "glGetBooleanv",
    "glGetBufferParameteri64v",
    "glGetBufferParameteriv",
    "glGetBufferParameterui64vNV",
    "glGetBufferPointerv",
    "glGetBufferSubData",
    "glGetCommandHeaderNV",
    "glGetCompressedMultiTexImageEXT",
    "glGetCompressedTexImage",
    "glGetCompressedTextureImage",
    "glGetCompressedTextureImageEXT",
    "glGetCompressedTextureSubImage",
    "glGetCoverageModulationTableNV",
    "glGetDebugMessageLog",
    "glGetDebugMessageLogARB",
    "glGetDoubleIndexedvEXT",
    "glGetDoublei_v",
    "glGetDoublei_vEXT",
    "glGetDoublev",
    "glGetError",
    "glGetFirstPerfQueryIdINTEL",
    "glGetFloatIndexedvEXT",
    "glGetFloati_v",
    "glGetFloati_vEXT",
    "glGetFloatv",
    "glGetFragDataIndex",
    "glGetFragDataLocation",
    "glGetFramebufferAttachmentParameteriv",
    "glGetFramebufferParameteriv",
    "glGetFramebufferParameterivEXT",
    "glGetFramebufferParameterivMESA",
    "glGetGraphicsResetStatus",
    "glGetGraphicsResetStatusARB",
    "glGetImageHandleARB",
    "glGetImageHandleNV",
    "glGetInteger64i_v",
    "glGetInteger64v",
    "glGetIntegerIndexedvEXT",
    "glGetIntegeri_v",
    "glGetIntegerui64i_vNV",
    "glGetIntegerui64vNV",
    "glGetIntegerv",
    "glGetInternalformatSampleivNV",
    "glGetInternalformati64v",
    "glGetInternalformativ",
    "glGetMemoryObjectDetachedResourcesuivNV",
    "glGetMultiTexEnvfvEXT",
    "glGetMultiTexEnvivEXT",
    "glGetMultiTexGendvEXT",
    "glGetMultiTexGenfvEXT",
    "glGetMultiTexGenivEXT",
    "glGetMultiTexImageEXT",
    "glGetMultiTexLevelParameterfvEXT",
    "glGetMultiTexLevelParameterivEXT",
    "glGetMultiTexParameterIivEXT",
    "glGetMultiTexParameterIuivEXT",
    "glGetMultiTexParameterfvEXT",
    "glGetMultiTexParameterivEXT",
    "glGetMultisamplefv",
    "glGetNamedBufferParameteri64v",
    "glGetNamedBufferParameteriv",
    "glGetNamedBufferParameterivEXT",
    "glGetNamedBufferParameterui64vNV",
    "glGetNamedBufferPointerv",
    "glGetNamedBufferPointervEXT",
    "glGetNamedBufferSubData",
    "glGetNamedBufferSubDataEXT",
    "glGetNamedFramebufferAttachmentParameteriv",
    "glGetNamedFramebufferAttachmentParameterivEXT",
    "glGetNamedFramebufferParameteriv",
    "glGetNamedFramebufferParameterivEXT",
    "glGetNamedProgramLocalParameterIivEXT",
    "glGetNamedProgramLocalParameterIuivEXT",
    "glGetNamedProgramLocalParameterdvEXT",
    "glGetNamedProgramLocalParameterfvEXT",
    "glGetNamedProgramStringEXT",
    "glGetNamedProgramivEXT",
    "glGetNamedRenderbufferParameteriv",
    "glGetNamedRenderbufferParameterivEXT",
    "glGetNamedStringARB",
    "glGetNamedStringivARB",
    "glGetNextPerfQueryIdINTEL",
    "glGetObjectLabel",
    "glGetObjectLabelEXT",
    "glGetObjectPtrLabel",
    "glGetPathCommandsNV",
    "glGetPathCoordsNV",
    "glGetPathDashArrayNV",
    "glGetPathLengthNV",
    "glGetPathMetricRangeNV",
    "glGetPathMetricsNV",
    "glGetPathParameterfvNV",
    "glGetPathParameterivNV",
    "glGetPathSpacingNV",
    "glGetPerfCounterInfoINTEL",
    "glGetPerfMonitorCounterDataAMD",
    "glGetPerfMonitorCounterInfoAMD",
    "glGetPerfMonitorCounterStringAMD",
    "glGetPerfMonitorCountersAMD",
    "glGetPerfMonitorGroupStringAMD",
    "glGetPerfMonitorGroupsAMD",
    "glGetPerfQueryDataINTEL",
    "glGetPerfQueryIdByNameINTEL",
    "glGetPerfQueryInfoINTEL",
    "glGetPointerIndexedvEXT",
    "glGetPointeri_vEXT",
    "glGetPointerv",
    "glGetProgramBinary",
    "glGetProgramInfoLog",
    "glGetProgramInterfaceiv",
    "glGetProgramPipelineInfoLog",
    "glGetProgramPipelineiv",
    "glGetProgramResourceIndex",
    "glGetProgramResourceLocation",
    "glGetProgramResourceLocationIndex",
    "glGetProgramResourceName",
    "glGetProgramResourcefvNV",
    "glGetProgramResourceiv",
    "glGetProgramStageiv",
    "glGetProgramiv",
    "glGetQueryBufferObjecti64v",
    "glGetQueryBufferObjectiv",
    "glGetQueryBufferObjectui64v",
    "glGetQueryBufferObjectuiv",
    "glGetQueryIndexediv",
    "glGetQueryObjecti64v",
    "glGetQueryObjectiv",
    "glGetQueryObjectui64v",
    "glGetQueryObjectuiv",
    "glGetQueryiv",
    "glGetRenderbufferParameteriv",
    "glGetSamplerParameterIiv",
    "glGetSamplerParameterIuiv",
    "glGetSamplerParameterfv",
    "glGetSamplerParameteriv",
    "glGetShaderInfoLog",
    "glGetShaderPrecisionFormat",
    "glGetShaderSource",
    "glGetShaderiv",
    "glGetShadingRateImagePaletteNV",
    "glGetShadingRateSampleLocationivNV",
    "glGetStageIndexNV",
    "glGetString",
    "glGetStringi",
    "glGetSubroutineIndex",
    "glGetSubroutineUniformLocation",
    "glGetSynciv",
    "glGetTexImage",
    "glGetTexLevelParameterfv",
    "glGetTexLevelParameteriv",
    "glGetTexParameterIiv",
    "glGetTexParameterIuiv",
    "glGetTexParameterfv",
    "glGetTexParameteriv",
    "glGetTextureHandleARB",
    "glGetTextureHandleNV",
    "glGetTextureImage",
    "glGetTextureImageEXT",
    "glGetTextureLevelParameterfv",
    "glGetTextureLevelParameterfvEXT",
    "glGetTextureLevelParameteriv",
    "glGetTextureLevelParameterivEXT",
    "glGetTextureParameterIiv",
    "glGetTextureParameterIivEXT",
    "glGetTextureParameterIuiv",
    "glGetTextureParameterIuivEXT",
    "glGetTextureParameterfv",
    "glGetTextureParameterfvEXT",
    "glGetTextureParameteriv",
    "glGetTextureParameterivEXT",
    "glGetTextureSamplerHandleARB",
    "glGetTextureSamplerHandleNV",
    "glGetTextureSubImage",
    "glGetTransformFeedbackVarying",
    "glGetTransformFeedbacki64_v",
    "glGetTransformFeedbacki_v",
    "glGetTransformFeedbackiv",
    "glGetUniformBlockIndex",
    "glGetUniformIndices",
    "glGetUniformLocation",
    "glGetUniformSubroutineuiv",
    "glGetUniformdv",
    "glGetUniformfv",
    "glGetUniformi64vARB",
    "glGetUniformi64vNV",
    "glGetUniformiv",
    "glGetUniformui64vARB",
    "glGetUniformui64vNV",
    "glGetUniformuiv",
    "glGetVertexArrayIndexed64iv",
    "glGetVertexArrayIndexediv",
    "glGetVertexArrayIntegeri_vEXT",
    "glGetVertexArrayIntegervEXT",
    "glGetVertexArrayPointeri_vEXT",
    "glGetVertexArrayPointervEXT",
    "glGetVertexArrayiv",
    "glGetVertexAttribIiv",
    "glGetVertexAttribIuiv",
    "glGetVertexAttribLdv",
    "glGetVertexAttribLi64vNV",
    "glGetVertexAttribLui64vARB",
    "glGetVertexAttribLui64vNV",
    "glGetVertexAttribPointerv",
    "glGetVertexAttribdv",
    "glGetVertexAttribfv",
    "glGetVertexAttribiv",
    "glGetVkProcAddrNV",
    "glGetnCompressedTexImage",
    "glGetnCompressedTexImageARB",
    "glGetnTexImage",
    "glGetnTexImageARB",
    "glGetnUniformdv",
    "glGetnUniformdvARB",
    "glGetnUniformfv",
    "glGetnUniformfvARB",
    "glGetnUniformi64vARB",
    "glGetnUniformiv",
    "glGetnUniformivARB",
    "glGetnUniformui64vARB",
    "glGetnUniformuiv",
    "glGetnUniformuivARB",
    "glHint",
    "glIndexFormatNV",
    "glInsertEventMarkerEXT",
    "glInterpolatePathsNV",
    "glInvalidateBufferData",
    "glInvalidateBufferSubData",
    "glInvalidateFramebuffer",
    "glInvalidateNamedFramebufferData",
    "glInvalidateNamedFramebufferSubData",
    "glInvalidateSubFramebuffer",
    "glInvalidateTexImage",
    "glInvalidateTexSubImage",
    "glIsBuffer",
    "glIsBufferResidentNV",
    "glIsCommandListNV",
    "glIsEnabled",
    "glIsEnabledIndexedEXT",
    "glIsEnabledi",
    "glIsFramebuffer",
    "glIsImageHandleResidentARB",
    "glIsImageHandleResidentNV",
    "glIsNamedBufferResidentNV",
    "glIsNamedStringARB",
    "glIsPathNV",
    "glIsPointInFillPathNV",
    "glIsPointInStrokePathNV",
    "glIsProgram",
    "glIsProgramPipeline",
    "glIsQuery",
    "glIsRenderbuffer",
    "glIsSampler",
    "glIsShader",
    "glIsStateNV",
    "glIsSync",
    "glIsTexture",
    "glIsTextureHandleResidentARB",
    "glIsTextureHandleResidentNV",
    "glIsTransformFeedback",
    "glIsVertexArray",
    "glLabelObjectEXT",
    "glLineWidth",
    "glLinkProgram",
    "glListDrawCommandsStatesClientNV",
    "glLogicOp",
    "glMakeBufferNonResidentNV",
    "glMakeBufferResidentNV",
    "glMakeImageHandleNonResidentARB",
    "glMakeImageHandleNonResidentNV",
    "glMakeImageHandleResidentARB",
    "glMakeImageHandleResidentNV",
    "glMakeNamedBufferNonResidentNV",
    "glMakeNamedBufferResidentNV",
    "glMakeTextureHandleNonResidentARB",
    "glMakeTextureHandleNonResidentNV",
    "glMakeTextureHandleResidentARB",
    "glMakeTextureHandleResidentNV",
    "glMapBuffer",
    "glMapBufferRange",
    "glMapNamedBuffer",
    "glMapNamedBufferEXT",
    "glMapNamedBufferRange",
    "glMapNamedBufferRangeEXT",
    "glMatrixFrustumEXT",
    "glMatrixLoad3x2fNV",
    "glMatrixLoad3x3fNV",
    "glMatrixLoadIdentityEXT",
    "glMatrixLoadTranspose3x3fNV",
    "glMatrixLoadTransposedEXT",
    "glMatrixLoadTransposefEXT",
    "glMatrixLoaddEXT",
    "glMatrixLoadfEXT",
    "glMatrixMult3x2fNV",
    "glMatrixMult3x3fNV",
    "glMatrixMultTranspose3x3fNV",
    "glMatrixMultTransposedEXT",
    "glMatrixMultTransposefEXT",
    "glMatrixMultdEXT",
    "glMatrixMultfEXT",
    "glMatrixOrthoEXT",
    "glMatrixPopEXT",
    "glMatrixPushEXT",
    "glMatrixRotatedEXT",
    "glMatrixRotatefEXT",
    "glMatrixScaledEXT",
    "glMatrixScalefEXT",
    "glMatrixTranslatedEXT",
    "glMatrixTranslatefEXT",
    "glMaxShaderCompilerThreadsARB",
    "glMaxShaderCompilerThreadsKHR",
    "glMemoryBarrier",
    "glMemoryBarrierByRegion",
    "glMinSampleShading",
    "glMinSampleShadingARB",
    "glMultiDrawArrays",
    "glMultiDrawArraysIndirect",
    "glMultiDrawArraysIndirectBindlessCountNV",
    "glMultiDrawArraysIndirectBindlessNV",
    "glMultiDrawArraysIndirectCount",
    "glMultiDrawArraysIndirectCountARB",
    "glMultiDrawElements",
    "glMultiDrawElementsBaseVertex",
    "glMultiDrawElementsIndirect",
    "glMultiDrawElementsIndirectBindlessCountNV",
    "glMultiDrawElementsIndirectBindlessNV",
    "glMultiDrawElementsIndirectCount",
    "glMultiDrawElementsIndirectCountARB",
    "glMultiDrawMeshTasksIndirectCountNV",
    "glMultiDrawMeshTasksIndirectNV",
    "glMultiTexBufferEXT",
    "glMultiTexCoordPointerEXT",
    "glMultiTexEnvfEXT",
    "glMultiTexEnvfvEXT",
    "glMultiTexEnviEXT",
    "glMultiTexEnvivEXT",
    "glMultiTexGendEXT",
    "glMultiTexGendvEXT",
    "glMultiTexGenfEXT",
    "glMultiTexGenfvEXT",
    "glMultiTexGeniEXT",
    "glMultiTexGenivEXT",
    "glMultiTexImage1DEXT",
    "glMultiTexImage2DEXT",
    "glMultiTexImage3DEXT",
    "glMultiTexParameterIivEXT",
    "glMultiTexParameterIuivEXT",
    "glMultiTexParameterfEXT",
    "glMultiTexParameterfvEXT",
    "glMultiTexParameteriEXT",
    "glMultiTexParameterivEXT",
    "glMultiTexRenderbufferEXT",
    "glMultiTexSubImage1DEXT",
    "glMultiTexSubImage2DEXT",
    "glMultiTexSubImage3DEXT",
    "glNamedBufferAttachMemoryNV",
    "glNamedBufferData",
    "glNamedBufferDataEXT",
    "glNamedBufferPageCommitmentARB",
    "glNamedBufferPageCommitmentEXT",
    "glNamedBufferPageCommitmentMemNV",
    "glNamedBufferStorage",
    "glNamedBufferStorageEXT",
    "glNamedBufferSubData",
    "glNamedBufferSubDataEXT",
    "glNamedCopyBufferSubDataEXT",
    "glNamedFramebufferDrawBuffer",
    "glNamedFramebufferDrawBuffers",
    "glNamedFramebufferParameteri",
    "glNamedFramebufferParameteriEXT",
    "glNamedFramebufferReadBuffer",
    "glNamedFramebufferRenderbuffer",
    "glNamedFramebufferRenderbufferEXT",
    "glNamedFramebufferSampleLocationsfvARB",
    "glNamedFramebufferSampleLocationsfvNV",
    "glNamedFramebufferTexture",
    "glNamedFramebufferTexture1DEXT",
    "glNamedFramebufferTexture2DEXT",
    "glNamedFramebufferTexture3DEXT",
    "glNamedFramebufferTextureEXT",
    "glNamedFramebufferTextureFaceEXT",
    "glNamedFramebufferTextureLayer",
    "glNamedFramebufferTextureLayerEXT",
    "glNamedFramebufferTextureMultiviewOVR",
    "glNamedProgramLocalParameter4dEXT",
    "glNamedProgramLocalParameter4dvEXT",
    "glNamedProgramLocalParameter4fEXT",
    "glNamedProgramLocalParameter4fvEXT",
    "glNamedProgramLocalParameterI4iEXT",
    "glNamedProgramLocalParameterI4ivEXT",
    "glNamedProgramLocalParameterI4uiEXT",
    "glNamedProgramLocalParameterI4uivEXT",
    "glNamedProgramLocalParameters4fvEXT",
    "glNamedProgramLocalParametersI4ivEXT",
    "glNamedProgramLocalParametersI4uivEXT",
    "glNamedProgramStringEXT",
    "glNamedRenderbufferStorage",
    "glNamedRenderbufferStorageEXT",
    "glNamedRenderbufferStorageMultisample",
    "glNamedRenderbufferStorageMultisampleAdvancedAMD",
    "glNamedRenderbufferStorageMultisampleCoverageEXT",
    "glNamedRenderbufferStorageMultisampleEXT",
    "glNamedStringARB",
    "glNormalFormatNV",
    "glObjectLabel",
    "glObjectPtrLabel",
    "glPatchParameterfv",
    "glPatchParameteri",
    "glPathCommandsNV",
    "glPathCoordsNV",
    "glPathCoverDepthFuncNV",
    "glPathDashArrayNV",
    "glPathGlyphIndexArrayNV",
    "glPathGlyphIndexRangeNV",
    "glPathGlyphRangeNV",
    "glPathGlyphsNV",
    "glPathMemoryGlyphIndexArrayNV",
    "glPathParameterfNV",
    "glPathParameterfvNV",
    "glPathParameteriNV",
    "glPathParameterivNV",
    "glPathStencilDepthOffsetNV",
    "glPathStencilFuncNV",
    "glPathStringNV",
    "glPathSubCommandsNV",
    "glPathSubCoordsNV",
    "glPauseTransformFeedback",
    "glPixelStoref",
    "glPixelStorei",
    "glPointAlongPathNV",
    "glPointParameterf",
    "glPointParameterfv",
    "glPointParameteri",
    "glPointParameteriv",
    "glPointSize",
    "glPolygonMode",
    "glPolygonOffset",
    "glPolygonOffsetClamp",
    "glPolygonOffsetClampEXT",
    "glPopDebugGroup",
    "glPopGroupMarkerEXT",
    "glPrimitiveBoundingBoxARB",
    "glPrimitiveRestartIndex",
    "glProgramBinary",
    "glProgramParameteri",
    "glProgramParameteriARB",
    "glProgramPathFragmentInputGenNV",
    "glProgramUniform1d",
    "glProgramUniform1dEXT",
    "glProgramUniform1dv",
    "glProgramUniform1dvEXT",
    "glProgramUniform1f",
    "glProgramUniform1fEXT",
    "glProgramUniform1fv",
    "glProgramUniform1fvEXT",
    "glProgramUniform1i",
    "glProgramUniform1i64ARB",
    "glProgramUniform1i64NV",
    "glProgramUniform1i64vARB",
    "glProgramUniform1i64vNV",
    "glProgramUniform1iEXT",
    "glProgramUniform1iv",
    "glProgramUniform1ivEXT",
    "glProgramUniform1ui",
    "glProgramUniform1ui64ARB",
    "glProgramUniform1ui64NV",
    "glProgramUniform1ui64vARB",
    "glProgramUniform1ui64vNV",
    "glProgramUniform1uiEXT",
    "glProgramUniform1uiv",
    "glProgramUniform1uivEXT",
    "glProgramUniform2d",
    "glProgramUniform2dEXT",
    "glProgramUniform2dv",
    "glProgramUniform2dvEXT",
    "glProgramUniform2f",
    "glProgramUniform2fEXT",
    "glProgramUniform2fv",
    "glProgramUniform2fvEXT",
    "glProgramUniform2i",
    "glProgramUniform2i64ARB",
    "glProgramUniform2i64NV",
    "glProgramUniform2i64vARB",
    "glProgramUniform2i64vNV",
    "glProgramUniform2iEXT",
    "glProgramUniform2iv",
    "glProgramUniform2ivEXT",
    "glProgramUniform2ui",
    "glProgramUniform2ui64ARB",
    "glProgramUniform2ui64NV",
    "glProgramUniform2ui64vARB",
    "glProgramUniform2ui64vNV",
    "glProgramUniform2uiEXT",
    "glProgramUniform2uiv",
    "glProgramUniform2uivEXT",
    "glProgramUniform3d",
    "glProgramUniform3dEXT",
    "glProgramUniform3dv",
    "glProgramUniform3dvEXT",
    "glProgramUniform3f",
    "glProgramUniform3fEXT",
    "glProgramUniform3fv",
    "glProgramUniform3fvEXT",
    "glProgramUniform3i",
    "glProgramUniform3i64ARB",
    "glProgramUniform3i64NV",
    "glProgramUniform3i64vARB",
    "glProgramUniform3i64vNV",
    "glProgramUniform3iEXT",
    "glProgramUniform3iv",
    "glProgramUniform3ivEXT",
    "glProgramUniform3ui",
    "glProgramUniform3ui64ARB",
    "glProgramUniform3ui64NV",
    "glProgramUniform3ui64vARB",
    "glProgramUniform3ui64vNV",
    "glProgramUniform3uiEXT",
    "glProgramUniform3uiv",
    "glProgramUniform3uivEXT",
    "glProgramUniform4d",
    "glProgramUniform4dEXT",
    "glProgramUniform4dv",
    "glProgramUniform4dvEXT",
    "glProgramUniform4f",
    "glProgramUniform4fEXT",
    "glProgramUniform4fv",
    "glProgramUniform4fvEXT",
    "glProgramUniform4i",
    "glProgramUniform4i64ARB",
    "glProgramUniform4i64NV",
    "glProgramUniform4i64vARB",
    "glProgramUniform4i64vNV",
    "glProgramUniform4iEXT",
    "glProgramUniform4iv",
    "glProgramUniform4ivEXT",
    "glProgramUniform4ui",
    "glProgramUniform4ui64ARB",
    "glProgramUniform4ui64NV",
    "glProgramUniform4ui64vARB",
    "glProgramUniform4ui64vNV",
    "glProgramUniform4uiEXT",
    "glProgramUniform4uiv",
    "glProgramUniform4uivEXT",
    "glProgramUniformHandleui64ARB",
    "glProgramUniformHandleui64NV",
    "glProgramUniformHandleui64vARB",
    "glProgramUniformHandleui64vNV",
    "glProgramUniformMatrix2dv",
    "glProgramUniformMatrix2dvEXT",
    "glProgramUniformMatrix2fv",
    "glProgramUniformMatrix2fvEXT",
    "glProgramUniformMatrix2x3dv",
    "glProgramUniformMatrix2x3dvEXT",
    "glProgramUniformMatrix2x3fv",
    "glProgramUniformMatrix2x3fvEXT",
    "glProgramUniformMatrix2x4dv",
    "glProgramUniformMatrix2x4dvEXT",
    "glProgramUniformMatrix2x4fv",
    "glProgramUniformMatrix2x4fvEXT",
    "glProgramUniformMatrix3dv",
    "glProgramUniformMatrix3dvEXT",
    "glProgramUniformMatrix3fv",
    "glProgramUniformMatrix3fvEXT",
    "glProgramUniformMatrix3x2dv",
    "glProgramUniformMatrix3x2dvEXT",
    "glProgramUniformMatrix3x2fv",
    "glProgramUniformMatrix3x2fvEXT",
    "glProgramUniformMatrix3x4dv",
    "glProgramUniformMatrix3x4dvEXT",
    "glProgramUniformMatrix3x4fv",
    "glProgramUniformMatrix3x4fvEXT",
    "glProgramUniformMatrix4dv",
    "glProgramUniformMatrix4dvEXT",
    "glProgramUniformMatrix4fv",
    "glProgramUniformMatrix4fvEXT",
    "glProgramUniformMatrix4x2dv",
    "glProgramUniformMatrix4x2dvEXT",
    "glProgramUniformMatrix4x2fv",
    "glProgramUniformMatrix4x2fvEXT",
    "glProgramUniformMatrix4x3dv",
    "glProgramUniformMatrix4x3dvEXT",
    "glProgramUniformMatrix4x3fv",
    "glProgramUniformMatrix4x3fvEXT",
    "glProgramUniformui64NV",
    "glProgramUniformui64vNV",
    "glProvokingVertex",
    "glPushClientAttribDefaultEXT",
    "glPushDebugGroup",
    "glPushGroupMarkerEXT",
    "glQueryCounter",
    "glRasterSamplesEXT",
    "glReadBuffer",
    "glReadPixels",
    "glReadnPixels",
    "glReadnPixelsARB",
    "glReleaseShaderCompiler",
    "glRenderbufferStorage",
    "glRenderbufferStorageMultisample",
    "glRenderbufferStorageMultisampleAdvancedAMD",
    "glRenderbufferStorageMultisampleCoverageNV",
    "glResetMemoryObjectParameterNV",
    "glResolveDepthValuesNV",
    "glResumeTransformFeedback",
    "glSampleCoverage",
    "glSampleMaski",
    "glSamplerParameterIiv",
    "glSamplerParameterIuiv",
    "glSamplerParameterf",
    "glSamplerParameterfv",
    "glSamplerParameteri",
    "glSamplerParameteriv",
    "glScissor",
    "glScissorArrayv",
    "glScissorExclusiveArrayvNV",
    "glScissorExclusiveNV",
    "glScissorIndexed",
    "glScissorIndexedv",
    "glSecondaryColorFormatNV",
    "glSelectPerfMonitorCountersAMD",
    "glShaderBinary",
    "glShaderSource",
    "glShaderStorageBlockBinding",
    "glShadingRateImageBarrierNV",
    "glShadingRateImagePaletteNV",
    "glShadingRateSampleOrderCustomNV",
    "glShadingRateSampleOrderNV",
    "glSignalVkFenceNV",
    "glSignalVkSemaphoreNV",
    "glSpecializeShader",
    "glSpecializeShaderARB",
    "glStateCaptureNV",
    "glStencilFillPathInstancedNV",
    "glStencilFillPathNV",
    "glStencilFunc",
    "glStencilFuncSeparate",
    "glStencilMask",
    "glStencilMaskSeparate",
    "glStencilOp",
    "glStencilOpSeparate",
    "glStencilStrokePathInstancedNV",
    "glStencilStrokePathNV",
    "glStencilThenCoverFillPathInstancedNV",
    "glStencilThenCoverFillPathNV",
    "glStencilThenCoverStrokePathInstancedNV",
    "glStencilThenCoverStrokePathNV",
    "glSubpixelPrecisionBiasNV",
    "glTexAttachMemoryNV",
    "glTexBuffer",
    "glTexBufferARB",
    "glTexBufferRange",
    "glTexCoordFormatNV",
    "glTexImage1D",
    "glTexImage2D",
    "glTexImage2DMultisample",
    "glTexImage3D",
    "glTexImage3DMultisample",
    "glTexPageCommitmentARB",
    "glTexPageCommitmentMemNV",
    "glTexParameterIiv",
    "glTexParameterIuiv",
    "glTexParameterf",
    "glTexParameterfv",
    "glTexParameteri",
    "glTexParameteriv",
    "glTexStorage1D",
    "glTexStorage1DEXT",
    "glTexStorage2D",
    "glTexStorage2DEXT",
    "glTexStorage2DMultisample",
    "glTexStorage3D",
    "glTexStorage3DEXT",
    "glTexStorage3DMultisample",
    "glTexSubImage1D",
    "glTexSubImage2D",
    "glTexSubImage3D",
    "glTextureAttachMemoryNV",
    "glTextureBarrier",
    "glTextureBarrierNV",
    "glTextureBuffer",
    "glTextureBufferEXT",
    "glTextureBufferRange",
    "glTextureBufferRangeEXT",
    "glTextureImage1DEXT",
    "glTextureImage2DEXT",
    "glTextureImage3DEXT",
    "glTexturePageCommitmentEXT",
    "glTexturePageCommitmentMemNV",
    "glTextureParameterIiv",
    "glTextureParameterIivEXT",
    "glTextureParameterIuiv",
    "glTextureParameterIuivEXT",
    "glTextureParameterf",
    "glTextureParameterfEXT",
    "glTextureParameterfv",
    "glTextureParameterfvEXT",
    "glTextureParameteri",
    "glTextureParameteriEXT",
    "glTextureParameteriv",
    "glTextureParameterivEXT",
    "glTextureRenderbufferEXT",
    "glTextureStorage1D",
    "glTextureStorage1DEXT",
    "glTextureStorage2D",
    "glTextureStorage2DEXT",
    "glTextureStorage2DMultisample",
    "glTextureStorage2DMultisampleEXT",
    "glTextureStorage3D",
    "glTextureStorage3DEXT",
    "glTextureStorage3DMultisample",
    "glTextureStorage3DMultisampleEXT",
    "glTextureSubImage1D",
    "glTextureSubImage1DEXT",
    "glTextureSubImage2D",
    "glTextureSubImage2DEXT",
    "glTextureSubImage3D",
    "glTextureSubImage3DEXT",
    "glTextureView",
    "glTransformFeedbackBufferBase",
    "glTransformFeedbackBufferRange",
    "glTransformFeedbackVaryings",
    "glTransformPathNV",
    "glUniform1d",
    "glUniform1dv",
    "glUniform1f",
    "glUniform1fv",
    "glUniform1i",
    "glUniform1i64ARB",
    "glUniform1i64NV",
    "glUniform1i64vARB",
    "glUniform1i64vNV",
    "glUniform1iv",
    "glUniform1ui",
    "glUniform1ui64ARB",
    "glUniform1ui64NV",
    "glUniform1ui64vARB",
    "glUniform1ui64vNV",
    "glUniform1uiv",
    "glUniform2d",
    "glUniform2dv",
    "glUniform2f",
    "glUniform2fv",
    "glUniform2i",
    "glUniform2i64ARB",
    "glUniform2i64NV",
    "glUniform2i64vARB",
    "glUniform2i64vNV",
    "glUniform2iv",
    "glUniform2ui",
    "glUniform2ui64ARB",
    "glUniform2ui64NV",
    "glUniform2ui64vARB",
    "glUniform2ui64vNV",
    "glUniform2uiv",
    "glUniform3d",
    "glUniform3dv",
    "glUniform3f",
    "glUniform3fv",
    "glUniform3i",
    "glUniform3i64ARB",
    "glUniform3i64NV",
    "glUniform3i64vARB",
    "glUniform3i64vNV",
    "glUniform3iv",
    "glUniform3ui",
    "glUniform3ui64ARB",
    "glUniform3ui64NV",
    "glUniform3ui64vARB",
    "glUniform3ui64vNV",
    "glUniform3uiv",
    "glUniform4d",
    "glUniform4dv",
    "glUniform4f",
    "glUniform4fv",
    "glUniform4i",
    "glUniform4i64ARB",
    "glUniform4i64NV",
    "glUniform4i64vARB",
    "glUniform4i64vNV",
    "glUniform4iv",
    "glUniform4ui",
    "glUniform4ui64ARB",
    "glUniform4ui64NV",
    "glUniform4ui64vARB",
    "glUniform4ui64vNV",
    "glUniform4uiv",
    "glUniformBlockBinding",
    "glUniformHandleui64ARB",
    "glUniformHandleui64NV",
    "glUniformHandleui64vARB",
    "glUniformHandleui64vNV",
    "glUniformMatrix2dv",
    "glUniformMatrix2fv",
    "glUniformMatrix2x3dv",
    "glUniformMatrix2x3fv",
    "glUniformMatrix2x4dv",
    "glUniformMatrix2x4fv",
    "glUniformMatrix3dv",
    "glUniformMatrix3fv",
    "glUniformMatrix3x2dv",
    "glUniformMatrix3x2fv",
    "glUniformMatrix3x4dv",
    "glUniformMatrix3x4fv",
    "glUniformMatrix4dv",
    "glUniformMatrix4fv",
    "glUniformMatrix4x2dv",
    "glUniformMatrix4x2fv",
    "glUniformMatrix4x3dv",
    "glUniformMatrix4x3fv",
    "glUniformSubroutinesuiv",
    "glUniformui64NV",
    "glUniformui64vNV",
    "glUnmapBuffer",
    "glUnmapNamedBuffer",
    "glUnmapNamedBufferEXT",
    "glUseProgram",
    "glUseProgramStages",
    "glUseShaderProgramEXT",
    "glValidateProgram",
    "glValidateProgramPipeline",
    "glVertexArrayAttribBinding",
    "glVertexArrayAttribFormat",
    "glVertexArrayAttribIFormat",
    "glVertexArrayAttribLFormat",
    "glVertexArrayBindVertexBufferEXT",
    "glVertexArrayBindingDivisor",
    "glVertexArrayColorOffsetEXT",
    "glVertexArrayEdgeFlagOffsetEXT",
    "glVertexArrayElementBuffer",
    "glVertexArrayFogCoordOffsetEXT",
    "glVertexArrayIndexOffsetEXT",
    "glVertexArrayMultiTexCoordOffsetEXT",
    "glVertexArrayNormalOffsetEXT",
    "glVertexArraySecondaryColorOffsetEXT",
    "glVertexArrayTexCoordOffsetEXT",
    "glVertexArrayVertexAttribBindingEXT",
    "glVertexArrayVertexAttribDivisorEXT",
    "glVertexArrayVertexAttribFormatEXT",
    "glVertexArrayVertexAttribIFormatEXT",
    "glVertexArrayVertexAttribIOffsetEXT",
    "glVertexArrayVertexAttribLFormatEXT",
    "glVertexArrayVertexAttribLOffsetEXT",
    "glVertexArrayVertexAttribOffsetEXT",
    "glVertexArrayVertexBindingDivisorEXT",
    "glVertexArrayVertexBuffer",
    "glVertexArrayVertexBuffers",
    "glVertexArrayVertexOffsetEXT",
    "glVertexAttrib1d",
    "glVertexAttrib1dv",
    "glVertexAttrib1f",
    "glVertexAttrib1fv",
    "glVertexAttrib1s",
    "glVertexAttrib1sv",
    "glVertexAttrib2d",
    "glVertexAttrib2dv",
    "glVertexAttrib2f",
    "glVertexAttrib2fv",
    "glVertexAttrib2s",
    "glVertexAttrib2sv",
    "glVertexAttrib3d",
    "glVertexAttrib3dv",
    "glVertexAttrib3f",
    "glVertexAttrib3fv",
    "glVertexAttrib3s",
    "glVertexAttrib3sv",
    "glVertexAttrib4Nbv",
    "glVertexAttrib4Niv",
    "glVertexAttrib4Nsv",
    "glVertexAttrib4Nub",
    "glVertexAttrib4Nubv",
    "glVertexAttrib4Nuiv",
    "glVertexAttrib4Nusv",
    "glVertexAttrib4bv",
    "glVertexAttrib4d",
    "glVertexAttrib4dv",
    "glVertexAttrib4f",
    "glVertexAttrib4fv",
    "glVertexAttrib4iv",
    "glVertexAttrib4s",
    "glVertexAttrib4sv",
    "glVertexAttrib4ubv",
    "glVertexAttrib4uiv",
    "glVertexAttrib4usv",
    "glVertexAttribBinding",
    "glVertexAttribDivisor",
    "glVertexAttribDivisorARB",
    "glVertexAttribFormat",
    "glVertexAttribFormatNV",
    "glVertexAttribI1i",
    "glVertexAttribI1iv",
    "glVertexAttribI1ui",
    "glVertexAttribI1uiv",
    "glVertexAttribI2i",
    "glVertexAttribI2iv",
    "glVertexAttribI2ui",
    "glVertexAttribI2uiv",
    "glVertexAttribI3i",
    "glVertexAttribI3iv",
    "glVertexAttribI3ui",
    "glVertexAttribI3uiv",
    "glVertexAttribI4bv",
    "glVertexAttribI4i",
    "glVertexAttribI4iv",
    "glVertexAttribI4sv",
    "glVertexAttribI4ubv",
    "glVertexAttribI4ui",
    "glVertexAttribI4uiv",
    "glVertexAttribI4usv",
    "glVertexAttribIFormat",
    "glVertexAttribIFormatNV",
    "glVertexAttribIPointer",
    "glVertexAttribL1d",
    "glVertexAttribL1dv",
    "glVertexAttribL1i64NV",
    "glVertexAttribL1i64vNV",
    "glVertexAttribL1ui64ARB",
    "glVertexAttribL1ui64NV",
    "glVertexAttribL1ui64vARB",
    "glVertexAttribL1ui64vNV",
    "glVertexAttribL2d",
    "glVertexAttribL2dv",
    "glVertexAttribL2i64NV",
    "glVertexAttribL2i64vNV",
    "glVertexAttribL2ui64NV",
    "glVertexAttribL2ui64vNV",
    "glVertexAttribL3d",
    "glVertexAttribL3dv",
    "glVertexAttribL3i64NV",
    "glVertexAttribL3i64vNV",
    "glVertexAttribL3ui64NV",
    "glVertexAttribL3ui64vNV",
    "glVertexAttribL4d",
    "glVertexAttribL4dv",
    "glVertexAttribL4i64NV",
    "glVertexAttribL4i64vNV",
    "glVertexAttribL4ui64NV",
    "glVertexAttribL4ui64vNV",
    "glVertexAttribLFormat",
    "glVertexAttribLFormatNV",
    "glVertexAttribLPointer",
    "glVertexAttribP1ui",
    "glVertexAttribP1uiv",
    "glVertexAttribP2ui",
    "glVertexAttribP2uiv",
    "glVertexAttribP3ui",
    "glVertexAttribP3uiv",
    "glVertexAttribP4ui",
    "glVertexAttribP4uiv",
    "glVertexAttribPointer",
    "glVertexBindingDivisor",
    "glVertexFormatNV",
    "glViewport",
    "glViewportArrayv",
    "glViewportIndexedf",
    "glViewportIndexedfv",
    "glViewportPositionWScaleNV",
    "glViewportSwizzleNV",
    "glWaitSync",
    "glWaitVkSemaphoreNV",
    "glWeightPathsNV",
    "glWindowRectanglesEXT",
};

GL3W_API union ImGL3WProcs imgl3wProcs;

static void load_procs(GL3WGetProcAddressProc proc)
{
    size_t i;
    for (i = 0; i < GL3W_ARRAY_SIZE(proc_names); i++)
        imgl3wProcs.ptr[i] = proc(proc_names[i]);
}

#ifdef __cplusplus
}
#endif
#endif
