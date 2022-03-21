class Solution {
public:
    bool check(vector<int>& ar,int req_sum,int m)
    {
        int sum=0,ans=1;
        for(int i=0;i<ar.size();i++)
        {
            if(ar[i]>req_sum)
                return 0;
            if(sum+ar[i]>req_sum)
            {
                sum=0;
                ans++;
            }
            sum+=ar[i];
        }
        
        return ans<=m;
    }
    int splitArray(vector<int>& ar, int m) 
    {
        long long int low=-1,high=1e8;
        
        while(low+1<high)
        {
            long long int mid = (low+high)/2;

            if(check(ar,mid,m))
                high=mid;
            else
                low=mid;
        }
        
        return high;
    }
};