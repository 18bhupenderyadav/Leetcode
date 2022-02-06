class Solution {
public:
    int memo[305];
    bool dp(int pos, string& s,set<string>& dict)
    {
        if(pos>=s.size())
            return true;
        
        if(memo[pos]!=-1)
            return memo[pos];
        
        string temp="";
        bool ans = 0;
        for(int i=pos;i<s.size();i++)
        {
            temp+=s[i];
            if(dict.find(temp)!=dict.end())
                ans = ans | dp(i+1,s,dict);
        }
        
        return memo[pos]=ans;
    }
    
    
    bool wordBreak(string st, vector<string>& ar) 
    {
        set<string> s;
        
        for(string i:ar)
            s.insert(i);
        
        memset(memo,-1,sizeof(memo));
        return dp(0,st,s);
    }
};