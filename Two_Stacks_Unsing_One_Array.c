//Implementation of Two Stacks By Using One Array
//Code Goes Here
#include<stdio.h>
#include<stdlib.h>
#define MAX 200  // Change The MAX to Change Stack Size.
int stack[MAX];
int top1=-1;
int top2=MAX;
void push1(int);
void push2(int);
int pop1();
int pop2();
void display();
int main()
{
	int ch,item;
	while(1)
	{
		printf("\t\tSelect The Choice\n");
		printf("\tPress 1 For PUSH in 1st Array\n");
		printf("\tPress 2 For PUSH in 2nd Array\n");
		printf("\tPress 3 For POP From 1st Array\n");
		printf("\tPress 4 For POP From 2nd Array\n");
		printf("\tPress 5 For Display The Stack\n");
		printf("\tPress 6 For Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter The Item to Be Inserted in 1st Array\n");
				scanf("%d",&item);
				push1(item);
				break;
				case 2:
					printf("Enter The Item to be Inserted in 2nd Array\n");
					scanf("%d",&item);
					push2(item);
					break;
					case 3:
						item=pop1();
						printf("Item Poped = %d From 1st Array\n",item);
						break;
						case 4:
							item=pop2();
							printf("Item Poped = %d From 2nd Array\n",item);
							break;
							case 5:
								display();
								break;
								case 6:
									exit(0);
									break;
									default:
										printf("Invalid Input\n");
										break;
		}
	}
	return 0;
}
void push1(int item)
{
	if(top1==top2-1)
	{
		printf("Overflow\n");
		return ;
	}
	stack[++top1]=item;
}
void push2(int item)
{
	if(top2 == top1+1)
	{
		printf("Overflow\n");
		return ;
	}
	stack[--top2]=item;
}
int pop1()
{
	int item;
	if(top1==-1)
	{
		printf("underflow\n");
		exit(0);
	}
	item=stack[top1--];
	return item;
}
int pop2()
{
	int item;
	if(top2 == MAX)
	{
		printf("Underflow\n");
		exit(0);
	}
	item=stack[top2++];
	return item;
}
void display()
{
	int tmp;
	if(top1==-1 && top2==MAX)
	{
		printf("Stack is Empty\n");
		exit(0);
	}
	printf("Items of Stack are :\n");
	tmp=top1;
	while(tmp!=-1)
	{
		printf("%d ",stack[tmp--]);
	}
	tmp=top2;
	while(tmp!=MAX)
	{
		printf("%d ",stack[tmp++]);
	}
	printf("\n");
}

