#pragma once

//******************************************************************************
//
//
//      common
//
//
//******************************************************************************

//------< �C���N���[�h >---------------------------------------------------------
#include <DirectXMath.h>

//------< �֐� >----------------------------------------------------------------

static float(* const ToRadian)(float) = DirectX::XMConvertToRadians;  // �p�x�����W�A����
static float(* const ToDegree)(float) = DirectX::XMConvertToDegrees;  // ���W�A�����p�x��


static constexpr float SCREEN_H = 1100.0f;
static constexpr float SCREEN_W = 1100.0f;
static constexpr int PLAYER_HP = 5;
static constexpr float PLAYER_STATE_POS_Y = 900.0f;
static constexpr float PLAYER_SPEED = 8.0f;
static constexpr float ENEMY_POS = 100.0f;
static constexpr float ROTATE = 0.1f;