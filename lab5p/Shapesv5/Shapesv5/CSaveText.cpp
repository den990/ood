#include "CSaveText.h"

void CSaveText::Save(std::string& fileName, std::vector<ShapeDecorator*> shapes)
{
	std::ofstream output(fileName + ".txt");
	PrintShapeInfo(output, shapes);
	output.close();
}
