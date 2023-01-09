#pragma once 

#include <iostream>
#include <sgg/graphics.h>
#include <string>

#include "config.h"
#include "widget.h"
#include "rectWidget.h"

using namespace std;

//class Button is a derived class of RectWidget
class Button: public RectWidget
{
	//float positionX,positionY;   // Button's center x,y coordinates    
	//float width, height;		 //	Button's width and height
	string text;				 // Text written inside the button surface				
	//bool isClicked = false;		 // Button by default is not clicked
						
public:
	Button(float posX,float posY,float width1,float height1,string text1);
	~Button();					 

	void  init();
	void  draw()   override;
	void  update() override;

	//checks if mouse is inside buttons surface
	//bool  isInside(float mouseX,float mouseY);

	string getText();
	void setText(string text1);
};