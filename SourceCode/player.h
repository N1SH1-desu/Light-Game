#pragma once
#include "all.h"

class PLAYER
{
private:
    GameLib::Sprite* sprPlayer;
    VECTOR2 position;
    VECTOR2 texPos;
    VECTOR2 texSize;
    VECTOR2 pivot;
    float angle;
    int hp;
public:
    void player_init();
    void player_deinit();
    void player_update();
    void player_render();

    void playermove();
};