class Solution {
public: 
    const int mod = 1e9+7;
    void make_options(vector<string>& options, string& curr, int m)
    {
        if(m==0)
        {
            options.push_back(curr);
            return ;
        }
        
        char prev = curr.back();
        for(int i=1;i<=3;i++)
        {
            if(i!=prev-'0')
            {
                curr += i+'0';
                make_options(options,curr,m-1);
                curr.pop_back();
            }
        }
        
        return ;
    }
    int cnt(vector<string>& options, int n , int prev, vector<vector<int>>& dp)
    {
        if(n==0)
        {
            return 1;
        }
        if(dp[n][prev]!=-1)
        {
            return dp[n][prev];
        }
        
        int ans = 0;
        for(int i=0;i<options.size();i++)
        {
            bool check = true;
            for(int j=0;j<options[i].size();j++)
            {
                if(options[i][j]==options[prev][j])
                {
                    check = false;
                    break;
                }
            }
            if(check)
            {
                ans += cnt(options,n-1,i,dp);
                ans %= mod;
            }
        }
        
        return dp[n][prev]=ans;
    }
    int colorTheGrid(int m, int n) 
    {
        
        vector<string>options;
        string curr = "";
        
        for(int i=1;i<=3;i++)
        {
            curr += i+'0';
            make_options(options,curr,m-1);
            curr.pop_back();
        }
        
        vector<vector<int>> dp(n+5,vector<int>(options.size()+5,-1));
        
        int ans = 0;
        
        for(int i=0;i<options.size();i++)
        {
            ans += cnt(options,n-1,i,dp);
            ans %= mod;
        }
        
        return ans;
    }
};