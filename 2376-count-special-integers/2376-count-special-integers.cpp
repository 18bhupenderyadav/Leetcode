class Solution {
public:
    
    int memo[12][2][1025];
    
    int dp(int pos,int restriction,int nonzero, string& num,int mask)
    {
        if(pos>= num.size())
            return 1;
        
        if(memo[pos][restriction][mask]!=-1)
            return memo[pos][restriction][mask];
                
        int last = 9;
        if(restriction)
            last = num[pos]-'0';

        
        int ans = 0;
        for(int i=0;i<=last;i++)
        {
            if((mask & (1<<i)))
                continue;
            
            int new_restriction = restriction;
            if(i < last)
                new_restriction = 0;
            
            if(i==0 and nonzero == 0)
            {
                ans+= dp(pos+1,new_restriction,0,num,mask);
                continue;
            }
            
            ans += dp(pos+1,new_restriction,1,num,mask|(1<<i));
        }
        
        return memo[pos][restriction][mask] = ans;
    }
    int countSpecialNumbers(int n) {

        string num = to_string(n);
        memset(memo,-1,sizeof(memo));
        return dp(0,1,0,num,0)-1;
    }
};