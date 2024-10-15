#pragma once

#include "State.h"
#include <HUD/Health.h>
#include <HUD/Score.h>
#include <HUD/Time.h>
#include <Game Objects/Player.h>
#include <Game Objects/Enviroment/Enviroment.h>
#include <Level/LevelGen.h>


extern int windowHeight;
extern int windowWidth;

class PlayState : public State {
public:
	PlayState();
	void enter(const std::vector<std::string>& enterParams) override;
	void update(float deltaTime) override;
	void handleMouseClick(int button, int state, int x, int y) override;
	void handleKeyPress(unsigned char key, int x, int y) override;
	void render() override;
	void exit() override;

private:
	Health health;
	Score score;
	Time time;
	Player player;
	Enviroment enviroment;
	LevelGen levelGenerator;
};
