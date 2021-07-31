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

void powerset(int* arr,int n, vector<int> output, int index){
  if(index>=n){
    for(auto i: output){
      cout<<i<<" ";
    }
    cout<<endl;
    return ;
  }
  powerset(arr,n,output,index+1);
  output.push_back(arr[index]);
  powerset(arr,n,output,index+1);
}

int main(){
    int arr[] = {1,2,3};
    vector<int> output;
    powerset(arr,3,output,0);
    return 0;
}