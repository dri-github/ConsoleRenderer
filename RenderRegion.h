#ifndef RENDERREGION_H
#define RENDERREGION_H

#include "Region.h"

#include <stdio.h>
#include <conio.h>
#include <Windows.h>

//	
// ������� ����� ��������� �������
// RenderRegion - ������������ �� ���� ������� ������� ������� ����� ����������������. �������� �� ��������� ����������� ������� ������� � ��������� ���������� ��
// ��������
//	
class RenderRegion : public Region
{
public:
	//������� �����������
	RenderRegion() : m_sleep_time(100), m_open(true) {}
	//����������� �����������
	RenderRegion(Vector2f position, Vector2i size) : Region(position, size), m_sleep_time(100), m_open(true) {}

	//����� ����� ����� ������� �����������
	void setSleepTime(int time) { m_sleep_time = time; }

	//���������� ����� ����� ������� �����������
	int getSleepTime() const { return m_sleep_time; }
	//���������� ������ ������� �������
	char getKey() const { return _getch(); }

	//���������� true ���� ������ �����-�� �������
	bool isKeyPressed() const { return _kbhit();  }
	//���������� ������� �� ����
	bool isOpen() const;

	//������� ������
	void clear();

	//������� ��� ��������� ��������� ������ ������
	void draw(char* text, Vector2f position);
	//������� ��� �������� �������� ��� ��������� (�������� ������� draw ����������� ������� � ������������)
	void draw(Region& region);

	//���������� �� ������ ��� ���������� �� ����� �������
	void display();
	//��������� ����
	void destroy() { m_open = false; }

protected:
	//��������/��������� ����������� �������
	HANDLE ShowConsoleCursor(BOOL bShow);

private:
	void draw(RenderRegion& render) {}

private:
	int m_sleep_time;	//<-- ����� ����� ������� �����������
	bool m_open;		//<-- ������� �� ����
};

#endif // !RENDERREGION_H