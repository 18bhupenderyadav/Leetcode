class Solution {
    static bool cmp(vector<int>& a,vector<int>& b)
    {
        return a[2]<b[2];
    }
public:
    int N;
    void dfs(int u,unordered_map<int,vector<int>>& adj,unordered_map<int,int>& vis,vector<int>& secret)
    {
        if(vis.find(u)!=vis.end())
            return;
        
        vis[u]++;
        
        secret[u]++;
        
        for(int v:adj[u])
        {
            dfs(v,adj,vis,secret);
        }
    }
    void grp(vector<pair<int,int>>& edges,vector<int>& secret)
    {
        unordered_map<int,vector<int>> adj;
        
        for(pair<int,int> i:edges)
        {
            adj[i.first].push_back(i.second);
            adj[i.second].push_back(i.first);
        }
        
        unordered_map<int,int> vis;
        
        for(pair<int,int> i:edges)
        {
            
            
            int u=i.first;
            int v=i.second;
            if(secret[u])
            {
                if(vis.find(u)==vis.end())
                {
                    dfs(u,adj,vis,secret);
                }
            }
            
            if(secret[v])
            {
                if(vis.find(v)==vis.end())
                {
                    dfs(v,adj,vis,secret);
                }
            }
        }
        
    }
    
    
    
    
    
    
    vector<vector<pair<int,int>>> make_bucket(vector<vector<int>>& meet)
    {
        vector<vector<pair<int,int>>> bucket;
        
        vector<pair<int,int>> temp;
        temp.push_back({meet[0][0],meet[0][1]});
        vector<int> cur=meet[0];
        
        for(int i=1;i<meet.size();i++)
        {
            if(cur[2]==meet[i][2])
                temp.push_back({meet[i][0],meet[i][1]});
            else
            {
                bucket.push_back(temp);
                temp.clear();
                temp.push_back({meet[i][0],meet[i][1]});
                cur=meet[i];
            }
        }
        bucket.push_back(temp);
        
        return bucket;
        
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meet, int firstPerson) 
    {
        N=n;
        sort(meet.begin(),meet.end(),cmp);
           
        vector<vector<pair<int,int>>> bucket = make_bucket(meet);
        
        vector<int> secret (n,0);
        secret[0] = secret[firstPerson] = 1;
        
        for(int i=0;i<bucket.size();i++)
        {
            grp(bucket[i],secret);
        }
        
        vector<int> ans;
        
        for(int i=0;i<n;i++)
        {
            if(secret[i])
                ans.push_back(i);
        }
        return ans;
    }
};