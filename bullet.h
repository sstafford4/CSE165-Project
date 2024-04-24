#pragma once
#include"player.h"
#include"npc.h"
#include<iostream>
#include<GLFW/glfw3.h>


class Bullet : public Player{
private:
	float bullet_x;
	float bullet_y;
	float bullet_speed; 

public:
	Bullet(float initialX, float initialY, float initialSpeed)
		: bullet_x(initialX), bullet_y(initialY), bullet_speed(initialSpeed) {}

	//Bullet(Player* playerX, Player* playerY, float initialSpeed) : bullet_x(playerX), bullet_y(playerY), bullet_speed(initialSpeed) {}

	void fire() {
		bullet_y += bullet_speed; 
	}

	void bullet_display(){
		glBegin(GL_QUADS);
		glColor3f(1.0f, 0.0f, 0.0f); // Red color
		glVertex2f(bullet_x, bullet_y);
		glVertex2f(bullet_x + 0.05f, bullet_y);
		glVertex2f(bullet_x + 0.05f, bullet_y + 0.05f);
		glVertex2f(bullet_x, bullet_y + 0.05f);
		glEnd();
	}
	// accessor
	//float returnBulletY() const;
};
