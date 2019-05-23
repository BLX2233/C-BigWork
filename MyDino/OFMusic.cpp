#include "MyFunction.h"
//≤•∑≈“Ù¿÷
void PLAYMUSICStart()
{
	mciSendString(_T("open ./Resources/Start.wav alias Start"), NULL, 0, NULL);
	mciSendString(_T("play Start"), NULL, 0, NULL);
}
void PLAYMUSICBin()
{
	mciSendString(_T("close Bin"), NULL, 0, NULL);
	mciSendString(_T("open ./Resources/Bin.wav alias Bin"), NULL, 0, NULL);
	mciSendString(_T("play Bin"), NULL, 0, NULL);
}
void PLAYMUSICBiu()
{
	mciSendString(_T("close all"), NULL, 0, NULL);
	mciSendString(_T("open ./Resources/Biu.wav alias Biu"), NULL, 0, NULL);
	mciSendString(_T("play Biu"), NULL, 0, NULL);
}
void PLAYMUSICXukun()
{
	mciSendString(_T("close all"), NULL, 0, NULL);
	mciSendString(_T("open ./Resources/Chick-You-are-Too-Beautiful.mp3 alias Xukun"), NULL, 0, NULL);
	mciSendString(_T("play Xukun repeat"), NULL, 0, NULL);
}
void PLAYMUSICBGM()
{
	mciSendString(_T("close BGM"), NULL, 0, NULL);
	mciSendString(_T("open ./Resources/BGM.mp3 alias BGM"), NULL, 0, NULL);
	mciSendString(_T("play BGM repeat"), NULL, 0, NULL);
}