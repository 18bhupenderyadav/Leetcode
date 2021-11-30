class Solution {
public:
    const int mod=1e9+7;
    int maxSum(vector<int>& nums1, vector<int>& nums2) 
    {
        long long int ans=0;
        long long int a=0,b=0;
        
        int i=0,j=0;
        
        while(i<nums1.size() && j<nums2.size())
        {
            
            if(nums1[i]<nums2[j])
            {
                a+=nums1[i];
                i++;
            }
            else if(nums1[i]>nums2[j])
            {
                b+=nums2[j];
                j++;
            }
            else
            {
                ans+=max(a,b)%mod;
                ans+=nums1[i]%mod;
                ans%=mod;
                a=b=0;
                i++;
                j++;
            }
        }
        
        while(i<nums1.size())
        {
            a+=nums1[i]%mod;
            i++;
        }
        
        while(j<nums2.size())
        {
            b+=nums2[j]%mod;
            j++;
        }

        ans+=max(a,b)%mod;
        ans%=mod;
        
        return ans;
        
    }
};