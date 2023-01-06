#pragma once

#include "config.h"
#include "rectWidget.h"

using namespace std;

class Image: public RectWidget
{
	string path;  				 //path of image asset in the filesystem
	float width, height;		 //	Button's width and height
	float positionX, positionY;				
	bool  isClicked = false;	

public:

	Image();
	~Image();

	void init(string path1,float posX,float posY,float width1,float height1);

	void  draw()   override;
	void  update() override;

	//checks if mouse is inside buttons surface
	bool  isInside(float mouseX,float mouseY);

	// text getter/setter
	string getPath();
	void   setPath(string path1);

};