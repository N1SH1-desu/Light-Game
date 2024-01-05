#include "all.h"

using namespace GameLib;
int player_state;

void PLAYER::player_init()
{
	player_state = 0;

}

void PLAYER::player_deinit()
{
	safe_delete(sprPlayer);
}

void PLAYER::player_update()
{
	switch (player_state)
	{
	case 0:
		sprPlayer = sprite_load(L"./Data/Images/");
		player_state++;
		break;
	case 1:
		position.x = SCREEN_W * 0.5f;
		position.y = PLAYER_STATE_POS_Y;
		texPos = { 0,0 };
		texSize = { 256,256 };
		pivot = { 256,128 };
		angle = 0;
		hp = PLAYER_HP;

		player_state++;
		break;
	case 2:
		PLAYER::playermove();
		break;
	}
}

void PLAYER::player_render()
{
	sprite_render(sprPlayer,
		position.x, position.y,
		1, 1,
		texPos.x, texPos.y,
		texSize.x, texSize.y,
		pivot.x, pivot.y,
		angle
	);

}

void PLAYER::playermove()
{
	using namespace input;
	if (STATE(0) & PAD_LEFT)
	{
		position.x -= PLAYER_SPEED;
		if (0 <= position.x)
		{
			position.x = 0;
		}
	}
	if (STATE(0) & PAD_RIGHT)
	{
		position.x += PLAYER_SPEED;
		if (position.x >= SCREEN_W)
		{
			position.x = SCREEN_W;
		}
	}
	if (STATE(0) & PAD_UP)
	{
		angle += static_cast<float>(ROTATE);
	}
	if (STATE(0) & PAD_DOWN)
	{
		angle -= static_cast<float>(ROTATE);
	}
}