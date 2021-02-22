#include "WindowManager.h"
#include <iostream>

WindowManager::WindowManager(int width, int height, const char* title){
    this->width_ = width;
    this->height_ = height;
    this->title_ = title;

    window_thread_ = new std::thread(create_window_);
}

WindowManager::~WindowManager(){
    delete[] window_thread_;
    delete[] window_;
    delete[] title_;
}

int WindowManager::create_window_() {
    int glfw_initialize_code = initialize_glfw_();

    if (glfw_initialize_code != 0) {
        std::cout << "GLFW has failed to initialize. Error code: " << glfw_initialize_code << std::endl;
        return;
    }

    this->window_ = glfwCreateWindow(this->width_, this->height_, this->title_, NULL, NULL);
    //Check if window was created successfully.
    if (this->window_ == NULL) {
        std::cout << "Window: '" << this->title_ << "' has failed to initialize" << std::endl;
        return;
    }

    glfwMakeContextCurrent(this->window_);
}

int WindowManager::initialize_glfw_(){
    if (initialized_) {
        return 1;
    }
    
    int glfw_status = glfwInit();
    //Check if glfw initialized correctly
    if (glfw_status == 0) {
        return 1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    initialized_ = 1;
}