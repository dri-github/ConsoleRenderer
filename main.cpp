#include "RenderRegion.h"
#include "Sprite.h"
#include "Animation.h"

const char* animation_texture = "hellohellohellohellohellohello_____^_____^_____^_____^_____^";

class RotateLatter : public Animation
{
public:
	RotateLatter(Vector2f position, float speed) : Animation(Vector2i(1, 1), 5, (char*)"/-\\||", speed)
	{
		setPosition(position);
		setType(Animation::Normal);
		play();
		setRepeate(true);
	}
};

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	RenderRegion* region = new RenderRegion(Vector2f(0, 0), Vector2i(40, 20));
	region->setSleepTime(80);

	Sprite sprite;
	sprite.loadFromFile("image.txt");

	Animation* animation = new Animation(Vector2i(5, 2), 6, (char*)animation_texture, 0.1);
	animation->setPosition(Vector2f(3, 4));
	animation->setType(Animation::Circle);
	animation->play();
	animation->setRepeate(true);

	//—корость дл€ анимации стоит задавать акуратно, так как анимации в консоли €вл€ютс€ не многокадравыми и дл€ человека это 
	//воспренимаецца как дерганье из-за пропуска кадрав если указана слишком больша€ скорость
	RotateLatter* rotate_latter_begin = new RotateLatter(Vector2f(3, 0), 0.25);
	RotateLatter* rotate_latter_end = new RotateLatter(Vector2f(22, 0), 0.25);

	Vector2f position(10, 10);

	while (region->isOpen())
	{
		if (region->isKeyPressed())
		{
			char key = region->getKey();
			switch (key)
			{
				//ѕеремещение на клавиши W, S, A, D
			case 'в':
			case 'd':
				position.x += 1;
				break;
			case 'ф':
			case 'a':
				position.x -= 1;
				break;
			case 'ы':
			case 's':
				position.y += 1;
				break;
			case 'ц':
			case 'w':
				position.y -= 1;
				break;
				//«авершение программы
			case 'й':
			case 'q':
				region->destroy();
				break;
			}
		}
		sprite.setPosition(position);

		region->clear();

		region->draw(*animation);

		region->draw(*rotate_latter_begin);
		region->draw((char*)"Console Renderer", Vector2f(5, 0));
		region->draw(*rotate_latter_end);

		region->draw(sprite);

		region->display();
	}

	return 0;
}