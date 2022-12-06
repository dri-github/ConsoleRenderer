#ifndef SPRITE_H
#define SPRITE_H

#include "RenderRegion.h"

#include <fstream>

//	
// ����� ��� ��������� ��������� �����������
//	
class Sprite : public Region
{
public:
	//������� �����������
	Sprite() {}
	//����������� �����������
	Sprite(const char* name);

	//��������� �������� �� ��������� �����
	//��������� �����:
	//- ������ ��� �������� �������� ��� ������ � ������
	//- ��� ����������� ��������, ��� � ���� ��������
	//�����!!!
	//���� ����� ��������� ������ ������ ������, �� �� ��������� � ��������� ������ ��� ������� �������� ������;
	//����� ������ ������ �������� �������� Enter;
	bool loadFromFile(const char* name);

public:
	void draw(RenderRegion& render);
};

#endif // !SPRITE_H