#include "GLSLProgram.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
void GLSLProgram::create(){
    _program[_id] = glCreateProgram();
}
void GLSLProgram::attachShader(GLenum type, std::string path){
    // Create the shaders
    GLuint shader = glCreateShader(type);
    // Read the Vertex Shader code from the file
    std::string shaderCode;
    std::ifstream fstream(path, std::ios::in);
    if (fstream.is_open()){
        std::string Line = "";
        while (getline(fstream, Line))
            shaderCode += "\n" + Line;
        fstream.close();
    }
    else{
        log = "Impossible to open Are you in the right directory ? Don't forget to read the FAQ !\n";
        return;
    }
    GLint Result = GL_FALSE;
    int InfoLogLength;
    // Compile Vertex Shader
    char const * sourcePointer = shaderCode.c_str();
    glShaderSource(shader, 1, &sourcePointer, NULL);
    glCompileShader(shader);
    // Check Vertex Shader
    glGetShaderiv(shader, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if (InfoLogLength > 0){
        std::vector<char> VertexShaderErrorMessage(InfoLogLength + 1);
        glGetShaderInfoLog(shader, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
        log= &VertexShaderErrorMessage[0];
    }
    glAttachShader(_program[_id], shader);
    glDeleteShader(shader);
}
void GLSLProgram::glActiveTex(GLenum texture){
    glActiveTexture(texture);
}
GLint GLSLProgram::getUniformLocation(const char *name){
    return _uniforms[_id][name];
}
void GLSLProgram::genFramebuffers(int size,GLuint name[]){
    glGenFramebuffers(size, name);
}
void GLSLProgram::bindFramebuffer(GLuint name,int width,int height,int samplers){
    glBindFramebuffer(GL_FRAMEBUFFER,name);
    glFramebufferParameteri(GL_FRAMEBUFFER, GL_FRAMEBUFFER_DEFAULT_WIDTH, width);
    glFramebufferParameteri(GL_FRAMEBUFFER, GL_FRAMEBUFFER_DEFAULT_HEIGHT, height);
    glFramebufferParameteri(GL_FRAMEBUFFER, GL_FRAMEBUFFER_DEFAULT_SAMPLES, samplers);
    GLenum e = glCheckFramebufferStatus(GL_FRAMEBUFFER);
    if (e != GL_FRAMEBUFFER_COMPLETE)
        checkFrameBufferStatus();
        //printf("There is a problem with the FBO\n");
}
void GLSLProgram::bindFramebuffer(GLuint name){
    glBindFramebuffer(GL_FRAMEBUFFER,name);
}
void GLSLProgram::framebufferTexture2D(GLuint tex,GLenum textureType){
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,textureType, tex, 0);
}
void GLSLProgram::genRenderbuffers(GLuint& index){
    glGenRenderbuffers(1, &index);
}
void GLSLProgram::genVertexArrays(GLsizei n,GLuint* arrays){
    glGenVertexArrays(n,arrays);
}
void GLSLProgram::bufferData(GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage){
    glBufferData(target,size,data,usage);
}
void GLSLProgram::bindBuffer(GLenum target, GLuint buffer){
    glBindBuffer(target,buffer);
}
void GLSLProgram::bindRenderbuffer(GLuint index){
    glBindRenderbuffer(GL_RENDERBUFFER,index);
}
void GLSLProgram::renderbufferStorage(int size){
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT,size,size);
}
void GLSLProgram::framebufferRenderbuffer(GLuint index){
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER,index);
}
void GLSLProgram::vertexAttrib3f(GLuint index, GLfloat v0, GLfloat v1, GLfloat v2){
    glVertexAttrib3f(index,v0,v1,v2);
}
void GLSLProgram::bindVertexArray(){
    glGenVertexArrays(1, &_vertex_array);
    //	glBindVertexArray(vertex_array);
}
void GLSLProgram::genBuffers(GLsizei n,GLuint* buffers){
    glGenBuffers(n,buffers);
}
GLuint GLSLProgram::bindBuffer(GLenum buffer_type, GLuint buffer_size, const GLvoid * data, GLenum draw_type ){
    GLuint buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(buffer_type, buffer);
    glBufferData(buffer_type, buffer_size, data, draw_type);
    buffers.push_back(buffer);
    return buffer;
}
void GLSLProgram::bindBufferToVertex(GLint attrib_location, GLint attrib_size, GLenum buffer_type, GLsizei buffer_per_size, const GLvoid * offset){
    glEnableVertexAttribArray(attrib_location);
    glVertexAttribPointer(attrib_location, attrib_size, buffer_type, GL_FALSE, buffer_per_size, offset);
}
void GLSLProgram::bindBufferToVertex(const char* attrib_name, GLint attrib_size, GLenum buffer_type, GLsizei buffer_per_size, const GLvoid * offset){
    GLint attrib_location = glGetAttribLocation(_program[_id], attrib_name);
    bindBufferToVertex(attrib_location, attrib_size, buffer_type, buffer_per_size, offset);
}
void GLSLProgram::generateMipmap(GLenum type){
    glGenerateMipmap(type);
}
void GLSLProgram::link(){
    glLinkProgram(_program[_id]);
    GLint status;
    glGetProgramiv(_program[_id], GL_LINK_STATUS, &status);
    if (GL_FALSE == status) {
        fprintf(stderr, "Failed to link shader program!\n");
        GLint logLen;
        glGetProgramiv(_program[_id], GL_INFO_LOG_LENGTH,
            &logLen);
        if (logLen > 0)
        {
            char * log = (char *)malloc(logLen);
            GLsizei written;
            glGetProgramInfoLog(_program[_id], logLen, &written, log);
        }
    }
    GLint maxLength,nUniforms;
    glGetProgramiv(_program[_id], GL_ACTIVE_UNIFORM_MAX_LENGTH,&maxLength);
    glGetProgramiv(_program[_id], GL_ACTIVE_UNIFORMS,&nUniforms);
    GLchar * name = new GLchar[maxLength];
    GLint written, size, location;
    GLenum type;
    for (int i = 0; i < nUniforms; ++i) {
        glGetActiveUniform(_program[_id], i, maxLength, &written,&size, &type, name);
        location = glGetUniformLocation(_program[_id], name);
        _uniforms[_id][name] = location;
    }
    delete []name;

}
void GLSLProgram::use(int id){
    change(id);
    glUseProgram(_program[id]);
    //printActiveUniforms();
}

char*GLSLProgram::glEnumToString(GLenum type){
    switch(type){
    case 0x8B50:return "GL_FLOAT_VEC2";
    case 0x8B51:return "GL_FLOAT_VEC3";
    case 0x8B52:return "GL_FLOAT_VEC4";
    case 0x1406:return "GL_FLOAT";
    case 0x1404:return "GL_INT";
    case 0x8B5A:return "GL_FLOAT_MAT2";
    case 0x8B5B:return "GL_FLOAT_MAT3";
    case 0x8B5C:return "GL_FLOAT_MAT4";
    case 0x8B5D:return "GL_SAMPLER_1D";
    case 0x8B5E:return "GL_SAMPLER_2D";
    case 0x8B5F:return "GL_SAMPLER_3D";
    case 0x8B60:return "GL_SAMPLER_CUBE";
    case 0x8B61:return "GL_SAMPLER_1D_SHADOW";
    case 0x8B62:return "GL_SAMPLER_2D_SHADOW";
    default: return "others";
    }
}
void GLSLProgram::printActiveAttirbs(){
    GLint maxLength, nAttribs;
    glGetProgramiv(_program[_id], GL_ACTIVE_ATTRIBUTES, &nAttribs);
    glGetProgramiv(_program[_id], GL_ACTIVE_ATTRIBUTE_MAX_LENGTH,
        &maxLength);
    GLchar * name = (GLchar *)malloc(maxLength);
    GLint written, size, location;
    GLenum type;
    printf(" Index | Name\n");
    printf("------------------------------------------------\n");
    for (int i = 0; i < nAttribs; i++) {
        glGetActiveAttrib(_program[_id], i, maxLength, &written,
            &size, &type, name);
        location = glGetAttribLocation(_program[_id], name);
        printf(" %-8d | %-10s | %-2d | %s\n", location, name,size,glEnumToString(type));
    }
    free(name);
}
void GLSLProgram::printActiveUniforms(){
    GLint maxLength,nUniforms;
    glGetProgramiv(_program[_id], GL_ACTIVE_UNIFORM_MAX_LENGTH,&maxLength);
    glGetProgramiv(_program[_id], GL_ACTIVE_UNIFORMS,&nUniforms);
    GLchar * name = (GLchar *)malloc(maxLength);
    GLint written, size, location;
    GLenum type;
    printf(" Location | Name | Size | Type\n");
    printf("------------------------------------------------\n");
    for (int i = 0; i < nUniforms; ++i) {
        glGetActiveUniform(_program[_id], i, maxLength, &written,&size, &type, name);
        location = glGetUniformLocation(_program[_id], name);
        printf(" %-8d | %-10s | %-2d | %s\n", location, name,size,glEnumToString(type));
    }
    std::cout<<std::endl;
    free(name);
}
void GLSLProgram::printGraphicInfo(){
    const GLubyte *renderer = glGetString( GL_RENDERER );
    const GLubyte *vendor = glGetString( GL_VENDOR );
    const GLubyte *version = glGetString( GL_VERSION );
    const GLubyte *glslVersion = glGetString( GL_SHADING_LANGUAGE_VERSION );
    GLint major, minor;
    glGetIntegerv(GL_MAJOR_VERSION, &major);
    glGetIntegerv(GL_MINOR_VERSION, &minor);
    printf("GL Vendor : %s\n", vendor);
    printf("GL Renderer : %s\n", renderer);
    printf("GL Version (string) : %s\n", version);
    printf("GL Version (integer) : %d.%d\n", major, minor);
    printf("GLSL Version : %s\n", glslVersion);
}
void GLSLProgram::printGLExtension(){
    GLint nExtensions;
    glGetIntegerv(GL_NUM_EXTENSIONS, &nExtensions);
    for( int i = 0; i < nExtensions; i++ )
        printf("%s\n", glGetStringi( GL_EXTENSIONS, i ) );
}

void GLSLProgram::printLog(){
    std::cout << log << std::endl;
}

void GLSLProgram::vertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid * pointer){
    glVertexAttribPointer(index,size,type,normalized,stride,pointer);
}
void GLSLProgram::enableVertexAttribArray(GLint index){
    glEnableVertexAttribArray(index);
}
void GLSLProgram::setUniform(const char *name, float x, float y, float z){
    GLint uniform_location = getUniformLocation(name);
    setUniform(uniform_location, x, y, z);
}
void GLSLProgram::setUniform(const char *name, const glm::vec3 & v){
    GLint uniform_location = getUniformLocation(name);
    setUniform(uniform_location, v);
}
void GLSLProgram::setUniform(const char *name, const glm::vec4 & v){
    GLint uniform_location = getUniformLocation(name);
    setUniform(uniform_location, v);
}
void GLSLProgram::setUniform(const char *name, const glm::mat4 & m){
    GLint uniform_location = getUniformLocation(name);
    setUniform(uniform_location, m);
}
void GLSLProgram::setUniform(const char *name, const glm::mat3 & m){
    GLint uniform_location = getUniformLocation(name);
    setUniform(uniform_location, m);
}
void GLSLProgram::setUniform(const char *name, float val){
    GLint uniform_location = getUniformLocation(name);
    setUniform(uniform_location, val);
}
void GLSLProgram::setUniform(const char *name, int val){
    GLint uniform_location = getUniformLocation(name);
    setUniform(uniform_location, val);
}
void GLSLProgram::setUniform(const char *name, bool val){
    GLint uniform_location = getUniformLocation(name);
    setUniform(uniform_location, val);
}
void GLSLProgram::setUniform(const char *name, int size,float* data){
    GLint uniform_location = getUniformLocation(name);
    glUniform3fv(uniform_location,size,data);
}
void GLSLProgram::setUniform(const char *name, float* data){
    GLint uniform_location = getUniformLocation(name);
    glUniformMatrix4fv(uniform_location, 1, GL_FALSE, data);
}
void GLSLProgram::setUniform(GLint uniform_location, float x, float y, float z){
    glUniform3f(uniform_location, x, y, z);
}
void GLSLProgram::setUniform(GLint uniform_location, const glm::vec3 & v){
    setUniform(uniform_location, v.x, v.y, v.z);
}
void GLSLProgram::setUniform(GLint uniform_location, const glm::vec4 & v){
    glUniform4f(uniform_location, v.x, v.y, v.z, v.w);
}
void GLSLProgram::setUniform(GLint uniform_location, const glm::mat4 & m){
    glUniformMatrix4fv(uniform_location, 1, GL_FALSE, &m[0][0]);
}
void GLSLProgram::setUniform(GLint uniform_location, const glm::mat3 & m){
    glUniformMatrix3fv(uniform_location, 1,GL_FALSE,&m[0][0]);
}
void GLSLProgram::setUniform(GLint uniform_location, float val){
    glUniform1f(uniform_location, val);
}
void GLSLProgram::setUniform(GLint uniform_location, int val){
    glUniform1i(uniform_location, val);
}
void GLSLProgram::setUniform(GLint uniform_location, bool val){
    glUniform1i(uniform_location, val);
}

GLuint GLSLProgram::setUniform(const char *name, GLuint buffer_size, GLvoid *pointer, GLenum draw_type){
    GLint blockIndex = glGetUniformBlockIndex(_program[_id], name);
    return setUniform(blockIndex, buffer_size, pointer, draw_type);
}

GLuint GLSLProgram::setUniform(GLint uniform_location, GLuint buffer_size, GLvoid *pointer, GLenum draw_type){
    GLuint uniform_buffer;
    glGenBuffers(1, &uniform_buffer);
    glBindBuffer(GL_UNIFORM_BUFFER, uniform_buffer);
    glBufferData(GL_UNIFORM_BUFFER, buffer_size, pointer, draw_type);
    glBindBufferBase(GL_UNIFORM_BUFFER, uniform_location, uniform_buffer);
    buffers.push_back(uniform_buffer);
    return uniform_buffer;
}

void GLSLProgram::destroy(){
    for (GLuint buffer : buffers)
        glDeleteBuffers(1, &buffer);
    for (GLuint shader : shaders)
        glDeleteShader(shader);
    glDeleteVertexArrays(1, &_vertex_array);
    glDeleteProgram(_program[_id]);
}
void GLSLProgram::getUniform(const char *name,float* variable)
{
    GLint uniform_location = getUniformLocation(name);
    getUniform(uniform_location,variable);
}

void GLSLProgram::getUniform(GLint uniform_location,float* variable){
    glGetUniformfv(_program[_id],uniform_location,variable);
}
void GLSLProgram::addCharacter(FT_Face face,int c){
    if (FT_Load_Char(face, c, FT_LOAD_RENDER))
    {
        std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
        return;
    }
    // Generate texture
    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D( GL_TEXTURE_2D, 0, GL_RED, face->glyph->bitmap.width, face->glyph->bitmap.rows, 0, GL_RED, GL_UNSIGNED_BYTE, face->glyph->bitmap.buffer
        );
    // Set texture options
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // Now store character for later use
    Character character = {
        texture,
        glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
        glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
        face->glyph->advance.x
    };
    _Characters.insert(std::pair<GLchar, Character>(c, character));
}
void GLSLProgram::initTextShader(){
    //Shader shader("shaders/text.vs", "shaders/text.frag");
    int currentID = _id;
    change(9);
    create();
    attachShader(GL_VERTEX_SHADER,"textVS.glsl");
    attachShader(GL_FRAGMENT_SHADER,"textFS.glsl");
    link();
    use(9);
    glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(800), 0.0f, static_cast<GLfloat>(600));
    glUniformMatrix4fv(glGetUniformLocation(_program[9], "projection"), 1, GL_FALSE, glm::value_ptr(projection));

    // FreeType
    FT_Library ft;
    // All functions return a value different than 0 whenever an error occurred
    if (FT_Init_FreeType(&ft))
        std::cout << "ERROR::FREETYPE: Could not init FreeType Library" << std::endl;

    // Load font as face
    FT_Face face;
    if (FT_New_Face(ft, "fonts/arial.ttf", 0, &face))
        std::cout << "ERROR::FREETYPE: Failed to load font" << std::endl;

    // Set size to load glyphs as
    FT_Set_Pixel_Sizes(face, 0, 48);

    // Disable byte-alignment restriction
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1); 

    // Load first 128 characters of ASCII set
    for (GLubyte c = 0; c < 128; c++)
    {
        // Load character glyph 
        addCharacter(face,c);
    }
    //wchar_t wChar= _T('博');
    // 查找‘好’的字符索引
    //FT_UInt glyph_index = FT_Get_Char_Index(face, wChar);
    //addCharacter(face,glyph_index);
    glBindTexture(GL_TEXTURE_2D, 0);
    // Destroy FreeType once we're finished
    FT_Done_Face(face);
    FT_Done_FreeType(ft);


    // Configure VAO/VBO for texture quads
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    use(currentID);
}
void GLSLProgram::renderText(std::string text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color){
    int currentID = _id;
    use(9);
    glUniform3f(glGetUniformLocation(_program[_id], "textColor"), color.x, color.y, color.z);
    glActiveTexture(GL_TEXTURE0);
    glBindVertexArray(VAO);

    // Iterate through all characters
    std::string::const_iterator c;
    for (c = text.begin(); c != text.end(); c++) 
    {
        Character ch = _Characters[*c];

        GLfloat xpos = x + ch.Bearing.x * scale;
        GLfloat ypos = y - (ch.Size.y - ch.Bearing.y) * scale;

        GLfloat w = ch.Size.x * scale;
        GLfloat h = ch.Size.y * scale;
        // Update VBO for each character
        GLfloat vertices[6][4] = {
            { xpos,     ypos + h,   0.0, 0.0 },            
            { xpos,     ypos,       0.0, 1.0 },
            { xpos + w, ypos,       1.0, 1.0 },

            { xpos,     ypos + h,   0.0, 0.0 },
            { xpos + w, ypos,       1.0, 1.0 },
            { xpos + w, ypos + h,   1.0, 0.0 }           
        };
        // Render glyph texture over quad
        glBindTexture(GL_TEXTURE_2D, ch.TextureID);
        // Update content of VBO memory
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices); // Be sure to use glBufferSubData and not glBufferData

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        // Render quad
        glDrawArrays(GL_TRIANGLES, 0, 6);
        // Now advance cursors for next glyph (note that advance is number of 1/64 pixels)
        x += (ch.Advance >> 6) * scale; // Bitshift by 6 to get value in pixels (2^6 = 64 (divide amount of 1/64th pixels by 64 to get amount of pixels))
    }
    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
    use(currentID);
}

void GLSLProgram::deleteShaders(){
    for(GLuint shader : shaders)
        glDeleteShader(shader);
    shaders.clear();
}

void GLSLProgram::deleteProgram(){
    glDeleteProgram(_program[_id]);
    _program[_id] = 0;
}

void GLSLProgram::change(int id){
    this->_id = id;
}

void GLSLProgram::getConstant(GLenum type,GLuint index,GLint* data){
    glGetIntegeri_v(type,index,data);
}
void GLSLProgram::getConstant(GLenum type,GLint* data){
    glGetIntegerv(type,data);
}

const char* GLSLProgram::getGLErrorInfo(int errorId){
        const char* getGLErrorInfo(int errorId);
        switch (errorId)
        {
            case GL_INVALID_ENUM:
                return ("GL Invalid Enum\n");
            case GL_INVALID_VALUE:
                return ("GL Invalid Value\n");
            case GL_INVALID_OPERATION:
                return ("GL Invalid Operation\n");
            case GL_OUT_OF_MEMORY:
                return ("GL Out Of Memory\n");
            case GL_INVALID_FRAMEBUFFER_OPERATION:
                return ("GL Invalid FrameBuffer Operation\n");
            case  GL_STACK_OVERFLOW:
                return ("GL Stack Overflow\n");
            case GL_STACK_UNDERFLOW:
                return ("GL Stack Underflow\n");
            case GL_TABLE_TOO_LARGE:
                 return ("GL Table Too Large\n");
        };
        return "GL Undefined Error";
}
void GLSLProgram::checkFrameBufferStatus(){
    GLenum type[] ={GL_FRAMEBUFFER,GL_DRAW_FRAMEBUFFER,GL_READ_FRAMEBUFFER};
    std::string name[]={"GL_FRAMEBUFFER","GL_DRAW_FRAMEBUFFER","GL_READ_FRAMEBUFFER"};
    for(int i=0;i<3;i++){
        GLenum e = glCheckFramebufferStatus(type[i]);
        switch (e) {
            case GL_FRAMEBUFFER_UNDEFINED:
                printf("%s Undefined\n",name[i].c_str());
                break;
            case GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT :
                printf("%s Incomplete Attachment\n",name[i].c_str());
                break;
            case GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT :
                printf("%s Missing Attachment\n",name[i].c_str());
                break;
            case GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER: 
                printf("%s Incomplete Draw Buffer\n",name[i].c_str());
                break;
            case GL_FRAMEBUFFER_UNSUPPORTED: 
                printf("%s Unsupported\n",name[i].c_str());
                break;
            case GL_FRAMEBUFFER_COMPLETE:
                printf("%s OK\n",name[i].c_str());
                break;
            default:
                printf("%s Problem?\n",name[i].c_str());
        }
    }
}
void GLSLProgram::printError(){
    GLenum error = glGetError();
    switch(error){
    case GL_NO_ERROR:
        printf("No error: No error has been recorded\n");break;
    case GL_INVALID_ENUM:
        printf("Invalid enum: An unacceptable enum value\n");break;
    case GL_INVALID_VALUE:
        printf("InvaliD value: A number is out of range\n");break;
    case GL_INVALID_OPERATION:
        printf("Invalid operation: The specified operation is not allowed in the current state\n");break;
    case GL_INVALID_FRAMEBUFFER_OPERATION:
        printf("Invalid framebuffer operation: The framebuffer object is not complete\n");break;
    case GL_OUT_OF_MEMORY:
        printf("Out of memory: There is not enough memory left to execute the command\n");break;
    case GL_STACK_UNDERFLOW:
        printf("Stack underflow: An attempt has been made to perform an operation that would cause an internal stack to underflow");break;
    case GL_STACK_OVERFLOW:
        printf("Stack overflow: An attempt has been made to perform an operation that would cause an internal stack to overflow\n");break;
    }
}
void Camera::normalize(float* v){
    float vl = sqrt(v[0]*v[0]+v[1]*v[1]+v[2]*v[2]);
    v[0] /= vl;
    v[1] /= vl;
    v[2] /= vl;
}
float* Camera::lookAt(float pos[3],float target[3],float up[3]){
    float* view = new float[16];
    float trans[16]={1.0f,0.0f,0.0f,0.0f,
                     0.0f,1.0f,0.0f,0.0f,
                     0.0f,0.0f,1.0f,0.0f,
                     -pos[0],-pos[1],-pos[2],1.0f};
    float d[4] = {pos[0]-target[0],pos[1]-target[1],pos[2]-target[2],0.0f};
    normalize(d);
    float r[4] = {up[1]*d[2]-up[2]*d[1],up[2]*d[0]-up[0]*d[2],up[0]*d[1]-d[0]*up[1],0.0f};
    normalize(r);
    float rotates[16]={r[0],up[0],d[0],0.0f,
                       r[1],up[1],d[1],0.0f,
                       r[2],up[2],d[2],0.0f,
                       0.0f,0.0f,0.0f,1.0f};
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            view[j*4+i] =trans[0*4+i]*rotates[j*4+0]+
                         trans[1*4+i]*rotates[j*4+1]+
                         trans[2*4+i]*rotates[j*4+2]+
                         trans[3*4+i]*rotates[j*4+3];
    return view;
}
void GLSLProgram::useProgram(GLuint id){
    glUseProgram(id);
}