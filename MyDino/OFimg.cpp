#include<graphics.h>
IMAGE img_1warning;
IMAGE img_1continue;
IMAGE img_1continue_bg;
IMAGE img_2start;
IMAGE img_3menu;
IMAGE img_3select_panel;
IMAGE img_4donate;
IMAGE img_4donate_pi;
IMAGE img_4rank;

IMAGE img_FlyDino;
IMAGE img_FlyDino1;
IMAGE img_FlyDino1_bk;

IMAGE img_FlyDino2;
IMAGE img_FlyDino2_bk;
IMAGE img_FlyDino_run;
IMAGE img_FlyDino_bk;
IMAGE img_Dino;
IMAGE img_Dino_bk;
IMAGE img_pipe_up;
IMAGE img_pipe_down;
IMAGE img_pipe2_up;
IMAGE img_pipe2_down;
IMAGE img_pipe_up_bk;
IMAGE img_pipe_down_bk;
IMAGE img_LAND;
IMAGE img_GameOver;
void LOADIMG()
{
	loadimage(&img_1warning, _T(".\\Resources\\1warning.png"));
	loadimage(&img_1continue, _T(".\\Resources\\1continue.png"));
	loadimage(&img_1continue_bg, _T(".\\Resources\\1continue_bg.png"));
	loadimage(&img_2start, _T(".\\Resources\\2start.png"));
	loadimage(&img_3menu, _T(".\\Resources\\3menu.png"));
	loadimage(&img_3select_panel, _T(".\\Resources\\3select_panel.png"));
	loadimage(&img_4donate, _T(".\\Resources\\4donate.png"));
	loadimage(&img_4donate_pi, _T(".\\Resources\\4donate_pi.png"));
	loadimage(&img_4rank, _T(".\\Resources\\4rank.png"));

	loadimage(&img_FlyDino, _T(".\\Resources\\FlyDino.png"));
	loadimage(&img_FlyDino_run, _T(".\\Resources\\FlyDino_run.png"));
	loadimage(&img_FlyDino1_bk, _T(".\\Resources\\FlyDino_bk.bmp"));
	loadimage(&img_FlyDino1, _T(".\\Resources\\FlyDino.bmp"));
	loadimage(&img_FlyDino2_bk, _T(".\\Resources\\FlyDino2_bk.bmp"));
	loadimage(&img_FlyDino2, _T(".\\Resources\\FlyDino2.bmp"));
	loadimage(&img_Dino, _T(".\\Resources\\Dino.png"));
	loadimage(&img_Dino_bk, _T(".\\Resources\\Dino_bk.png"));
	loadimage(&img_pipe_up, _T(".\\Resources\\pipe_up.png"));
	loadimage(&img_pipe_down, _T(".\\Resources\\pipe_down.png"));
	loadimage(&img_pipe2_up, _T(".\\Resources\\pipe2_up.png"));
	loadimage(&img_pipe2_down, _T(".\\Resources\\pipe2_down.png"));
	loadimage(&img_pipe_up_bk, _T(".\\Resources\\pipe_up_bk.png"));
	loadimage(&img_pipe_down_bk, _T(".\\Resources\\pipe_down_bk.png"));
	loadimage(&img_LAND, _T(".\\Resources\\land.png"));
	loadimage(&img_GameOver, _T(".\\Resources\\GameOver.png"));	
}

void RUNNING_UP(int y, IMAGE yimg, int vy)
{
	while (y >= 0)//调用Sleep函数实现画面的滚动
	{
		putimage(0, y, &yimg);
		Sleep(20);
		y -= vy;
	}
	Sleep(50);
}

int Dino(int x, int y)
{
	putimage(x, y, &img_Dino_bk, SRCAND);
	putimage(x, y, &img_Dino, SRCPAINT);
	return 0;
}
int FlyDino(int x, int y,int z)
{
	if (z == 1)
	{
		putimage(x, y, &img_FlyDino1_bk, SRCAND);
		putimage(x, y, &img_FlyDino1, SRCPAINT);
	}
	else
	{
		putimage(x, y, &img_FlyDino2_bk, SRCAND);
		putimage(x, y, &img_FlyDino2, SRCPAINT);
	}
	FlushBatchDraw();
	return 0;
}

int Pipe_up(int x, int y)
{
	putimage(x, y, &img_pipe_up_bk, SRCAND);
	putimage(x, y, &img_pipe_up, SRCPAINT);
	return 0;
}
int Pipe2_up(int x, int y)
{
	putimage(x, y, &img_pipe_up_bk, SRCAND);
	putimage(x, y, &img_pipe2_up, SRCPAINT);
	return 0;
}
int Pipe_down(int x, int y)
{
	putimage(x, y, &img_pipe_down_bk, SRCAND);
	putimage(x, y, &img_pipe_down, SRCPAINT);
	return 0;
}
int Pipe2_down(int x, int y)
{
	putimage(x, y, &img_pipe_down_bk, SRCAND);
	putimage(x, y, &img_pipe2_down, SRCPAINT);
	return 0;
}
int LAND(int x, int y)
{
	putimage(x, y, &img_LAND);
	return 0;
}