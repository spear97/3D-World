#include "Engine.h"

//////////////OPENGL INITIALIZER/////////////////
void init()
{
	GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat mat_shininess[] = {50.0};
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_COLOR_MATERIAL);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	/* Enable a single OpenGL light */
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	/* Use depth buffering for hidden surface elimination */
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
}

//////////////3D RENDERING FUNCTIONS/////////////

//Initialize a Pyramid Already Loaded into the Environment
void initPolyhedron()
{
	Polyhedron p1("models/Pyramid.obj", Vector3d(0, 0, 0), 0, Vector3d(1, 1, 0));
	p1.Load();
	p1.Recenter();
	polys.push_back(p1);
}

//Load a File from a given filename
void loadFromFile(string filename, Vector3d center, double rot, Vector3d color)
{
	Polyhedron p1(filename, center, rot, color);
	p1.Load();
	p1.Recenter();
	polys.push_back(p1);
}

// Clear all objects from the Environment
void clear()
{
	if (!polys.empty())
	{
		polys.clear();
		initPolyhedron();
	}
}

//////////////COMPUTATIONAL FUNCTIONS///////////

// Compute XZ Position
void computePos(float deltaMove)
{
	//Calculation the value for X
	x += deltaMove * lx * 0.2f;

	//Calculation the value for Z
	z += deltaMove * lz * 0.2f;
}

// Compute Direction
void computeDir(float deltaAngle)
{
	//Caculate the value for angle
	angle += deltaAngle;

	//Calculate the vaule for lx
	lx = sin(angle);

	//Calculate the value for lz
	lz = -cos(angle);
}

//////////////CALLBACK FUNCTION//////////////

//Render changes to the current Scene
void renderScene(void)
{

	//If there is a Postional Change
	if (deltaMove)
	{
		computePos(deltaMove);
	}

	//If there is an Angle Change
	if (deltaAngle)
	{
		computeDir(deltaAngle);
	}

	//Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Reset transformations
	glLoadIdentity();

	//Set the camera
	gluLookAt(x, 1.0f, z, x + lx, 1.0f, z + lz, 0.0f, 1.0f, 0.0f);

	//Render - Environment Based on User Selection
	if (useDefault)
	{
		DefaultEnv(Vector3d(0.85f, 0.85f, 0.85f));
	}
	else
	{
		if (Env_ID == 0) //Environment 1 - Rendering
		{
			Env1(Vector3d(0.f, 1.f, 0.f));
		}
		else if (Env_ID == 1) //Environment 2 - Rendering
		{
			Env2(Vector3d(0.588f, 0.294f, 0.f));
		}
		else if (Env_ID == 2) //Environment 3 - Rendering
		{
			Env3(Vector3d(0.761f, 0.698f, 0.502f));
		}
	}

	//Draw Polygons
	for (int i = 0; i < (int)polys.size(); i++)
	{
		polys[i].Draw();
	}

	//Update to the current frame
	glutSwapBuffers();
}

//Update the Size of the Window
void changeSize(int w, int h)
{
	//Prevent a divide by zero, when window is too short
	// (you can't make a window of zero width)
	h = h == 0 ? 1 : h;
	float ratio = w * 1.0 / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(45.0f, ratio, 0.1f, 1000.0f);

	//Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

//When a Key is released determine what needs to be done
void keyboard(unsigned char key, int x, int y)
{
	//Kill Program
	if ((key == 'q') || (key == '27')) exit(0);
}

//When a Key is pressed determine what needs to be done
void pressKey(int key, int xx, int yy) 
{
	switch (key)
	{
	case GLUT_KEY_UP:
		deltaMove = slowDown ? 0.005f : 0.05f;
		break;
	case GLUT_KEY_DOWN:
		deltaMove = slowDown ? -0.005f : -0.05f;
		break;
	case GLUT_KEY_LEFT:
		deltaAngle = slowDown ? -0.0001f : -0.001f;
		break;
	case GLUT_KEY_RIGHT:
		deltaAngle = slowDown ? 0.0001f : 0.001f;
		break;
	}
}

//When a Key is released determine what needs to be done
void releaseKey(int key, int x, int y) 
{
	// If Stopped Turning
	if (key == GLUT_KEY_LEFT || key == GLUT_KEY_RIGHT) deltaAngle = 0.f;

	// If stopped Moving
	if (key == GLUT_KEY_UP || key == GLUT_KEY_DOWN) deltaMove = 0.f;
}

//////////////Environmetal Functions//////////////////

void DefaultEnv(Vector3d color)
{
	glColor3f(color[0], color[1], color[2]);
	glBegin(GL_QUADS);
	glVertex3f(minBound, 0.0f, minBound);
	glVertex3f(minBound, 0.0f, maxBound);
	glVertex3f(maxBound, 0.0f, maxBound);
	glVertex3f(maxBound, 0.0f, minBound);
	glEnd();
}

void Env1(Vector3d color)
{
	DefaultEnv(color);
}

void Env2(Vector3d color)
{
	DefaultEnv(color);
}

void Env3(Vector3d color)
{
	DefaultEnv(color);
}

//////////////SPEED FUNCTIONS//////////////

//SpeedUp Simulation
void SpeedUp()
{
	if (!slowDown) slowDown = true;
}

//SlowDown Simulation
void SlowDown()
{
	if (slowDown) slowDown = false;
}

//////////////MENU CREATION FUNCTIONS//////////////////

//Menu for Program to perform different Events
void menu(int num)
{
	switch (num)
	{
	case 0: //Kill the Simulation
		exit(0);
		break;
	case 1: //Clear all objects from current Environment
		clear();
		break;
	case 2: //Spawn Grass
		
		break;
	case 3: //Spawn Wukong
		
		break;
	case 4: //Spawn MilitaryVehicle
		
		break;
	case 5: //Spawn Patrick
		
		break;
	case 6: //Spawn Sonic
		
		break;
	case 7: //Render Environment 1
		
		break;
	case 8: //Render Environment 2
		
		break;
	case 9: //Render Environment 3
		
		break;
	case 10: //Render Default Environment

		break;
	case 11: //SlowDown the Simulation
		SlowDown();
		break;
	case 12: //SpeedUp the Simulation
		SpeedUp();
		break;
	}
}

//Render Menu for Program
void createMenu(void)
{
	submenu_Draw_id = glutCreateMenu(menu);
	glutAddMenuEntry("Grass", 2);
	glutAddMenuEntry("Wukong", 3);
	glutAddMenuEntry("Military Vehicle", 4);
	glutAddMenuEntry("Patrick", 5);
	glutAddMenuEntry("Sonic", 6);
	submenu_Scene_id = glutCreateMenu(menu);
	glutAddMenuEntry("Scene 1", 7);
	glutAddMenuEntry("Scene 2", 8);
	glutAddMenuEntry("Scene 3", 9);
	glutAddMenuEntry("Default Scene", 10);
	submenu_CamSpeed_id = glutCreateMenu(menu);
	glutAddMenuEntry("Fast", 11);
	glutAddMenuEntry("Slow", 12);
	menu_id = glutCreateMenu(menu);
	glutAddMenuEntry("Clear", 1);
	glutAddSubMenu("Draw", submenu_Draw_id);
	glutAddSubMenu("Environments", submenu_Scene_id);
	glutAddSubMenu("Camera Speed", submenu_CamSpeed_id);
	glutAddMenuEntry("Quit", 0);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

//////////////MAIN DRIVER//////////////////
int main(int argc, char** argv)
{
	// init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 640);
	glutCreateWindow("3D World");

	// register callbacks
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);

	glutKeyboardFunc(keyboard);
	glutSpecialFunc(pressKey);

	// here are the new entries
	glutIgnoreKeyRepeat(1);
	glutSpecialUpFunc(releaseKey);

	// OpenGL init
	glEnable(GL_DEPTH_TEST);
	init();
	initPolyhedron();
	createMenu();

	// enter GLUT event processing cycle
	glutMainLoop();

	return 1;
}