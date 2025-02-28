#ifndef _MAIN_
#define _MAIN_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "glad.h"
#include <GLFW/glfw3.h>
#include <math.h>

char *read_shader(const char *path);
void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void error_callback(int error, const char *d);
void processInput(GLFWwindow *window);

#endif