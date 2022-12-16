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
    int a = -1;
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
    q->size = 350;
    q->F = q->R = 0;
    q->arr = (int *)malloc(q->size * sizeof(int));

    // BFS Implementation
    int i = 0;
    int visited[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    int a[8][8] = {
        {0, 1, 1, 1, 0, 0, 0, 0},
        {1, 0, 0, 0, 1, 1, 0, 0},
        {1, 0, 0, 0, 0, 0, 1, 0},
        {1, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 0, 0, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 0, 0, 1},
        {0, 0, 1, 0, 0, 0, 0, 1},
        {0, 0, 0, 1, 1, 1, 1, 0}};

    printf("%d", i);
    visited[i] = 1;
    enqueue(q, i);
    while (!isEmpty(q))
    {
        int node = dequeue(q);
        for (int j = 0; j < 8; j++)
        {
            if (a[node][j] == 1 && visited[j] == 0)
            {
                printf("%d", j);
                visited[j] = 1;
                enqueue(q, j);
            }
        }
    }

    return 0;
}