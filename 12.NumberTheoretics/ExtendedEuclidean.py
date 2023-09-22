def extended_euclidean(a, b):
    if b == 0:
        return (a, 1, 0)

    else:
        (d1, x1, y1) = extended_euclidean(b, a % b)
        (d , x, y) = (d1, y1, x1 - (a // b) * y1 )
        return d , x, y
    

(d, x, y) = extended_euclidean(50,30)
print(d)
