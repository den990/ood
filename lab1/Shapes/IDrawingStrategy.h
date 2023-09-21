#pragma once
#include <SFML/Graphics.hpp>
#include "IVisualObjectInfo.h"
#include <sstream>
class IDrawingStrategy
{
public:
	virtual ~IDrawingStrategy() = default;
	virtual void Draw(sf::RenderWindow& window, IVisualObjectInfo& object) const = 0;
	static sf::Color StringToSfmlColor(const std::string& colorStr);
};