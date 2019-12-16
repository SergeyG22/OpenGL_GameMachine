#pragma once
#ifndef KEYBOARD_MOUSE_H
#define KEYBOARD_MOUSE_H

const double PI = 3.141592653;


// Класс создания и контроля камеры


class Control
{	
	int w;     
	int h;
	const float height = 0;
	int x ;
	int y ;
	int z ;	
	sf::Clock fps;
public:
	Control():w(1600),h(1200), angleX(0.0), angleY(0.0)
	{
		x = -100;
		y = 250;
		z = -150;
	}
	~Control(){ }
	float angleX;
	float angleY;
	void keyboard();
	void vision(std::string);
	void load_texture(std::string );
	void display_text(float x,float y,float z,float r,float g,float b,const char* string);
	
};






#endif // !1

