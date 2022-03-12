class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& ar,vector<vector<int>>& vis)
    {
        if(i<0 || j<0 || i>=ar.size() || j>=ar[0].size())
            return;
        
        if(vis[i][j] || ar[i][j]==0)
            return;
        
        vis[i][j]=1;
        dfs(i+1,j,ar,vis);
        dfs(i-1,j,ar,vis);
        dfs(i,j-1,ar,vis);
        dfs(i,j+1,ar,vis);
        return;
    }
    int initdfs(vector<vector<int>>& ar)
    {
        int ans = 0;
        int n=ar.size(),m=ar[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(ar[i][j]==1 && vis[i][j]==0)
                {
                    ans++;
                    dfs(i,j,ar,vis);
                }
            }
        }
        
        if(ans>=2 || ans==0)
            return 1;
        return 0;
    }
    int minDays(vector<vector<int>>& ar) 
    {
        int n = ar.size();
        int m = ar[0].size();
        
        if(initdfs(ar))
            return 0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(ar[i][j])
                {
                    ar[i][j]=0;
                    if(initdfs(ar))
                        return 1;
                    ar[i][j]=1;
                }
            }
        }
        return 2;
    }
};