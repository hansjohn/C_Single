#include <stdio.h>

int main()
{
    double a,b,c;
    scanf("%lf %lf %lf",&a,&b,&c);
    if(a<b)
    {
        double temp=a;
        a=b;
        b=temp;
    }
    if (a<c)
    {
        double temp=a;
        a=c;
        c=temp;
    }
    if(b<c)
    {
        double temp=b;
        b=c;
        c=temp;
    }
    printf("%.10lf %.10lf %.10lf",a,b,c);
    return 0;
}