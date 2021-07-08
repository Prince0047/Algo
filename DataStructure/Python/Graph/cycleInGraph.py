class Solution:
    
    #Function to detect cycle in a directed graph.
    def isCyclic(self, V, adj):
        # code here
        vis = [False]*V
        callStack = [False]*V
        for node in range(V):
            if not vis[node]:
                if self.dfs(node,adj,vis,callStack):
                    return True
        
        return False
        
    # @staticmethod
    def dfs(self,src,adj,vis,callStack):
        vis[src] = True
        callStack[src] = True
        
        for node in adj[src]:
            if (not vis[node]):
                if self.dfs(node,adj,vis,callStack):
                    return True
            if callStack[node]:
                return True
                
        callStack[src] = False
        return False
                 
    