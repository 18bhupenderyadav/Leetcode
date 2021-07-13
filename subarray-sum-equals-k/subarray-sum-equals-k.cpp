class Solution {
public:
    int subarraySum(vector<int>& ar, int k) 
    {
        int sum=0,ans=0,n=ar.size();
        
        unordered_map<int,int> mp;
        
        mp[0]=1;
        
        for(int i=0;i<n;i++)
        {
            sum+=ar[i];
            if(mp[sum-k])
                ans+=mp[sum-k];
            mp[sum]++;
        }
        return ans;
    }
};