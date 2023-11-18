#pragma once
#include "CBuilder.h"
#include "CRectangle.h"

class CRectangleBuilder : public CBuilder
{
public:
	CRectangleBuilder(std::vector<unsigned int> args);

	void SetShape() override;
	void SetPosition() override;

private:
	sf::Vector2f m_leftTop;
	sf::Vector2f m_rightBottom;
};