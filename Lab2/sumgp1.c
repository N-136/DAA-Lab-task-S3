//method 1
#include<stdio.h>
#include<math.h>
int main()
{
	int x,n,sum;
	printf("Enter X value: ");
	scanf("%d",&x);
	printf("Enter number of elements: ");
	scanf("%d",&n);
	
	sum=(pow(x,n)-1)/(x-1);
	printf("Sum of the elements is %d",sum);
	return 0;
}
