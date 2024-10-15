#pragma once
#include "State.h"
#include "Utils/Button.h"
#include "StateManager.h"
class MenuState : public State {
public:
	MenuState();
	void enter(const std::vector<std::string>& enterParams) override;

	void update(float deltaTime) override;

	void handleMouseClick(int button, int state, int x, int y) override;

	void handleKeyPress(unsigned char key, int x, int y) override;

	void render() override;

	void exit() override;

private:
	Button playButton;
	Button exitButton;

};

