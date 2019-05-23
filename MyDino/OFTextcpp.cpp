#include "MyFunction.h"
extern char UserName[50];
extern int tempscore;
extern int YourBestScore;

int FontSetting(int FontHeight, int FontWidth)//输入字体参数来设置字体样式
{
	LOGFONT FontSetting;
	gettextstyle(&FontSetting);//获取当前字体设置
	FontSetting.lfHeight = FontHeight;	//设置字体高度，0为自适应
	FontSetting.lfWidth = FontWidth;	//设置每个字体平均宽度，0为自适应
	_tcscpy_s(FontSetting.lfFaceName, _T("黑体"));//设置字体为“黑体”
	//FontSetting.lfQuality = PROOF_QUALITY;//设置输出效果为正稿质量
	FontSetting.lfQuality = ANTIALIASED_QUALITY;//设置输出效果为抗锯齿
	settextstyle(&FontSetting);//设置字体样式
	setbkmode(TRANSPARENT);//设置字体背景为透明
	return 0;
}
void TEXTPressContinue()//在程序中输入一段话‘按下任意键以继续’
{
	FontSetting(60,0);
	settextcolor(BLACK); //RGB(0, 0, 0)
	TCHAR PressContinue[] = _T("按下任意键以继续");
	outtextxy(230, 350, PressContinue);
}
void TEXTFlyDino()//在游戏过程中输出得分情况
{
	FontSetting(40, 0);
	settextcolor(BLACK); //RGB(0, 0, 0)
	char tempsave[50];
	_stprintf_s(tempsave, "%d", tempscore);
	TCHAR Score[] = _T("得分：");
	outtextxy(290, 8, Score);
	outtextxy(390, 8, tempsave);
}
void BLXNB()//在排行榜输出第一名的成绩
{
	FontSetting(30, 0);
	settextcolor(BLACK); //RGB(0, 0, 0)
	TCHAR First[] = _T("第一名：");
	TCHAR Firster[] = _T("BLX2233");
	TCHAR Last[] = _T("上次成绩：");
	TCHAR LastScore[] = _T("9999999");
	TCHAR Best[] = _T("最佳记录：");
	TCHAR BestScore[] = _T("9999999");
	outtextxy(500, 8, First);
	outtextxy(650, 8, Firster);
	outtextxy(500, 38, Last);
	outtextxy(650, 38, LastScore);
	outtextxy(500, 68, Best);
	outtextxy(650, 68, BestScore);
}
void YourScore()//在排行榜输出第二名的成绩
{
	FontSetting(30, 0);
	settextcolor(BLACK); //RGB(0, 0, 0)
	TCHAR Second[] = _T("第二名：");
	TCHAR Last[] = _T("上次成绩：");
	TCHAR Best[] = _T("最佳记录：");
	char tempsave[50];
	_stprintf_s(tempsave, "%d", tempscore);
	char tempbestsocre[50];
	_stprintf_s(tempbestsocre, "%d", YourBestScore);

	outtextxy(500, 108, Second);
	outtextxy(650, 108, UserName);
	outtextxy(500, 138, Last);
	outtextxy(650, 138, tempsave);
	outtextxy(500, 168, Best);
	outtextxy(650, 168, tempbestsocre);
}