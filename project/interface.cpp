#include <iterator>
#include <list>
#include "interface.h"

Interface* Interface::m_instance = nullptr;

// Interface Constructor
Interface::Interface()
{
	createMovieList(movieList);
	button.init(CANVAS_WIDTH/2,CANVAS_HEIGHT-10,12,5,"Search");
}

// Interface Destructor
Interface::~Interface()
{
	destroyList(movieList); 
}


// Initialization of Interface member varialbes(is done in constructor)
void Interface::init()
{}

//Draws a Movie Interface
void Interface::draw()
{
	graphics::Brush br;
 	SETCOLOR(br.fill_color,0.0,0.1,0.1);

    graphics::setFont("assets//FFF_Tusj.ttf");
 	graphics::drawText(CANVAS_WIDTH/2 - 22,CANVAS_HEIGHT-74,8, "Movies", br);

 	button.draw();

 	float i = 0.0;
 	for (auto movie : movieList)
	{
		SETCOLOR(br.fill_color,1.0,1.0,1.0);
		//graphics::Brush br;
		br.texture = "assets//joker.png";
		graphics::drawRect(30+i,30,20,40,br);

		i += 22;
	}
	

	//graphics::drawRect(20,40,20,60,br);


 	if (button.getIsClicked() == true)
 	{
 		graphics::drawText(CANVAS_WIDTH/2,CANVAS_HEIGHT-35,10, "YEAS", br);	
 	}	
}

void Interface::update()
{
	graphics::MouseState mouse;
    getMouseState(mouse);

    float xx = graphics::windowToCanvasX(mouse.cur_pos_x);
    float yy = graphics::windowToCanvasY(mouse.cur_pos_y);

	if(mouse.button_left_pressed && button.isInside(xx,yy))
    {
     	button.setIsClicked(true);
    } 
    
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