#include<stdio.h>
#include<stdlib.h>
#define LEN sizeof(struct a)
#define LON sizeof(struct a*)
struct a
{
	int num;
	struct a*next;
};
int n;  //��nΪȫ����� �Ա�����main��ʹ��
struct a*creat(void)
{
	struct a*head;
	struct a*p1,*p2;
	n=0;
	p1=p2=(struct a*)malloc(LEN);
	scanf("%d",&p1->num);
	head=NULL;
	while(p1->num!=0)
	//����������Ϊ0��ʾ�������
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
	struct a**b; //��b����Ϊ��ŵ�ַ������
	int i;
	printf("Input 0 represents the end of the input\n");
	p=pt=creat();
	b=calloc(n,LON);
	for(i=0;p!=NULL;i++)
	{
		b[i]=p;
		p=p->next;
	}//��nextֵ����b������
	p=pt;
	for(i=2;i<n;i=i+2)
	{
		p->next=b[i];
		p=b[i];
	}//�����������н�������
	for(i=1;i<n;i=i+2)
	{
		p->next=b[i];
		p=b[i];
	}//ż�������н�������
	p->next=NULL;
	for(p=pt;p!=NULL;p=p->next)
	   {
	       printf("%d ",p->num);
	   }
	return 0;
}
