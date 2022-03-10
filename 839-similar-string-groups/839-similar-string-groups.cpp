class Solution {
public:
    void dfs(int u,vector<vector<int>>& adj,vector<int>& vis)
    {
        if(vis[u])
            return ;
        
        vis[u] = 1;
        for(int v:adj[u])
            dfs(v,adj,vis);
        return;
    }
    bool issimmilar(string& a,string& b)
    {
        int cnt=0;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]!=b[i])
                cnt++;
        }
        
        return cnt==2 || cnt==0;
    }
    int numSimilarGroups(vector<string>& strs) 
    {
        int n=strs.size();
        vector<vector<int>> adj(n);
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(issimmilar(strs[i],strs[j]))
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        vector<int> vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                ans++;
                dfs(i,adj,vis);
            }
        }
        
        return ans;
    }
};