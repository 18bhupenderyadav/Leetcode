class Solution {
public:
    
    int memo[34][2][2];
    
    string tob(int n)
    {
        string ans="";
        while(n!=0)
        {
            ans+=to_string(n%2);
            n/=2;
        }
        
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    
    int dp(int pos,int restricted,int prev,string& s)
    {
        if(pos==s.length())
        {
            return 1;
        }
        
        if(memo[pos][restricted][prev]!=-1)
            return memo[pos][restricted][prev];
        
        int limit = (restricted==1) ? s[pos]-'0' : 1;
        int ans=0;
        
        for(int i=0;i<=limit; i++)
        {
            int new_restricted=restricted;
            if(i<limit)
            {
                new_restricted=0;
            }
            
            if(prev==1)
            {
                //can add only 0
                if(i==0)
                {
                    ans+=dp(pos+1,new_restricted,0,s);
                }
            }
            else
            {
                ans+=dp(pos+1,new_restricted,i,s);
            }
        }
        
        return memo[pos][restricted][prev]=ans;
    }
    
    
    int findIntegers(int n) 
    {
        
        string s=tob(n);
        
        memset(memo,-1,sizeof(memo));
        return dp(0,1,0,s);
        
    }
};