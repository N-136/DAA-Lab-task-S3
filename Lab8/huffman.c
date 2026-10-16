#include<stdio.h>
#include<stdlib.h>
#define max 100
struct node
{
	char ch;
	int fq;
	struct node *left, *right;
};

struct node *createnode(char ch, int fq)
{
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	newnode->ch=ch;
	newnode->fq=fq;
	newnode->left=NULL;
	newnode->right=NULL;
	
	return newnode;
}

int findmin(struct node *nodes[], int size)
{
	int min=0,i;
	for(i=0;i<size;i++)
	{
		if(nodes[i]->fq < nodes[min]->fq)
			min=i;
	}
	return min;
}

struct node *huffman(char chars[], int freq[], int n)
{
	int size=n,i;
	struct node *nodes[max];
	for(i=0;i<n;i++)
		nodes[i]= createnode(chars[i],freq[i]);
	
	while(size>1)
	{
		int j = findmin(nodes, size);
		struct node *left = nodes[j];
		nodes[j]=nodes[size-1];
		size--;
		
		int k = findmin(nodes, size);
		struct node *right = nodes[k];
		nodes[k] = nodes[size-1];
		size--;
		
		struct node *parent = createnode( '\0' , left->fq + right->fq);
		parent->left=left;
		parent->right=right;
		
		nodes[size++]=parent;
	}
	return nodes[0];	
}

void codes(struct node *root, int code[], int top)
{
	if(root->left)
	{
		code[top]=0;
		codes(root->left, code, top+1);
	}
	if(root->right)
	{
		code[top]=1;
		codes(root->right, code, top+1);
	}
	if(!root->left && !root->right)
	{
		printf("%c: ",root->ch);
		if(top==0)
			printf("0");
		int i;
		for(i=0;i<top;i++)
			printf("%d",code[i]);
		printf("\n");
	}
}

void freeTree(struct node *root)
{
    if (root == NULL)
        return;

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main()
{
	int n, freq[max], code[max];
	char chars[max];
	int i;
	printf("Enter number of characters: ");
	scanf("%d",&n);
	if(n<1 || n>max)
	{
		printf("Invalid number of characters!");
		return 1;
	}
	printf("Enter each character and its frequency (char, freq):\n");
	for(i=0;i<n;i++)
		scanf(" %c %d",&chars[i],&freq[i]);
		
	struct node *root = huffman(chars, freq, n);
	
	printf("\nHuffman Codes:\n");
	codes(root,code, 0);
	
	freeTree(root);
    return 0;
}
