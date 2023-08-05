class Solution {
public:
    void dfs(vector<int>adjList[],vector<int> &visited,int node){
        visited[node]=1;
        for(auto x:adjList[node]){
            if(visited[x]!=1)
                dfs(adjList,visited,x);
        }
        
    }
    
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
         int V=isConnected[0].size(); 
         vector<int> adjList[V+1];
         vector<int> visited(V+1,0);
         int ans=0;
        
        //creating adj list
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(isConnected[i][j]==1&&i!=j)
                {
                    adjList[i+1].push_back(j+1);
                    // adjList[j+1].push_back(i+1);
                }
            }
        }
        
        
         for(int i=1;i<=V;i++)
         {
             if(visited[i]!=1)
             {   ans=ans+1;
                 dfs(adjList,visited,i);
             }
         }
        return ans;
    }
    
    
};




DFS
*convert matrix to adj list
*make a visited array to keep a track of all the nodes 
*traverse teh visited array , if a node is not visited , call a separate function dfs()
in dfs() that particular node would be marked as visited and the List correcponding to that node in the adjList would be traversed.
as the list is being traversed.

In this que:
as in this question we were asked to calculate the no of provinces present, 
we would simply add a "ans" variable and increment it by one every time we see an visited array element to null[before] calling the dfs function.
