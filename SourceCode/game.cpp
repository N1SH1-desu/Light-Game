//******************************************************************************
//
//
//      �Q�[��
//
//
//******************************************************************************

//------< �C���N���[�h >---------------------------------------------------------
#include "all.h"

//------< using >---------------------------------------------------------------
using namespace GameLib;

//------< �ϐ� >----------------------------------------------------------------
Game Game::instance_;

Game::Game() :
    isPaused(false)
{
}

//--------------------------------
//  ����������
//--------------------------------
void Game::init()
{
    Scene::init();	    // ���N���X��init���Ă�

    isPaused = false;   // �|�[�Y�t���O�̏�����
}

//--------------------------------
//  �I������
//--------------------------------
void Game::deinit()
{
    // �e�N�X�`���̉��
    texture::releaseAll();

    // ���y�̃N���A
    music::clear();
}

//--------------------------------
//  �X�V����
//--------------------------------
void Game::update()
{
    using namespace input;

    // �\�t�g���Z�b�g
    if ((STATE(0) & PAD_SELECT) &&  // 0�R���̃Z���N�g�{�^����������Ă����Ԃ�
        (TRG(0) & PAD_START))       // 0�R���̃X�^�[�g�{�^���������ꂽ�u��
    {
        changeScene(Title::instance());   // �^�C�g���V�[���ɐ؂�ւ���
        return;
    }

    // �f�o�b�O������\��
    debug::setString("state:%d", state);
    debug::setString("timer:%d", timer);

    // �|�[�Y����
    if (input::TRG(0) & PAD_START)
        isPaused = !isPaused;       // 0�R���̃X�^�[�g�{�^���������ꂽ��|�[�Y��Ԃ����]
    if (isPaused) return;           // ���̎��_�Ń|�[�Y���Ȃ烊�^�[��

    switch (state)
    {
    case 0:
        //////// �����ݒ� ////////

        timer = 0;
        GameLib::setBlendMode(Blender::BS_ALPHA);   // �ʏ�̃A���t�@����
        
        state++;    // �����������̏I��

        /*fallthrough*/     // case 1:�̏����������ɍs���K�v�����邽�߁A�킴��break;���L�q���Ă��Ȃ�

    case 1:
        //////// �ʏ펞�̏��� ////////

        timer++;

        debug::setString("");
        debug::setString("Left Up Right Down");
        debug::setString("Z:Horizontal");
        debug::setString("X:Vertical");

        break;
    }
}

//--------------------------------
//  �`�揈��
//--------------------------------
void Game::draw()
{
    // ��ʃN���A
    GameLib::clear(VECTOR4(0, 0, 0, 1));

    // �X�e���V�����[�h�F�ʏ�
    DepthStencil::instance().set(DepthStencil::MODE::NONE);

}

//******************************************************************************
