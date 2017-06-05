//Priority Queue Implementation : By Using The Linked List 
//Code Goes Here
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int priority;
	int info;
	struct node *link;
}*front=NULL;
void insert(int,int);
int del(void);
void display(void);
int main()
{
	int ch,item,pr;
	while(1)
	{
		printf("\n----\t\t Enter The Choice\n");
		printf("\tPress 1 For Insertion\n");
		printf("\tPress 2 For Deletion\n");
		printf("\tPress 3 For Display\n");
		printf("\tPress 4 To Exit\n");
		printf("---\t------------\t---------\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter The Item\n");
				scanf("%d",&item);
				printf("Enter Its Priority\n");
				scanf("%d",&pr);
				insert(item,pr);
				break;
				case 2:
					item=del();
					printf("Item Deleted = %d\n",item);
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
void insert(int item,int pr)
{
	struct node *tmp,*ptr,*q=NULL;
	tmp=(struct node *)malloc(sizeof(struct node));
	if(tmp==NULL)
	{
		printf("Memory Not Available\n");
		return ;
	}
	tmp->priority=pr;
	tmp->info=item;
	if((front==NULL) || (pr < front->priority))
	{
		tmp->link=front;
		front=tmp;
	}
	else
	{
		ptr=front;
		q=ptr;
		while(ptr && pr>ptr->priority)
		{
			q=ptr;
			ptr=ptr->link;
		}
		tmp->link=ptr;
		q->link=tmp;
	}
}
int del()
{
	int item;
	struct node *ptr;
	if(front==NULL)
	{
		printf("Underflow\n");
		exit(0);
	}
	ptr=front;
	front=front->link;
	item=ptr->info;
	free(ptr);
	return item;
}
void display()
{
	struct node *ptr;
	if(front==NULL)
	{
		printf("Queue is Empty\n");
		return ;
	}
	printf("\tPriority\tItems\n");
	ptr=front;
	while(ptr)
	{
		printf("\t%d\t\t%d\n",ptr->priority,ptr->info);
		ptr=ptr->link;
	}
}
