#ifndef WINDOW_H
#define WINDOW_H

#include "stdio.h"
#include <string>
#include <GL/glew.h>
#include "GLFW/glfw3.h"

class Window
{
public:
    Window() : window_{nullptr}, width_{}, height_{}, bufferWidth_{}, bufferHeight_{} {}
    ~Window();

    int init(GLint width, GLint height,const std::string& name);

    GLint getBufferWidth() { return bufferWidth_; }
    GLint getBufferHeight() { return bufferHeight_; }

    bool getShouldClose() { return glfwWindowShouldClose(window_); }

    void swapBuffers() { glfwSwapBuffers(window_); }

private:
    GLFWwindow* window_ {nullptr};

    GLint width_ {};
    GLint height_ {};
    GLint bufferWidth_ {};
    GLint bufferHeight_ {};
};

#endif // WINDOW_H
