#pragma once
#include "CBuilder.h"
#include "CTriangle.h"

class CTriangleBuilder : public CBuilder
{
public:
	CTriangleBuilder(std::vector<unsigned int> args);
	void SetShape() override;
	void SetPosition() override;
private:
	sf::Vector2f m_vertexFirst;
	sf::Vector2f m_vertexSecond;
	sf::Vector2f m_vertexThird;
};