class Solution {
public:
    void add(vector<int>& ans, vector<int>& temp)
    {
        unordered_set<int> s;
        
        for(int i:ans)
            s.insert(i);
        
        for(int i: temp)
            if(s.find(i) == s.end())
                ans.push_back(i);
        
        return;
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) 
    {
        vector<vector<int>> ans(n),adj(n);
        
        queue<int> q;
        
        vector<int> in_deg(n,0);
        
        for(auto i:edges)
        {
            in_deg[i[1]]++;
            
            adj[i[0]].push_back(i[1]);
        }
        
        for(int i=0;i<n;i++)
        {
            if(in_deg[i]==0)
                q.push(i);
        }
        
        while(q.size())
        {
            int top = q.front();
            q.pop();
            
            for(auto i:adj[top])
            {
                in_deg[i]--;
                
                if(in_deg[i]==0)
                {
                    q.push(i);
                }
                
                add(ans[i],ans[top]);
                ans[i].push_back(top);
            }
        }
        
        for(auto& i:ans)
            sort(i.begin(),i.end());
        
        return ans;
    }
};