#pragma once 

//Abstract class Widget
class Widget
{

public:
	//virtual void init()   = 0; //Comment 
	virtual void draw()   = 0;
	virtual void update() = 0;
};