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
	// ���ÿ���̨ API�����֮ǰ�������ڵ����а�����
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));//��ֹ��Ϸ��ʼ���水��������Կ�ʼʱ���¿ո����ѡ��ʼ��Ϸ
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