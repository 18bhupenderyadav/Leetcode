class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        
        stack<int>s;
        vector<int>ans(nums1.size(),-1);
        
        unordered_map<int,int>mp;
        
        for(int i=nums2.size()-1;i>=0;i--)
        {
            
             while(!s.empty() && nums2[s.top()]<nums2[i])
             {
                 s.pop(); 
             }
             
             if(!s.empty())
             {
                 mp[nums2[i]] = nums2[s.top()];
             }
            
             s.push(i);
            
        }
        
        for(int i=0;i<nums1.size();i++)
        {
            if(mp.find(nums1[i])!=mp.end())
            {
                ans[i] = mp[nums1[i]];
            }
        }
        
        return ans;
    }
};