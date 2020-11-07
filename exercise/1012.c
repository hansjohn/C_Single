#include <stdio.h>
#define pi 3.14
int main()
{
    double r,h;
    scanf("%lf %lf",&r,&h);
    printf("C1=%.2lf\n",2*r*pi);
    printf("Sa=%.2lf\n",r*r*pi);
    printf("Sb=%.2lf\n",4*r*r*pi);
    printf("Va=%.2lf\n",4.0/3*pi*r*r*r);
    printf("Vb=%.2lf\n",h*r*r*pi); 

    return 0;
}
