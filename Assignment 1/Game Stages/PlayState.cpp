#include "Game Stages/PlayState.h"
#include <SoundManager.h>
#include <cstdlib>
#include <ctime>
#include <Game Stages/StateManager.h>


extern int windowHeight;
extern int windowWidth;
extern float speedUp;
extern StateManager gStateMachine;
extern SoundManager soundManager;

PlayState::PlayState() {
	player.init((windowWidth * 0.25), (windowHeight * 0.25));
	health.setLives(player.getHealth());
	score.setScore(player.getScore());
	levelGenerator.generateLevel();
}

void PlayState::enter(const std::vector<std::string>& enterParams) {
	soundManager.playBackgroundMusic("play", true);
}

void PlayState::handleMouseClick(int button, int state, int x, int y) {

}

void PlayState::handleKeyPress(unsigned char key, int x, int y) {
	player.handleKeyPress(key, x, y);
}

void PlayState::update(float deltaTime) {

	speedUp += 0.2f;  // Increase the speed up factor

	if (player.getHealth() <= 0) {
		soundManager.stopBackgroundMusic();
		gStateMachine.change("gameoverlose", { std::to_string(player.getScore()) });
		return;
	}

	if (time.getTime() <= 0) {
		soundManager.stopBackgroundMusic();
		gStateMachine.change("gameover", { std::to_string(player.getScore()) });
		return;
	}

	// check collision with player
	for (auto& obstacle : levelGenerator.getObstacleManager().getObstacles()) {
		if (player.checkCollision(obstacle.getX(), obstacle.getY(), obstacle.getWidth(), obstacle.getHeight())) {
			player.takeDamage();
			player.setInvisible(true);
			soundManager.playSound("hit");
			health.setLives(player.getHealth());
			levelGenerator.resetLevel();
			break;
		}

	}

	for (auto& collectible : levelGenerator.getCollectibleManager().getCollectibles()) {
		if (player.checkCollision(collectible.getX(), collectible.getY(), collectible.getWidth(), collectible.getHeight())) {
			if (!collectible.isCollected()) {
				collectible.setCollected(true);
				player.addScore(100);
				soundManager.playSound("collect");
				score.setScore(player.getScore());
			}
		}
	}

	for (auto& powerUp : levelGenerator.getPowerUpManager().getPowerUps()) {
		if (player.checkCollision(powerUp.getX(), powerUp.getY(), powerUp.getWidth(), powerUp.getHeight())) {
			if (powerUp.getPowerUpType() == 1) { // Assuming 1 is for invisibility
				player.setInvisible(true);
			}
			else if (powerUp.getPowerUpType() == 2) { // Assuming 2 is for jump boost
				player.setBoost(true);
			}
			powerUp.setCollected(true);
			soundManager.playSound("powerUp");
		}
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
