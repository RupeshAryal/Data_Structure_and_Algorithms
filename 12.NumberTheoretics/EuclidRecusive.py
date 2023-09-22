#recursive algorith to find the GCD of two number using euclid algorithm 


def euclid(a , b):
    if b == 0:
        return a
    
    else:
        return euclid(b, a % b)
    
print(euclid(899, 493))