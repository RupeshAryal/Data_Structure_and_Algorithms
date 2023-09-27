#given that you are a travller moving in a 2D grid starting from the top left cell,
#Find in how many ways you can reach the bottom right cell
#you can move only down or left.


memo = {}

def grid_traveller(total_rows, total_columns):

    if (total_rows, total_columns) in memo:
       return memo[(total_rows, total_columns)]

    if total_rows == 0 or total_columns == 0:
        return 0
    
    if (total_rows, total_columns) == (1, 1):
        return 1
    
    ways = grid_traveller(total_rows-1, total_columns) + grid_traveller(total_rows, total_columns - 1)
    memo[(total_rows, total_columns)] = ways
    return ways

print(grid_traveller(8,8))