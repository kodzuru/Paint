/*
пиратский пейнт
*/

#include <iostream>
#include <conio.h>
#include <glut.h>
#include <vector>
#include <time.h>
#include "Point.h"
#include "Color.h"
#include "Define.h"


float WinWid = 800.0;
float WinHei = 800.0;
float x; // текущая координата мыши X
float y; // текущая координата мыши Y
float lastx, lasty; //координаты отвечающие за отклонение от предыдущих значений
float w = 1.0; //переменная ширины точки
int linew[2]; // данные о состоянии ширины передаём в glGetIntegerv();
std::vector<std::vector<Point> >  Tp; // вектор класса точек массив массивов
int CurrPos = -1; // текущая позиция
bool down; // нажата ли кнопка мыши?
Color c(1.0, 1.0, 0.0);
#include "functions.h"



using namespace std;
int main(int argc, char** argv) {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	//инициализация
	glutInit(&argc, argv); // глобальная инициализация
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);// инициализация мода дисплея(как рисуем)
	glutInitWindowSize(WinWid, WinHei); // инициализация размеров дисплея/окна
	glutInitWindowPosition(100, 200); // инициализация позиции окна
	glutCreateWindow("Super <openGL> balalaika"); //создание окна
	
	glutDisplayFunc(Draw); //регистрация функции рисования
	glutTimerFunc(1, Timer, 0); // регистрация функции анимации(функция таймера)

	glutMotionFunc(MousePressedMove);//регистрация когда движение нажали и двигаем
	glutMouseFunc(MousePressed); //регистрация когда происходит клик

	Initialize(); //регистрация функции инициализация
	MenuInit(); //регистрирует функции меню

	glGetIntegerv(GL_LINE_WIDTH_RANGE, linew); //просим вернуть возможные значения ширины 1-эл min 2-ой max
	glutMainLoop(); //запуск главного цикла(стандартная функция GLUT)


	_getch();
	return 1;
}