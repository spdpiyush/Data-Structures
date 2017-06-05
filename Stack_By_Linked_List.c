//Stack Implementation Using The Linked List.
//Code Goes Here
#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int info;
	struct node *link;
}*top=NULL;
void push(int);
int pop(void);
void display(void);
int main()
{
	int ch,item;
	while(1)
	{
		printf("Press 1 For PUSH\n");
		printf("Press 2 For POP\n");
		printf("Press 3 For Display\n");
		printf("Press 4 For Exit\n");
		printf("Enter Your Choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter The Item to Be Inserted\n");
				scanf("%d",&item);
				push(item);
				break;
				case 2:
					item=pop();
					printf("Item Poped = %d\n",item);
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
void push(int item)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	if(tmp==NULL)
	{
		printf("Overflow\n");
		return ;
	}
	tmp->info=item;
	tmp->link=top;
	top=tmp;
}
int pop()
{
	int item;
	struct node *tmp;
	if(top==NULL)
	{
		printf("Underflow\n");
		exit(0);
	}
	item=top->info;
	tmp=top;
	top=top->link;
	free(tmp);
	return item;
}
void display()
{
	struct node *tmp;
	tmp=top;
	if(top==NULL)
	{
		printf("Stack is Empty\n");
		return ;
	}
	printf("Items in The Stack are :\n");
	while(tmp)
	{
		printf("%d\n",tmp->info);
		tmp=tmp->link;
	}
	return ;
}
