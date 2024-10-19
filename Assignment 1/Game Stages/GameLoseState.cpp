#include <Game Stages/GameLoseState.h>
#include <SoundManager.h>
#include <GL/glut.h>

extern SoundManager soundManager;

GameLoseState::GameLoseState() {
	playerScore = 0;
}

void GameLoseState::enter(const std::vector<std::string>& enterParams) {
	// Initialize any state-specific properties if needed
	if (!enterParams.empty()) {
		playerScore = std::stoi(enterParams[0]);
	}
	soundManager.playBackgroundMusic("gameLose", true);
}

void GameLoseState::handleMouseClick(int button, int state, int x, int y) {
	// Handle mouse click events
}

void GameLoseState::handleKeyPress(unsigned char key, int x, int y) {
	// Handle key press events
}

void GameLoseState::update(float deltaTime) {
	// Update state logic
}

void GameLoseState::render() {
	// Render the lose game screen
	glColor3f(1.0f, 0.0f, 0.0f); // Set color to red
	glRasterPos2f(100, 100); // Position the text
	std::string message = "You Lose! Your Score: " + std::to_string(playerScore);
	for (const char* c = message.c_str(); *c != '\0'; c++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
	}
}

void GameLoseState::exit() {
	// Clean up any state-specific properties if needed
}
