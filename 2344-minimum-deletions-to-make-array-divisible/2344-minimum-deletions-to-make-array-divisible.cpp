class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& ar) 
    {
        int gcd = 0;
        
        for(int i: ar)
            gcd = __gcd(i,gcd);
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++)
        {
            if(gcd%nums[i] == 0)
                return i;
        }
        
        return -1;
        
    }
};