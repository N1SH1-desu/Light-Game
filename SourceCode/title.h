#pragma once

//******************************************************************************
//
//
//      タイトルシーン
//
//
//******************************************************************************

//==============================================================================
//
//      Titleクラス
//
//==============================================================================

class Title : public Scene
{
public:
    static Title* instance() { return &instance_; }

	void update();
	void draw();

private:
    static Title instance_;
};

//******************************************************************************
