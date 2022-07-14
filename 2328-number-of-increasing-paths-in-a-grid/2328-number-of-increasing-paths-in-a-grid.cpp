class Solution {
public:
    const long long int mod = 1e9 + 7;
    bool check(int i,int j, int i1,int j1,vector<vector<int>>& ar)
    {
        if(i1>=ar.size() || j1>= ar[0].size() || i1<0 || j1<0)
            return 0;
        
        if(ar[i1][j1]>ar[i][j])
            return 1;
        
        return 0;
    }
    long long int dp(int i,int j,vector<vector<int>>& ar,vector<vector<int>>& memo)
    {
        if(memo[i][j]!=-1)
            return memo[i][j];
        
        long long int ans = 0;
        
        if(check(i,j,i+1,j,ar))
            ans = (ans + 1 + dp(i+1,j,ar,memo)%mod)%mod;
        
        if(check(i,j,i-1,j,ar))
            ans = (ans + 1 + dp(i-1,j,ar,memo)%mod)%mod;
        
        if(check(i,j,i,j+1,ar))
            ans = (ans + 1 + dp(i,j+1,ar,memo)%mod)%mod;
        
        if(check(i,j,i,j-1,ar))
            ans = (ans + 1 + dp(i,j-1,ar,memo)%mod)%mod;
        
        return memo[i][j] = ans;
    }
    int countPaths(vector<vector<int>>& ar) 
    {
        long long int ans = 0;
        int n = ar.size();
        int m = ar[0].size();
        
        vector<vector<int>> memo(n,vector<int>(m,-1));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans += 1 + dp(i,j,ar,memo);
                ans %= mod;
            }
        }
        
        return ans;
    }
};