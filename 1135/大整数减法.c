#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
    char x[105], y[105];
    while (scanf("%s %s", x, y) != EOF)
    {
        int a[105] = {0}, b[105] = {0}, i;
        int la = strlen(x), lb = strlen(y);
        for (i = 0; i < la; i++)
            a[i] = x[la - 1 - i] - '0';
        for (i = 0; i < lb; i++)
            b[i] = y[lb - 1 - i] - '0';
        if (strcmp(x, y) > 0)
        {
            for (i = 0; i < la; i++)
                a[i] -= b[i];
            for (i = 0; i < la; i++)
            {
                if (a[i] < 0)
                {
                    a[i] += 10;
                    a[i + 1]--;
                }
            }
            for (; i >= 0; i--)
                if (a[i])
                    break;
            for (; i >= 0; i--)
                printf("%d", a[i]);
            printf("\n");
        }
        else if (strcmp(x, y) < 0)
        {
            for (i = 0; i < lb; i++)
                b[i] -= a[i];
            for (i = 0; i < lb; i++)
            {
                if (b[i] < 0)
                {
                    b[i] += 10;
                    b[i + 1]--;
                }
            }
            for (; i >= 0; i--)
                if (b[i])
                    break;
            printf("-");
            for (; i >= 0; i--)
                printf("%d", b[i]);
            printf("\n");
        }
        else
            printf("0\n");
    }
    return 0;
}