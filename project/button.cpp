#include "button.h"

// Button's Constructor
Button::Button()
{}

// Button's Destructor
Button::~Button()
{}


//initialize Button member variables
void Button::init(float posX,float posY,float width1,float height1,string text1)
{
	positionX = posX; 
	positionY = posY;   
	width     = width1;
	height    = height1;
	text      = text1;	
}

void Button::update()
{}

// Draws a Button in the screen
void Button::draw()
{
	graphics::Brush br;
	br.outline_opacity = 0.5f;

	SETCOLOR(br.fill_color,0.7,0.7,0.7);
    graphics::drawRect(positionX,positionY,width,height,br);

    graphics::setFont("assets//OpenSans-Regular.ttf");
    SETCOLOR(br.fill_color,0.1,0.2,0.1);
    graphics::drawText(positionX-5.5,positionY+1,4,text, br);
}

// Checks if mouse pointer is inside button surface
bool Button::isInside(float mouseX,float mouseY)
{
	if (positionX - (width/2) <= mouseX && mouseX <= positionX + (width/2))
		if (positionY - (height/2) <= mouseY && mouseY <= positionY + (height/2))
			return true;

	return false;
}


//text getter/setter
string Button::getText(){ return text;}
void   Button::setText(string text1){ text = text1;}