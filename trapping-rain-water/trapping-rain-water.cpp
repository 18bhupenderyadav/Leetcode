class Solution {
public:
    int trap(vector<int>& height) 
    {
        
        int n = height.size();
        vector<int>left(n,0) , right(n,0);
        
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                left[i] = height[i];
            }
            else
            {
                left[i] = max(height[i],left[i-1]);
            }
        }
        
        for(int i=n-1;i>=0;i--)
        {
            if(i==n-1)
            {
                right[i]=height[i];
            }
            else
            {
                right[i] = max(height[i],right[i+1]);
            }
        }
        
        int ans = 0;
        
        for(int i=1;i<n-1;i++)
        {
            ans += min(left[i],right[i])-height[i]; 
        }
        
        return ans;
        
        
    }
};