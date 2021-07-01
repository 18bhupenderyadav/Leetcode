class Solution {
public:
    bool find132pattern(vector<int>& nums)
    {
        
        int n = nums.size();
        vector<int>mn(n,0);
        mn[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            mn[i] = min(mn[i-1],nums[i]);
        }
        
        stack<int>s;
        
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() && s.top()<=mn[i])
            {
                s.pop();
            }
            if(!s.empty() && nums[i]>s.top())
            {
                return true;
            }
            s.push(nums[i]);
                
        }
        return 0;
    }
};