#include <stdio.h>
#include <stdlib.h>

void showArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void hashing(int hash_table[], int t_size, int arr[], int N)
{
    for (int i = 0; i < N; i++)
    {
        int hash_func = arr[i] % t_size;
        if (hash_table[hash_func] == -1)
        {
            hash_table[hash_func] = arr[i];
        }
        else
        {
            // if collision occurs
            for (int j = 0; j < N; j++)
            {
                int coll_func = (hash_func + j) % t_size;
                if (hash_table[coll_func] == -1)
                {
                    hash_table[coll_func] = arr[i];
                    break;
                }
            }
        }
    }

    showArr(hash_table, N);
}

int main()
{
    int arr[6] = {7, 2, 8, 25, 16, 17};
    int n = 6;
    int s = 6;

    int h_table[6] = {0, 0, 0, 0, 0, 0};

    for (int i = 0; i < s; i++)
    {
        h_table[i] = -1;
    }

    hashing(h_table, s, arr, n);
}