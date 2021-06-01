# Count Primes in a given range

import math

def fun(MAX):
    primes = [True]*MAX
    for p in range(2,int(math.sqrt(MAX))):
        if primes[p]:
            for i in range(2*p,MAX,p):
                primes[i] = False
    
    count = [0]
    for i in range(2,MAX):
        if primes[i] == True:
            count.append(count[-1]+1)
        else:
            count.append(count[-1])

    return count


MAX = 10000000
count = fun(MAX)