#include <stdio.h>
double fact(int n)
{
    double sum =1;
    int i;
    for(i=1;i<=n;i++)
    {
        sum*=1.0/i;
    }
    return sum;
}
double fact2(int n)
{
    double sum =0;
    int i;
    for(i=1;i<=n;i++)
    {
        sum+=fact(i);
    }
    return sum;
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("sum=%.5lf",fact2(n));
    return 0;
}