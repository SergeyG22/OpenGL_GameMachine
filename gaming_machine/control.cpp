
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GLU.h>
#include <Windows.h>
#include <string>
#include <glut.h>
#include "control.h"

void Control::keyboard()                // функция позволяет перемещаться в трехмерном пространстве
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		x -= (float)sin(angleX / 180 * PI) * 5;
		z -= (float)cos(angleX / 180 * PI) * 5;
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		x += (float)sin(angleX / 180 * PI) * 5;
		z += (float)cos(angleX / 180 * PI) * 5;
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		x += (float)sin((angleX - 90) / 180 * PI) * 5;
		z += (float)cos((angleX - 90) / 180 * PI) * 5;
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		x += (float)sin((angleX + 90) / 180 * PI) * 5;
		z += (float)cos((angleX + 90) / 180 * PI) * 5;

	}


}



void Control::vision(std::string str)              //функция строит визуальное отображения окна
{
	
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65, float(w / h), 1, 1600);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(x, y + height, z, x - sin(angleX / 180 * PI), y + height + (tan(angleY / 180 * PI)), z - cos(angleX / 180 * PI), 0, 1, 0);

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glGetError();
//===================== Подсчитывает fps и отображает на экране


	sf::Time time = fps.getElapsedTime();
	int a = 1.0f / time.asSeconds();
	std::string s = "fps: " + std::to_string(a);
	const char* b = s.c_str();
	display_text(-250, 80,-140, 0.0f, 0.0f, 0.0f, b);
	fps.restart();


//=====================


	sf::Image data_img;
	data_img.loadFromFile(str);
	GLuint textureID;
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 128, 128, 0, GL_RGBA, GL_UNSIGNED_BYTE, data_img.getPixelsPtr());




	glBlendFunc(GL_ONE, GL_ONE);
	
	glBegin(GL_POLYGON);
	glColor4f(1.0f, 1.0f, 0.0f, 0.9);
	glVertex3f(30, -30, 30);
	glColor4f(1.0f, 1.0f, 0.0f, 0.9);
	glVertex3f(30, 30, 30);
	glColor4f(1.0f, 1.0f, 0.0f, 0.9);
	glVertex3f(-30, 30, 30);
	glColor4f(1.0f, 1.0f, 0.0f, 0.9);
	glVertex3f(-30, -30, 30);
	glEnd();


	glBegin(GL_POLYGON);
	glColor4f(1.0f, 1.0f, 0.0f, 0.9);
	glVertex3f(30, -30, -30);
	glColor4f(1.0f, 1.0f, 0.0f, 0.9);
	glVertex3f(30, 30, -30);
	glColor4f(1.0f, 1.0f, 0.0f, 0.9);
	glVertex3f(30, 30, 30);
	glColor4f(1.0f, 1.0f, 0.0f, 0.9);
	glVertex3f(30, -30, 30);
	glEnd();



	glBegin(GL_POLYGON);
	glColor4f(1.0f, 1.0f, 0.0f, 0.1);
	glVertex3f(-30, -30, 30);
	glColor4f(1.0f, 1.0f, 0.0f, 0.1);
	glVertex3f(-30, 30, 30);
	glColor4f(1.0f, 1.0f, 0.0f, 0.1);
	glVertex3f(-30, 30, -30);
	glColor4f(1.0f, 1.0f, 0.0f, 0.1);
	glVertex3f(-30, -30, -30);
	glEnd();
	glDisable(GL_BLEND);

	glEnable(GL_TEXTURE_2D);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(30, 30, 30);
	glTexCoord2f(-1.0, 0.0);
	glVertex3f(30, 30, -30);
	glTexCoord2f(-1.0, -1.0);
	glVertex3f(-30, 30, -30);
	glTexCoord2f(0.0, -1.0);
	glVertex3f(-30, 30, 30);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glBegin(GL_POLYGON);
	glColor4f(1.0f, 1.0f, 0.0f, 0.1);
	glVertex3f(30, -30, -30);
	glColor4f(1.0f, 1.0f, 0.0f, 0.1);
	glVertex3f(-30, -30, -30);
	glColor4f(1.0f, 1.0f, 0.0f, 0.1);
	glVertex3f(-30, 30, -30);
	glColor4f(1.0f, 1.0f, 0.0f, 0.1);
	glVertex3f(30, 30, -30);
	glEnd();


	glBegin(GL_POLYGON);
	glColor4f(1.0f, 1.0f, 0.0f, 0.1);
	glVertex3f(30, -30, 30);
	glColor4f(1.0f, 1.0f, 0.0f, 0.1);
	glVertex3f(-30, -30, 30);
	glColor4f(1.0f, 1.0f, 0.0f, 0.1);
	glVertex3f(-30, -30, -30);
	glColor4f(1.0f, 1.0f, 0.0f, 0.1);
	glVertex3f(30, -30, -30);
	glEnd();

	glTranslated(-210,0,175);
}


void Control::display_text(float x,float y,float z,float r,float g,float b,const char* string)
{
	int j = strlen(string);
	glColor3f(r, g, b);
	glRasterPos3f(x,y,z);
	for (int i = 0; i < j; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
	}

}









void Control::load_texture(std::string str)   // функция загрузки текстуры кнопки
{
	sf::Image data_img;
	data_img.loadFromFile(str);
	GLuint textureID;
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 128, 128, 0, GL_RGBA, GL_UNSIGNED_BYTE, data_img.getPixelsPtr());
	glDeleteTextures;
}