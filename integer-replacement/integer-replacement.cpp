class Solution {
public:
    long long int dp(long long int n)
    {
        if(n==1)
            return 0;
        if(n%2==0)
            return 1+dp(n/2);
        return 1+min(dp(n+1),dp(n-1));
    }
    int integerReplacement(int n) 
    {
        return dp(n);
    }
};

// 1-0
// 2-1
// 3-2
// 4-2
// 5-3
// 6-3
// 7-4
// 8-3
// 9-4
// 10-4
// 11-5
// 12-4
// 13-5
// 14-5
// 15-5
