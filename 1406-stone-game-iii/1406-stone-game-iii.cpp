class Solution {
public:
    int memo[50000+5][3];
    int dp(int pos,int turn, vector<int>& ar)
    {
        if(pos>=ar.size())
            return 0;
        
        if(memo[pos][turn]!=-1)
            return memo[pos][turn];
        
        int ans = 0;
        if(turn)
        {
            ans = INT_MAX/2;
            int j = 0,sum=0;
            for(int i=pos;i<ar.size() && j<3;i++,j++)
            {
                sum+=ar[i];
                ans = min(ans,-sum+dp(i+1,0,ar));
            }
        }
        else
        {
            ans = INT_MIN/2;
            int j = 0,sum=0;
            for(int i=pos;i<ar.size() && j<3;i++,j++)
            {
                sum+=ar[i];
                ans = max(ans,sum+dp(i+1,1,ar));
            }
        }
        
        return memo[pos][turn] = ans;
    }
    string stoneGameIII(vector<int>& ar) 
    {
        memset(memo,-1,sizeof(memo));
        int ans = dp(0,0,ar);
        
        if(ans>0)
            return "Alice";
        if(ans<0)
            return "Bob";
        
        return "Tie";
    }
};