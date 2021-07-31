#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a, i<b; i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

const int N = 1e5+2, MOD = 1e9+7;


// fibonacci
unordered_map<int,long long int> fibmap;

long long int fib(int n){
  if(n==1 or n==2){
    return 1;
  }
  if(fibmap.find(n) == fibmap.end()){
    fibmap[n] = fib(n-2)+ fib(n-1);
  }
  return fibmap[n];
}


// staircase Optimal solution
unordered_map<int,long long int> mp;

long long int stairCaseOptimal(int n){
  if(n==1 or n==2){
    return n;
  }
  if(mp.find(n) == mp.end()){
    mp[n] = stairCaseOptimal(n-2) + stairCaseOptimal(n-1);
  }
  return mp[n];
}



int stairCase(int n){
  if(n==1 or n==2){
    return 1;
  }
  return stairCase(n-2) + stairCase(n-1);
}

int main(){
    int n;
    cin>>n;
    cout<<fib(n)<<endl;
    cout<<stairCaseOptimal(n)<<endl;
    return 0;
}