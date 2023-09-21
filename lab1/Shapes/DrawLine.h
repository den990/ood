#pragma once
#include "IDrawingStrategy.h"
class DrawingLine : public IDrawingStrategy
{
	void Draw(sf::RenderWindow& window) const override;
};