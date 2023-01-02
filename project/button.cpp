#include "button.h"

// Button Constructor
Button::Button()
{}

// Button Destructor
Button::~Button()
{}

//initialize Button memmber variables
void Button::init(float posX,float posY,float width1,float height1,string text1)
{
	positionX = posX; 
	positionY = posY;   
	width     = width1;
	height    = height1;
	text      = text1;	
}

void Button::update()
{
	graphics::MouseState mouse;
    getMouseState(mouse);

    float xx = graphics::windowToCanvasX(mouse.cur_pos_x);
    float yy = graphics::windowToCanvasY(mouse.cur_pos_y);

    /*if(mouse.button_left_pressed and isPressed()){

    }
    */
}

// Draws a button in the screen
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
bool Button::isPressed(float mouseX,float mouseY)
{
	if (positionX - (width/2) <= mouseX && mouseX <= positionX + (width/2))
		if (positionY - (height/2) <= mouseY && mouseY <= positionY + (height/2))
			return true;

	return false;
}

//positionX getter/setter
float Button::getPositionX() { return positionX;}
void  Button::setPositionX(float positionX1) { positionX = positionX1; }

//positionY getter/setter
float Button::getPositionY() { return positionY; }
void  Button::setPositionY(float positionY1) { positionY = positionY1; }

//width getter/setter
float Button::getWidth() { return width; }
void  Button::setWidth(float width1) {width = width1; }

//height getter/setter
float Button::getHeight(){ return height; }
void  Button::setHeight(float height1){height = height1 ;}
