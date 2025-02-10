#include "Hit.h"
#include <corecrt_math.h>

int Hit::isHit(Vector2 pos1, int radius1, Vector2 pos2, int radius2) {
	if (sqrtf(powf(pos1.x - pos2.x, 2) + powf(pos1.y - pos2.y, 2)) <= radius1 + radius2) {
		return true;
	} else {
		return false;
	}
}
