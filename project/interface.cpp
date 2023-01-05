#include "interface.h"

Interface* Interface::m_instance = nullptr;

// Interface Constructor
Interface::Interface()
{
	createMovieList(movieList);
	button.init(CANVAS_WIDTH/2,CANVAS_HEIGHT/2,12,5,"Search");
}

// Interface Destructor
Interface::~Interface()
{
	destroyList(movieList); 
}


// Initialization of Interface member varialbes(is done in constructor)
void Interface::init()
{
	
}

//Draws a Movie Interface
void Interface::draw()
{
	graphics::Brush br;
 	SETCOLOR(br.fill_color,0.0,0.1,0.1);

    graphics::setFont("assets//FFF_Tusj.ttf");
 	graphics::drawText(CANVAS_WIDTH/2 - 22,CANVAS_HEIGHT-74,8, "Movies", br);

 	button.draw();	
}

void Interface::update()
{
	
}


Interface* Interface::getInstance() {
	if (m_instance == nullptr) {
		m_instance = new Interface();			 
	}
	return m_instance;
}

void Interface::releaseInstance() {
	if (m_instance != nullptr) {
		delete m_instance;
	}

	m_instance = nullptr;		 
}