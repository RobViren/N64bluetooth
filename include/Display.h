#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Display
{
public:
	Display();
	~Display();

	void init();
	void run();

private:
	//View Moving code
	void moveView();

	//Event handler
	void eventHandle();

	//SFML varibles
	sf::RenderWindow m_renderWindow;
	sf::Clock m_clock;
	sf::View m_view;
	sf::Event m_event;
	float m_zoom = 1.0f;

    sf::CircleShape m_circle;


};

