#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAXCODE 100
typedef struct hfmtree //哈夫曼树的结点
{
    int weight;
    char bit;
    struct hfmtree* lchild;
    struct hfmtree* rchild;
} HFMnode, * HFMtree;
typedef struct node //临时存放权重的地点
{
    int weight;
    char charater;
} Node;
typedef struct indexnode
{
    char* code;
    char character;
    struct indexnode* next;
}IndexNode;
typedef struct _hlTable
{
    IndexNode* first;  //指向第一个节点
    IndexNode* last;//指向第二个节点
}HFMTable;
void bubbleSort(HFMnode arr[], int len) //排完从小到大
{
    HFMnode temp;
    int i, j;
    for (i = 0; i < len - 1; i++) /* 外循环为排序趟数，len个数进行len-1趟 */
        for (j = 0; j < len - 1 - i; j++)
        { /* 内循环为每趟比较的次数，第i趟比较len-i次 */
            if (arr[j].weight > arr[j + 1].weight)
            { /* 相邻元素比较，若逆序则交换（升序为左大于右，降序反之） */
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
}
HFMtree CreatLeave(HFMnode a)
{
    HFMtree p = (HFMtree)malloc(sizeof(HFMnode));
    *p = a;
    return p;
}
HFMtree CreatHFMtree(HFMnode a[])
{
    int i = 0;
    HFMtree p, q, r;
    while (i < 128)
    {
        i = 0;
        while (a[i].weight == 0) //找出第一个权重不为0的结点
        {
            i++;
        }
        p = CreatLeave(a[i]);
        a[i].weight = 0;
        i++;
        q = CreatLeave(a[i]);;
        r = (HFMtree)malloc(sizeof(HFMnode));
        r->weight = p->weight + q->weight;
        if (p->weight > q->weight)
        {
            r->rchild = p;
            r->lchild = q;
        }
        else
        {
            r->rchild = q;
            r->lchild = p;
        }
        a[i] = (*r);
        bubbleSort(a, 128);

    }
    r = (HFMtree)malloc(sizeof(HFMnode));
    *r = a[127];
    return r;
}
void FindChar(HFMtree ht)
{
    char code[100];
    int c;
    printf(" 输入你想查询的编码：\n");
    scanf("%s", code);

    int direction;
    int len = strlen(code) - 1;
    HFMtree p;
    direction = code[0] - '0';
    if (direction == 1)
    {
        p = ht->rchild;
    }
    else
    {
        p = ht->lchild;
    }
    for (int i = 1; i < len; i++)
    {
        direction = code[i] - '0';
        if (direction == 1)
        {
            p = p->rchild;
        }
        else
        {
            p = p->lchild;
        }
    }
    printf("%c\n", p->bit);
}
void print_table(HFMTable* table)
{
    IndexNode* temp = table->first;
    while (temp != NULL)
    {
        printf("%c:%s\n", temp->character, temp->code);
        temp = temp->next;
    }
    printf("\n");
}
void traverseTree(HFMtree treeNode, HFMTable* table, int k, char code[256])
{
    if (treeNode->lchild == NULL && treeNode->rchild == NULL)//已经到达huffman树叶子节点，
    {
        code[k] = '\0';//加上结束符
        IndexNode* aux = (IndexNode*)malloc(sizeof(IndexNode));
        aux->code = (char*)malloc(sizeof(char) * (strlen(code) + 1));
        strcpy(aux->code, code);//赋值该字符编码
        aux->character = treeNode->bit;//赋值节点字符，就是叶节点的字符

        aux->next = NULL;
        if (table->first == NULL)//插入到编码表里
        {
            table->first = aux;
            table->last = aux;
        }
        else
        {

            table->last->next = aux;
            table->last = aux;
        }
    }
    if (treeNode->lchild != NULL)//还没到根节点先查询左孩子
    {
        code[k] = '0';//向左走，赋值0
        traverseTree(treeNode->lchild, table, k + 1, code);
    }
    if (treeNode->rchild != NULL)//还没到根节点查询右孩子
    {
        code[k] = '1';//向右走，赋值1
        traverseTree(treeNode->rchild, table, k + 1, code);
    }
}
HFMTable* buildTable(HFMtree huffmantree)
{
    HFMTable* table = (HFMTable*)malloc(sizeof(HFMTable));
    if (table)
    {
        table->first = NULL;
        table->last = NULL;
    }
    char code[256];//保存编码
    int k = 0;
    traverseTree(huffmantree, table, k, code);
    printf("对应编码表为\n");
    print_table(table);
    return table;
}
void FindCode(char a, HFMTable* table)
{
    IndexNode* temp = table->first;
    while (temp != NULL && temp->character != a)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("no this character!\n");
        return;
    }
    if (temp->character == a)
    {
        printf("the code of %c is %s\n", a, temp->code);
    }
}
int main()
{
    HFMtree ht;
    HFMnode a[128];
    char b[101];
    char s;
    for (int i = 0; i < 128; i++)
    {
        a[i].bit = i;
        a[i].weight = 0;
    }

    printf("输入编码字段，只允许字母，空格，句号，逗号。不超过100字符"); //输入编码的句子
    fgets(b, 102, stdin);
    int len = strlen(b);
    int i = 0;
    for (i = 0; i < len - 1; i++)
    {
        a[b[i]].weight++;
    }
    //对权重进行冒泡排序
    bubbleSort(a, 128);
    //建立哈夫曼树
    ht = CreatHFMtree(a);
    HFMTable* table = buildTable(ht);
    FindChar(ht);
    printf("输入你想查询的符号\n");
    getchar();
    scanf("%c", &s);
    FindCode(s, table);
    return 0;
}