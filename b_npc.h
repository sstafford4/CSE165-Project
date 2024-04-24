#pragma once
#include "NPCVirt.h"
#include<GLFW/glfw3.h>
#include<iostream>

// the purpose of this header is to create a bullet bill type enemy that does not move side to side
// but rather teleports back to one side when it reaches the end. 

class BNPC : public NPCVirt {
private:
	bool moving; 

public:
	BNPC(float initialX, float initialY, float initialSpeed)
		: NPCVirt(initialX, initialY, initialSpeed), moving(true) {}

	void b_movement() override{
		if (moving) {
			x += speed;
			if (x > 0.8f) {
				x = -1.0f; // teleporting all the way to the left side
			}
		}
	}

	void b_display() const override {
		glBegin(GL_QUADS);
		glColor3f(1.0f, 0.0f, 0.0f);// red color
		//size of the square
		glVertex2f(x, y);
		glVertex2f(x + 0.2f, y);
		glVertex2f(x + 0.2f, y + 0.2f);
		glVertex2f(x, y + 0.2f);

		glEnd();
	}

	float getBX();
	float getBY();

};
