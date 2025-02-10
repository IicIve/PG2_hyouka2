#include "Enemy.h"
#include <Novice.h>

Enemy::Enemy() {
	pos_ = {640.0f,100.0f};
	radius_ = 16;
	speed_ = 8;
	isHit_ = false;
	isAlive = true;
	enemyRespawnTimer = 120;
}

void Enemy::Update() {
	if (isAlive) {
		pos_.x += speed_;
		if (pos_.x + radius_ >= 1280 || pos_.x <= radius_) {
			speed_ = -speed_;
		}
	}

	if (isHit_) {
		isAlive = false;
	}

	if (!isAlive) {
		if (enemyRespawnTimer >= 0) {
			enemyRespawnTimer--;
		}
		if (enemyRespawnTimer <= 0) {
			isAlive = true;
		}
	}

}

void Enemy::Draw() {
	if (isAlive) {
		Novice::DrawEllipse(static_cast<int>(pos_.x), static_cast<int>(pos_.y),
			static_cast<int>(radius_), static_cast<int>(radius_), 0.0f, RED, kFillModeSolid);
	}

}

int Enemy::GetIsHit() {
	return isHit_;
}

void Enemy::SetIsHit(int isHit) {
	isHit_ = isHit;
}
