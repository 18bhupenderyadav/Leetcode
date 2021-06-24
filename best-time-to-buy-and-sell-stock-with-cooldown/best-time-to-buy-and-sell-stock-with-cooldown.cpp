class Solution {
public:
    int dp(int pos,int restricted,vector<int>& ar,vector<vector<int>>& memo)
    {
        if(pos>=ar.size())
            return 0;
        
        if(memo[pos][restricted]!=-1)
            return memo[pos][restricted];
        
        int ans=0;
        if(restricted)
        {
            ans=max(ans,ar[pos]+dp(pos+2,0,ar,memo));
        }
        else 
        {
            ans=max(ans,-ar[pos]+dp(pos+1,1,ar,memo));
        }
        
        ans=max(ans,dp(pos+1,restricted,ar,memo));
        
        return memo[pos][restricted]=ans;
    }
    int maxProfit(vector<int>& prices) 
    {
        vector<vector<int>> memo(prices.size(),vector<int>(2,-1));
        return dp(0,0,prices,memo);
    }
};