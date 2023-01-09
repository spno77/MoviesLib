#include "button.h"


Button::Button(float posX,float posY,float width1,float height1,string text1):
RectWidget(posX,posY,width1,height1),text(text1)
{}


// Button's Destructor
Button::~Button()
{}


//initialize Button member variables
void Button::init()
{}

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


//text getter/setter
string Button::getText(){ return text;}
void   Button::setText(string text1){ text = text1;}