#include <iostream>
#include <sgg/graphics.h>
#include <string>

#include "config.h"
#include "button.h"

using namespace std;


Button bt2;
bool test = false;

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
	graphics::Brush br;
 	SETCOLOR(br.fill_color,0.0,0.1,0.1);

    graphics::setFont("assets//FFF_Tusj.ttf");
 	graphics::drawText(CANVAS_WIDTH/2 - 22,CANVAS_HEIGHT-72,8, "Movies", br);

 	//Button bt;
 	bt2.init(CANVAS_WIDTH/2,CANVAS_HEIGHT/2,10,5);
 	bt2.draw();

 	if(test == true){
 		graphics::drawText(CANVAS_WIDTH/2,CANVAS_HEIGHT,13, "Movies", br);
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
