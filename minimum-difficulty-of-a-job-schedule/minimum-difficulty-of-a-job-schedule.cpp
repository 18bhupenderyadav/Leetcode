class Solution {
public:
    const int inf=1e8;
    int memo[10][301];
    int dp(vector<int>& ar,int d,int n)
    {
        if(n<0)
            return inf;
        if(d==0)
        {
            int mx=0;
            for(int i=n;i>=0;i--)
                mx=max(mx,ar[i]);
            return mx;
        }
        
        if(memo[d][n]!=-1)
            return memo[d][n];
        
        int mx=0;
        int ans=inf;
        for(int i=n;i>=0;i--)
        {
            mx=max(mx,ar[i]);
            ans=min(ans,mx+dp(ar,d-1,i-1));
        }
        
        return memo[d][n]=ans;
    }
    
    int minDifficulty(vector<int>& ar, int d) 
    {
        memset(memo,-1,sizeof(memo));
        int ans=dp(ar,d-1,ar.size()-1);
        if(ans==(int)1e8)
            ans=-1;
        return ans;
    }
};