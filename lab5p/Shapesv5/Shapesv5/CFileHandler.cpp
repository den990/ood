#include "CFileHandler.h"

CFileHandler::CFileHandler(std::string fileName, CShapeHandler* shapeHendler, CSave* saveIn, CLoad* importFrom) :
	m_fileName(fileName),
	m_shapeHandler(shapeHendler),
	m_saveIn(saveIn),
	m_importFrom(importFrom)
{};

void CFileHandler::Save()
{
	m_saveIn->Save(m_fileName, m_shapeHandler->GetShapes());
}

void CFileHandler::Import()
{
	m_shapeHandler->RestoreState(m_importFrom->Import(m_fileName));
}

std::string CFileHandler::GetTypeSave() const
{
	return typeid(*m_saveIn).name();
}

std::string CFileHandler::GetTypeImport() const
{
	return typeid(*m_importFrom).name();
}
