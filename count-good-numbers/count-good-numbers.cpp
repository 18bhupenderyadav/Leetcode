class Solution {
public: 
    int mod = 1e9+7;
    long long int p(long long int a, long long int b)
    {
        if(b==0)
        {
            return 1; 
        }
        if(a==0)
        {
            return 0;
        } 
        
        if(b%2)
        {
            return a*p(a*a%mod,b/2)%mod; 
        } 
        
        return p(a*a%mod,b/2)%mod;
    }
    int countGoodNumbers(long long n) 
    {
        
         if(n%2)
         {
             return (1ll*countGoodNumbers(n-1)%mod*5%mod)%mod;
         }
        
        return (p(5,n/2)%mod*p(4,n/2)%mod)%mod;
    }
};

// primes : 2 3 5 7
// evens : 0 2 4 6 8 

// n is even -
// n/2 : primes  = 4^n/2 
// n/2 : evens  = 5^n/2
// tot = multiply

// n is odd - 
// f(n-1)*5