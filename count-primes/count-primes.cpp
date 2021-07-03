class Solution {
public:
    bool is_prime(int n) 
    { 
        // Corner cases 
        if (n <= 1) 
            return false; 
        if (n <= 3) 
            return true; 

        // This is checked so that we can skip 
        // middle five numbers in below loop 
        if (n % 2 == 0 || n % 3 == 0) 
            return false; 

        for (int i = 5; i * i <= n; i = i + 6) 
            if (n % i == 0 || n % (i + 2) == 0) 
                return false; 

        return true; 
    }
    int countPrimes(int n) 
    {
        int i,j;
        if(n==0||n==1)
            return 0;
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[0]=0;
        dp[1]=0;
        for(i=2;i<=n;i++)
        {
            dp[i]=dp[i-1];
            if(is_prime(i-1))
                dp[i]++;
        }
        return dp[n];
    }
};