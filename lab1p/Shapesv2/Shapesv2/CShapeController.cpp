#include "CShapeController.h"
const std::string NAME_WINDOW = "Shape";
const std::string INPUT_FILE_NAME = "input.txt";
const std::string OUTPUT_FILE_NAME = "output.txt";
const std::string TYPE_RECTANGLE = "RECTANGLE:";
const std::string TYPE_CIRCLE = "CIRCLE:";
const std::string TYPE_TRIANGLE = "TRIANGLE:";
const std::string ERROR_WRITE_FILE = "Error, failed to write data to file";

CShapeController::CShapeController()
    : m_window(sf::VideoMode(800, 600), NAME_WINDOW)
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
        if (typeFigure == TYPE_RECTANGLE)
        {
            sf::Vector2f size, size1;
            std::string strSize, strSize1;

            iss >> strSize;
            size = ParseCoordinates(strSize);

            iss >> strSize1;
            size1 = ParseCoordinates(strSize1);


            auto rectangle = std::make_unique<sf::RectangleShape>();
            rectangle->setPosition(size);
            rectangle->setSize({ abs(size.x - size1.x), abs(size.y - size1.y) });
            rectangle->setFillColor(sf::Color::Green);

            auto rectangleDecorator = std::make_unique<CRectangle>(std::move(rectangle), size, size1);
            m_shapes.push_back(std::move(rectangleDecorator));
        }
        if (typeFigure == TYPE_CIRCLE)
        {
            sf::Vector2f center;
            float radius;

            std::string centerStr, radiusStr;
            iss >> centerStr >> radiusStr;

            center = ParseCoordinates(centerStr);

            size_t radiusPosition = radiusStr.find('=');
            if (radiusPosition != std::string::npos)
                radius = std::stof(radiusStr.substr(radiusPosition + 1));

            auto circle = std::make_unique<sf::CircleShape>();
            circle->setPosition(center);
            circle->setRadius(radius);
            circle->setFillColor(sf::Color::Blue);

            auto circleDecorator = std::make_unique<CCircle>(std::move(circle), center, radius);
            m_shapes.push_back(std::move(circleDecorator));
        }
        if (typeFigure == TYPE_TRIANGLE)
        {
            sf::Vector2f vertex1, vertex2, vertex3;
            std::string strPoint1, strPoint2, strPoint3;
            iss >> strPoint1 >> strPoint2 >> strPoint3;

            vertex1 = ParseCoordinates(strPoint1);
            vertex2 = ParseCoordinates(strPoint2);
            vertex3 = ParseCoordinates(strPoint3);

            auto triangle = std::make_unique<sf::ConvexShape>();
            triangle->setPointCount(3);
            triangle->setPoint(0, vertex1);
            triangle->setPoint(1, vertex2);
            triangle->setPoint(2, vertex3);
            triangle->setFillColor(sf::Color::Red);

            auto triangleDecorator = std::make_unique<CTriangle>(std::move(triangle), vertex1, vertex2, vertex3);
            m_shapes.push_back(std::move(triangleDecorator));
        }
    }
}

void CShapeController::DrawShapes()
{
    m_window.clear();

    for (const auto& shape : m_shapes)
    {
        shape->Draw(m_window);
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
        output << ERROR_WRITE_FILE << std::endl;
        return;
    }
    for (const auto& shape : m_shapes)
    {
        output << shape->ToString() << std::endl;
    }
}