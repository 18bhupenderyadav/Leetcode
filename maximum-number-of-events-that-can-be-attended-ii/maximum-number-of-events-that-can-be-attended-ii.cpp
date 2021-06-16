class Solution {
public:
    int dp(int pos,int k,vector<vector<int>>& ar,vector<vector<int>>& memo)
    {
        if(pos>=ar.size())
            return 0;
        if(k==0)
            return 0;
        
        if(memo[pos][k]!=-1)
            return memo[pos][k];
        
        int next=ar.size()+1;
        
        for(int i=pos+1;i<ar.size();i++)
        {
            if(ar[i][0]>ar[pos][1])
            {
                next=i;
                break;
            }
        }
        
        int ans=0;
        ans=max(ans,dp(next,k-1,ar,memo)+ar[pos][2]);
        
        ans=max(ans,dp(pos+1,k,ar,memo));
        
        return memo[pos][k]=ans;
    }
    int maxValue(vector<vector<int>>& ar, int k) 
    {
        auto cmp = [&] (vector<int>& i, vector<int>& j)
        {
            return i[0]<j[0];
        };
        
        sort(ar.begin(),ar.end(),cmp);
        
        vector<vector<int>> memo(ar.size()+10,vector<int>(k+5,-1));
        
        return dp(0,k,ar,memo);
    }
};