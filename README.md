# 3D World

## Description

An Interactive 3D Environment project that was created during my Spring 2022 Semester at Texas Wesleyan University. A custom graphics Engine Made from Scratch Utilizing OpenGL and C++ to render different environment and spawn 3d object into the Environment. 

## Table of Contents
- Screenshots
  - [UI](#UI)
  - [Forest Environment](#Forest)
  - [Muddy Environment](#Muddy)
  - [Desert Environment](#Desert)
- Classes
  - [Vector3d](#Vector3d)
  - [ObjLoader](#ObjLoader)
  - [Polyhedron](#Polyhedron)
- Technology
  - [Cpp](#Cpp)
  - [OpenGL](#OpenGL)

## Screenshots

### UI

![Custom Screenshot](https://github.com/spear97/3D-World/blob/main/ScreenShots/UI_A.png)  ![Custom Screenshot](https://github.com/spear97/3D-World/blob/main/ScreenShots/UI_B.png) 

### Default

![Custom Screenshot](https://github.com/spear97/3D-World/blob/main/ScreenShots/Default.png)  
How the application will load initially

![Custom Screenshot](https://github.com/spear97/3D-World/blob/main/ScreenShots/Default_Grass.png) 

3D Grass Object that was rendered from Grass.obj

![Custom Screenshot](https://github.com/spear97/3D-World/blob/main/ScreenShots/Default_Wukong.png) 

3D Wukong Object that was rendered from Wukong.obj

![Custom Screenshot](https://github.com/spear97/3D-World/blob/main/ScreenShots/Default-Military-Vehicle.png) 

3D MIlitary Vehicle Object that was rendered from MilitaryVehicle.obj

![Custom Screenshot](https://github.com/spear97/3D-World/blob/main/ScreenShots/Default-Patrick.png) 

3D Patrick Object that was rendered from patrick.obj

![Custom Screenshot](https://github.com/spear97/3D-World/blob/main/ScreenShots/Default-Sonic.png) 

3D Sonic Object that was rendered from Sonic.obj

### Forest 

![Custom Screenshot](https://github.com/spear97/3D-World/blob/main/ScreenShots/ForestA.png) ![Custom Screenshot](https://github.com/spear97/3D-World/blob/main/ScreenShots/ForestB.png) ![Custom Screenshot](https://github.com/spear97/3D-World/blob/main/ScreenShots/ForestC.png) ![Custom Screenshot](https://github.com/spear97/3D-World/blob/main/ScreenShots/ForestD.png) ![Custom Screenshot](https://github.com/spear97/3D-World/blob/main/ScreenShots/ForestE.png) ![Custom Screenshot](https://github.com/spear97/3D-World/blob/main/ScreenShots/ForestF.png)    

### Muddy 

![Custom Screenshot](https://github.com/spear97/3D-World/blob/main/ScreenShots/DirtA.png) ![Custom Screenshot](https://github.com/spear97/3D-World/blob/main/ScreenShots/DirtB.png) ![Custom Screenshot](https://github.com/spear97/3D-World/blob/main/ScreenShots/DirtC.png) ![Custom Screenshot](https://github.com/spear97/3D-World/blob/main/ScreenShots/DirtD.png) ![Custom Screenshot](https://github.com/spear97/3D-World/blob/main/ScreenShots/DirtE.png) ![Custom Screenshot](https://github.com/spear97/3D-World/blob/main/ScreenShots/DirtF.png) 

### Desert Environment

![Custom Screenshot](https://github.com/spear97/3D-World/blob/main/ScreenShots/DesertA.png) ![Custom Screenshot](https://github.com/spear97/3D-World/blob/main/ScreenShots/DesertB.png) ![Custom Screenshot](https://github.com/spear97/3D-World/blob/main/ScreenShots/DesertC.png) ![Custom Screenshot](https://github.com/spear97/3D-World/blob/main/ScreenShots/DesertD.png) ![Custom Screenshot](https://github.com/spear97/3D-World/blob/main/ScreenShots/DesertE.png) ![Custom Screenshot](https://github.com/spear97/3D-World/blob/main/ScreenShots/DesertF.png)

## Classes

### Vector3d

The `Vector3d` class represents a 3D vector with x, y, and z components. It includes various constructors, operator overloads, and functions for vector manipulation such as addition, subtraction, scalar multiplication, normalization, and rotation.

#### Usage

To use the `Vector3d` class in your project, include the `Vector3d.h` header file and make sure to link it properly.

```cpp
#include "Vector3d.h"
#include <iostream>

int main() {
    // Create vectors
    mathtool::Vector3d v1(1.0, 2.0, 3.0);
    mathtool::Vector3d v2(4.0, 5.0, 6.0);

    // Perform operations
    mathtool::Vector3d sum = v1 + v2;
    mathtool::Vector3d difference = v1 - v2;
    
    // Output results
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Difference: " << difference << std::endl;

    return 0;
}
```

#### Operators

The Vector3d class overloads the following operators:
- `+=`, `-=`: Addition and subtraction with another vector.
- `*=`: Scalar multiplication with a double.
- `/=`: Scalar division with a double.
- `==`, `!=`: Equality and inequality comparisons.
- `+`, `-`: Addition and subtraction of vectors.
- `*`: Dot product with another vector or scalar multiplication with a double.
- `/`: Scalar division with a double.
- `^`: Power with another vector.
- `%`: Cross product with another vector.
- `<<`: Output stream for vector.
- `>>`: Input stream for vector.

### Functions

The Vector3d class provides the following member functions:

- `norm()`: Get the norm (magnitude) of the vector.
- `normsqr()`: Get the squared norm of the vector.
- `selfNormalize()`: Normalize the vector in place.
- `normalize()`: Return a normalized copy of the vector.
- `comp()`: Find the component of this vector along another vector's direction.
- `selfScale()`: Scale the vector to a certain size in place.
- `scale()`: Return a scaled copy of the vector.
- `rotateX()`, `rotateY()`, `rotateZ()`: Rotate the vector about the X, Y, or Z axis by a given angle.
- `rotateXd()`, `rotateYd()`, `rotateZd()`: Rotate the vector about the X, Y, or Z axis by a given angle in degrees.
- `reset()`: Set all components of the vector to zero.
- `GetX()`, `GetY()`, `GetZ()`: Get individual components of the vector.
- `SetX()`, `SetY()`, `SetZ()`: Set individual components of the vector.

#### Examples

Here are some examples demonstrating the usage of the Vector3d class:

```cpp
#include "Vector3d.h"
#include <iostream>

int main() {
    mathtool::Vector3d v1(1.0, 2.0, 3.0);
    mathtool::Vector3d v2(4.0, 5.0, 6.0);

    // Addition
    mathtool::Vector3d sum = v1 + v2;
    std::cout << "Sum: " << sum << std::endl;

    // Scalar multiplication
    mathtool::Vector3d scaled = v1 * 2.0;
    std::cout << "Scaled: " << scaled << std::endl;

    // Dot product
    double dot = v1 * v2;
    std::cout << "Dot product: " << dot << std::endl;

    // Normalization
    mathtool::Vector3d normalized = v1.normalize();
    std::cout << "Normalized: " << normalized << std::endl;

    return 0;
}
```
### ObjLoader

The `ObjLoader` class provides functionality for loading Wavefront OBJ files, extracting vertex positions, texture coordinates, normals, and faces. It can be used to load 3D models from OBJ files for rendering or other purposes.

### Usage 

To use the `ObjLoader` class, include the `ObjLoader.h` header file in your C++ project.

### Functions

- `ObjLoader()`: Default constructor.
- `ObjLoader(string _fname)`: Constructor that sets the filename to load.
- `void Load()`: Loads the OBJ file specified by the filename.
- `void Print()`: Prints information about the loaded OBJ file.
- `vector<Vector3d> GetVertices()`: Returns the vector of vertex positions.
- `vector<pair<double, double>> GetTextureCoordinates()`: Returns the vector of texture coordinates.
- `vector<Vector3d> GetNormals()`: Returns the vector of normals.
- `vector<Face> GetFaces()`: Returns the vector of faces.

### Structs

#### Face

- `void Print()`: Prints the IDs of vertices in the face.
- `vector<int> ids`: Vector of vertex IDs for the face.
- `vector<int> texIds`: Vector of texture coordinate IDs for the face.
- `vector<int> normalIds`: Vector of normal IDs for the face.

### Examples

Here is an example of how to use the ObjLoader class:

```cpp
#include "ObjLoader.h"

int main() {
    ObjLoader obj("model.obj");
    obj.Load();

    obj.Print(); // Print information about the loaded model

    // Get the loaded data
    vector<Vector3d> vertices = obj.GetVertices();
    vector<pair<double, double>> texCoords = obj.GetTextureCoordinates();
    vector<Vector3d> normals = obj.GetNormals();
    vector<Face> faces = obj.GetFaces();

    // Use the data...
}
```

### ObjLoader

The `Polyhedron` class extends the functionality of `ObjLoader` to represent a 3D polyhedron. It includes methods for drawing the polyhedron, recentring its position, and adjusting its orientation. This class is useful for rendering and manipulating 3D models loaded from Wavefront OBJ files.

### Usage 
To use the `Polyhedron` class, include the `Polyhedron.h` header file in your C++ project.

```cpp
#include "Polyhedron.h"
```

### Creating a Polyhedron

You can create a Polyhedron instance by providing the filename of the OBJ file, center position, rotation angle around Y-axis, and color:

```cpp
Vector3d centerPosition(0.0, 0.0, 0.0);
double rotationY = 0.0; // in radians
Vector3d color(1.0, 0.0, 0.0); // Red color
Polyhedron poly("path/to/file.obj", centerPosition, rotationY, color);
```

### Drawing the Polyhedron

You can draw the polyhedron using the Draw() function:

```cpp
poly.Draw();
```

### Recentering

You can recentre the polyhedron's position using Recenter() or only on the XZ-plane using RecenterXZ():

```cpp
poly.Recenter();   // Recenters the polyhedron
poly.RecenterXZ(); // Recenters the polyhedron on the XZ-plane
```

### Constructors

- `Polyhedron(string _fname, Vector3d _c, double _rotY, Vector3d _clr)`: Constructor that takes the filename of the OBJ file, center position _c, rotation angle around Y-axis _rotY, and color _clr.
- `Polyhedron(const Polyhedron& other)`: Copy constructor.

### Functions

- `void Draw()`: Draws the polyhedron.
- `void Recenter()`: Recenters the polyhedron's position.
void RecenterXZ(): Recenters the polyhedron's position on the XZ-plane.

### Members

Vector3d center: Center position of the polyhedron.
double rotY: Rotation angle around the Y-axis.
Vector3d color: Color of the polyhedron.

### Examples

Here is an example of how to use the Polyhedron class:

```cpp
#include "Polyhedron.h"

int main() {
    Vector3d centerPosition(0.0, 0.0, 0.0);
    double rotationY = 0.0; // in radians
    Vector3d color(1.0, 0.0, 0.0); // Red color

    Polyhedron poly("model.obj", centerPosition, rotationY, color);
    poly.Load(); // Load the OBJ file
    poly.Recenter(); // Recenter the polyhedron
    poly.Draw(); // Draw the polyhedron

    return 0;
}
```

## Technology

### Cpp

#### What is C++?
C++ is a high-level programming language that was developed as an extension of the C programming language. It was created by Bjarne Stroustrup at Bell Labs in the early 1980s, and it has become one of the most widely used languages, particularly for systems programming, game development, and other performance-intensive applications.

#### Features of C++
- `Object-Oriented`: C++ supports the principles of object-oriented programming (OOP) such as classes, inheritance, polymorphism, encapsulation, and abstraction.

- `Efficient`: It allows low-level manipulation of data, making it suitable for system programming, embedded programming, and other performance-critical applications.

- `Standard Library`: C++ comes with a rich standard library that provides a set of functions manipulating various data structures, algorithms, and more.
- `Platform Independence`: C++ programs can run on different operating systems with minimal changes, thanks to its compilers available for various platforms.
- `Compatibility with C`: C++ is largely compatible with C code. It is possible to include C code in C++ programs, and many C programs can be compiled with a C++ compiler.

#### Use Cases

- `System Software`: Operating systems, device drivers, firmware, and other system-level software are often written in C++ due to its low-level capabilities.
- `Game Development`: Many game engines and game development frameworks (like Unreal Engine, Unity) use C++ as a primary language for game development due to its performance.
- `Application Software`: C++ is used for creating various types of applications, including desktop applications, web browsers (like Mozilla Firefox), productivity software, etc.
- `Embedded Systems`: C++ is used in embedded systems programming where resources are limited, but performance is crucial.
  
#### Example

Here's a simple "Hello, World!" program in C++:

```cpp
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
```

This program uses the iostream library to print "Hello, World!" to the console. The `main()` function is the entry point of the program, and `std::cout` is used for output. `<<` is the stream insertion operator used to output data to the console, and `std::endl` is used to end the line.

C++ has a rich syntax and many features beyond this simple example, making it a powerful and flexible language for a wide range of programming tasks.

### OpenGL

`OpenGL (Open Graphics Library)` is an open-source, cross-platform graphics `API (Application Programming Interface)` for rendering 2D and 3D vector graphics. It provides a set of functions for rendering complex 2D and 3D graphics, enabling developers to create interactive applications such as video games, simulations, visualizations, and more. `OpenGL` is widely used in the computer graphics industry and is supported on various platforms, including Windows, macOS, Linux, and mobile operating systems.

##### Features of OpenGL

- `Cross-Platform`: `OpenGL` is designed to be platform-independent, allowing developers to write code once and have it run on different operating systems without significant modifications.
- `Hardware Acceleration`: It takes advantage of the GPU (Graphics Processing Unit) in modern graphics cards, allowing for fast and efficient rendering of complex graphics.
- `Rendering Pipeline`: OpenGL follows a rendering pipeline model, where objects and scenes are transformed and rendered in stages, providing flexibility and control over the rendering process.
- `Shader Support`: OpenGL supports programmable shaders written in languages like `GLSL` (OpenGL Shading Language), allowing developers to create custom effects and manipulate graphics at a more granular level.
- `Community and Libraries`: There is a large community of developers using OpenGL, as well as various libraries and frameworks built on top of OpenGL (such as GLFW, GLM, and GLEW) that simplify common tasks and provide additional functionality.

#### Use Cases

- `Game Development`: OpenGL is widely used in the gaming industry for creating graphics-intensive games. Game engines like Unity and Unreal Engine use OpenGL (or its modern variant, Vulkan) as their rendering backend.
- `Scientific Visualization`: It is used in applications that require visualizing complex data, such as simulations, medical imaging, and CAD (Computer-Aided Design) software.
- `Virtual Reality (VR) and Augmented Reality (AR)`: OpenGL has been used in creating VR and AR applications, providing the necessary rendering capabilities for immersive experiences.
- `Computer-Aided Design (CAD)`: Many CAD applications rely on OpenGL for rendering 3D models and scenes.
- `Visual Effects (VFX) in Films`: OpenGL is also used in the film industry for creating visual effects and rendering scenes.

#### Example

Here's a simple example of an OpenGL program in C++ that creates a basic window and renders a colored triangle:

```cpp
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(640, 480, "OpenGL Window", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Define the vertices of a triangle
    GLfloat vertices[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

    // Create and bind a Vertex Array Object (VAO)
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    // Create a Vertex Buffer Object (VBO) and copy the vertex data to it
    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Specify the layout of the vertex data
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    // Main rendering loop
    while (!glfwWindowShouldClose(window)) {
        // Clear the color buffer
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw the triangle
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // Swap buffers and poll for events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Clean up
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    glfwTerminate();
    return 0;
}
```

This program creates a simple OpenGL window using GLFW, initializes GLEW for OpenGL extensions, and renders a colored triangle using vertex buffer objects (VBOs) and vertex array objects (VAOs). This example demonstrates the basic setup and rendering process in OpenGL.
