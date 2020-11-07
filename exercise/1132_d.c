#include <stdio.h>
int num(char a)
{
    return a - '0';
}
char tochar(int a)
{
    return a + '0';
}
int main()
{
    int b;
    char a[201];
    while (scanf("%d%s", &b, &a) != EOF)
    {
        int i = 0, flag = 0;

        if (tochar(num(a[i]) + 1) > '9')
        {
            a[i]+=1;
            while (i < b - 1 && a[i] > '9')
            {
                a[i] = '0';
                a[i + 1]++;
                i++;
            }
            if (i == b - 1 && a[i] > '9')
            {
                a[i] = '0';
                flag = 1;
            }
        }
        else
        {
            a[i] = tochar(num(a[i]) + 1);
        }
        for (i = 0; i < b; i++)
        {
            printf("%c", a[i]);
        }
        if (flag == 1)
        {
            printf("1\n");
        }
        else
        {
            printf("\n");
        }
    }
    return 0;
}