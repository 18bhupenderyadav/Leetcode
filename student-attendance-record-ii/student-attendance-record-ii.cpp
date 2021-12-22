class Solution {
public:
    const int mod=1e9+7;
    int memo[100005][3][3];
    int dp(int n,int a,int l)
    {
        if(a>=2)
            return 0;
        if(l>=3)
            return 0;
        if(n==0)
            return 1;
        
        if(memo[n][a][l]!=-1)
            return memo[n][a][l];
        
        long long int ans=0;
        ans+=dp(n-1,a,0)%mod;
        ans+=dp(n-1,a+1,0)%mod;
        ans+=dp(n-1,a,l+1)%mod;
        
        ans%=mod;
        
        return memo[n][a][l]=ans;
    }
    
    int checkRecord(int n) 
    {
        memset(memo,-1,sizeof(memo));
        return dp(n,0,0);
    }
};
