#include <iostream>
#include <sgg/graphics.h>
#include <string>

#include "config.h"
#include "button.h"
#include "movie.h"
#include "interface.h"

using namespace std;

// Global variables for test purposes
//Button bt2;
//Movie movie("pio",1212,"asdasd","asda","asdsd" );
bool test = false;
//list<Movie *> movieList;

//Update function
void update(float ms)
{
 	graphics::MouseState mouse;
    getMouseState(mouse);

    float xx = graphics::windowToCanvasX(mouse.cur_pos_x);
    float yy = graphics::windowToCanvasY(mouse.cur_pos_y);

	/*if(mouse.button_left_pressed && bt2.isPressed(xx,yy))
    {
     	test = true;
    } 
    */
}
 
//Draw function.
void draw()
{
    Interface *movieInterface = Interface::getInstance();
    movieInterface->draw();
}
 

int main()
{
    graphics::createWindow(WINDOW_WIDTH,WINDOW_HEIGHT,"MoviesLib");

    //Create an Interface object and a pointer to it
    Interface *movieInterface = new Interface();
 
    graphics::setDrawFunction(draw);       // draw
    graphics::setUpdateFunction(update);   // update
 
    graphics::setCanvasSize(CANVAS_WIDTH,CANVAS_HEIGHT);
    graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);
    
    graphics::Brush br;

 	SETCOLOR(br.fill_color,0.4,0.3,0.8);
    
    graphics::setWindowBackground(br);

    graphics::startMessageLoop();
 
    return 0;
}
