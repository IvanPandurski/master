#include "Shader.h"
#include <cstring>

Shader::~Shader()
{
    clear();
}

void Shader::createFromFiles(const char* vertexLocation, const char* fragmentLocation)
{
    std::string vertexString = readFile(vertexLocation);
    std::string fragmentString = readFile(fragmentLocation);
    const char* vertexCode = vertexString.c_str();
    const char* fragmentCode = fragmentString.c_str();

    compile(vertexCode, fragmentCode);
}

std::string Shader::readFile(const char* fileLocation)
{
    std::string content;
    std::ifstream fileStream(fileLocation, std::ios::in);

    if (!fileStream.is_open()) {
        printf("Failed to read %s! File doesn't exist.", fileLocation);
        return "";
    }

    std::string line = "";
    while (!fileStream.eof())
    {
        std::getline(fileStream, line);
        content.append(line + "\n");
    }

    fileStream.close();
    return content;
}

GLuint Shader::getProjectionLocation()
{
    return uni_projection_;
}

GLuint Shader::getModelLocation()
{
    return uni_model_;
}

void Shader::use()
{
    glUseProgram(id_);
}

void Shader::clear()
{
    if (id_ != 0)
    {
        glDeleteProgram(id_);
        id_ = 0;
    }

    uni_model_ = 0;
    uni_projection_ = 0;
}

void Shader::compile(const char* vertex, const char* fragment)
{
    id_ = glCreateProgram();

    if (!id_)
    {
        printf("Error creating shader program!\n");
        return;
    }

    add(id_, vertex, GL_VERTEX_SHADER);
    add(id_, fragment, GL_FRAGMENT_SHADER);

    GLint result = 0;
    GLchar eLog[1024] = { 0 };

    glLinkProgram(id_);
    glGetProgramiv(id_, GL_LINK_STATUS, &result);
    if (!result)
    {
        glGetProgramInfoLog(id_, sizeof(eLog), NULL, eLog);
        printf("Error linking program: '%s'\n", eLog);
        return;
    }

    glValidateProgram(id_);
    glGetProgramiv(id_, GL_VALIDATE_STATUS, &result);
    if (!result)
    {
        glGetProgramInfoLog(id_, sizeof(eLog), NULL, eLog);
        printf("Error validating program: '%s'\n", eLog);
        return;
    }

    uni_projection_ = glGetUniformLocation(id_, "projection");
    uni_model_ = glGetUniformLocation(id_, "model");
}

void Shader::add(GLuint program, const char* code, GLenum type)
{
    GLuint shader = glCreateShader(type);

    const GLchar* theCode[1];
    theCode[0] = code;

    GLint codeLength[1];
    codeLength[0] = strlen(code);

    glShaderSource(shader, 1, theCode, codeLength);
    glCompileShader(shader);

    GLint result = 0;
    GLchar eLog[1024] = { 0 };

    glGetShaderiv(shader, GL_COMPILE_STATUS, &result);
    if (!result)
    {
        glGetShaderInfoLog(shader, sizeof(eLog), NULL, eLog);
        printf("Error compiling the %d shader: '%s'\n", type, eLog);
        return;
    }

    glAttachShader(program, shader);
}
