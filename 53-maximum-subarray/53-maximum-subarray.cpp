class Solution {
public:
    int ans = 0;
    long long int memo[100000+5];
    int dp(int pos,vector<int>& ar)
    {
        if(pos==0)
        {
            ans=max(ans,ar[pos]);
            return ar[pos];
        }
        
        if(memo[pos]!=-1)
            return memo[pos];
        
        
        ans=max(ans,max(ar[pos]+dp(pos-1,ar),ar[pos]));
        
        return memo[pos]=max(ar[pos]+dp(pos-1,ar),ar[pos]);
    }
    int maxSubArray(vector<int>& nums) {
        ans=nums[0];
        memset(memo,-1,sizeof(memo));

        dp(nums.size()-1,nums);
        return ans;
    }
};