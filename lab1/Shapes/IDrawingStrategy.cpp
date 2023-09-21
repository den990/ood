#include "IDrawingStrategy.h"

sf::Color IDrawingStrategy::StringToSfmlColor(const std::string& colorStr)
{
    if (colorStr.size() != 7 || colorStr[0] != '#')
    {
        return sf::Color::White; 
    }

    std::istringstream iss(colorStr.substr(1));
    int r, g, b;
    iss >> std::hex >> r >> g >> b;

    if (!iss)
    {
        return sf::Color::White; 
    }

    return sf::Color(static_cast<sf::Uint8>(r), static_cast<sf::Uint8>(g), static_cast<sf::Uint8>(b));
}

