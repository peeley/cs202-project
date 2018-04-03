// practice.cpp
// created 3/30/2018 by TB
// this program is for testing out git and checking compatibility issues

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <string>
using std::string;
using std::getline;
#include <vector>
using std::vector;
#include <sstream>
using std::istringstream;
using std::ostringstream;
using std::stringstream;
#include <fstream>
using std::ofstream;
using std::ifstream;
using std::fstream;
#include <cstdlib>
#include <algorithm>
#include <ios>

#include <SFML/Graphics.hpp>

void sfTest();

int main(){
	cout << "Hello world!" << endl;
	sfTest();
	return 0;
}

void sfTest(){
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }
		window.clear();
        window.draw(shape);
        window.display();
    }
}




