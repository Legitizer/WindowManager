#ifndef _WindowManager_H
#define _WindowManager_H

#include "../include/GLFW/glfw3.h"

class WindowManager {
public:
WindowManager(int width, int height, const char* title);
private:
static int initialized_;
GLFWwindow *window_;

//Window properties
int width_, height_;
const char* title;

int initialize_();
int create_window_();


};

#endif