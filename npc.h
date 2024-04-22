#pragma once
#include<iostream>
#include<vector>
#include <GLFW/glfw3.h>
#include<cmath>


class NPC {
private:
	float square_pos_x = 0.6f; //initial position of square
	float sq_speed_x = 0.00005f; //speed of movement of the square
	// ideal speed is 0.00005f
	float square_pos_y = 0.0f;

public:
	NPC(float initialX, float initialY, float initialSpeed) {
		square_pos_x = initialX;
		square_pos_y = initialY;
		sq_speed_x = initialSpeed; 
		}; 
	void display() {

		glBegin(GL_QUADS); 
		glColor3f(0.0f, 1.0f, 1.0f);// teal color
		//size of the square
		glVertex2f(square_pos_x, 0.0f);
		glVertex2f(square_pos_x + 0.2f, 0.0f);
		glVertex2f(square_pos_x + 0.2f, 0.2f);
		glVertex2f(square_pos_x, 0.2f);

		glEnd();
	}

	// moves side to side
	void side_movement() {
		// in the window, 1 represents the right barrier, -1 represents the left barrier
		square_pos_x += sq_speed_x; 
		if (square_pos_x > 0.8f || square_pos_x < -0.4f) {
			sq_speed_x = -sq_speed_x;
			square_pos_x += sq_speed_x;
		}
	}
	// accessors 
	float getNpcX();
	float getNpcY();

	~NPC() {}

};
