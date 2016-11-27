#pragma once
#include "Color.h"
//структура точки
struct Point {
	float x;
	float y;
	float w; //ширина точки
	Color c;
	void draw(); //метод рисования
	Point(Color &c_, float _x = 0, float _y = 0, float _w=1.0) :c(c_), x(_x), y(_y), w(_w) {}; // конструктор по умолчанию
	void Set(); // метод установки цвета точки

};



