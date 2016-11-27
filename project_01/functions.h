#pragma once


void Initialize() {
	glClearColor(0.0, 0.0, 0.0, 0.0);//каким цветом всё стереть | цвет очистки
	glMatrixMode(GL_PROJECTION);//тип матрицы который будет изменять в последующем GL_PROJECTION - матрица проекций
	glLoadIdentity(); //загружаем единичную матрицу
	//glOrtho(-WinWid/2, WinWid/2, -WinHei /2, WinHei/2, -WinHei/2, WinHei/2); //задаётся сетка координат(матрица проекции) относительно центра экрана
	glOrtho(0, WinWid, WinHei, 0, -200.0, 200.0); //задаётся сетка координат(матрица проекции) относительно левого верхнего угла

}
void Draw() {
	glClear(GL_COLOR_BUFFER_BIT); //рисуем фон GL_COLOR_BUFFER_BIT - буфер цвета, GL_DEPTH_BUFFER_BIT - буфер глубины
	// если нажато
	if (down) {
		if (lastx != x || lasty != y) // если предыдущие значения НЕ совпадают с текущими
		{
			Point* temp = new Point(c, x, y, w); //создаём новую точку
			Tp[CurrPos].push_back(*temp); // пушим её в вектор
		}
		else {
			Point* temp = new Point(c, x, y, w); //создаём новую точку
			Tp[CurrPos].push_back(*temp); // пушим её в вектор
		}

	}
	// рисуем наши линии
	for (std::vector<std::vector<Point> >::iterator j = Tp.begin(); j != Tp.end(); j++) {
		j->begin()->Set(); // устанавливаем цвет линии
		glBegin(GL_LINE_STRIP);
		for (std::vector<Point>::iterator i = j->begin(); i != j->end(); i++) {
			i->draw();
		}
		glEnd();
	}
	glutSwapBuffers(); //при использовании двойного буфера GLUT_DOUBLE
}


void Timer(int value) {
	glutPostRedisplay(); //обновление всего экрана. того что нарисовали
	glutTimerFunc(1, Timer, 0); //обновления функции инициализации(функции таймера):типа рекурсия
}
void MousePressed(int button, int state, int ax, int ay) //событие на клик
{
	lastx = x;
	lasty = y;
	down = button == GLUT_LEFT_BUTTON && state == GLUT_DOWN; //нажата ли кнопка
	x = ax;
	y = ay;
	//если нажата
	if (down) {
		CurrPos++; //увеличиваем счётчик массива позиций
		std::vector<Point> *temp = new std::vector<Point>; 
		Tp.push_back(*temp);
	}
	std::cout << "ax " << ax << "  ay  " << ay << std::endl;
}
void MousePressedMove(int ax, int ay) //движение при нажатой одной++
{

	if (down) //если нажата то записываем координаты
	{
		lastx = x;
		lasty = y;
		x = ax;
		y = ay;
	}
		
	std::cout << "ax " << ax << "  ay  " << ay << std::endl;
}
//функции меню
void MenuCheckG(int) //функция для вызова необходимого нам меню
{

}
void MenuCheckС(int v) //функция для вызова необходимого нам меню
{
	switch (v)
	{
	case COLOR_WHITE:
		c.Change(1.0, 1.0, 1.0);
		break;
	case COLOR_RED:
		c.Change(1.0, 0.0, 0.0);
		break;
	case COLOR_GREEN:
		c.Change(0.0, 1.0, 0.0);
		break;
	case COLOR_BLUE:
		c.Change(0.0, 0.0, 1.0);
		break;
	case COLOR_RANDOM:
		//double((rand()%100)/100.0) для получения флоат
		c.Change(rand()%100/100.0, rand() % 100/100.0, rand() % 100/100.0);
		break;
	}
}
void MenuCheckW(int v) {
	switch (v)
	{
	case WIDTH_SMALLEST:
		w = 1.0;
		break;
	case WIDTH_SMALL:
		w = 2.0;
		break;
	case WIDTH_HIGH:
		w = 3.0;
		break;
	case WIDTH_HIGHEST:
		w = 4.0;
		break;
	case WIDTH_RANDOM:
		w = rand()%(linew[1]-linew[0]) + linew[0];
		break;
	}
}

void MenuInit() //функция создания меню
{
	int M = glutCreateMenu(MenuCheckG); // создаём меню. функция возвращает ID принимает параметр указатель на функцию
	int MC = glutCreateMenu(MenuCheckС);//создаём подменю цвета
	// подменю цветов цветов
	glutSetMenu(MC); //указываем какое именно меню выбираем|с каким меню будем работать
	glutAddMenuEntry("Белый", COLOR_WHITE);
	glutAddMenuEntry("Красный", COLOR_RED);
	glutAddMenuEntry("Зелёный", COLOR_GREEN);
	glutAddMenuEntry("Синий", COLOR_BLUE);
	glutAddMenuEntry("Рандомный", COLOR_RANDOM);

	int MW = glutCreateMenu(MenuCheckW);
	// подменю ширины
	glutSetMenu(MW); //указываем какое именно меню выбираем|с каким меню будем работать
	glutAddMenuEntry("Самая тонкая", WIDTH_SMALLEST);
	glutAddMenuEntry("Тонкая", WIDTH_SMALL);
	glutAddMenuEntry("Толстая", WIDTH_HIGH);
	glutAddMenuEntry("Самая толстая", WIDTH_HIGHEST);
	glutAddMenuEntry("Рандомная", WIDTH_RANDOM);

	//Добавляем основное меню
	glutSetMenu(M); //указываем какое именно меню выбираем|с каким меню будем работать
	glutAddSubMenu("Изменить цвет", MC);
	glutAddSubMenu("Изменить ширину", MW);
	glutAttachMenu(GLUT_RIGHT_BUTTON);//сообщаем на какую кнопку мыши приходится наше меню

	



		
}