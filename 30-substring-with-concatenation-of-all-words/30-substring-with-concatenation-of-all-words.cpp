class Solution {
public:
    bool check(unordered_map<string,int> mp,string s, int wrdlen)
    {
        for(int j = 0;j<s.size();j+=wrdlen)
        {
            string temp = s.substr(j,wrdlen);
            if(mp.find(temp)!=mp.end())
            {
                if(mp[temp]==0)
                    return 0;
                mp[temp]--;
            } 
            else
                return 0;
        }
        
        return 1;
    }
    vector<int> findSubstring(string s, vector<string>& words) 
    {
        unordered_map<string,int> mp;
        
        for(string i: words)
            mp[i]++;
        
        int wrdlen = words[0].size();
        
        int i = 0;
        vector<int> ans;
        
        while(i + wrdlen * words.size() <= s.size())
        {
            if(check(mp,s.substr(i,wrdlen*words.size()),wrdlen))
                ans.push_back(i);
            
            i++;
        }
        
        return ans;
    }
};