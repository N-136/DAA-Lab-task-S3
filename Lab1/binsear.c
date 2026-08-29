#include<stdio.h>
int main()
{
	int n;
	printf("Enter number of elements: ");
	scanf("%d",&n);
	int a[n],key,i,j;
	printf("Enter elements: ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
		for(j=0;j<i;j++)
			if(a[j]>a[i])
			{
				a[i]=a[i]+a[j];
				a[j]=a[i]-a[j];
				a[i]=a[i]-a[j];
			}
	printf("Sorted array: ");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\nEnter element to be searched: ");
	scanf("%d",&key);
	
	int beg,end,mid;
	beg=0;
	end=n-1;
	mid=(beg+end)/2;
	while(beg<=end)
	{
		if(key==a[mid])
		{
			printf("Element found at index %d",mid);
			return 0;
		}
		if(key<a[mid])
			end=mid-1;
		if(key>a[mid])
			beg=mid+1;
		mid=(beg+end)/2;
	}
	printf("Element not found! Try Again!");
	return 0;
}
