#include "vcdpmain.h"
#include <QtWidgets/QApplication>
#include <QTextCodec>
#ifdef _DEBUG
#pragma comment(lib,"../lib/Debug/KSYSClient.lib")
#pragma comment(lib,"../lib/Debug/IDXCore.lib")
#pragma comment(lib,"../lib/Debug/NETEC.lib")
#pragma comment(lib,"../lib/Debug/AUDEC.lib")
#pragma comment(lib,"../lib/Debug/VIDEC.lib")
#else
#pragma comment(lib,"../lib/Release/KSYSClient.lib")
#pragma comment(lib,"../lib/Release/IDXCore.lib")
#pragma comment(lib,"../lib/Release/NETEC.lib")
#pragma comment(lib,"../lib/Release/AUDEC.lib")
#pragma comment(lib,"../lib/Release/VIDEC.lib")
#endif
vcdpMain* w;
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("gbk"));
	//Æô¶¯ÍøÂç
	NETEC_Core::Start(0, false, false, true);

	AUDEC_Engine::AUDEC_Init(0);
	VIDEC_Init();
	w = new vcdpMain();
	//w->show();
	return a.exec();
}
