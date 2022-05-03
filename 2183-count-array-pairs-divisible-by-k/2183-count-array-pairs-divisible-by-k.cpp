class Solution {
public:
    long long countPairs(vector<int>& ar, int k) 
    {
        long long int ans = 0,cnt=0;
        map<long long int,long long int> mp;
        
        int mx=ar[0];
        
        for(long long int i=0;i<ar.size();i++)
        {
            mx = max(mx,ar[i]);
            ar[i] = __gcd(ar[i],k);
        }
        
        for(long long int i=0;i<ar.size();i++)
        {
            long long int a = ar[i];
            
            for(auto& [b,cnt]:mp)
            {
                if((a*b)%k==0)
                    ans+=cnt;
            }
            
            mp[a]++;

        }
        
        return ans;
    }
};