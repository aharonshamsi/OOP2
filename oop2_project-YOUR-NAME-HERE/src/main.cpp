#include "GameControler.h"
#include "GameMenu/FontHolder.h"
#include "GameObjectType.h"

int main()
{
	ImagesObject::loadAllTextures(); // תעינת תמונות מל תפריט
	FontHolder::loadFont();

	sf::RenderWindow window(sf::VideoMode(GameData::SIZE_GAME_WINDOW.x, GameData::SIZE_GAME_WINDOW.y), "Geometry Dash");
	sf::Vector2f wantedSize(100.f, 200.f);
	sf::Sprite sprint = ImagesObject::getSpinte(GameObjectType::playerOne, wantedSize);

	// בחר את האזור שרוצים להציג מתוך הטקסטורה:
	sf::IntRect rect(0, 0, 50, 50);
	sprint.setTextureRect(rect);


	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		sprint.setPosition(400.f, 400.f);
		window.clear();
		window.draw(sprint);
		window.display();
	}



}
