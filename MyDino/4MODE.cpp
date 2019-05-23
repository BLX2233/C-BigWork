#include "MyFunction.h"
extern int mode;
extern IMAGE img_2start;
extern IMAGE img_4rank;
extern IMAGE img_4donate;
extern IMAGE img_4donate_pi;
extern int v_y;
extern int start_y;

void STARTGAME(void)
{
	FlyDino();
}

void LOADGAME(void)
{
	LoadGame();
}

void RANK()
{
	RUNNING_UP(start_y, img_4rank, v_y);
	BLXNB();
	YourScore();
	while (1)
	{
		if (_kbhit())
		{
			char tempinput;
			tempinput = _getch();
			if (tempinput == 27)
			{
				PLAYMUSICBiu();
				break;
			}
		}
	}
}

void DONATE()
{
	char tempinput;
	RUNNING_UP(start_y, img_4donate, v_y);
	PLAYMUSICXukun();
	putimage(73, 172, &img_4donate_pi);
	while (1)
	{	
		tempinput = _getch();
		if (tempinput == 27)
		{
			PLAYMUSICBiu();
			break;
		}
		else if(tempinput==' ')
			QuickCopy();
	}
}