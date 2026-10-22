#include<stdio.h>
#define inf 99999
int main()
{
	int n,i,j,k;
	int mat[10][10];
	printf("Enter number of vertices: ");
	scanf("%d",&n);
	printf("Enter adjacentry matrix (use %d for infinity):\n",inf);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&mat[i][j]);
	for(k=0;k<n;k++)
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				if(mat[i][k]!=inf && mat[k][j]!=inf && mat[i][j]>mat[i][k]+mat[k][j])
					mat[i][j]=mat[i][k]+mat[k][j];
			}
			
	printf("\nShortest path matrix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(mat[i][j]==inf)
				printf("INF ");
			else
				printf("%d ",mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}
