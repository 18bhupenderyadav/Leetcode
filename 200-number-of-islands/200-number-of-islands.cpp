class Solution {
public:
    int get(int a,vector<int>& par)
    {
        if(a==par[a])
            return a;
        return par[a]=get(par[a],par);
    }
    
    void uni(int a,int b,vector<int>& par,vector<int>& sz)
    {
        int u = get(a,par);
        int v = get(b,par);
        
        if(u==v)
            return;
        
        if(sz[u]<sz[v])
            swap(u,v);
        
        par[v]=u;
        sz[u]+=sz[v];
        
        return;
    }
    
    vector<pair<int,int>> pos_mk(int i,int j,vector<vector<int>> & ar)
    {
        int n=ar.size(),m=ar[0].size();
        
        vector<pair<int,int>> ans;
        
        if(i+1<n)
        {
            if(ar[i+1][j])
                ans.push_back({i+1,j});
        }
        
        if(i-1>0)
        {
            if(ar[i-1][j])
                ans.push_back({i-1,j});
        }
        
        if(j+1<m)
        {
            if(ar[i][j+1])
                ans.push_back({i,j+1});
        }
        
        if(j-1>0)
        {
            if(ar[i][j-1])
                ans.push_back({i,j-1});
        }
        
        return ans;
    }
    
    vector<vector<int>> mk(vector<vector<char>>& grid)
    {
        int n=grid.size(),m=grid[0].size();
        
        vector<vector<int>> ar(n,vector<int>(m));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                    ar[i][j]=1;
                else
                    ar[i][j]=0;
            }
        }
        
        return ar;
    }
    
    int numIslands(vector<vector<char>>& grid) 
    {
        int n=grid.size(),m=grid[0].size();
        
        vector<vector<int>> ar = mk(grid);
        
        map<pair<int,int>,int> mp;
        vector<int> par(n*m+5),sz(n*m+5,1);
        
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                mp[{i,j}]=cnt;
                par[cnt]=cnt;

                
                cnt++;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(ar[i][j]==0)
                    continue;
                
                vector<pair<int,int>> pos = pos_mk(i,j,ar);
                
                for(pair<int,int> it:pos)
                {
                    int u = mp[{i,j}];
                    int v = mp[{it.first,it.second}];
                    uni(u,v,par,sz);
                }
            }
        }
        
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(ar[i][j]==0)
                    continue;
                
                int u = mp[{i,j}];
                if(get(u,par)==u)
                    ans++;
            }
        }
        
        return ans;
    }
};