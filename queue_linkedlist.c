#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *rear = NULL;
struct node *front = NULL;
int is_stack_empty()
{
    if ((rear == NULL) && (front == NULL))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enqueue(int element)
{
    // int x = is_stack_empty();
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = element;
    temp->next = NULL;
    if ((front == NULL) && (rear == NULL))
    {
        rear = front = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}
void print()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp = front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void dequeue()
{
    struct node *temp = front;
    if (front == rear)
    {
        return;
    }
    front = front->next;
    free(temp);
}
int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    dequeue();
    print();
    return 0;
}
