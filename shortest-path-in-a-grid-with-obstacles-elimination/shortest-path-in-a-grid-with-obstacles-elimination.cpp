class Solution {
public:
    bool valid(int x, int y, int n , int m){
        if(x>=n || y>=m || x<0 || y<0){
                    return 0;
        }
        
        return 1;
    }
    int shortestPath(vector<vector<int>>& grid, int k) 
    {
        int n = grid.size() , m = grid[0].size();
        
        vector<int>dirx = {1,0,-1,0};
        
        vector<int>diry = {0,1,0,-1};
        
        vector<vector<int>>vis(n,vector<int>(m,-1));
        
        queue<vector<int>>q;
        
        q.push({0,0,0,0}); 
        
        while(!q.empty())
        {
            int sz = q.size();
            
            while(sz--)
            {
                
                vector<int> temp = q.front();
                q.pop();
                
                int x = temp[0], y = temp[1] , l = temp[2] , curr = temp[3];

                if(x==n-1 && y==m-1)
                {
                    return l;
                }
                if(x>=n || y>=m || x<0 || y<0)
                {
                    continue;
                }
                
                if(vis[x][y]!=-1 && vis[x][y]<=curr)
                {
                    continue;
                }
                
                if(curr>k)
                {
                    continue;
                }
                
                vis[x][y] = curr;
                
                for(int i=0;i<4;i++)
                { 
                    if(valid(x+dirx[i],y+diry[i],n,m))
                    {
                        int new_curr = curr;
                        if(grid[x+dirx[i]][y+diry[i]]==1)
                        {
                            new_curr++;
                        } 
                        q.push({x+dirx[i],y+diry[i],l+1,new_curr}); 
                    }              
                }
            }
        }
        
        return -1;
    }
};