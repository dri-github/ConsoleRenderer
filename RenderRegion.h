#ifndef RENDERREGION_H
#define RENDERREGION_H

#include "Region.h"

#include <stdio.h>
#include <conio.h>
#include <Windows.h>

//	
// Главный класс отрисовки консоли
// RenderRegion - представляет из себя область консоли которая будет перерисовываться. Отвечает за обработку содержимого данного региона и отрисовку переданных ей
// регионов
//	
class RenderRegion : public Region
{
public:
	//Базовый конструктор
	RenderRegion() : m_sleep_time(100), m_open(true) {}
	//Расширенный конструктор
	RenderRegion(Vector2f position, Vector2i size) : Region(position, size), m_sleep_time(100), m_open(true) {}

	//Задаёт время между этапами перерисовки
	void setSleepTime(int time) { m_sleep_time = time; }

	//Возвращает время между этапами перерисовки
	int getSleepTime() const { return m_sleep_time; }
	//Возвращает символ нажатой клавиши
	char getKey() const { return _getch(); }

	//Возвращает true если нажата какая-то клавиша
	bool isKeyPressed() const { return _kbhit();  }
	//Возвращает открыто ли окно
	bool isOpen() const;

	//Очищает регион
	void clear();

	//Функции для отрисовки одиночной строки текста
	void draw(char* text, Vector2f position);
	//Функции для передачи регионов для отрисовки (вызывает функцию draw переданного региона и отрисовывает)
	void draw(Region& region);

	//Отображает на экране все переданные до этого регионы
	void display();
	//Закрывает окно
	void destroy() { m_open = false; }

protected:
	//Включает/отключает отображение курсора
	HANDLE ShowConsoleCursor(BOOL bShow);

private:
	void draw(RenderRegion& render) {}

private:
	int m_sleep_time;	//<-- Время между этапами перерисовки
	bool m_open;		//<-- Открыто ли окно
};

#endif // !RENDERREGION_H