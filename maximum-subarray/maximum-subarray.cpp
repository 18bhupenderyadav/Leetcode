class Solution {
public:
    
    // Divide and Conquer in TC:O(NlogN) SC:O(1).     
    int mxcro(vector<int>& ar,int st,int mid,int ed)
    {
        int sum=0;
        int lsum=INT_MIN;
        for(int i=mid;i>=st;i--)
        {
            sum+=ar[i];
            lsum=max(lsum,sum);
        }
        
        sum=0;
        int rsum=INT_MIN;
        for(int i=mid+1;i<=ed;i++)
        {
            sum+=ar[i];
            rsum=max(sum,rsum);
        }
        
        return max({lsum,rsum,lsum+rsum});
    }
    int mxsub(vector<int>& ar,int st,int ed)
    {
        if(st==ed)
            return ar[st];
        
        int mid=(st+ed)/2;
        
        return max({mxsub(ar,st,mid),mxsub(ar,mid+1,ed),mxcro(ar,st,mid,ed)});
    }
    
    // Kadanes Algo in TC:O(N) SC:O(N).
    int kdmx(vector<int>& nums)
    {
        int sum =0,big = INT_MIN;
        for(int i: nums){
            sum = max(i,sum+i);
            big = max(big,sum);
        }
        return big;
    }
    
    
    int maxSubArray(vector<int>& nums) 
    {
        return mxsub(nums,0,nums.size()-1);
    }
};