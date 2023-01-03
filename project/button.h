#pragma once 

#include <iostream>
#include <sgg/graphics.h>
#include <string>

#include "config.h"
#include "widget.h"

using namespace std;

//class Button is a derived class of Widget abstract class
class Button: public Widget
{
	float positionX,positionY;   // x,y coordinates of Button's center    
	float width, height;		 //	Button's width and height
	string text;				 // Text written inside the button surface				

public:
	Button();
	~Button();

	void  init(float posX,float posY,float width1,float height1,string text1);
	void  draw() override;
	void update() override;

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
