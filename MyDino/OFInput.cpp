#include "MyFunction.h"
char UserName[50] = {0};

void YourName()//�û������û����ĶԻ���
{
	char temp[50];
	InputBox(temp, 50, "������������֣�\n(�����Ҫ��ȡ֮ǰ�Ĵ浵��������������д)","���ڽ������ʶ��..........");
	strcpy_s(UserName,temp);
}
void QuickCopy()//�û����ٸ��ƵĶԻ���
{
	char temp[50];
	InputBox(temp, 50, "����������е����Ҽ�ѡ��ȫѡ����", "���ٸ���","https://github.com/BLX2233");
}