#include <iterator>
#include <list>
#include "interface.h"
#include <unistd.h>

Interface* Interface::m_instance = nullptr;

//Interface Constructor
Interface::Interface()
{
	createMovieList(movieList);
	filterButton = new Button(CANVAS_WIDTH-30,57,12,5,"Filter");
	info   		 = new Button(50,46,8,5,"Info");


	string genres[] = {"thriller","horror","drama","action"};

	float ii = 0.0f;
	for(int i = 0 ; i < GENRE_NUM; i++)
	{
		genreButton[i] = new Button(25+ii,15,12,5,genres[i]);
		ii+=30;
	}

	backButton = new Button(6,CANVAS_HEIGHT-78,12,5,"Back");

}

//Interface Destructor
Interface::~Interface()
{
	destroyList(movieList);
	delete filterButton;
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

	//STATE INIT
	if (state == STATE_INIT)
	{
	 	float i = 0.0;
 		for (auto movie : movieList)
		{
			Image *img = new Image(movie->getPosterPath(),20+i,22,23,33);
			imageList.push_back(img);
			i += 25;
		}
		state = STATE_DRAW;
		return;
	}
	//STATE DRAW
	if (state == STATE_DRAW)
	{
		for (auto image : imageList)
		{
			image->draw();
		}
		state = STATE_CLICKED;
		return;
	}
	
 	//STATE CLICKED
	if (state == STATE_CLICKED)
	{		
		filterButton->draw();

		if (filterButton->getIsClicked()== true )
		{
			state = STATE_FILTER;
			return;
		}
	
		for (auto image : imageList)
		{
			image->draw();

			if (image->getIsClicked() == true)
			{	
				currentMovie = searchListByPoster(movieList,image->getPath());
				info->draw();

				//Draw movie title in the screen
				graphics::drawText(8,50,6,currentMovie->getTitle(), br);
			}

			if (info->getIsClicked() == true)
				{
					//Draw movie title in the screen
					graphics::drawText(8,50,6,currentMovie->getTitle(), br);

					//Draw static string in the screen
					graphics::drawText(8,57,3,"Director :",br); 
					graphics::drawText(8,61,3,"Stars :",br); 
					graphics::drawText(8,65,3,"Genre :",br); 
					graphics::drawText(8,69,3,"Year :",br); 

					// Draw movie member variables in the screen				
					graphics::drawText(30,57,3,currentMovie->getDirectors(),br); 
					graphics::drawText(30,61,3,currentMovie->getStars(),br); 
					graphics::drawText(30,65,3,currentMovie->getGenre(),br); 
					graphics::drawText(30,69,3,to_string(currentMovie->getYear()),br);	
				}
		}		
		state = STATE_DRAW;
		return;
	}

	//STATE FILTER
	if (state == STATE_FILTER)
	{

		//draw backButton
		backButton->draw();

		if (backButton->getIsClicked() == true)
		{
			state = STATE_DRAW;
			backButton->setIsClicked(false);
			filterButton->setIsClicked(false);
			return;
		}

		graphics::drawText(6,10,5,"Select Genre:",br);
		for(int i = 0; i < GENRE_NUM; i++){
			genreButton[i]->draw();
		}

		for (int i = 0; i < GENRE_NUM; ++i)
		{
			if (genreButton[i]->getIsClicked())
			{
				Movie *movie = nullptr; //movie pointer
				movie = searchListByGenre(movieList,genreButton[i]->getText());

				//Draw static string in the screen
				graphics::drawText(8,57,3,"Director :",br); 
				graphics::drawText(8,61,3,"Stars :",br); 
				graphics::drawText(8,65,3,"Genre :",br); 
				graphics::drawText(8,69,3,"Year :",br); 

				graphics::drawText(8,50,6,movie->getTitle(), br);
				
				// Draw movie member variables in the screen				
				graphics::drawText(30,57,3,movie->getDirectors(),br); 
				graphics::drawText(30,61,3,movie->getStars(),br); 
				graphics::drawText(30,65,3,movie->getGenre(),br); 
				graphics::drawText(30,69,3,to_string(movie->getYear()),br);	
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


	if (state == STATE_INIT)
	{
		state = STATE_DRAW;
	}

	if (state == STATE_DRAW)
	{
		//button->setIsClicked(false);
		state = STATE_CLICKED;
	}

	if (state == STATE_CLICKED)
	{
		
    	if(mouse.button_left_pressed)
    	{
    		if (filterButton->isInside(xx,yy))
    		{
    			filterButton->setIsClicked(true);
    			state = STATE_FILTER;		
 				return;   		
    		}
    		else
    		{
    			filterButton->setIsClicked(false);
    		}


   			for (auto image : imageList)
    		{
    			if (info->isInside(xx,yy) && image->isInside(xx,yy) == false)
    			{
					info->setIsClicked(true);    		
    			}
    			else
    			{
    				info->setIsClicked(false);
    			}
    			if (image->isInside(xx,yy))
    			{		
    	 			image->setIsClicked(true);
    			}
    			else
    			{
    				image->setIsClicked(false);
    			}
			}
			state = STATE_DRAW;
 		}
	}

	if (state == STATE_FILTER)
	{
		if (mouse.button_left_pressed)
		{
			if (backButton->isInside(xx,yy))
			{
				backButton->setIsClicked(true);
				state = STATE_DRAW;
			}
			else
			{
				backButton->setIsClicked(false);
			}

			for (int i = 0; i < GENRE_NUM; ++i)
			{
				if (genreButton[i]->isInside(xx,yy))
				{
					genreButton[i]->setIsClicked(true);
				}
				else
				{
					genreButton[i]->setIsClicked(false);
				}
			}
			
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