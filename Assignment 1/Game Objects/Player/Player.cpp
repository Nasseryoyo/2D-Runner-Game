#include "Game Objects/Player.h"
#include <cmath>
#include <GL/glut.h>


extern int windowHeight;
extern int windowWidth;

const float gravity = 150.0f; // Gravity constant to affect jump velocity
const float jumpVelocity = 200.0f; // Initial jump velocity

const float duckDuration = 2.0f; // Duration to stay ducked in seconds
const float invincibilityDuration = 10.0f; // Duration of invisibility in seconds
const float boostDuration = 100.0f; // Duration of jump boost in seconds


extern float groundLevel; // Ground level for the player
float maxJumpHeight; // Maximum height the player can jump

Player::Player() {
	x = 0;
	y = 0;
	width = 10;
	height = 20;
	dy = 0;
	duckTime = 0.0f; // Initialize duck time
	isJumping = false;
	isDucking = false;
	isInvisible = false;
	isBoost = false;
	invincibilityTimer = invincibilityDuration;
	boostTimer = boostDuration;
	health = 5; // Initialize player health
	score = 0; // Initialize player score
}

void Player::takeDamage() {
	// Handle player taking damage
	if (health > 0) {
		health--;
	}
}

void Player::addScore(int points) {
	// Handle adding points to the player's score
	score += points;
}

int Player::getScore() const {
	return score;
}

int Player::getHealth() const {
	return health;
}

void Player::setInvisible(bool flag) {
	isInvisible = flag;
	invincibilityTimer = invincibilityDuration; // Reset invincibility timer
}

void Player::setBoost(bool flag) {
	isBoost = flag;
	boostTimer = boostDuration; // Reset boost timer
	maxJumpHeight = groundLevel + groundLevel * 0.90f; // Increase jump height
}

bool Player::getInvisible() {
	return isInvisible;
}

void Player::init(float startX, float startY) {
	// Initialize any player-specific properties if needed
	x = startX;
	y = startY;
	maxJumpHeight = groundLevel + groundLevel * 0.65;
}

void Player::jump() {
	// Handle jump logic
	if (!isJumping && y == groundLevel) {
		dy = jumpVelocity;
		isJumping = true;
	}
}

void Player::duck() {
	// Handle duck logic
	if (!isDucking && y == groundLevel) {
		height /= 2; // Halve the player's height
		isDucking = true;
		duckTime = 0.0f; // Reset duck time
	}
}

void Player::update(float deltaTime) {


	if (isJumping) {
		dy -= gravity * deltaTime;
		y += dy * deltaTime;

		// Check if player has reached max jump height
		if (y > maxJumpHeight) {
			y = maxJumpHeight;
			dy = 0;
		}

		// Check if player has landed
		if (y <= groundLevel) {
			y = groundLevel;
			dy = 0;
			isJumping = false;
		}
	}

	if (isDucking) {
		duckTime += deltaTime;
		if (duckTime >= duckDuration) {
			height *= 2; // Restore the player's height
			isDucking = false;
		}
	}

	// Handle Invisibility
	if (isInvisible) {
		invincibilityTimer -= deltaTime;
		if (invincibilityTimer <= 0.0f) {
			isInvisible = false;
		}
	}

	// Handle Jump Boost
	if (isBoost) {
		boostTimer -= deltaTime;
		if (boostTimer <= 0.0f) {
			isBoost = false;
			maxJumpHeight = groundLevel + groundLevel * 0.65f; // Reset jump height
		}
	}
}

void Player::handleKeyPress(unsigned char key, int x, int y) {
	if (key == GLUT_KEY_UP) {
		jump();
	}

	if (key == GLUT_KEY_DOWN) {
		duck();
	}
}

void Player::render() {
	glColor3f(0.0f, 0.0f, 1.0f); // Set color to blue
	glBegin(GL_QUADS);
	glVertex2f(x, y);
	glVertex2f(x + width, y);
	glVertex2f(x + width, y + height);
	glVertex2f(x, y + height);
	glEnd();
}

bool Player::checkCollision(float objX, float objY, float objWidth, float objHeight) {

	bool collided = (x <= objX + objWidth &&
		x + width >= objX &&
		y <= objY + objHeight &&
		y + height >= objY);



	return collided;
}

void Player::handleCollisionWithObstacle(Obstacle obstacle) {
	if (!isInvisible && checkCollision(obstacle.getX(), obstacle.getY(), obstacle.getWidth(), obstacle.getHeight())) {
		printf("player collided with obstacle");
		takeDamage();
	}
}

void Player::handleCollisionWithPowerUp(PowerUp powerUp) {
	if (checkCollision(powerUp.getX(), powerUp.getY(), powerUp.getWidth(), powerUp.getHeight())) {
		printf("player collided with powerup");
		if (powerUp.getPowerUpType() == 1) { // Assuming 1 is for invisibility
			setInvisible(true);
		}
		else if (powerUp.getPowerUpType() == 2) { // Assuming 2 is for jump boost
			setBoost(true);
		}
		powerUp.setCollected(true);
	}
}

void Player::handleCollisionWithCollectible(Coin coin) {
	printf("checkin player collided with coin");
	if (checkCollision(coin.getX(), coin.getY(), coin.getWidth(), coin.getHeight())) {
		printf("player collided with coin");
		coin.setCollected(true);
		addScore(100);
	}
}
