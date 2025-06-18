#include "GameController.h"
#include "GameMenu/FontHolder.h"
#include "ImageMenu.h"
#include "GameObject/Images/ImagesObject.h"
int main()
{

	ImageMenu::loadAllTextures();
	FontHolder::loadFont();

	ImagesObject::loadAllImagesObject;

	GameController gameController;
	gameController.run();
}