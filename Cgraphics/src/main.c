#include "../include/main.h"

float vertices[] = {
    -0.9f, -0.5f, 0.0f,  // left 
    -0.0f, -0.5f, 0.0f,  // right
    -0.45f, 0.5f, 0.0f, // bottom left
    -0.5f, 0.5f, 0.0f   // top left
};

unsigned int indices[] = {
    // note that we start from 0!
    0, 1, 3, // first triangle
    1, 2, 3  // second triangle
};

int main(void)
{        
    unsigned int vertexShader, fragmentShader, shaderProgram;
    unsigned int VBO, EBO;
    unsigned int VAO;
    const char *_vs, *_fs;
    char *vs, *fs;
    int success;
    char infoLog[512];

    // 1. intialize opengl
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
    {
        fprintf(stderr, "Failed to initialized GLFW\n");
        return (-1);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(800, 600, "Calculator", NULL, NULL);

    if (!window)
    {
        fprintf(stderr, "Failed to create window\n");
        glfwTerminate();
        return (-1);
    }
    glfwMakeContextCurrent(window);

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        fprintf(stderr, "failed\n");
        return (-1);
    }

    //beginning of actual graphics
    vs = read_shader("/home/eleven/knust-computer_graphics/Cgraphics/shaders/vertex.vs");
    fs = read_shader("/home/eleven/knust-computer_graphics/Cgraphics/shaders/fragment.fs");

    //vs = (const char *)_vs;
    //fs = (const char *)_fs;

    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    _vs = vs;
    glShaderSource(vertexShader, 1, &_vs, NULL);
    glCompileShader(vertexShader);
    free(vs);

    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n%s\n", infoLog);
    }

    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    _fs = fs;
    glShaderSource(fragmentShader, 1, &_fs, NULL);
    glCompileShader(fragmentShader);
    free(fs);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        printf("ERROR::SHADER::fragment::COMPILATION_FAILED\n%s\n", infoLog);
    }

    //link sharder programs 
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        printf("ERROR::SHADER::LINKING_FAILED\n%s\n", infoLog);
    }

    //clean up memory
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    //binding the vertices to vertix objects on 
    glGenVertexArrays(1, &VAO); // vertice array object
    glGenBuffers(1, &VBO);     //vertice buffer object
    glGenBuffers(1, &EBO);      //element buffer object

    glBindVertexArray(VAO);
    // 2. copy our vertices array in a vertex buffer for OpenGL to use
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    // 3. copy our index array in a element buffer for OpenGL to use
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    // 4. then set the vertex attributes pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); //wireframe

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.18f, 0.18f, 0.18f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(0);

        processInput(window);
        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    
    return (0);
}