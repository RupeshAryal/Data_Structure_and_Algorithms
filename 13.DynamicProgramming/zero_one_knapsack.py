
def zero_one_knapsack(profit, weight, max_capacity):

    table = [[0] * (max_capacity + 1) for _ in range(len(weight) + 1)]
    
    for i in range(0, len(profit) + 1):

        print(table[0], "\n", table[1], "\n", table[2], "\n", table[3], "\n", table[4], "\n", table[5], f"\n\nfinished iteration {i}")
    
    
        for w in range(0, max_capacity + 1):
            print(i,w)
            
            if i == 0 or w == 0:
                table[i][w] = 0
            else:
                if w - weight[i-1] < 0:
                    table[i][w] = table[i-1][w]
                else:
                    table[i][w] = max(table[i-1][w], table[i-1][w - weight[i-1]] + profit[i-1])

    return table

table = zero_one_knapsack([2,2,4,5,3], [3,1,3,4,2], 7)

print(table)