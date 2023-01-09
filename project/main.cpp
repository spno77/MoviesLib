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
    graphics::Brush br;
    SETCOLOR(br.fill_color,1.0,1.0,1.0);
    br.texture = "assets//purple.png";
    br.outline_opacity = 0.0f;

    graphics::drawRect(CANVAS_WIDTH/2,CANVAS_HEIGHT/2,CANVAS_WIDTH,CANVAS_HEIGHT,br);
    graphics::setWindowBackground(br);

    Interface *movieInterface = Interface::getInstance();
    movieInterface->draw();
}
 
int main()
{
    graphics::createWindow(WINDOW_WIDTH,WINDOW_HEIGHT,"MoviesLib");

    Interface *movieInterface = new Interface();
 
    graphics::setDrawFunction(draw);       // draw
    graphics::setUpdateFunction(update);   // update
    
    graphics::setCanvasSize(CANVAS_WIDTH,CANVAS_HEIGHT);
    graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);
      
    graphics::startMessageLoop();
 
    return 0;
}
