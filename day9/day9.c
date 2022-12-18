#include <stdio.h>
#include <math.h>

#define Y 1000
#define X 1000

struct position {
	int x, y;
};
typedef struct position position;
position tail[10];
char square[Y][X] = { 0 };


FILE* open()
{
	errno_t err;
	FILE* path;
	err = fopen_s(&path, "C:\\Users\\Admin\\source\\repos\\Advent of Code\\day9\\example2.txt", "r");
	if (err != 0)
		return -1;
	return path;
}

void check(char a, int num)
{
	int i, set;
	char situ = a, type;
	if (num <= 7)
		type = '$';
	else
		type = '#';
	if (a == 'U')
	{
		if (fabs(tail[num].y - tail[num + 1].y) <= 1)
			;
		else
		{
			if (tail[num + 1].x != tail[num].x)
			{
				if (tail[num + 1].x < tail[num].x)
					situ = 'R';
				else
					situ = 'L';
			}
			set = fabs(tail[num].y - tail[num + 1].y) - 1;
			tail[num + 1].x = tail[num].x;
			for (i = 0; i < set; i++)
			{
				tail[num + 1].y--;
				if (square[tail[num + 1].y][tail[num + 1].x] == '#')
					continue;
				square[tail[num + 1].y][tail[num + 1].x] = type;
			}
		}
	}
	if (a == 'D')
	{
		if (fabs(tail[num].y - tail[num + 1].y) <= 1)
			;
		else
		{
			if (tail[num + 1].x != tail[num].x)
			{
				if (tail[num + 1].x < tail[num].x)
					situ = 'R';
				else
					situ = 'L';
				set = fabs(tail[num].y - tail[num + 1].y) - 1;
				tail[num + 1].x = tail[num].x;
				for (i = 0; i < set; i++)
				{
					tail[num + 1].y++;
					if (square[tail[num + 1].y][tail[num + 1].x] == '#')
						continue;
					square[tail[num + 1].y][tail[num + 1].x] = type;
				}
			}
		}
	}
	if (a == 'L')
	{
		if (fabs(tail[num].x - tail[num + 1].x) <= 1)
			;
		else
		{
			if (tail[num + 1].y != tail[num].y)
			{
				if (tail[num + 1].y < tail[num].y)
					situ = 'U';
				else
					situ = 'D';
				set = fabs(tail[num].x - tail[num + 1].x) - 1;
				tail[num + 1].y = tail[num].y;
				for (i = 0; i < set; i++)
				{
					tail[num + 1].x--;
					if (square[tail[num + 1].y][tail[num + 1].x] == '#')
						continue;
					square[tail[num + 1].y][tail[num + 1].x] = type;
				}
			}
		}
	}
	if (a == 'R')
	{
		if (fabs(tail[num].x - tail[num + 1].x) <= 1)
			;
		else
		{
			if (tail[num + 1].y != tail[num].y)
			{
				if (tail[num + 1].y < tail[num].y)
					situ = 'U';
				else
					situ = 'D';
				set = fabs(tail[num].x - tail[num + 1].x) - 1;
				tail[num + 1].y = tail[num].y;
				for (i = 0; i < set; i++)
				{
					tail[num + 1].x++;
					if (square[tail[num + 1].y][tail[num + 1].x] == '#')
						continue;
					square[tail[num + 1].y][tail[num + 1].x] = type;
				}
			}
		}
	}
	if (num > 7)
		return;
	else
		check(situ, num + 1);
}

void commandinsert2(char direction, int move)
{
	int i;
	if (direction == 'U')
	{
		for (i = 0; i < move; i++)
		{
			tail[0].y--;
			check('U', 0);
		}
	}
	if (direction == 'D')
	{
		for (i = 0; i < move; i++)
		{
			tail[0].y++;
			check('D', 0);
		}
	}
	if (direction == 'L')
	{
		for (i = 0; i < move; i++)
		{
			tail[0].x--;
			check('L', 0);
		}
	}
	if (direction == 'R')
	{
		for (i = 0; i < move; i++)
		{
			tail[0].x++;
			check('R', 0);
		}
	}
	return;
}

void commandinsert(char direction, int move)
{
	if (direction == 'U')
	{
		tail[0].y -= move;
		check('U',0);
	}
	if (direction == 'D')
	{
		tail[0].y += move;
		check('D',0);
	}
	if (direction == 'L')
	{
		tail[0].x -= move;
		check('L',0);
	}
	if (direction == 'R')
	{
		tail[0].x += move;
		check('R',0);
	}
	return;
}

void process(FILE* path)
{
	char mid[20] = { 0 };
	char direction;
	int move;

	while (!(feof(path)))
	{
		
		fgets(mid, 20, path);
		sscanf_s(mid, "%c %d", &direction,1, &move);
		//fscanf_s(path, "&c %d", &direction, &move);

		commandinsert2(direction, move);

	}
	return;
}

int scan()
{
	int count = 0,i,j;
	for (i = 0; i < Y; i++)
	{
		for (j = 0; j < X; j++)
		{
			if (square[i][j] == '#')
			{
				count++;
				printf("%d行%d列\n",i+1,j+1);
			}
		}
	}
	return count;
}

int main(void)
{
	int result,i;
	FILE* path;
	for (i = 0; i < 10; i++)
	{
		tail[i].x = tail[i].y = 500;
	}
	square[tail[1].y][tail[1].x] = '#';
	path = open();
	process(path);
	result = scan();
	printf("结果：%d", result);
	return 0;
}