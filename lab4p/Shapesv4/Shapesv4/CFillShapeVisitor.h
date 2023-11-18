#pragma once
#include "IVisitor.h"

class CFillShapeVisitor : public IVisitor
{
public:
	CFillShapeVisitor(sf::Color color);
	void VisiteShape(ShapeDecorator* shape) override;
private:
	sf::Color m_color;
};