#include "CShapeController.h"
const std::string WINDOW_NAME = "Shape";
const std::string RECTANGLE_TYPE = "RECTANGLE:";
const std::string CIRCLE_TYPE = "CIRCLE:";
const std::string TRIANGLE_TYPE = "TRIANGLE:";
const std::string INPUT_FILE_NAME = "input.txt";
const std::string OUTPUT_FILE_NAME = "output.txt";


 CShapeController::CShapeController()
    : m_window(sf::VideoMode(800, 600), WINDOW_NAME)
{
}

void CShapeController::Start()
{
    ReadFileAndFillData(INPUT_FILE_NAME);

    while (m_window.isOpen())
    {
        HandleEvents();
        DrawShapes();
    }

    WriteData(OUTPUT_FILE_NAME);
}

sf::Vector2f CShapeController::ParseCoordinates(const std::string& coordStr)
{
    sf::Vector2f result;
    size_t position = coordStr.find("=");
    if (position != std::string::npos)
    {
        result.x = std::stof(coordStr.substr(position + 1));
        size_t commaPos = coordStr.find(',', position);
        if (commaPos != std::string::npos)
        {
            result.y = std::stof(coordStr.substr(commaPos + 1));
        }
    }
    return result;
}

void CShapeController::ReadFileAndFillData(const std::string& fileName)
{
    std::ifstream fileInput(fileName);
    if (!fileInput)
    {
        std::cout << "Error, file not exist" << std::endl;
        return;
    }
    std::string line;
    while (getline(fileInput, line))
    {
        std::istringstream iss(line);
        std::string typeFigure;
        iss >> typeFigure;
        if (typeFigure == RECTANGLE_TYPE)
        {
            sf::Vector2f size, size1;
            std::string strSize, strSize1;

            iss >> strSize;
            size = ParseCoordinates(strSize);

            iss >> strSize1;
            size1 = ParseCoordinates(strSize1);

            // Создаем декоратор для прямоугольника
            std::unique_ptr<sf::Shape> rectangleDecorator = std::make_unique<CRectangleDecorator>(size, size1);
            m_shapes.push_back(std::move(rectangleDecorator));
        }
        if (typeFigure == CIRCLE_TYPE)
        {
            sf::Vector2f center;
            float radius;

            std::string centerStr, radiusStr;
            iss >> centerStr >> radiusStr;

            center = ParseCoordinates(centerStr);

            size_t radiusPosition = radiusStr.find('=');
            if (radiusPosition != std::string::npos)
                radius = std::stof(radiusStr.substr(radiusPosition + 1));

            // Создаем декоратор для окружности
            std::unique_ptr<sf::Shape> circleDecorator = std::make_unique<CCircleDecorator>(center.x, center.y, radius);
            m_shapes.push_back(std::move(circleDecorator));
        }
        if (typeFigure == TRIANGLE_TYPE)
        {
            sf::Vector2f point1, point2, point3;
            std::string strPoint1, strPoint2, strPoint3;
            iss >> strPoint1 >> strPoint2 >> strPoint3;

            point1 = ParseCoordinates(strPoint1);
            point2 = ParseCoordinates(strPoint2);
            point3 = ParseCoordinates(strPoint3);

            // Создаем декоратор для треугольника
            std::unique_ptr<sf::Shape> triangleDecorator = std::make_unique<CTriangleDecorator>(point1, point2, point3);
            m_shapes.push_back(std::move(triangleDecorator));
        }
    }
}

void CShapeController::DrawShapes()
{
    m_window.clear();

    for (const auto& shape : m_shapes)
    {
        m_window.draw(*shape);
    }

    m_window.display();
}

void CShapeController::HandleEvents()
{
    sf::Event event;
    while (m_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            m_window.close();
    }
}

void CShapeController::WriteData(const std::string& fileName)
{
    std::ofstream output(fileName);
    if (!output)
    {
        output << "Error, failed to write data to file" << std::endl;
        return;
    }
    for (const auto& shape : m_shapes)
    {
        if (auto* decorator = dynamic_cast<CRectangleDecorator*>(shape.get()))
        {
            output << decorator->PrintInfo() << std::endl;
        }
        if (auto* decorator = dynamic_cast<CCircleDecorator*>(shape.get()))
        {
            output << decorator->PrintInfo() << std::endl;
        }
        if (auto* decorator = dynamic_cast<CTriangleDecorator*>(shape.get()))
        {
            output << decorator->PrintInfo() << std::endl;
        }
    }
}
