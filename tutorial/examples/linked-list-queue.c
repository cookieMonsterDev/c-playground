#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    struct Node *prev;
    struct Node *next;
    int value;
} Node;

int size = 0;
Node *head = NULL;
Node *tail = NULL;

void enqueue(int value)
{

    Node *node = (Node *)malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    node->prev = NULL;

    if (size <= 0)
    {
        head = node;
        tail = node;
    }
    else
    {
        node->prev = tail;
        tail->next = node;
        tail = node;
    }
    size++;
}

int dequeue()
{
    if (!head)
        exit(1);

    Node *node = head;

    int value = node->value;

    head = head->next;

    if (head)
    {
        head->prev = NULL
    }
    else
    {
        tail = NULL;
    }

    size--;
    free(node);

    return value;
}

void printQueue()
{
    Node *node = head;
    while (node)
    {
        printf("node - %d\n", node->value);
        node = node->next;
    }
    printf("End\n");
}

int main()
{

    // Filling Queue
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);

    // Print
    printQueue();

    // Get items
    int fist = dequeue();
    int second = dequeue();

    printf("First: %d\n", fist);
    printf("Second: %d\n", second);

    // Print
    printQueue();

    return 0;
}