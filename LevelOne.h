#include <SFML/Graphics.hpp>
#include<fstream>
#include "stdafx.h"

using namespace std;
class LevelOne
{
public:
	LevelOne();
	~LevelOne();
	void DrawMap(sf::RenderWindow  &window);
	void GameController(sf::RenderWindow &window);

private:
	sf::Sprite Energy;
	sf::Texture EnergyBlast;
	int EnergyX = 0;

	bool BesdieCollider = false;
	std::string removal;

	sf::Texture itexture;
	sf::Sprite  canvas[10][10];

	sf::Sprite playerimage;
	int animPos = 64 + 64;



	sf::Texture box;
	sf::Texture wall;
	sf::Texture ColliderBox;
	sf::Texture mark;
	//sf::Texture *ColliderBox;
	//	ColliderBox->loadFromFile("BoxCollider.png");


	ifstream map;
	char hash;
	string temp;
	int x = 0;
	int y = 0;
	int lines = 0;
	string blank = "";
	char remove = ' ';


	int FileLengthes[10];

	int BoxPositionX = 0;
	int BoxPositionY = 0;

	int MarksX = 0;
	int MarksY = 0;
	int k = 0;
	int px = 6;
	int py = 3;
};
