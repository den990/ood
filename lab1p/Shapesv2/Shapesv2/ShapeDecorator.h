#pragma once
#include "include.h"

typedef std::unique_ptr<sf::Shape> ShapePtr;

class ShapeDecorator : sf::Shape
{
public:

	std::size_t getPointCount() const override { return 0; };
	sf::Vector2f getPoint(std::size_t index) const override { return { 0, 0 }; };
	virtual float GetSquare() const = 0;
	virtual float GetPerimeter() const = 0;
	virtual std::string ToString() const = 0;
	void Draw(sf::RenderWindow& window);
protected:
	ShapeDecorator(ShapePtr&& shape);
private:
	ShapePtr m_shape;
};