#include "MyFunction.h"
extern char UserName[50];
extern int tempscore;
extern int YourBestScore;

int FontSetting(int FontHeight, int FontWidth)//�����������������������ʽ
{
	LOGFONT FontSetting;
	gettextstyle(&FontSetting);//��ȡ��ǰ��������
	FontSetting.lfHeight = FontHeight;	//��������߶ȣ�0Ϊ����Ӧ
	FontSetting.lfWidth = FontWidth;	//����ÿ������ƽ����ȣ�0Ϊ����Ӧ
	_tcscpy_s(FontSetting.lfFaceName, _T("����"));//��������Ϊ�����塱
	//FontSetting.lfQuality = PROOF_QUALITY;//�������Ч��Ϊ��������
	FontSetting.lfQuality = ANTIALIASED_QUALITY;//�������Ч��Ϊ�����
	settextstyle(&FontSetting);//����������ʽ
	setbkmode(TRANSPARENT);//�������屳��Ϊ͸��
	return 0;
}
void TEXTPressContinue()//�ڳ���������һ�λ�������������Լ�����
{
	FontSetting(60,0);
	settextcolor(BLACK); //RGB(0, 0, 0)
	TCHAR PressContinue[] = _T("����������Լ���");
	outtextxy(230, 350, PressContinue);
}
void TEXTFlyDino()//����Ϸ����������÷����
{
	FontSetting(40, 0);
	settextcolor(BLACK); //RGB(0, 0, 0)
	char tempsave[50];
	_stprintf_s(tempsave, "%d", tempscore);
	TCHAR Score[] = _T("�÷֣�");
	outtextxy(290, 8, Score);
	outtextxy(390, 8, tempsave);
}
void BLXNB()//�����а������һ���ĳɼ�
{
	FontSetting(30, 0);
	settextcolor(BLACK); //RGB(0, 0, 0)
	TCHAR First[] = _T("��һ����");
	TCHAR Firster[] = _T("BLX2233");
	TCHAR Last[] = _T("�ϴγɼ���");
	TCHAR LastScore[] = _T("9999999");
	TCHAR Best[] = _T("��Ѽ�¼��");
	TCHAR BestScore[] = _T("9999999");
	outtextxy(500, 8, First);
	outtextxy(650, 8, Firster);
	outtextxy(500, 38, Last);
	outtextxy(650, 38, LastScore);
	outtextxy(500, 68, Best);
	outtextxy(650, 68, BestScore);
}
void YourScore()//�����а�����ڶ����ĳɼ�
{
	FontSetting(30, 0);
	settextcolor(BLACK); //RGB(0, 0, 0)
	TCHAR Second[] = _T("�ڶ�����");
	TCHAR Last[] = _T("�ϴγɼ���");
	TCHAR Best[] = _T("��Ѽ�¼��");
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