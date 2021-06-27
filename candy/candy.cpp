class Solution {
public:
    int candy(vector<int>& ar) 
    {
        int i,j,n,ans=0,last;
        n=ar.size();
        
        int dpl[n],dpr[n],dp[n];
        
        for(i=0;i<n;i++)
            dpl[i]=dpr[i]=1;
        
        for(i=1;i<n;i++)
        {
            if(ar[i]>ar[i-1])
                dpl[i]=dpl[i-1]+1;
        }
        
        for(i=n-1;i>0;i--)
        {
            if(ar[i-1]>ar[i])
                dpr[i-1]=dpr[i]+1;
        }
        
        for(i=0;i<n;i++)
        {
            dp[i]=max(dpl[i],dpr[i]);
            ans+=dp[i];
        }
        
        return ans;
        
    }
};