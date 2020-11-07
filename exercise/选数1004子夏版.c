#include <stdio.h>
#include <math.h>
int ans=0,k,n,a[20];
int prime(int x)
{
    int i;
    for(i=2;i<=sqrt(x);i++)
    if(x%i==0){
        return 0;
    }
    return 1;
}
void search(int start,int cnt,int sum)
{
    int i;
    if(cnt==k&&prime(sum)==1)
        ans++;
    for(i=start;i<=n;i++)
        search(i+1,cnt+1,sum+a[i]);
}
int main(){
    int i;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
    search(1,0,0);
    printf("%d\n",ans);
    return 0;
}
