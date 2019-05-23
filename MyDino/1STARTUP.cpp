#include "MyFunction.h"

int start_y = 800;
int v_y = 8;

extern IMAGE img_1warning;
extern IMAGE img_1continue;
extern IMAGE img_1continue_bg;
extern IMAGE img_2start;


void STARTUP()
{
	initgraph(960, 480);//新建960*480的画布	
	setbkcolor(WHITE);//设置背景色为白色
	cleardevice();//用背景色填充画布

	// 获取窗口MyDino的句柄
	HWND MyDino = GetHWnd();

	// 设置窗口MyDino标题文字
	SetWindowText(MyDino, "MyDino---Dino版FlyBird，希望你喜欢QAQ");

	//获取当前系统屏幕的宽度与高度
	int ScreenWidth = GetSystemMetrics(SM_CXSCREEN); 
	int ScreenHeight = GetSystemMetrics(SM_CYSCREEN);

	//设置窗口MyDino属性：置于所有窗口上面，
	//修改位置为 [(ScreenWidth-960)/2, (ScreenHeight-600)/2]，即屏幕中间，
	//修改大小为（0,0），
	//SWP_NOSIZE为修改大小不生效
	SetWindowPos(MyDino, HWND_TOP, (ScreenWidth -960)/2, (ScreenHeight -600)/2, 0, 0, SWP_NOSIZE);

	while (!_kbhit())
	{
		putimage(0, 0, &img_1warning);//插入图片1提示页面
		Sleep(480);

		TEXTPressContinue();//显示文字：按下任意键以继续，初始效果是用下面的两行代码插图显示的，可将本行代码注释并取消下两行代码注释查看
		//putimage(214, 350, &img_1continue_bg, SRCAND);//插入图片1提示页面
		//putimage(214, 350, &img_1continue, SRCPAINT);//插入图片1提示页面

		Sleep(500);
	}
	YourName();
	cleardevice();//用背景色填充画布，即覆盖/清空画布内容
	RUNNING_UP(start_y, img_2start, v_y);
}