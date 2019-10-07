#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include<fstream>
using namespace std;
class Levels
{
public:

	Levels(string x);
	~Levels();
	ifstream map;

	void RestOfTheLevels(sf::RenderWindow  &window,int LevelNumber);
	void FirstLevel(sf::RenderWindow &window);
	void Level3(sf::RenderWindow &window);
	void FourthLevel(sf::RenderWindow &window);
	void FifthLevel(sf::RenderWindow &window);
	void DrawMap(sf::RenderWindow &window);
	void DeleteMap(sf::RenderWindow &window);
	void MovePlayer(string Direction);
private:
	int counter = 250;
	sf::Font font;
	sf::Text text;
	bool Initial = false;
	sf::Sprite Energy;
	sf::Texture EnergyBlast;
	int EnergyX = 0;
	
	int LevelCounter = 20;
	
	int PlayerPositionX = 0;
	int PlayerPositionY = 0;
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
	int px = 6;
	int py = 3;
};
