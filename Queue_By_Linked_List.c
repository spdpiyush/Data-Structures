//Queue Implementation By Using Linked List
//Code Goes Here
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *link;
}*front=NULL,*rear=NULL;
void insert(int);
int del(void);
void display(void);
int main()
{
	int ch,item;
	while(1)
	{
		printf("\t\tSelect The Choice\n");
		printf("\tPress 1 For Insertion\n");
		printf("\tPress 2 For Deletion\n");
		printf("\tPress 3 For Display\n");
		printf("\tPress 4 To Exit\n");
		printf("----\t------\t----\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter The Item To Be Inserted\n");
				scanf("%d",&item);
				insert(item);
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
void insert(int item)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	if(tmp==NULL)
	{
		printf("Oveflow\n");
		return ;
	}
	tmp->info=item;
	tmp->link=NULL;
	if(front==NULL)
	front=tmp;
	else
	rear->link=tmp;
	rear=tmp;
}
int del()
{
	int item;
	struct node *tmp;
	if(front==NULL)
	{
		printf("Underflow\n");
		exit(0);
	}
	tmp=front;
	front=front->link;
	item=tmp->info;
	free(tmp);
	return item;
}
void display()
{
	struct node *tmp;
	if(front==NULL)
	{
		printf("Queue is Empty\n");
		return ;
	}
	tmp=front;
	printf("Queue Items are :\n");
	while(tmp)
	{
		printf("%d ",tmp->info);
		tmp=tmp->link;
	}
	printf("\n");
}
