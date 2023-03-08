#include <SFML/Graphics.hpp>
using namespace sf;

class Map
{
public:
	int imageMapW = 50, imageMapH = 51, heightMap = 16, widthMap = 25;
	Sprite map;
	Texture maptexture;
	Map(){
		maptexture.loadFromFile("../images/wall.png");
		map.setTexture(maptexture);
		map.setTextureRect(IntRect(0, 0, imageMapW, imageMapH));
	};
};
