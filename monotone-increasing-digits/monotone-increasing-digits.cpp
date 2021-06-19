class Solution {
public:
    long long int ans=0;
    void dp(long long int cur,long long int n)
    {
        if(cur>n)
            return;

        // cout<<cur<<endl;
        int ls=cur%10;
        for(int i=ls;i<10;i++)
        {
            if(cur*10+i<=n)
            {
                // cout<<cur*10+i<<endl;
                ans=max(ans,cur*10+i);
                dp(cur*10+i,n);
            }
        }

        return;
    }
    int monotoneIncreasingDigits(int n) 
    {
        if(n<=10)
        return min(n,9);
        ans=0;
        for(int i=1;i<10;i++)
        {
            dp(i,n);
        }
        return ans;
    }
};