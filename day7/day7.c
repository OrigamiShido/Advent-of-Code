#include <stdio.h>
#include <string.h>
#define N 500

int result2 = 70000000;
int result = 0;
int dimention = 0;
int total = 0;
int free = 0;

int byte[20] = { 0 };

FILE* open()
{
	errno_t err;
	FILE* sys;
	err = fopen_s(&sys, "C:\\Users\\Admin\\source\\repos\\Advent of Code\\day7\\input.txt", "r");
	if (err != 0)
		return -1;
	return sys;
}

void check(int a)
{
	if (byte[a - 1] <= 100000)
		result += byte[a - 1];
	byte[a - 1] = 0;
	return;
}

void check2(int a)
{
	if (byte[a - 1] >= free)
		if (byte[a - 1] <= result2)
			result2 = byte[a - 1];
	byte[a - 1] = 0;
	return;
}

void checktotal()
{
	total = byte[0];
	free = 30000000 - (70000000 - total);
	return;
}

void finalcheck(int a)
{
	int i;
	if (a == 1)
	{
		for (i = 0; i < 20; i++)
		{
			if (byte[i] != 0)
				check(i + 1);
		}
	}
	if (a == 2)
	{
		for (i = 0; i < 20; i++)
		{
			if (byte[i] != 0)
				check2(i + 1);
		}
	}
	return;
}

void plus(int a)
{
	int i;
	for (i = dimention - 1; i >= 0; i--)
	{
		byte[i] += a;
	}
	return;
}

void list(FILE* sys)
{
	int judge = 0, bytes = 0, length, i = 1;
	char mid[N] = { 0 }, place[10] = { 0 };
	while (!(feof(sys)))
	{
		fgets(mid, N, sys);
		if (mid[0] == '$')
		{
			length = strlen(mid);
			fseek(sys, -(length), 1);
			fseek(sys, -1, 1);
			break;
		}
		sscanf_s(mid, "%d %s", &bytes, place, 10);
		//judge += bytes;
		//byte[dimention-1] += bytes;
		plus(bytes);
		bytes = 0;
	}
	/*if (judge <= 100000)
		return judge;
	else
		return 0;*/
	return;
}

void cd(char* lines, int a)
{
	if (a == 1)
	{
		if (lines[5] == '.' || lines[6] == '.')
		{
			check(dimention);
			dimention--;
		}
		else
			dimention++;
		return;
	}
	if (a == 2)
	{
		if (lines[5] == '.' || lines[6] == '.')
		{
			check2(dimention);
			dimention--;
		}
		else
			dimention++;
		return;
	}
}

void insertcmd(FILE* sys,char* lines,int a)
{
	if (lines[2] == 'l' && lines[3] == 's')
	{
		//result += list(sys);
		list(sys);
		return;
	}
	if (lines[2] == 'c' && lines[3] == 'd')
	{
		cd(lines, a);
		return;
	}
}

void process2(FILE* sys)
{
	char lines[N] = { 0 };
	rewind(sys);
	dimention = 0;
	while (!(feof(sys)))
	{
		fgets(lines, N, sys);
		if (lines[0] == '$')
			insertcmd(sys, lines, 2);
		else
			continue;
	}
	finalcheck(2);
	return;
}

void process(FILE* sys)
{
	char lines[N] = { 0 };
	while (!(feof(sys)))
	{
		fgets(lines, N, sys);
		if (lines[0] == '$')
			insertcmd(sys, lines, 1);
		else
			continue;
	}
	checktotal();
	finalcheck(1);
	process2(sys);
	return;
}

int main(void)
{
	FILE* sys;
	sys = open();
	process(sys);
	printf("结果：%d,%d", result, result2);
	fclose(sys);
	return 0;
}