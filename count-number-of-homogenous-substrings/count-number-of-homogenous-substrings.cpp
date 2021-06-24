class Solution {
public:
    const int mod=1e9+7;
    int countHomogenous(string s) 
    {
        int n=s.length();
        
        long long int ans=0,cnt=1;
        
        for(int i=1;i<n;i++)
        {
            if(s[i]==s[i-1])
            {
                cnt++;
            }
            else
            {
                ans+=(cnt*(cnt+1)/2);
                ans%=mod;
                cnt=1;
            }
        }
        ans+=(cnt*(cnt+1)/2);
        ans%=mod;
        
        return ans;
    }
};

// two pointer + math