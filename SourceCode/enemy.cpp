#include "all.h"
int enemy_state;
using namespace GameLib;
void ENEMY::enemy_init()
{
	enemy_state = 0;
}

void ENEMY::enemy_deinit()
{
	safe_delete(sprEnemy);
}

void ENEMY::enemy_update()
{
	switch (enemy_state)
	{
	case 0:
		sprEnemy = sprite_load(L"./data/Images/");
		enemy_state++;
		break;
	case 1:
		position.x = SCREEN_W * 0.5f;
		position.y = ENEMY_POS;
		texPos = { 0,0 };
		texSize = { 256,256 };
		pivot = { 256,128 };
	}
}

void ENEMY::enemy_render()
{
	sprite_render(sprEnemy,
		position.x, position.y,
		1, 1,
		texPos.x, texPos.y,
		texSize.x, texSize.y,
		pivot.x, pivot.y);
}
