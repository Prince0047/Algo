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

int sol = 0;

bool goSafe(int m, int n, int x, int y){
  if(m>=x and n>= y){
    return true;
  }
  return false;
}

void printWays(int m, int n, int srx, int sry, int desx, int desy, string output){
  if(srx == desx and sry == desy){
    sol++;
    cout<<"Answer -> "<<output<<endl;
    return;
  }
  
  // Right
  if(goSafe(m,n,srx+1,sry)){
    // cout<<"here";
    output.push_back('R');
    printWays(m,n,srx+1,sry,desx,desy,output);
    output.pop_back();
  }
  
  if(goSafe(m,n,srx,sry+1)){
    output.push_back('U');
    printWays(m,n,srx,sry+1,desx,desy,output);
    output.pop_back();
  }
  
  
}

int main(){
    int n,m,srx,sry,desx,desy;
    string output = "";
    cin>>m>>n>>srx>>sry>>desx>>desy;
    printWays(m,n,srx,sry,desx,desy,output);
    cout<<"Total ways : "<<sol<<endl;
    return 0;
}
