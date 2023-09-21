#pragma once
#include <SFML/Graphics.hpp>
#include "IVisualObjectInfo.h"
class IDrawingStrategy
{
public:
	virtual ~IDrawingStrategy() = default;
	virtual void Draw(sf::RenderWindow& window) const = 0;

};