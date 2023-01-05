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
	float positionX,positionY;   // Button's center x,y coordinates    
	float width, height;		 //	Button's width and height
	string text;				 // Text written inside the button surface				
	bool isClicked = false;		 // Button by default is not clicked

public:
	Button();					 //	Button's Constructor 
	~Button();					 //	Button's Destructor

	void  init(float posX,float posY,float width1,float height1,string text1);
	void  draw()   override;
	void  update() override;

	//checks if mouse is inside buttons surface
	bool  isInside(float mouseX,float mouseY);

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

	//isClicked getter/setter
	bool getIsClicked();
	void setIsClicked(bool isClicked1);
};