#include <stdio.h>
typedef struct index_table
{
    int key;
    int star;
    int size;
}Index_Table;

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

    return index;
}
void bubbleSort (int arr[], int len) {
    int temp;
    int i, j;
    for (i=0; i<len-1; i++) 
        for (j=0; j<len-1-i; j++) { 
            if (arr[j] > arr[j+1]) { 
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
}
 

void PrintList(Index_Table * index) 
{
	
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
    if (flag=0)
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
    bubbleSort (SList, SListSize);
    for (i=0;i<SListSize;i++)
    {
    	printf("%d ",SList[i]);
	}
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
    printf("enter a number you want to find.");
    scanf("%d",&num);
    FindIndex(num,index,SList,SListSize,block_num,block);
    return 0;
}
