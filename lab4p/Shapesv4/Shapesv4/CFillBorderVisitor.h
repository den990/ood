#pragma once
#include "IVisitor.h"

class CFillBorderVisitor : public IVisitor
{
public:
	CFillBorderVisitor(sf::Color color);
	void VisiteShape(ShapeDecorator* shape) override;
private:
	sf::Color m_color;
};