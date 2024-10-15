#include "Game Stages/MenuState.h"
#include <Utils/Button.h>
#include <Game Stages/StateManager.h>
#include <string>
#include <GL/glut.h>

extern int windowWidth;
extern int windowHeight;
extern StateManager gStateMachine;

MenuState::MenuState() {
	// Set buttons relative to window size (percentages)
	this->playButton = Button("Play", (windowWidth * 0.46f), windowHeight * 0.57f, 100, 50);
	this->exitButton = Button("Exit", (windowWidth * 0.46f), windowHeight * 0.42f, 100, 50);
}

void MenuState::enter(const std::vector<std::string>& enterParams) {

}

void MenuState::render() {
	// Draw the play button
	playButton.draw();
	// Draw the exit button
	exitButton.draw();
}

void MenuState::update(float deltaTime) {

}

void MenuState::exit() {

}

void MenuState::handleMouseClick(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		if (playButton.isClicked(x, y)) {
			gStateMachine.change("play", {});
		}
		else if (exitButton.isClicked(x, y)) {
			exit();
		}
	}
}

void MenuState::handleKeyPress(unsigned char key, int x, int y) {

}
