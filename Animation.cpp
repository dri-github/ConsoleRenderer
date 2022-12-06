#include "Animation.h"

Animation::Animation() : m_count_frames(0), m_speed(1)
{}

Animation::Animation(Vector2i size, int count_frames, char* texture, float speed) : m_count_frames(count_frames), m_speed(speed)
{
	image = texture;
	m_size = size;
}

void Animation::setRepeate(bool repeate)
{
	m_repeate = repeate;
}

void Animation::draw(RenderRegion& render)
{
	//Предварительная обработка процесса движения прогресса в зависимости от типа анимации
	switch (m_type)
	{
	case Normal:
	{
		if (m_play == true)
			m_progress += m_speed;

		if (m_progress >= 1)
		{
			m_progress = 0;
			if (m_repeate == false)
				m_play = false;
		}
		break;
	}
	case Circle:
	{
		if (m_play == true)
			m_progress += m_speed;

		if (m_progress >= 1 || m_progress <= 0)
		{
			m_speed *= -1;
			m_progress += m_speed;
			if (m_speed > 0 && m_repeate == false)
				m_play = false;
		}
		break;
	}
	case Revers:
	{
		if (m_play == true)
			m_progress -= m_speed;

		if (m_progress <= 0)
		{
			m_progress = 1 - m_speed;
			if (m_repeate == false)
				m_play = false;
		}
		break;
	}
	}

	//Сдвиг текстуры до необходимого кадра
	int frame_shift = int(m_count_frames * m_progress) * m_size.x;

	image += frame_shift;
	//Послойная отрисовка необходимой текстуры
	for (int y = 0; y < m_size.y; y++)
	{
		int image_shift = m_size.x * m_count_frames;
		char* buffer = new char[m_size.x + 1];

		memcpy(buffer, image, m_size.x);
		image += image_shift;

		buffer[m_size.x] = '\0';

		render.draw(buffer, Vector2f(m_position.x, m_position.y + y));
	}
	image -= frame_shift + m_size.x * m_count_frames * m_size.y;
}