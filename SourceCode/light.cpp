#include "all.h"

using namespace GameLib;

light::light() :
	transform_{}
	, velocity_{}
{
}

light::~light()
{
}

void light::init()
{
	transform_ = { 700.0f, 200.0f };

	std::random_device rnd;  // �񌈒�I�ȗ��������@���쐬
	std::mt19937 mt(rnd());  //�@����I�ȗ��������@���쐬
	std::uniform_int_distribution<> x_rand(1, 5);  // [1, 5]�͈͂̈�l����
	float x_velo = static_cast<float>(x_rand(mt));  //�����x�����

	velocity_ = { x_velo, 1.0f };
}

void light::update()
{
	debug::setString("x_velo : %f", velocity_.x);
	debug::setString("x : %f", transform_.x);
	debug::setString("y : %f", transform_.y);
	transform_.x += velocity_.x;
	transform_.y += velocity_.y;
}

void light::render() const
{
	GameLib::primitive::rect(transform_, { 50, 50 }, { 25, 25 }, 0, { 0,0,1,1 });
}

bool light::isHit()
{
	return false;
}
