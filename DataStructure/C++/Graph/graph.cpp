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

// BFS
void BFS(int V, vi adj[]){
    queue<int> q;
    q.push(1);

    bool vis[N];
    rep(i,1,V+1){
        vis[i] = false;
    }
    vis[1] = true;

    int cnt = 0;
    while(!q.empty()){
        cnt++;
        int node =  q.front();
        q.pop();

        cout<<node<<" ";

        forin(x, adj[node]){
            if(!vis[*x]){
                vis[*x] = true;
                q.push(*x);
            }
        }
    }

}

// DFS
void DFS(int V, vi adj[]){
    stack<int> s;
    bool vis[V+1];

    rep(i,1,V+1){
        vis[i] = false;
    }

    s.push(1);
    vis[1] = true;

    while(!s.empty()) {
        int node = s.top();
        cout<<node<<" ";
        s.pop();

        forin(it , adj[node]){
            if(!vis[*it]){
                vis[*it] = true;

                s.push(*it);
            }
        }
    }
}

// Topological Sort  
void TLS(int V, vi adj[]){
    queue<int> q;
    vi indeg(V+1,0);

    rep(i,1,V+1){
        forin(x,adj[i]){
            indeg[*x] ++;
        }
    }

    rep(i,1,V+1){
        if(indeg[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();

        cout<<node<<" ";

        forin(x, adj[node]) {
            indeg[*x] --;

            if(indeg[*x]== 0){
                q.push(*x);
            }
        }
    }
}

bool cycle_util(int i,int n, vector<bool> &vis){
    vis[i] = true;
}

// Cycle Detection
class Cycle 
{
    public:
    //Function to detect cycle in an undirected graph.
    bool cycleDetect(int src, vector<int>adj[], vector<bool> &vis, int parent){
        vis[src]=true;
        for(auto i:adj[src]){
            if(i!=parent){
                if(vis[i])
                return true;
                if(!vis[i] && cycleDetect(i,adj,vis,src))
                return true;
            }
        }
        return false;
    }
	bool isCycle(int V, vector<int>adj[])
	{
	    // Code here
	    vector<bool> vis(V,false);
	    for(int i=0;i<V;i++){
	        if(!vis[i] && cycleDetect(i,adj,vis,-1))
	        return true;
	    }
	    return false;
	}
};

int main(){
    // Adjecency List
    vi adj[N];

    int n,m;
    cin>>n >> m;

    rep(i,0,m){
        int x,y;
        cin>> x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    BFS(n, adj);
    cout<<endl;

    DFS(n, adj);
    cout<<endl;

    // Topological Sort ( for DAG only )
    TLS(n, adj);
    cout<<endl;

    Cycle obj;
    cout<<"cycle is "<<obj.isCycle(n, adj)<<endl;
      

    return 0;
}

// 7 7
// 1 2
// 1 3
// 2 4
// 2 5
// 2 6
// 2 7
// 7 3