#include <stdio.h>
#include <string.h>
#define ROW 2
#define COL 2
typedef struct mat
{
    int a[ROW][COL];
}mat;
mat matmul(mat a,mat b)
{
    mat c;
    memset(c.a,0,sizeof(c.a));
    for(int i=0;i<ROW;i++)
        for(int j=0;j<COL;j++)
            for(int k=0;k<COL;k++)
                c.a[i][j]=(c.a[i][j]+a.a[i][k]*b.a[k][j])%10000;
    return c;
}
mat matpow(int n)
{
    mat ans,g;
    ans.a[0][0]=ans.a[1][1]=1;
    ans.a[1][0]=ans.a[0][1]=0;
    g.a[0][0]=g.a[0][1]=g.a[1][0]=1;
    g.a[1][1]=0;
    while(n)
    {
        if(n&1)
        {
            ans=matmul(ans,g);
        }
        g=matmul(g,g);
        n>>=1;
    }
    return ans;
}
int main()
{
    int i;
    scanf("%d",&i);
    while(i!=-1)
    {
        mat b=matpow(i);
        printf("%d\n",b.a[0][1]);
        scanf("%d",&i);
    }
}