class Solution {
public:
    int memo[505][505];
    int dp(int pos,int cnt,vector<int>& ar)
    {
        if(pos>=ar.size())
            return 0;
        
        if(memo[pos][cnt]!=-1)
            return memo[pos][cnt];
        int ans=dp(pos+1,cnt,ar);
        ans=max(ans,cnt*ar[pos]+dp(pos+1,cnt+1,ar));
        
        return memo[pos][cnt]=ans;
    }
    int maxSatisfaction(vector<int>& ar) 
    {
        sort(ar.begin(),ar.end());
        memset(memo,-1,sizeof(memo));
        return dp(0,1,ar);
    }
};