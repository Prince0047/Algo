def howSum(umap, ar, target):
  if target == 0:
    return []
  if target < 0:
    return None
    
    
  if target in umap.keys():
    return umap[target]

  for num in ar:
    res = howSum(umap, ar,target-num)
    if res != None:
      res.append(num)
      umap[target] = res
      return res
  
  umap[target] = None
  return None
  

umap = {}
target = int(input())
ar = list(map(int, input().split()))

print(howSum(umap, ar, target))