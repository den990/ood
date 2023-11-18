#pragma once
#include "CBuilder.h"
#include "CCircle.h"

class CCircleBuilder : public CBuilder
{
public:
	CCircleBuilder(std::vector<unsigned int> args);

	void SetShape() override;
	void SetPosition() override;

private:
	sf::Vector2f m_centerPoint;
	float m_radius;
};