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
        sf::Event event;
        if (m_window.waitEvent(event))
        {
            m_cursorPosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(m_window));

            switch (event.type)
            {
            case sf::Event::Closed:
            {
                m_window.close();
                break;
            }
            case sf::Event::MouseButtonPressed:
            {
                HandleMouse(event);
                break;
            }
            case sf::Event::MouseButtonReleased:
            {
                m_move = false;
                break;
            }
            case sf::Event::KeyPressed:
            {
                HandleKey(event);
                break;
            }
            }
        }

        Moving();
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


            auto rectangle = new sf::RectangleShape();
            rectangle->setPosition(size);
            rectangle->setSize({ abs(size.x - size1.x), abs(size.y - size1.y) });
            rectangle->setFillColor(sf::Color::Green);

            ShapeDecorator* rectangleDecorator = new CRectangle(std::move(rectangle), size, size1);
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

            auto circle = new sf::CircleShape();
            circle->setPosition(center);
            circle->setRadius(radius);
            circle->setFillColor(sf::Color::Blue);

            ShapeDecorator* circleDecorator = new CCircle(std::move(circle), center, radius);
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

            auto triangle = new sf::ConvexShape();
            triangle->setPointCount(3);
            triangle->setPoint(0, vertex1);
            triangle->setPoint(1, vertex2);
            triangle->setPoint(2, vertex3);
            triangle->setFillColor(sf::Color::Red);

            ShapeDecorator* triangleDecorator = new CTriangle(std::move(triangle), vertex1, vertex2, vertex3);
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

void CShapeController::HandleMouse(sf::Event event)
{
    if (event.mouseButton.button == sf::Mouse::Left)
    {
        for (const auto& shape : m_shapes)
        {
            if (!sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
            {
                for (const auto& shape : m_selectedShapes)
                {
                    ClearSelectedShapes(shape); // написать функцию для очищения
                }
            }
            if (shape->IsPointInShape({ (float)event.mouseButton.x, (float)event.mouseButton.y }))
            {
                if (shape->GetSelect())
                {
                    RemoveShapeInSelect(shape);
                }
                else
                {
                    AddShapeInSelect(shape);
                    PreparingForMove(shape);
                }
            }
        }
    }
}

void CShapeController::AddShapeInSelect(ShapeDecorator* shape)
{
    m_selectedShapes.push_back(shape);
    shape->SetSelect(true);
}

void CShapeController::RemoveShapeInSelect(ShapeDecorator* shape)
{
    auto it = std::find(m_selectedShapes.begin(), m_selectedShapes.end(), shape);
    m_selectedShapes.erase(it);
    shape->SetSelect(false);
}

void CShapeController::ClearSelectedShapes(ShapeDecorator* shape)
{
    shape->SetSelect(false);
    m_selectedShapes.clear();
}

void CShapeController::HandleKey(sf::Event event)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
        {
            GroupShapes();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::U))
        {
            UngroupShapes();
        }
    }
}

void CShapeController::GroupShapes()
{
    if (m_selectedShapes.size() > 1)
    {

        CShapeComposite* compositeShape = new CShapeComposite();

        std::vector<ShapeDecorator*> copySelectedShapes = m_selectedShapes;

        for (const auto& shape : copySelectedShapes)
        {
            compositeShape->Add(shape);
            auto it = find(m_shapes.begin(), m_shapes.end(), shape);
            m_shapes.erase(it);
            RemoveShapeInSelect(shape);
        }

        AddShapeInSelect(compositeShape);
        m_shapes.push_back(compositeShape);
    }
}

void CShapeController::UngroupShapes()
{
    if (m_selectedShapes.size() == 1 && dynamic_cast<CShapeComposite*>(m_selectedShapes.back()))
    {

        CShapeComposite* compositeShape = static_cast<CShapeComposite*>(m_selectedShapes.back());

        std::vector<ShapeDecorator*> compositeShapes = compositeShape->GetShapes();

        auto it = find(m_shapes.begin(), m_shapes.end(), m_selectedShapes.back());
        m_shapes.erase(it);
        RemoveShapeInSelect(m_selectedShapes.back());

        for (const auto& shape : compositeShapes)
        {
            AddShapeInSelect(shape);
            m_shapes.push_back(shape);
        }
    }
}

void CShapeController::PreparingForMove(ShapeDecorator* shape)
{
    m_move = true;
    m_cursorOffset.x = m_cursorPosition.x - shape->GetPosition().x;
    m_cursorOffset.y = m_cursorPosition.y - shape->GetPosition().y;
}

void CShapeController::Moving() const
{
    if (m_selectedShapes.size() == 1 && m_move)
    {
        m_selectedShapes.back()->SetPosition({
            m_cursorPosition.x - m_cursorOffset.x,
            m_cursorPosition.y - m_cursorOffset.y
            });
    }
}

