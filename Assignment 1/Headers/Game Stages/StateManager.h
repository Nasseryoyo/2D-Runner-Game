#pragma once
#include <map>
#include <functional>
#include <string>
#include <vector>
#include "State.h"

class StateManager {

public:
	StateManager(const std::map<std::string, std::function<State* ()>>& states);
	~StateManager();
	void change(const std::string& stateName, const std::vector<std::string>& enterParams);
	void update(float dt);
	void render();
	void handleMouseClick(int button, int state, int x, int y);
	void handleKeyPress(unsigned char key, int x, int y);


private:
	State* current;
	std::map<std::string, std::function<State* ()>> states;
};



