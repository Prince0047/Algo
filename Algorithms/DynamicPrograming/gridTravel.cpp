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

class Solution
{
    public:

    int gridTraveler(int m,int n){
        if(m==0 or n==0) return 0;
        if(m==1 or n==1 ) return 1;

        return gridTraveler(m-1, n) + gridTraveler(m, n-1);
    }



};

int main(){
    // cout<<"hello world";
    int m,n;
    cin>>m>>n;
    Solution obj;
    cout<<obj.gridTraveler(m,n)<<endl;

    return 0;
}