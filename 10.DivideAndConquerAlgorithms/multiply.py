def multiply(nums):
    if len(nums) == 1:
        return nums[0]
    if len(nums) == 2:
        return nums[0] * nums[1]
    
    mid = len(nums) // 2

    print(nums)

    return multiply(nums[:mid]) * multiply(nums[mid :])


print(multiply([1,2,3,4,]))