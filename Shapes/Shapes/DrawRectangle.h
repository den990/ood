#pragma once
#include "IDrawingStrategy.h"
#include "Point.h"
#include <Windows.h>
class DrawRectangle : public IDrawingStrategy
{
public:
	void Draw(sf::RenderWindow& window) const override;
};