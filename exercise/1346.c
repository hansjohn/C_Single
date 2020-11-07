#include <stdio.h>
typedef struct student
{
    int no;
    int yuwen;
    int shuxue;
    int yinyu;
    int zhongfen;
}student;
int main()
{
    int n;
    scanf("%d",&n);
    student s[n];
    int i;
    for(i=0;i<n;i++)
    {
        s[i].no=i+1;
        scanf("%d%d%d",&(s[i].yuwen),&(s[i].shuxue),&(s[i].yinyu));
        s[i].zhongfen=s[i].yuwen+s[i].shuxue+s[i].yinyu;
    }
    student temp;
    int  j;
    for (i=0; i<n-1; i++) /* 外循环为排序趟数，len个数进行len-1趟 */
        for (j=i; j<n-1; j++) { /* 内循环为每趟比较的次数，第i趟比较len-i次 */
            if (s[i].zhongfen <s[j+1].zhongfen) { /* 相邻元素比较，若逆序则交换（升序为左大于右，降序反之） */
                
                temp = s[i];
                s[i] = s[j+1];
                s[j+1] = temp;
            }
            else if(s[i].zhongfen ==s[j+1].zhongfen)
            {
                if(s[i].yuwen<s[j+1].yuwen)
                {
                    temp = s[i];
                    s[i] = s[j+1];
                    s[j+1] = temp;
                }
            }
        }
        for(i=0;i<5;i++)
        {
            printf("%d %d\n",s[i].no,s[i].zhongfen);
        }
        return 0;
}