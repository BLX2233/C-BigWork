#include "MyFunction.h"
extern char UserName[50];
extern int tempscore;
extern int YourBestScore;

void LoadGame()//获取存档中用户名、上一次得分和最佳纪录的数据，同时判断存档是否存在
{
	FILE* fp;
	fp=fopen(".\\GameSave.dat", "r");
	if (fp)//判断存档存在才写入数据
	{
		fscanf(fp, "%s %d %d", &UserName, &tempscore, &YourBestScore);
		fclose(fp);
	}
}
void SaveGame()//写入存档中用户名、上一次得分和最佳纪录的数据
{
	FILE *fp;
	fopen_s(&fp,".\\GameSave.dat", "w");
	fprintf(fp, "%s %d %d", UserName, tempscore, YourBestScore);
	fclose(fp);
}