#include "MyFunction.h"

int start_y = 800;
int v_y = 8;

extern IMAGE img_1warning;
extern IMAGE img_1continue;
extern IMAGE img_1continue_bg;
extern IMAGE img_2start;


void STARTUP()
{
	initgraph(960, 480);//�½�960*480�Ļ���	
	setbkcolor(WHITE);//���ñ���ɫΪ��ɫ
	cleardevice();//�ñ���ɫ��仭��

	// ��ȡ����MyDino�ľ��
	HWND MyDino = GetHWnd();

	// ���ô���MyDino��������
	SetWindowText(MyDino, "MyDino---Dino��FlyBird��ϣ����ϲ��QAQ");

	//��ȡ��ǰϵͳ��Ļ�Ŀ����߶�
	int ScreenWidth = GetSystemMetrics(SM_CXSCREEN); 
	int ScreenHeight = GetSystemMetrics(SM_CYSCREEN);

	//���ô���MyDino���ԣ��������д������棬
	//�޸�λ��Ϊ [(ScreenWidth-960)/2, (ScreenHeight-600)/2]������Ļ�м䣬
	//�޸Ĵ�СΪ��0,0����
	//SWP_NOSIZEΪ�޸Ĵ�С����Ч
	SetWindowPos(MyDino, HWND_TOP, (ScreenWidth -960)/2, (ScreenHeight -600)/2, 0, 0, SWP_NOSIZE);

	while (!_kbhit())
	{
		putimage(0, 0, &img_1warning);//����ͼƬ1��ʾҳ��
		Sleep(480);

		TEXTPressContinue();//��ʾ���֣�����������Լ�������ʼЧ��������������д����ͼ��ʾ�ģ��ɽ����д���ע�Ͳ�ȡ�������д���ע�Ͳ鿴
		//putimage(214, 350, &img_1continue_bg, SRCAND);//����ͼƬ1��ʾҳ��
		//putimage(214, 350, &img_1continue, SRCPAINT);//����ͼƬ1��ʾҳ��

		Sleep(500);
	}
	YourName();
	cleardevice();//�ñ���ɫ��仭����������/��ջ�������
	RUNNING_UP(start_y, img_2start, v_y);
}