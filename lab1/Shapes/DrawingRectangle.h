#pragma once
#include "IDrawingStrategy.h"
class DrawingRectangle : public IDrawingStrategy
{
	void Draw(sf::RenderWindow& window, IVisualObjectInfo& object) const override;
};