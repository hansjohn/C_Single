#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int isPrime(int n){
	//1不是素数，所以要先判断传入的参数是否为1 
	if(n==1){
		//如果为1则返回0 
		return 0;
	}else{
		for(int i=2;i<n;i++){
		if(n%i==0){
			return 0;
		}
	}
    //没有在2~m-1之间找到n的商，证明此数是素数，返回1 
	return 1;
	}
	
}
int saifa(int N,int *a)
{
    a[0]=a[1]=0;
    int i=2;
    int j;
    for(;i<=N;i++)
    {
        a[i]=1;
    }
    for(i=2;i<=N;i++)
    {
        if (!isPrime(i))
        {
            for(j=i;j<=N;j++)
            {
                if(j%i==0)
                {
                    a[j]=0;
                }
            }
        }
    }
    for(i=2;i<=N;i++)
    {
        if(a[i]==1)
        {
            printf("%d\n",i);
        }
    }

}
int main()
{
    int N;
    scanf("%d",&N);
    int *a=(int *)malloc((N+1)*sizeof(int));
    saifa(N,a);
    return 0;

}