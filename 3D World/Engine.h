#ifndef ENGINE_H_
#define ENGINE_H_

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <tuple>
using namespace std;

#include "Polyhedron.h"
#include "Basic.h"

/*************Callback Functions*************/

// Render changes to the current Scene
void renderScene(void);

// Update the Size of the Window
void changeSize(int w, int h);

// Determine actions when a key is pressed
void keyboard(unsigned char key, int x, int y);

// Determine actions when a key is pressed
void pressKey(int key, int xx, int yy);

// Determine actions when a key is released
void releaseKey(int key, int x, int y);

/*************Menu Creation Functions*************/

//Menu for Program to perform different Events
void menu(int num);

//Render Menu for Program
void createMenu(void);

/*************Computational Functions*************/

// Compute XZ Position
void computePos(float deltaMove);

// Compute Direction
void computeDir(float deltaAngle);

/*************OpenGL Initializer*****************/
void init();

/*************Speed Functions*************/

//SpeedUp Simulation
void SpeedUp();

//SlowDown Simulation
void SlowDown();

/*************3D Rendering Functions*************/

// Initialize a Pyramid Already Loaded into the Environment
void initPolyhedron();

// Load a File from a given filename
void loadFromFile(string filename, Vector3d center, double rot, Vector3d color);

// Clear all objects from the Environment
void clear();

/*************Environemntal Function*************/

void DefaultEnv(Vector3d color);

void Env1(Vector3d color);

void Env2(Vector3d color);

void Env3(Vector3d color);

/*************Variables for the application*************/

// Camera variables
vector<Polyhedron> polys;					// Collection of polygons for a given object
float angle = 0.0f;							// Angle of rotation for the camera direction
float lx = 0.614692f, lz = -0.788767f;		// Actual vector representing the camera's direction
float x = -26.8996f, z = 37.175f;			// XZ position of the camera

// Scene and rendering menu variables
float minBound = -100.f, maxBound = 100.f;								// The Bounds that the Ground Exist on
int submenu_Draw_id, submenu_Scene_id, submenu_CamSpeed_id, menu_id;	// The ids that will be used to navigate through the menu for spawn Renders
bool useDefault = true;													// Determine if Default should be rendered or not
bool alreadyGenerate = false;											// Determine if Objects have already been generated in the Scene or Not
bool isSimulating = false;												// Determine if a Simulation is running
bool slowDown = false;													// Determine if Camera needs to be slowed down
float deltaAngle = 0.f, deltaMove = 0.f;									// The key states. These variables will be zero when no key is being presses
int Env_ID;																// The Identifier for the Environment that will need to be rendered

// Lighting variables
GLfloat light_diffuse[] = { 0.8f, 0.8f, 0.8f, 0.9f };  // Red diffuse light
GLfloat light_position[] = { 1.0f, 1.0f, 1.0f, 0.0f }; // Infinite light location

#endif