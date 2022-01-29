#include <stdio.h>
#include <string.h>
#include <vector>
#include <memory>

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/mat4x4.hpp"

#include "Mesh.h"
#include "Shader.h"
#include "Window.h"

using mesh_vec = std::vector<std::unique_ptr<Mesh>>;
using shader_vec = std::vector<std::unique_ptr<Shader>>;

// Vertex Shader code
static const char* vShader = "../shaders/shader.vert";
// Fragment Shader
static const char* fShader = "../shaders/shader.frag";


void CreateObjects(mesh_vec& list)
{
   unsigned int indices[] = //use this for IBO, point correspondig to the points in vertices
   {
        0, 3, 1,
        1, 3, 2,
        2, 3, 0,
        0, 1, 2
   };

    GLfloat vertices[] = // points
    {
        -1.0f, -1.0f, 0.0f,
        0.0f, -1.0f, 1.0f,
        1.0f, -1.0f, 0.0f,
        0.0f, 1.0f, 0.0f
    };

    auto mesh = std::make_unique<Mesh>();
    mesh->create(vertices, indices, 12, 12);

    list.push_back(std::move(mesh));
}

void CreateShader(shader_vec& list)
{
    auto shader = std::make_unique<Shader>();
    shader->createFromFiles(vShader, fShader);
    list.emplace_back(std::move(shader));
}

int main()
{
    std::unique_ptr<Window> window = std::make_unique<Window>();
    window->init(800, 600, "OpenGL");
    mesh_vec mesh_list;
    shader_vec shader_list;

    CreateObjects(mesh_list);
    CreateShader(shader_list);


    GLuint uniformModel, uniformProjection;
    glm::mat4 projection = glm::perspective(45.0f,(GLfloat)window->getBufferWidth()/(GLfloat)window->getBufferHeight(), 0.1f, 100.0f );

    // Loop until window closed
    while (!window->getShouldClose())
    {
        // Get + Handle user input events
        glfwPollEvents();

        // Clear window
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        shader_list.front()->use();
        uniformModel = shader_list.front()->getModelLocation();
        uniformProjection = shader_list.front()->getProjectionLocation();


        glm::mat4 model (1.0f);
        model = glm::translate(model, glm::vec3(0.0f, 0.0f, -2.5f)); //translation
        model = glm::rotate(model,float(glfwGetTime()), glm::vec3(0.0f, 1.0f, 0.0f)); //rotation
        model = glm::scale(model, glm::vec3(0.4f, 0.4f, 1.0f)); // scale

        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));

        for(const auto& list : mesh_list)
        {
            list->render();
        }

        glUseProgram(0);
        window->swapBuffers();
    }

    return 0;
}


