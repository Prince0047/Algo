''' Find the number of ways to reach the (m,n) block from (0,0) in a grid '''

def gridTraveler(m,n):
    key = str(m) + "," + str(n)
    if m==0 and n==0:
        return 1
    if m<0 or n<0:
        return 0

    if key in grid.keys():
        return grid[key]
    
    grid[key] = gridTraveler(m-1,n) + gridTraveler(m,n-1)

    return grid[key]

m,n = map(int, input().split())

grid = {}

print(gridTraveler(m,n))

