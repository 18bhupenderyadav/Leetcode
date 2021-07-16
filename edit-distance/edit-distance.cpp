class Solution {
public:
    int memo[501][501];
    int dp(string& s,string& t,int n,int m)
    {
        if(n==0)
            return m;
        
        if(m==0)
            return n;
        
        if(memo[n][m]!=-1)
            return memo[n][m];
        
        
        if(s[n-1]==t[m-1])
            return memo[n][m]=dp(s,t,n-1,m-1);
        
        return memo[n][m]=1+min({dp(s,t,n-1,m),dp(s,t,n,m-1),dp(s,t,n-1,m-1)});
            
    }
    int minDistance(string s, string t) 
    {
        memset(memo,-1,sizeof(memo));
        return dp(s,t,s.length(),t.length());
    }
};