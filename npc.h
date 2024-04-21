#pragma once
#include<iostream>
#include<vector>
#include <GLFW/glfw3.h>
#include<cmath>

using namespace std;

// In the event that i cant get the npc moving back and forth, then I can do
// a bullet bill type enemy, where they move out of the stage and respawn.

class NPC {
 
	float square_pos_x = 0.0f; //initial position of square
	float sq_speed_x = 0.00005f; //speed of movement of the square
	// ideal speed is 0.00005f

	// variables for vertical movement
	float square_pos_y = 0.0f;
	float sq_speed_y = 0.00005f; // just setting it to the same as x.
public:
	NPC() {}; 
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
		if (square_pos_x > 0.8f || square_pos_x < -1.0f) {
			sq_speed_x = -sq_speed_x;
			square_pos_x += sq_speed_x;
		}
	}
	// will add vertical movement
	void vert_movement() {

	}

	~NPC() {}

};
