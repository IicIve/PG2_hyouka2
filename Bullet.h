#pragma once
#include "Object.h"
class Bullet : public Object {
private:
	/*int bulletPosX_;
	int bulletPosY_;
	int bulletSpeed_;
	int bulletRadius_;*/
	int isShot_;

public:
	/// <summary>
	/// コンストラクター
	/// </summary>
	Bullet(Vector2 pos, int radius,int speed);

	/// <summary>
	/// 弾が発射されたら上に動かす
	/// </summary>
	void Update();

	/// <summary>
	/// 描画関数
	/// </summary>
	void Draw();

};

