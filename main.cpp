#include <cmath>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include "tweens.h"
#include "colorf.h"

using namespace std;
using namespace sf;

void update_state(float dt);
void render_frame();

RenderWindow window;
Font font;

const Vector2f START_POS(100, 250);
const Vector2f END_POS(600, 250);
const ColorF START_COLOR(1, 0, 0);
const ColorF END_COLOR(0, 1, 0);
RectangleShape shape;

float t = 0;
bool isTweening = false;

int main()
{
	window.create(VideoMode(800, 600), "SFML Example");
	font.loadFromFile("arial.ttf");

	shape.setPosition(START_POS);
	shape.setFillColor(Color::Red);
	shape.setSize(Vector2f(100, 100));

	Clock clock;

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			else if (event.type == sf::Event::KeyPressed && event.key.code == Keyboard::Space)
			{
				if (isTweening)
				{
					isTweening = false;
					t = 0;
				}
				else
				{
					isTweening = true;
				}
			}
		}

		float dt = clock.restart().asSeconds();

		update_state(dt);
		render_frame();
		window.display();
	}

	return 0;
}

void update_state(float dt)
{
	if (isTweening)
		t = fminf(t + dt, 1);

	Vector2f pos = lerp(START_POS, END_POS, t);
	shape.setPosition(pos);

	ColorF col = lerp(START_COLOR, END_COLOR, t);
	shape.setFillColor(col);
}

void render_frame()
{
	window.clear();
	window.draw(shape);

	string s = "t=";
	s += to_string(t);
	Text txt;
	txt.setString(s);
	txt.setFont(font);
	txt.setPosition(shape.getPosition() + Vector2f(0, 110));
	txt.setCharacterSize(24);
	txt.setFillColor(Color::White);
	window.draw(txt);
}