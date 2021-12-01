class Solution {
public:
    int smallestDistancePair(vector<int>& ar, int k) 
    {
        int n=ar.size();
        sort(ar.begin(),ar.end());
        
        int lo=-1,hi=ar[n-1]-ar[0]+4;
        
        auto check = [&] (int x)
        {
            int i=0;
            int ans=0;
            for(int j=0;j<n;j++)
            {
                while(ar[j]-ar[i]>x)
                    i++;
                ans+=j-i;
            }

            return ans;
        };
        
        while(lo+1<hi)
        {
            int mid=(lo+hi)/2;
            
            if(check(mid)<k)
            {
                lo=mid;
            }
            else
            {
                hi=mid;
            }
        }

        return hi;
    }
};