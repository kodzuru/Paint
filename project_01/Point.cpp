#include "Point.h"
#include <glut.h>



void Point::draw() {
	glVertex2f(this->x, this->y);
}
void Point::Set() {
	c.Set();
	glLineWidth(w);
}