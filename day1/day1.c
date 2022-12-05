#include<stdio.h>
#define n 1000

void nomi(int* a, int space)
{
	errno_t err;
	FILE* statistic;
	int i = 0, j;
	int mid[50] = { 0 };
	int total = 0;
	char test;
	int count=0;

	err = fopen_s(&statistic, "C:\\Users\\Admin\\source\\repos\\Advent of Code\\day1\\input.txt", "r");
	while (!(feof(statistic)))
	{
		fscanf_s(statistic, "%d", &mid[i]);
		i++;
		if (feof(statistic) != 0)
			return;
		test = fgetc(statistic);
		test = fgetc(statistic);
		if (test != '\n')
		{
			fseek(statistic, -1, 1);
		}
		else
		{
			for (j = 0; j < i; j++)
				total += mid[j];
			for (j = 0; j < i; j++)
				mid[j] = 0;
			i = 0;
			a[count] = total;
			count++;
			total = 0;
		}
	}
	fclose(statistic);
}

int max(int* a, int N)
{
	int i;
	int result=a[0];
	for (i = 0; i < N; i++)
	{
		if (result < a[i])
			result = a[i];
	}
	return result;
}

int maxloop(int* a, int N)
{
	int i = 1,j;
	int mid;
	
	mid=max(a, N);
	for (j = 0; j < N; j++)
	{
		if (mid == a[j])
			a[j] = 0;
	}
	
	return max(a, N);
}

int main(void)
{
	int a[n] = { 0 };
	int result,result1, result2, result3;
	nomi(a, n);
	result1 = max(a, n);
	result2 = maxloop(a, n);
	result3 = maxloop(a, n);
	result = result1 + result2 + result3;
	printf("结果：%d", result);
	return 0;
}