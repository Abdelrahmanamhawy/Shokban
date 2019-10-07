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
#include "LevelOne.h"
using namespace std;
void main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 900), "Sokoban ,Level 2!");
	LevelOne x;
	//x.ReadFile();
	x.DrawMap(window);
	x.GameController(window);
	//window.display();


	system("pause");
}
