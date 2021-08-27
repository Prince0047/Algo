
#   Time Complexity   =>   O(n^m)
#   Space Complexity  =>   O(m)

def howSum(ar, target, res):
  if target == 0:
    return res
  if target < 0:
    return None

  for num in ar:
    if howSum(ar,target-num,res) != None:
      res.append(num)
      return res
      
  return None
  

umap = {}
target = int(input())
ar = list(map(int, input().split()))
res = []
print(howSum(ar, target,res))