class Solution {
public:
    int findKthNumber(int m, int n, int k) 
    {
        long long int lo=0,hi=2e10;
        
        auto check = [&](long long int mid)
        {
            long long int cnt=0;
            
            for(int i=0;i<m;i++)
            {
                cnt+= min(1ll*(mid/(i+1)),1ll*n);
            }
            
            if(cnt<k)
                return 1;
            return 0;
        };
        
        while(lo+1<hi)
        {
            long long int mid=(lo+hi)/2;

            if(check(mid))
            {
                lo=mid;
            }
            else
                hi=mid;
        }
        
        return hi;
    }
};