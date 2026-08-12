#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void createList(int n) {
    struct node *newNode, *temp;
    int data, i;

    for(i = 1; i <= n; i++) {
        newNode = (struct node*)malloc(sizeof(struct node));
        if(newNode == NULL) {
            printf("Memory allocation failed!\n");
            return;
        }
		
		else
	{
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);

        newNode->data = data;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
        }
		else {
            temp = head;
            while(temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    }
    printf("Linked list created successfully!\n");
}

void inserte(){
	int value;
	struct node *newnode,*temp;
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("Enter value to insert");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=newnode;
	printf("\nNode Inserted at end successfully!");
}

void insertb()
{
	int value;
	struct node *newnode,*temp;
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("Enter value to insert: ");
	scanf("%d",&newnode->data);
	newnode->next=head;
	head=newnode;
	printf("\nNode Inserted at beginning successfully!");
}
void insertm(int pos)
{
	int value,i;
	struct node *newnode,*temp;
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("Enter value to insert: ");
	scanf("%d",&newnode->data);
	temp=head;
	while(temp!=NULL || i!=pos)
	{
		temp=temp->next;
		i++;
	}
	newnode->next=temp->next;
	temp->next=newnode;
}
void displayList() {
    struct node *temp = head;

    if(temp == NULL) {
        printf("List is empty!\n");
        return;
    }
	else{
    printf("Linked List:\n");
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
	}
}

int main() {
    int choice, n, value,pos;

    while(1){
        printf("\n----- MENU -----\n");
        printf("1. Create List\n");
        printf("2. Display List\n");
        printf("3.Inserte\n4.insertb\n5.insertm");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                createList(n);
                break;

            case 2:
                displayList();
                break;

            case 3:
                inserte();
                break;
                
            case 4: insertb();
            break;
            
            case 5: printf("position: ");
            scanf("%d",&pos);
			insertm(pos);
            break;

            case 6:
                printf("Exiting program...\n");
                return 0;
            
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } 
}

