class Solution {
public:
    vector<int> topKFrequent(vector<int>& ar, int k) 
    {
        unordered_map<int,int> mp;
        int n = ar.size();
        for(int i=0;i<n;i++)
        {
            mp[ar[i]]++;
        }
        
        vector<vector<int>> buck(n+1);
        
        for(auto i:mp)
        {
            buck[i.second].push_back(i.first);
        }
        
        vector<int> ans;
        
        for(int i=n;i>=0;i--)
        {
            if(ans.size()==k)
                break;
            for(int j=0;j<buck[i].size();j++)
                ans.push_back(buck[i][j]);
        }
        
        return ans;
    }
};