#include "CSimpleShapeDecorator.h"

void CSimpleShapeDecorator::SetOutlineThickness(float thickness) const
{
	m_shape->setOutlineThickness(thickness);
}

void CSimpleShapeDecorator::SetOutlineColor(sf::Color color) const
{
	m_shape->setOutlineColor(color);
}

void CSimpleShapeDecorator::SetFillColor(sf::Color color) const
{
	m_shape->setFillColor(color);
}

void CSimpleShapeDecorator::SetPosition(sf::Vector2f position) const
{
	m_shape->setPosition(position);
}

sf::Vector2f CSimpleShapeDecorator::GetPosition() const
{
	return m_shape->getPosition();
}

void CSimpleShapeDecorator::Draw(sf::RenderWindow& window) const
{
	if (m_select)
	{
		sf::FloatRect bound = m_shape->getGlobalBounds();
		window.draw(GetBounds({ bound.left, bound.top }, { bound.width, bound.height }));
	}
	window.draw(*m_shape);
}

sf::FloatRect CSimpleShapeDecorator::GetGlobalBounds() const
{
	return m_shape->getGlobalBounds();
}
