#pragma once
struct Color {
	float r, g, b;
	Color(float r_, float g_, float b_) :r(r_), g(g_), b(b_) {}; //явный конструктор
	void Set(); //установка цветов
	void Change(float r_, float g_, float b_); // изменение цветов
};