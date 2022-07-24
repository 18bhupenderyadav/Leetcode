class Solution {
public:
    int countbits(int num)
    {  
        int sum = 0;
         
        for(int i=0;i<32;i++)
        {
            sum += (((1<<i)&num)!=0); 
        }
        
        return sum;   
    }
    long long countExcellentPairs(vector<int>& nums, int k)
    {
        
        long long int ans = 0;
    
        vector<int>cnt(32,0);
        unordered_set<int>s;
        
        for(int i=0;i<nums.size();i++)
        {
            if(s.find(nums[i])==s.end())
            {  
                s.insert(nums[i]);
                int set_bits = countbits(nums[i]);
                cnt[set_bits]++;
            }
        }
        
        for(int i=0;i<32;i++)
        {
            for(int j=0;j<32;j++)
            {
                if(i+j>=k)
                {
                    ans += (1ll*cnt[i]*cnt[j]);
                }  
            }
        }
        
        return ans;
    }
};