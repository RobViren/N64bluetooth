#include "Display.h"

Display::Display()
{
}


Display::~Display()
{
}

void Display::init()
{
	//Set Window and View varibles
	m_renderWindow.create(sf::VideoMode(800, 600), "Joy");
	m_view = m_renderWindow.getDefaultView();
	m_renderWindow.setFramerateLimit(60);
}

void Display::run()
{

	while (m_renderWindow.isOpen())
	{
        
        if (sf::Joystick::isConnected(0))
        {
            unsigned int buttonCount = sf::Joystick::getButtonCount(0);
            for(int i = 0; i < buttonCount; ++i){
                if (sf::Joystick::isButtonPressed(0, i))
                {
                    std::cout << i << " is pressed \n";
                }   
            }
        }

		moveView();
		eventHandle();

		//Set view
		m_renderWindow.setView(m_view);
        
		//Clear previous frame
		m_renderWindow.clear(sf::Color::Blue);
        
        m_circle.setRadius(150);
        m_circle.setOutlineColor(sf::Color::Red);
        m_circle.setOutlineThickness(5);
        m_circle.setPosition(50, 50);
        m_renderWindow.draw(m_circle);

		m_renderWindow.display();
	}
}

void Display::moveView()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		m_view.move(sf::Vector2f(0.f, -20.0f*m_zoom));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_view.move(sf::Vector2f(0.f, 20.0f * m_zoom));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_view.move(sf::Vector2f(-20.f * m_zoom, 0.f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_view.move(sf::Vector2f(20.f * m_zoom, 0.f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		m_view.rotate(2.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		m_view.rotate(-2.0f);
	}
}

void Display::eventHandle()
{
	while (m_renderWindow.pollEvent(m_event))
	{

		// "close requested" event: we close the m_renderWindow
		if (m_event.type == sf::Event::Closed)
			m_renderWindow.close();

		// catch the resize events
		if (m_event.type == sf::Event::Resized)
		{
			// update the view to the new size of the window
			sf::FloatRect visibleArea(0, 0, (float)m_event.size.width, (float)m_event.size.height);
			m_renderWindow.setView(sf::View(visibleArea));
			m_view = m_renderWindow.getView();
		}

		//Wheel Moving Listener
		if (m_event.type == sf::Event::MouseWheelMoved)
		{

			if (m_event.mouseWheel.delta > 0)
			{
				m_zoom *= .90f;
				m_view.zoom(.9f);
			}
			else if (m_event.mouseWheel.delta < 0)
			{
				m_zoom /= .90f;
				m_view.zoom(1.f / .9f);
			}
		}
	}
}
