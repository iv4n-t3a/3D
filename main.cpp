#include <iostream>
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <time.h>
#include <chrono>
#include <thread>

#include "math.h"
#include "config.h"


using namespace std::this_thread;
using namespace std::chrono;

void drawTriangle2(sf::RenderWindow& win, Triangle2 t) {
	sf::Vertex ab[] = {
		sf::Vertex( sf::Vector2f(t[0].x * SCALE + OFFSET.x, t[0].y * SCALE + OFFSET.y) ),
		sf::Vertex( sf::Vector2f(t[1].x * SCALE + OFFSET.x, t[1].y * SCALE + OFFSET.y) )
	};
	sf::Vertex bc[] = {
		sf::Vertex( sf::Vector2f(t[1].x * SCALE + OFFSET.x, t[1].y * SCALE + OFFSET.y) ),
		sf::Vertex( sf::Vector2f(t[2].x * SCALE + OFFSET.x, t[2].y * SCALE + OFFSET.y) )
	};
	sf::Vertex ac[] = {
		sf::Vertex( sf::Vector2f(t[0].x * SCALE + OFFSET.x, t[0].y * SCALE + OFFSET.y) ),
		sf::Vertex( sf::Vector2f(t[2].x * SCALE + OFFSET.x, t[2].y * SCALE + OFFSET.y) )
	};
	win.draw(ab, 2, sf::Lines);
	win.draw(bc, 2, sf::Lines);
	win.draw(ac, 2, sf::Lines);
}
void renderTriangle3(sf::RenderWindow& win, Triangle3 t3) {
	Triangle2 t2 = {
		Vec2(t3[0].x, t3[0].y),
		Vec2(t3[1].x, t3[1].y),
		Vec2(t3[2].x, t3[2].y)
	};
	drawTriangle2(win, t2);
}

int main() {
	sf::RenderWindow win(sf::VideoMode(800, 800), "RENDER");

	double xy = XY_START;
	double xz = XZ_START;
	double yz = YZ_START;

	while (win.isOpen()) {
		sf::Event e;
		while (win.pollEvent(e))
			if (e.type == sf::Event::Closed) win.close();

		xy += XY_SPEED;
		xz += XZ_SPEED;
		yz += YZ_SPEED;
		win.clear();
		for (Triangle3 t : tris) {
			Triangle3 tr = rotate(t, xy, xz, yz);
			renderTriangle3(win, tr);
		}
		win.display();
	}

	return 0;
}
