class Solution {
public:
    int memo[55][55][55];
    const int mod=1000000000+7;
    int dp(int i,int j,int n,int m,int moves)
    {
        if(i<0||j<0||i==n||j==m)
                return 1;
        if(moves==0)
            return 0;
        
        if(memo[i][j][moves]!=-1)
            return memo[i][j][moves];
        int ans=dp(i+1,j,n,m,moves-1);
        ans%=mod;
        ans+=dp(i-1,j,n,m,moves-1);
        ans%=mod;
        ans+=dp(i,j+1,n,m,moves-1);
        ans%=mod;
        ans+=dp(i,j-1,n,m,moves-1);
        ans%=mod;
        memo[i][j][moves]=ans;
        return memo[i][j][moves];
    }
    int findPaths(int n, int m, int N, int i, int j)
    {
        memset(memo,-1,sizeof(memo));
        return dp(i,j,n,m,N);
    }
};