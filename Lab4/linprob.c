//Linear probing
#include<stdio.h>
#define size 10
int hasht[size];

void initialize()
{
	int i;
	for(i=0;i<size;i++)
		hasht[i]=-1;
}
void insert(int key)
{
	int index = key%size;
	
	while(hasht[index]!=-1)
	{
		index = (index+1)%size;
	}
	hasht[index]=key;
}
void display()
{
	int i;
	printf("\nHash table:\n");
	for(i=0;i<size;i++)
	{
		if(hasht[i]==-1)
			printf("%d : Empty\n",i);
		else
			printf("%d : %d\n",i,hasht[i]);
	}
}
int main()
{
	int n,key,i;
	initialize();
	
	printf("Size of hash table = 10\n");
	printf("\nEnter number of elements: ");
	scanf("%d",&n);
	
	printf("\nEnter elements: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&key);
		insert(key);
	}
	
	display();
	return 0;
}
