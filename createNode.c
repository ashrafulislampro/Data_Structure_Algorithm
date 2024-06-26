#include <stdio.h>
#include <stdlib.h>
#include <error.h>

typedef struct node Node;

struct node
{
    int data;
    Node *next;
};

Node *create_node(int item, Node *next)
{
    Node *new_node = (Node *)malloc(sizeof(Node));

    if (new_node == NULL)
    {
        printf("Error! Could not create A new node\n");
        exit(1);
    }

    new_node->data = item;
    new_node->next = next;

    return new_node;
}

Node *prepend(Node *head, int item)
{
    Node *new_node = create_node(item, head);
    return new_node;
}

Node *append(Node *head, int item){
    Node *new_node = create_node(item, NULL);

    if(head == NULL){
        return new_node;
    }


    Node *current_node = head;

    while(current_node->next != NULL){
        current_node = current_node->next;
};

current_node->next = new_node;
return head;
}

int main()
{
    Node *n, *n2, *n3, *head;
    n = create_node(10, NULL);
    head = n;
    head = prepend(head, 20);
    n2 = head;
    printf("first data = %d\n", n2->data);
    n3 = n2->next;
    printf("second data = %d\n", n3->data);

    return 0;
}