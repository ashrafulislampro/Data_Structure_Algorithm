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

int count(Node *head)
{
    int counter = 0;
    Node *current_node = head;
    while (current_node != NULL)
    {
        counter++;
        current_node = current_node->next;
    }
    return counter;
}

Node *search(Node *head, int item, int *position)
{
    *position = 0;
    Node *current_node = head;
    while (current_node != NULL)
    {
        (*position)++;
        if (current_node->data == item)
        {
            return current_node;
        }
        current_node = current_node->next;
    }
    return NULL; // Item not found
}

int main()
{
    int position;
    Node *n, *search_item, *head;
    n = create_node(10, NULL);
    head = n;
    print_linked_list(head);

    head = prepend(head, 20);
    print_linked_list(head);

    head = append(head, 30);
    print_linked_list(head);

    int result = count(head);
    printf("Total Node = %d\n", result);

    search_item = search(head, 10, &position);
    if (search_item != NULL)
    {
        printf("Search Item = %d\n", search_item->data);
        printf("Position = %d\n", position);
    }
    else
    {
        printf("Item not found\n");
    }

    return 0;
}
