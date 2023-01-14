#pragma once 

#include <iostream>
#include <sgg/graphics.h>
#include <string>
#include <vector>

#include "config.h"
#include "widget.h"
#include "movie.h"
#include "button.h"
#include "image.h"

using namespace std;

//MovieLib interface inherits from base class Widget
class Interface: public Widget{

public:
	enum interfaceState{STATE_INIT,STATE_CLICKED,STATE_DRAW};  

private:	
	list<Movie *> movieList;			// List with pointers to Movie objects
	list<Image *> imageList;			// List with pointers to Image objects
	Image *currentImage = nullptr;		// Image  pointer 
	Movie *currentMovie = nullptr;		// Movie  pointer
	Button *button 		= nullptr;		// Button pointer
	Button *info		= nullptr;	
	string input = "";

protected:
	static Interface* m_instance;
	interfaceState state = STATE_INIT;

public:

	Interface();						//Interface constructor
	~Interface();						//Interface destructor

	//overriden methods from base abstract class Widget
	void  init()   override;
    void  draw()   override;
	void  update() override;

	static void releaseInstance();
	static Interface* getInstance();

};