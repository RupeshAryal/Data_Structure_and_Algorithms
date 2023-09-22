def euclid_iterative(a, b):
    while True:
        if b == 0 :
            return a
        else:
            temp = a
            a = b
            b = temp % b

    
print(euclid_iterative(899, 493))
