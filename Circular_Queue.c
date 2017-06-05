//Circular Queue Implemetation
//Code Goes Here
#include<stdio.h>
#include<stdlib.h>
#define MAX 200
int cir_queue[MAX];
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
		printf("\t\tSelect The Choice\n");
		printf("\tPress 1 For Insertion\n");
		printf("\tPress 2 For Deletion\n");
		printf("\tPress 3 For Display\n");
		printf("\tPress 4 To Exit\n");
		printf("-------\t-----------\t----------\n");
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
	if((front == 0 && rear==MAX-1) || (front==rear+1))
	{
		printf("Overflow\n");
		return ;
	}
	if(front==-1)
	front=0;
	if(rear==MAX-1)
	rear=0;
	else
	rear+=1;
	cir_queue[rear]=item;
}
int del()
{
	int item;
	if((front==-1))
	{
		printf("Overflow\n");
		exit(0);
	}
	item=cir_queue[front];
	if(front==rear)
	{
		front=-1;
		rear=-1;
	}
	else if(front==MAX-1)
	front=0;
	else
	front+=1;
	return item;
}
void display()
{
	int i;
	if((front==-1))
	{
		printf("Circular Queue is Empty\n");
		return ;
	}
	printf("Items of Circular Queue are :\n");
	i=front;
	if(front<=rear)
	{
		while(i<=rear)
		printf("%d ",cir_queue[i++]);
	}
	else
	{
		while(i<MAX)
		printf("%d ",cir_queue[i++]);
		i=0;
		while(i<=rear)
		printf("%d ",cir_queue[i++]);
	}
	printf("\n");
}
