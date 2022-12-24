#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int F;
    int R;
    int *arr;
};

int isFull(struct queue *q)
{
    if (q->R == q->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct queue *q)
{
    if (q->R == q->F)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue Overflow");
    }
    else
    {
        q->R++;
        q->arr[q->R] = val;
    }
}

int dequeue(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue Underflow");
    }
    else
    {
        q->F++;
        return q->arr[q->F];
    }
}

int main()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 30;
    q->F = q->R = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    enqueue(q, 12);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);

    if (isEmpty(q))
    {
        printf("Queue is empty");
    }

    printf("dequeue element: %d\n", dequeue(q));
    printf("dequeue element: %d\n", dequeue(q));
    printf("dequeue element: %d\n", dequeue(q));
    printf("dequeue element: %d\n", dequeue(q));

    if (isEmpty(q))
    {
        printf("Queue is empty");
    }
}