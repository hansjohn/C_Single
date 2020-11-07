#pragma warning(disable:4996)
#include <stdio.h>
#include <malloc.h>
#define NUM 100
struct index
{
int key;
int link;
} index_table[10];
typedef struct Slist*List;
struct Slist
{
int data[NUM];
int n;
int N;
};
List creatSlist(int num, List L)
{
int i;
List P = (List)malloc(sizeof(struct Slist));
for (i = 0; i < num; i++)
{
scanf("%d", &P->data[i]);
}
L = P;
return L;
}
void creatindex(int a[][10], int fenkuai, int fenkuainum[], List L)
{
int i = 0, j = 0, k = 0;
for (i = 0; i < fenkuai; i++)
{
for (j = 0; j < fenkuainum[i]; j++)
{
a[i][j] = L->data[k];
k++;
}
}
}
void printfindex(int a[][10], int fenkuai, int fenkuainum[])
{
int i = 0, j = 0, k = 0;
for (i = 0; i < fenkuai; i++)
{
for (j = 0; j < fenkuainum[i]; j++)
{
printf("%d ", a[i][j]);
}
printf("\n");
}
}
void findkey(struct index index_table[], int a[][10], int fenkuainum[], int fenkuai)
{
int i;
for (i = 0; i < fenkuai; i++)
{
index_table[i].key = a[i][fenkuainum[i] - 1];
index_table[i].link = i;
}
}
int searchind(struct index index_table[], int fenkuai, int number)
{
	int i, flag = 0;
	for (i = 0; i < fenkuai; i++)
	{
		if (number <= index_table[i].key)
		{
			flag = 1;
			//return index_table[i].link;
			break;
		}
	}
	if (flag == 1)return index_table[i].link;
	else
	{
		printf("这个数不存在\n");
		return -1;
	}

}
int searchpos(struct index index_table[], int fenkuai, int ind, int a[][10], int number, int fenkuainum[])
{
	int flag = 0,j;
	for (j = 0; j < fenkuainum[ind]; j++)
	{
		if (a[ind][j] == number)
		{
			flag = 1;
			//return j;
			break;
		}
	}
	if (flag == 1)
	{
		return j;
	}
	else
	{
		printf("这个数不存在\n");
		return -1;
	}
}
int main()
{
	List L;
	L = NULL;
	int num, fenkuai;
	int fenkuainum[10];
	int ind, pos, number;
	printf("请输入顺序表的储存量\n");
	scanf("%d", &num);
	printf("请输入%d个数\n", num);
	L = creatSlist(num, L);
	printf("请输入要分成几块\n");
	scanf("%d", &fenkuai);
	printf("请输入每块要分成几个\n");
	for (int i = 0; i < fenkuai; i++)
	{
		scanf("%d", &fenkuainum[i]);
	}
	int a[10][10];
	creatindex(a, fenkuai, fenkuainum, L);
	printf("输出分块情况\n");
	printfindex(a, fenkuai, fenkuainum);
	findkey(index_table, a, fenkuainum, fenkuai);
	printf("请输入要查找的数字\n");
	scanf("%d", &number);
	ind = searchind(index_table, fenkuai, number);
	pos = searchpos(index_table, fenkuai, ind, a, number, fenkuainum);
	if (ind != -1 && pos != -1)
	{
		printf("该数位于第%d块第%d个\n", ind + 1, pos + 1);
	}
	printf("还要继续查找吗？是的话，输入1，不是的话输入0\n");
	int e;
	scanf("%d", &e);
	while ((e != 1) && (e != 0))
	{
		printf("输入不合法,请重新输入e\n");
		scanf("%d", &e);
	}//保证输入合法
	while (e == 1)
	{
		printf("请输入要查找的数字\n");
		scanf("%d", &number);
		ind = searchind(index_table, fenkuai, number);
		pos = searchpos(index_table, fenkuai, ind, a, number, fenkuainum);
		if (ind != -1 && pos != -1)
		{
			printf("该数位于第%d块第%d个", ind + 1, pos + 1);
		}
	}
	return 0;
}