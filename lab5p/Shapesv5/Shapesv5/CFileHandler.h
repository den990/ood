#pragma once
#include "CSave.h"
#include "CLoad.h"
#include "CShapeHandler.h"

class CShapeHandler;

class CFileHandler
{
public:
	CFileHandler(std::string fileName, CShapeHandler* shapeHendler, CSave* save, CLoad* importFrom);
	void Save();
	void Import();

	std::string GetTypeSave() const;
	std::string GetTypeImport() const;

	CSave* m_saveIn;
	CLoad* m_importFrom;
	std::string m_fileName;
	CShapeHandler* m_shapeHandler;
};