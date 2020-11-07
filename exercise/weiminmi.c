
#include <stdio.h>

int main()
{
    int S = 0;
    int n,i,j,mult;
    int MOD = 1000000;
    while(scanf("%d",&n)!=EOF)
    {
        
    if(n>=25)printf("000000\n");
    else
    {for(i = 1; i <= n; i++)
    {
        mult= 1;
        
        for( j = 1 ; j <= i; j++)
            //进行取余
            mult = mult*j%MOD;

    }
    printf("%06d\n",mult);}
    }
    return 0;
}