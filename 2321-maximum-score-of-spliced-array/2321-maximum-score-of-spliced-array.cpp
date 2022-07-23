class Solution {
public:
    int memo[100010][3][3];
    int dp(int pos, int cur,int restriction, vector<int>& ar, vector<int>& br)
    {
        if(pos>=ar.size())
            return 0;
        
        if(memo[pos][cur][restriction]!=-1)
            return memo[pos][cur][restriction];
        
        int ans = 0;
        if(cur == 1)
        {
            ans = max(ans, ar[pos] + dp(pos+1,cur,restriction,ar,br));
            
            if(!restriction)
            {
                ans = max(ans, ar[pos] + dp(pos+1,2,restriction,ar,br));
            }
        }
        else 
        {
            ans = max(ans, br[pos] + dp(pos+1,cur,restriction,ar,br));
            
            if(!restriction)
            {
                ans = max(ans, br[pos] + dp(pos+1,1,1,ar,br));
            }
        }
        
        return memo[pos][cur][restriction] = ans;
    }
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2)
    {
        memset(memo,-1,sizeof(memo));
        int ans = dp(0,1,0,nums1,nums2);
        
        memset(memo,-1,sizeof(memo));
        ans = max(ans, dp(0,1,0,nums2,nums1));
        
        return ans;
    }
};