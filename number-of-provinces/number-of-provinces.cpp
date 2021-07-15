class Solution {
public:
    void dfs(int u,vector<vector<int>>& adj,vector<int>& vis)
    {
        if(vis[u])
            return ;
        
        vis[u]=1;
        
        for(int i=0;i<adj.size();i++)
        {
            if(adj[u][i]==1)
            {
                dfs(i,adj,vis);
            }
        }
        
        return;
    }
    int findCircleNum(vector<vector<int>>& adj) 
    {
        int n=adj.size();
        
        vector<int> vis(n,0);
        
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                ans++;
                dfs(i,adj,vis);
            }
        }
        
        return ans;
    }
};