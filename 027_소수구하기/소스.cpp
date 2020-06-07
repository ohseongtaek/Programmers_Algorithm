#include <stdio.h>

int arr[1000001] = { 1,1,1, };

int main()
{
    int min, max, temp;
    scanf_s("%d %d", &min, &max);
    for (int i = 2; i <= max; i++)
    {
        temp = i;
        while (temp + i <= max)
        {
            temp = temp + i;
            if (arr[temp] != 1)
            {
                arr[temp] = 1;
            }
        }
    }

    if (min <= 2 && max >= 2)
    {
        printf("2\n");
    }

    for (int i = min; i <= max; i++)
    {
        if (arr[i] == 0)
        {
            printf("%d\n", i);
        }
    }

    return 0;
}