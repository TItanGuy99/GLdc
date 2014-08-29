/* KallistiGL for KallistiOS ##version##

   libgl/gl.h
   Copyright (C) 2013-2014 Josh "PH3NOM" Pearson
   Copyright (C) 2014 Lawrence Sebald

   Some functionality adapted from the original KOS libgl:
   Copyright (C) 2001 Dan Potter
   Copyright (C) 2002 Benoit Miller

   This API implements much but not all of the OpenGL 1.1 for KallistiOS.
*/

#ifndef __GL_GL_H
#define __GL_GL_H

#include <sys/cdefs.h>
__BEGIN_DECLS

#include <math.h>

#include <dc/fmath.h>
#include <dc/matrix.h>
#include <dc/matrix3d.h>
#include <dc/pvr.h>
#include <dc/vec3f.h>
#include <dc/video.h>

/* Primitive Types taken from GL for compatability */
/* Not all types are implemented in Open GL DC V.1.0 */
#define GL_POINTS           0x01
#define GL_LINES            0x02
#define GL_LINE_LOOP        0x03
#define GL_LINE_STRIP       0x04
#define GL_TRIANGLES        0x05
#define GL_TRIANGLE_STRIP   0x06
#define GL_TRIANGLE_FAN     0x07
#define GL_QUADS            0x08
#define GL_QUAD_STRIP       0x09
#define GL_POLYGON          0x0A

/* FrontFaceDirection */
#define GL_CW               0x0900
#define GL_CCW              0x0901

#define GL_FRONT            0x0404
#define GL_BACK             0x0405
#define GL_FRONT_AND_BACK   0x0408
#define GL_CULL_FACE        0x0B44
#define GL_CULL_FACE_MODE   0x0B45
#define GL_FRONT_FACE       0x0B46

/* Scissor box */
#define GL_SCISSOR_TEST     0x0008      /* capability bit */
#define GL_SCISSOR_BOX      0x0C10

/* Matrix modes */
#define GL_MATRIX_MODE      0x0BA0
#define GL_SCREENVIEW       0x00
#define GL_MODELVIEW        0x01
#define GL_PROJECTION       0x02
#define GL_TEXTURE          0x03
#define GL_IDENTITY         0x04
#define GL_RENDER           0x05
#define GL_MATRIX_COUNT     0x06

#define GL_MODELVIEW_MATRIX   0x0BA6
#define GL_PROJECTION_MATRIX  0x0BA7
#define GL_TEXTURE_MATRIX     0x0BA8

/* Depth buffer */
#define GL_NEVER              0x0200
#define GL_LESS               0x0201
#define GL_EQUAL              0x0202
#define GL_LEQUAL             0x0203
#define GL_GREATER            0x0204
#define GL_NOTEQUAL           0x0205
#define GL_GEQUAL             0x0206
#define GL_ALWAYS             0x0207
#define GL_DEPTH_TEST         0x0B71
#define GL_DEPTH_BITS         0x0D56
#define GL_DEPTH_CLEAR_VALUE  0x0B73
#define GL_DEPTH_FUNC         0x0B74
#define GL_DEPTH_RANGE        0x0B70
#define GL_DEPTH_WRITEMASK    0x0B72
#define GL_DEPTH_COMPONENT    0x1902

/* Blending: Simply Need to Map GL constants to PVR constants */
#define GL_BLEND                0x0BE2 /* capability bit */
#define GL_BLEND_DST            0x0BE0
#define GL_BLEND_SRC            0x0BE1

#define GL_ZERO                    0x0
#define GL_ONE                     0x1
#define GL_SRC_COLOR            0x0300
#define GL_ONE_MINUS_SRC_COLOR  0x0301
#define GL_SRC_ALPHA            0x0302
#define GL_ONE_MINUS_SRC_ALPHA  0x0303
#define GL_DST_ALPHA            0x0304
#define GL_ONE_MINUS_DST_ALPHA  0x0305
#define GL_DST_COLOR            0x0306
#define GL_ONE_MINUS_DST_COLOR  0x0307
#define GL_SRC_ALPHA_SATURATE   0x0308

/* Misc texture constants */
#define GL_TEXTURE_2D           0x0001      /* capability bit */
#define GL_TEXTURE_WRAP_S       0x2802
#define GL_TEXTURE_WRAP_T       0x2803
#define GL_TEXTURE_MAG_FILTER   0x2800
#define GL_TEXTURE_MIN_FILTER   0x2801
#define GL_TEXTURE_FILTER       GL_TEXTURE_MIN_FILTER
#define GL_FILTER_NONE             0x0
#define GL_FILTER_BILINEAR         0x1
#define GL_REPEAT               0x2901
#define GL_CLAMP                0x2900

/* Texture Environment */
#define GL_TEXTURE_ENV_MODE 0x2200
#define GL_REPLACE          0x0
#define GL_MODULATE         0x1
#define GL_DECAL            0x2
#define GL_MODULATEALPHA    0x3

/* TextureMagFilter */
#define GL_NEAREST                      0x2600
#define GL_LINEAR                       0x2601

/* Texture mapping */
#define GL_TEXTURE_ENV                  0x2300
#define GL_TEXTURE_ENV_COLOR            0x2201
#define GL_NEAREST_MIPMAP_NEAREST       0x2700
#define GL_NEAREST_MIPMAP_LINEAR        0x2702
#define GL_LINEAR_MIPMAP_NEAREST        0x2701
#define GL_LINEAR_MIPMAP_LINEAR         0x2703

#define GL_MAX_TEXTURE_UNITS 0x2 /* 0 = Opaque, 1 = Translucent / Blended */

#define GL_TEXTURE_BINDING_2D             0x8069

/* TextureUnit */
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
#define GL_CLIENT_ACTIVE_TEXTURE          0x84E1

#define GL_CURRENT_BIT                          0x00000001
#define GL_POINT_BIT                            0x00000002
#define GL_LINE_BIT                             0x00000004
#define GL_POLYGON_BIT                          0x00000008
#define GL_POLYGON_STIPPLE_BIT                  0x00000010
#define GL_PIXEL_MODE_BIT                       0x00000020
#define GL_LIGHTING_BIT                         0x00000040
#define GL_FOG_BIT                              0x00000080
#define GL_DEPTH_BUFFER_BIT                     0x00000100
#define GL_ACCUM_BUFFER_BIT                     0x00000200
#define GL_STENCIL_BUFFER_BIT                   0x00000400
#define GL_VIEWPORT_BIT                         0x00000800
#define GL_TRANSFORM_BIT                        0x00001000
#define GL_ENABLE_BIT                           0x00002000
#define GL_COLOR_BUFFER_BIT                     0x00004000
#define GL_HINT_BIT                             0x00008000
#define GL_EVAL_BIT                             0x00010000
#define GL_LIST_BIT                             0x00020000
#define GL_TEXTURE_BIT                          0x00040000
#define GL_SCISSOR_BIT                          0x00080000
#define GL_ALL_ATTRIB_BITS                      0x000FFFFF

/* Fog */
#define GL_FOG              0x0004      /* capability bit */
#define GL_FOG_MODE         0x0B65
#define GL_FOG_DENSITY      0x0B62
#define GL_FOG_COLOR        0x0B66
#define GL_FOG_INDEX        0x0B61
#define GL_FOG_START        0x0B63
#define GL_FOG_END          0x0B64
#define GL_LINEAR           0x2601
#define GL_EXP              0x0800
#define GL_EXP2             0x0801

/* Hints - Not used by the API, only here for compatibility */
#define GL_DONT_CARE                    0x1100
#define GL_FASTEST                      0x1101
#define GL_NICEST                       0x1102
#define GL_PERSPECTIVE_CORRECTION_HINT  0x0C50
#define GL_POINT_SMOOTH_HINT            0x0C51
#define GL_LINE_SMOOTH_HINT             0x0C52
#define GL_POLYGON_SMOOTH_HINT          0x0C53
#define GL_FOG_HINT                     0x0C54

/* Lighting constants */
#define GL_MAX_LIGHTS   0x0008

#define GL_LIGHTING     0x0b50

#define GL_LIGHT0                         0x4000
#define GL_LIGHT1                         0x4001
#define GL_LIGHT2                         0x4002
#define GL_LIGHT3                         0x4003
#define GL_LIGHT4                         0x4004
#define GL_LIGHT5                         0x4005
#define GL_LIGHT6                         0x4006
#define GL_LIGHT7                         0x4007

/* LightParameter */
#define GL_AMBIENT                        0x1200
#define GL_DIFFUSE                        0x1201
#define GL_SPECULAR                       0x1202
#define GL_POSITION                       0x1203
#define GL_SPOT_DIRECTION                 0x1204
#define GL_SPOT_EXPONENT                  0x1205
#define GL_SPOT_CUTOFF                    0x1206
#define GL_CONSTANT_ATTENUATION           0x1207
#define GL_LINEAR_ATTENUATION             0x1208
#define GL_QUADRATIC_ATTENUATION          0x1209

/* MaterialParameter */
#define GL_EMISSION                       0x1600
#define GL_SHININESS                      0x1601
#define GL_AMBIENT_AND_DIFFUSE            0x1602
#define GL_COLOR_INDEXES                        0x1603
#define GL_COLOR_MATERIAL                       0x0B57
#define GL_COLOR_MATERIAL_FACE                  0x0B55
#define GL_COLOR_MATERIAL_PARAMETER             0x0B56
#define GL_NORMALIZE                            0x0BA1
#define GL_LIGHT_MODEL_TWO_SIDE                 0x0B52
#define GL_LIGHT_MODEL_LOCAL_VIEWER             0x0B51
#define GL_LIGHT_MODEL_AMBIENT                  0x0B53
#define GL_FRONT_AND_BACK                       0x0408
#define GL_FRONT                                0x0404
#define GL_BACK                                 0x0405

#define GL_SHADE_MODEL      0x0b54
#define GL_FLAT         0x1d00
#define GL_SMOOTH       0x1d01

/* Data types */
#define GL_BYTE                                 0x1400
#define GL_UNSIGNED_BYTE                        0x1401
#define GL_SHORT                                0x1402
#define GL_UNSIGNED_SHORT                       0x1403
#define GL_INT                                  0x1404
#define GL_UNSIGNED_INT                         0x1405
#define GL_FLOAT                                0x1406
#define GL_DOUBLE                               0x140A
#define GL_2_BYTES                              0x1407
#define GL_3_BYTES                              0x1408
#define GL_4_BYTES                              0x1409

/* ErrorCode */
#define GL_NO_ERROR                       0
#define GL_INVALID_ENUM                   0x0500
#define GL_INVALID_VALUE                  0x0501
#define GL_INVALID_OPERATION              0x0502
#define GL_STACK_OVERFLOW                 0x0503
#define GL_STACK_UNDERFLOW                0x0504
#define GL_OUT_OF_MEMORY                  0x0505

/* KOS near Z-CLIPPING */
#define GL_KOS_NEARZ_CLIPPING       0x0020      /* capability bit */

#define GL_UNSIGNED_SHORT_5_6_5       PVR_TXRFMT_RGB565
#define GL_UNSIGNED_SHORT_5_6_5_REV   PVR_TXRFMT_RGB565
#define GL_UNSIGNED_SHORT_1_5_5_5     PVR_TXRFMT_ARGB1555
#define GL_UNSIGNED_SHORT_1_5_5_5_REV PVR_TXRFMT_ARGB1555
#define GL_UNSIGNED_SHORT_4_4_4_4     PVR_TXRFMT_ARGB4444
#define GL_UNSIGNED_SHORT_4_4_4_4_REV PVR_TXRFMT_ARGB4444

#define GL_RGB565_TWID PVR_TXRFMT_RGB565 | PVR_TXRFMT_TWIDDLED
#define GL_ARGB4444_TWID PVR_TXRFMT_ARGB4444 | PVR_TXRFMT_TWIDDLED

#define GL_RED  0x00
#define GL_RG   0x01
#define GL_RGB  0x02
#define GL_BGR  0x03
#define GL_RGBA 0x04
#define GL_BGRA 0x05

#define GLbyte   char
#define GLshort  short
#define GLint    int
#define GLfloat  float
#define GLdouble float
#define GLvoid   void
#define GLushort unsigned short
#define GLuint   unsigned int
#define GLenum   unsigned int
#define GLsizei  unsigned long
#define GLfixed  const unsigned int
#define GLclampf float
#define GLubyte  unsigned char
#define GLboolean   int
#define GL_FALSE    0
#define GL_TRUE     1

#define GLAPI extern
#define APIENTRY

/* Initialize the GL pipeline. GL will initialize the PVR. */
GLAPI void APIENTRY glKosInit();

/* Start Submission of Primitive Data */
/* Currently Supported Primitive Types:
   -GL_POINTS   ( does NOT work with glDrawArrays )( ZClipping NOT supported )
   -GL_TRIANGLES        ( works with glDrawArrays )( ZClipping supported )
   -GL_TRIANLGLE_STRIP  ( works with glDrawArrays )( ZClipping supported )
   -GL_QUADS            ( works with glDrawArrays )( ZClipping supported )
**/
GLAPI void APIENTRY glBegin(GLenum mode);

/* Finish Submission of Primitive Data */
GLAPI void APIENTRY glEnd();

/* Primitive Texture Coordinate Submission */
GLAPI void APIENTRY glTexCoord2f(GLfloat u, GLfloat v);
GLAPI void APIENTRY glTexCoord2fv(GLfloat *uv);

/* Primitive Color Submission */
GLAPI void APIENTRY glColor1ui(GLuint argb);
GLAPI void APIENTRY glColor4ub(GLubyte r, GLubyte  g, GLubyte b, GLubyte a);
GLAPI void APIENTRY glColor3f(GLfloat r, GLfloat g, GLfloat b);
GLAPI void APIENTRY glColor3fv(GLfloat *rgb);
GLAPI void APIENTRY glColor4f(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
GLAPI void APIENTRY glColor4fv(GLfloat *rgba);

/* Primitive Normal Submission */
GLAPI void APIENTRY glNormal3f(float x, float y, float z);
GLAPI void APIENTRY glNormal3fv(float *xyz);

/* Primitive 2D Position Submission */
GLAPI void APIENTRY glVertex2f(GLfloat x, GLfloat y);
GLAPI void APIENTRY glVertex2fv(GLfloat *xy);

/* Non-Standard KOS Primitive 2D Submission.  This will perform no tranformations on the vertices. */
GLAPI void APIENTRY glKosVertex2f(GLfloat x, GLfloat y);
GLAPI void APIENTRY glKosVertex2fv(GLfloat *xy);

/* Primitive 3D Position Submission */
GLAPI void APIENTRY(*glVertex3f)(float, float, float);
GLAPI void APIENTRY(*glVertex3fv)(float *);

/* Enable / Disable Capability */
/* Currently Supported Capabilities:
        GL_TEXTURE_2D
        GL_BLEND
        GL_DEPTH_TEST
        GL_LIGHTING
        GL_SCISSOR_TEST
        GL_FOG
        GL_CULL_FACE
        GL_KOS_NEARZ_CLIPPING
*/
GLAPI void APIENTRY glEnable(GLenum cap);
GLAPI void APIENTRY glDisable(GLenum cap);

/* Clear Caps */
GLAPI void APIENTRY glClear(GLuint mode);
GLAPI void APIENTRY glClearColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a);

/* Depth Testing */
GLAPI void APIENTRY glClearDepthf(GLfloat depth);
#define glClearDepth glClearDepthf
GLAPI void APIENTRY glDepthMask(GLboolean flag);
GLAPI void APIENTRY glDepthFunc(GLenum func);

/* Hints */
/* Currently Supported Capabilities:
      GL_PERSPECTIVE_CORRECTION_HINT - This will Enable Texture Super-Sampling on the PVR */
GLAPI void APIENTRY glHint(GLenum target, GLenum mode);

/* Culling */
GLAPI void APIENTRY glFrontFace(GLenum mode);
GLAPI void APIENTRY glCullFace(GLenum mode);

/* Shading - Flat or Goraud */
GLAPI void APIENTRY glShadeModel(GLenum mode);

/* Blending */
GLAPI void APIENTRY glBlendFunc(GLenum sfactor, GLenum dfactor);

/* Texturing */
GLAPI void APIENTRY glTexParameteri(GLenum target, GLenum pname, GLint param);
GLAPI void APIENTRY glTexEnvi(GLenum target, GLenum pname, GLint param);
GLAPI void APIENTRY glTexEnvf(GLenum target, GLenum pname, GLfloat param);

GLAPI void APIENTRY glGenTextures(GLsizei n, GLuint *textures);
GLAPI void APIENTRY glDelTextures(GLsizei n, GLuint *textures);
GLAPI void APIENTRY glBindTexture(GLenum  target, GLuint texture);

/* Loads texture from SH4 RAM into PVR VRAM */
GLAPI void APIENTRY glTexImage2D(GLenum target, GLint level, GLint internalFormat,
                                 GLsizei width, GLsizei height, GLint border,
                                 GLenum format, GLenum type, GLvoid *data);

/* Bind a Texture that is already in PVR VRAM */
GLAPI void APIENTRY glKosTexImage2D(GLenum target, GLint level, GLint internalFormat,
                                    GLsizei width, GLsizei height, GLint border,
                                    GLenum format, GLenum type, GLvoid *data);

/* GL Array API - Only GL_TRIANGLES, GL_TRIANGLE_STRIP, and GL_QUADS are supported */
GLAPI void APIENTRY glVertexPointer(GLint size, GLenum type,
                                    GLsizei stride, const GLvoid *pointer);

GLAPI void APIENTRY glTexCoordPointer(GLint size, GLenum type,
                                      GLsizei stride, const GLvoid *pointer);

/* If a Normal Pointer is set and GL Lighting has been enabled,
   Vertex Lighting will be used instead of glColorPointer */
GLAPI void APIENTRY glNormalPointer(GLint size, GLenum type,
                                    GLsizei stride, const GLvoid *pointer);

/* Use either this OR glNormalPointer to color vertices, NOT both */
GLAPI void APIENTRY glColorPointer(GLint size, GLenum type,
                                   GLsizei stride, const GLvoid *pointer);

GLAPI void APIENTRY glIndexPointer(GLenum type, GLsizei stride, const GLvoid *pointer);

/* Array Data Submission */
GLAPI void APIENTRY glDrawArrays(GLenum mode, GLint first, GLsizei count);
GLAPI void APIENTRY glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices);

/* No need to Enable Array Client State... */
#define glEnableClientState(cap) {;}
#define glDisableClientState(cap) {;}

/* Transformation / Matrix Functions */

GLAPI void APIENTRY glMatrixMode(GLenum mode);

GLAPI void APIENTRY glLoadIdentity();

GLAPI void APIENTRY glLoadMatrixf(const GLfloat *m);
GLAPI void APIENTRY glLoadTransposeMatrixf(const GLfloat *m);
GLAPI void APIENTRY glMultMatrixf(const GLfloat *m);
GLAPI void APIENTRY glMultTransposeMatrixf(const GLfloat *m);

GLAPI void APIENTRY glPushMatrix();
GLAPI void APIENTRY glPopMatrix();

GLAPI void APIENTRY glTranslatef(GLfloat x, GLfloat y, GLfloat z);
#define glTranslated glTranslatef

GLAPI void APIENTRY glScalef(GLfloat x, GLfloat y, GLfloat z);
#define glScaled glScalef

GLAPI void APIENTRY glRotatef(GLfloat angle, GLfloat x, GLfloat  y, GLfloat z);
#define glRotated glRotatef

GLAPI void APIENTRY glOrtho(GLfloat left, GLfloat right,
                            GLfloat bottom, GLfloat top,
                            GLfloat znear, GLfloat zfar);

GLAPI void APIENTRY glViewport(GLint x, GLint y, GLsizei width, GLsizei height);

GLAPI void APIENTRY glScissor(GLint x, GLint y, GLsizei width, GLsizei height);

GLAPI void APIENTRY glKosGetMatrix(GLenum mode, GLfloat *params);


/* Fog Functions - client must enable GL_FOG for this to take effect */
GLAPI void APIENTRY glFogi(GLenum pname, GLint param);
GLAPI void APIENTRY glFogf(GLenum pname, GLfloat param);
GLAPI void APIENTRY glFogfv(GLenum pname, const GLfloat *params);

/* Lighting Functions - client must enable GL_LIGHTING for this to take effect */

/* Set Global Ambient Light Color */
GLAPI void APIENTRY glKosLightAmbient3f(GLfloat r, GLfloat g, GLfloat b);
GLAPI void APIENTRY glKosLightAmbient4f(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
GLAPI void APIENTRY glKosLightAmbient3fv(GLfloat *rgb);
GLAPI void APIENTRY glKosLightAmbient4fv(GLfloat *rgba);

/* Set Individual Light Parameters */
GLAPI void APIENTRY glLightfv(GLenum light, GLenum pname, const GLfloat *params);
GLAPI void APIENTRY glLightf(GLenum light, GLenum pname, GLfloat param);

/* Set Global Material Parameters */
GLAPI void APIENTRY glMateriali(GLenum face, GLenum pname, const GLint param);
GLAPI void APIENTRY glMaterialf(GLenum face, GLenum pname, const GLfloat param);
GLAPI void APIENTRY glMaterialfv(GLenum face, GLenum pname, const GLfloat *params);

/* Returns the size needed to store a mip-mapped texture generated by gluBuild2DMipmaps(...) */
GLAPI GLuint APIENTRY glKosMipMapTexSize(GLuint width, GLuint height);

/* glGet Functions */
void glGetIntegerv(GLenum pname, GLint *params);
void glGetFloatv(GLenum pname, GLfloat *params);

/* Multi-Texture Extensions */
GLAPI void APIENTRY glActiveTexture(GLenum texture);

GLAPI void APIENTRY glClientActiveTexture(GLenum texture);

GLAPI void APIENTRY glMultiTexCoord2f(GLenum target, GLfloat s, GLfloat t);
GLAPI void APIENTRY glMultiTexCoord2fv(GLenum target, const GLfloat *v);

__END_DECLS
#endif /* !__GL_GL_H */
