#ifndef MESH_H
#define MESH_H

#include "GL/glew.h"

class Mesh
{
public:
    Mesh() : vao_{0}, vbo_{0}, ibo_{0}, idx_count_{} {}
    ~Mesh() {clear();}

    void create(GLfloat* vertices, unsigned int* indices, unsigned int vert_num, unsigned int ind_num);
    void render();
    void clear();

private:

    GLuint vao_ {};
    GLuint vbo_ {};
    GLuint ibo_ {};

    GLsizei idx_count_ {};
};

#endif // MESH_H
