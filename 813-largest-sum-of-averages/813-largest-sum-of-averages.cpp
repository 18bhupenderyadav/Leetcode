class Solution {
public:
    double memo[110][110];
    double dp(vector<int>& ar,int n,int k)
    {
        if(k<0)
        {
            return -100000;
        }
        if(k==1)
        {
            double sum=0,cnt=0;
            for(int i=n;i>=0;i--)
            {
                sum+=ar[i];
                cnt++;
            }
            
            return sum/cnt;
        }
        
        if(n<0)
            return 0;
        
        if(memo[n][k]!=0)
            return memo[n][k];
        
        double sum=0,cnt=0,ans=0;
        
        for(int i=n;i>=0;i--)
        {
            sum+=ar[i];
            cnt++;
            ans=max(ans,sum/cnt+dp(ar,i-1,k-1));
        }
        
        return memo[n][k]=ans;
    }
    double largestSumOfAverages(vector<int>& nums, int k) 
    {
        // memset(memo,(double)-1,sizeof(memo));
        return dp(nums,nums.size()-1,k);
    }
};