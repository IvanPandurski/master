#include "Mesh.h"
#include "stdio.h"

void Mesh::create(GLfloat *vertices, unsigned int *indices, unsigned int vert_num, unsigned int ind_num)
{
    idx_count_ = ind_num;

    glGenVertexArrays(1, &vao_); //first generate and bind VAO - vertex array object
    glBindVertexArray(vao_);

    glGenBuffers(1, &ibo_); // if u have IBO then generate and bind it, after that set buffer data to it
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo_);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices[0]) * ind_num, indices, GL_STATIC_DRAW);

    glGenBuffers(1, &vbo_); // generete and bind VBO - vertex buffer object, after that set buffer data to it
    glBindBuffer(GL_ARRAY_BUFFER, vbo_);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[0]) * vert_num, vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0); // set vertex attribute pointers
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

}

void Mesh::render()
{
    if(vao_ == 0 || vbo_ == 0 || ibo_ == 0)
    {
        printf("ERROR!!! VAO = %d, VBO = %d, IBO = %d", vao_, vbo_, ibo_);
        return;
    }
    glBindVertexArray(vao_);
//        glDrawArrays(GL_TRIANGLES, 0, 3); // when we dont use IBO
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo_);

    glDrawElements(GL_TRIANGLES, idx_count_, GL_UNSIGNED_INT, 0);

    glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Mesh::clear()
{
    if(vao_ != 0)
    {
        glDeleteVertexArrays(1, &vao_);
        vao_ = 0;
    }
    if(vbo_ != 0)
    {
        glDeleteBuffers(1, &vbo_);
        vbo_ = 0;
    }
    if(ibo_ != 0)
    {
        glDeleteBuffers(1, &ibo_);
        ibo_ = 0;
    }

    idx_count_ = 0;
}
