#include <stdio.h>

int main(void)
{
    int i;
    printf("please input a num between 1 and 3\n");
    scanf_s("%d", &i);
    switch (i)
    {
    case 1:
        printf("you input %d;\n", i);
        printf("maybe %d is you lucky number!\n", i);
        break;
    case 2:
        printf("you input %d;\mn", i);
        printf("maybe %d is your lucky number!\n", i);
        break;
    default:printf("not a valid number.\n");
    }
    return 0;
}
