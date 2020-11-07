#include <stdio.h>
#include <string.h>
#define N 50 
int main() 
{
int len,num,i;
double total=0;
char name[N];
char s[N],s1[N],s2[N];
gets(name);
printf("        #1 MT Takeaway\n\n") ;
len=strlen(name) ;
if(len%2==0)
	{
		for(i=0;i<(28-len)/2;i++)
		printf("-");
		printf(" %s ",name);
		for(i=0;i<(28-len)/2;i++)
		printf("-");
		printf("\n");
	}
	else {
		for(i=0;i<(27-len)/2;i++)
		printf("-"); 
		printf(" %s ",name); 
		for(i=0;i<(29-len)/2;i++)
		printf("-");
		printf("\n");
	} 

while(scanf("%s", s) !=EOF) 
{
	if(s[0]=='F')
{
	scanf("%s%s%d",s1,s2,&num) ;
	total +=num*7.0;
	printf("Fried beef pepper   x%-2d%5.1f\n", num, num*7.0);}
else if(s[0]=='L') 
{
	scanf("%s%s%d",s1,s2,&num);
	total+=num*4.0;
	printf("Lotus root soup     x%-2d%5.1f\n",num, num*4.0) ;}
else if(s[0]=='D') 
{
	scanf("%s%s%d",s1,s2,&num);
	total+=num*3.0;
	printf("Dried bean curd     x%-2d%5.1f\n",num,num*3.0);}
else if(s[0] =='P') 
{
	scanf("%d",&num);
	total+=num*2.5;
	printf("Potato              x%-2d%5.1f\n", num, num*2.5) ;}
else if(s[0]=='S') 
{	
	scanf("%s%d",s1,&num) ;
	total+=num*2.5;
	printf("Sauteed lettuce     x%-2d%5.1f\n" ,num, num*2.5) ;}
else if(s[0] =='R') 
{
	scanf("%d", &num);
	total+=num*1.0;
	printf("Rice                x%-2d%5.1f\n", num, num*1.0) ;}
}
	total+=4;
	printf("Delivery fees: 4\n------------------------------\n");
	printf("                Total:%6.1f",total) ;
	return 0;
}