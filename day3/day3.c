#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 50
#define num 310

FILE* input()
{
	errno_t err;
	FILE* chars;

	err = fopen_s(&chars, "C:\\Users\\Admin\\source\\repos\\Advent of Code\\day3\\input.txt", "r");

	if (err != 0)
		return -1;
	return chars;
}

void compare(char* a, FILE* chars)
{
	int length, i, j, count = 0;
	char mid0[N / 2] = { 0 }, mid1[N / 2] = { 0 }, origin[N] = { 0 };

	while (!(feof(chars)))
	{
		fscanf_s(chars, "%s", origin, N);
		length = strlen(origin);
		for (i = 0; i < (length / 2); i++)
		{
			mid0[i] = origin[i];
			mid1[i] = origin[i + (length / 2)];
		}
		for (i = 0; i < (length / 2); i++)
		{
			for (j = 0; j < (length / 2); j++)
			{
				if (mid0[i] == mid1[j])
				{
					a[count] = mid0[i];
					count++;
					break;
				}
			}
			if (mid0[i] == mid1[j])
			{
				break;
			}
		}
		memset(origin, 0, sizeof(origin));
		memset(mid0, 0, sizeof(mid0));
		memset(mid1, 0, sizeof(mid1));
	}
	fclose(chars);
}

void compare3(char* a, FILE* chars)
{
	int length[3] = { 0 }, i, j, count = 0, count2 = 0;
	char mid[20] = { 0 }, origin[3][N] = { 0 };

	while (!(feof(chars)))
	{
		for (i = 0; i < 3; i++)
		{
			fscanf_s(chars, "%s", origin[i], N);
		}
		
		for (i = 0; i < 3; i++)
			length[i] = strlen(origin[i]);

		for (i = 0; i < length[0]; i++)
		{
			for (j = 0; j < length[1]; j++)
			{
				if (origin[0][i] == origin[1][j])
				{
					mid[count] = origin[0][i];
					count++;
					break;
				}
			}
		}

		count = 0;

		for (i = 0; i < strlen(mid); i++)
		{
			for (j = 0; j < length[2]; j++)
			{
				if (mid[i] == origin[2][j])
				{
					a[count2] = mid[i];
					count2++;
					break;
				}
			}
			if (mid[i] == origin[2][j])
				break;
		}
		
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < N; j++)
				origin[i][j] = 0;
		}
		memset(mid, 0, sizeof(mid));
	}
	fclose(chars);
}

int judge(char* a)
{
	int length, result = 0, i;
	length = strlen(a);
	for (i = 0; i < length; i++)
	{
		if (islower(a[i]))
			result += (a[i] - 'a' + 1);
		if (isupper(a[i]))
			result += (a[i] - 'A' + 27);
	}
	return result;
}

int main(void)
{
	int result;
	char a[num] = { 0 };
	FILE* chars;
	chars = input();
	compare3(a, chars);
	result = judge(a);
	printf("结果：%d", result);
	return 0;
}