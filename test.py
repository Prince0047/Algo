def inp():
    n = int(input())
    return n

def inparr():
    arr = list(map(int, input().split()))
    return arr

def integ(val,sum):
    div = sum/val
    if div%1==0:
        return True
    return False

for _ in range(inp()):
    n = inp()
    arr = inparr()

    dp = [0]*(2*n+1)
    for i in range(n):
        val = arr[i]
        sum = i
        if dp[]
