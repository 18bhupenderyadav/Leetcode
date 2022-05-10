class Solution {
public:
    int memo[105][105][215];
    int func(char c)
    {
        if(c=='(')
            return 1;
        return -1;
    }
    int dp(int i,int j,int cnt,vector<vector<char>>& ar)
    {
        if(cnt<0)
            return 0;
        if(i==ar.size()-1 && j==ar[0].size()-1)
        {
            cnt+=func(ar[i][j]);
            
            if(cnt==0)
                return 1;
            return 0;
        }
        
        if(memo[i][j][cnt+5]!=-1)
            return memo[i][j][cnt+5];
        
        int ans = 0;
        if(i+1<ar.size())
        {
            ans = ans | dp(i+1,j,cnt+func(ar[i][j]),ar);
        }
        if(j+1<ar[0].size())
        {
            ans = ans | dp(i,j+1,cnt+func(ar[i][j]),ar);
        }
        
        return memo[i][j][cnt+5]=ans;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        memset(memo,-1,sizeof(memo));
        return dp(0,0,0,grid);
    }
};