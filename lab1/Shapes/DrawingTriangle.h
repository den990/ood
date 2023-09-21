#pragma once
#include "IDrawingStrategy.h"
class DrawingTriangle : public IDrawingStrategy
{
	void Draw(sf::RenderWindow& window) const override;
};