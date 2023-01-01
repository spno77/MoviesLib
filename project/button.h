#pragma once 

#include <iostream>
#include <sgg/graphics.h>
#include <string>

#include "config.h"

using namespace std;

class Button
{
	float positionX,positionY;   // x,y coordinates of Button's center    
	float width, height;		 //	Button's width and height

public:
	Button();
	~Button();

	void init(float posX,float posY,float width1,float height1);
	void draw();
	void update();

	bool isPressed(float mouseX,float mouseY);

	//positionX
	float getPositionX();
	void  setPositionX(float positionX1);

	//positionY
	float getPositionY();
	void  setPositionY(float positionY1);

	//width
	float getWidth();
	void  setWidth(float width1);

	//height
	float getHeight();
	void  setHeight(float height1);

};
