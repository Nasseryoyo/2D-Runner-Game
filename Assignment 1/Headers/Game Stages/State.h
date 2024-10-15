
#pragma once
#include <vector>
#include <string>

class State {
public:
	State() {}
	virtual ~State() {}
	virtual void enter(const std::vector<std::string>& enterParams) = 0;
	virtual void update(float deltaTime) = 0;
	virtual void render() = 0;
	virtual void exit() = 0;
	virtual void handleMouseClick(int button, int state, int x, int y) = 0;
	virtual void handleKeyPress(unsigned char key, int x, int y) = 0;
};

