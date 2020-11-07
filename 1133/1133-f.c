#include <stdio.h>
int main() {
	int n,cnt=0;
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		int a=i%3;
		int b=i%7;
		if((a==1&&b==3)||(a==1&&b==4)||(a==2&&b==2)||(a==2&&b==5)||(a==0&&b==1)||(a==0&&b==6))
			cnt++;
	}
	printf("%d\n",cnt);

	return 0;
}