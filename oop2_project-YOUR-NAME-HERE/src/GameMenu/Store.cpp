#include "GameMenu/Store.h"

Store::Store(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:Button(TypeButton::Store, location, wantedSize)
{}

void Store::handleClick(State & state, sf::RenderWindow& window, sf::Event& event)
{
	state.setStore(true);
	// פה יהיה פתיחה של החנות וכדומה

	while (window.waitEvent(event)) {
		if (event.type == sf::Event::Closed)
			return;

		window.clear();
		//window.draw(); מופע החנות
		window.display();
	}
}
