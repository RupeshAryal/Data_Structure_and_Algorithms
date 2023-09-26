#given an array an integar return the maximum and minimum of the array


def min_max(arr):

    if len(arr) == 1:
        return (arr[0], arr[0])
    
    if len(arr) == 2:
        return (sorted(arr))
    
    partition = len(arr) // 2

    min1 , max1 = min_max(arr[:partition])
    min2 , max2 = min_max(arr[partition:])

    min_ = min1 if min1 < min2 else min2
    max_ = max1 if max1 > max2 else max2

    return (min_, max_)