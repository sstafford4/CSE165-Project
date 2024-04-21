#pragma once
#include "npc.h"
#include<vector>
#include<cmath>
#include<GLFW/glfw3.h>
#include<iostream>


using namespace std; 

class Player {
private:
	// initial player position 
	float pos_x = 0.0f;
	float pos_y = 0.0f; 
	// initial player speed
	float pl_speed = 0.001f; // initial speed

public:
	//default constructor
	Player(float initialX, float initialY, float initialSpeed)
		: pos_x(initialX), pos_y(initialY), pl_speed(initialSpeed) {}

	void moveUp() { pos_y += pl_speed; }
	void moveDown() { pos_y -= pl_speed; }
	void moveLeft() { pos_x -= pl_speed; }
	void moveRight() { pos_x += pl_speed; }

	void player_display() const {

		glBegin(GL_QUADS);
		glColor3f(1.0f, 0.0f, 1.0f);
		//size of the square
		glVertex2f(pos_x, pos_y);
		glVertex2f(pos_x + 0.2f, pos_y);
		glVertex2f(pos_x + 0.2f, pos_y + 0.2f);
		glVertex2f(pos_x, pos_y + 0.2f);

		glEnd();
	}
};
