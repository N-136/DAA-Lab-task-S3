#include<stdio.h>
#define size 10
int hasht[size];
int freq[size];

void initialize()
{
	int i;
	for(i=0;i<size;i++)
	{
		hasht[i]=-1;
		freq[i]=0;
	}
}

int hash(int key)
{
	return (key%size +size)%size;
}

void insert(int key)
{
	int index = hash(key);
	
	while(hasht[index]!=-1 && hasht[index]!=key)
	{
		index = (index+1)%size;
	}
	
	if(hasht[index]==key)
		freq[index]++;
	else
	{
		hasht[index]=key;
		freq[index]=1;
	}
}

int main()
{
	int n,i;
	printf("Enter size of array: ");
	scanf("%d",&n);
	
	int a[n];
	printf("Enter array: ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	initialize();
	
	for(i=0;i<n;i++)
		insert(a[i]);
	
	printf("Element\tFrequency\n");
	for(i=0;i<size;i++)
	{
		if(hasht[i]!=-1)
			printf("%d\t%d\n",hasht[i],freq[i]);
	}
	
	return 0;
}
