#ifndef SHADER_H
#define SHADER_H
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

#include <GL\glew.h>

class Shader
{
public:
    Shader() : id_ {}, uni_projection_{}, uni_model_{} {}
    ~Shader();

    void createFromFiles(const char* vertexLocation, const char* fragmentLocation);

    std::string readFile(const char* fileLocation);

    GLuint getProjectionLocation();
    GLuint getModelLocation();

    void use();
    void clear();


private:
    void compile(const char* vertex, const char* fragment);
    void add(GLuint program, const char* code, GLenum type);

private:
    GLuint id_ {};
    GLuint uni_projection_ {};
    GLuint uni_model_ {};
};

#endif // SHADER_H
