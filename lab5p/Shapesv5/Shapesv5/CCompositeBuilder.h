#pragma once
#include "CShapeComposite.h"
#include "CBuilder.h"

class CCompositeBuilder : public CBuilder
{
public:
	CCompositeBuilder(std::vector<ShapeDecorator*> shapes);

	void SetShape() override;
	void SetPosition() override;

	void SetBorderThickness() override;
	void SetBorderColor() override;
	void SetFillColor() override;

private:
	std::vector<ShapeDecorator*> m_shapes;
};