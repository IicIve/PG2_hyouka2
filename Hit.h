#pragma once
#include "Object.h"
class Hit {
public:
	/// <summary>
	/// 当たり判定の関数
	/// </summary>
	/// <param name="pos1">1つ目の円の座標</param>
	/// <param name="radius1">1つ目の円の半径</param>
	/// <param name="pos2">2つ目の円のポジション</param>
	/// <param name="radius2">2つ目の円の半径</param>
	/// <returns>当たってるかどうか</returns>
	int isHit(Vector2 pos1, int radius1, Vector2 pos2, int radius2);
};

