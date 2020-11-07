#include <stdio.h>
#include <math.h>
int main()
{
    int i,bai,shi,ge;
    for(i=100;i<=999;i++)
    {
        bai=i/100;
        shi=(i-bai*100)/10;
        ge=i%10;
        if(ge*ge*ge+bai*bai*bai+shi*shi*shi==i)
        {
            printf("%d\n",i);
        }
    }
    return 0;
}
