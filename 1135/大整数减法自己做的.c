#include <stdio.h>
#include <string.h>
int main()
{
    char a[105], b[105];
    while (scanf("%s %s", a, b) != EOF)
    {

        int fushu=0;
        int x[105] = {0}, y[105] = {0};
        int long_a = strlen(a);
        int long_b = strlen(b);
        int min = long_b;
        if (long_a > long_b || (long_a == long_b && strcmp(a, b) > 0))
        {
            for (int i = 0; i < long_a; i++)
            {
                x[i] = a[i] - '0';
            }
            for (int i = 0; i < long_b; i++)
            {
                y[i] = b[i] - '0';
            }
            min = long_b;
        }
        else
        {
            fushu=1;
            for (int i = 0; i < long_a; i++)
            {
                y[i] = a[i] - '0';
            }
            for (int i = 0; i < long_b; i++)
            {
                x[i] = b[i] - '0';
            }
            int min = long_b;
            long_b = long_a;
            long_a = min;
        } //x是大的，y是小的
        for (int i = 0; i < long_b; i++)
        {
            if (x[long_a - i - 1] >= y[long_b - i - 1])
            {
                x[long_a - i - 1] -= y[long_b - i - 1];
            }
            else
            {
                x[long_a - i - 1 - 1]--;
                 x[long_a - i - 1]=x[long_a - i - 1] -y[long_b - i - 1] + 10;
            }
        }
        for(int i=long_a-long_b-1;i>0;i--)
        {
            if(x[i]<0)
            {
                x[i]+=10;
                x[i-1]--;
            }
        }
        int i;
        for(i=0;i<long_a;i++)
        {
            if(x[i]!=0)
            break;
        }
        if(i==long_a)
        {
            printf("0\n");
        }
        if(i<long_a)
        {
            if(fushu==1)
            {
                printf("-");
            }
            for(;i<long_a;i++)
            {
                printf("%d",x[i]);
            }
            printf("\n");
        }
        
    }
    return 0;
}