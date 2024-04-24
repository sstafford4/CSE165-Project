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

	virtual void b_movement() = 0; 
	virtual void b_display() const = 0;


};
