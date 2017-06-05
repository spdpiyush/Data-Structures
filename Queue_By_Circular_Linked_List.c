//Queue Implementation Using Circular Linked List.
//Both Insertion and Deletion Takes Constant amount Of Time .(i.e O(1))
//Code Goes Here
#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *link;
}*p=NULL;
void insert(int);
void del(void);
void display(void);
int main()
{
	int ch,item;
	while(1)
	{
		printf("\t\tEnter Your Choice\n");
		printf("\tPress 1 For Insertion\n");
		printf("\tPress 2 For Deletion\n");
		printf("\tPress 3 For Display\n");
		printf("\tPress 4 Exit\n");
		printf("---------\t-----------\t------\n");
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
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=item;
	if(p == NULL)
	{
		tmp->link=tmp;
		p=tmp;
		return ;
	}
	tmp->link=p->link;
	p->link=tmp;
	p=tmp;
}
void del()
{
	int item;
	struct node *tmp;
	if(p==NULL)
	{
		printf("Queue is Empty\n");
		return ;
	}
	if(p->info == p->link->info)
	{
		item=p->info;
		tmp=p;
		p=NULL;
		printf("Item Deleted = %d\n",item);
		free(tmp);
		return ;
	}
	tmp=p->link;
	item=tmp->info;
	p->link=tmp->link;
	printf("Item Deleted = %d\n",item);
	free(tmp);
	return ;
}
void display()
{
	struct node *ptr;
	if(p==NULL)
	{
		printf("Queue is Empty\n");
		return ;
	}
	if(p->info == p->link->info)
	{
		printf("%d\n",p->info);
		return ;
	}
	ptr=p->link;
	while(ptr!=p)
	{
		printf("%d ",ptr->info);
		ptr=ptr->link;
	}
	printf("%d",ptr->info);
	printf("\n");
}
