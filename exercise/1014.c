#include <stdio.h>

int main()
{
    float x;
    scanf("%f",&x);
    if(x<1)
    {
        printf("%.0f\n",x);
    }
    else if(x>=1&& x<10)
    {
        printf("%.0f\n",2*x-1);
    }
    else
    {
        printf("%.0f\n",3*x-11);
    }
    

    return 0;
}