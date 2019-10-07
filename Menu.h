#pragma once
#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include<fstream>
class Menu
{
public:
	Menu(float h,float w);
	~Menu();
	void DrawMenu(sf::RenderWindow &window);
private:
	int index;
	sf::Font font;
	sf::Text MenuItems[4];
	void Handle(sf::RenderWindow &window);


};

