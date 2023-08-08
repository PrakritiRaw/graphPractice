class Solution {
  public:
  
    bool detect(int src,vector<int> adj[],int visited[])
    { 
      queue<pair<int,int>> q;
      visited[src]=1;
      q.push({src,-1});
      
      while(!q.empty())
      {
        int current=q.front().first;
        int previous=q.front().second;
        q.pop();
        
        for(auto x: adj[current])
        {
            if(visited[x]==0)
            {
                visited[x]=1;
                q.push({x,current});
            }
            else if(x!=previous)
            {
                return 1;
            }
        }
        
        
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
                if(detect(i,adj,visited)) return 1;
            }
                
        }
        return 0;
    }
};
