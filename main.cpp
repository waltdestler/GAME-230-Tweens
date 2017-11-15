#include <cmath>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

using namespace std;
using namespace sf;

void update_state(float dt);
void render_frame();

RenderWindow window;
Font font;

const Vector2f START_POS(100, 250);
const Vector2f END_POS(600, 250);
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

template<typename T>
T lerp(T start, T end, float t)
{
	return start + (end - start) * t;
}

template<typename T>
T easeIn(T start, T end, float t)
{
	return start + (end - start) * t * t * t;
}

template<typename T>
T easeOut(T start, T end, float t)
{
	--t;
	return start + (end - start) * (t * t * t + 1);
}

template<typename T>
T easeInOut(T start, T end, float t)
{
	return start + (end - start) * (t * t * (3.0f - 2.0f * t));
}

template<typename T>
T easeOutBack(T start, T end, float t)
{
	const float s = 1.70158f;
	--t;
	return start + (end - start) * (t * t * ((s + 1) * t + s) + 1);
}

template<typename T>
T easeOutBounce(T start, T end, float t)
{
	if (t < (1 / 2.75f)) {
		return start + (end - start) * (7.5625f*t*t);
	}
	else if (t < (2 / 2.75f)) {
		float postFix = t -= (1.5f / 2.75f);
		return start + (end - start) * (7.5625f*(postFix)*t + .75f);
	}
	else if (t < (2.5 / 2.75)) {
		float postFix = t -= (2.25f / 2.75f);
		return start + (end - start) * (7.5625f*(postFix)*t + .9375f);
	}
	else {
		float postFix = t -= (2.625f / 2.75f);
		return start + (end - start) * (7.5625f*(postFix)*t + .984375f);
	}
}

void update_state(float dt)
{
	if (isTweening)
		t = fminf(t + dt, 1);

	Vector2f pos = easeOutBounce(START_POS, END_POS, t);
	shape.setPosition(pos);
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