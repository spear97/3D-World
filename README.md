# 3D World

## Description

An Interactive 3D Environment project that was created during my Spring 2022 Semester at Texas Wesleyan University. A custom graphics Engine Made from Scratch Utilizing OpenGL and C++ to render different environment and spawn 3d object into the Environment. 

## Table of Contents
- Screenshots
  - UI
  - Forest Environment
  - Muddy Environment
  - Desert Environment
- Classes
  - Vector3d
  - ObjLoader
  - Polyhedron
- Technology
  - C++
  - OpenGL

## Screenshots

### Menu for user selection

![Custom Screenshot](https://github.com/spear97/3D-World/blob/main/ScreenShots/UI_A.png)  ![Custom Screenshot](https://github.com/spear97/3D-World/blob/main/ScreenShots/UI_B.png) 

### Default Environment

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

### Forest Environment

![Custom Screenshot](https://github.com/spear97/3D-World/blob/main/ScreenShots/ForestA.png) ![Custom Screenshot](https://github.com/spear97/3D-World/blob/main/ScreenShots/ForestB.png) ![Custom Screenshot](https://github.com/spear97/3D-World/blob/main/ScreenShots/ForestC.png) ![Custom Screenshot](https://github.com/spear97/3D-World/blob/main/ScreenShots/ForestD.png) ![Custom Screenshot](https://github.com/spear97/3D-World/blob/main/ScreenShots/ForestE.png) ![Custom Screenshot](https://github.com/spear97/3D-World/blob/main/ScreenShots/ForestF.png)    

### Muddy Environment

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
