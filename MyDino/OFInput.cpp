#include "MyFunction.h"
char UserName[50] = {0};

void YourName()//用户输入用户名的对话框
{
	char temp[50];
	InputBox(temp, 50, "请输入你的名字：\n(如果想要读取之前的存档，此项请随意填写)","正在进行身份识别..........");
	strcpy_s(UserName,temp);
}
void QuickCopy()//用户快速复制的对话框
{
	char temp[50];
	InputBox(temp, 50, "请在输入框中单击右键选择全选复制", "快速复制","https://github.com/BLX2233");
}