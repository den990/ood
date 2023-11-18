#include "CCompositeBuilder.h"

CCompositeBuilder::CCompositeBuilder(std::vector<ShapeDecorator*> shapes)
	:m_shapes(shapes)
{
	m_borderThickness = 5;
	m_borderColor = 1887209727;
	m_fillColor = 3032272127;
}

void CCompositeBuilder::SetShape()
{
	CShapeComposite* compositeShape = new CShapeComposite();

	for (const auto& shape : m_shapes)
	{
		compositeShape->Add(shape);
	}

	m_shape = compositeShape;
}

void CCompositeBuilder::SetPosition()
{
}

void CCompositeBuilder::SetBorderThickness()
{
}

void CCompositeBuilder::SetBorderColor()
{
}

void CCompositeBuilder::SetFillColor()
{
}
