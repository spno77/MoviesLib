#include "rectWidget.h"
#include "image.h"

// Image's Constructor
Image::Image()
{}

// Image's Destructor
Image::~Image()
{}


//initialize Image member variables
void Image::init(string path1,float posX,float posY,float width1,float height1)
{
	path 	  = path1;
	positionX = posX; 
	positionY = posY;   
	width     = width1;
	height    = height1;	
}

void Image::update()
{}

// Draws a Image in the screen
void Image::draw()
{
	graphics::Brush br;
	br.outline_opacity = 0.0f;
	SETCOLOR(br.fill_color,1.0,1.0,1.0);
	br.texture = path; 
    graphics::drawRect(positionX,positionY,width,height,br);

}

// Checks if mouse pointer is inside button surface
bool Image::isInside(float mouseX,float mouseY)
{
	if (positionX - (width/2) <= mouseX && mouseX <= positionX + (width/2))
		if (positionY - (height/2) <= mouseY && mouseY <= positionY + (height/2))
			return true;

	return false;
}


//text getter/setter
string Image::getPath(){ return path;}
void   Image::setPath(string path1){ path = path1;}