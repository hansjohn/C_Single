/* 谁先拿饮料
题目 1094
描述
IBM俱乐部的同学们为了缓解这一个月来紧张的“上学情绪”，决定一起出去吃顿饭。
服务员端上来好多种特色的软饮，大家都想先下手，抢到自己喜欢的那份。
但是俱乐部是一个有纪律的组织，大庭广众下不能这么浪荡....
那么问题来了...
俱乐部来聚餐的一共有n个同学。
假如从第一位同学开始报数，报到第m位，那么就先确定出第一位挑软饮的同学，然后排除这位同学，从这位同学的下一位同学开始报数，报到第m位，那么这位就是第二位挑软饮的同学，如此循环...
简单说就是：n = 5 位同学编号 1 2 3 4 5，假设m = 3，则第一位就是3，第二位就是1，第三位就是5，第四位就是2，最后一位就是4. 
输入
输入n，m，n表示此次聚餐有n（n<=1000）位俱乐部的同学来参加，m如上解释....
输出
输出挑选软饮的同学编号的顺序。 */
#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int n,m;
    while (scanf("%d %d",&n,&m)!=EOF)
    {
        int num=1;
        int count=0;
        int * queue=(int *)(malloc((n+1)*sizeof(int)));
        int i=0;
        for(;i<=n;i++)
        {
            queue[i]=1;
        }
        int b=1;
        while(count<=n)
        {
            
            if(b%m==0&&queue[num]==1)
            {
                if(count<n)
                {
                    printf("%d ",num);
                    count++;
                    queue[num]=0;
                }
                else if(count==n)
                {
                    printf("%d\n",num);
                    queue[num]=0;
                    count++;
                }
            }
            num++;
            b++;
            if(num>n)
            {
                num=1;
            }
            
        }
    }
    return 0;
    
}