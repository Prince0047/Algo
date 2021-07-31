#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool dfs(int src, vector<int> adj[], bool* vis, bool* callStack){
        vis[src] = true;
        callStack[src] = true;
        for(auto i= adj[src].begin();i!=adj[src].end();i++){
            if(!vis[*i]){
                if (dfs(*i,adj,vis,callStack)){
                    return true;
                }
            }
            if(callStack[*i]){
                return true;
            }
        }
        callStack[src] = false;
        return false;
        
    }
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	// code here
	   	bool vis[V];
        bool callStack[V];
	   	
	   	for(int i=0;i<V;i++){
	   	    vis[i] = false;
            callStack[i] = false;
	   	}
	   	
	   	for(int i=0;i<V;i++){
	   	    if (!vis[i]){
	   	        if (dfs(i,adj,vis,callStack)){
	   	            return true;
	   	        }
	   	    }
	   	}
	   	return true;
	}
};

int main(){
    cout<<"hello"<<endl;
    return 0;
}