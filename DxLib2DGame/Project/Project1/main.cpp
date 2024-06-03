#include"DxLib.h"//Dx���C�u�����[���C���N���[�h

int WinMain(HINSTANCE, HINSTANCE, LPSTR, int)//Windows�̃��C���œ�����
{
//��{�݌v
    ChangeWindowMode(TRUE);
    DxLib_Init();//DxLib�̏�����
    SetDrawScreen(DX_SCREEN_BACK);
    SetGraphMode(800,600,32);//��ʂ̑傫��


//DxLib�̏���������
if (DxLib_Init() == -1)
{
    //�G���[���N�����璼���ɏI��
    return -1;
}
//�����̈ʒu
int stringX = 10;
int stringY = 15;
int stringX1 = 10;
int stringY1= 55;
//�}�E�X�̍��W
int mouseX = 0;
int mouseY = 0;

//�~�̏����ʒu
    int circleX = 150;
    int circleY = 200;
    //�~�̐F�̎w��
    int circleColor = GetColor(0,0,225);
    //�����̐F�w��
    int StringColor = GetColor(225, 225, 225);
    int StringColor2 = GetColor(225, 0, 0);
    //�Q�[�����[�v
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        //��ʂ̏�����
        ClearDrawScreen();
        //�����̑傫�����w��
        SetFontSize(32);
        //��ʂɕ�����`�悳����
        //DrawString(10, 15, "HelloWorld", StringColor);
        DrawFormatString(stringX, stringY, StringColor, "Mouse X:%d Y:%d", mouseX, mouseY);
        //��ʂɉ~��`�悳����
        DrawCircle(circleX, circleY, 30, GetColor(0, 0, 255), TRUE);
        //�}�E�X�̍��W���擾
        GetMousePoint(&mouseX, &mouseY);
        //�}�E�X���N���b�N���ꂽ��
        if ((GetMouseInput() & MOUSE_INPUT_LEFT))
        {
            SetFontSize(30);
            DrawString(stringX1, stringY1, "Hit!", StringColor2);
        }
        if (CheckHitKey(KEY_INPUT_UP))
        {
            //�~��Y���W���S�O��菬�����Ȃ�����
            if (circleY >= 40)
            {
                circleY -= 3;
            }
            else
            {
                circleY += 3;
            }
        }
        if (CheckHitKey(KEY_INPUT_DOWN))
        {
            if (circleY >= 560)
            {
                circleY -= 3;
            }
            else
            {
                circleY += 3;
            }
        }
        if (CheckHitKey(KEY_INPUT_LEFT))
        {

            if (circleX >= 40)
            {
                circleX -= 3;
            }
            else
            {
                circleX += 3;
            }
        }
        if (CheckHitKey(KEY_INPUT_RIGHT))
        {
            if (circleX >= 760)
            {
                circleX -= 3;
            }
            else
            {
                circleX += 3;
            }
        }
        //�~��X���W�ɓ���������
        /*circleX += 2;
        circleY += 1;
        if (circleX >= 800)
        {
            circleX = 0;
            circleY = 0;
        }*/
        //����ʂ̓��e��\��ʂɔ��f������
        ScreenFlip();
    }
        //��ʂɓ_��`�悳����
//DrawCircle(320, 240, 30, GetColor(0, 0, 255), TRUE);
//��ʂɓ_��`�悳���āiX���W�@y���W �_�̐F�w��j
DrawPixel(320, 240, GetColor(255, 0, 0));
//�L�[���͑҂�
WaitKey();
//DxLib�g�p�̏I������
DxLib_End();
//�\�[�X�̏I��
return 0;
}


