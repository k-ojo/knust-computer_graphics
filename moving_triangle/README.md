# Computer Graphics Project

This project is part of the final examination in Computer Graphics at KNUST, demonstrating proficiency in OpenGL programming, shader management, and graphical transformations.

## Project Structure

### Source Files

- **`glad.c`** - Adds OpenGL Loader (GLAD) to the project.
- **`main.cpp`** - Contains the main function to initialize the application and handle the rendering loop.
- **`shaders.cpp`** - Defines methods for the `Shader` class, handling shader compilation and linking.
- **`translator.cpp`** - Helper file for translating graphical data.
- **`Callback_helpers.cpp`** - Provides helper functions for handling user input and callbacks.

### Shader Files (GLSL)

- **`fragment.fs`** - GLSL fragment shader file, defining pixel-level operations.
- **`vertex.vert`** - GLSL vertex shader file, defining vertex transformations.

### Build Configuration

- **`CMakeLists.txt`** - CMake configuration file for compiling the project.

## Libraries Used

- **GLFW** - Handles window creation and input.
- **GLAD** - Manages OpenGL function pointers.
- **GLM** - Provides a mathematics library for 3D graphics (vectors, matrices, transformations).

## Building the Project

To compile the project, follow these steps:

1. Ensure CMake, GLFW, GLAD, and GLM are installed on your system.
2. Clone the repository and navigate to the project folder.
3. Run the following commands:

   ```bash
   mkdir build
   cd build
   cmake ..
   make
