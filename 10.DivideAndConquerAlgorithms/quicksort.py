#implementing quick sort 

def partition(unsorted_list, low, high):
    pivot = unsorted_list[low]
    i = low + 1
    j = high

    while True:
        while i <= j and unsorted_list[i] <= pivot:
            i += 1
        while unsorted_list[j] >= pivot and j >= i:
            j -= 1
        if j <= i:
            break
        unsorted_list[i], unsorted_list[j] = unsorted_list[j], unsorted_list[i]

    unsorted_list[low], unsorted_list[j] = unsorted_list[j], unsorted_list[low]
    return j


def quicksort(unsorted_list, low, high):
    if(low <  high):
       j = partition(unsorted_list, low, high)
       quicksort(unsorted_list, low, j)
       quicksort(unsorted_list, j + 1, high)
    
    
array = [10,16,8,12,15,6,3,9,5]
quicksort(array, 0, len(array) - 1)
print(array)