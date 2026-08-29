#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int item)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node* node, int value)
{
    if (node == NULL)
        return newNode(value);

    if (value < node->data)
        node->left = insert(node->left, value);
    else if (value > node->data)
        node->right = insert(node->right, value);

    return node;
}

struct node* minValueNode(struct node* node)
{
    struct node* current = node;

    while (current != NULL && current->left != NULL)
        current = current->left;

    return current;
}

struct node* deleteNode(struct node* root, int value)
{
    if (root == NULL)
        return root;

    if (value < root->data)
        root->left = deleteNode(root->left, value);

    else if (value > root->data)
        root->right = deleteNode(root->right, value);

    else
    {
        if (root->left == NULL)
        {
            struct node* temp = root->right;
            free(root);
            return temp;
        }

        else if (root->right == NULL)
        {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = minValueNode(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void inorder(struct node* root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d -> ", root->data);
    inorder(root->right);
}

int main()
{
    struct node* root = NULL;

    root = insert(root, 50);
    root = insert(root, 12);
    root = insert(root, 34);
    root = insert(root, 67);
    root = insert(root, 56);
    root = insert(root, 78);
    root = insert(root, 13);

    printf("\nInorder traversal before deletion:\n");
    inorder(root);

    root = deleteNode(root, 50);

    printf("\n\nInorder traversal after deleting 50:\n");
    inorder(root);

    return 0;
}
