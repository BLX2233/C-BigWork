#include "MyFunction.h"

extern int mode;
extern IMAGE img_3menu;
extern IMAGE img_3select_panel;

void SelectPanel(int x)
{
	if(x==1)
		putimage(7, 79, &img_3select_panel);
	if(x==2)
		putimage(7, 183, &img_3select_panel);
	if(x==3)
		putimage(639, 79, &img_3select_panel);
	if (x==4)
		putimage(639, 183, &img_3select_panel);
}

int STARTUPmenu(int temp)
{
	// 调用控制台 API，清空之前缓冲区内的所有按键。
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));//防止游戏开始界面按下任意键以开始时按下空格键来选择开始游戏
	while (1)
	{
		if (_kbhit())
		{
			char tempinput=0;
			tempinput = _getch();
			if (tempinput == 32)
			{
				PLAYMUSICBiu();
				break;
			}
			if (tempinput == 72)
			{
				temp -= 1;
				PLAYMUSICBin();
			}
			if (tempinput == 80)
			{
				temp += 1;
				PLAYMUSICBin();
			}
		}
		else
		{		
			if (temp > 4)
			temp = 1;
			else if(temp < 1)
			temp = 4;

			putimage(0, 0, &img_3menu);
			Sleep(200);
			SelectPanel(temp);
			Sleep(200);
		}
	}
	putimage(0, 0, &img_3menu);
	mode = temp;
	return mode;
}