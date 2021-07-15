class Solution {
public:
    bool check(int i,int j,vector<vector<int>>& ar)
    {
        if(i<0 || j<0 || i>=ar.size() || j>=ar[0].size())
            return 0;
        return 1;
    }
    int dp(int i,int j,vector<vector<int>>& ar,vector<vector<int>>& memo)
    {
        if(!check(i,j,ar))
            return 0;
        
        if(memo[i][j]!=-1)
            return memo[i][j];
        
        int ans=0;
        
        if(check(i+1,j,ar) && ar[i][j]<ar[i+1][j])
            ans=max(ans,1+dp(i+1,j,ar,memo));
        
        if(check(i-1,j,ar) && ar[i][j]<ar[i-1][j])
            ans=max(ans,1+dp(i-1,j,ar,memo));
        
        if(check(i,j+1,ar) && ar[i][j]<ar[i][j+1])
            ans=max(ans,1+dp(i,j+1,ar,memo));
        
        if(check(i,j-1,ar) && ar[i][j]<ar[i][j-1])
            ans=max(ans,1+dp(i,j-1,ar,memo));
        
        return memo[i][j]=ans;
    }
    int longestIncreasingPath(vector<vector<int>>& ar) 
    {
        int n=ar.size();
        int m=ar[0].size();
        
        vector<vector<int>> memo(n+5,vector<int>(m+5,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(memo[i][j]==-1)
                {
                    dp(i,j,ar,memo);
                }
            }
        }
        dp(0,0,ar,memo);
        
        int ans=0;
        for(vector<int>& i:memo)
        {
            for(int j:i)
            {
                ans=max(ans,j);
            }
        }
        
        return ans+1;
    }
};