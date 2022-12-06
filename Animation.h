#ifndef ANIMATION_H
#define ANOMATION_H

#include "RenderRegion.h"

//	
//  ласс дл€ воспроизведени€ анимаций
// ѕредставл€ет из себ€ набор текстур отрисовываемых в заданной последовательности
//	
class Animation : public Region
{
public:
	//	
	// “ипы выполнени€ анимации:
	// Normal - анимаци€ выполн€етс€ последовательно
	// Circle - анимаци€ выполн€етс€ сначало последовательно, а затем в обратной последовательности
	// Revers - анимаци€ выполн€етс€ в обратной последовательности
	//	
	enum Type
	{
		Normal = 0,
		Circle,
		Revers
	};

public:
	//Ѕазовый конструктор
	Animation();
	//–асширенный конструктор
	Animation(Vector2i size, int count_frames, char* texture, float speed);

	//«адаЄт скорость анимации
	void setSpeed(float speed) { m_speed = speed; }
	//”станавливает тип выполнени€ анимации
	void setType(Type type) { m_type = type; }
	//ќпредел€ет должна ли анимаци€ повтор€тьс€ или же остановитьс€ по завершению
	void setRepeate(bool repeate);

	//¬озвращает количество кадров анимации
	int getCountFrames() const { return m_count_frames; }
	//¬озвращает прогресс выполнени€ анимации
	float getProgress() const { return m_progress; }

	//«апускает анимацию
	void play() { m_play = true; }
	//ќстанавливает анимацию
	void pause() { m_play = false; }
	//ѕерезапускает анимацию
	void restart() { m_progress = 0; }

	//¬озврощает состо€ние анимации
	bool isPlay() const { return m_play; }

private:
	void draw(RenderRegion& render);

protected:
	bool m_play = false;		//<-- «апущена анимаци€ или остановлена
	bool m_repeate = false;		//<-- ƒолжна ли анимаци€ повтор€тьс€
	int m_count_frames;			//<--  оличество кадров анимации
	float m_speed;				//<-- —корость выполнени€
	float m_progress = 0;		//<-- ѕрогресс выполнени€ анимации
	Type m_type = Type::Normal;	//<-- “ип выполнени€ анимации
};


#endif // !ANIMATION_H