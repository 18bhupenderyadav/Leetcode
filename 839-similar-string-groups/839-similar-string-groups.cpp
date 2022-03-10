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
    int numSimilarGroups(vector<string>& strs) 
    {
        unordered_map<string,int> mp;
        
        int n=strs.size();
        for(int i=0;i<n;i++)
        {
            mp[strs[i]] = i;
        }
        
        vector<vector<int>> adj(n);
        
        for(int i=0;i<n;i++)
        {
            string temp = strs[i];
            if(mp.find(temp)!=mp.end())
            {
                adj[i].push_back(mp[temp]);
                adj[mp[temp]].push_back(i);
            }
            for(int j=0;j<temp.size();j++)
            {
                for(int k=j+1;k<temp.size();k++)
                {
                    swap(temp[j],temp[k]);
                    if(mp.find(temp)!=mp.end())
                    {
                        adj[i].push_back(mp[temp]);
                        adj[mp[temp]].push_back(i);
                    }
                    swap(temp[j],temp[k]);
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