class Solution {
public:
    double dfs(vector<vector<int>>& adj, int curr, int parent, int target, int t )
    {
        if(t==0)
        {
            if(curr==target)
            {
                return 1;
            }
            return 0;
        }
        
        if(curr!=1 && adj[curr].size()==1)
        {
            return curr==target;
        } 
        
        double ans = 0;
        double n = 0;
        
        for(int it : adj[curr])
        {
            if(it==parent)
            {
                continue;
            }
            n++;
        }
        
        for(int it : adj[curr])
        {
            if(it==parent)
            {
                continue;
            }
            ans += (double)(1/n)*dfs(adj,it,curr,target,t-1);
        }
        
        return ans;
    }
    
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) 
    {
        if(edges.size()==0){
            return target==1;
        }
        vector<vector<int>> adj(105);
        for(vector<int>v : edges)
        {
            adj[v[0]].push_back(v[1]); 
            adj[v[1]].push_back(v[0]);
        }
        
        return dfs(adj,1,-1,target,t);
    }
};


//    1
// 2      
//     3