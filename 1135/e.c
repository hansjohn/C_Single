#include <stdio.h>
#include <math.h>
int toten(int a,int x) { 
	int ans=0,i=0;
	while(x) {
		ans+=x%10*pow(a,i);
		x/=10;
		i++;
	}
	return ans;
}
int tod3(int a,int x) { 
	int ans=0,i=0;
	while(x) {
		ans+=x%a*pow(10,i);
		x/=a;
		i++;
	}
	return ans;
}
int main()
{
    int n;
    long long a,b,d1,d2,d3;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int j=0;
        int along=0;int blong=0;
        int aa[12],bb[12];
        scanf("%lld%lld%lld%lld%lld",&a,&d1,&b,&d2,&d3);
        printf("%d\n",tod3(d3,(toten(d1,a)+toten(d2,b))));
            
        
    }
    return 0;
}