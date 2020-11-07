#include <stdio.h>
#include <math.h>
int RelativelyPrime(int a, int b)
{
    if(a==1||b==1)
    {return 1;}
    int min = a < b ? a : b;
    for (int i = 2; i <= min; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int p, n;
    while (scanf("%d%d", &p, &n) != EOF)
    {
        int x,y,u,v;
        int X=1,Y=1,U=n,V=1;
        double sqrt1=sqrt(p);
        int limit=(int)(sqrt(p));
        //找下界
        for(y=1;y<=n;y++)
        {
            for(x=limit*y;x<=(limit+1)*y&&x<=n;x++)
            {
                if(RelativelyPrime(x,y))
                {
                    if((double)(X)/(double)(Y)<(double)(x)/(double)(y))
                    {
                        if((double)(x)/(double)(y)<=sqrt1)
                        {
                            X=x;
                            Y=y;
                        }
                        else
                        {
                            if((double)(U)/(double)(V)>(double)(x)/(double)(y))
                            {
                                U=x;
                                V=y;
                            }
                        }
                    }
                }
            }
        }
        printf("%d/%d %d/%d\n",X,Y,U,V);
    }
    return 0;
}