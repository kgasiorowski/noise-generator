#pragma once
#include <SFML/Graphics.hpp>

class NoiseGen {

public:
	sf::Image noise(sf::Vector2u size);
	sf::Image smooth(sf::Image noiseToSmooth);

};