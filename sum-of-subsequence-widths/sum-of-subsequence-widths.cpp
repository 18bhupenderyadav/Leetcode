class Solution {
public:
    const int mod = 1e9+7;
    int pw(int x, int y)
    {
        if(x==0)
        {
            return 0;
        }
        if(y==0)
        {
            return 1;
        }
        
        long ans;
        if(y%2==0)
        {
            ans = pw(x,y/2);
            ans = (ans*ans) % mod;
        }
        
        else
        {
            ans = x%mod;
            ans = (ans * pw(x,y-1)%mod)%mod;
        }
        return (ans + mod)%mod; 
        
    }
    int sumSubseqWidths(vector<int>& nums) 
    {
         
        sort(nums.begin(),nums.end());
        
        long long int ans = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            ans += (long long)nums[i]*(long long)pw(2,i);
            ans+=mod;
            ans%=mod;
            
        }
        
        for(int i=0;i<nums.size();i++)
        { 
            ans -= ((long long)nums[i]*(long long)pw(2,nums.size()-1-i));
            ans+=mod;
            ans%=mod;
        }
        
        
        return ans;
        
    }
};