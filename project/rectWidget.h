#pragma once 

#include <iostream>
#include <sgg/graphics.h>
#include <string>

#include "config.h"
#include "widget.h"

using namespace std;

//Rectangular Widget class(All rectangular widgets will use this as base class)
class RectWidget: public Widget
{

protected:
	float positionX,positionY;   // RectWidget's center x,y coordinates    
	float width, height;		 //	RectWidget's width and height				
	bool  isClicked = false;	 // RectWidget by default is not clicked

public:
	//RectWidget();
	RectWidget(float posX,float posY,float width1,float height1);
	~RectWidget();

	void  init();
	void  draw()   override;
	void  update() override;

	//checks if mouse is inside rectWidget's surface
	bool isInside(float mouseX,float mouseY);

	//positionX getter/setter
	float getPositionX();
	void  setPositionX(float positionX1);

	//positionY getter/setter
	float getPositionY();
	void  setPositionY(float positionY1);

	//width getter/setter
	float getWidth();
	void  setWidth(float width1);

	//height getter/setter
	float getHeight();
	void  setHeight(float height1);

	//isClicked getter/setter
	bool getIsClicked();
	void setIsClicked(bool isClicked1);	
};