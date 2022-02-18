class Solution {
public:
    int dp(int pos,int prev,vector<int>& col,vector<int>& t,vector<vector<int>>& memo)
    {
        if(pos>=col.size())
            return 0;
        
        if(memo[pos][prev+1]!=-1)
            return memo[pos][prev+1];
        
        int ans = INT_MAX;
        
        ans = min(ans , t[pos]+dp(pos+1,prev,col,t,memo));

        // If last color and this one is not same then we have 2 options 
        // that is to remove this or not
        if(col[pos]!=prev)
        {
            ans = min(ans , dp(pos+1,col[pos],col,t,memo));
        }
        
        memo[pos][prev+1]=ans;
        
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
        
        // memset(memo,-1,sizeof(memo));
        vector<vector<int>> memo(n+5,vector<int>(27,-1));
        return dp(0,-1,col,t,memo);
    }
};