class Solution {
public:
    int dac(vector<int>& nums, int st, int end)
    {
        if(st>end)
        {
            return 0;
        }
        
        if(st==end)
        {
            if(nums[st]<=0)
            {
                return 0;
            }
            return 1;
        }
        
        for(int i=st;i<=end;i++)
        {
            if(nums[i]==0)
            {
                return max(dac(nums,st,i-1),dac(nums,i+1,end));
            }
        }
        
        int n_cnt = 0, first_n = -1 , last_n = -1;
        
        for(int i=st;i<=end;i++)
        {
            if(nums[i]<0)
            {
                n_cnt^=1;
                if(first_n==-1)
                {
                    first_n = i;
                }
                last_n = max(last_n,i);
            }
        }
        
        if(n_cnt==0)
        {
            return (end-st+1);
        }
        
        return max(end-(first_n+1)+1 , (last_n-1)-st+1);
    }
    int getMaxLen(vector<int>& nums) 
    {
        return dac(nums,0,nums.size()-1);
    }
};