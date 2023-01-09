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
	string text;	// Text written inside the button surface								
public:
	Button(float posX,float posY,float width1,float height1,string text1);
	~Button();					 

	void  init()   override;
	void  draw()   override;
	void  update() override;

	string getText();
	void   setText(string text1);
};