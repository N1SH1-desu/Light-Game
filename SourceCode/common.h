#pragma once

//******************************************************************************
//
//
//      common
//
//
//******************************************************************************

//------< インクルード >---------------------------------------------------------
#include <DirectXMath.h>

//------< 関数 >----------------------------------------------------------------

static float(* const ToRadian)(float) = DirectX::XMConvertToRadians;  // 角度をラジアンに
static float(* const ToDegree)(float) = DirectX::XMConvertToDegrees;  // ラジアンを角度に


static constexpr float SCREEN_H = 1100.0f;
static constexpr float SCREEN_W = 1100.0f;
static constexpr int PLAYER_HP = 5;
static constexpr float PLAYER_STATE_POS_Y = 900.0f;
static constexpr float PLAYER_SPEED = 8.0f;
static constexpr float ENEMY_POS = 100.0f;
static constexpr float ROTATE = 0.1f;