#include "GameController.h"
#include "GameMenu/FontHolder.h"
#include "ImageMenu.h"

int main()
{
	ImageMenu::loadAllTextures();
	FontHolder::loadFont();

	GameController gameController;
	gameController.run();
}