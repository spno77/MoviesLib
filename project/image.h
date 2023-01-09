#pragma once

#include "config.h"
#include "rectWidget.h"

using namespace std;

//Image widget
class Image: public RectWidget
{
	string path;  				 // Path of image's png
	//float width, height;		 //	Image width and height
	//float positionX, positionY;	 // Image's position in canvas			
	//bool  isClicked = false;	 // isClicked by default is false

	//Bool values that shows if image is active and highlighted
	bool m_highlighted = false;  
	bool m_active      = false;

public:
	//Image();
	Image(string path1,float posX,float posY,float width1,float height1);
	~Image();

	void init();

	void  draw()   override;
	void  update() override;

	//checks if mouse is inside image surface
	//bool  isInside(float mouseX,float mouseY);

	//Path's getter/setter
	string getPath();
	void   setPath(string path1);

	//Setters for highllighted and active bool variables
	void setHighlight(bool highlight); 
	void setActive(bool active); 
};
