#include <glut.h>
#include "Color.h"

void Color::Set() {
	glColor3f(this->r, this->g, this->b);
}
void Color::Change(float r_, float g_, float b_) {
	this->r = r_;
	this->g = g_;
	this->b = b_;
}