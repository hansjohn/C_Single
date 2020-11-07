# include <stdlib.h>
# include<stdio.h>
#include <malloc.h>
#pragma warning(disable:4996)
typedef int Type; //创建，删除，查找，显示，插入
typedef struct Node
{
    Type data;   //数据域；type：用户定义数据类型
    struct Node* next;

}Node, * LinkList;
LinkList InitList(LinkList L)
{
    L = (LinkList)malloc(sizeof(Node));
    if (!L) exit(1);  //申请空间失败
    else
    {
        L->next = NULL;
        return L;
    }

}
void InsertList(LinkList L, int i, Type e)
{
    LinkList p = L;
    int j = 0;
    if (p->next == NULL&& i==1)     //链表只有头指针，插在头上
    {
        p->next = (LinkList)malloc(sizeof(Node));
        if (p->next) //内存分配成功时
        {
            p->next->data = e;
            p->next->next = NULL;
            return ;
        }

    }
    while (p && j < i - 1)   //找到前一个节点
    {
        p = p->next;   //跳过第一个节点，到第一个有数据的结点
        j++;
    }
    if (j > i - 1 || !p)  //异常处理 返回0
    {
        exit(1);
    }
    if (j == i - 1 && p) {
        LinkList q;
        q = (LinkList)malloc(sizeof(Node));
        if (q)
        {
            q->data = e;
            q->next = p->next;
            p->next = q;
        }
    }
    
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
        ++j;

    }
    if (j > i || !p)
    {
        printf("Error!n is bigger than the list!");
        exit(1) ;
    }

    else { return p->data; }
    

}
//int FindList(LinkList L, Type e)
//{
//    LinkList p = L->next;
//    int i = 1;
//    while ((p->data != e) && (!p))
//    {
//        i++;
//    }
//    if (!p)
//    {
//        printf("no this data");
//        return 0;
//    }
//    else return i;
//
//}
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
//void DestroyList(LinkList L)
//{
//    if (!L) exit(0);
//    else
//    {
//        LinkList p = L->next;//指向下一个结点
//        while (!p)
//        {
//            free(L);
//            L = p;
//            p = p->next;
//            if (!p) break;
//        }
//        free(L);
//    }
//}
LinkList CreatList()
{
    LinkList L=NULL;
    L=InitList(L);     //创建头指针
    Type a;
    int i=1;
    printf("输入数值（control+z结尾）：");
    while (scanf("%d", &a))
    {
        InsertList(L,i,a);
        i++;
    }
    PrintList(L);
    printf("\n");
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
    printf("请先创建一个链表\n");
    LinkList List = CreatList();
    printf("选择你想要的操作：\n" "delete(d)\n" "insert(i)\n" "get(g)\n"  
        "destroy(D)（注意是大写）\n" "length(l)\n" "creat(c)\n" "quit(q)\n");
    scanf("%c", &s);
    while (s != 'q')
    {
        switch (s)
        {
        case 'd':
        {
            printf("选择你要删除的节点位置：\n");
            int TmpLoation;
            scanf("%d", &TmpLoation);
            DeleteList(List, TmpLoation);
            PrintList(List); break;
        }
        case 'i':
        {
            int TmpLoation;
            printf("选择你要插入的节点位置：\n");
            scanf("%d", &TmpLoation);
            int e;
            printf("输入你要插入的数据：");
            scanf("%d", &e);
            InsertList(List, TmpLoation, e);
            PrintList(List);
            printf("\n"); break;
        }
       /* case 'D':
        {
            DestroyList(List);
        }*/
        case 'c':
        {
            List = CreatList();
            PrintList(List);
            printf("\n"); break;
        }
        case 'g':
        {
            int TmpLoation;
            printf("选择你要查看的值的位置：");
            scanf("%d", &TmpLoation);
            printf("%d\n", GetList(List, TmpLoation));
            break;
        }
        case 'l':
        {
            printf("%d\n", LengthList(List)); break;
        }
        

        }
        scanf("%c", &s);
    }
    printf("bye!");
    return 0;
}