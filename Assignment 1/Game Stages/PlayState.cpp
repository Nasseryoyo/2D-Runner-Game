#include "Game Stages/PlayState.h"

#include <cstdlib>
#include <ctime>

extern int windowHeight;
extern int windowWidth;

PlayState::PlayState() {
	player.init((windowWidth * 0.25), (windowHeight * 0.25));
	health.setLives(player.getHealth());
	score.setScore(player.getScore());
	levelGenerator.generateLevel();
}

void PlayState::enter(const std::vector<std::string>& enterParams) {

}

void PlayState::handleMouseClick(int button, int state, int x, int y) {

}

void PlayState::handleKeyPress(unsigned char key, int x, int y) {
	player.handleKeyPress(key, x, y);
}

void PlayState::update(float deltaTime) {

	// check collision with player
	for (auto& obstacle : levelGenerator.getObstacleManager().getObstacles()) {
		player.handleCollisionWithObstacle(obstacle);
		health.setLives(player.getHealth());
	}

	for (auto& collectible : levelGenerator.getCollectibleManager().getCollectibles()) {
		player.handleCollisionWithCollectible(collectible);
		score.setScore(player.getScore());
	}

	for (auto& powerUp : levelGenerator.getPowerUpManager().getPowerUps()) {
		player.handleCollisionWithPowerUp(powerUp);
	}

	time.updateTime(deltaTime);
	enviroment.update(deltaTime);
	health.drawHealth();
	score.drawScore();
	player.update(deltaTime);
	levelGenerator.update(deltaTime);


}

void PlayState::render() {
	enviroment.render();
	health.drawHealth();
	score.drawScore();
	time.drawTime();
	player.render();
	levelGenerator.render();
}

void PlayState::exit() {

}
