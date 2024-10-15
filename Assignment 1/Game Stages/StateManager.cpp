#include "Game Stages/StateManager.h"
#include "Game Stages/State.h"


StateManager::StateManager(const std::map<std::string, std::function<State* ()>>& states) : states(states) {
	current = nullptr;
}

StateManager::~StateManager() {
	if (current) {
		current->exit();
	}
}

void StateManager::handleMouseClick(int button, int state, int x, int y) {
	if (current) {
		current->handleMouseClick(button, state, x, y);
	}
}

void StateManager::handleKeyPress(unsigned char key, int x, int y) {
	if (current) {
		current->handleKeyPress(key, x, y);
	}
}

void StateManager::change(const std::string& stateName, const std::vector<std::string>& enterParams) {
	auto it = states.find(stateName);
	if (it != states.end()) {
		current = it->second();
		current->enter(enterParams);
	}
}

void StateManager::update(float dt) {
	if (current) {
		current->update(dt);
	}
}

void StateManager::render() {
	current->render();

}