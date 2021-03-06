#ifndef LEVELONE_H
#define LEVELONE_H

#include "stage.h"
#include "curupira.h"

class LevelOne : public Stage
{
public:
	LevelOne();
	~LevelOne();

	void generateEnemies();
	void generateCivilians();
	void drawScenarioRelativeImages();

	void defineBackground();
	void generatePlatform();
	void generateSecondLayer();
};

#endif // LEVELONE_H