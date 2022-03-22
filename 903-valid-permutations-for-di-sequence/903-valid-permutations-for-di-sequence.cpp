class Solution {
public:
    const int mod = 1e9+7;
    int memo[201][201];
    int vis[201];
    int dp(int pos,int prev,string& s)
    {
        if(pos>=s.size())
            return 1;
        
        if(memo[pos][prev]!=-1)
            return memo[pos][prev];
        
        int ans=0;
        
        if(s[pos]=='D')
        {
            for(int i=0;i<=s.size();i++)
            {
                if(i<prev && vis[i]==1)
                {
                    vis[i]=0;
                    ans+=dp(pos+1,i,s)%mod;
                    ans%=mod;
                    vis[i]=1;
                }
            }
        }
        else
        {
            for(int i=0;i<=s.size();i++)
            {
                if(i>prev && vis[i]==1)
                {
                    vis[i]=0;
                    ans+=dp(pos+1,i,s)%mod;
                    ans%=mod;
                    vis[i]=1;
                }
            }
        }
        
        return memo[pos][prev]=ans;
    }
    int numPermsDISequence(string s) 
    {
        // cout<<s.size()<<endl;
        int ans=0;
        set<int> num;
        for(int i=0;i<=s.size();i++)
            vis[i]=1;
        
        memset(memo,-1,sizeof(memo));
        for(int i=0;i<=s.size();i++)
        {
            
            vis[i]=0;
            ans+=dp(0,i,s)%mod;
            ans%=mod;
            vis[i]=1;
        }
        
        return ans;
    }
};