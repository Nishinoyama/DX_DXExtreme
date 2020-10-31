#include "DxLib.h"
#include <complex>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800

using Comp = std::complex<double>;

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);	// �E�B���h�E���[�h�ŊJ��

	SetGraphMode(WINDOW_WIDTH, WINDOW_HEIGHT, 16, 60);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
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

	WaitKey();				// �L�[���͑҂�

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}