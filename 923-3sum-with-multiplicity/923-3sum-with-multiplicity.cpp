class Solution {
public:
    const int mod=1e9+7;
    int tp(vector<int>& ar,int i,int t)
    {
        int r=ar.size()-1,l=i+1,ans=0;
        
        while(l<r)
        {
            int sum=ar[l]+ar[r];
            
            if(sum>t)
                r--;
            else if(sum<t)
                l++;
            else if(ar[l]!=ar[r])
            {
                int left=1,right=1;
                while(l+1<r && ar[l]==ar[l+1])
                {
                    left++;
                    l++;
                }
                while(r>l+1 && ar[r]==ar[r-1])
                {
                    right++;
                    r--;
                }
                
                ans+=left*right;
                if(ans>mod)
                    ans-=mod;
                l++;
                r--;
            }
            else
            {
                ans+=(r-l+1)*(r-l)/2;
                if(ans>mod)
                    ans-=mod;
                break;
            }
        }
        
        return ans;
    }
    int threeSumMulti(vector<int>& ar, int t) 
    {
        int ans=0,n=ar.size();
        
        sort(ar.begin(),ar.end());
        
        for(int i=0;i<n;i++)
        {
            int a=tp(ar,i,t-ar[i]);
            
            ans+=a;
            if(ans>mod)
                ans-=mod;
        }
        
        return ans;
    }
};