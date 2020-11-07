#include <stdio.h>
#include <math.h>
int change(int a,int x) { 
	int ans=0,i=0;
	while(x) {
		ans+=x%10*pow(a,i);
		x/=10;
		i++;
	}
	return ans;
}
int change_b(int a,int x) { 
	int ans=0,i=0;
	while(x) {
		ans+=x%a*pow(10,i);
		x/=a;
		i++;
	}
	return ans;
}
int main() {
	int n;
	scanf("%d",&n);
	while(n--) {
		int a,b,c,d,e;
		scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
		printf("%d\n",change_b(e,(change(b,a)+change(d,c))));
	}
	return 0;
}