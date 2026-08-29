#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head= NULL;
void push(int value)
{
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	struct node *top=head;
	struct node *temp=head;
	if(newnode==NULL)
	{
		printf("Memory allocation failed!");
		return;
	}
	else
	{
		newnode->data=value;
		newnode->next=NULL;
		
		if(head==NULL)
		{
			head=newnode;
		}
		else
		{
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			newnode->next=top;
			head=newnode;
		}
		printf("Successfully pushed %d!",value);
	}
}
void display()
{
	struct node *temp=head;
	printf("Stack: \n");
	if(head==NULL)
	{
		printf("Stack is empty!");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("%d\n",temp->data);
			temp=temp->next;
		}
	}
}
void peek()
{
	struct node *top=head;
	if(head==NULL)
	{
		printf("Stack is empty!");
	}
	else
	{
		printf("Top is %d",top->data);
	}
}
void pop()
{
	struct node *temp=head;
	if(head==NULL)
	{
		printf("Stack is empty! POP operation not possible!");
	}
	else
	{
		printf("Successfully popped %d",temp->data);
		head=head->next;
		free(temp);
	}
}
int main()
{
	int n,value,i,choice;

	while(1)
	{
		printf("\n\n --- Menu --- \n");
		printf("1.PUSH\n2.POP\n3.Display\n4.Peek\n5.Exit\n");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter value to push: ");
					scanf("%d",&value);
					push(value);
					break;
			case 2: pop();
					break;
			case 3: display();
					break;
			case 4: peek();
					break;
			case 5: printf("\nExiting... \n");
					return 0;
					break;
			default: printf("\nInvalid choice! Try again!");
		}
	}
}
