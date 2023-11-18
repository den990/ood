#pragma once
#include "include.h"
#include "const.h"
#include "CShapeHandler.h"
#include "CUserInterface.h"
#include "CDragAndDropState.h"
#include "CFillShapeState.h"
#include "CFillBorderState.h"
#include "CWidthBorderState.h"
#include <functional>
#include <string>
#include "CFillShapeVisitor.h"
#include "CFillBorderVisitor.h"
#include "CWidthBorderVisitor.h"


class CShapeController
{
public:
    CShapeController(std::istream& input, std::ostream& output);
    void Start();

private:

    void Draw();
    void DrawShapes();
    void DrawUserInterface() const;

    void ReadFileAndFillData(const std::string& fileName);

    void WriteData(const std::string& fileName);

    using Handler = std::function<void(std::istringstream& args)>;
    using ActionMap = std::map<std::string, Handler>;

    const ActionMap m_actionMap;

    sf::RenderWindow m_window;
    CShapeHandler* m_shapeHandler;
    CUserInterface* m_userInterface;
    std::istream& m_input;
    std::ostream& m_output;
};