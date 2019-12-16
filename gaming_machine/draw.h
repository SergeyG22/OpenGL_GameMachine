#pragma once
#ifndef DRAW_OBJECT_H
#define DRAW_OBJECT_H



//  лассы построени€ геометрических примитивов


class CilynderA
{
	int x_vector_angle;
	int y_vector_angle;
	int z_vector_angle;
	int rotate;
	float translate_x;
	float translate_y;
	float translate_z;

public:
	CilynderA() :translate_x(0), translate_y(0), translate_z(0), rotate(0)
	{
		x_vector_angle = 0;
		y_vector_angle = 0;
		z_vector_angle = 30;
	};
	~CilynderA(){ }
	void load_texture();
	void move();
	void rotate_figure();
	void cylinder();
	
};

class CilynderB
{
	int x_vector_angle;
	int y_vector_angle;
	int z_vector_angle;
	int rotate;
	float translate_x;
	float translate_y;
	float translate_z;
public:
	CilynderB() :translate_x(0), translate_y(0), translate_z(0), rotate(0)
	{
		x_vector_angle = 0;
		y_vector_angle = 0;
		z_vector_angle = 30;
	};
	~CilynderB() { }
	void load_texture();
	void cylinder();
	void rotate_figure();
};

class CilynderC
{
	int x_vector_angle;
	int y_vector_angle;
	int z_vector_angle;
	int rotate;
	float translate_x;
	float translate_y;
	float translate_z;
public:
	CilynderC() :translate_x(0), translate_y(0), translate_z(0), rotate(0)
	{
		x_vector_angle = 0;
		y_vector_angle = 0;
		z_vector_angle = 30;
	};
	~CilynderC() { }
	void load_texture();;
	void cylinder();
	void rotate_figure();
};

class CilynderD
{
	int x_vector_angle;
	int y_vector_angle;
	int z_vector_angle;
	int rotate;
	float translate_x;
	float translate_y;
	float translate_z;
public:
	CilynderD() :translate_x(0), translate_y(0), translate_z(0), rotate(0)
	{
		x_vector_angle = 0;
		y_vector_angle = 0;
		z_vector_angle = 30;
	};
	~CilynderD() { }
	void load_texture();
	void cylinder();
	void rotate_figure();
};

class CilynderE
{
	int x_vector_angle;
	int y_vector_angle;
	int z_vector_angle;
	int rotate;
	float translate_x;
	float translate_y;
	float translate_z;
	int x =10;
public:
	CilynderE() :translate_x(0), translate_y(0), translate_z(0), rotate(0)
	{
		x_vector_angle = 0;
		y_vector_angle = 0;
		z_vector_angle = 30;
	};
	~CilynderE() { }
	void load_texture();
	void cylinder();
	void rotate_figure();
};




#endif // !1

