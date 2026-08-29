#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head= NULL;
void enqueue(int value)
{
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	struct node *rear, *front,*temp;
	front=temp=head;
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
			temp->next=newnode;
			rear=newnode;
		}
		printf("Successfully inserted %d!",value);
	}
}
void display()
{
	struct node *temp=head;
	printf("Queue: ");
	if(head==NULL)
	{
		printf("Queue is empty!");
	}
	else
	{
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
	}
}

void dequeue()
{
	struct node *temp=head;
	if(head==NULL)
	{
		printf("Queue is empty! Dequeue is not possible!");
	}
	else
	{
		printf("Successfully dequeued %d",temp->data);
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
		printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter value to enqueue: ");
					scanf("%d",&value);
					enqueue(value);
					break;
			case 2: dequeue();
					break;
			case 3: display();
					break;
			case 4: printf("\nExiting... \n");
					return 0;
					break;
			default: printf("\nInvalid choice! Try again!");
		}
	}
}
