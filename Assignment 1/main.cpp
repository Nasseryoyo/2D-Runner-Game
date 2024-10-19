#include <Game Stages/StateManager.h>
#include <Game Stages/MenuState.h>
#include <Game Stages/PlayState.h>
#include <Game Stages/GameEndState.h>
#include <Game Stages/GameLoseState.h>
#include <random>  // For random number generation
#include <ctime>  // For time measurement
#include <SoundManager.h>
#include <GL/glut.h>

int windowWidth = 1280;  // Window width
int windowHeight = 720;  // Window height
float groundLevel = windowHeight * 0.25;  // Ground level for the player	

float speedUp = 0.0f;  // Speed up factor for the game

float lastTime = 0.0f;   // For keeping track of time between frames
std::default_random_engine generator(std::random_device{}());  // Random number generator

// State manager
StateManager gStateMachine({
	{"menu", []() -> State* { return new MenuState(); }},
	{"play", []() -> State* { return new PlayState(); }},
	{"gameover", []() -> State* { return new GameEndState(); }},
	{"gameoverlose", []() -> State* { return new GameLoseState(); }}
	});

SoundManager soundManager;  // Sound manager

void Display() {
	glClear(GL_COLOR_BUFFER_BIT);

	// Draw the current state
	gStateMachine.render();

	glFlush();
}

void update(int value) {
	// Calculate time passed between frames (deltaTime)
	float currentTime = glutGet(GLUT_ELAPSED_TIME) / 1000.0f;  // Time in seconds
	float deltaTime = currentTime - lastTime;
	lastTime = currentTime;

	// Update the current state
	gStateMachine.update(deltaTime);

	// Redraw the display
	glutPostRedisplay();

	// Continue calling this function every 16 milliseconds (~60 FPS)
	glutTimerFunc(16, update, 0);
}

void handleMouseClick(int button, int state, int x, int y) {
	// Convert the y-coordinate to match the coordinate system used in OpenGL
	y = windowHeight - y;

	// Handle mouse click in the current state
	gStateMachine.handleMouseClick(button, state, x, y);
}

void reshape(int w, int h) {
	windowWidth = w;
	windowHeight = h;

	glViewport(0, 0, windowWidth, windowHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, windowWidth, 0.0, windowHeight);
	glMatrixMode(GL_MODELVIEW);
}

void initWindow(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	// Set window size
	glutInitWindowSize(windowWidth, windowHeight);

	// Calculate the position to center the window
	int screenWidth = glutGet(GLUT_SCREEN_WIDTH);
	int screenHeight = glutGet(GLUT_SCREEN_HEIGHT);
	int windowPosX = (screenWidth - windowWidth) / 2;
	int windowPosY = (screenHeight - windowHeight) / 2;

	// Set window position (centered)
	glutInitWindowPosition(windowPosX, windowPosY);

	// Create the window
	glutCreateWindow("Runner Game");
}

void initSounds() {

	soundManager.addSound("jump", "Sounds/Effects/jump.wav");
	soundManager.addSound("collect", "Sounds/Effects/collect.wav");
	soundManager.addSound("hit", "Sounds/Effects/hurt.wav");
	soundManager.addSound("powerUp", "Sounds/Effects/powerup.wav");

	soundManager.addSound("play", "Sounds/BackGround/music.wav");
	soundManager.addSound("gameWin", "Sounds/BackGround/gameWin.wav");
	soundManager.addSound("gameLose", "Sounds/BackGround/gameLoss.wav");
}

int main(int argc, char** argr) {

	initWindow(argc, argr);
	initSounds();

	// Set up the display function
	glutDisplayFunc(Display);

	// Initialize lastTime (starting point for time tracking)
	lastTime = glutGet(GLUT_ELAPSED_TIME) / 1000.0f;  // In seconds

	// Set up the timer function to call updateHUD every 16 milliseconds (~60 FPS)
	glutTimerFunc(16, update, 0);

	// Set up the mouse click function
	glutMouseFunc(handleMouseClick);

	// Set up the keyboard function
	glutKeyboardFunc([](unsigned char key, int x, int y) {
		gStateMachine.handleKeyPress(key, x, y);
		});

	// Set up the special keyboard function
	glutSpecialFunc([](int key, int x, int y) {
		gStateMachine.handleKeyPress(key, x, y);
		});

	// Set up reshape function to handle window size changes
	glutReshapeFunc(reshape);

	// Initialize the state manager with the initial state (e.g., MenuState)
	gStateMachine.change("menu", {});



	// Start the main loop
	glutMainLoop();

	return 0;
}
