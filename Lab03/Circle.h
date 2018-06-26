#pragma once
#include <GL/freeglut.h>
#include "Figure.h"
#include <math.h>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 

#define M_PI acos(-1.0)

class Circle : public Figure
{
public:
	Circle(double _radius)
	{
		radius = _radius;
		x = 0.1*((rand() % 40) - 17);
		y = 0.1*((rand() % 40) - 17);
		r = 0.1*(rand() % 10);
		g = 0.1*(rand() % 10);
		b = 0.1*(rand() % 10);
	}
	void draw()
	{
		int i;
		int triangleAmount = 30; //# of triangles used to draw circle
								 //GLfloat radius = 0.8f; //radius
		GLfloat twicePi = 2.0f * M_PI;

		glBegin(GL_TRIANGLE_FAN);
		glColor3d(r, g, b);
		glVertex2f(x, y); // center of circle
		for (i = 0; i <= triangleAmount; i++) {
			glVertex2f(
				x + (radius * cos(i *  twicePi / triangleAmount)),
				y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
		glEnd();
	}
	bool Mouse_inside(int mouse_x, int mouse_y)
	{
		if (abs(x-mouse_x) < 0.5 && abs(y-mouse_y) < 0.5)
			return true;
		else
			return false;
	}
	void Drag(int dx, int dy)
	{
		this->picked = true;
		this->x = dx;
		this->y = dy;
	}
private:
	double radius;
};