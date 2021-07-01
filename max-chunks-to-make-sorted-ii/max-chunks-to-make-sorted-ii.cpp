class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) 
    {
        vector<int>sorted = arr;
        vector<int>mn = arr;
        mn.push_back(INT_MAX);
        
        sort(sorted.begin(),sorted.end());
        
        int mx = -1;
        int ans = 0;
        
        for(int i=arr.size()-2;i>=0;i--)
        {
            mn[i] = min(mn[i],mn[i+1]);
        }
        
        for(int i=0;i<arr.size();i++)
        {
            
            mx = max(mx,arr[i]);
            
            if(mx==sorted[i] && mn[i+1]>=mx)
            {
                ans++;
                mx = -1;
            }
        }
        
        return ans;
        
    }
};