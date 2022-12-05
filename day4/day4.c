#include <stdio.h>

FILE* input()
{
	errno_t err;
	FILE* ids;

	err = fopen_s(&ids, "C:\\Users\\Admin\\source\\repos\\Advent of Code\\day4\\input.txt", "r");
	if (err != 0)
		return -1;
	return ids;
}

int contain(FILE* ids)
{
	int result = 0, comp[4] = { 0 };
	while (!(feof(ids)))
	{
		fscanf_s(ids, "%d-%d,%d-%d", &comp[0], &comp[1], &comp[2], &comp[3]);
		if ((comp[0] <= comp[2] && comp[1] >= comp[3]) || (comp[0] >= comp[2] && comp[1] <= comp[3]))
			result++;
	}
	fclose(ids);
	return result;
}

int contain2(FILE* ids)
{
	int result = 0, comp[4] = { 0 };
	while (!(feof(ids)))
	{
		fscanf_s(ids, "%d-%d,%d-%d", &comp[0], &comp[1], &comp[2], &comp[3]);
		//if ((comp[2] >= comp[0] && comp[2] <= comp[1]) || (comp[3] >= comp[0] && comp[3] <= comp[1])|| (comp[0] >= comp[2] && comp[0] <= comp[3]) || (comp[1] >= comp[2] && comp[1] <= comp[3]))
		//if (!((comp[0] < comp[2] && comp[1] < comp[2]) || (comp[2] < comp[0] && comp[3] < comp[0])))//920 in this and above
		if ((comp[0] <= comp[2] && comp[1] >= comp[2]) || (comp[0] >= comp[2] && comp[0] <= comp[3]))
			result++;
	}
	fclose(ids);
	return result;
}

int main(void)
{
	FILE* ids;
	int result;
	ids = input();
	result = contain2(ids);
	printf("结果：%d", result);
	return 0;
}