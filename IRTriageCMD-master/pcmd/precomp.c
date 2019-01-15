#include "precomp.h"
static char _buf[4096] = { 0 };
char* debugstr_w(wchar_t* wc)
{
	if (wc)
	{
		int len = WideCharToMultiByte(CP_ACP, 0, wc, wcslen(wc), NULL, 0, NULL, NULL);
		if (len < 4096)
		{
			WideCharToMultiByte(CP_ACP, 0, wc, wcslen(wc), _buf, len, NULL, NULL);
			_buf[len] = '\0';
			return _buf;
		}
	}
	return "(error)";
}