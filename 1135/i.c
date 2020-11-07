#include <stdio.h>
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int a;
        scanf("%d", &a);
        if (a > 1)
        {
            printf("%dx^%d", a, n);
        }
        else if (a < -1)
        {
            printf("%dx^%d", a, n);
        }
        else if (a == 1)
        {
            printf("x^%d", n);
        }
        else if (a == -1)
        {
            printf("-x^%d", n);
        }

        for (int i = n - 1; i > 1; i--)
        {
            scanf("%d", &a);
            if (a > 1)
            {
                printf("+%dx^%d", a, i);
            }
            else if (a < -1)
            {
                printf("%dx^%d", a, i);
            }
            else if (a == 1)
            {
                printf("+x^%d", i);
            }
            else if (a == -1)
            {
                printf("-x^%d", i);
            }
        }
        scanf("%d", &a);
        if (a > 1)
            {
                printf("+%dx", a);
            }
            else if (a < -1)
            {
                printf("%dx", a);
            }
            else if (a == 1)
            {
                printf("+x");
            }
            else if (a == -1)
            {
                printf("-x");
            }
        scanf("%d", &a);
        if (a > 0)
        {
            printf("+%d", a);
        }
        else if (a < 0)
        {
            printf("%d", a);
        }
        printf("\n");
    }
    return 0;
}