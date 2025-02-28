#include "../include/main.h"

char *read_shader(const char *path)
{
    FILE *file = fopen(path, "r"); // Open file in read mode
    if (!file)
    {
        perror("Error opening shader file");
        printf("\n%s\n", path);
        return NULL;
    }

    // Seek to the end of the file to determine its size
    fseek(file, 0, SEEK_END);
    long filesize = ftell(file);
    rewind(file); // Go back to the start

    // Allocate memory for shader source (+1 for null terminator)
    char *shaderSource = (char *)malloc(filesize + 1);
    if (!shaderSource)
    {
        fclose(file);
        return NULL;
    }

    // Read the entire file into the allocated memory
    fread(shaderSource, 1, filesize, file);
    shaderSource[filesize] = '\0'; // Null-terminate the string

    fclose(file);
    return shaderSource;
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void error_callback(int error, const char *d)
{
    fprintf(stderr, "GLFW Error (%d): %s\n", error, d);
}

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}