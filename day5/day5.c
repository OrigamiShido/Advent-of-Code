#include <stdio.h>
#include <string.h>


FILE* input()
{
	errno_t err;
	FILE* steps;
	err = fopen_s(&steps, "C:\\Users\\Admin\\source\\repos\\Advent of Code\\day5\\input.txt", "r");
	if (err != 0)
		return -1;
	return steps;
}

void move(char stack[][50], int* guide)
{
	int i, length[9] = { 0 };
	for (i = 0; i < 9; i++)
		length[i] = strlen(stack[i]);
	for (i = 0; i < guide[0]; i++)
	{
		stack[guide[2] - 1][length[guide[2] - 1] + i] = stack[guide[1] - 1][length[guide[1] - 1] - 1 - i];
		stack[guide[2] - 1][length[guide[2] - 1] + i + 1] = 0;
		stack[guide[1] - 1][length[guide[1] - 1] - 1 - i] = 0;
	}
}

void move2(char stack[][50], int* guide)
{
	int i, length[9] = { 0 };
	for (i = 0; i < 9; i++)
		length[i] = strlen(stack[i]);
	for (i = 0; i < guide[0]; i++)
	{
		stack[guide[2] - 1][length[guide[2] - 1] + i] = stack[guide[1] - 1][length[guide[1] - 1] - guide[0] + i];
		stack[guide[2] - 1][length[guide[2] - 1] + i + 1] = 0;
		stack[guide[1] - 1][length[guide[1] - 1] - guide[0] + i] = 0;
	}
}

void operate(FILE* steps,char* result)
{
	char stack[9][50] = { 0 };
	int i, guide[3] = { 0 }, line=9, length[9] = { 0 };
	printf("please initialize.\n");
	//printf("please enter the lines.\n");
	//scanf_s("%d", &line);
	printf("please input the initial stacks.\n");
	for (i = 0; i < line; i++)
		scanf_s("%s", &stack[i],50);
	while (!(feof(steps)))
	{
		fscanf_s(steps,"%d %d %d", &guide[0], &guide[1], &guide[2]);
		move2(stack, guide);
	}
	fclose(steps);
	for (i = 0; i < line; i++)
		length[i] = strlen(stack[i]);
	for (i = 0; i < line; i++)
		result[i] = stack[i][length[i] - 1];
	return;
}

int main(void)
{
	char result[10] = { 0 };
	FILE* steps;
	steps = input();
	operate(steps, result);
	printf("结果：%s\n", result);
	return 0;
}