#pragma once
#include "Object.h"
class Hit {
public:
	/// <summary>
	/// �����蔻��̊֐�
	/// </summary>
	/// <param name="pos1">1�ڂ̉~�̍��W</param>
	/// <param name="radius1">1�ڂ̉~�̔��a</param>
	/// <param name="pos2">2�ڂ̉~�̃|�W�V����</param>
	/// <param name="radius2">2�ڂ̉~�̔��a</param>
	/// <returns>�������Ă邩�ǂ���</returns>
	int isHit(Vector2 pos1, int radius1, Vector2 pos2, int radius2);
};

