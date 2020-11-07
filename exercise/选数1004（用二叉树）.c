//用二叉树的方法求
#include <stdio.h>
#include <math.h>
int ans=0,k,n,a[21];
int IsPrime(int x)
{
    int i;
    for(i=2;i<=sqrt(x);i++)
    if(x%i==0)
    {
        return 0;
    }
    return 1;
}
void Search(int start,int count,int sum,int times,int pos)
{
    if(count==k&&IsPrime(sum))
    {
        ans++;
    }
    else if(times==n)
    {
        return;
    }
    else
    { 
        pos++;
        Search(start+1,count,sum,times+1,pos);
        Search(start+1,count+1,sum+a[pos],times+1,pos);
    }
    
}
int main ()
{
    int i;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    Search(1,0,0,0,0);
    printf("%d\n",ans);
    return 0;
}
