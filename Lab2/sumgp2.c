//method 2
#include<stdio.h>
int main()
{
	int n,x,i,sum=0,a=1;
	printf("Enter X value: ");
	scanf("%d",&x);
	printf("Enter number of elements: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		sum+=a;
		a*=x;
	}
	printf("Sum of the elements is %d",sum);
	return 0;
}
