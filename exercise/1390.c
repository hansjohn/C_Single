#include <stdio.h>
int GreatestCommonFactor(int a,int b)
{
    int i;
    int min=a<b? a:b;
    for(i=min;i>0;i--)
    {
        if(a%i==0&&b%i==0)
        return i;
    }
}
int LeastCommonMultiple(int a,int b)
{
    
    int max=a>b? a:b;
    int i=max;
    for(;i<=a*b;i++)
    {
        if(i%a==0&&i%b==0)
        return i;
    }
}
int main()
{
    int x,y;
    int count=0;
    scanf("%d%d",&x,&y);
    for(int i=x,j;i<=y;i++)
    {
        if((x*y)%i==0)
        {
            j=(x*y)/i;
            if(GreatestCommonFactor(i,j)==x&&LeastCommonMultiple(i,j)==y)
            {
                count++;
            }
        }
    }
    printf("%d\n",count);
    return 0;
}