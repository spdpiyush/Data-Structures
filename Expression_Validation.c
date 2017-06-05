//Expression Validation : By Using Stack
//Code Goes Here
#include<stdio.h>
#include<stdlib.h>
#define MAX 100 // Change The MAX Value From Here
char stack[MAX];
int top=-1;
void push(char);
char pop(void);
int match(char *);
int valid(char,char);
int main()
{
	char str[MAX];
	int ch;
	printf("Enter The Expression\n");
	scanf("%s",str);
	ch = match(str);
	if(ch == 1)
	printf("Valid Expression\n");
	else
	printf("Invalid Expression\n");
	return 0;
}
int match(char *str)
{
	int i,l,v;
	char tmp;
	i=0;
	l=0;
	while(*(str+i))
	{
		l++;
		i++;
	}
	for(i=0;i<l;i++)
	{
		if(*str == '[' || *str == '{' || *str == '(')
		push(*str);
		else if(*str==']' || *str=='}' || *str==')')
		{
			if(top == -1)
			{
				printf("Right Parenthesis are more than Left\n");
				return 0;
			}
			else
			{
				tmp=pop();
				v=valid(tmp,*str);
				if(v!=1)
				{
					printf("Mismatched Parenthesis : %c and %c\n",*str,tmp);
					return 0;
				}
			}
		}
		str++;
	}
	if(top == -1)
	return 1;
	else
	return 0;
}
int valid(char a,char b)
{
	if(a=='[' && b==']')
	return 1;
	else if(a=='{' && b=='}')
	return 1;
	else if(a=='(' && b==')')
	return 1;
	return 0;
}
void push(char a)
{
	stack[++top]=a;
}
char pop()
{
	char a;
	if(top==-1)
	{
		printf("Underflow\n");
		exit(0);
	}
	a=stack[top--];
	return a;
}
