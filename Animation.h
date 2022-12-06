#ifndef ANIMATION_H
#define ANOMATION_H

#include "RenderRegion.h"

//	
// ����� ��� ��������������� ��������
// ������������ �� ���� ����� ������� �������������� � �������� ������������������
//	
class Animation : public Region
{
public:
	//	
	// ���� ���������� ��������:
	// Normal - �������� ����������� ���������������
	// Circle - �������� ����������� ������� ���������������, � ����� � �������� ������������������
	// Revers - �������� ����������� � �������� ������������������
	//	
	enum Type
	{
		Normal = 0,
		Circle,
		Revers
	};

public:
	//������� �����������
	Animation();
	//����������� �����������
	Animation(Vector2i size, int count_frames, char* texture, float speed);

	//����� �������� ��������
	void setSpeed(float speed) { m_speed = speed; }
	//������������� ��� ���������� ��������
	void setType(Type type) { m_type = type; }
	//���������� ������ �� �������� ����������� ��� �� ������������ �� ����������
	void setRepeate(bool repeate);

	//���������� ���������� ������ ��������
	int getCountFrames() const { return m_count_frames; }
	//���������� �������� ���������� ��������
	float getProgress() const { return m_progress; }

	//��������� ��������
	void play() { m_play = true; }
	//������������� ��������
	void pause() { m_play = false; }
	//������������� ��������
	void restart() { m_progress = 0; }

	//���������� ��������� ��������
	bool isPlay() const { return m_play; }

private:
	void draw(RenderRegion& render);

protected:
	bool m_play = false;		//<-- �������� �������� ��� �����������
	bool m_repeate = false;		//<-- ������ �� �������� �����������
	int m_count_frames;			//<-- ���������� ������ ��������
	float m_speed;				//<-- �������� ����������
	float m_progress = 0;		//<-- �������� ���������� ��������
	Type m_type = Type::Normal;	//<-- ��� ���������� ��������
};


#endif // !ANIMATION_H