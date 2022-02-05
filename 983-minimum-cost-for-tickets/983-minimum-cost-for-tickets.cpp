class Solution {
public:
    int memo[366];
    
    // Iterate through all days of the year
    int dp(int d,vector<int>& costs,vector<int>& days)
    {
        if(d>365)
            return 0;
        
        if(memo[d]!=-1)
            return memo[d];
        
        // Ans to store solution and we need to minimize ans
        int ans=INT_MAX;
        
        // If we need pass for this day
        if(binary_search(days.begin(),days.end(),d))
        {
            // We can choose any of the three pass
            ans=min(ans,dp(d+1,costs,days)+costs[0]);
            ans=min(ans,dp(d+7,costs,days)+costs[1]);
            ans=min(ans,dp(d+30,costs,days)+costs[2]);
        }
        // If we dont compulsory need the pass for this day
        else
        {
            // Dont take any pass for this day
            ans=dp(d+1,costs,days);
        }
        
        return memo[d]=ans;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {
        memset(memo,-1,sizeof(memo));
        return dp(1,costs,days);
    }
};