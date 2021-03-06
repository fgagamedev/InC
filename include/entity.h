#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include "aim.h"
#include "caio.h"
#include "camera.h"
#include "civil.h"
#include "enemy.h"
#include "item.h"
#include "timer.h"
#include "systemlogger.h"

using namespace camera;
using namespace systemLogger;
using namespace timer;

class Entity
{
public:
	Entity();
	virtual ~Entity();
	
	virtual void controlEntityEvents();
	virtual void generateEnemies();

	void initEntity();
	void drawEntity();
	void updateEntity();

protected:
	Aim* aim;
	Caio* caio;
	Enemy* enemy;
	vector<Enemy*> enemies;
	Civil* civil;
	vector<Civil*> civis;
	Item* item;
	vector<Item*> itens;
};

#endif // ENTITY_H
