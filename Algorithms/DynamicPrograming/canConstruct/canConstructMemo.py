
#    Time Complexity   =>   O(m*n)
#    Space Complexity  =>   O(m) (Not Sure)


def canConstruct(umap, ar, target):
  
  if len(target) == 0:
    return True 
    
  if target in umap.keys():
    return umap[target]
    
    
  for s in ar:
    n = len(s)
    if n <= len(target):
      if s == target[:n]:
        if canConstruct(umap, ar, target[n:]):
          umap[target] = True
          return True
    
  umap[target] = False     
  return False

umap = {}
target = input()
ar = list(map(str, input().split()))


print(canConstruct(umap, ar, target))