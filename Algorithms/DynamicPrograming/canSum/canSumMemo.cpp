#include <bits/stdc++.h>
#include<string> 
using namespace std;

bool canSum(unordered_map<int,bool> &umap, int* arr, int n, int target){
  if (target==0){
    return true;
  }
  if (target<0){
    return false;
  }
  if (umap.find(target) == umap.end()){
    for(int i=0;i<n;i++){
      if(canSum(umap,arr, n, target-arr[i])){
        umap[target] = true;
        return true;
      }
    }
    umap[target] = false;
  }
  return umap[target];
}

int main() 
{
    int n, target;
    cin>>n>>target;
    
    int arr[n];
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
    
    unordered_map<int,bool> umap;
    
    cout<<canSum(umap, arr, n, target);
    return 0;
}