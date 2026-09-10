#include<stdio.h>

struct result
{
	int max;
	int min;
};

struct result minmax(int a[],int low, int high)
{
	struct result r, left, right;
	
	if(low==high)
	{
		r.max=r.min=a[low];
		return r;
	}
	if(high==low+1)
	{
		if(a[low]>a[high])
		{
			r.min=a[high];
			r.max=a[low];
		}
		else
		{
			r.min=a[low];
			r.max=a[high];
		}
		return r;
	}
	
	int mid=(low+high)/2;
	left=minmax(a,low,mid);
	right=minmax(a,mid,high);
	
	r.max= (left.max>right.max)?left.max:right.max;
	r.min= (left.min<right.min)?left.min:right.min;
	
	return r;
}

int main()
{
	int n,i;
	printf("Enter number of elements: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter array elements: ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	struct result r=minmax(a,0,n-1);
	printf("\nMaximum = %d\n",r.max);
	printf("Minimum = %d\n",r.min);
	
	return 0;
}
