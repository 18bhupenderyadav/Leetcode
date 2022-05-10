class Solution {
public:
    const int mod = 1e9+7;
    int time[10]={0,0,3,3,3,3,3,4,3,4};
    
    int memo[100000+10];
    
    int dp(int pos,string& s)
    {
        if(pos>=s.size())
            return 1;
        
        if(memo[pos]!=-1)
            return memo[pos];
        
        int ans = 0;
        int c = s[pos]-'0';
        int i = 0,times=time[c];
        
        for(int i=pos;i<s.size() && times>0;i++)
        {
            if(s[i]-'0' == c)
            {
                ans+=dp(i+1,s)%mod;
                ans%=mod;
            }
            else
            {
                break;
            }
            times--;
        }
        
        return memo[pos]=ans;
    }
    int countTexts(string s) 
    {
        memset(memo,-1,sizeof(memo));
        return dp(0,s);
    }
};