#include <iostream>
#include <sgg/graphics.h>
#include <string>

#include "config.h"

using namespace std;


void update(float ms)
{
   
}
 

void draw()
{
    
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
