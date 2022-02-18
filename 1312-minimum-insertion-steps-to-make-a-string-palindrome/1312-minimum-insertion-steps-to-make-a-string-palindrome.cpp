class Solution {
public:
    int memo[505][505];
    int dp(string& a,string& b,int i,int j)
    {
        if(i<0 || j<0)
            return 0;
        if(memo[i][j]!=-1)
            return memo[i][j];
        
        int ans=0;
        if(a[i]==b[j])
        {
            ans = max(ans,1+dp(a,b,i-1,j-1));
        }
        else
        {
            ans = max(ans,dp(a,b,i-1,j));
            ans = max(ans,dp(a,b,i,j-1));
        }
        
        return memo[i][j]=ans;
    }
    int minInsertions(string s) 
    {
        string t=s;
        reverse(t.begin(),t.end());
        
        memset(memo,-1,sizeof(memo));
        int l=dp(s,t,s.size()-1,t.size()-1);
        
        return s.size()-l;
    }
};
