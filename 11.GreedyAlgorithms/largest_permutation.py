# given a list on numbers 1 to N and total number of swap that can be made S
# find the largest permutation that can be formed with the given swap

#eg: given [1,2,3] and S = 1
#output: [3,2,1]


def highest_permutation(A, S):

    maxValue = len(A)
    print(maxValue)
    i = 0
    hash_table = { x:i for  i,x in enumerate(A)}
    print(hash_table)

    while S and i < len(A):
        j = hash_table[maxValue]

        if i == j:
            pass
        
        else:
            A[i], A[j] = A[j], A[i]
            hash_table[A[i]], hash_table[A[j]] = hash_table[A[j]], hash_table[A[i]]
            S -= 1

        i += 1
        maxValue -= 1

    return A

output = highest_permutation([4,3,2,1,5], 3)
print(output)        



