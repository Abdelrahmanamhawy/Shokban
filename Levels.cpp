#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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


using namespace std;
Levels::Levels(string LevelMap) {
	map.open(LevelMap.c_str());
}
Levels::~Levels() {}
void Levels::MovePlayer(string direction) {
	bool move = true;
	if (counter <= 0)
	{
		counter = 0;
		move = false;
	}
	if (move)
	{
		if (direction == "up") {
			counter--;
			animPos = 0;
			if (canvas[px - 1][py].getTexture() == &wall)
				px--;
			else if (canvas[px - 1][py].getTexture() == &ColliderBox) {
				if (canvas[px - 2][py].getTexture() == &wall || canvas[px - 2][py].getTexture() == &mark) {
					canvas[px - 1][py].setTexture(wall);
					canvas[px - 2][py].setTexture(ColliderBox);
					px--;
				}
			}

		}
		if (direction == "left") {
			counter--;
			animPos = 64;
			if (canvas[px][py - 1].getTexture() == &wall)
				py--;
			else if (canvas[px][py - 1].getTexture() == &ColliderBox) {
				if (canvas[px][py - 2].getTexture() == &wall || canvas[px][py - 2].getTexture() == &mark) {
					canvas[px][py - 1].setTexture(wall);
					canvas[px][py - 2].setTexture(ColliderBox);
					py--;
				}
			}
		}
		if (direction == "down") {
			counter--;
			animPos = 64 * 2;
			if (canvas[px + 1][py].getTexture() == &wall)
				px++;
			else if (canvas[px + 1][py].getTexture() == &ColliderBox) {
				if (canvas[px + 2][py].getTexture() == &wall || canvas[px + 2][py].getTexture() == &mark) {
					canvas[px + 1][py].setTexture(wall);
					canvas[px + 2][py].setTexture(ColliderBox);
					px++;
				}
			}
		}
		if (direction == "right") {
			counter--;
			animPos = 64 * 3;
			if (canvas[px][py + 1].getTexture() == &wall)
				py++;
			if (canvas[px][py + 1].getTexture() == &ColliderBox) {
				if (canvas[px][py + 2].getTexture() == &wall || canvas[px][py + 2].getTexture() == &mark) {
					canvas[px][py + 1].setTexture(wall);
					canvas[px][py + 2].setTexture(ColliderBox);
					py++;
				}
			}
		}
	}
	

}
void Levels::DeleteMap(sf::RenderWindow &window) {
	
}

void Levels::DrawMap(sf::RenderWindow &window) {
	window.clear();
	int k = 0;
	lines = 0;
	//PlayerPositionX = 0;
	//PlayerPositionY = 0;
	ColliderBox.loadFromFile("BoxCollider.png");

	box.loadFromFile("Boxing.png");


	wall.loadFromFile("RedWall.png");

	mark.loadFromFile("Mark.png");
	//while (window.isOpen())

	//{
	while (getline(map, temp)) {


		FileLengthes[k] = temp.length();
		k++;
		for (int i = 0; i < temp.length(); i++) {
			if (temp.at(i) == '#') {

				canvas[lines][i].setPosition(sf::Vector2f(i * 100, lines * 100));

				canvas[lines][i].setTexture(box);
				//	canvas[lines][i].




			}
			else if (temp.at(i) == '.') {
				canvas[lines][i].setPosition(sf::Vector2f(i * 100, lines * 100));

				canvas[lines][i].setTexture(wall);

			}

			else {

			}



		}
		if (temp == "Boxes:") {

			for (int i = 0; i < 4; i++) {

				getline(map, removal);
				//k++;
				//this->FileLengthes[k] = removal.length();
				k++;
				int numb;
				//Conver the string into integer ya3ni
				istringstream(removal) >> numb;

				//Y-axis is the last integer.
				BoxPositionY = numb % 10;

				//Remove the Y-axis
				numb /= 10;

				//Get the first int in string,the x axis y3ni
				BoxPositionX = numb;

				canvas[BoxPositionX][BoxPositionY].setTexture(ColliderBox);

			}


		}
		else if (temp == "Marks:") {
			for (int i = 0; i < 4; i++) {

				getline(map, removal);
				//k++;
				//this->FileLengthes[k] = removal.length();
				k++;
				int numb2;
				istringstream(removal) >> numb2;
				MarksY = numb2 % 10;
				numb2 /= 10;
				MarksX = numb2;
				canvas[MarksX][MarksY].setTexture(mark);
			}

		}
		else if (temp == "Initial:") {
			getline(map, removal);
			//k++;
			//this->FileLengthes[k] = removal.length();
			k++;
			int numb2;
			istringstream(removal) >> numb2;
			PlayerPositionY= numb2 % 10;
			numb2 /= 10;
			PlayerPositionX= numb2;
			
		}

		lines++;
	}




}

//}
void Levels::FirstLevel(sf::RenderWindow &window) {
	
	int msgboxID = MessageBox(
		NULL,
		(LPCWSTR)L"You are cycplous from X-men",
		(LPCWSTR)L"Account Details",
		MB_OK
	);
	

	Levels z("NewMap.txt");

	cout << "It's succed ya " << hash;
	sf::Texture itexture;

	itexture.loadFromFile("player.PNG");

	playerimage.setTexture(itexture);

	EnergyBlast.loadFromFile("EnergyBlast.png");
	Energy.setTexture(EnergyBlast);
	Energy.setScale(sf::Vector2f(0.2, 0.1));
	sf::Music Lazer;
	if (!Lazer.openFromFile("Laser.ogg")) {
		cout << "Error";
	}
	map.open("NewMap.txt");
	int k = 0;
	px = PlayerPositionX;
	py = PlayerPositionY;



	while (window.isOpen())

	{

		sf::Event event;
		while (window.pollEvent(event)) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
			{
				counter--;

				if (canvas[px - 1][py].getTexture() == &wall) {
					cout << "First";
					px--;
				}

				else if (canvas[px - 1][py].getTexture() == &ColliderBox) {
					BesdieCollider = true;
					Energy.setRotation(-90.0);
					Energy.setPosition(playerimage.getPosition().x + 20, playerimage.getPosition().y + 20);
					
					for (int i = px - 1; i >= 0; i--)
						if (canvas[i][py].getTexture() == &mark) {
							canvas[px - 1][py].setTexture(wall);
							canvas[i][py].setTexture(ColliderBox);
						}
					//px--;
				}
				animPos = 0;
				
			


			}
			

			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
			{
				counter--;
				if (canvas[px][py - 1].getTexture() == &ColliderBox) {
					BesdieCollider = true;
					Energy.setRotation(180);
					Energy.setPosition(playerimage.getPosition().x + 30, playerimage.getPosition().y + 40);


					for (int i = py - 1; i >= 0; i--)
						if (canvas[px][i].getTexture() == &mark) {
							canvas[px][py - 1].setTexture(wall);
							canvas[px][i].setTexture(ColliderBox);
						}


				}
				animPos = 64;
				if (canvas[px][py - 1].getTexture() == &wall)
					py--;
				else if (canvas[px][py - 1].getTexture() == &ColliderBox) {
					if (canvas[px][py - 2].getTexture() == &wall || canvas[px][py - 2].getTexture() == &mark) {
						canvas[px][py - 1].setTexture(wall);
						canvas[px][py - 2].setTexture(ColliderBox);
					py--;
					}

				}
				if (canvas[px][py].getTexture() == &ColliderBox && canvas[px][py - 1].getTexture() == &box)
					py++;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
				counter--;
				if (canvas[px + 1][py].getTexture() == &wall) {
					cout << "First";
					px++;
				}

				else if (canvas[px +1][py].getTexture() == &ColliderBox) {
					BesdieCollider = true;
					Energy.setRotation(90.0);
					Energy.setPosition(playerimage.getPosition().x + 40, playerimage.getPosition().y + 40);

					for (int i = px +1; i <=FileLengthes[px];i++)
						if (canvas[i][py].getTexture() == &mark) {
							canvas[px +1][py].setTexture(wall);
							canvas[i][py].setTexture(ColliderBox);
						}
					//px--;
				}
				animPos = 64 * 2;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
			{
				counter--;
				animPos = 64 * 3;
				if (canvas[px][py + 1].getTexture() == &ColliderBox) {
					BesdieCollider = true;
					Energy.setRotation(0);
					Energy.setPosition(playerimage.getPosition().x + 30, playerimage.getPosition().y + 15);

					for (int i = py + 1; i < FileLengthes[px]; i++)
						if (canvas[px][i].getTexture() == &mark) {

							canvas[px][py + 1].setTexture(wall);
							canvas[px][i].setTexture(ColliderBox);




						}


				}
				else {
					if (py < 10)
						py++;
					else {
						py = 5;
					}
				}

				if (canvas[px][py].getTexture() == &ColliderBox && canvas[px][py + 1].getTexture() == &ColliderBox)
					py--;



				if (canvas[px][py].getTexture() == &ColliderBox && canvas[px][py + 1].getTexture() == &box)
					py--;
				if (px == 2 && py == 5)
					py--;
				if (px == 4 && py == 5)
					py--;

			}
			else {
				BesdieCollider = false;
			}


			playerimage.setTextureRect(sf::IntRect(animPos, 0, 64, 196));
		}
		
		if (px == 1 && py == 3)
			px++;
		if (px == 1 && py == 4)
			px++;
		if (px == 5 && py == 5)
			py--;
		if (px == 6 && py == 4)
			px--;
		if (px == 3 && py == 6)
			py--;
		if (px == 4 && py == 1)
			py++;
		if (px == 5 && py == 2)
			px--;
		if (px == 3 && py == 1)
			py++;

		for (int i = 0;i < 9;i++)
			for (int j = 0;j < FileLengthes[i];j++)
				window.draw(canvas[i][j]);

		if (canvas[px][py].getTexture() == &wall && !BesdieCollider)
			playerimage.setPosition(canvas[px][py].getPosition());
		else {

			while (EnergyX < 800) {
				EnergyX += 100;

				Energy.setTextureRect(sf::IntRect(100, 0, EnergyX, 800));
			}
			Lazer.play();

			window.draw(Energy);
			EnergyX = 0;

		}

		
		//DrawMap(window);


		window.draw(playerimage);
		window.display();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::BackSpace)) {
			map.close();
			

			RestOfTheLevels(window,2);
		

		}
	}




}
void Levels::RestOfTheLevels(sf::RenderWindow &window,int l)
{
	font.loadFromFile("PRINP___.ttf");
	std::string numbers = std::to_string(counter);
	text.setFont(font);
	text.setString(numbers);
	text.setCharacterSize(30);
	text.setFillColor(sf::Color::Black);
	
	Initial = true;
	bool MarioMode = false;
	sf::Sprite playerimage;
	sf::Music Jump;
	Jump.openFromFile("Jump.ogg");
	sf::Texture itexture;


	itexture.loadFromFile("player.PNG");
	playerimage.setTexture(itexture);

	
	if (l == 2) {
		int msgboxID = MessageBox(
			NULL,
			(LPCWSTR)L"Just a normal level ",
			(LPCWSTR)L"Account Details",
			MB_OK
		);
		map.open("NewMap2.txt");
		cout << l;
	}
	//Jump By space to finsh the level
	 if (l == 3) {
		 int msgboxID = MessageBox(
			 NULL,
			 (LPCWSTR)L"You are Super Mario !! ",
			 (LPCWSTR)L"Account Details",
			 MB_OK
		 );
		cout << "hEY";
		map.open("ThirdMap.txt");
	}
	 //Keep pressing left while beside the target wall so that you go to the otherside.
	 if (l == 4) {
		 int msgboxID = MessageBox(
			 NULL,
			 (LPCWSTR)L"Not all exits are equal",
			 (LPCWSTR)L"Account Details",
			 MB_OK
		 );
		 map.open("FourthMap.txt");
		 canvas[5][0].setRotation(5.0);
	 }
	 if (l == 5) {
		 int msgboxID = MessageBox(
			 NULL,
			 (LPCWSTR)L"Just a normal level :) I swear. ",
			 (LPCWSTR)L"Account Details",
			 MB_OK
		 );
		 map.open("FifthMap.txt");
	 }
	
	while (window.isOpen())

	{
		
		sf::Event event;

		while (window.pollEvent(event)) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
			{
				
				MovePlayer("up");

			}

			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
			{
				if (l == 4) {
					if (canvas[px][py - 1].getTexture() == &box) {
						if (px == 5 && py == 1) {
							canvas[5][0].move(0, 1);
							if (canvas[px][0].getPosition().y > 590) {
								px = 6;
								py = 5;
							}
						}
					}
					
				}

				
				MovePlayer("left");
			
		
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {

				MovePlayer("down");
		
			}



			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
			{
				MovePlayer("right");
				
			
			}
		
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
					MarioMode = true;

				}
				else
					MarioMode = false;
			

			playerimage.setTextureRect(sf::IntRect(animPos, 0, 64, 196));
		}


		DrawMap(window);
		if (Initial) {
			px = PlayerPositionX;
			py = PlayerPositionY;
			Initial = false;
		}
		
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < FileLengthes[i]; j++) {
				window.draw(canvas[i][j]);
			}
		}
	
		if (MarioMode && l==3) {
			if (canvas[px - 2][py].getTexture() == &wall)
				px = px - 2;
			Jump.play();
		}
		if (canvas[px][py].getTexture() == &wall)
			playerimage.setPosition(canvas[px][py].getPosition());


		window.draw(playerimage);
		window.draw(text);
		window.display();
		//Levels	q("ThirdMapNew.txt");
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::BackSpace))
		{
			//window.close();
			map.close();
			if (l == 5) {
				window.close();
			}
			else if (l < 5) {
				cout << l;
				l++;
				
			}
			
			RestOfTheLevels(window, l % 10);
			
		}
	}

}

