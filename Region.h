#ifndef REGION_H
#define REGION_H

//	
// ��������� �������� ��� ��������� ������ � ������� ���������� ������ ��� ����������� � ������
//	
template <typename T>
struct Vector2
{
	T x;
	T y;

	Vector2() : x(0), y(0) {}
	Vector2(T x, T y) : x(x), y(y) {}
};

typedef Vector2<int> Vector2i;
typedef Vector2<float> Vector2f;

//	
// ������� ����� ��� ���� �������� ���������� ConsoleRenderer
// Region - ��� ������� � ������� ������� ���������� ������ � ���������� ������ �������
//	
class Region
{
	friend class RenderRegion;

public:
	//������� �����������
	Region() : m_position({ 0, 0 }), m_size({ 0, 0 }), image(nullptr) {}
	//����������� �����������
	Region(Vector2f position, Vector2i size) : m_position(position), m_size(size), image(new char[size.x * size.y]) {}

	//�������������
	~Region() { delete[] image; }

	//������������� ����������
	void setPosition(Vector2f position) { m_position = position; }
	//������������� ������
	void setSize(Vector2i size) { m_size = size; }

	//���������� ����������
	Vector2f getPosition() const { return m_position; }
	//���������� ������
	Vector2i getSize() const { return m_size; }

protected:
	//������� ��������� �������
	//������ ������ ������� ������ ���� ��������� � ������� ������ ������������� ������ �������
	virtual void draw(RenderRegion& render) = 0;

protected:
	Vector2f m_position;	//<-- ����������
	Vector2i m_size;		//<-- ������
	char* image;			//<-- ���������� �������
};

#endif // !REGION_H