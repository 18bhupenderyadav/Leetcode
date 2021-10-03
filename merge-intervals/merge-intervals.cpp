class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& ar) 
    {
        sort(ar.begin(),ar.end());
        int n=ar.size();
        
        vector<vector<int>> ans;
        
        int st=ar[0][0],end=ar[0][1];
        
        for(int i=1;i<n;i++)
        {
            if(ar[i][0]<=end)
                end=max(end,ar[i][1]);
            else
            {
                ans.push_back({st,end});
                st=ar[i][0];
                end=ar[i][1];
            }
        }
        ans.push_back({st,end});
        
        return ans;
    }
};