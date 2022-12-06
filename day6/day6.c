#include <stdio.h>
#include <string.h>
#define N 5000
#define distance 14

FILE* open()
{
	errno_t err;
	FILE* chars;

	err = fopen_s(&chars, "C:\\Users\\Admin\\source\\repos\\Advent of Code\\day6\\input.txt", "r");
	if (err != 0)
		return -1;
	return chars;
}

int judge(char* sample)
{
	if (sample[0] == sample[1] || sample[1] == sample[2] || sample[2] == sample[3] || sample[0] == sample[2] || sample[1] == sample[3] || sample[0] == sample[3])
		return 1;
	else
		return 0;
}

int judge2(char* sample)
{
	int length, i, j;
	length = strlen(sample);
	for (i = 0; i < length; i++)
	{
		for (j = i+1; j < length; j++)
		{
			if (sample[i] == sample[j])
				return 1;
		}
	}
	return 0;
}

void read(FILE* chars,char* origin)
{
	fgets(origin, N, chars);
	return;
}

int process(char* origin)
{
	char sample[distance+1] = { 0 };
	int length, i, j;
	length = strlen(origin);
	for (i = 0; i < length - (distance-1); i++)
	{
		for (j = 0; j < distance; j++)
			sample[j] = origin[i + j];
		if (judge2(sample))
			continue;
		else
			return (i + distance);
	}
}

int main(void)
{
	int result;
	char origin[N] = { 0 };
	FILE* chars;
	chars = open();
	read(chars, origin);
	result=process(origin);
	fclose(chars);
	printf("结果：%d", result);
	return 0;
}