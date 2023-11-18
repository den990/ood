#pragma once
#include "include.h"
#include "const.h"
class ShapeDecorator 
{
public:

	virtual float GetSquare() const = 0;
	virtual float GetPerimeter() const = 0;
	virtual std::string ToString() const = 0;

	virtual void SetOutlineThickness(float thickness) const = 0;
	virtual void SetOutlineColor(sf::Color color) const = 0;
	virtual void SetFillColor(sf::Color color) const = 0;

	virtual void SetPosition(sf::Vector2f position) const = 0;
	virtual sf::Vector2f GetPosition() const = 0;

	virtual sf::Color GetColor() const = 0;
	virtual sf::Color GetEdgeColor() const = 0;
	virtual float GetEdgeWidth() const = 0;

	virtual sf::FloatRect GetGlobalBounds() const = 0;
	virtual void Draw(sf::RenderWindow& window) const = 0;
	bool IsPointInShape(const sf::Vector2f& point) const;

	void SetSelect(bool select);
	bool GetSelect() const;

	virtual std::string GetType();

protected:
	sf::RectangleShape GetBounds(sf::Vector2f position, sf::Vector2f size) const;
	bool m_select = false;
	std::string m_type;
};