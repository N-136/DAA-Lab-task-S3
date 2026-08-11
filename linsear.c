#include<stdio.h>
int main()
{
	int n;
	printf("Enter number of elements: ");
	scanf("%d",&n);
	int a[n],key,i;
	printf("Enter elements: ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter element to be searched: ");
	scanf("%d",&key);
	for(i=0;i<n;i++)
	{
		if(a[i]==key)
		{
			printf("Element found at index %d",i);
			return 0;
		}
	}
	printf("Element not found! Try Again!");
	return 0;
}
