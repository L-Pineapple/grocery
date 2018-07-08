#include<stdio.h>
#include<stdlib.h>
#define LEN sizeof(struct a)
#define LON sizeof(struct a*)
struct a
{
	int num;
	struct a*next;
};
int n;  //设n为全体变量 以便于在main中使用
struct a*creat(void)
{
	struct a*head;
	struct a*p1,*p2;
	n=0;
	p1=p2=(struct a*)malloc(LEN);
	scanf("%d",&p1->num);
	head=NULL;
	while(p1->num!=0)
	//当输入数据为0表示输入结束
	{
		n=n+1;
		if(n==1)head=p1;
		else p2->next=p1;
		p2=p1;
		p1=(struct a*)malloc(LEN);
		scanf("%d",&p1->num);
	}
	p2=NULL;
	return(head);
}
int main()
{
	struct a*pt,*p;
	struct a**b; //设b数组为存放地址的数组
	int i;
	printf("Input 0 represents the end of the input\n");
	p=pt=creat();
	b=calloc(n,LON);
	for(i=0;p!=NULL;i++)
	{
		b[i]=p;
		p=p->next;
	}//把next值存入b数组中
	p=pt;
	for(i=2;i<n;i=i+2)
	{
		p->next=b[i];
		p=b[i];
	}//奇数项先排列进新链表
	for(i=1;i<n;i=i+2)
	{
		p->next=b[i];
		p=b[i];
	}//偶数项排列进新链表
	p->next=NULL;
	for(p=pt;p!=NULL;p=p->next)
	   {
	       printf("%d ",p->num);
	   }
	return 0;
}
