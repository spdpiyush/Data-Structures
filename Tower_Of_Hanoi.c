//Tower Of Hanoi
#include<stdio.h>
void toh(int,char,char,char);
int main()
{
	int no;
	char s='A',temp='B',d='C';
	printf("Enter The Number of The Disk \n");
	scanf("%d",&no);
	printf("Sequence is :\n");
	toh(no,s,temp,d);
	return 0;
}
void toh(int no,char s,char t,char d)
{
	if(no==1)
	{
		printf("Move %d disk from %c to %c\n",no,s,d);
		return ;
	}
	toh(no-1,s,d,t);
	printf("Move %d disk From %c to %c\n",no,s,d);
	toh(no-1,t,s,d);
}
