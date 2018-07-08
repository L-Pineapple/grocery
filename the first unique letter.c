#include<stdio.h>
int main()
{
	char a[100];
	int i,j,k=0;
	int c[100]={0};
scanf("Please enter less than 100 lowercase letters");
	scanf("%s",a);
	for(i=0;a[i]!='\0';i++)
	   {
	   	for(j=0;a[j]!='\0';j++)
	       if(a[i]==a[j])
	       k++;
	       c[i]=k;
	       k=0;
	   }
	for(i=0;c[i]!=0;i++)
	   if(c[i]==1)
	   {  printf("%d",i);
	   	break;           }
	   if(c[i]==0)
	   printf("-1");
	   return 0;
}
