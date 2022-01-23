class Solution {
public:
    int memo[14][(1<<14)+5];
    int dp(vector<int>& ar,vector<int>& br,int pos,int mask)
    {
        if(pos==ar.size())
            return 0;
        if(memo[pos][mask]!=-1)
            return memo[pos][mask];
        
        int ans=INT_MAX;
        for(int i=0;i<ar.size();i++)
        {
            if((mask&(1<<i))==0)
            {
                int new_mask=mask|(1<<i);
                ans=min(ans,(ar[pos]^br[i])+dp(ar,br,pos+1,new_mask));
            }
        }
        
        return memo[pos][mask]=ans;
    }
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2)
    {
        memset(memo,-1,sizeof(memo));
        return dp(nums1,nums2,0,0);
    }
};