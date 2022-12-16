#include <stdio.h>
#include <stdlib.h>

int s[100];

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

void DFS(int i)
{
    printf("%d ", i);
    visited[i] = 1;
    for (int j = 0; j < 8; j++)
    {
        if (a[i][j] == 1 && !visited[j])
        {
            DFS(j);
        }
    }
}

void topological_Sort(int n, int a[][100])
{
    for (int i = 0; i < n; i++)
    {
        s[i] = 0;
    }
    int j = 0;
    for (int u = 0; u < n; u++)
    {
        if (s[u] == 0)
        {
            DFS(u);
        }
    }
    return;
}

int main()
{
    // DFS Implementation
    DFS(1);
    int n = 8;
    printf("\nTopological order:\n");

    topological_Sort(n, a);

    return 0;
}