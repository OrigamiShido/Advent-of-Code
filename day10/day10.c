#include <stdio.h>
#include <math.h>

int circle = 0;
int X = 1;
int result = 0;
int count = 0;

FILE* open()
{
	errno_t err;
	FILE* cmds;
	err = fopen_s(&cmds, "C:\\Users\\Admin\\source\\repos\\Advent of Code\\day10\\input.txt", "r");
	if (err != 0)
		return -1;
	return cmds;
}

void check()
{
	int mid;
	if (circle == 20 || circle == 60 || circle == 100 || circle == 140 || circle == 180 || circle == 220)
	{
		mid = circle * X;
		printf("结果为：%d\n", mid);
		result += mid;
	}
	return; 
}

void check2()
{
	if (count == 40)
	{
		printf("\n");
		count -= 40;
	}
	if (fabs(count - X) <= 1)
	{
		printf("#");
		count++;
	}
	else
	{
		printf(".");
		count++;
	}
}

void noop()
{
	circle += 1;
	check2();
	return;
}

void addx(int num)
{
	circle += 1;
	check2();
	circle += 1;
	check2();
	X += num;
	return;
}

void read(FILE* cmds)
{
	int num;
	char mid[20] = { 0 }, mid2[5] = { 0 };
	while(!(feof(cmds)))
	{
		fgets(mid, 20, cmds);
		if (mid[0] == 'n')
			noop();
		if (mid[0] == 'a')
		{
			sscanf_s(mid, "%s %d", &mid2, 5, &num);
			addx(num);
		}
	}
}

int main(void)
{
	FILE* cmds;
	cmds = open();
	read(cmds);
	printf("结果：%d\n", result);
	return 0;
}