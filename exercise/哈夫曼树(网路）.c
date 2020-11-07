#include <stdio.h>

#define MAXBIT      100
#define MAXVALUE  10000
#define MAXLEAF     30
#define MAXNODE    MAXLEAF*2 -1

typedef struct 
{
    int bit[MAXBIT];
    int start;
} HCodeType;      
typedef struct
{
    int weight;
    int parent;
    int lchild;
    int rchild;
} HNodeType;        
//构造一颗哈夫曼树 
void HuffmanTree (HNodeType HuffNode[MAXNODE],  int n)
{ 
int i, j, m1, m2, x1, x2;

    for (i=0; i<2*n-1; i++)   //初始化存放哈夫曼树数组 HuffNode[] 中的结点 
    {
        HuffNode[i].weight = 0;
        HuffNode[i].parent =-1;
        HuffNode[i].lchild =-1;
        HuffNode[i].lchild =-1;
    }

    for (i=0; i<n; i++)
    {
        printf ("输入叶子结点的权值%d: ", i);
        scanf ("%d", &HuffNode[i].weight);
    }
    for (i=0; i<n-1; i++)
    {
        m1=m2=MAXVALUE;     // m1、m2中存放两个无父结点且结点权值最小的两个结点 
        x1=x2=0;
        // 找出所有结点中权值最小、无父结点的两个结点，并合并之为一颗二叉树 
        for (j=0; j<n+i; j++)
        {
            if (HuffNode[j].weight < m1 && HuffNode[j].parent==-1)
            {
                m2=m1; 
                x2=x1; 
                m1=HuffNode[j].weight;
                x1=j;
            }
            else if (HuffNode[j].weight < m2 && HuffNode[j].parent==-1)
            {
                m2=HuffNode[j].weight;
                x2=j;
            }
        } 
        HuffNode[x1].parent  = n+i;
        HuffNode[x2].parent  = n+i;
        HuffNode[n+i].weight = HuffNode[x1].weight + HuffNode[x2].weight;
        HuffNode[n+i].lchild = x1;
        HuffNode[n+i].rchild = x2;
    }
} 
int main(void)
{
    HNodeType HuffNode[MAXNODE];            // 定义一个结点结构体数组 
    HCodeType HuffCode[MAXLEAF],  cd;       
    int i, j, c, p, n;
    printf ("请输入 n:\n");
    scanf ("%d", &n);
    HuffmanTree (HuffNode, n);
    
    for (i=0; i < n; i++)
    {
        cd.start = n-1;
        c = i;
        p = HuffNode[c].parent;
        while (p != -1)   // 父结点存在 
        {
            if (HuffNode[p].lchild == c)
                cd.bit[cd.start] = 0;
            else
                cd.bit[cd.start] = 1;
            cd.start--;        // 求编码的低一位 
            c=p;                    
            p=HuffNode[c].parent;    
        }
        
        for (j=cd.start+1; j<n; j++)
        { HuffCode[i].bit[j] = cd.bit[j];}
        HuffCode[i].start = cd.start;
    } 
    for (i=0; i<n; i++)   //输出已保存好的所有存在编码的哈夫曼编码 
    {
        printf ("%d 哈夫曼编码是； ", i);
        for (j=HuffCode[i].start+1; j < n; j++)
        {
            printf ("%d", HuffCode[i].bit[j]);
        }
        printf ("\n");
    }
    return 0;
}
