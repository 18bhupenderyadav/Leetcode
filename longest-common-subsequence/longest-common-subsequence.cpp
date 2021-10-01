class Solution {
public:
    int longestCommonSubsequence(string s, string t) 
    {
        int i,j,n,m;
        n=s.length();
        m=t.length();
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};