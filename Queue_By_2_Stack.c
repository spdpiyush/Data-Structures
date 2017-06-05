//Queue Implementation By Using Two Stack
//Code Goes Here
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int stack1[MAX];
int stack2[MAX];
int top1=-1;
int top2=-1;
void insert(int);
void del(void);
void display(void);
int main()
{
	int ch,item;
	while(1)
	{
		printf("\t\tEnter The Choice\n");
		printf("\tPress 1 To Insert\n");
		printf("\tPress 2 To Delete\n");
		printf("\tPress 3 To Display\n");
		printf("\tPress 4 To Exit\n");
		printf("-----\t--------\t--------\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter The Item\n");
				scanf("%d",&item);
				insert(item);
				break;
				case 2:
					del();
					break;
					case 3:
						display();
						break;
						case 4:
							exit(0);
							break;
							default:
								printf("Invalid Input\n");
								break;
		}
	}
	return 0;
}
void insert(int item)
{
	if(top1==MAX-1)
	{
		printf("Overflow\n");
		return ;
	}
	stack1[++top1]=item;
}
void del()
{
	int item;
	if(top2 == -1)
	{
		if(top1==-1)
		{
			printf("Queue is Empty\n");
			return ;
		}
		else
		{
			while(top1!=-1)
			{
				stack2[++top2]=stack1[top1--];
			}
		}
	}
	item=stack2[top2--];
	printf("Item Deleted = %d\n",item);
	return ;
}
void display()
{
	int i;
	if(top1 == -1)
	{
		printf("Queue is Empty\n");
		return ;
	}
	while(top1!=-1)
	{
		stack2[++top2]=stack1[top1--];
	}
	i=top2;
	while(i!=-1)
	{
		printf("%d ",stack2[i--]);
	}
	printf("\n");
}
