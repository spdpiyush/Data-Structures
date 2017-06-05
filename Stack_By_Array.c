//Implementing Stack using The Array
//Code Goes Here
#include<stdio.h>
#include<stdlib.h>
#define MAX 100  //Change MAX size From Here
int stack[MAX];
int top=-1;
void push(int);
int pop();
void display(void);
int main()
{
	int ch,item;
	while(1)
	{
		printf("Press 1 For The PUSH\n");
		printf("Press 2 For The POP\n");
		printf("Press 3 For The Display\n");
		printf("Press 4 To Exit\n");
		printf("Enter The Choice\n");
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
void push(int item)
{
	if(top==MAX-1)
	{
		printf("Overflow\n");
		return ;
	}
	stack[++top]=item;
}
int pop()
{
	int item;
	if(top==-1)
	{
		printf("Underflow\n");
		exit(0);
	}
	item=stack[top--];
	return item;
}
void display()
{
	int i=top;
	if(top==-1)
	{
		printf("Stack is Empty\n");
		return ;
	}
	printf("Items in The Stacks are :\n");
	while(i!=-1)
	{
		printf("%d\n",stack[i--]);
	}
	return ;
}
