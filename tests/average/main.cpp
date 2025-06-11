/* Include cpp-u-test's headers. */
#include "CppUTest/CommandLineTestRunner.h"

int main(int ac, char **av)
{
	return CommandLineTestRunner::RunAllTests(ac, av);
}
