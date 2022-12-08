#include <stdio.h>
#include <string.h>

#define x 100
#define y 100

struct scene {
	int xn, xp, yn, yp;
};
typedef struct scene scene;
scene score;

FILE* open()
{
	errno_t err;
	FILE* trees;

	err = fopen_s(&trees, "C:\\Users\\Admin\\source\\repos\\Advent of Code\\day8\\input.txt", "r");
	if (err != 0)
		return -1;
	return trees;
}

int read(FILE* trees, char origin[y][x])
{
	int i = 0;

	while (!(feof(trees)))
	{
		fscanf_s(trees, "%s", &origin[i], x);
		i++;
	}
	return i;
}

int looky(char a[y][x], int i, int j,int lines)
{
	int k,h;
	for (k = 0; k < i; k++)
	{
		if (a[k][j] >= a[i][j])
		{
			for (h = lines - 1; h > i; h--)
			{
				if (a[h][j] >= a[i][j])
					return 0;
			}
			return 1;
		}
	}
	return 1;
}

int lookx(char a[y][x], int i, int j, int length)
{
	int k, h;
	for (k = 0; k < j; k++)
	{
		if (a[i][k] >= a[i][j])
		{
			for (h = length - 1; h > j; h--)
			{
				if (a[i][h] >= a[i][j])
					return 0;
			}
			return 1;
		}
	}
	return 1;
}

void checky(char a[y][x], int i, int j, int lines)
{
	int k;
	for (k = i-1; k >= 0; k--)
	{
		if (a[k][j] >= a[i][j])
		{
			score.yp = i - k;
			break;
		}
		else
			score.yp = i;
	}
	for (k = i + 1; k <= lines - 1; k++)
	{
		if (a[k][j] >= a[i][j])
		{
			score.yn = k - i;
			break;
		}
		else
			score.yn = (lines - 1 - i);
	}
	return ;
}

void checkx(char a[y][x], int i, int j, int length)
{
	int k;
	for (k = j - 1; k >= 0; k--)
	{
		if (a[i][k] >= a[i][j])
		{
			score.xn = j - k;
			break;
		}
		else
			score.xn = j;
	}
	for (k = j + 1; k <= length - 1; k++)
	{
		if (a[i][k] >= a[i][j])
		{
			score.xp = k - j;
			break;
		}
		else
			score.xp = (length - 1 - j);
	}
	return;
}

int scores(char a[y][x], int i, int j, int lines, int length)
{
	int result;
	checky(a, i, j, lines);
	checkx(a, i, j, length);
	result = score.xn * score.xp * score.yn * score.yp;
	return result;
}

int localmaxmini(char a[y][x],int lines,int length)
{
	int i, j, k, count = 0, result=0, max=0;
	for (i = 1; i < lines - 1; i++)
	{
		for (j = 1; j < length - 1; j++)
		{
			//if (a[i][j] < a[i][j - 1] && a[i][j] < a[i][j + 1] && a[i][j] < a[i - 1][j - 1] && a[i][j] < a[i - 1][j] && a[i][j] < a[i - 1][j + 1] && a[i][j] < a[i + 1][j - 1] && a[i][j] < a[i + 1][j] && a[i][j] < a[i + 1][j + 1])
			if (a[i][j] > a[i][j - 1] || a[i][j] > a[i][j + 1] || a[i][j] > a[i - 1][j] || a[i][j] > a[i + 1][j])
			{
				if (looky(a,i,j,lines) || lookx(a, i, j,length))
				{
					result=scores(a, i, j, lines, length);
					printf("%c,在第%d行，第%d列，分数为%d\n", a[i][j], i + 1, j + 1, result);
					if (result >= max)
						max = result;
					count++;
				}
			}
		}
	}
	printf("最大值为：%d\n", max);
	return count;
}

int process(char origin[y][x],int lines)
{
	int result = 0, length = 0;
	length = strlen(origin[1]);//注意：gets会把换行符也读进去，导致长度加一！！！
	result += localmaxmini(origin, lines, length);
	result += length + length + lines + lines - 4;
	return result;
}

int main(void)
{
	FILE* trees;
	int lines, result;
	char origin[y][x] = { 0 };
	int i = 0;

	trees = open();
	lines = read(trees, origin);
	result = process(origin, lines);
	printf("结果：%d", result);
	fclose(trees);

	return 0;
}