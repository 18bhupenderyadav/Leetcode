class Solution {
public:
    const int inf = 1e7;
    bool can(vector<vector<int>>& matrix, int in)
    {
        int n = matrix.size() , m = matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-inf));
        
        dp[0][0] = in+matrix[0][0];
        if(dp[0][0]<=0)
        {
            return 0;
        }
        
        for(int i=1;i<m;i++)
        {
            if(dp[0][i-1]==-inf)
            {
                continue;
            }
            dp[0][i] = dp[0][i-1] + matrix[0][i];
            if(dp[0][i]<=0){
                dp[0][i] = -inf;
            }
        }
        
        for(int i=1;i<n;i++)
        {
            if(dp[i-1][0]==-inf)
            {
                continue;
            }
            dp[i][0] = dp[i-1][0] + matrix[i][0];
            if(dp[i][0]<=0){
                dp[i][0] = -inf;
            }
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                int a  = -inf , b = -inf;
                if(dp[i-1][j]!=-inf)
                {
                    a = dp[i-1][j]+matrix[i][j];
                }
                if(dp[i][j-1]!=-inf)
                {
                    b = dp[i][j-1]+matrix[i][j];
                }
                dp[i][j] = max(a,b);
                if(dp[i][j]<=0)
                {
                    dp[i][j]=-inf;
                }
            }
        }
        
        return (dp[n-1][m-1]>0);
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) 
    {
        int low = 0 , high = 1e8;
        
        while(low+1<high)
        {
            int mid = low + (high-low)/2;
            if(can(dungeon,mid))
            {
                high = mid;
            }
            else
            {
                low = mid;
            }
        }
        
        return high;
    }
};