#pragma once
#include<iostream>
#include<vector>
#include <GLFW/glfw3.h>

using namespace std;

class NPC {
	float square_pos = 0.0f; //initial position of square
	float sq_speed = 0.00005f; //speed of movement of the square
	

public:
	void display() {
		glClear(GL_COLOR_BUFFER_BIT);

		glBegin(GL_QUADS); 
		glColor3f(0.0f, 1.0f, 1.0f);// teal color
		//size of the square
		glVertex2f(square_pos, 0.0f);
		glVertex2f(square_pos + 0.2f, 0.0f);
		glVertex2f(square_pos + 0.2f, 0.2f);
		glVertex2f(square_pos, 0.2f);

		glEnd();
	}

	// placeholder for a potential second square
	/*void display2() {
		glClear(GL_COLOR_BUFFER_BIT);

		glBegin(GL_QUADS);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex2f(square + 1.0f, 0.0f);
		glVertex2f(square + 1.2f, 0.0f);
		glVertex2f(square + 1.2f, 1.2f);
		glVertex2f(square + 1.0f, 1.2f);

		glEnd();
	}*/

	// square currently moves to the right and stops at the border of the window
	void movement() {
		square_pos += sq_speed;
		if (square_pos > 0.8f || square_pos < -1.0f) {
			square_pos -= sq_speed;
			//square_pos += sq_speed; 
		}
	}
};
