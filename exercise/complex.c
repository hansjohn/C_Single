#include <stdio.h>
#include <stdlib.h>
typedef struct complex
{
    double real;
    double imag;
}Complex;
Complex add(Complex * a,Complex * b)
{
    Complex temp;
    temp.real= a->real+b->real;
    temp.imag = a->imag+b->imag;
    return temp;
}
Complex Create(double a,double b)
{
    Complex temp;
    temp.real = a;
    temp.imag = b;
    return temp;
}
void PrintComplex(Complex * a)
{
    printf("%.2lf+%.2lfi",a->real,a->imag);
}
int main (void)
{
    Complex a=Create(1,2);
    Complex b=Create(2,4);
    Complex c;
    c=add(&a,&b);
    PrintComplex(&c);
    return 0;
}