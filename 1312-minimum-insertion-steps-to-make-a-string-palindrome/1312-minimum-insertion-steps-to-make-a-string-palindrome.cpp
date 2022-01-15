class Solution {
public:
    int memo[505][505];
    int dp(string& s,string& t,int i,int j)
    {
        if(i<0)
            return 0;
        if(j<0)
            return 0;
        
        if(memo[i][j]!=-1)
            return memo[i][j];
        if(s[i]==t[j])
        {
            return memo[i][j]=1+dp(s,t,i-1,j-1);
        }
        
        return memo[i][j]=max(dp(s,t,i-1,j),dp(s,t,i,j-1));
    }
    int minInsertions(string s) 
    {
        string t=s;
        reverse(t.begin(),t.end());
        int n=s.size();
        memset(memo,-1,sizeof(memo));
        return n-dp(s,t,n-1,n-1);
    }
};