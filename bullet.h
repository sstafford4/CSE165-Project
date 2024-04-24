#pragma once
#include "player.h"
#include<iostream>
#include <GLFW/glfw3.h>

class Bullet {
private:
	float bul_x;
	float bul_y;
	float bul_speed;
	bool active;

public:
	Bullet(float initialX, float initialY, float initialSpeed)
		: bul_x(initialX), bul_y(initialY), bul_speed(initialSpeed), active(false) {}

	void setBulletPosition(float x_coord, float y_coord) {
		bul_x = x_coord;
		bul_y = y_coord;
		active = true;
	}

	void fired() {
		if (active) {
			bul_x += bul_speed;
		}
	}

	bool isActive() const {
		return active;
	}

	void display() {
		glBegin(GL_QUADS);
		glColor3f(1.0f, 1.0f, 0.0f);//yellow color
		//size of the square
		glVertex2f(bul_x, bul_y);
		glVertex2f(bul_x + 0.05f, bul_y);
		glVertex2f(bul_x + 0.05f, bul_y + 0.05f);
		glVertex2f(bul_x, bul_y + 0.05f);
		glEnd();
	}

	float getBulletX() const;
	float getBulletY() const;
};
