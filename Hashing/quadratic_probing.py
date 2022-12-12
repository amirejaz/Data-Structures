def displayArray(arr, n):
    for i in range(n):
        print(arr[i], end=" ")


def hashing(table_hash, t_size, arr, N):

    for i in range(N):
        hash_func = arr[i] % t_size

        if(table_hash[hash_func] == -1):
            table_hash[hash_func] = arr[i]

        else:
            # if collision occurs
            for j in range(N):
                coll_func = (hash_func + j * j) % t_size

                if(table_hash[coll_func] == -1):
                    table_hash[coll_func] = arr[i]
                    break

    displayArray(table_hash, N)


if __name__ == "__main__":
    arr = [34, 82, 55, 27, 84, 23, 71, 66]
    N = 8
    S = 8  # size of hash_table

    hash_table = [0] * S

    for i in range(S):
        hash_table[i] = -1

    hashing(hash_table, S, arr, N)
