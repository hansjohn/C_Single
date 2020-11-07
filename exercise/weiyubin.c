#include <stdio.h>
#include <stdlib.h>
typedef char element;
typedef struct btnode
{
    char date;
    struct btnode *lchild,*rchild;
}btnode,*bitree;

btnode *createbt1(char *pre,char*in,int n)
{  if(n==0){return 0;}
    btnode *b;
    b=(btnode*)malloc(sizeof(btnode));
    b->date=*pre;
    char *p;
    p=in;
    while(*p!=*pre)
    {
        p++;
    }
    int k;
    k=p-in;
    b->lchild=createbt1(pre+1,in,k);
    b->rchild=createbt1(pre+k+1,in+k+1,n-k-1);
    return(b);}

  btnode *createbt2(char *pre,char*in,int n)
{  if(n==0){return 0;}
    btnode *b;
    b=(btnode*)malloc(sizeof(btnode));
    char *end;
    end=pre+n-1;
    b->date=*end;
    char *p;
    p=in;
    while(*p!=*end)
    {
        p++;
    }
    int k;
    k=p-in;
    b->lchild=createbt2(pre,in,k);
    b->rchild=createbt2(pre+k,in+k+1,n-k-1);
    return(b);}

void disbtree(btnode *b)
{
    if(b!=NULL)
    {
        printf("%c",(b->date));
        if(b->lchild!=NULL||b->rchild!=NULL)
        {
            printf("(");
            disbtree(b->lchild);
            if(b->rchild!=NULL)
                printf(",");
            disbtree(b->rchild);
            printf(")");
        }
    }
}






int main()
{btnode *createbt1(char *pre,char*in,int n);
void disbtree(btnode *b);
btnode *createbt2(char *pre,char*in,int n);
 btnode *f;
    printf("请输入先序排列");
    char c[20];
    c[20]='9';
    int i=0;
    do{
        scanf("%c",&c[i]);
        i++;
    }while(c[i-1]!='\n');
    int num;
    num=i-1;
    printf("请输入中序排列");
    char l[20];
    for(int i=0;i<num;i++)
    {
        scanf("%c",&l[i]);
    }
    f=createbt1(c,l,num);
    disbtree(f);
printf("\n");
btnode *g;
printf("请输入后序序列");
char d[20];
    d[20]='8';
    int t=0;
    do{
        scanf("%c",&d[t]);
        t++;
    }while(d[t-1]!='\n');
    int n;
    n=t-1;
printf("请输入中序排列");
    char k[20];
    for(int i=0;i<n;i++)
    {
        scanf("%c",&k[i]);
    }
    g=createbt2(d,k,n);
disbtree(g);
    return 0;
}