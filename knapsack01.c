//Tabulation method
//Time Complexity = O(nm)
#include<stdio.h>
int main()
{
	int n,i,w,m;
	printf("Enter number of items: ");
	scanf("%d",&n);
	printf("Enter capacity: ");
	scanf("%d",&m);
	
	int v[n+1][m+1],wt[n],p[n];
	printf("Enter item weights:\n");
	for(i=0;i<n;i++)
		scanf("%d",&wt[i]);
	printf("Enter item profits:\n");
	for(i=0;i<n;i++)
		scanf("%d",&p[i]);
	
	for(i=0;i<=m;i++)
		v[0][i]=0;
	for(i=0;i<=n;i++)
		v[i][0]=0;
	
	for(i=1;i<=n;i++)
	{
		for(w=0;w<=m;w++)
		{
			if(wt[i-1] <= w)
			{
    			if(v[i-1][w-wt[i-1]] + p[i-1] > v[i-1][w])
        			v[i][w] = v[i-1][w-wt[i-1]] + p[i-1];
    			else
        			v[i][w] = v[i-1][w];
			}
			else
    			v[i][w] = v[i-1][w];
		}
	}
	printf("Total profit = %d",v[n][m]);
	return 0;
}
