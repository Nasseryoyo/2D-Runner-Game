#pragma once

#include "Game Stages/State.h"

class GameLoseState : public State {
public:
	GameLoseState();
	void enter(const std::vector<std::string>& enterParams) override;
	void handleMouseClick(int button, int state, int x, int y) override;
	void handleKeyPress(unsigned char key, int x, int y) override;
	void update(float deltaTime) override;
	void render() override;
	void exit() override;
private:
	int playerScore;
};

