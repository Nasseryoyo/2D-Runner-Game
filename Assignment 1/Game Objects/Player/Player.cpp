#include "Game Objects/Player.h"
#include <cmath>
#include <SoundManager.h>
#include <GL/glut.h>

extern SoundManager soundManager;

extern int windowHeight;
extern int windowWidth;
extern float speedUp;

const float gravity = 300.0f; // Gravity constant to affect jump velocity
const float jumpVelocity = 350.0f; // Initial jump velocity

const float duckDuration = 2.0f; // Duration to stay ducked in seconds
const float invincibilityDuration = 5.0f; // Duration of invisibility in seconds
const float boostDuration = 5.0f; // Duration of jump boost in seconds


extern float groundLevel; // Ground level for the player
float maxJumpHeight; // Maximum height the player can jump

Player::Player() {
	x = 0;
	y = 0;
	width = 30;
	height = 60;
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

void Player::init(float startX, float startY) {
	// Initialize any player-specific properties if needed
	x = startX;
	y = startY;
	maxJumpHeight = groundLevel + groundLevel * 0.80f;
}

void Player::setBoost(bool flag) {
	isBoost = flag;
	boostTimer = boostDuration; // Reset boost timer
	maxJumpHeight = groundLevel + groundLevel * 1.1f; // Increase jump height
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



bool Player::getInvisible() {
	return isInvisible;
}



void Player::jump() {
	// Handle jump logic
	if (!isJumping && y == groundLevel) {
		dy = jumpVelocity;
		isJumping = true;
		soundManager.playSound("jump");
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
			maxJumpHeight = groundLevel + groundLevel * 0.80f; // Reset jump height
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
	// Draw a quad for the body
	glBegin(GL_QUADS);
	glVertex2f(x, y + height * 0.4f);
	glVertex2f(x + width, y + height * 0.4f);
	glVertex2f(x + width, y + height);
	glVertex2f(x, y + height);
	glEnd();

	// Draw a circle for the head
	float radius = width * 0.3f;
	float centerX = x + width * 0.5f;
	float centerY = y + height + radius;
	int numSegments = 100;
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(centerX, centerY);
	for (int i = 0; i <= numSegments; i++) {
		float angle = 2.0f * 3.1416 * i / numSegments;
		float dx = radius * cosf(angle);
		float dy = radius * sinf(angle);
		glVertex2f(centerX + dx, centerY + dy);
	}
	glEnd();

	// Draw lines for the arms
	glLineWidth(10.0f);
	glBegin(GL_LINES);
	glVertex2f(x, y + height);
	glVertex2f(x, y + height * 0.6f);
	glVertex2f(x + width, y + height);
	glVertex2f(x + width, y + height * 0.6f);
	glEnd();
	glLineWidth(1.0f);

	// Draw a quad strip for the legs
	glBegin(GL_QUAD_STRIP);
	glVertex2f(x + width * 0.2f, y + height * 0.4f);
	glVertex2f(x + width * 0.2f, y);
	glVertex2f(x + width * 0.4f, y + height * 0.4f);
	glVertex2f(x + width * 0.4f, y);
	glVertex2f(x + width * 0.6f, y + height * 0.4f);
	glVertex2f(x + width * 0.6f, y);
	glVertex2f(x + width * 0.8f, y + height * 0.4f);
	glVertex2f(x + width * 0.8f, y);
	glEnd();
}

bool Player::checkCollision(float objX, float objY, float objWidth, float objHeight) {

	bool collided = (x <= objX + objWidth &&
		x + width >= objX &&
		y <= objY + objHeight &&
		y + height >= objY);



	return collided;
}

