#pragma once
#include<iostream>

class NPCVirt {
protected:
	float x;
	float y;
	float speed; 

public:

	NPCVirt(float initialX, float initialY, float initialSpeed)
		: x(initialX), y(initialY), speed(initialSpeed) {}

	virtual void side_movement() = 0;
	virtual void scroll_movement() = 0;
	virtual void display() const = 0;
	virtual void display(float r, float g, float b) = 0; 

	virtual void npc_death() = 0; 
};
