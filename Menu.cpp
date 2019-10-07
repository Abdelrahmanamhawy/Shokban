#include "stdafx.h"
#include "Menu.h"
#include "Levels.h"
#include <iostream>
Menu::Menu(float width,float height)
{
	font.loadFromFile("PRINP___.ttf");
	MenuItems[0].setFont(font);
	MenuItems[0].setFillColor(sf::Color::Red);
	MenuItems[0].setString("Play");
	MenuItems[0].setPosition(sf::Vector2f(width / 2, height / 2));

	MenuItems[1].setFont(font);
	MenuItems[1].setFillColor(sf::Color::Red);
	MenuItems[1].setString("Exit");
	MenuItems[1].setPosition(sf::Vector2f(width / 2,( height / 2)+60));

}


Menu::~Menu()
{
}
void Menu::DrawMenu(sf::RenderWindow &window) {
	
	for (int i = 0;i < 2;i++)
		window.draw(MenuItems[i]);
	

}
void Menu::Handle(sf::RenderWindow &window) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
		cout << "Hi";
		Levels LevelOne("NewMap.txt");
		LevelOne.DrawMap(window);
		LevelOne.FirstLevel(window);

	}


}
