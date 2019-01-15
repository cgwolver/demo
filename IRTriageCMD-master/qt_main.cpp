//#include <QCoreApplication>
#include <TCHAR.H>
#include <QString>



extern "C" { int cmd_main (int argc, const TCHAR *argv[]);}
int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
#ifdef _UNICODE
    const wchar_t** argvw = new const wchar_t*[argc];
    for(int i = 0;i<argc;i++)
    {
        QString qs(argv[i]);
        int n = qs.length();
        wchar_t* ws = new wchar_t[n+1];
        qs.toWCharArray(ws);
        argvw[i] = ws;
    }
    cmd_main(argc,argvw);
    for(int i = 0;i<argc;i++)
    {
        delete[] argvw[i];
    }
    delete[] argvw;
#else
    cmd_main(argc,argv);
#endif
    return 0;//a.exec();
}
