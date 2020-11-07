#include <stdio.h>

unsigned long long fan(int n)
{
    unsigned long long mult =1;
    int i;
    for(i=1;i<=n;i++)
    {
        mult*=i;
    }
    return mult;
}
int main() 
{
	unsigned long long sum=0;
	int i;
	int n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		sum+=fan(i);
	}
	printf("%llu\n",sum);
	return 0;
}
