#pragma once
#include "const.h"
#include "ICommand.h"

class CButton
{
public:
	CButton(sf::Vector2f position, sf::Vector2f size, std::string text,
		sf::Color outlineColor = BUTTON_OUTLINE_COLOR, sf::Color fillColor = BUTTON_FILL_COLOR);

	void Draw(sf::RenderWindow& window) const;
	void SetCommand(ICommand* command);
	bool IsPointInButton(sf::Vector2f point) const;
	void PressButton() const;

private:
	sf::RectangleShape m_rect;
	sf::Text m_text;
	sf::Font m_font;

	ICommand* m_command;
};