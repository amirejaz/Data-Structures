#include <stdio.h>

void showArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", arr[i]);
    }
}

void hashing(int table_hash[], int t_size, int arr[], int N)
{
    for (int i = 0; i < N; i++)
    {
        int hash_func = arr[i] % t_size;
        if (table_hash[hash_func] == -1)
        {
            table_hash[hash_func] = arr[i];
        }

        else
        {
            for (int j = 0; j < N; j++)
            {
                int coll_func = (hash_func + j * j) % t_size;
                if (table_hash[coll_func] == -1)
                {
                    table_hash[coll_func] = arr[i];
                    break;
                }
            }
        }
    }

    showArr(table_hash, N);
}

int main()
{
    int N = 8;
    int S = 8;
    int Arr[8] = {34, 82, 55, 27, 84, 23, 71, 66};

    int h_table[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < S; i++)
    {
        h_table[i] = -1;
    }

    hashing(h_table, S, Arr, N);
}