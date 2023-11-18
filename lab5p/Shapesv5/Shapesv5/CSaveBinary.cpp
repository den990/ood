#include "CSaveBinary.h"

void CSaveBinary::Save(std::string& fileName, std::vector<ShapeDecorator*> shapes)
{
	std::ostringstream strm;
	PrintShapeInfo(strm, shapes);

	std::ofstream output(fileName + ".bin", std::ios::out | std::ios::binary);
	output << strm.str().c_str();
}
