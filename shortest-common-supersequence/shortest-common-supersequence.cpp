class Solution {
public:
    string helper(string s,string t)
    {
        int n=s.length();
        int m=t.length();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        string lcs;
        for(int i=0;i<dp[n][m];i++)
            lcs+=' ';
        
        int len=dp[n][m];
        int i=n,j=m;
        
        while(i>0 && j>0)
        {
            if(s[i-1]==t[j-1])
            {
                lcs[len-1]=s[i-1];
                i--,j--,len--;
            }
            else
            {
                if(dp[i-1][j]>dp[i][j-1])
                    i--;
                else
                    j--;
            }
        }
        
        return lcs;
        
    }
    string shortestCommonSupersequence(string A, string B) 
    {
        string lcs=helper(A,B);
        int i = 0, j = 0;
        string res = "";
        for (char c : lcs) {
            while (A[i] != c)
                res += A[i++];
            while (B[j] != c)
                res += B[j++];
            res += c, i++, j++;
        }
        return res + A.substr(i) + B.substr(j);
    }
};

// bbabacccacaaab
// bbabcacccaaab

// lcs:ab
// ans:ca