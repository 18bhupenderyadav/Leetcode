class Solution {
public:
    const int inf=1e9+10;
    int minDays(vector<int>& ar, int m, int k) 
    {
        if(m*k>ar.size())
            return -1;
        
        long long int n=ar.size();
        
        
        
        vector<int> temp;
            
        multiset<int> s;

        for(int i=0;i<k;i++)
        {
            s.insert(ar[i]);
        }

        temp.push_back(*s.rbegin());

        for(int i=1;i+k-1<n;i++)
        {
            s.erase(s.find(ar[i-1]));
            s.insert(ar[i+k-1]);
            temp.push_back(*s.rbegin());
        }
        
        // for(int i:temp)
        //     cout<<i<<" ";
        // cout<<endl;
        
        
        
        
        
        auto check = [&] (long long int mid)
        {
            long long int cnt=0;
            
            for(int i=0;i<temp.size();i++)
            {
                if(temp[i]<=mid)
                {
                    cnt++;
                    i+=k-1;
                }
            }

            return cnt;
        };
        
        long long int low=0,high=1e9+10;

        while(low+1<high)
        {
            long long int mid=(low+high+1)/2;
            if(check(mid)>=m)
            {
                high=mid;
            }
            else
                low=mid;
        }

        
        return high;
        
    }
};