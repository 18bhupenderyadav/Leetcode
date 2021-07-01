class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        stack<int>s;
        
        vector<int>ar = nums; 
        
        ar.insert(ar.end(),nums.begin(),nums.end());
        
        vector<int>ans(nums.size(),-1); 
        
        for(int i=ar.size()-1;i>=0;i--)
        {
            
            while(!s.empty() && ar[s.top()]<=ar[i])
            { 
                s.pop();
            }
            
            if(!s.empty())
            {
                if(i<nums.size())
                    ans[i] = ar[s.top()];      
            }
            
            s.push(i);
        }
        
        return ans;
    }
};