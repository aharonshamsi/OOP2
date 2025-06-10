#include "GameControler.h"
#include "GameMenu/FontHolder.h"

int main()
{
	ImagesObject::loadAllTextures(); // תעינת תמונות מל תפריט
	FontHolder::loadFont();

	GameControler gameControler;
	gameControler.run();
}
