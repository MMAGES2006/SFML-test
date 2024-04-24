#include <SFML/Graphics.hpp>
#include "square.hpp"
#include <vector>
using namespace sf;
using namespace std;

Vector2f speed = {5.f, 10.f};

int main()
{
    RenderWindow window(VideoMode(800, 600), "SFML works!");
    Square shape(Vector2f(50.f, 50.f));
    window.setFramerateLimit(60);
    vector<Square> cuadrados;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == Mouse::Left)
                {
                    int w = rand() % 100;
                    int h = rand() % 100;
                    int x = event.mouseButton.x;
                    int y = event.mouseButton.y;
                    Square cuad(Vector2f(w, h), x, y);
                    cuadrados.push_back(cuad);
                }
            }
        }
        window.clear();
        shape.update();
        shape.drawTo(window);
        for (auto &c : cuadrados)
        {
            c.update();
            c.drawTo(window);
        }

        window.display();
    }

    return 0;
}