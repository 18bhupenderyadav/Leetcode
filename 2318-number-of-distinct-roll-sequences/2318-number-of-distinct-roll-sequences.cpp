class Solution {
public:
    const int mod = 1e9 + 7;
    int memo[10000+10][7][7];
    int dp(int n, int prev, int prev_prev)
    {
        if(n==0)
            return 1;
        
        if(memo[n][prev][prev_prev]!=-1)
            return memo[n][prev][prev_prev];
        
        int ans = 0;
        for(int i=1;i<=6;i++)
        {
            if(__gcd(i,prev) == 1 && i!=prev_prev && i!=prev)
            {
                ans += dp(n-1,i,prev)%mod;
                ans %= mod;
            }
        }
        
        return memo[n][prev][prev_prev]=ans;
    }
    
    int distinctSequences(int n) 
    {
        int ans = 0;
        
        memset(memo,-1,sizeof(memo));
        
        if(n == 1)
        {
            return 6;
        }
                
        for(int i=1;i<=6;i++)
        {
            for(int j=1;j<=6;j++)
            {
                if(__gcd(i,j) == 1 && i!=j)
                {
                    ans += dp(n-2,j,i)%mod;
                    ans %= mod;
                }
            }
        }
        
        return ans;
    }
};