class Solution {
public:
    int memo[505][505];
    int dp(int i,int j,vector<int>& ar)
    {
        if(i>=j)
            return 0;
        
        if(memo[i][j]!=-1)
            return memo[i][j];
        
        int tot=0;
        for(int k=i;k<=j;k++)
        {
            tot+=ar[k];
        }
        
        int ans=0;
        int rsum=0;
        
        for(int k=i;k<j;k++)
        {
            rsum+=ar[k];
            int left=rsum;
            int right=tot-rsum;          
            if(left<right)
            {
                ans=max(ans,left+dp(i,k,ar));
            }
            else if(right<left)
            {
                ans=max(ans,right+dp(k+1,j,ar));
            }
            else
            {
                ans=max({ans,left+dp(i,k,ar),right+dp(k+1,j,ar)});
            }
            
            
        }
        
        return memo[i][j]=ans;
    }
    int stoneGameV(vector<int>& ar) 
    {
        memset(memo,-1,sizeof(memo));
        return dp(0,ar.size()-1,ar);
    }
};