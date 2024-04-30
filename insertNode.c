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

Node *append(Node *head, int item)
{
    Node *new_node = create_node(item, NULL);

    if (head == NULL)
    {
        return new_node;
    }

    Node *current_node = head;

    while (current_node->next != NULL)
    {
        current_node = current_node->next;
    };

    current_node->next = new_node;
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

void insert_node(Node *node, int item)
{
    Node *new_node = create_node(item, node->next);
    node->next = new_node;
}

int main()
{

    Node *n, *n2, *head;
    n = create_node(10, NULL);
    head = n;
    print_linked_list(head);

    head = prepend(head, 20);
    print_linked_list(head);

    head = append(head, 30);
    print_linked_list(head);

    insert_node(n, 40);
    print_linked_list(head);

    // n2 = head;
    // head = remove_node(head, n2);
    // print_linked_list(head);

    return 0;
}
