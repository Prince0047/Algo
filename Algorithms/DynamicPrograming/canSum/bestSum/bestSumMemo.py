
#    Time Complexity   =>   O(m*n)
#    Space Complexity  =>   O(m) (Not Sure)


def bestSum(umap, ar, target):
  
  
  if target == 0:
    return []
  if target < 0:
    return None
    
  
  if target in umap.keys():
    return umap[target]
    
  shortestComb = None

  for num in ar:
    combination = bestSum(umap, ar,target-num)

    if combination is not None:
      combination = combination + [num]                                  # <= Right Answer
      # combination.append(num)                                            #<=  Wrong Answer
      if shortestComb is None or len(combination) < len(shortestComb):
        shortestComb = combination
  
  umap[target] = shortestComb
  return shortestComb
  

umap = {}
target = int(input())
ar = list(map(int, input().split()))

print(bestSum(umap, ar, target))