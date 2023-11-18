#include "ShapeDecorator.h"

ShapeDecorator::ShapeDecorator(ShapePtr&& shape)
	: m_shape(std::move(shape))
{
}

void ShapeDecorator::Draw(sf::RenderWindow& window)
{
	window.draw(*m_shape);
}
