#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <iomanip>
#include "windows.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>  
#include <ctime>         //Better Timer library.
#include <chrono>
#include <thread>
#include<fstream>
#include <sstream>
#include "Levels.h"
#include "Menu.h"

using namespace std;
int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Sokoban ,Level 2!");

	Menu MainMenu(window.getSize().x, window.getSize().y);
	MainMenu.DrawMenu(window);
    window.display();
	sf::Event event;
	while (window.isOpen()) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
			Levels m("NewMap.txt");
			m.DrawMap(window);
			m.FirstLevel(window);
		}

	}
	//window.display();

	//m.Game(window);
	

	system("pause");

	
}
