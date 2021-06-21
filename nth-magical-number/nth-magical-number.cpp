class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        int mod = 1e9+7;
        auto lcm = [&](int a, int b){
            return (a*b)/__gcd(a,b);
        };
        auto calc = [&](long long int x){
            return x/a + x/b - (long long int)(x/lcm(a,b)) ;
        };
        
        long long int low = 0 , high = 1e16;
        while(low+1<high){
            
            long long int mid = low+(high-low)/2;
            
            if(calc(mid)<n){
                low = mid;
            }
            else{
                high = mid;
            }
        }
        return high%mod;
        
    }
};