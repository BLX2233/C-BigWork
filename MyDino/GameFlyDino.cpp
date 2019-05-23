#include "MyFunction.h"
int tempscore = 0;
int pipe_x = 288, pipe_y = -(rand() % 200 + 100), land_x = 0, land_y = 394;
int pipespace = 125;
int dino_x = 100, dino_y = 240;
int width = 288, high = 480;
int FlyDinoMode = 1;
int FlyDinoOver = 0;
char input;
extern int mode;
extern IMAGE img_FlyDino;
extern IMAGE img_FlyDino_run; 
extern IMAGE img_FlyDino_bk;
extern IMAGE img_2start;
extern int v_y;
extern int start_y;
extern IMAGE img_GameOver;
extern int YourBestScore;

void FlyDinoIMG()
{
	putimage(0, 0, &img_FlyDino);
	Pipe();
	FlyDino(dino_x, dino_y, FlyDinoMode);
	TEXTFlyDino();
	FlushBatchDraw();
	FlyDinoMode *= (-1);
}

void Pipe()
{
	Sleep(20 );
	if (pipe_x == -52)
	{
		pipe_x = 288;
		pipe_y= -(rand() % 200 + 100);
		Pipe_up(pipe_x, pipe_y + 320 + pipespace);
		Pipe_down(pipe_x, pipe_y);
		pipe_x--;
	}
	else if (pipe_x > -52)
	{
		Pipe_up(pipe_x, pipe_y + 320 + pipespace);
		Pipe_down(pipe_x, pipe_y);
		pipe_x--;
	}
	if (land_x == -288)
		land_x = 0;
	LAND(land_x, land_y);
	LAND(land_x + 288, land_y);
	LAND(land_x + 288*2, land_y);
	LAND(land_x + 288*3, land_y);
	land_x--;
	putimage(0, 0, &img_FlyDino_bk, SRCAND);
	putimage(0, 0, &img_FlyDino_run, SRCPAINT);
}
void ControlFlyDino()
{
	if (_kbhit())
	{
		input = _getch();
		if (input == ' ' && dino_y >= 10)
		{
			dino_y -= 15;
		}
		else if (input == 27)
			while (1)
			{
				input = 0;
				Sleep(10);
				input = _getch();
				if (input == 27)
					break;
			}
		else if (input == 's')
			SaveGame();
	}
	else if(!_kbhit()&&dino_y<=339)
	{
		dino_y += 1;
	}
}

void Judgement()
{
	if (dino_x == pipe_x + 52)
	{
		tempscore++;
		if (YourBestScore < tempscore)
			YourBestScore = tempscore;
	}
	else if (pipe_x <= dino_x + 55-8 && pipe_x >= dino_x)
	{
		if (pipe_y + 320 >= dino_y + 3 || pipe_y + 320 + pipespace <= dino_y + 57 - 3)
		{
			Pipe2_up(pipe_x, pipe_y + 320 + pipespace);
			Pipe2_down(pipe_x, pipe_y);
			FlyDinoEnd();
		}
	}
}
void FlyDinoEnd()
{
	EndBatchDraw();
	RUNNING_UP(start_y, img_GameOver, v_y);
	while (1)
	{
		Sleep(10);
		if (_kbhit())
		{
			input = _getch();
			if (input ==32)
			{
				FlyDino();
			}
			else if (input == 27)
			{
				FlyDinoOver = 1;
				break;
			}
		}
	}
}
void FlyDino()
{
	//游戏开始前先重置数据
	tempscore = 0;//上一次记录变为0
	pipe_x = 288, pipe_y = -(rand() % 200 + 100), land_x = 0, land_y = 394;//管道的位置
	dino_x = 100, dino_y = 240;//Dino的位置
	pipespace = 125;//上下管道之间的间隔
	FlyDinoOver = 0;//判断游戏是否结束，0为游戏仍在进行中
	BeginBatchDraw();// 开启批量绘图模式，尽可能地减少屏闪效果
	FlyDinoIMG();//贴上FlyDino游戏中的所有图片素材
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));//清空键盘缓存区
	while (!_kbhit())//进入游戏中时先暂停，按下任意键就开始游戏
	{
		TEXTPressContinue();//输出文字“按下任意键以继续”
		FlushBatchDraw();//批量输出贴上的图片素材
	}
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); //清空键盘缓存区
	PLAYMUSICBGM();//播放背景音乐
	while (FlyDinoOver == 0)//判断游戏是否结束，否则循环
	{
		FlyDinoIMG();//贴上FlyDino游戏中的所有图片素材
		ControlFlyDino();//检测键盘操作。调整图片素材贴的位置
		Judgement();//判断游戏是否结束与计算得分
	}
	mciSendString(_T("close BGM"), NULL, 0, NULL);//游戏结束，关闭音乐
}