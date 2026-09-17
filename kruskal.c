#include<stdio.h>

struct edge
{
	int u,v,w;
};
int group[20];

int find(int x)
{
	while(group[x]!=x)
		x=group[x];
	
	return x;
}
void combine(int a, int b)
{
	group[a]=b;
}
int main()
{
	struct edge e[20], temp;
	int n,m,u,v,w,count=0,sum=0;
	int i,j;
	printf("Enter number of vertices: ");
	scanf("%d",&n);
	printf("Enter number of edges: ");
	scanf("%d",&m);
	printf("\nEnter edges (u v weight):\n");
	for(i=0; i<m; i++)
		scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].w);
	for(i=0; i<m; i++)
		for(j=0; j<i; j++)
			if(e[i].w < e[j].w)
			{
				temp = e[i];
				e[i] = e[j];
				e[j] = temp;
			}
	
	for(i=0;i<n;i++)
		group[i]=i;
	
	printf("\nEdges of MST:\n");
	for(i=0;i<m && count<=n-1;i++)
	{
		int a=find(e[i].u);
		int b=find(e[i].v);
		if(a!=b)
		{
			printf("%d - %d: %d\n",e[i].u,e[i].v,e[i].w);
			sum += e[i].w;
			count++;
			combine(a,b);
		}
	}
	
	printf("\nMinimum cost = %d", sum);
	return 0;
}
