#include <iterator>
#include <list>
#include "interface.h"
#include <unistd.h>

Interface* Interface::m_instance = nullptr;

//Interface Constructor
Interface::Interface()
{
	createMovieList(movieList);
	button = new Button(CANVAS_WIDTH/2,CANVAS_HEIGHT-10,12,5,"Search");
	info   = new Button(50,46,8,5,"Info");

}

//Interface Destructor
Interface::~Interface()
{
	destroyList(movieList);
	delete button;
	delete info; 
}

//Initialization of Interface member varialbes(is done in constructor)
void Interface::init()
{}

//Draws a Movie Interface
void Interface::draw()
{
	graphics::Brush br;
 	SETCOLOR(br.fill_color,0.0,0.1,0.1);

    graphics::setFont("assets//FFF_Tusj.ttf");
 	graphics::drawText(CANVAS_WIDTH/2 - 11,CANVAS_HEIGHT-76,5, "Movies", br);

 	button->draw();
 
 	float i = 0.0;
 	for (auto movie : movieList)
	{
		Image *img = new Image(movie->getPosterPath(),20+i,22,23,33);
		imageList.push_back(img);
		i += 25;
		img->draw();
	}

	if (state == STATE_CLICKED)
	{
		for (auto image : imageList)
		{
			if (image->getIsClicked() == true)
			{	
				currentMovie = searchList(movieList,image->getPath());
			
				//Draw movie title in the screen
				graphics::drawText(8,50,6,currentMovie->getTitle(), br);

				// Draw static strings in the screen
				graphics::drawText(8,57,3,"Director :",br); 
				graphics::drawText(8,61,3,"Stars :",br); 
				graphics::drawText(8,65,3,"Genre :",br); 
				graphics::drawText(8,69,3,"Year :",br); 

				// Draw movie member variables in the scree				
				graphics::drawText(30,57,3,currentMovie->getDirectors(),br); 
				graphics::drawText(30,61,3,currentMovie->getStars(),br); 
				graphics::drawText(30,65,3,currentMovie->getGenre(),br); 
				graphics::drawText(30,69,3,to_string(currentMovie->getYear()),br);	
			}
		}		
	}
}

void Interface::update()
{
	
	graphics::MouseState mouse;
    getMouseState(mouse);

    float xx = graphics::windowToCanvasX(mouse.cur_pos_x);
    float yy = graphics::windowToCanvasY(mouse.cur_pos_y);
    
    
	



    if(mouse.button_left_pressed)
    {

   
    	for (auto image : imageList)
    	{
    		if (image->isInside(xx,yy))
    		{		
    	 		image->setIsClicked(true);
    		}
    		else
    		{
    			image->setIsClicked(false);
    		}
    	
    	state = STATE_CLICKED;
    		
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
