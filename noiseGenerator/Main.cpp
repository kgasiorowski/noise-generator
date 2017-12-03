#include <SFML\Graphics.hpp>
#include <iostream>
#include "NoiseGen.h"


using namespace std;

void exitWithStatus(const int EXIT) {

	cout << "Press enter to continue..." << endl;
	getchar();
	exit(EXIT);

}


int main() {

	sf::Vector2u size;
	string filename;
	NoiseGen noiseGen;

	cout << "Enter width: ";
	cin >> size.x;

	cout << "And height: ";
	cin >> size.y;

	cout << "Output filename: ";
	cin >> filename;

	cout << "Generating..." << endl;
	sf::Image noise = noiseGen.noise(size);

	cout << "Writing to file..." << endl;
	noise.saveToFile(filename);

	cout << "Smoothing noise..." << endl;
	sf::Image smoothedNoise = noiseGen.sfSmooth(noise);

	string rawfilename = filename.substr(0, filename.find("."));
	string extension = filename.substr(filename.find("."));

	string smoothedNoiseFile = rawfilename + "_smooth" + extension;

	cout << "Writing smoothed noise to " << smoothedNoiseFile << endl;
	smoothedNoise.saveToFile(smoothedNoiseFile);

	cout << "Done!" << endl;

	getchar();
	exitWithStatus(EXIT_SUCCESS);

}