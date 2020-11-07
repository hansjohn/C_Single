#include <stdio.h>
int main()
{
	int a,b,c,i;double sum=0;
	scanf("%d%d%d",&a,&b,&c);
	for(i=1;i<=a;i++)
		sum+=i;
	for(i=1;i<=b;i++)
		sum+=i*i;
	for(i=1;i<=c;i++)
		sum+=1.0/i;
	printf("%.2lf\n",sum);
	return 0;
}
