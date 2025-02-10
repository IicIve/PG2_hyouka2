#pragma once
#include "Object.h"
#include "Bullet.h"

class Player : public Object{
public:
	Player();
	~Player();
	void Update(char* keys, char* preKeys);
	void Draw();
	int GetIsAlive();
	int GetIsHit();
	void SetIsHit(int isHit);
private:
	int isShot;
	int isAlive;
public:
	int bulletRadius_;
	Bullet* bullet;

};

