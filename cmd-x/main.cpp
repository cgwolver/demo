#include "cmd.h"
#include <QCoreApplication>

extern "C"
{
	int
		_CRTAPI1
#ifndef _CMD_X
		main(int argc, char **argv);
#else
		cmd_main(int argc, char **argv);
#endif
}


int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
	return cmd_main(argc, argv);
    //return a.exec();
}

