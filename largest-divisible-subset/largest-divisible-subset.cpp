class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        
        vector<pair<int,int>> dp(n,{1,-1});
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0)
                {
                    if(dp[i].first<dp[j].first+1)
                    {
                        dp[i].first=dp[j].first+1;
                        dp[i].second=j;
                    }
                }
            }
        }
        
        int ans=1;
        int pos=0;
        
        for(int i=0;i<n;i++)
        {
            if(dp[i].first>ans)
            {
                ans=dp[i].first;
                pos=i;
            }
        }
        
        vector<int> sol;

        while(pos!=-1)
        {
            sol.push_back(nums[pos]);
            pos=dp[pos].second;
        }
        
        return sol;
        
    }
};