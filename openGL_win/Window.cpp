#include "Window.h"

int Window::init(GLint width, GLint height,const std::string &name)
{
    if (!glfwInit())
    {
        printf("Error Initialising GLFW");
        glfwTerminate();
        return 1;
    }

    // Setup GLFW Windows Properties
    // OpenGL version
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    // Core Profile
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // Allow forward compatiblity
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    // Create the window
    window_ = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);
    if (!window_)
    {
        printf("Error creating GLFW window!");
        glfwTerminate();
        return 1;
    }

    // Get buffer size information
    glfwGetFramebufferSize(window_, &bufferWidth_, &bufferHeight_);

    // Set the current context
    glfwMakeContextCurrent(window_);

    // Allow modern extension access
    glewExperimental = GL_TRUE;

    GLenum error = glewInit();
    if (error != GLEW_OK)
    {
        printf("Error: %s", glewGetErrorString(error));
        glfwDestroyWindow(window_);
        glfwTerminate();
        return 1;
    }

    glEnable(GL_DEPTH_TEST);

    // Create Viewport
    glViewport(0, 0, bufferWidth_, bufferHeight_);

    return 1;
}


Window::~Window()
{
    glfwDestroyWindow(window_);
    glfwTerminate();
}
