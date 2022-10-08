#include "x2tTester.h"

#ifdef LINUX
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#endif

#ifdef WIN32
int wmain(int argc, wchar_t** argv)
#else
int main(int argc, char** argv)
#endif
{
#ifdef _WIN32
	UINT currConsoleCP = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
#endif

	std::wstring config_path;

	if(argc < 2) config_path = L"./config.xml";
	else config_path = std::wstring(argv[1]);

	SetConsoleOutputCP(CP_UTF8);

	Cx2tTester tester(config_path);
	tester.Start();

#ifdef _WIN32
	SetConsoleOutputCP(currConsoleCP);
#endif

	return 0;
}
