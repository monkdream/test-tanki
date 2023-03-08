#include <SFML/Graphics.hpp>
using namespace sf;

class Bullet
{
public:
	Sprite bullet;
	Texture bullettexture;
	double dead = false;
	float x = 0, y = 0, speed = 0.3;
	int pos = 0, h = 40, w = 8;

	// default bullet
	Bullet(float X, float Y, int Pos) {
		x = X;
		y = Y;
		pos = Pos;
		bullettexture.loadFromFile("images/bullet.png");
		bullet.setTexture(bullettexture);
		bullet.setTextureRect(IntRect(0, 0, w, h));
		bullet.setOrigin(w / 2, h);
		bullet.setPosition(x, y);
	};

	// movement bullet
	void move(float time, int imageMapH, int imageMapW, int heightMap, int widthMap) {
		switch (pos)
		{
		case 0: // up
			y += -speed * time;
			bullet.setRotation(0);
			if (y < imageMapH + h) {
				dead = true;
			}
			bullet.setPosition(x, y);
			break;
		case 1: // right
			bullet.setRotation(90);
			x += speed * time;	
			if (x > (widthMap - 1) * imageMapW - h) {
				dead = true;
			}
			bullet.setPosition(x, y);
			break;
		case 2: // down
			bullet.setRotation(180);
			y += speed * time;
			if (y > (heightMap - 1) * imageMapH - h) {
				dead = true;
			}
			bullet.setPosition(x, y);
			break;
		case 3: // left
			bullet.setRotation(-90);
			x += -speed * time;
			if (x < imageMapW + h) {
				dead = true;
			}
			bullet.setPosition(x, y);		
			break;
		}		
	}
};
