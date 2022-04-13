class Solution {
public:
    
    pair<int,int> get(int a,vector<pair<int,int>>& par)
    {
        if(a == par[a].first)
            return {a,0};
        
        int parity = par[a].second;
        par[a] = get(par[a].first,par);
        par[a].second = (par[a].second+parity)%2;
        
        return par[a];
    }
    
    bool uni(int a,int b,vector<pair<int,int>>& par,vector<int>& sz)
    {
        auto pa = get(a,par);
        a = pa.first;
        int x = pa.second;
        
        auto pb = get(b,par);
        b = pb.first;
        int y = pb.second;
        
        if(a==b)
        {
            if(x==y)
                return 0;
        }
        else
        {
            if(sz[a]<sz[b])
                swap(a,b);
            
            int len = (x+y+1)%2;
            par[b] = make_pair(a,len);
            sz[a]+=sz[b];
        }
        
        return 1;
    }
    
    bool isBipartite(vector<vector<int>>& adj) 
    {
        int n = adj.size();
        
        vector<pair<int,int>> par(n);
        vector<int> sz(n,1);
        
        for(int i=0;i<n;i++)
        {
            par[i].first = i;
            par[i].second = 0;
        }
        
        for(int i=0;i<adj.size();i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                if(uni(i,adj[i][j],par,sz)==false)
                    return 0;
            }
        }
        
        return  1;
    }
};