#include <stdio.h>
#include <math.h>
int main()
{
    double r ,a;
    int flag=0;
    while(scanf("%lf",&r)!=EOF)
    {
       a=r+0.0000000001;
       if(a>100)
       {
           printf("100.0000000000");
       }
       else
       printf("%.10lf\n",a);
        
    }
    return 0;
}