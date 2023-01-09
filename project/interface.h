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

	list<Movie *> movieList;
	list<Image *> imageList;
	Image *currentImage = nullptr;
	Movie *currentMovie = nullptr;
	Button *button;

protected:
	static Interface* m_instance;

public:
	Interface();
	~Interface();

	void  init();
    void  draw()   override;
	void  update() override;

	static void releaseInstance();
	static Interface* getInstance();
};