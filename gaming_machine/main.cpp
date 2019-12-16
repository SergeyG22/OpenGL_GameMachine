#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <Windows.h>
#include <gl/GLU.h>
#include <iostream>
#include <string>
#include "control.h"
#include "draw.h"
#include <glut.h>



#pragma comment(lib,"glu32.lib")

POINT mousexy;


int main()
{
	sf::RenderWindow window(sf::VideoMode(1600, 1200), "gaming machine", sf::Style::None);
	window.setMouseCursorVisible(false);
	ShowCursor(FALSE);
	
	Control control;
	CilynderA object1;
	CilynderB object2;
	CilynderC object3;
	CilynderD object4;
	CilynderE object5;
	
	bool event_start = false;
	sf::Clock clock;
	sf::Clock fps;
	sf::Clock change_t;
	sf::Time elapsed;
	std::string t_name;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.close();
			switch (event.type)
			{
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Q)
					window.close();
				break;
			}

			
			sf::Time time2 = change_t.getElapsedTime();
		
			elapsed = clock.getElapsedTime();
			

			if (elapsed.asSeconds() > 7) clock.restart();

			if (time2.asSeconds() < 2) 
			{
				t_name = "texture6.png";
				
			}
			else
			{				
				t_name = "texture7.png";
				if (time2.asSeconds() > 4) { change_t.restart(); }
			}
		}
		
		

		window.clear();
		glClearColor(0.3, 1.0, 1.0, 1.0);
		GetCursorPos(&mousexy);
		HCURSOR oldCursor = SetCursor(NULL);
		control.angleX += (320 - mousexy.x) / 3;
		control.angleY += (240 - mousexy.y) / 3;
		if (control.angleY < -89.0) { control.angleY = -89.0; }
		if (control.angleY > 89.0) { control.angleY = 89.0; }
		SetCursorPos(320, 240);

		
		control.keyboard();
		control.vision(t_name);

		
		
		object1.load_texture();
		object1.cylinder();		
		object2.load_texture();
		object2.cylinder();	
		object3.load_texture();
		object3.cylinder();
		object4.load_texture();
		object4.cylinder();	
		object5.load_texture();
		object5.cylinder();

		control.load_texture(t_name);
		

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))                  // при нажатии клавишы "space" приводит барабаны во вращение
		{
			 event_start = true;
			 clock.restart();
		}
		
			if (event_start)
			{

				if (elapsed.asSeconds() < 3) 
				{ object1.rotate_figure();
				  object2.rotate_figure();
				  object3.rotate_figure();
				  object4.rotate_figure();
				  object5.rotate_figure();
				}
				else if (elapsed.asSeconds() < 3.5) { 
					object2.rotate_figure();
					object3.rotate_figure();
					object4.rotate_figure();
					object5.rotate_figure();
				}
				else if (elapsed.asSeconds() < 4) { 
					object3.rotate_figure(); 
					object4.rotate_figure();
					object5.rotate_figure();
				}
				else if (elapsed.asSeconds() < 4.5) { 
					object4.rotate_figure();
				    object5.rotate_figure();
				
				}
				else if (elapsed.asSeconds() < 5.0) {
					object5.rotate_figure();
					event_start = false;
				}
			}
			
			
		window.display();

	}

	return 0;
}
