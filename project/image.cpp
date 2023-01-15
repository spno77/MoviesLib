#include "rectWidget.h"
#include "image.h"

// Image's Constructor
Image::Image(string path1,float posX,float posY,float width1,float height1):
path(path1),RectWidget(posX,posY,width1,height1) 
{}

// Image's Destructor
Image::~Image()
{}

void Image::init()
{}

void Image::update()
{}

// Draws a Image in the screen
void Image::draw()
{
	graphics::Brush br;
	float h = 1.0f * m_highlighted;
    SETCOLOR(br.fill_color,h,h,h);
    br.outline_opacity = 1.0f * (m_active);
	
	SETCOLOR(br.fill_color,1.0,1.0,1.0);
	br.texture = path; 
    graphics::drawRect(positionX,positionY,width,height,br);
}

// path getter/setter
string Image::getPath(){ return path;}
void   Image::setPath(string path1){ path = path1;}

// setters for highlighted and active bool variables
void Image::setHighlight(bool highlight) { m_highlighted = highlight; }
void Image::setActive(bool active) { m_active = active; }
bool Image::getActive(){return m_active;}