#ifndef SPRITE_H
#define SPRITE_H

#include "RenderRegion.h"

#include <fstream>

//	
// Класс для отрисовки заданного изображения
//	
class Sprite : public Region
{
public:
	//Базовый конструктор
	Sprite() {}
	//Расширенный конструктор
	Sprite(const char* name);

	//Зашружает текстуру из заданного файла
	//Структура файла:
	//- Первые два значения текстуры это ширина и высота
	//- Все последующие значения, это и есть текстура
	//Важно!!!
	//Если между символами должен стоять пробел, то он ставиться в противном случае все символы пишуться слитно;
	//После каждой строки текстуры ставится Enter;
	bool loadFromFile(const char* name);

public:
	void draw(RenderRegion& render);
};

#endif // !SPRITE_H