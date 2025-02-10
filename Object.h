#pragma once
struct Vector2 {
	float x, y;
};

class Object {
public:
	Vector2 pos_;
	int speed_;
	int radius_;
	int isHit_;
	int isActive_;


};

