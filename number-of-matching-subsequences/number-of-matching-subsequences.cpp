class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) 
    {
        vector<vector<int>> dp(26);
        
        for(int i=0;i<s.size();i++)
        {
            dp[s[i]-'a'].push_back(i);
        }
        
        int ans=0;

        
        for(auto& wr:words)
        {
            int last=-1;
            int flag=1;
            for(int i=0;i<wr.size();i++)
            {
                int c=wr[i]-'a';
                auto it=upper_bound(dp[c].begin(),dp[c].end(),last);
                if(it == dp[c].end())
                {
                    flag=0;
                    break;
                }
                last=*it;
            }

            ans+=flag;
        }
        
        return ans;
    }
};