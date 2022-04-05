class Solution {
public:
    int maxArea(vector<int>& ar) 
    {
        int ans = 0, n=ar.size();
        int l = 0, r=n-1;
        
        while(l<r)
        {
            ans = max(ans,(r-l) * min(ar[l],ar[r]));
            if(ar[l]>ar[r])
                r--;
            else
                l++;
        }
        
        return ans;
        
    }
};