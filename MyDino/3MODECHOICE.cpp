#include "MyFunction.h"
extern int mode;
extern int v_y;
extern int start_y;
extern IMAGE img_2start;

int MODECHOICE(int temp)
{
	switch (temp)
	{
		case 1:
			STARTGAME();
			break;
		case 2:
			LOADGAME();
			break;
		case 3:
			RANK();
			break;
		case 4:
			DONATE();
			break;
	}
	RUNNING_UP(start_y, img_2start, v_y);
	STARTUPmenu(mode);
	MODECHOICE(mode);
	return 0;
}