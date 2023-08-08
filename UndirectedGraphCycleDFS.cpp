//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    bool dfs(int src,int parent ,vector<int> adj[],int visited[])
    { 
      visited[src]=1;
      for(auto x: adj[src])
      {
          if(visited[x]==0) 
          {
              if(dfs(x,src,adj,visited)==1) return 1;
          }
          else if(parent!=x) return 1;
      }
      
      return 0;
    }
    
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int visited[V]={0};
        for(int i=0;i<V;i++)
        {
            if(visited[i]==0)
            {
                if(dfs(i,-1,adj,visited)) return 1;
            }
                
        }
        return 0;
    }
};
