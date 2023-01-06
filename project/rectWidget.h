#pragma once 

#include <iostream>
#include <sgg/graphics.h>
#include <string>

#include "config.h"
#include "widget.h"

using namespace std;

class RectWidget: public Widget
{
	float positionX,positionY;   // RectWidget's center x,y coordinates    
	float width, height;		 //	RectWidget's width and height				
	bool isClicked = false;		 // RectWidget by default is not clicked

public:
	RectWidget();
	~RectWidget();

	void  init(float posX,float posY,float width1,float height1);
	void  draw()   override;
	void  update() override;

	//checks if mouse is inside rectWidgets surface
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