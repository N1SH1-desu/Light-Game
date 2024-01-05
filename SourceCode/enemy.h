#pragma once
#include "all.h"

class ENEMY
{
private:
    GameLib::Sprite* sprEnemy;
    VECTOR2 position;
    VECTOR2 texPos;
    VECTOR2 texSize;
    VECTOR2 pivot;
    int hp;
public:
    void enemy_init();
    void enemy_deinit();
    void enemy_update();
    void enemy_render();
};

enum EnemyMotion
{

};