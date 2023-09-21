#include "CCanvas.h"
#include "ShapeController.h"
#include <SFML/Graphics.hpp>
#include <fstream>

int main()
{
    std::ifstream inF1("figures.txt");
    std::vector<std::shared_ptr<IShape>> shapes;
    ShapeController shapeController(shapes, inF1, std::cout);

    shapeController.Start();

    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    CCanvas canvas(window);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(250, 220, 100, 0));

        canvas.DrawCircle({ 400, 300 }, 100, 200);
        canvas.FillCircle({ 400, 300 }, 100, 200);

        // sf::CircleShape circle(50.f);

        // Закрашиваем наш круг
        // circle.setFillColor(sf::Color(230, 0, 230));

        // Отрисовка круга
        // window.draw(circle);

        window.display();
    }

    return 0;
}