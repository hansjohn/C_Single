# include <stdlib.h>
# include<stdio.h>
typedef int Type; //创建，删除，查找，显示，插入
typedef struct Node
{
    Type data;   //数据域；type：用户定义数据类型
    struct Node* next;

}Node, * LinkList;
int InitList(LinkList L)
{
    L = (LinkList)malloc(sizeof(Node));
    if (!L) return 0;  //申请空间失败
    else
    {
        L->next = NULL;
        return 1;
    }

}
int InsertList(LinkList L, int i, Type e)
{
    LinkList p = L;
    int j = 0;
    if (p->next == NULL&& i==1)     //插在头上
    {
        p->next = (LinkList)malloc(sizeof(Node));
        p->next->data = e;
        p->next->next = NULL;
        return 1;
    }
    while (p && j < i - 1)   //找到前一个节点
    {
        p = p->next;   //跳过第一个节点
        j++;
    }
    if (j > i - 1 || !p)  //异常处理 返回0
    {
        return 0;
    }
    LinkList q;
    q = (LinkList)malloc(sizeof(Node));
    q->data = e;
    q->next = p->next;
    p->next = q;
    return 1;
}
void PrintList(LinkList L)   //显示全部内容
{
    LinkList p;
    if (!(p = L->next))
    {
        printf("the list is null");
    }
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
Type GetList(LinkList L, int i)   //显示第i个数据
{
    LinkList p = L;
    int j = 1;
    if (!(p = L->next))
    {
        printf("the list is null");
        exit(1);
    }
    while (p && j < i)
    {
        p = p->next;
        j++;

    }
    if (j > i || !p)
    {
        printf("Error!n is bigger than the list!");
        exit(1) ;
    }

    else { return p->data; }
    

}

void DeleteList(LinkList L, int i)
{
    LinkList p, q;
    int j;
    j = 1; p = L->next; q = L;
    while (p && j < i)  //寻找第i个结点p
    {
        ++j;
        q = p;
        p = p->next;
    }
    if (j > i || !p)
    {
        printf("Error!n is bigger than the list!");
        exit(1);
    }
    if (p)   //删除第i个结点
    {
        q->next = p->next;
        free(p);
    }
}
void DestroyList(LinkList L)
{
    if (!L) exit(0);
    else
    {
        LinkList p = L->next;//指向下一个结点
        while (!p)
        {
            free(L);
            L = p;
            p = p->next;
        }
        free(L);
    }
}
LinkList CreatList()
{
    LinkList L=NULL;
    InitList(L);     //创建头指针
    Type a;
    int i=1;
    printf("输入数值（输入q结尾）：");
    while (a = (scanf("%d", &a)))
    {
        InsertList(L,i,a);
        i++;
    }
    return L;
}
int LengthList(LinkList L)
{
    LinkList p;
    int length=0;
    if (!(p = L->next))
    {
        printf("the list is null");
        return 0;
    }
    while (p)
    {
        p = p->next;
        length++;
    }
    return length;
}
int main(void)
{
    char s;
    printf("菜单\n");
    printf("请先创建一个链表");
    LinkList List = CreatList();
    printf("选择你想要的操作：\n" "delete(d)\t" "insert(i)\n" "get(g)\t"  
        "destroy(D)（注意是大写）\n" "length(l)\t" "creat(c)\n" "quit(q)\n");
    while ((s = scanf("%c", &s)) != 'q')
    {
        switch (s = scanf("%c", &s))
        {
        case 'd':
        {
            printf("选择你要删除的节点位置：\n");
            int TmpLoation;
            scanf("%d", &TmpLoation);
            DeleteList(List, TmpLoation);
            PrintList(List);
        }
        case 'i':
        {
            int TmpLoation;
            printf("选择你要插入的节点位置：");
            scanf("%d", &TmpLoation);
            int e;
            printf("输入你要插入的数据：");
            scanf("%d", &e);
            InsertList(List, TmpLoation, e);
            PrintList(List);
            printf("\n");
        }
        case 'D':
        {
            DestroyList(List);
        }
        case 'c':
        {
            List = CreatList();
            PrintList(List);
            printf("\n");
        }
        case 'g':
        {
            int TmpLoation;
            printf("选择你要查看的值的位置：");
            scanf("%d", &TmpLoation);
            GetList(List, TmpLoation);
            PrintList(List);
            printf("\n");
        }
        case 'l':
        {
            printf("%d\n", LengthList(List));
        }


        }
    }
    printf("bye!");
    return 0;
}