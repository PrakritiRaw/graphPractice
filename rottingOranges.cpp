class Solution {
public:
    
    int orangesRotting(vector<vector<int>>& grid) {
         
        int n=grid.size();
        int m=grid[0].size();
        int visited[n][m];
        queue<pair<pair<int,int>,int>> q;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {visited[i][j]=2;
                q.push({{i,j},0});
                }
                else visited[i][j]=0;
                    
            }
        }
        
        int row[4]={-1,0,+1,0};
        int col[4]={0,+1,0,-1};
        int time=0;
        while(!q.empty())
        {
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            time=max(time,t);
            q.pop();
            
            for(int i=0;i<4;i++)
            {
                int nrow= r+row[i];
                int ncol= c+col[i];
                
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol]==1 &&visited[nrow][ncol]==0  )
                {
                        visited[nrow][ncol]=2;
                        q.push({{nrow,ncol},t+1});
                }
            }
            
        }
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && visited[i][j]!=2) return -1;
            }
        }
        
        return time;
    }
};






// *so here we will use BFS because we have to find the least time because one orange is rotting all its neighbouring oranges, that is we would first
// come on a node cover all its neighbours and then move on to the second node. 
// *first we have created a visited 2D matrix , so that we can keep track of all the rotten oranges. initialize it with 0 , except the ones which are rotten
// while initilizing it with zero push the rotten orange's coordinates and the time in a queue.
// *traverse the queue until it is empty:
// take the coordinate of the rotten orange from the top element of queue and also the time. and then push all its neighbouring oranges marked 1 in the queue 
// and change it to 2 which indicate that its neighbouring oranges are now rotten, also remember to increment the time by one.
// *now that the queue is empty check both matrix grid and visited, where grid=1 and visited =1 , this means that orange is left unrotten thus return -1. 
//   else return max time.
