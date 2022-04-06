class MagicDictionary {
public:
    // vector<vector<int>> nxt;
    map<string,int> mp,al;
    MagicDictionary() 
    {
        mp.clear();
    }
    
    void buildDict(vector<string> ar) 
    {
        for(int i=0;i<ar.size();i++)
        {
            // string s = ar[i];
            for(int j=0;j<ar[i].size();j++)
            {
                char a = ar[i][j];
                ar[i][j] = '#';
                mp[ar[i]]++;;
                ar[i][j] = a;
            }
            al[ar[i]];
        }
    }
    
    bool search(string s) 
    {
        int flag = 0;
        if(al.find(s)!=al.end())
            flag = 1;
        
        if(flag == 1)
        {
            int mx = 0;
            for(int i=0;i<s.size();i++)
            {
                char a = s[i];
                s[i] = '#';
                if(mp.find(s)!=mp.end())
                    mx = max(mx,mp[s]);
                s[i] = a;
            }
            
            return mx>1;
        }
        
        
        for(int i=0;i<s.size();i++)
        {
            char a = s[i];
            s[i] = '#';
            if(mp.find(s)!=mp.end())
                return 1;
            s[i] = a;
        }
        
        return 0;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
