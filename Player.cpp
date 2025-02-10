#include "Player.h"
#include "Bullet.h"
#include "Object.h"
#include <Novice.h>

Player::Player() {
	pos_ = { 640.0f,600.0f };
	radius_ = 32;
	speed_ = 8;
	bulletRadius_ = 8;
	isShot = false;
	isHit_ = false;
	isAlive = true;
	bullet = new Bullet(pos_, bulletRadius_, speed_);
}

Player::~Player() {

}

void Player::Update(char* keys, char* preKeys) {
	if (keys[DIK_W]) {
		pos_.y -= speed_;

	} else if (keys[DIK_S]) {
		pos_.y += speed_;

	}

	if (keys[DIK_A]) {
		pos_.x -= speed_;

	} else if (keys[DIK_D]) {
		pos_.x += speed_;
	}

	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		isShot = true;
		bullet = new Bullet(pos_, bulletRadius_, speed_);

	}

	if (isShot) {
		bullet->Update();
		if (bullet->pos_.y <= bullet->radius_) {
			delete bullet;
			isShot = false;
		}

	}

	if (isHit_) {
		isAlive = false;
    }

}

void Player::Draw() {
	if (isShot) {
		bullet->Draw();
	}

	if (isAlive) {
		Novice::DrawEllipse(static_cast<int>(pos_.x), static_cast<int>(pos_.y),
			radius_, radius_, 0.0f, WHITE, kFillModeSolid);
	}
}

int Player::GetIsAlive() {
	return isAlive;
}

int Player::GetIsHit() {
	return isHit_;
}

void Player::SetIsHit(int isHit) {
	isHit_ = isHit;
}
