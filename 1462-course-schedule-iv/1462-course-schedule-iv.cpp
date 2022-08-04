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
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) 
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
        
        vector<unordered_set<int>> sol(n);
        
        for(int i=0;i<n;i++)
        {
            for(auto j:ans[i])
                sol[i].insert(j);
        }
        
        vector<bool> qr(queries.size());
        
        for(int i=0;i<queries.size();i++)
        {
            if(sol[queries[i][1]].find(queries[i][0]) != sol[queries[i][1]].end())
                qr[i] = true;
        }
        
        return qr;
    }
};