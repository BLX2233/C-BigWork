#include <stdio.h>//C���Ա�׼�����������
#include <windows.h> //����Sleep()����
#include <conio.h> //����_kbhit()����
#include <graphics.h> //����easyx�Ŀ⣬��Ҫ���úñ��뻷��
#include <easyx.h> //����easyx�Ŀ⣬��Ҫ���úñ��뻷��

#pragma comment(lib,"Winmm.lib")// ���� Windows Multimedia API������������
#pragma warning(disable : 4996)//����VS��4996����������fscanf()ҪתΪfscanf_s()�ľ�����ͨ������

void LOADIMG();//��ȡ��ͼƬ�ز��йصĺ���
void RUNNING_UP(int y, IMAGE yimg, int vy);//����һ����ͼƬ����������������Ч����������һ��ֵ�ǿ�ʼ������y�����꣬�ڶ���ֵ��Ҫ������ͼƬ��������ֵ�ǹ������ٶ�
void	STARTUP();//����ʼ�������½�easyx�Ļ������޸Ĵ��ڵ�λ�úͱ���
int STARTUPmenu(int temp);//ѡ��˵����溯�����ڲ���ֵ���ڲ˵�ѡ���ģʽ
int MODECHOICE(int temp);//ѡ���ܺ�����ͨ��switch()����ʵ�ֹ��ܵ�ѡ��ͬʱҲ�ظ�����RUNNING_UP()��STARTUP()��MODECHOICE()��ʵ�ֲ˵���ѭ������

void STARTGAME();//����1����ʼ��Ϸ
void LOADGAME();//����2����ȡ�浵���˴浵���������û�������һ�ε÷ֺ���Ѽ�¼��
void RANK();//����3�����а񣨸��û�һ�����ұȽϵĻ��ᣬ��Ȼ��ķ��������ܱ��Ҹ�QAQ��
void DONATE();//����4���������ӣ��ҵ�github��ַQAQ��

void BLXNB();//���ڹ���3�����а��У�����ҵ���һ�ε÷ֺ���Ѽ�¼
void YourScore();////���ڹ���3�����а��У�����û�����һ�ε÷ֺ���Ѽ�¼
void LoadGame();//���ڹ���2����ȡ�浵��ͨ��fscanf()��ȡ�û��Ĵ浵
void SaveGame();//���ڹ���1����ʼ��Ϸ������Ϸ������ͨ������S��������fprintf()����浵�ļ�

void PLAYMUSICStart();//���ų�������ʱ������
void PLAYMUSICBin();//����ѡ����ʱ������
void PLAYMUSICBiu();//����ȷ������ʱ�����֣����ڲ˵����¿ո��ʱ������
void PLAYMUSICXukun();//�����������ӵ�����
void PLAYMUSICBGM();//������Ϸ�����е�����

int FontSetting(int FontHeight,  int FontWidth);//����һ����������������easyx������������ĺ���
void TEXTPressContinue();//������塰����������Լ�����
void TEXTUserName();//����û���
void TEXTFlyDino();	//�����Ϸ�ĵ÷�

void YourName();//��ȡ�û���
void QuickCopy();//�������ٸ��ƿ򣬷����û����ٸ������ߵ�github����

void FlyDino();//��Ϸ���庯��
void Pipe();//��Ϸ�йܵ����ƶ�
void FlyDinoEnd();//��Ϸ�н������ѡ��
int Dino(int x, int y);//��x��yλ������Dino��ͼƬ�ز�
int FlyDino(int x, int y, int z);//��x��yλ�����ϱ�����ͼƬ�ز�
int Pipe_up(int x, int y);//��x��yλ�����Ϲܵ���ͼƬ�ز�
int Pipe2_up(int x, int y);//��x��yλ�����Ϲܵ���ͼƬ�ز�
int Pipe_down(int x, int y);//��x��yλ�����Ϲܵ���ͼƬ�ز�
int Pipe2_down(int x, int y);//��x��yλ�����Ϲܵ���ͼƬ�ز�
int LAND(int x, int y);//��x��yλ������½�ص�ͼƬ�ز�