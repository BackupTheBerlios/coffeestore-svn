#include <UnitTest++.h>
#include <TestReporterStdout.h>

int main(int, char const *[])
{
    int res = UnitTest::RunAllTests();
	system("pause");
	return res;
}
