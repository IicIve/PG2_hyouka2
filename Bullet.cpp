#include "Bullet.h"
#include <Novice.h>

Bullet::Bullet(Vector2 pos, int radius, int speed){
	pos_ = pos;
	radius_ = radius;
	speed_ = speed;
}

void Bullet::Update() {
	pos_.y -= speed_;
}

void Bullet::Draw() {
	Novice::DrawEllipse(static_cast<int>(pos_.x), static_cast<int>(pos_.y), 
		static_cast<int>(radius_), static_cast<int>(radius_), 0.0f, WHITE, kFillModeSolid);

}
