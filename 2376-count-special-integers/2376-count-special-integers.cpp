class Solution {
public:
    
    int dp(int pos,int restriction,int nonzero, string& num,int mask)
    {
        if(pos>= num.size())
        {
            return 1;
        }
                
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
        
        return ans;
    }
    int countSpecialNumbers(int n) {

        string num = to_string(n);
        
        return dp(0,1,0,num,0)-1;
    }
};