#include <stdio.h>
int main()
{
    double pid4=0;
    int n=1,flag=1,flag2=1;
    while(flag2)
    {
        pid4+=(1.0/n)*flag;
        if((1.0/n)<1e-6)
            flag2=0;
        n+=2;
        flag*=-1;
    }
    printf("%lf\n",pid4-0.000001);
    return 0;
}