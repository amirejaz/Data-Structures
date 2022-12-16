#include <stdio.h>
#include <stdlib.h>

void adjencyMatrix(int arr[][100], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            arr[i][j] = 0;
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            arr[i][j] = rand() % 2;
            arr[j][i] = 0;
        }
    }
}

int main()
{
    int arr[100][100];
    int n;
    printf("Enter number of vertices\n");
    scanf("%d", &n);

    printf("Adjency Matrix of a graph is: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("\t%d", arr[i][j]);
        }
        printf("\n");
    }
}