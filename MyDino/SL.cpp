#include "MyFunction.h"
extern char UserName[50];
extern int tempscore;
extern int YourBestScore;

void LoadGame()//��ȡ�浵���û�������һ�ε÷ֺ���Ѽ�¼�����ݣ�ͬʱ�жϴ浵�Ƿ����
{
	FILE* fp;
	fp=fopen(".\\GameSave.dat", "r");
	if (fp)//�жϴ浵���ڲ�д������
	{
		fscanf(fp, "%s %d %d", &UserName, &tempscore, &YourBestScore);
		fclose(fp);
	}
}
void SaveGame()//д��浵���û�������һ�ε÷ֺ���Ѽ�¼������
{
	FILE *fp;
	fopen_s(&fp,".\\GameSave.dat", "w");
	fprintf(fp, "%s %d %d", UserName, tempscore, YourBestScore);
	fclose(fp);
}