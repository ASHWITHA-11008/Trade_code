#include<iostream>
#include <SFML\Graphics.hpp>
#include<vector>
#include<algorithm>
#include<iterator>
#include<array>
#include"players.h"
#include"properties.h"
#include"start.h"
#include"mortgage_or_unmortgage.h"

using namespace std;

int main()
{
	sf::RenderWindow window1(sf::VideoMode(800, 600), "Trade");
	window1.setKeyRepeatEnabled(false);

	sf::Font font;
	if (!font.loadFromFile("Avara.otf"))
	{
		std::cout << "Loading Failed" << std::endl;
	}
	/*sf::Text t[size - 1];

	bool run = 0;
	Inputs ip;
	ip = Run(run); // implements code in start.cpp
	int size = ip.num_players;
	player pl[size];
	t[i].setstring(ip.name[i]);
	const int s = 4;
	player pl[s];
	int j;*/

	sf::Text text1;
	text1.setFont(font);
	text1.setString("Player_1");
	text1.setCharacterSize(30);
	text1.setFillColor(sf::Color::White);
	text1.setStyle(sf::Text::Bold);

	sf::Text text2;
	text2.setFont(font);
	text2.setString("Player_2");
	text2.setCharacterSize(30);
	text2.setFillColor(sf::Color::White);
	text2.setStyle(sf::Text::Bold);

	sf::Text text3;
	text3.setFont(font);
	text3.setString("Player_3");
	text3.setCharacterSize(30);
	text3.setFillColor(sf::Color::White);
	text3.setStyle(sf::Text::Bold);

	sf::Text text4;
	text4.setFont(font);
	text4.setString("Player_4");
	text4.setCharacterSize(30);
	text4.setFillColor(sf::Color::White);
	text4.setStyle(sf::Text::Bold);

	sf::RectangleShape rectangle1(sf::Vector2f(150.f, 50.f));
	rectangle1.setOutlineThickness(5.f);
	rectangle1.setOutlineColor(sf::Color::White);
	rectangle1.setFillColor(sf::Color::Red);

	sf::Text text5;
	text5.setFont(font);
	text5.setString("confirm");
	text5.setCharacterSize(30);
	text5.setFillColor(sf::Color::White);
	text5.setStyle(sf::Text::Bold);



	int n, p;
	cout << "Enter number of players: ";
	cin >> n;

	cout << "Enter name of player no.: ";
	cin >> p;

	while (window1.isOpen())
	{
		sf::Event event1;
		while (window1.pollEvent(event1))
		{

			if (event1.type == sf::Event::Closed)
				window1.close();
			if (event1.type == sf::Event::MouseButtonPressed)
			{
				if (text1.getGlobalBounds().contains(sf::Mouse::getPosition(window1).x, sf::Mouse::getPosition(window1).y))
				{
					text1.setOutlineColor(sf::Color(255, 0, 0));
					text1.setOutlineThickness(14);
					text2.setOutlineColor(sf::Color(0, 0, 0));
					text3.setOutlineColor(sf::Color(0, 0, 0));
					text4.setOutlineColor(sf::Color(0, 0, 0));
				}
				if (text2.getGlobalBounds().contains(sf::Mouse::getPosition(window1).x, sf::Mouse::getPosition(window1).y))
				{
					text2.setOutlineColor(sf::Color(255, 0, 0));
					text2.setOutlineThickness(14);
				    text1.setOutlineColor(sf::Color(0, 0, 0));
					text3.setOutlineColor(sf::Color(0, 0, 0));
					text4.setOutlineColor(sf::Color(0, 0, 0));
				}
				if (text3.getGlobalBounds().contains(sf::Mouse::getPosition(window1).x, sf::Mouse::getPosition(window1).y))
				{
					text3.setOutlineColor(sf::Color(255, 0, 0));
					text3.setOutlineThickness(14);
					text1.setOutlineColor(sf::Color(0, 0, 0));
					text2.setOutlineColor(sf::Color(0, 0, 0));
					text4.setOutlineColor(sf::Color(0, 0, 0));
				}
				if (text4.getGlobalBounds().contains(sf::Mouse::getPosition(window1).x, sf::Mouse::getPosition(window1).y))
				{
					text4.setOutlineColor(sf::Color(255, 0, 0));
					text4.setOutlineThickness(14);
					text1.setOutlineColor(sf::Color(0, 0, 0));
					text2.setOutlineColor(sf::Color(0, 0, 0));
					text3.setOutlineColor(sf::Color(0, 0, 0));
				}
			}
		}

		if (event1.type == sf::Event::MouseButtonPressed)
		{
			if (rectangle1.getGlobalBounds().contains(sf::Mouse::getPosition(window1).x, sf::Mouse::getPosition(window1).y))
			{
				window1.close();
			}
		}

		switch (n)
		{
		case 2:
			switch (p)
			{
			case 1:window1.draw(text2);
				break;
			case 2:window1.draw(text1);
				break;
			}
			break;
		case 3:
			switch (p)
			{
			case 1:window1.draw(text2);
				text3.setPosition(0.f, 50.f);
				window1.draw(text3);
				break;
			case 2:window1.draw(text1);
				text3.setPosition(0.f, 50.f);
				window1.draw(text3);
				break;
			case 3:window1.draw(text1);
				text2.setPosition(0.f, 50.f);
				window1.draw(text2);
				break;
			}
			break;
		case 4:
			switch (p)
			{
			case 1:window1.draw(text2);
				text3.setPosition(0.f, 50.f);
				window1.draw(text3);
				text4.setPosition(0.f, 100.f);
				window1.draw(text4);
				break;
			case 2:window1.draw(text1);
				text3.setPosition(0.f, 50.f);
				window1.draw(text3);
				text4.setPosition(0.f, 100.f);
				window1.draw(text4);
				break;
			case 3:window1.draw(text1);
				text2.setPosition(0.f, 50.f);
				window1.draw(text2);
				text4.setPosition(0.f, 100.f);
				window1.draw(text4);
				break;
			case 4:window1.draw(text1);
				text2.setPosition(0.f, 50.f);
				window1.draw(text2);
				text3.setPosition(0.f, 100.f);
				window1.draw(text3);
				break;

				//default:cout << "Entered a invalid player no.";
			}
			//default:cout << "Entered a invalid number of players";
		}

		rectangle1.setPosition(600.0f, 500.f);
		window1.draw(rectangle1);
		text5.setPosition(605.f, 505.f);
		window1.draw(text5);
		window1.display();
	}


	sf::RenderWindow window2(sf::VideoMode(800, 600), "Players");

	player pl[4];

	int player_chance = 3;
	float length = 20, width = 70;
	sf::Text text_m2[40];

	//pl[0].playerProps[2]=3;

	for (int j = 0; j < pl[player_chance].numbProps; j++) {
		text_m2[j].setFont(font);
		print_places(&pl[player_chance].playerProps[j], text_m2[j]);
		text_m2[j].setPosition(length, width);
		width += 30;
		if (width == 520) {
			length = 410;
			width = 70;
			text_m2[j].setPosition(length, width);
		}
	}

	while (window2.isOpen())
	{
		sf::Event event2;
		while (window2.pollEvent(event2))
		{
			if (event2.type == sf::Event::Closed)
			{
				window2.close();
			}
			if (event2.type == sf::Event::MouseButtonPressed)
			{
				if (rectangle1.getGlobalBounds().contains(sf::Mouse::getPosition(window2).x, sf::Mouse::getPosition(window2).y))
				{
					window2.close();
				}
			}
		}

		rectangle1.setPosition(600.0f, 500.f);
		window2.draw(rectangle1);
		text5.setPosition(605.f, 505.f);
		window2.draw(text5);
		window2.draw(text_m2[j]);
		window2.display();
	}

	

	sf::RenderWindow window3(sf::VideoMode(800, 600), "PlayersPr");

	sf::RectangleShape rectangle2(sf::Vector2f(150.f, 70.f));
	rectangle2.setOutlineThickness(5.f);
	rectangle2.setOutlineColor(sf::Color::White);
	rectangle2.setFillColor(sf::Color::Red);
	rectangle2.setPosition(300.0f, 150.f);

	sf::Text text7;
	text7.setFont(font);
	text7.setString("Money");
	text7.setCharacterSize(30);
	text7.setFillColor(sf::Color::White);
	text7.setStyle(sf::Text::Bold);
	text7.setPosition(310.f, 160.f);

	sf::RectangleShape rectangle3(sf::Vector2f(150.f, 70.f));
	rectangle3.setOutlineThickness(5.f);
	rectangle3.setOutlineColor(sf::Color::White);
	rectangle3.setFillColor(sf::Color::Red);
	rectangle3.setPosition(300.0f, 300.f);

	sf::Text text8;
	text8.setFont(font);
	text8.setString("Property");
	text8.setCharacterSize(30);
	text8.setFillColor(sf::Color::White);
	text8.setStyle(sf::Text::Bold);
	text8.setPosition(305.f, 310.f);

	sf::RectangleShape rectangle4(sf::Vector2f(150.f, 70.f));
	rectangle4.setOutlineThickness(5.f);
	rectangle4.setOutlineColor(sf::Color::White);
	rectangle4.setFillColor(sf::Color::Red);

	sf::Text text9;
	text9.setFont(font);
	text9.setString("Confirm");
	text9.setCharacterSize(30);
	text9.setFillColor(sf::Color::White);
	text9.setStyle(sf::Text::Bold);

	sf::RectangleShape rectangle5(sf::Vector2f(130.f, 50.f));
	rectangle5.setOutlineThickness(5.f);
	rectangle5.setOutlineColor(sf::Color::White);
	rectangle5.setFillColor(sf::Color::Red);

	sf::Text text11;
	text11.setFont(font);
	text11.setString("Agree");
	text11.setCharacterSize(30);
	text11.setFillColor(sf::Color::White);
	text11.setStyle(sf::Text::Bold);

	sf::RectangleShape rectangle6(sf::Vector2f(150.f, 50.f));
	rectangle6.setOutlineThickness(5.f);
	rectangle6.setOutlineColor(sf::Color::White);
	rectangle6.setFillColor(sf::Color::Red);

	sf::Text text12;
	text12.setFont(font);
	text12.setString("Disagree");
	text12.setCharacterSize(30);
	text12.setFillColor(sf::Color::White);
	text12.setStyle(sf::Text::Bold);
	

	while (window3.isOpen())
	{
		sf::Event event3;
		while (window3.pollEvent(event3))
		{
			if (event3.type == sf::Event::Closed)
			{
				window3.close();
			}
			if (event3.type == sf::Event::MouseButtonPressed)
			{
				if (rectangle2.getGlobalBounds().contains(sf::Mouse::getPosition(window3).x, sf::Mouse::getPosition(window3).y))
				{
					sf::RenderWindow window4(sf::VideoMode(800, 600), "PlayersProps");

					std::string str1;
					sf::Text name1;
					sf::Text text10;
					sf::Text text13;

					sf::RectangleShape box1(sf::Vector2f(200, 50));
					setText(text10, &font, "Enter amount  : ", 20, 50, 30, sf::Color(0, 255, 0));
					setBox(box1, 300, 50, sf::Color(0, 0, 0), sf::Color(0, 255, 0), 2);

					setText(text13, &font, "$.  ", 305, 55, 30, sf::Color(0, 255, 0));

					while (window4.isOpen())
					{
						sf::Event event4;

						bool sel = false;

						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
						{
							sel = true;
						}
						else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
						{
							sel = false;
						}

						while (window4.pollEvent(event4))
						{
							if (event4.type == sf::Event::Closed)
							{
								window4.close();
							}
							if (event4.type == sf::Event::TextEntered)
							{
								//#################### Taking input name from user ############

								input(window4, event4, box1, str1, name1, &font, 335, 55, sel);
							}
							if (event4.type == sf::Event::MouseButtonPressed)
							{
								if (rectangle4.getGlobalBounds().contains(sf::Mouse::getPosition(window4).x, sf::Mouse::getPosition(window4).y))
								{
									window4.close();
								}
							}
						}

						window4.draw(box1);
						window4.draw(text10);
						window4.draw(text13);
						window4.draw(name1);
						rectangle4.setPosition(230.0f, 200.f);
						window4.draw(rectangle4);
						text9.setPosition(234.f, 215.f);
						window4.draw(text9);
						rectangle5.setPosition(70.0f, 400.f);
						window4.draw(rectangle5);
						text11.setPosition(75.f, 405.f);
						window4.draw(text11);
						rectangle6.setPosition(390.0f, 400.f);
						window4.draw(rectangle6);
						text12.setPosition(393.f, 405.f);
						window4.draw(text12);
						window4.display();
					}
				}
			}
			if (event3.type == sf::Event::MouseButtonPressed)
			{
				if (rectangle3.getGlobalBounds().contains(sf::Mouse::getPosition(window3).x, sf::Mouse::getPosition(window3).y))
				{
					sf::RenderWindow window4(sf::VideoMode(800, 600), "property");

					while (window4.isOpen())
					{
						sf::Event event4;
						while (window4.pollEvent(event4))
						{
							if (event4.type == sf::Event::Closed)
							{
								window4.close();
							}
						}

						rectangle4.setPosition(70.0f, 500.f);
						window4.draw(rectangle4);
						text9.setPosition(75.f, 515.f);
						window4.draw(text9);
						rectangle5.setPosition(610.0f, 200.f);
						window4.draw(rectangle5);
						text11.setPosition(615.f, 205.f);
						window4.draw(text11);
						rectangle6.setPosition(600.0f, 400.f);
						window4.draw(rectangle6);
						text12.setPosition(603.f, 405.f);
						window4.draw(text12);
						window4.display();
					}
				}
			}
		}

		window3.draw(rectangle2);
		window3.draw(text7);
		window3.draw(rectangle3);
		window3.draw(text8);
		window3.display();
	}

	return 0;
}
