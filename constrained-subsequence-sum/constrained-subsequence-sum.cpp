class Solution {
public:
    int constrainedSubsetSum(vector<int>& ar, int k) 
    {
        
        int n = ar.size();
        vector<int>dp(n+5);
        
        int ans = ar[0];
        int mx  = INT_MIN; 
        
        multiset<int> s;
        
        dp[0]=ar[0];
        s.insert(dp[0]);
        
        for(int i=1;i<k;i++)
        {
            dp[i]=max(ar[i],ar[i]+(*s.rbegin()));
            s.insert(dp[i]);
            ans=max(ans,dp[i]);
        }
        
        
        for(int i=k;i<n;i++)
        {

            dp[i]=max(ar[i],ar[i]+(*s.rbegin()));
            s.erase(s.lower_bound(dp[i-k]));
            s.insert(dp[i]);
            ans=max(ans,dp[i]);
        }

        
        return ans;
    }
};