/// <summary>
/// @author Darragh McKernan
/// @date 21/01/2022
/// </summary>

#include "Game.h"
#include <iostream>



/// <summary>
/// default constructor
/// setup the window properties
/// load and setup the text 
/// load and setup thne image
/// </summary>
Game::Game() :
	m_window{ sf::VideoMode{ 800U, 600U, 32U }, "SFML Game" },
	m_redSquare(sf::Vector2f(200.0f, 200.0f)),
	m_blueSquare(sf::Vector2f(200.0f, 200.0f)),
	m_greenSquare(sf::Vector2f(200.0f, 200.0f)),
	m_yellowSquare(sf::Vector2f(200.0f, 200.0f)),
	m_exitGame{false} //when true game will exit
{
	squareSetup();
	title();
}

/// <summary>
/// default destructor we didn't dynamically allocate anything
/// so we don't need to free it, but mthod needs to be here
/// </summary>
Game::~Game()
{
}


/// <summary>
/// main game loop
/// update 60 times per second,
/// process update as often as possible and at least 60 times per second
/// draw as often as possible but only updates are on time
/// if updates run slow then don't render frames
/// </summary>
void Game::run()
{	
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float fps{ 30.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps); // 30 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}
/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	sf::Event newEvent;
	while (m_window.pollEvent(newEvent))
	{
		if ( sf::Event::Closed == newEvent.type) // window message
		{
			m_exitGame = true;
		}
		if (sf::Event::KeyPressed == newEvent.type) //user pressed a key
		{
			processKeys(newEvent);
		}
	}
}


/// <summary>
/// deal with key presses from the user
/// </summary>
/// <param name="t_event">key press event</param>
void Game::processKeys(sf::Event t_event)
{
	if (sf::Keyboard::Escape == t_event.key.code)
	{
		m_exitGame = true;
	}
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();
	}
}

/// <summary>
/// draw the frame and then switch buffers
/// </summary>
void Game::render()
{
	m_window.clear(GREY);
	m_window.draw(m_redSquare);
	m_window.draw(m_blueSquare);
	m_window.draw(m_greenSquare);
	m_window.draw(m_yellowSquare);

	m_window.draw(m_titleName);
	m_window.draw(m_greenEasy);
	m_window.draw(m_yellowMedium);
	m_window.draw(m_redHard);
	m_window.draw(m_blueExit);


	m_window.display();
}

void Game::squareSetup()
{
	m_redSquare.setFillColor(RED);
	m_redSquare.setPosition(sf::Vector2f(575, 25));
	m_blueSquare.setFillColor(BLUE);
	m_blueSquare.setPosition(sf::Vector2f(350, 25));
	m_greenSquare.setFillColor(GREEN);
	m_greenSquare.setPosition(sf::Vector2f(575, 250));
	m_yellowSquare.setFillColor(YELLOW);
	m_yellowSquare.setPosition(sf::Vector2f(350, 250));
}

void Game::title()
{
	if (!m_ArialBlackfont.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
	{
		std::cout << "Problem with Ariel FOnt" << std::endl;
	}
	m_titleName.setFont(m_ArialBlackfont);
	m_titleName.setString("SIMON GAME");
	m_titleName.setPosition(25.0f, 30.0f);
	m_titleName.setCharacterSize(40U);
	m_titleName.setOutlineColor(sf::Color::Black);
	m_titleName.setFillColor(sf::Color::White);
	m_titleName.setOutlineThickness(3.0f);

	m_greenEasy.setFont(m_ArialBlackfont);
	m_greenEasy.setFillColor(GREEN);
	m_greenEasy.setCharacterSize(32);
	m_greenEasy.setPosition(25, 85);
	m_greenEasy.setString("Press green for \nan easy game");

	m_yellowMedium.setFont(m_ArialBlackfont);
	m_yellowMedium.setFillColor(YELLOW);
	m_yellowMedium.setCharacterSize(32);
	m_yellowMedium.setPosition(25, 185);
	m_yellowMedium.setString("Press yellow for \na medium game");

	m_redHard.setFont(m_ArialBlackfont);
	m_redHard.setFillColor(RED);
	m_redHard.setCharacterSize(32);
	m_redHard.setPosition(25, 285);
	m_redHard.setString("Press red for \na hard game");

	m_blueExit.setFont(m_ArialBlackfont);
	m_blueExit.setFillColor(BLUE);
	m_blueExit.setCharacterSize(32);
	m_blueExit.setPosition(25, 385);
	m_blueExit.setString("Press blue to exit");
}