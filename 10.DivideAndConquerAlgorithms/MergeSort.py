def divide(Array):
    length = len(Array) // 2
    return Array[0:length], Array[length:]

def conquer(first_array, second_array):
    final_list = []
    i = 0
    j = 0

    while i <= len(first_array) - 1 and j <= len(second_array) - 1:
        if first_array[i] <= second_array[j]:
            final_list.append(first_array[i])
            i += 1
        else:
            final_list.append(second_array[j])
            j += 1

    while i < len(first_array):
        final_list.append(first_array[i])
        i += 1
    
    while j < len(second_array):
        final_list.append(second_array[j])
        j += 1

    return final_list


def Merge_Sort(Array):
    if len(Array) <= 1:
        return Array

    left_array, right_array = divide(Array)
    left = Merge_Sort(left_array)
    right = Merge_Sort(right_array)
    return conquer(left, right)

our_list = [4,5,3,6,3,1,2,9,6,4]
final_list = Merge_Sort(our_list)
print(final_list)