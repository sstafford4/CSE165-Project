#pragma once
#include"player.h"
#include"enemy.h"
#include<iostream>
#include<GLFW/glfw3.h>


class Bullet{
private:
	float bullet_x;
	float bullet_y;
	float bullet_speed;
	bool active; 

public:
	Bullet(float initialX, float initialY, float initialSpeed)
		: bullet_x(initialX), bullet_y(initialY), bullet_speed(initialSpeed), active(false) {}


	void setBulletPosition(float x_coord, float y_coord) {
		bullet_x = x_coord;
		bullet_y = y_coord;
		active = true;
	}

	void fire() {
		if (active) {
			bullet_y += bullet_speed; 
		}
	}

	// boolean accessor
	bool isActive() const {
		return active; 
	}

	void bullet_display(){
		glBegin(GL_QUADS);
		glColor3f(1.0f, 1.0f, 0.0f); // Yellow color
		glVertex2f(bullet_x, bullet_y);
		glVertex2f(bullet_x + 0.05f, bullet_y);
		glVertex2f(bullet_x + 0.05f, bullet_y + 0.05f);
		glVertex2f(bullet_x, bullet_y + 0.05f);
		glEnd();
	}
	// accessor
	float returnBulletX() const; 
	float returnBulletY() const;
};
