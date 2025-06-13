#include "GameController.h"
#include "GameMenu/FontHolder.h"
#include "ImageMenu.h"

int main()
{
	ImagesObject::loadAllImagesObject(); // load images
	ImageMenu::loadAllTextures();
	FontHolder::loadFont();

	GameController gameController;
	gameController.run();
}