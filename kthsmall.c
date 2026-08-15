//method 1
#include<stdio.h>
int main()
{
	int n,k,i,j;
	printf("Enter number of elements: ");
	scanf("%d",&n);
	
	int a[n];
	printf("Enter elements: ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter k value: ");
	scanf("%d",&k);
	for(i=0;i<n;i++)
		for(j=0;j<i;j++)
		{
			if(a[j]>a[i])
			{
				a[i]=a[i]+a[j];
				a[j]=a[i]-a[j];
				a[i]=a[i]-a[j];
			}
		}
	printf("The Kth smallest element is %d",a[k-1]);
	return 0;
}
