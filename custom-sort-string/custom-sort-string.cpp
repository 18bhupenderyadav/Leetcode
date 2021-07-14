class Solution {
public:
    string customSortString(string order, string str) 
    {
        vector<int> ord(26,400);
        for(int i=0;i<order.size();i++)
        {
            ord[order[i]-'a']=i;
        }
        
        auto cts = [&](char a,char b)
        {
            return ord[a-'a']<ord[b-'a'];
        };
        
        sort(str.begin(),str.end(),cts);
        
        return str;
    }
};