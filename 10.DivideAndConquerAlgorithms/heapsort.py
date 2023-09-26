def create_heap(A):
    temp = [A[0]]
    heap_size = 1  
    for i in A[1:]:

        temp.append(i)
        current_index = heap_size #get the current index of the inserted element 

        while current_index > 0:
            parent = (current_index + 1) // 2 - 1
            if i > temp[parent]:
                temp[current_index], temp[parent] = temp[parent], temp[current_index]
                current_index = parent
            else:
                break
        heap_size += 1 #increase the heap size when an element is inserted
    return temp

def heap_sort(A):
    """
    Takes an array and returns the sorted list.
    """
    heap = create_heap(A)
    heap_size = len(heap)

    while heap_size > 0:
        last_index = heap_size - 1
        heap[0], heap[last_index] = heap[last_index], heap[0]

        heap_size -= 1

        #adjusting the heap
        parent = 0
        
        while parent * 2 + 2 < heap_size :  
            left_child = parent * 2 + 1
            right_child = parent * 2 + 2
            max_ = left_child if heap[left_child] > heap[right_child] else right_child

            if heap[max_] > heap[parent]:
                heap[max_], heap[parent] = heap[parent], heap[max_]
                parent = max_

            else:
                break

    return heap

print(heap_sort([9,8,7,6,5,4,3,2,1]))
            

        
        



    
    
    