#include "NoiseGen.h"
#include <cstdio>

sf::Image NoiseGen::noise(sf::Vector2u size) {

	sf::Image toReturn;
	toReturn.create(size.x, size.y);

	printf("Creating noise with width: %d and height: %d\n", size.x, size.y);

	for(unsigned int x = 0; x < size.x; x++)
		for (unsigned int y = 0; y < size.y; y++)
		{

			int randshade = rand() % 255;
			toReturn.setPixel(x, y, sf::Color(randshade, randshade, randshade));

		}

	return toReturn;

}

sf::Image NoiseGen::smooth(sf::Image noiseToSmooth) {

	//Bi-linearly interpolates the noise so it looks a little more natural
	sf::Image toReturn;
	int noiseWidth = noiseToSmooth.getSize().x, noiseHeight = noiseToSmooth.getSize().y;

	toReturn.create(noiseWidth, noiseHeight);

	//std::cout << "Generated an empty smoothed image with width " << noiseWidth << " and height " << noiseHeight << std::endl;
	printf("Width: %d, Height: %d\n", noiseWidth, noiseHeight);

	for(int x = 0; x < noiseWidth; x++)
		for (int y = 0; y < noiseHeight; y++) {

			double fracX, fracY;

			fracX = x - int(x);
			fracY = y - int(y);

			int x1 = (int(x) + noiseWidth) % noiseWidth;
			int y1 = (int(y) + noiseHeight) % noiseHeight;

			int x2 = (x1 + noiseWidth - 1) % noiseWidth;
			int y2 = (y1 + noiseHeight - 1) % noiseHeight;

			double value = 0.0;

			value += fracX * fracY * noiseToSmooth.getPixel(y1, x1).r;
			value += (1 - fracX) * fracY * noiseToSmooth.getPixel(y1, x2).r;
			value += fracX * (1 - fracY) * noiseToSmooth.getPixel(y2, x1).r;
			value += (1 - fracX) * (1 - fracY) * noiseToSmooth.getPixel(y2, x2).r;

			sf::Color color(value, value, value);
			toReturn.setPixel(x, y, color);

		}

	return toReturn;

}