class Solution {
public:   
    int minAbsDifference(vector<int>& nums, int goal) 
    {
       
        vector<long long int> left = {0}, right = {0};
        
        for(int i=0;i<nums.size()/2;i++)
        {
            int t = left.size();
            for(int j=0;j<t;j++)
            {
                left.push_back(left[j]+nums[i]);
            }
        }
        
        for(int i=nums.size()/2;i<nums.size();i++)
        {
            int t = right.size();
            for(int j=0;j<t;j++)
            {
                right.push_back(right[j]+nums[i]);
            }
        }
        
        set<long long int> first,second;
        
        long long int ans = INT_MAX;
        
        for(long long int i: left)
        {
            first.insert(i);
            ans=min(ans,abs(goal-i));
        }
        
        for(long long int i:right)
        {
            second.insert(i);
            ans=min(ans,abs(goal-i));
        }
        
        
        
        for(long long int i : first)
        {
            
            int req = goal - i;
            
            auto it=second.lower_bound(req);
            
            if(it!=second.end())
            {
                ans=min(ans,abs(goal-i-*it));
                auto it2=it;
                it2++;
            
                if(it2!=second.end())
                {
                    ans=min(ans,abs(goal-i-*it2));
                }
            }
            
            if(it!=second.begin())
            {
                it--;
                ans=min(ans,abs(goal-i-*it));
            }
        }
        
        return ans;
    }
};