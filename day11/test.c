#include <stdio.h>
#include <string.h>

int main(void)
{
	char* a1 = "1234", * a2 = "5678";
	strcpy_s(a1, 10, a2);
	printf("%s", a1);
	return 0;
}