class Solution {
public:
    int memo[10002];
    int dp(int pos,int prev,vector<int>& ar,int n)
    {
        if(prev>=n)
            return 0;
        
        if(pos>=ar.size()) 
            return INT_MAX/2;
        
        if(memo[prev]!=-1)
            return memo[prev];
        
        int ans = INT_MAX;
        
        ans = min(ans,dp(pos+1,prev,ar,n));
        
        if(pos-ar[pos]<=prev)
            ans = min(ans,1+dp(pos+1,pos+ar[pos],ar,n));
        
        return memo[prev] = ans;
    }
    int minTaps(int n, vector<int>& ar) {
        memset(memo,-1,sizeof(memo));
        long long int ans =  dp(0,0,ar,n);
        if(ans>ar.size())
            ans = -1;
        
        return ans;
    }
};