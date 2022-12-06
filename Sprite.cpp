#include "Sprite.h"

Sprite::Sprite(const char* name)
{
	loadFromFile(name);
}

bool Sprite::loadFromFile(const char* name)
{
	//��������� ����
	std::ifstream file(name);
	int lenght;

	//��������� ��������
	if (!file)
		return false;

	//��������� ������ ��� �������� X � Y
	file >> lenght;
	m_size.x = lenght;
	file >> lenght;
	m_size.y = lenght;
	
	image = new char[m_size.x * m_size.y];

	//��� ��� ������ ������ ����������� ��� ������ file >> �� ��������� �������, ��� ��������� �� ����� ������
	//���������� ������������� ������� �� ��������� ������
	char* skip_zero_line = new char[1];
	file.getline(skip_zero_line, 1);
	delete[] skip_zero_line;

	//���������� ������ �� ����� � ������
	for (int y = 0; y < m_size.y; y++)
	{
		char* text = new char[m_size.x];
		file.getline(text, m_size.x + 1);
		memcpy(image, text, m_size.x);
		image += m_size.x;
	}

	//������� ��������� � ������
	image -= m_size.x * m_size.y;
	file.close();

	return true;
}

void Sprite::draw(RenderRegion& render)
{
	//���������� ���������
	for (int y = 0; y < m_size.y; y++)
	{
		char* buffer = new char[m_size.x + 1];

		//�������� ������ � ��������� � ���������
		memcpy(buffer, image, m_size.x);
		image += m_size.x;

		buffer[m_size.x] = '\0';
		render.draw(buffer, Vector2f(m_position.x, m_position.y + y));

		delete[] buffer;
	}

	image -= m_size.x * m_size.y;
}
