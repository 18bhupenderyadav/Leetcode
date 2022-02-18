class Solution {
public:
    int memo[100000+5][27];
    int dp(int pos,int prev,vector<int>& col,vector<int>& t)
    {
        if(pos>=col.size())
            return 0;
        
        if(prev!=-1 && memo[pos][prev]!=-1)
            return memo[pos][prev];
        
        int ans = INT_MAX;
        if(col[pos]==prev)
        {
            ans = min(ans , t[pos]+dp(pos+1,prev,col,t));
        }
        else
        {
            ans = min(ans , t[pos]+dp(pos+1,prev,col,t));
            ans = min(ans , dp(pos+1,col[pos],col,t));
        }
        
        if(prev!=-1)
            memo[pos][prev]=ans;
        
        return ans;
    }
    int minCost(string colors, vector<int>& t) 
    {
        int n=colors.size();
        
        vector<int> col(n,0);
        
        for(int i=0;i<n;i++)
        {
            col[i]=colors[i]-'a';
        }
        
        memset(memo,-1,sizeof(memo));
        return dp(0,-1,col,t);
    }
};