class Solution {
public:
    int memo[110][110];
    int dp(int pos,int rpos,string& ring,string& key)
    {
        if(pos>=key.size())
            return 0;
        
        if(memo[pos][rpos]!=-1)
            return memo[pos][rpos];
        
        int ans = INT_MAX;
        
        if(ring[rpos]==key[pos])
        {
            ans = min(ans, 1 + dp(pos+1,rpos,ring,key));
        }
        int n = ring.size();
        for(int i=1;i<n;i++)
        {
            if(ring[(i+rpos)%n] == key[pos])
            {
                ans = min(ans, 1 + i + dp(pos+1,(i+rpos)%n,ring,key));
            }
        }
        
        for(int i=1;i<n;i++)
        {
            if(ring[((rpos-i)+n)%n] == key[pos])
            {
                ans = min(ans, 1 + i + dp(pos+1,((rpos-i)+n)%n,ring,key));
            }
        }
        
        return memo[pos][rpos]=ans;
        
    }
    int findRotateSteps(string ring, string key) 
    {
        memset(memo,-1,sizeof(memo));
        return dp(0,0,ring,key);
    }
};