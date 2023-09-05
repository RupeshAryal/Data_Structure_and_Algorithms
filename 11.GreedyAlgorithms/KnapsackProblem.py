#Greedy Algorithms is a algorithmic techniques to solve optimization problem.i.e those problems that requires finding the best solution among the sets of solution
#or finding the minimum or maximum cost solution


#Knapsack Problems

#you are given set of items and each item have associated weights and profits
#you have a knapsack with capacity W
#you have to fill the knapsack with object so as to maximize the profit and the total weight of selected object should 
#be less than that of capacity

#we will be looking at the variant of knapsack problem called the fractional knapsack where taking a fractions of items is allowed


def knapsack(objects, ks_capacity):
    #objects is a 2d array where each entry consists of associated weight and profit in 0th and 1st index respectivelly

    weight_remaining = ks_capacity
    final_list = []
    weight_profit = []

    #calculate unit profit for each object
    for item in objects:
        unit_profit = round(item[1]/item[0], 2)
        weight_profit.append(unit_profit)

    
    #continue until there's weight capacity and items available
    while weight_remaining > 0 and weight_profit:

        max_index = weight_profit.index(max(weight_profit))
        print('max_index', max_index, weight_profit)

        if objects[max_index][0] <= weight_remaining:
            final_list.append([max_index, 1.0])        
            weight_remaining -= objects[max_index][0]
            weight_profit[max_index] = 0

        else:
            carriable_weight = weight_remaining / objects[max_index][0]  
            final_list.append([max_index, carriable_weight])
            weight_remaining = 0

    return final_list


objects = [[2,10], [3,5], [5,15], [7,7], [1,6], [4,18], [1,3]]
knapsack_capacity = 15

selected_items = knapsack(objects, knapsack_capacity)

# Print the selected items and their fractions
for item in selected_items:
    index, fraction = item
    weight, profit = objects[index]
    print(f"Item {index + 1}: Fraction {fraction:.2f}, Weight {weight}, Profit {profit}")

# Calculate and print the total profit
total_profit = sum(objects[i][1] * fraction for i, fraction in selected_items)
print(f"Total Profit: {total_profit}")


        




    


