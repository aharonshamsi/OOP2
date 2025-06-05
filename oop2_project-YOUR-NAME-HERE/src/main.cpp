#include "GameControler.h"
#include "GameMenu/FontHolder.h"

int main()
{
	ImagesButton::loadAllTextures(); // תעינת תמונות מל תפריט
	FontHolder::loadFont();

	GameControler gameControler;
	gameControler.runGeometryDash();
}
