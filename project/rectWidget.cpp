#include "rectWidget.h"

RectWidget::RectWidget(float posX,float posY,float width1,float height1):
positionX(posX),positionY(posY),width(width1),height(height1)
{}

RectWidget::~RectWidget()
{}

//initialize RectWidget member variables
void RectWidget::init()
{}

void RectWidget::update()
{}

// Draws a button in the screen
void RectWidget::draw()
{
	graphics::Brush br;
	br.outline_opacity = 0.5f;

	SETCOLOR(br.fill_color,0.7,0.7,0.7);
    graphics::drawRect(positionX,positionY,width,height,br);
}


// Checks if mouse pointer is inside button surface
bool RectWidget::isInside(float mouseX,float mouseY)
{
	if (positionX - (width/2) <= mouseX && mouseX <= positionX + (width/2))
		if (positionY - (height/2) <= mouseY && mouseY <= positionY + (height/2))
			return true;

	return false;
}

//positionX getter/setter
float RectWidget::getPositionX() { return positionX;}
void  RectWidget::setPositionX(float positionX1) { positionX = positionX1; }

//positionY getter/setter
float RectWidget::getPositionY() { return positionY; }
void  RectWidget::setPositionY(float positionY1) { positionY = positionY1; }

//width getter/setter
float RectWidget::getWidth() { return width; }
void  RectWidget::setWidth(float width1) { width = width1; }

//height getter/setter
float RectWidget::getHeight(){ return height; }
void  RectWidget::setHeight(float height1){ height = height1 ;}

//isClicked getter/setter
bool RectWidget::getIsClicked(){ return isClicked; }
void RectWidget::setIsClicked(bool isClicked1){ isClicked = isClicked1 ;}