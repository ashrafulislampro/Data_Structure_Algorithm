#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <error.h>

typedef struct node Node;

struct node
{
    int data;
    Node *next;
    Node *prev;
};

Node *create_node(int item, Node *next, Node *prev)
{
    Node *new_node = (Node *)malloc(sizeof(Node));

    if (new_node == NULL)
    {
        printf("Error! Could Not create a new node\n");
        exit(1);
    }

    new_node->data = item;
    new_node->next = next;
    new_node->prev = prev;

    return new_node;
}

Node *prepend(Node *head, int item)
{
    Node *new_node = create_node(item, head, NULL);
    new_node->next->prev = new_node;
    return new_node;
}

Node *append(Node *head, int item)
{
    Node *new_node = create_node(item, NULL, NULL);
    if (head == NULL)
    {
        return new_node;
    }
    Node *current_node = head;

    while (current_node->next != NULL)
    {
        current_node = current_node->next;
    }

    current_node->next = new_node;
    new_node->prev = current_node;

    return head;
};

Node *remove_node(Node *head, Node *node)
{
    if (node == head)
    {
        head = node->next;
        head->prev = NULL;
        free(node);
        return head;
    }

    Node *previous_node = node->prev;
    Node *next_node = node->next;

    previous_node->next = next_node;
    next_node->prev = previous_node;

    free(node);
    return head;
}

void print_linked_list(Node *head)
{
    Node *current_node = head;
    while (current_node != NULL)
    {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
};

int main()
{
    int position;
    Node *n, *search_item, *head;
    n = create_node(10, NULL, NULL);
    head = n;
    print_linked_list(head);

    head = prepend(head, 20);
    print_linked_list(head);

    head = append(head, 30);
    print_linked_list(head);

    return 0;
}