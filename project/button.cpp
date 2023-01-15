#include "button.h"

// Button's Constructor
Button::Button(float posX,float posY,float width1,float height1,string text1):
RectWidget(posX,posY,width1,height1),text(text1)
{}

// Button's Destructor
Button::~Button()
{}

void Button::init()
{}

void Button::update()
{}

// Draws a Button in the screen
void Button::draw()
{
	graphics::Brush br;
	
	SETCOLOR(br.fill_color,0.8,0.8,0.9);
	br.outline_opacity = 0.0f;
    br.texture = "assets//button.png";
    graphics::drawRect(positionX,positionY,width,height,br);

    graphics::setFont("assets//OpenSans-Regular.ttf");
    SETCOLOR(br.fill_color,0.0,0.0,0.0);
    
    int textPosX,textPosY;  			
    
    // where text is located in the screen 
    textPosX = positionX - (width/2)+1;
    textPosY = positionY + 1;
   
    graphics::drawText(textPosX,textPosY,4,text, br);
}

// Text getter/setter
string Button::getText(){ return text;}
void   Button::setText(string text1){ text = text1;}