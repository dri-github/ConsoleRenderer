#include "RenderRegion.h"

bool RenderRegion::isOpen() const
{
	//������ ������� �������� �� ������ ��� �������� ������ �� ����� ��� ������
	//����� ������������ �������� ������� destroy, �� �� �������� ��� ����� ������ ���� ������ �� ��������� ��������
	//��� ���� ������� ����� ��� �� ������ �����, ��� ��������� � ������
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
	//����� �� ����������� ����������
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
	//�������� ������� �� ����� �����������
	HANDLE cursor_handle = ShowConsoleCursor(FALSE);

	//����������� ���������
	for (int y = 0; y < m_size.y; y++)
	{
		//���������� ������� � ����������� ����������
		SetConsoleCursorPosition(cursor_handle, { (short)m_position.x, (short)(y + m_position.y) });

		char* display_buffer = new char[m_size.x + 1];
		memcpy(display_buffer, image, m_size.x);
		image += m_size.x;
		display_buffer[m_size.x] = '\0';

		//���������
		printf(display_buffer);
		printf("\n");

		delete[] display_buffer;
	}

	image -= m_size.x * m_size.y;

	//������ ������� �������
	ShowConsoleCursor(TRUE);
	Sleep(m_sleep_time);
}

HANDLE RenderRegion::ShowConsoleCursor(BOOL bShow)
{
	CONSOLE_CURSOR_INFO cci;
	HANDLE hStdOut;

	//��������� ��������� �������
	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	if (hStdOut == INVALID_HANDLE_VALUE)
		return NULL;

	//��������� ��������� �������
	if (!GetConsoleCursorInfo(hStdOut, &cci))
		return NULL;

	//������������� ��������� �������
	cci.bVisible = bShow;
	//������ ���������� ��������� �������
	if (!SetConsoleCursorInfo(hStdOut, &cci))
		return NULL;

	return hStdOut;
}