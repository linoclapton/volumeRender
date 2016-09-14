#pragma once
#include <gl/glew.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <string>
#include <vector>
#include <map>
#include <ft2build.h>
#include <freetype\freetype.h>
struct Character {
    GLuint TextureID;   // ID handle of the glyph texture
    glm::ivec2 Size;    // Size of glyph
    glm::ivec2 Bearing;  // Offset from baseline to left/top of glyph
    GLuint Advance;    // Horizontal offset to advance to next glyph
};
class Camera{
public:
    float* lookAt(float pos[3],float target[3],float up[3]);
private:
    void normalize(float*);
};
class GLSLProgram{

private:
    int _id;
    GLuint _program[10];
    GLuint _textProgram;
    GLuint _vertex_array;
    GLuint VAO,VBO;
    std::vector<GLuint> shaders;
    std::vector<GLuint> buffers;
    std::map<wchar_t, Character> _Characters;
    std::map<std::string,GLint> _uniforms[10];
public:
    std::string log;
    GLSLProgram(){
        _id = 0;
        log = "";
        for(int i=0;i<10;i++)
            _program[i]=0;
    }
    void attachShader(GLenum type, std::string path);
    void create();
    void link();
    void initTextShader();
    void addCharacter(FT_Face face,int c);
    void bindVertexArray();
    GLuint bindBuffer(GLenum buffer_type, GLuint buffer_size, const GLvoid * data, GLenum draw_type);
    void bindBufferToVertex(GLint attrib_location, GLint attrib_size, GLenum buffer_type, GLsizei buffer_per_size,const GLvoid * offset);
    void bindBufferToVertex(const char * attrib_name, GLint attrib_size, GLenum buffer_type, GLsizei buffer_per_size, const GLvoid * offset);
    void change(int id);
    void use(int id);
    void destroy();
    void genBuffers(GLsizei n,GLuint* buffers);
    void genVertexArrays(GLsizei n,GLuint* arrays);
    void bufferData(GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage); 
    void bindBuffer(GLenum target, GLuint buffer);
    void vertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid * pointer);
    void enableVertexAttribArray(GLint index);

    //SetUniform
    void setUniform(const char *name, float x, float y,float z);
    void setUniform(const char *name, const glm::vec3 & v);
    void setUniform(const char *name, const glm::vec4 & v);
    void setUniform(const char *name, const glm::mat4 & m);
    void setUniform(const char *name, const glm::mat3 & m);
    void setUniform(const char *name, float val);
    void setUniform(const char *name, int val);
    void setUniform(const char *name, bool val);
    void setUniform(const char *name, int size,float* data);
    void setUniform(const char *name, float* data);

    GLuint setUniform(const char *name, GLuint buffer_size, GLvoid *pointer, GLenum draw_type);

    void setUniform(GLint uniform_location, float x, float y, float z);
    void setUniform(GLint uniform_location, const glm::vec3 & v);
    void setUniform(GLint uniform_location, const glm::vec4 & v);
    void setUniform(GLint uniform_location, const glm::mat4 & m);
    void setUniform(GLint uniform_location, const glm::mat3 & m);
    void setUniform(GLint uniform_location, float val);
    void setUniform(GLint uniform_location, int val);
    void setUniform(GLint uniform_location, bool val);
    GLuint setUniform(GLint uniform_location, GLuint buffer_size, GLvoid *pointer, GLenum draw_type);

    void getUniform(GLint uniform_location,float* variable);
    void getUniform(const char *name,float* variable);
    void glActiveTex(GLenum texture);
    GLint getUniformLocation(const char *name);
    void genFramebuffers(int size,GLuint index[]);
    void bindFramebuffer(GLuint index,int width,int height,int samplers);
    void bindFramebuffer(GLuint index);
    void framebufferTexture2D(GLuint tex,GLenum textureType=GL_TEXTURE_2D);
    void genRenderbuffers(GLuint& index);
    void bindRenderbuffer(GLuint index);
    void renderbufferStorage(int size);
    void framebufferRenderbuffer(GLuint index);
    void vertexAttrib3f(GLuint index, GLfloat v0, GLfloat v1, GLfloat v2);
    void getConstant(GLenum type,GLuint index,GLint* data);
    void getConstant(GLenum type,GLint* data);
    void generateMipmap(GLenum type);
    void useProgram(GLuint id);
    void renderText(std::string text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color);

    const char* getGLErrorInfo(int errorId);

    void deleteShaders();
    void deleteProgram();
    void printGLExtension();
    void printGraphicInfo();
    char*glEnumToString(GLenum type);
    void printActiveUniforms();
    void printActiveAttirbs();
    void printLog();
    void printError();


    void checkFrameBufferStatus();
};
