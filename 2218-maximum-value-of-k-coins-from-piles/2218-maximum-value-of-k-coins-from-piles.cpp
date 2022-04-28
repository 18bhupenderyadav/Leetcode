class Solution {
public:
    int memo[1010][2020];
    int dp(int pos,int k,vector<vector<int>>& ar)
    {
        if(k<0)
            return INT_MIN/2;
        if(pos>=ar.size())
            return 0;
        if(k==0)
            return 0;
        
        if(memo[pos][k]!=-1)
            return memo[pos][k];
        
        int ans = dp(pos+1,k,ar),sum=0;
        for(int i=0;i<ar[pos].size();i++)
        {
            sum+=ar[pos][i];
            ans=max(ans,sum+dp(pos+1,k-i-1,ar));
        }
        
        return memo[pos][k]=ans;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) 
    {
        memset(memo,-1,sizeof(memo));
        return dp(0,k,piles);
    }
};