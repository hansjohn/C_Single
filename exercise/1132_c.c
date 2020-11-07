#include <stdio.h>
#include <math.h>
int main()
{
    int a, b;
    while (scanf("%d%d", &a, &b)!=EOF)
    {
        int i, bai, shi, ge,flag=0;
        for (i = a; i <=b; i++)
        {
            bai = i / 100;
            shi = (i - bai * 100) / 10;
            ge = i % 10;
            if (ge * ge * ge + bai * bai * bai + shi * shi * shi == i &&flag==0)
            {
                printf("%d", i);
                flag=1;
            }
            else if(ge * ge * ge + bai * bai * bai + shi * shi * shi == i &&flag==1)
            {
                printf(" %d", i);
            }
        }
        if(flag==1)
        {
            printf("\n");
        }
        else
        {
            printf("no\n");
        }
        
    }
    return 0;
}
