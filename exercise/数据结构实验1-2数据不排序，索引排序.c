#include <stdio.h>
typedef struct index_table
{
    int key;
    int star;
    int size;
}Index_Table;
void bubbleSort (Index_Table *index, int block_num) {
    Index_Table temp;
    int i, j;
    for (i=0; i<block_num-1; i++) 
        for (j=0; j<block_num-1-i; j++) { 
            if ( index[j].key > index[j+1].key) { 
                temp = index[j];
                index[j] = index[j+1];
                index[j+1] = temp;
            }
        }
}
Index_Table* CreatIndex(int *SList,int SListSize,int block_num,int *block,Index_Table * index)
{
    int i,j,k,temp;
    Index_Table tempindex;
    for(i=0,k=0;i<block_num;i++)
    {
        index[i].star=k;
        for(j=0,(index[i]).size=block[i];j<block[i];j++,k++)
        {
            
            if(j==0){(index[i]).key=SList[k];}
            else if((index[i]).key<SList[k])
            {
                (index[i]).key=SList[k];
            }

        }
        
    }
    //对索引表进行排序
    bubbleSort(index,block_num);

    return index;
}

 

void PrintList(Index_Table * index,int block_num,int block[]) 
{
    int i=0,j=0;
	for(;i<block_num;i++)
    {
        printf("key=%d ,start at %d,size is %d\n",
            index[i].key,index[i].star,index[i].size);
    }
}
void FindIndex(int num,Index_Table * index,int *SList,int SListSize,int block_num,int *block)
{
    int i,j ,k,flag=0;
    for(i=0;i<block_num;i++)
    {
        if(num<=(index[i]).key)
        {
            for(j=0,k=(index[i]).star;j<(index[i]).size;j++)
            {
                if(SList[k]==num)
                {
                    printf("%d is the %dth number\n",num,k+1);
                    return;
                    flag=1;
                }
                k++;
            }
        }
    }
    if (flag==0)
    {
        printf("no this number\n");
    }
}
int main()
{
    int SListSize;
    int block_num;
    int num;
    
    printf("Please select the amount of data you want to create:");
    scanf("%d",&SListSize);
    printf("Please enter %d numbers:",SListSize);
    int SList[SListSize];
	int i=0; 
    for(;i<SListSize;i++)
    {
        scanf("%d",&SList[i]);

    }
    getchar();

	printf("\n");
    printf("Enter the number of blocks you want to divide:");
    scanf("%d",&block_num);
    int block[block_num];
    
    printf("Enter how many values each block has:");
    for(i=0;i<block_num;i++)
    {
        scanf("%d",&block[i]);
    }
    getchar();
    Index_Table index[block_num];
    CreatIndex(SList,SListSize,block_num,block,index);

    printf("the index is:\n");
    PrintList(index,block_num,block);
    printf("enter a number you want to find.");
    scanf("%d",&num);
    FindIndex(num,index,SList,SListSize,block_num,block);
    return 0;
}
