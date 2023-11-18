#include <iostream>
#include "CShapeController.h"
#include <fstream>
int main()
{
    std::ifstream fileInput("input.txt");
    std::ofstream fileOutput("output.txt");
    CShapeController shape(fileInput, fileOutput);
    shape.Start();
}


