/// <summary>
/// author Darragh McKernan
/// </summary>
#ifndef GAME_HPP
#define GAME_HPP
/// <summary>
/// include guards used so we don't process this file twice
/// same as #pragma once
/// Don't forget the endif at the bottom
/// </summary>
#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();

private:

	void processEvents();
	void processKeys(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();
	void squareSetup();
	

	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message
	bool m_exitGame; // control exiting game
	sf::RectangleShape m_redSquare;
	const sf::Color RED{ 128,0,0,255 };//Sets a constant colour for red that can be used instead of the default red 
	const sf::Color GREY{ 128,128,128,255 };

};

#endif // !GAME_HPP

