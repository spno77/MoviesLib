#include <iostream>
#include <sgg/graphics.h>
#include <string>

#include "config.h"
#include "button.h"
#include "movie.h"

using namespace std;

// Global variables for test purposes
Button bt2;
Movie movie("pio",1212,"asdasd","asda","asdsd" );
bool test = false;
list<Movie *> movieList;


void update(float ms)
{
 	graphics::MouseState mouse;
    getMouseState(mouse);

    float xx = graphics::windowToCanvasX(mouse.cur_pos_x);
    float yy = graphics::windowToCanvasY(mouse.cur_pos_y);

	if(mouse.button_left_pressed && bt2.isPressed(xx,yy))
    {
     	test = true;
    } 
}
 

void draw()
{
//test
    createMovieList(movieList);
    auto mv = movieList.begin();

    string title = (*mv)->getTitle();
//////////////////////////////////////////////////////

	graphics::Brush br;
 	SETCOLOR(br.fill_color,0.0,0.1,0.1);

    graphics::setFont("assets//FFF_Tusj.ttf");
 	graphics::drawText(CANVAS_WIDTH/2 - 22,CANVAS_HEIGHT-72,8, "Movies", br);

 	//Button bt;
 	bt2.init(CANVAS_WIDTH/2,CANVAS_HEIGHT/2,12,5,"Search");
 	bt2.draw();

 	if(test == true){
 		graphics::drawText(CANVAS_WIDTH/2,CANVAS_HEIGHT,13, title, br);
 	}
}
 
int main()
{
    graphics::createWindow(WINDOW_WIDTH,WINDOW_HEIGHT,"MoviesLib");

    graphics::setDrawFunction(draw);
    graphics::setUpdateFunction(update);
 
    graphics::setCanvasSize(CANVAS_WIDTH,CANVAS_HEIGHT);
    graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);
    
    graphics::Brush br;

 	SETCOLOR(br.fill_color,0.4,0.3,0.8);
    
    graphics::setWindowBackground(br);

    graphics::startMessageLoop();
 
    return 0;
}
