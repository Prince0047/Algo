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

// exponentian function
int exp(int x,int y){
    if(y==0){
        return 1;
    }
    else if(y&1){
        return x*exp(x,y-1);
    }
    return exp(x*x,y/2);
}

int main(){
    int x,y;
    cin>>x>>y;
    cout<<exp(x,y)<<endl;
    return 0;
}