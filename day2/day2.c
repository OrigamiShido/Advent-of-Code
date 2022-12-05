#include <stdio.h>

judge2(char op, char me)
{
	int result = 0;
	if (me == 'X')
	{
		result += 0;
		result += op - 'A';
		if (op == 'A')
			result += 3;
	}
	if (me == 'Y')
	{
		result += 3;
		result += op - 'A' + 1;
	}
	if (me == 'Z')
	{
		result += 6;
		result += op - 'A' + 2;
		if (op == 'C')
			result -= 3;
	}
	return result;
}

judge(char op, char me)
{
	int result=0;
	if (me == 'X')
		result += 1;
	if (me == 'Y')
		result += 2;
	if (me == 'Z')
		result += 3;
	op += 23;
	if (op == me)
	{
		result += 3;
		return result;
	}
	if (me == 'X' && op == 'Z')
	{
		result += 6;
		return result;
	}
	if ((me - 1) == op)
	{
		result += 6;
		return result;
	}
	else
		return result;
}

int input()
{
	FILE* statistics;
	char op, me;
	int score = 0;
	errno_t err;
	err = fopen_s(&statistics, "C:\\Users\\Admin\\source\\repos\\Advent of Code\\day2\\input.txt", "r");
	if (err != 0)
		return -1;
	while (!(feof(statistics)))
	{
		op = fgetc(statistics);
		fgetc(statistics);
		me = fgetc(statistics);
		fgetc(statistics);
		score += judge2(op, me);
	}
	fclose(statistics);
	return score;
}

int main(void)
{
	int result;
	result=input();
	printf("结果是：%d", result);
	return 0;
}