#pragma once
#include <iostream>

#ifndef GLFW_INCLUDE_NONE
#define GLFW_INCLUDE_NONE
#endif
#include <GLFW/glfw3.h>


class GlfwRuntime {
public:
    GlfwRuntime() {}

    ~GlfwRuntime() {
        if (initialized) glfwTerminate();
    }

    GlfwRuntime(const GlfwRuntime&) = delete;
    GlfwRuntime& operator=(const GlfwRuntime&) = delete;

    bool Initialize() {
        if (glfwInit() == GLFW_FALSE) {
            std::cout << "GLFW Failed to initialize!" << std::endl;
            return false;
        }
        initialized = true;
        return true;
    }

    void PollEvents() {
        glfwPollEvents();
    }

private:
    bool initialized = false;
};