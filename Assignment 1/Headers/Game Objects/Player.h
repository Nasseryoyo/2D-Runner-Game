#pragma once
#include <Game Objects/Obstacle.h>
#include <Game Objects/Collectibles/PowerUp.h>
#include "Collectibles/Coin.h"

class Player {
public:
	Player();
	void init(float startX, float startY);
	void render();
	void update(float deltaTime);
	void handleKeyPress(unsigned char key, int x, int y);
	void jump();
	void duck();
	int getScore() const;
	int getHealth() const;
	void takeDamage();       // To reduce health
	void addScore(int points); // To add points to the score
	bool checkCollision(float objX, float objY, float objWidth, float objHeight);
	void setInvisible(bool flag);
	void setBoost(bool flag);
	bool getInvisible();
	void handleCollisionWithObstacle(Obstacle obstacle);
	void handleCollisionWithPowerUp(PowerUp powerUp);
	void handleCollisionWithCollectible(Coin coin);

private:
	float x, y;              // Position of the player
	float width, height;     // Player dimensions
	float dy;                // Change in y position
	bool isJumping;          // Flag to check if player is jumping
	bool isDucking;          // Flag to check if player is ducking
	float duckTime;          // Time spent ducking
	int health;              // Player health
	int score;               // Player score
	bool isInvisible;        // Invisibility flag
	bool isBoost;            // Jump Boost flag
	float invincibilityTimer;
	float boostTimer;
};
