class Solution {
public:
    long long int lcm(long long int a,long long int b)
    { 
        
        return (a*b)/__gcd(a,b);
    }
    bool f(long long int mid, int a, int b, int c, int n)
    {
        long long int ans = 0;
        ans += mid/a + mid/b + mid/c;
        ans -= (mid/lcm(a,b) + mid/lcm(b,c) + mid/lcm(a,c));
        ans += mid/lcm(a,lcm(b,c));
        
        return ans<n;
    }
    int nthUglyNumber(int n, int a, int b, int c) 
    {
        long long int low = min({a,b,c})-1 , high = 1e18;
        
        while(low+1<high)
        {
            long long int mid = low + (high-low)/2;
            
            if(f(mid,a,b,c,n))
            {
                low = mid;
            }
            else
            {
                high = mid;
            }
        }
        return high; 
    }
};