#include <stdio.h>
int main() {
	int n,cnt=0;
	while(scanf("%d",&n)!=EOF)
    {
        cnt=0;
	for(int i=1; i<=n; i++) {
		int a=i%3;
		int b=i%7;
		if(a==0)
		{
            if ((1-b*b)%7==0)
            {
                cnt++;
            }
        }
        if(a==1)
        {
            if ((2-b*b)%7==0)
            {
                cnt++;
            }
        }
        if(a==2)
        {
            if ((4-b*b)%7==0)
            {
                cnt++;
            }
        }
	}
	printf("%d\n",cnt);
    }

	return 0;
}