#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define forin(it,x) for(auto it = x.begin(); it!=x.end(); ++it)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

const int N = 1e5+2, MOD = 1e9+7;

int main(){
    
    int n, m;
    cin>>n>>m;

    vvi adjm(n+1, vi(n+1,0));

    rep(i,0,m){
        int x,y;
        cin>> x>> y;

        adjm[x][y]= 1;
        adjm[y][x] = 1;
    }

    cout<<" adjacency matrix of above graph is given by :"<< endl;

    rep(i,1,n+1){
        rep(j, 1, n+1){
            cout<<adjm[i][j]<< " ";
        }
        cout<<endl;
    }
    

    // Adgecency List for Graph

    vi adj[N];

    rep(i,0,m){
        int x,y;
        cin>> x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    cout<< "adjecency list of the graph is :"<<endl;

    rep(i,1,n+1){
        cout<<i<<" -> ";

        forin(it, adj[i]){
            cout<<*it<<" ";
        }
        cout<<endl;
    }

    return 0;
}