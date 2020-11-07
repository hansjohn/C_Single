#include <stdio.h>
void swap(int *a,int * b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int max_2(int a,int b,int c,int d)
{
    if (a<b)
        swap(&a,&b);
    if (a<c)
        swap(&a,&c);
    if (a<d)
        swap(&a,&d);
    if (b<c)
        swap(&b,&c);
    if (b<d)
        swap(&b,&d);
    if (c<d)
        swap(&c,&d);
    if(a!=b)
        return b;
    else if(b!=c) return c;
    else return d;
    
}

int main() 
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
   float l,f;int i =2;
   scanf("%f",&f);
   while (scanf("%f", &l) != EOF)
   {
      if(l<f)
      {
          printf("%d波峰%f\n",i,f);
      }
      f=l;
      i++;

   }
   return 0;
}