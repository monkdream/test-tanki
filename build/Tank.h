#include <SFML/Graphics.hpp>
using namespace sf;

class Tank
{
	public:
		int h = 90, w = 90, pos = 0;
		Sprite tank;
		Texture tanktexture;
		float speed = 0.1, x = 640, y = 120;
		View view;
		// ������ ����������� ��������� ��� �����
		Tank() {
			tanktexture.loadFromFile("images/tank1.png");
			tank.setTexture(tanktexture);
			tank.setTextureRect(IntRect(0, 0, w, h));		
			tank.setPosition(x, y);		
			tank.setOrigin(w / 2, h / 2);
		};

		// ��������� �������� ����� �� ��������
		// �����, ������ �����, ������ �����, ���������� ������ ����� �� ������, ���������� ������ ����� �� ������
		void move(float time, int imageMapH, int imageMapW, int heightMap, int widthMap) {
			// ��� �����
			if (Keyboard::isKeyPressed(Keyboard::Up))
			{
				pos = 0;
				tank.setRotation(0);
				y += -speed * time;
				// �������������� �������� ����� ��������
				if (y < imageMapH + h / 2) {
					y = imageMapH + h / 2;
				}
				tank.setPosition(x,y);
				return;
			}
			// ��� ������
			if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				pos = 1;
				tank.setRotation(90);
				x += speed * time;
				// �������������� �������� ����� ��������
				if (x > (widthMap - 2) * imageMapW + 6) {
					x = (widthMap - 2) * imageMapW + 6;
				}
				tank.setPosition(x, y);
				return;
			}

			// ��� ����
			if (Keyboard::isKeyPressed(Keyboard::Down))
			{
				pos = 2;
				tank.setRotation(180);			
				y += speed * time;
				// �������������� �������� ����� ��������
				if (y > (heightMap - 2) * imageMapH + 6) {
					y = (heightMap - 2) * imageMapH + 6;
				}
				tank.setPosition(x, y);
				return;
			}
			// ��� �����
			if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				pos = 3;
				tank.setRotation(-90);			
				x += -speed * time;
				// �������������� �������� ����� ��������
				if (x < imageMapW + h / 2) {
					x = imageMapW + h / 2;
				}
				tank.setPosition(x, y);
				return;
			}	
		}

};

