#pragma once
#include "ShapeDecorator.h"

class CShapeComposite : public ShapeDecorator
{
public:
	CShapeComposite()
	{
	}


	float GetSquare() const override;
	float GetPerimeter() const override;
	std::string ToString() const override;

	void SetOutlineThickness(float thickness) const override;
	void SetOutlineColor(sf::Color color) const override;
	void SetFillColor(sf::Color color) const override;

	void SetPosition(sf::Vector2f position) const override;
	sf::Vector2f GetPosition() const override;

	sf::Color GetColor() const override;
	sf::Color GetEdgeColor() const override;
	float GetEdgeWidth() const override;

	void Draw(sf::RenderWindow& window) const override;

	sf::FloatRect GetGlobalBounds() const override;

	void Add(ShapeDecorator* shape);
	void Remove(ShapeDecorator* shape);
	std::vector<ShapeDecorator*> GetShapes() const;
private:
	std::vector<ShapeDecorator*> m_shapes;
};