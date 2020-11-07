#include <stdio.h>
int Isprime(int n) {
    if(n==1||n==0) return 0;
    else 
    for(int i=2; i<n; i++)
        if(n%i==0) return 0;
    return 1;
}
int main() {
    int a,d,n;
    while(scanf("%d %d %d",&a,&d,&n)!=EOF){
    	int cnt=0;
    	long long i;
    	for(i=a;cnt<n;i+=d){
    		if(Isprime(i)) cnt++;
		}
		printf("%lld\n",i-d);
	}
    return 0;
}