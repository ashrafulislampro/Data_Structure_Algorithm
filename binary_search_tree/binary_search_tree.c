#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node Node;

struct node
{
    int data;
    Node *parent;
    Node *left;
    Node *right;
};

Node *create_node(int item)
{
    Node *new_node = (Node *)malloc(sizeof(Node));

    if (new_node == NULL)
    {
        printf("Error! Could not create a new Node\n");
        exit(1);
    }

    new_node->data = item;
    new_node->parent = NULL;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

void add_left_child(Node *node, Node *child)
{
    node->left = child;

    if (child != NULL)
    {
        child->parent = node;
    }
}

void add_right_child(Node *node, Node *child)
{
    node->right = child;
    if (child != NULL)
    {
        child->parent = node;
    }
}

int main()
{

    return 0;
}