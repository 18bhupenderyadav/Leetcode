class Solution {
public:
    
    int cost(int i,int j,vector<vector<int>>& pt)
    {
        int ct = abs(pt[i][0]-pt[j][0]) + abs(pt[i][1]-pt[j][1]);
        return ct;
    }
    
    static bool cmp(pair<int,pair<int,int>>& a,pair<int,pair<int,int>>& b)
    {
        return a.second.second<b.second.second;
    }
    
    int get(int a,vector<int>& par)
    {
        if(a==par[a])
            return a;
        
        return par[a] = get(par[a],par);
    }
    
    void uni(int a,int b,vector<int>& par,vector<int>& sz)
    {
        int u = get(a,par);
        int v = get(b,par);
        
        if(u==v)
            return;
        
        if(sz[u]<sz[v])
            swap(u,v);
        
        par[v] = u;
        sz[v] += sz[v];
        
        return;
    }
    
    int minCostConnectPoints(vector<vector<int>>& pt) 
    {
        int n = pt.size(),ans = 0;
        
        vector<pair<int,pair<int,int>>> ar;
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int ct = cost(i,j,pt);
                ar.push_back({i,{j,ct}});
            }
        }
        
        sort(ar.begin(),ar.end(),cmp);
        
        vector<int> par(n,-1);
        vector<int> sz(n,1);
        
        for(int i=0;i<n;i++)
        {
            par[i] = i;
            sz[i] = 1;
        }
        
        for(int i=0;i<ar.size();i++)
        {
            int a = ar[i].first;
            int b = ar[i].second.first;
            int u = get(a,par);
            int v = get(b,par);
            
            if(u == v)
                continue;
            
            ans += ar[i].second.second;
            uni(a,b,par,sz);
        }
        
        return ans;
        
    }
};

//  -      -     -
// [[0,0],[2,2],[3,10],[5,2],[7,0]]

// ans = 4 + 13 +