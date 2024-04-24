#ifndef square_h
#define square_h
#include <SFML/Graphics.hpp>
using namespace sf;

class Square
{
private:
    Vector2f speed;
    Vector2f acc;
    RectangleShape shape;

public:
    Square(Vector2f size);
    Square(Vector2f, int x, int y);

    void update();
    void drawTo(RenderWindow &window);
};

#endif