class Solution {
public:
    map<string,int> mp;
    int dp(string& s,string& t,int pos)
    {
        if(s==t)
            return 0;
        
        if(mp.find(s)!=mp.end())
            return mp[s];
        
        int ans = INT_MAX/2;
        
        while(pos<s.size() && s[pos]==t[pos])
            pos++;
        

            
        for(int j=pos+1;j<s.size();j++)
        {
            if(s[j]==t[pos])
            {
                swap(s[pos],s[j]);
                ans = min(ans,dp(s,t,pos+1)+1);
                swap(s[pos],s[j]);
            }
        }

        
        return mp[s]=ans;
    }
    int kSimilarity(string s, string t) 
    {
        return dp(s,t,0);
    }
};

