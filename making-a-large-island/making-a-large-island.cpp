class Solution {
public:
    int cnt;
    void dfs(vector<vector<int>>& grid, int i, int j, int id, vector<vector<int>>& vis){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || vis[i][j]==1 || grid[i][j]==0){
            return ;
        }
        vis[i][j]=1;
        grid[i][j]=id;
        cnt++;
        dfs(grid,i+1,j,id,vis);
        dfs(grid,i-1,j,id,vis);
        dfs(grid,i,j+1,id,vis);
        dfs(grid,i,j-1,id,vis); 
        return ;
    }
    int largestIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        vector<vector<int>>vis(n,vector<int>(n,0));
        
            int id = 1;
            int ans = 0;
        
            
            unordered_map<int,int>mp;
            mp[0]=0;
        
        
            for(int i=0;i<grid.size();i++){
                for(int j=0;j<grid[0].size();j++){
                    if(grid[i][j]==1 && vis[i][j]==0){
                        cnt = 0;
                        dfs(grid,i,j,id,vis);
                        mp[id]=cnt;
                        id++;
                        ans = max(ans,cnt);
                    }
                }
            }
        
        
            for(int i=0;i<grid.size();i++){
                for(int j=0;j<grid[0].size();j++){
                    if(grid[i][j]==0 ){
                        
                        set<int>islands; 
                        if(i+1<n){
                            islands.insert(grid[i+1][j]);
                        }
                        if(i-1>=0){
                            islands.insert(grid[i-1][j]);
                        }
                        if(j+1<n){
                            islands.insert(grid[i][j+1]);
                        }
                        if(j-1>=0){
                            islands.insert(grid[i][j-1]);
                        }
                        
                        int temp = 0;
                        for(int k:islands){
                            temp+=mp[k];
                        }
                        ans = max(ans,temp+1);
                    }
                }
            }
        
        return ans;
        
    }
};
