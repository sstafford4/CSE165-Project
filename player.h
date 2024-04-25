#pragma once
#include "enemy.h"
#include <vector>
#include <cmath>
#include <GLFW/glfw3.h>
#include <iostream>

#include <cstdlib>
#include <ctime>


class Player {
private:
	// initial player position 
	float pos_x = 0.0f;
	float pos_y = 0.0f; 
	// initial player speed
	float pl_speed = 0.002f; // initial speed

public:
	//default constructor`
	Player() {
		pos_x = 0.0f;
		pos_y = 0.0f;
		pl_speed = 0.002f; 
	}
	Player(float initialX, float initialY, float initialSpeed)
		: pos_x(initialX), pos_y(initialY), pl_speed(initialSpeed) {}

	void moveLeft() { pos_x -= pl_speed; }
	void moveRight() { pos_x += pl_speed; }

	void player_display() const {

		glBegin(GL_QUADS);
		glColor3f(1.0f, 0.0f, 1.0f); // makes pink square
		//size of the square
		glVertex2f(pos_x, pos_y);
		glVertex2f(pos_x + 0.1f, pos_y);
		glVertex2f(pos_x + 0.1f, pos_y + 0.1f);
		glVertex2f(pos_x, pos_y + 0.1f);

		glEnd();
	}
	
	// function for use with collision, resets player square to leftmost side
	void death_reset() {
		pos_x = -1 + (static_cast<double>(rand()) / RAND_MAX) * (1 - (-1));
		pos_y = -1 + (static_cast<double>(rand()) / RAND_MAX) * (1 - (-1));
	}

	// accessor to grant access to the pos_x value
	float getPlayerX() const;

	// accessor to grant access to the pos_y value
	float getPlayerY() const;
};
