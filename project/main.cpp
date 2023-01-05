#include <iostream>
#include <sgg/graphics.h>
#include <string>

#include "config.h"
#include "button.h"
#include "movie.h"
#include "interface.h"

using namespace std;

//Update function
void update(float ms)
{ 	
    Interface *movieInterface = Interface::getInstance();
    movieInterface->update(); 
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
