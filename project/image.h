#pragma once

#include "config.h"
#include "rectWidget.h"

using namespace std;

//Image widget
class Image: public RectWidget
{
	string path;  				 // Path of image's png

	//Bool values that shows if image is active and highlighted
	bool m_highlighted = false;  
	bool m_active      = false;

public:
	Image(string path1,float posX,float posY,float width1,float height1);
	~Image();

	void  init()   override;
	void  draw()   override;
	void  update() override;

	//Path's getter/setter
	string getPath();
	void   setPath(string path1);

	//Setters for highllighted and active bool variables
	void setHighlight(bool highlight); 
	
	void setActive(bool active); 
	bool getActive();
};
