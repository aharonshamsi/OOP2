#include "GameMenu/Help.h"

Help::Help(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:Button(TypeButton::Help, location, wantedSize)
{
    InitInstructions();

	m_instructionText = FontHolder::getText();
	m_instructionText.setString(m_instructions);
	m_instructionText.setPosition(50.f, 50.f);

}

void Help::handleClick(State & state, sf::RenderWindow& window, sf::Event& event)
{
	state.setHelp(true);

	while (window.waitEvent(event)) {
		if (event.type == sf::Event::Closed)
			return;

		window.clear();
		window.draw(m_instructionText);
		window.display();
	}
}


void Help::InitInstructions()
{
	m_instructions = 
        "Welcome to Geometry Dash!\n"
        "\n"
        "Controls:\n"
        "- Press SPACE or click to jump.\n"
        "- Avoid spikes and gaps.\n"
        "- Reach the goal to win!\n"
        "\n"
        "Collect Coins:\n"
        "- Each level has coins to collect.\n"
        "- Coins add to your total score.\n"
        "\n"
        "Store:\n"
        "- Use coins to unlock new players.\n"
        "- Open the store from the main menu.\n"
        "\n"
        "Tips:\n"
        "- Timing is key.\n"
        "- Some jumps are trickier than others.\n"
        "- Practice makes perfect!\n"
        "\n"
        "Have fun and good luck!";
}
