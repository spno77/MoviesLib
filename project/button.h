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
	float positionX,positionY;   // Button's center x,y coordinates    
	float width, height;		 //	Button's width and height
	string text;				 // Text written inside the button surface				
	//bool isClicked = false;		 // Button by default is not clicked
						
public:
	Button();					 //	Button's Constructor 
	~Button();					 //	Button's Destructor

	void  init(float posX,float posY,float width1,float height1,string text1);
	void  draw()   override;
	void  update() override;

	//checks if mouse is inside buttons surface
	bool  isInside(float mouseX,float mouseY);

	// text getter/setter
	// Getters/setters for other member variables are inherited 
	// from RectWidget base class
	string getText();
	void setText(string text1);
};