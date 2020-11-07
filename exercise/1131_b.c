#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    
    freopen("out.txt","w",stdout);
    for(n=1;n<200;n++)
    {
        printf("%lf\t\t\t\t\t\t\t\t\%d\n",pow(2,n)-pow(n,2),(long)(pow(2,n)-pow(n,2))%7==0);
    }

    return 0;
}