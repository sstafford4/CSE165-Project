#pragma once
#include<iostream>
#include<GLFW/glfw3.h>
#include "NPCVirt.h"



class Enemy : public NPCVirt{
private:
	bool moving;

public:
	Enemy()
		: NPCVirt(-0.1f, 0.7f, 0.0005f), moving(true) {}

	Enemy(float initialX, float initialY, float initialSpeed)
		: NPCVirt(initialX, initialY, initialSpeed), moving(true) {}

	void scroll_movement() override {
		if (moving) {
			x += speed;
			if (x > 1.0f) {
				x = -1.1f; // teleporting all the way to the left side
			}
		}
	}

	void side_movement() override{
		// in the window, 1 represents the right barrier, -1 represents the left barrier
		x += speed;
		if (x > 0.8f || x < -1.0f) {
			speed = -speed;
			x += speed;
		}
	}

	void display() const override{
		glBegin(GL_QUADS);
		glColor3f(1.0f, 0.0f, 0.0f);// red color
		//size of the square
		glVertex2f(x, y);
		glVertex2f(x + 0.2f, y);
		glVertex2f(x + 0.2f, y + 0.2f);
		glVertex2f(x, y + 0.2f);

		glEnd();
	}

	void display(float r, float g, float b) override{
		glBegin(GL_QUADS);
		glColor3f(r, g, b);
		glVertex2f(x, y);
		glVertex2f(x + 0.2f, y);
		glVertex2f(x + 0.2f, y + 0.2f);
		glVertex2f(x, y + 0.2f);

		glEnd();
	}

	void npc_death() override{
		moving = false;
		x = 1.5f;
	}

	// accessors
	float enemyX();
	float enemyY(); 
};
