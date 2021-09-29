class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) 
    {
        vector<int> num=nums;
        vector<int> ans(105,0);
        
        sort(nums.begin(),nums.end());
            
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1])
                continue;
            else
                ans[nums[i]]=i;
        }
        
        int n=nums.size();
        vector<int> sol(n);
        
        for(int i=0;i<n;i++)
        {
            sol[i]=ans[num[i]];
        }
        
        return sol;
        
        
    }
};

// [8,1,2,2,3]
// [1,2,2,3,8]
// [0,1,1,3,4]
