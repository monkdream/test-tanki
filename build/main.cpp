#include <SFML/Graphics.hpp>
#include "Tank.h";
#include "Bullet.h";
#include "Map.h";
#include <list>

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(1250, 816), L"Tan4iki");
	Tank player;
	Map mainmap;
	Clock clock;
	std::list<Bullet*> bullets;
	std::list<Bullet*>::iterator bul;

	while (window.isOpen())
	{
		Event event;		
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 600;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Space)
				{
					bullets.push_back(new Bullet(player.x, player.y, player.pos));
				}				
			}
		}
		

		for (bul = bullets.begin(); bul != bullets.end();)
		{
			Bullet* b = *bul;
			b->move(time, mainmap.imageMapH, mainmap.imageMapW, mainmap.heightMap, mainmap.widthMap);
			if (b->dead == true) 
			{ 
				bul = bullets.erase(bul);
				delete b; 
			} else {
				bul++;
			}
		}
		
		player.move(time, mainmap.imageMapH, mainmap.imageMapW, mainmap.heightMap, mainmap.widthMap); // передвижение танка

		window.clear();
		
		for (int i = 0; i < mainmap.heightMap; i++)
		{
			for (int j = 0; j < mainmap.widthMap; j++)
			{
				if (i == 0 || j == 0 || i == (mainmap.heightMap - 1) || j == (mainmap.widthMap - 1))
				{
					mainmap.map.setPosition(j * mainmap.imageMapW, i * mainmap.imageMapH);
					window.draw(mainmap.map); // рисуем карту
				}
			}
		}
		
		// отрисовываем пули
		for (bul = bullets.begin(); bul != bullets.end(); bul++) {
			window.draw((*bul)->bullet);
		}

		window.draw(player.tank); // отрисовываем танк		

		window.display();
	}
	return 0;
}
