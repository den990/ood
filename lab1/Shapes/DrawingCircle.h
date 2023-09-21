#pragma once
#include "IDrawingStrategy.h"
class DrawingCricle : public IDrawingStrategy
{
	void Draw(sf::RenderWindow& window) const override;
};