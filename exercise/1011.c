/* #include <stdio.h>
#include <string.h>

int main()
{
    char str[50];
    gets(str);
    int i;
    for(i=1;i<strlen(str)+1;i++)
    {
        printf("%c",str[i-1]+4);
    }
    printf("\n");
    return 0;
} */
#include <stdio.h>
#define PI 3.140001
 
int main()
{
    double r, h, C1, Sa, Sb, Va, Vb;
    scanf("%lf %lf", &r, &h);
    C1 = 2*PI*r;    //圆周长
    Sa = PI*r*r;    //圆面积
    Sb = 4*PI*r*r;  //球表面积
    Va = 4*PI*r*r*r/3.0;
    Vb = Sa*h;
    printf("C1=%.2lf\n", C1);
    printf("Sa=%.2lf\n", Sa);
    printf("Sb=%.2lf\n", Sb);
    printf("Va=%.2lf\n", Va);
    printf("Vb=%.2lf\n", Vb);
    return 0;
}