class Solution {
public:
    int memo[8][(1<<15)];
    int dp(int count,int mask,vector<int>& ar)
    {
        if(count>(ar.size()/2))
            return 0;
        
        if(memo[count][mask]!=-1)
            return memo[count][mask];
        
        int ans=0;
        for(int i=0;i<ar.size();i++)
        {
            for(int j=i+1;j<ar.size();j++)
            {
                int new_mask=(1<<i)+(1<<j);
                if(((mask & (1<<i))==0)&& (mask & (1<<j))==0)
                {
                    ans=max(ans,count*__gcd(ar[i],ar[j])+dp(count+1,mask|new_mask,ar));
                }
            }
        }

        return memo[count][mask]=ans;
    }
    int maxScore(vector<int>& nums) 
    {
        int count=1;
        memset(memo,-1,sizeof(memo));
        return dp(count,0,nums);
    }
};