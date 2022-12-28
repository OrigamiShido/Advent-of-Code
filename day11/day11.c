#include <stdio.h>
#include <math.h>

#define N 100

unsigned long long itempool[8][N] = { {54, 82, 90, 88, 86, 54},{91, 65},{ 62, 54, 57, 92, 83, 63, 63},{67, 72, 68},{68, 89, 90, 86, 84, 57, 72, 84},{79, 83, 64, 58},{96, 72, 89, 70, 88},{79} };

//unsigned long long rolldown(unsigned long long num)
//{
//	float result;
//	result = floor((float)num / 3);
//	return (unsigned long long)result;
//}

unsigned long long rolldown(unsigned long long num)
{
	return num;
}

unsigned long long monkey0()
{
	unsigned long long i, j;
	unsigned long long monkeynum = 0, operationnum = 7, testnum = 11, truethrow = 2, falsethrow = 6;
	static unsigned long long count = 0;
	for (i = 0; i < N; i++)
	{
		if (itempool[monkeynum][i] == 0)
			continue;
		count++;
		itempool[monkeynum][i] *= operationnum;
		itempool[monkeynum][i] = rolldown(itempool[monkeynum][i]);
		if (itempool[monkeynum][i] % testnum == 0)
		{
			for (j = 0; j < N; j++)
			{
				if (itempool[truethrow][j] == 0)
				{
					itempool[truethrow][j] = itempool[monkeynum][i];
					itempool[monkeynum][i] = 0;
				}
				else
					continue;
			}
		}
		else
		{
			for (j = 0; j < N; j++)
			{
				if (itempool[falsethrow][j] == 0)
				{
					itempool[falsethrow][j] = itempool[monkeynum][i];
					itempool[monkeynum][i] = 0;
				}
				else
					continue;
			}
		}
	}
	return count;
}

unsigned long long monkey1()
{
	unsigned long long i, j;
	static unsigned long long count = 0;
	unsigned long long monkeynum = 1, operationnum = 13, testnum = 5, truethrow = 7, falsethrow = 4;
	for (i = 0; i < N; i++)
	{
		if (itempool[monkeynum][i] == 0)
			continue;
		count++;
		itempool[monkeynum][i] *= operationnum;
		itempool[monkeynum][i] = rolldown(itempool[monkeynum][i]);
		if (itempool[monkeynum][i] % testnum == 0)
		{
			for (j = 0; j < N; j++)
			{
				if (itempool[truethrow][j] == 0)
				{
					itempool[truethrow][j] = itempool[monkeynum][i];
					itempool[monkeynum][i] = 0;
				}
				else
					continue;
			}
		}
		else
		{
			for (j = 0; j < N; j++)
			{
				if (itempool[falsethrow][j] == 0)
				{
					itempool[falsethrow][j] = itempool[monkeynum][i];
					itempool[monkeynum][i] = 0;
				}
				else
					continue;
			}
		}
	}
	return count;
}

unsigned long long monkey2()
{
	unsigned long long i, j;
	static unsigned long long count = 0;
	unsigned long long monkeynum = 2, operationnum = 1, testnum = 7, truethrow = 1, falsethrow = 7;
	for (i = 0; i < N; i++)
	{
		if (itempool[monkeynum][i] == 0)
			continue;
		count++;
		itempool[monkeynum][i] += operationnum;
		itempool[monkeynum][i] = rolldown(itempool[monkeynum][i]);
		if (itempool[monkeynum][i] % testnum == 0)
		{
			for (j = 0; j < N; j++)
			{
				if (itempool[truethrow][j] == 0)
				{
					itempool[truethrow][j] = itempool[monkeynum][i];
					itempool[monkeynum][i] = 0;
				}
				else
					continue;
			}
		}
		else
		{
			for (j = 0; j < N; j++)
			{
				if (itempool[falsethrow][j] == 0)
				{
					itempool[falsethrow][j] = itempool[monkeynum][i];
					itempool[monkeynum][i] = 0;
				}
				else
					continue;
			}
		}
	}
	return count;
}

unsigned long long monkey3()
{
	unsigned long long i, j;
	static unsigned long long count = 0;
	unsigned long long monkeynum = 3, testnum = 2, truethrow = 0, falsethrow = 6;
	for (i = 0; i < N; i++)
	{
		if (itempool[monkeynum][i] == 0)
			continue;
		count++;
		itempool[monkeynum][i] *= itempool[monkeynum][i];
		itempool[monkeynum][i] = rolldown(itempool[monkeynum][i]);
		if (itempool[monkeynum][i] % testnum == 0)
		{
			for (j = 0; j < N; j++)
			{
				if (itempool[truethrow][j] == 0)
				{
					itempool[truethrow][j] = itempool[monkeynum][i];
					itempool[monkeynum][i] = 0;
				}
				else
					continue;
			}
		}
		else
		{
			for (j = 0; j < N; j++)
			{
				if (itempool[falsethrow][j] == 0)
				{
					itempool[falsethrow][j] = itempool[monkeynum][i];
					itempool[monkeynum][i] = 0;
				}
				else
					continue;
			}
		}
	}
	return count;
}

unsigned long long monkey4()
{
	unsigned long long i, j;
	static unsigned long long count = 0;
	unsigned long long monkeynum = 4, operationnum = 7, testnum = 17, truethrow = 3, falsethrow = 5;
	for (i = 0; i < N; i++)
	{
		if (itempool[monkeynum][i] == 0)
			continue;
		count++;
		itempool[monkeynum][i] += operationnum;
		itempool[monkeynum][i] = rolldown(itempool[monkeynum][i]);
		if (itempool[monkeynum][i] % testnum == 0)
		{
			for (j = 0; j < N; j++)
			{
				if (itempool[truethrow][j] == 0)
				{
					itempool[truethrow][j] = itempool[monkeynum][i];
					itempool[monkeynum][i] = 0;
				}
				else
					continue;
			}
		}
		else
		{
			for (j = 0; j < N; j++)
			{
				if (itempool[falsethrow][j] == 0)
				{
					itempool[falsethrow][j] = itempool[monkeynum][i];
					itempool[monkeynum][i] = 0;
				}
				else
					continue;
			}
		}
	}
	return count;
}

unsigned long long monkey5()
{
	unsigned long long i, j;
	static unsigned long long count = 0;
	unsigned long long monkeynum = 5, operationnum = 6, testnum = 13, truethrow = 3, falsethrow = 0;
	for (i = 0; i < N; i++)
	{
		if (itempool[monkeynum][i] == 0)
			continue;
		count++;
		itempool[monkeynum][i] += operationnum;
		itempool[monkeynum][i] = rolldown(itempool[monkeynum][i]);
		if (itempool[monkeynum][i] % testnum == 0)
		{
			for (j = 0; j < N; j++)
			{
				if (itempool[truethrow][j] == 0)
				{
					itempool[truethrow][j] = itempool[monkeynum][i];
					itempool[monkeynum][i] = 0;
				}
				else
					continue;
			}
		}
		else
		{
			for (j = 0; j < N; j++)
			{
				if (itempool[falsethrow][j] == 0)
				{
					itempool[falsethrow][j] = itempool[monkeynum][i];
					itempool[monkeynum][i] = 0;
				}
				else
					continue;
			}
		}
	}
	return count;
}

unsigned long long monkey6()
{
	unsigned long long i, j;
	static unsigned long long count = 0;
	unsigned long long monkeynum = 6, operationnum = 4, testnum = 3, truethrow = 1, falsethrow = 2;
	for (i = 0; i < N; i++)
	{
		if (itempool[monkeynum][i] == 0)
			continue;
		count++;
		itempool[monkeynum][i] += operationnum;
		itempool[monkeynum][i] = rolldown(itempool[monkeynum][i]);
		if (itempool[monkeynum][i] % testnum == 0)
		{
			for (j = 0; j < N; j++)
			{
				if (itempool[truethrow][j] == 0)
				{
					itempool[truethrow][j] = itempool[monkeynum][i];
					itempool[monkeynum][i] = 0;
				}
				else
					continue;
			}
		}
		else
		{
			for (j = 0; j < N; j++)
			{
				if (itempool[falsethrow][j] == 0)
				{
					itempool[falsethrow][j] = itempool[monkeynum][i];
					itempool[monkeynum][i] = 0;
				}
				else
					continue;
			}
		}
	}
	return count;
}

unsigned long long monkey7()
{
	unsigned long long i, j;
	static unsigned long long count = 0;
	unsigned long long monkeynum = 7, operationnum = 8, testnum = 19, truethrow = 4, falsethrow = 5;
	for (i = 0; i < N; i++)
	{
		if (itempool[monkeynum][i] == 0)
			continue;
		count++;
		itempool[monkeynum][i] += operationnum;
		itempool[monkeynum][i] = rolldown(itempool[monkeynum][i]);
		if (itempool[monkeynum][i] % testnum == 0)
		{
			for (j = 0; j < N; j++)
			{
				if (itempool[truethrow][j] == 0)
				{
					itempool[truethrow][j] = itempool[monkeynum][i];
					itempool[monkeynum][i] = 0;
				}
				else
					continue;
			}
		}
		else
		{
			for (j = 0; j < N; j++)
			{
				if (itempool[falsethrow][j] == 0)
				{
					itempool[falsethrow][j] = itempool[monkeynum][i];
					itempool[monkeynum][i] = 0;
				}
				else
					continue;
			}
		}
	}
	return count;
}

unsigned long long max(unsigned long long* count)
{
	unsigned long long i, maxium = 0, mid = 0;
	unsigned long long result;
	for (i = 0; i < 8; i++)
	{
		if (mid < count[i])
			mid = count[i];
	}
	for (i = 0; i < 8; i++)
	{
		if (maxium < count[i] && count[i] != mid)
			maxium = count[i];
	}
	result = mid * maxium;
	return result;
}

unsigned long long process()
{
	unsigned long long i;
	unsigned long long result;
	unsigned long long count[8] = { 0 };
	for (i = 0; i < 10000; i++)
	{
		count[0] = monkey0();
		count[1] = monkey1();
		count[2] = monkey2();
		count[3] = monkey3();
		count[4] = monkey4();
		count[5] = monkey5();
		count[6] = monkey6();
		count[7] = monkey7();
	}
	result = max(count);
	return result;
}

unsigned long long main(void)
{
	unsigned long long result;
	result = process();
	printf("结果：%llu", result);
	return 0;
}