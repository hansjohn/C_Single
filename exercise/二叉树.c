#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Type;
typedef struct BiTNode
{
    Type data;  //数据域；Type: 用户定义数据类型
    struct BiTNode* Lchild;  //左指针域
    struct BiTNode* Rchild;  //右指针域
} BiTNode, * BiTree;
//写一个队列的数据结构
typedef struct node
{
    BiTNode element;
    struct node* Link;
}Node;
typedef struct queue
{
    Node* Front, * Rear;
    int size;
}*Queue;
void InitQueue(Queue Q)//初始化
{

    Q->Front = Q->Rear = (Node*)malloc(sizeof(Node));
    Q->Front->Link = NULL;
    Q->size = 0;

}
int DestoryQueue(Queue Q)
{
    while (Q->Front)
    {
        Q->Rear = Q->Front->Link;
        free(Q->Front);
        Q->Front = Q->Rear;

    }
    return 1;
}
int EnQueue(Queue Q, BiTNode e)
{
    Node* p = (Node*)malloc(sizeof(Node));
    if (p)

    {
        p->element = e;
        p->Link = NULL;
        Q->Rear->Link = p;
        Q->Rear = p;
        Q->size++;
        return 1;
    }
    else
    {
        return 0;
    }

}
int IsQueueEmpty(Queue Q)
{
    if (Q->Front == Q->Rear)
    {
        return 1;
    }
}
BiTNode DeQueue(Queue Q)//删除第一个元素，并返回这个元素
{

    if (Q->Front == Q->Rear)
    {
        /*printf("the queue is empty");
        exit(1);*/
        return;
    }
    else
    {
        Node* p = Q->Front->Link;
        Q->Front->Link = p->Link;
        Node temp = *p;
        if (Q->Rear == p) Q->Rear = Q->Front;
        free(p);
        Q->size--;
        return temp.element;
    }
}
//队列建立好了

BiTree InitBiTree(BiTree L)
{
    L->data = 0;
    L->Lchild = NULL;
    L->Rchild = NULL;
    return L;

}
void PreOrder(BiTree L)    //前序遍历
{

    if (L != NULL)
    {
        printf("%d", L->data);
        PreOrder(L->Lchild);
        PreOrder(L->Rchild);
    }
}
void PostOrder(BiTree L)    //后序遍历
{

    if (L != NULL)
    {

        PostOrder(L->Lchild);
        PostOrder(L->Rchild);
        printf("%d", L->data);
    }
}
void InOrder(BiTree L)    //中序遍历
{

    if (L != NULL)
    {

        InOrder(L->Lchild);
        printf("%d", L->data);
        InOrder(L->Rchild);

    }
}
BiTree CreateTree(BiTree t)  //前序建立一棵树
{
    int temp;
    scanf("%d", &temp);
    if (temp == 0)
    {
        t = NULL;
    }
    else
    {
        
        t = (BiTree)malloc(sizeof(BiTNode));
        t->data = temp;
        t->Lchild=CreateTree(t->Lchild);
        t->Rchild=CreateTree(t->Rchild);
    }
    return t;
}
void LevelOrderL(BiTree L)
{
    struct queue treedata;
    InitQueue(&treedata);
    if (L->data != 0)
    {
        EnQueue(&treedata, *L);
    }
    while (treedata.size > 0)
    {
        BiTNode tempnode = DeQueue(&treedata);
        printf("%d ", tempnode.data);
        if (tempnode.Lchild != NULL)
        {
            EnQueue(&treedata, *(tempnode.Lchild));
        }
        if (tempnode.Rchild != NULL)
        {
            EnQueue(&treedata, *(tempnode.Rchild));
        }
    }
}
bool DestoryBiTree(BiTree L)
{
    if (L != NULL)
    {

        PreOrder(L->Lchild);
        PreOrder(L->Rchild);
        free(L);
    }
    return 0;
}
bool ClearBiTree(BiTree L)
{
    if (L != NULL)
    {

        PreOrder(L->Lchild);
        PreOrder(L->Rchild);
        L->data = 0;
    }
    return 1;
}

int main()
{
    BiTree tree = (BiTree)malloc(sizeof(BiTNode));
    tree= InitBiTree(tree);
    printf("输入数据：（以0表示空，一个数据后一个回车）\n");
    tree = CreateTree(tree);//构建一棵树
    LevelOrderL(tree);
    return 0;
}
