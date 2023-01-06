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
 	graphics::drawText(CANVAS_WIDTH/2 - 11,CANVAS_HEIGHT-76,5, "Movies", br);

 	button.draw();
	
 	float i = 0.0;
 	for (auto movie : movieList)
	{
		Image *img = new Image;
		img->init(movie->getPosterPath(),20+i,CANVAS_HEIGHT-58,23,33);
		imageList.push_back(img);
		i += 25;
		img->draw();
	}
	

	for (auto image : imageList)
	{
		if (image->getIsClicked() == true)
		{
			currentMovie = searchList(movieList,image->getPath());
			graphics::drawText(CANVAS_WIDTH/2,CANVAS_HEIGHT-30,10,currentMovie->getTitle(), br);	
		}
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

    //if mouse is inside a certain image make that current
    for (auto image : imageList)
    {
    	if(mouse.button_left_pressed && image->isInside(xx,yy))
    	{
     		currentImage = image;
     		currentImage->setIsClicked(true);
    	}
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
