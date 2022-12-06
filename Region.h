#ifndef REGION_H
#define REGION_H

//	
// Структура созданна для упрощения работы с парными значениями такими как коорждината и размер
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
// Базовый класс для всех объектов библиотеки ConsoleRenderer
// Region - это область в консоли имеющая координаты размер и наполнение данной области
//	
class Region
{
	friend class RenderRegion;

public:
	//Базовый конструктор
	Region() : m_position({ 0, 0 }), m_size({ 0, 0 }), image(nullptr) {}
	//Расширенный конструктор
	Region(Vector2f position, Vector2i size) : m_position(position), m_size(size), image(new char[size.x * size.y]) {}

	//Деконструктор
	~Region() { delete[] image; }

	//Устанавливает координаты
	void setPosition(Vector2f position) { m_position = position; }
	//Устанавливает размер
	void setSize(Vector2i size) { m_size = size; }

	//Возвращает координаты
	Vector2f getPosition() const { return m_position; }
	//Возвращает размер
	Vector2i getSize() const { return m_size; }

protected:
	//Функция отрисовки региона
	//Каждый объект который должен быть отрисован в консоли должен реализовывать данную функцию
	virtual void draw(RenderRegion& render) = 0;

protected:
	Vector2f m_position;	//<-- Координаты
	Vector2i m_size;		//<-- Размер
	char* image;			//<-- Содержимое региона
};

#endif // !REGION_H