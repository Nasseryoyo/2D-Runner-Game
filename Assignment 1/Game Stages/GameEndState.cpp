#include <Game Stages/GameEndState.h>
#include <SoundManager.h>
#include <GL/glut.h>

extern SoundManager soundManager;

GameEndState::GameEndState() {
	playerScore = 0;

}

void GameEndState::enter(const std::vector<std::string>& enterParams) {
	// Initialize any state-specific properties if needed
	if (!enterParams.empty()) {
		playerScore = std::stoi(enterParams[0]);
	}
	soundManager.playBackgroundMusic("gameWin", true);
}

void GameEndState::handleMouseClick(int button, int state, int x, int y) {
	// Handle mouse click events
}

void GameEndState::handleKeyPress(unsigned char key, int x, int y) {
	// Handle key press events
}

void GameEndState::update(float deltaTime) {
	// Update state logic
}

void GameEndState::render() {
	// Render the end game screen
	glColor3f(1.0f, 1.0f, 1.0f); // Set color to white
	glRasterPos2f(100, 100); // Position the text
	std::string message = "Game Over! Your Score: " + std::to_string(playerScore);
	for (const char* c = message.c_str(); *c != '\0'; c++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
	}
}

void GameEndState::exit() {
	// Clean up any state-specific properties if needed
}
