//Doubly Linked List Implementation
//Code Goes Here
#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *prev;
	int info;
	struct node *next;
}*start=NULL;
void insert_at_beg(int);
void insert_at_end(int);
void insert_at_pos(int,int);
void insert_after(int,int);
void insert_before(int,int);
void del(int);
void reverse(void);
void display(void);
int main()
{
	int ch,item,pos,data;
	while(1)
	{
		printf("\t\tEnter Your Choice\n");
		printf("\tPress 1 To Insert at Beginning\n");
		printf("\tPress 2 To Insert at End\n");
		printf("\tPress 3 To Insert at Some Position\n");
		printf("\tPress 4 To Insert After\n");
		printf("\tPress 5 To Insert Before\n");
		printf("\tPress 6 To Delete\n");
		printf("\tPress 7 To Reverse\n");
		printf("\tPress 8 To Display\n");
		printf("\tPress 9 To Exit\n");
		printf("-------\t-------\t-------\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter The Item To Insert at Beginning\n");
				scanf("%d",&item);
				insert_at_beg(item);
				break;
				case 2:
					printf("Enter The Item To Insert at End\n");
					scanf("%d",&item);
					insert_at_end(item);
					break;
					case 3:
						printf("Enter The Item To Insert\n");
						scanf("%d",&item);
						printf("Enter The Position of Insertion\n");
						scanf("%d",&pos);
						insert_at_pos(item,pos);
						break;
						case 4:
							printf("Enter The Item To Insert\n");
						    scanf("%d",&item);
						    printf("Enter The Data after Which Insertion Takes\n");
							scanf("%d",&data);
							insert_after(item,data);
							break;
							case 5:
								printf("Enter The Item To Insert\n");
								scanf("%d",&item);
								printf("Enter The Data Before Which Insertion Takes\n");
								scanf("%d",&data);
								insert_before(item,data);
								break;
								case 6:
									printf("Enter The Item To Be Deleted\n");
									scanf("%d",&item);
									del(item);
									break;
									case 7:
										reverse();
										break;
										case 8:
											display();
											break;
											case 9:
												exit(0);
												break;
											    default:
													printf("Invalid Input\n");
													break;
		}
	}
	return 0;
}
void insert_at_beg(int item)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	if(tmp==NULL)
	{
		printf("Out Of Memory\n");
		return ;
	}
	tmp->info=item;
	if(start==NULL)
	{
		tmp->next=start;
		tmp->prev=NULL;
		start=tmp;
		return ;
	}
	tmp->prev=NULL;
	tmp->next=start;
	start->prev=tmp;
	start=tmp;
}
void insert_at_end(int item)
{
	struct node *tmp,*ptr;
	tmp=(struct node *)malloc(sizeof(struct node));
	if(tmp==NULL)
	{
		printf("Out Of Memory\n");
		return ;
	}
	tmp->info=item;
	if(start==NULL)
	{
		tmp->next=NULL;
		tmp->prev=NULL;
		start=tmp;
		return ;
	}
	ptr=start;
	while(ptr->next)	
	{
		ptr=ptr->link;
	}
	tmp->next=NULL;
	tmp->prev=ptr;
	ptr->next=tmp;
}
void insert_at_pos(int item,int pos)
{
	struct node *tmp,*p=start;
	int i;
	tmp=(struct node *)malloc(sizeof(struct node));
	if(tmp==NULL)
	{
		printf("Out of Memory\n");
		return ;
	}
	tmp->info=item;
	if(pos == 1)
	{
		tmp->next=start;
		tmp->prev=NULL;
		if(start!=NULL)
		start->prev=tmp;
		start=tmp;
		return ;
	}
	for(i=1;i<(pos-1) && p ;i++)
	{
		p=p->next;
	}
	if(!p)
	{
		printf("There are Less Elements Than %d\n",pos);
		return ;
	}
	else
	{
		
		tmp->link=p->link;
		p->link=tmp;
	}
}
void insert_after(int item,int data)
{
	struct node *tmp,*p;
	tmp=(struct node *)malloc(sizeof(struct node));
	if(tmp==NULL)
	{
		printf("Out of Memory\n");
		return ;
	}
	if(start == NULL)
	{
		printf("List is Empty\n");
		return ;
	}
	p=start;
	while(p)
	{
		if(p->info==data)
		{
			tmp->info=item;
			tmp->link=p->link;
			p->link=tmp;
			return ;
		}
		p=p->link;
	}
	printf("Data Which You Entered Doesn't Exist in The List\n");
}
void insert_before(int item,int data)
{
	struct node *tmp,*p;
	tmp=(struct node *)malloc(sizeof(struct node));
	if(tmp==NULL)
	{
		printf("Out of Memory\n");
		return ;
	}
	if(start==NULL)
	{
		printf("List  is Empty\n");
		return ;
	}
	if(start->info==data)
	{
		tmp->info=item;
		tmp->link=start;
		start=tmp;
		return ;
	}
	p=start;
	while(p->link)
	{
		if(p->link->info==data)
		{
			tmp->info=item;
			tmp->link=p->link;
			p->link=tmp;
			return ;
		}
		p=p->link;
	}
	printf("Entered Data Not Present in The List\n");
}
void del(int data)
{
	struct node *ptr,*tmp;
	int item;
	if(start==NULL)
	{
		printf("List is Empty\n");
		return ;
	}
	if(start->info==data)
	{
		ptr=start;
		start=start->link;
		item=ptr->info;
		printf("Item Deleted = %d\n",item);
		free(ptr);
		return ;
	}
	ptr=start;
	while(ptr->link)
	{
		if(ptr->link->info==data)
		{
			item=ptr->link->info;
			tmp=ptr->link;
			printf("Item Deleted = %d\n",item);
			ptr->link=ptr->link->link;
			free(tmp);
			return ;
		}
		ptr=ptr->link;
	}
	printf("Entered Data Doesn't Inside The List\n");
	return ;
}
void display()
{
	struct node *ptr;
	if(start==NULL)
	{
		printf("List is Empty\n");
		return ;
	}
	ptr=start;
	while(ptr)
	{
		printf("%d ",ptr->info);
		ptr=ptr->link;
	}
	printf("\n");
	return ;
}
void reverse()
{
	struct node *prev,*cur,*next;
	if(start==NULL)
	{
		printf("List is Empty\n");
		return ;
	}
	prev=NULL;
	cur=start;
	while(cur)
	{
		next=cur->link;
		cur->link=prev;
		prev=cur;
		cur=next;
		
	}
	start=prev;
}
