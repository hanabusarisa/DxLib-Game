#include"DxLib.h"//Dxライブラリーをインクルード

int WinMain(HINSTANCE, HINSTANCE, LPSTR, int)//Windowsのメインで動かす
{
//基本設計
    ChangeWindowMode(TRUE);
    DxLib_Init();//DxLibの初期化
    SetDrawScreen(DX_SCREEN_BACK);
    SetGraphMode(800,600,32);//画面の大きさ


//DxLibの初期化処理
if (DxLib_Init() == -1)
{
    //エラーが起きたら直ちに終了
    return -1;
}
//文字の位置
int stringX = 10;
int stringY = 15;
int stringX1 = 10;
int stringY1= 55;
//マウスの座標
int mouseX = 0;
int mouseY = 0;

//円の初期位置
    int circleX = 150;
    int circleY = 200;
    //円の色の指定
    int circleColor = GetColor(0,0,225);
    //文字の色指定
    int StringColor = GetColor(225, 225, 225);
    int StringColor2 = GetColor(225, 0, 0);
    //ゲームループ
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        //画面の初期化
        ClearDrawScreen();
        //文字の大きさを指定
        SetFontSize(32);
        //画面に文字を描画させる
        //DrawString(10, 15, "HelloWorld", StringColor);
        DrawFormatString(stringX, stringY, StringColor, "Mouse X:%d Y:%d", mouseX, mouseY);
        //画面に円を描画させる
        DrawCircle(circleX, circleY, 30, GetColor(0, 0, 255), TRUE);
        //マウスの座標を取得
        GetMousePoint(&mouseX, &mouseY);
        //マウスがクリックされたら
        if ((GetMouseInput() & MOUSE_INPUT_LEFT))
        {
            SetFontSize(30);
            DrawString(stringX1, stringY1, "Hit!", StringColor2);
        }
        if (CheckHitKey(KEY_INPUT_UP))
        {
            //円のY座標が４０より小さくなったら
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
        //円のX座標に動きをつける
        /*circleX += 2;
        circleY += 1;
        if (circleX >= 800)
        {
            circleX = 0;
            circleY = 0;
        }*/
        //裏画面の内容を表画面に反映させる
        ScreenFlip();
    }
        //画面に点を描画させる
//DrawCircle(320, 240, 30, GetColor(0, 0, 255), TRUE);
//画面に点を描画させて（X座標　y座標 点の色指定）
DrawPixel(320, 240, GetColor(255, 0, 0));
//キー入力待ち
WaitKey();
//DxLib使用の終了処理
DxLib_End();
//ソースの終了
return 0;
}


