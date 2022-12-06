#include "RenderRegion.h"

bool RenderRegion::isOpen() const
{
	//Данная функция защищает от ошибки при удалении класса во время его работы
	//Когда пользователь вызывает функцию destroy, то он помечает что класс должен быть удален на следующей итерации
	//Без этой функции класс был бы удален сразу, что привелобы к ошибке
	if (m_open == false)
	{
		delete this;
		return false;
	}

	return m_open;
}

void RenderRegion::clear()
{
	memset(image, ' ', m_size.x * m_size.y);
}

void RenderRegion::draw(char* text, Vector2f position)
{
	//Сдвиг на необходимую координату
	int shift = (int)position.y * m_size.x + (int)position.x;

	image += shift;
	memcpy(image, text, strlen(text));
	image -= shift;
}
void RenderRegion::draw(Region& region)
{
	region.draw(*this);
}

void RenderRegion::display()
{
	//Скрываем каретку на время отображения
	HANDLE cursor_handle = ShowConsoleCursor(FALSE);

	//Посторочная отрисовка
	for (int y = 0; y < m_size.y; y++)
	{
		//Перемещаем каретку в необходимые координаты
		SetConsoleCursorPosition(cursor_handle, { (short)m_position.x, (short)(y + m_position.y) });

		char* display_buffer = new char[m_size.x + 1];
		memcpy(display_buffer, image, m_size.x);
		image += m_size.x;
		display_buffer[m_size.x] = '\0';

		//Отрисовка
		printf(display_buffer);
		printf("\n");

		delete[] display_buffer;
	}

	image -= m_size.x * m_size.y;

	//Делаем каретку видимой
	ShowConsoleCursor(TRUE);
	Sleep(m_sleep_time);
}

HANDLE RenderRegion::ShowConsoleCursor(BOOL bShow)
{
	CONSOLE_CURSOR_INFO cci;
	HANDLE hStdOut;

	//Получение указателя каретку
	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	if (hStdOut == INVALID_HANDLE_VALUE)
		return NULL;

	//Получение структуры каретки
	if (!GetConsoleCursorInfo(hStdOut, &cci))
		return NULL;

	//Устанавливаем видимость каретки
	cci.bVisible = bShow;
	//Задаем измененную структуру каретки
	if (!SetConsoleCursorInfo(hStdOut, &cci))
		return NULL;

	return hStdOut;
}