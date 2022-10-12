class Solution {
public:
    vector<long long int> lft_mxz(vector<long long int> ar)
    {
        vector<long long int> ans(ar.size());
        
        for(int i=0;i<ar.size();i++)
        {
            if(i==0)
            {
                ans[i] = ar[i];
            }
            else
                ans[i] = max(ar[i],ans[i-1]);
        }
        
        return ans;
    }
    
    vector<long long int> rgt_mxz(vector<long long int> ar)
    {
        vector<long long int> ans(ar.size());
        
        for(int i=ar.size()-1;i>=0;i--)
        {
            if(i==ar.size()-1)
            {
                ans[i] = ar[i];
            }
            else
                ans[i] = max(ar[i],ans[i+1]);
        }
        
        return ans;
    }
    
    long long maxPoints(vector<vector<int>>& ar) 
    {
        int n = ar.size();
        int m = ar[0].size();
        
        vector<vector<long long int>> dp(n,vector<long long int>(m,0));
        
        for(int j=0;j<m;j++)
        {
            dp[0][j] = ar[0][j]; 
        }
        
        for(int i=1;i<n;i++)
        {
            vector<long long int> left(m,0), right(m,0);
            
            for(int j=0;j<m;j++)
            {
                left[j] = dp[i-1][j] + j;
                right[j] = dp[i-1][j] - j;
            }
            
            vector<long long int> rgt_mx = rgt_mxz(right);
            vector<long long int> lft_mx = lft_mxz(left);
            
            for(int j=0;j<m;j++)
            {
                dp[i][j] = max({ dp[i][j],  ar[i][j] - j + lft_mx[j] , ar[i][j] + j + rgt_mx[j] });
            }
            
        }
        
        long long int ans = 0;
        
        for(int i=0;i<m;i++)
        {
            ans = max(ans, dp[n-1][i]);
        }
        
        return ans;
    }
};