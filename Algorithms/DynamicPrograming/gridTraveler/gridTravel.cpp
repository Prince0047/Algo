#include <bits/stdc++.h>
#include<string> 
using namespace std;

int gridTraveler(unordered_map<string,long long int> &grid, int m, int n){
  string key = to_string(m) + "," + to_string(n);
  // cout<<key<<endl;
  if (m==0 and n==0){
    return 1;
  }
  if(m<0 or n<0){
    return 0;
  }
  if(grid.find(key) == grid.end()){
    grid[key] = gridTraveler(grid,m-1,n) + gridTraveler(grid, m, n-1);
  }
  
  return grid[key];
}

int main() 
{
    int m,n;
    cin>>m>>n;
    unordered_map<string,long long int> grid;
    
    cout<<gridTraveler(grid,m,n);
    return 0;
}