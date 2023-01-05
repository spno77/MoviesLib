#pragma once 

#include <iostream>
#include <sgg/graphics.h>
#include <string>

#include "config.h"
#include "widget.h"
#include "movie.h"
#include "button.h"

using namespace std;

//MovieLib interface inherits from base class Widget
class Interface: public Widget{

	list<Movie *> movieList;
	Button button;

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