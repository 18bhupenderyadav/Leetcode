class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        set<int> s;
        
        for(int i:nums)
        {
            if(s.insert(i).second)
            {
                auto k=s.find(i);
                
                k++;
                if(k!=s.end())
                {
                    s.erase(k);
                }
            }
        }
        
        return s.size();
    }
};