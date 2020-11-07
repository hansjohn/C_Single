#include <stdio.h>
int main()
{
    long long a,b;
    while(scanf("%lld%lld",&a,&b)!=EOF)
    {
        a=a%1012;
        int jieguo=1;
        for(int i=1;i<=b;i++)
        {
            jieguo=jieguo*a;
            jieguo%=1012;
        }
        jieguo%=1012;
        printf("%d\n",jieguo);
    }
    return 0;
}