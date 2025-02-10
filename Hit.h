#pragma once
#include "Object.h"
class Hit {
public:
	/// <summary>
	/// “–‚½‚è”»’è‚ÌŠÖ”
	/// </summary>
	/// <param name="pos1">1‚Â–Ú‚Ì‰~‚ÌÀ•W</param>
	/// <param name="radius1">1‚Â–Ú‚Ì‰~‚Ì”¼Œa</param>
	/// <param name="pos2">2‚Â–Ú‚Ì‰~‚Ìƒ|ƒWƒVƒ‡ƒ“</param>
	/// <param name="radius2">2‚Â–Ú‚Ì‰~‚Ì”¼Œa</param>
	/// <returns>“–‚½‚Á‚Ä‚é‚©‚Ç‚¤‚©</returns>
	int isHit(Vector2 pos1, int radius1, Vector2 pos2, int radius2);
};

