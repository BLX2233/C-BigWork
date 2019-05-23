#include <stdio.h>//C语言标准输入输出函数
#include <windows.h> //引入Sleep()函数
#include <conio.h> //引入_kbhit()函数
#include <graphics.h> //引用easyx的库，需要配置好编译环境
#include <easyx.h> //引用easyx的库，需要配置好编译环境

#pragma comment(lib,"Winmm.lib")// 引用 Windows Multimedia API用来播放音乐
#pragma warning(disable : 4996)//禁用VS的4996警告来跳过fscanf()要转为fscanf_s()的警告来通过编译

void LOADIMG();//读取与图片素材有关的函数
void RUNNING_UP(int y, IMAGE yimg, int vy);//定义一个将图片从下面滚动到上面的效果函数，第一个值是开始滚动的y轴坐标，第二个值是要滚动的图片，第三个值是滚动的速度
void	STARTUP();//程序开始函数，新建easyx的画布、修改窗口的位置和标题
int STARTUPmenu(int temp);//选择菜单界面函数，内部的值是在菜单选择的模式
int MODECHOICE(int temp);//选择功能函数，通用switch()函数实现功能的选择，同时也重复引用RUNNING_UP()、STARTUP()和MODECHOICE()来实现菜单的循环启动

void STARTGAME();//功能1：开始游戏
void LOADGAME();//功能2：读取存档（此存档用来保存用户名、上一次得分和最佳纪录）
void RANK();//功能3：排行榜（给用户一个与我比较的机会，当然你的分数不可能比我高QAQ）
void DONATE();//功能4：作者链接（我的github地址QAQ）

void BLXNB();//用在功能3：排行榜中，输出我的上一次得分和最佳纪录
void YourScore();////用在功能3：排行榜中，输出用户的上一次得分和最佳纪录
void LoadGame();//用在功能2：读取存档，通过fscanf()读取用户的存档
void SaveGame();//用在功能1：开始游戏，在游戏过程中通过按下S键来调用fprintf()输出存档文件

void PLAYMUSICStart();//播放程序启动时的音乐
void PLAYMUSICBin();//播放选择功能时的音乐
void PLAYMUSICBiu();//播放确定功能时的音乐，即在菜单按下空格键时的音乐
void PLAYMUSICXukun();//播放作者链接的音乐
void PLAYMUSICBGM();//播放游戏过程中的音乐

int FontSetting(int FontHeight,  int FontWidth);//定义一个函数来快速设置easyx库中设置字体的函数
void TEXTPressContinue();//输出字体“按下任意键以继续”
void TEXTUserName();//输出用户名
void TEXTFlyDino();	//输出游戏的得分

void YourName();//获取用户名
void QuickCopy();//启动快速复制框，方便用户快速复制作者的github链接

void FlyDino();//游戏主体函数
void Pipe();//游戏中管道的移动
void FlyDinoEnd();//游戏中结束后的选择
int Dino(int x, int y);//在x，y位置贴上Dino的图片素材
int FlyDino(int x, int y, int z);//在x，y位置贴上背景的图片素材
int Pipe_up(int x, int y);//在x，y位置贴上管道的图片素材
int Pipe2_up(int x, int y);//在x，y位置贴上管道的图片素材
int Pipe_down(int x, int y);//在x，y位置贴上管道的图片素材
int Pipe2_down(int x, int y);//在x，y位置贴上管道的图片素材
int LAND(int x, int y);//在x，y位置贴上陆地的图片素材