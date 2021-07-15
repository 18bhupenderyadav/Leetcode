class Solution {
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        if(a[0]==b[0])
        {
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
public: 
    
    int maxEnvelopes(vector<vector<int>>& envelopes) 
    {
        sort(envelopes.begin(),envelopes.end(),cmp);
        
        set<int> s;
        
        for(int i=0;i<envelopes.size();i++)
        {
            if(s.insert(envelopes[i][1]).second)
            {
                auto it = s.find(envelopes[i][1]);
                it++;
                if(it!=s.end())
                {
                    s.erase(it);
                }
            }
        }
        return s.size();
    }
};