#include "DxLib.h"
#include <complex>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800

using Comp = std::complex<double>;

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);	// ウィンドウモードで開く

	SetGraphMode(WINDOW_WIDTH, WINDOW_HEIGHT, 16, 60);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	for (int i = 0; i < WINDOW_WIDTH; i++)
	{
		for (int j = 0; j < WINDOW_HEIGHT; j++)
		{
			Comp c = Comp(-2.1 + 2.6*i/WINDOW_WIDTH, -1.3 + 2.6*j/WINDOW_HEIGHT);
			Comp t = Comp(0, 0);
			int cnt = 0;
			for (; cnt < 128 && std::abs(t) <= 2.0; cnt++)
			{
				t = t * t + c;
			}
			DrawPixel(i, j, GetColor(256-cnt*2, 256-cnt*2, 256-cnt*2));
		}
	}

	WaitKey();				// キー入力待ち

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}