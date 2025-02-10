#pragma once
#include "Object.h"
class Enemy : public Object{
public:
	Enemy();
	void Update();
	void Draw();
	int GetIsHit();
	void SetIsHit(int isHit);
private:
	int isAlive;
	int enemyRespawnTimer;

};

