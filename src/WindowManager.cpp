#include "WindowManager.h"
#include <iostream>

WindowManager::WindowManager(int width, int height, const char* title) {
    initialize_();
}

int WindowManager::initialize_(){
    if (initialized_) {
        return 1;
    }
    
    int glfw_status = glfwInit();
    //Check if glfw initialized correctly
    if (glfw_status == 0) {
        std::cout << "GLFW has failed to initialize" << std::endl;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    initialized_ = 1;
}