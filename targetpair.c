#include<stdio.h>
#define size 10
int hasht[size];
void initialize()
{
	int i;
	for(i=0;i<size;i++)
		hasht[i]=-1;
}
int hash(int key)
{
	return (key%size + size)%size;
}
int search(int key)
{
	int index = hash(key);
	while(hasht[index]!=-1)
	{
		if(hasht[index]==key)
			return 1;
		index=(index+1)%size;
	}
	return 0;
}
void insert(int key)
{
	int index=hash(key);
	while(hasht[index]!=-1)
		index=(index+1)%size;
	hasht[index]=key;
}
int main()
{
	int a[]={2,5,7,14,23};
	int n=5,T;
	printf("Enter target value: ");
	scanf("%d",&T);
	int i,need;
	
	initialize();
	
	for(i=0;i<n;i++)
	{
		need= T-a[i];
		if(search(need))
		{
			printf("Pair found: %d + %d = %d", need, a[i], T);
			return 0;
		}
		insert(a[i]);
	}
	printf("Pair does not exist");
	return 0;
}
