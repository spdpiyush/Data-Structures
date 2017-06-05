//Implemenatation of Queue By Using Array
//Code Goes Here
#include<stdio.h>
#include<stdlib.h>
#define MAX 200 // Change MAX to Change The Array size.
int queue[MAX];
int front=-1;
int rear=-1;
void insert(int);
int del(void);
void display();
int main()
{
	int ch,item;
	while(1)
	{
		printf("\t\t Select The Choice\n");
		printf("\tPress 1 For Insertion\n");
		printf("\tPress 2 For Deletion\n");
		printf("\tPress 3 For Display\n");
		printf("\tPress 4 To Exit\n");
		printf("-------\t--------\t-------\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter The Item\n");
				scanf("%d",&item);
				insert(item);
				break;
				case 2:
					item=del();
					printf("\tItem Deleted = %d\n",item);
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
	if(rear==MAX-1)
	{
		printf("Overflow\n");
		return ;
	}
	if(front=-1)
	front=0;
	queue[++rear]=item;
}
int del()
{
	int item;
	if(front==-1 || front==rear+1)
	{
		printf("Underflow\n");
		exit(0);
	}
	item=queue[front++];
	return item;
}
void display()
{
	int i;
	if(front==-1 || front==rear+1)
	{
		printf("Queue is Empty\n");
		return ;
	}
	printf("Queue Items are : \n");
	for(i=front;i<=rear;i++)
	{
		printf("%d ",queue[i]);
	}
	printf("\n");
}
