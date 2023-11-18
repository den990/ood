#include "CButton.h"

CButton::CButton(sf::Vector2f position, sf::Vector2f size, std::string text, sf::Color outlineColor, sf::Color fillColor)
{

	m_rect.setPosition(position);
	m_rect.setSize(size);
	m_rect.setOutlineThickness(BUTTON_OUTLINE_THICKNESS);
	m_rect.setOutlineColor(outlineColor);
	m_rect.setFillColor(fillColor);

	if (m_font.loadFromFile(BUTTON_FONT_FILE))
	{
		m_text.setFont(m_font);
		m_text.setString(text);
		m_text.setFillColor(sf::Color::White);//почему то не передается из констант
		m_text.setCharacterSize(BUTTON_TEXT_SIZE);

		auto rect = m_text.getGlobalBounds();
		sf::Vector2f offset;
		offset.x = (size.x - rect.width) / 2;
		offset.y = (size.y - rect.height) / 2;

		m_text.setPosition({ position.x + offset.x, position.y + offset.y });
	}
}

void CButton::Draw(sf::RenderWindow& window) const
{
	window.draw(m_rect);
	window.draw(m_text);
}

void CButton::SetCommand(ICommand* command)
{
	m_command = command;
}

bool CButton::IsPointInButton(sf::Vector2f point) const
{
	return m_rect.getGlobalBounds().contains(point);
}

void CButton::PressButton() const
{
	m_command->Execute();
}