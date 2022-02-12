class Solution {
public:
    int memo[(1<<16)][16];
    unordered_map<string,int> mp;
    
    string tos(int mask,int cnt)
    {
        string s="";
        s+=to_string(mask)+'-'+to_string(cnt);
        return s;
    }
    
    bool dp(vector<int>& ar,int& k,int& subsum,int mask,int cnt,int cursum)
    {
        if(cursum==subsum)
        {
            //if k-2 subsets are formed then remaning elements will form 
            // the last subset.
            if(cnt==k-2)
                return 1;
            
            return dp(ar,k,subsum,mask,cnt+1,0);
        }
        
        // if(memo[mask][cnt]!=-1)
        //     return memo[mask][cnt];
        
        string s = tos(mask,cnt);
        
        if(mp.find(s)!=mp.end())
            return mp[s];
        
        for(int i=ar.size()-1;i>=0;i--)
        {
            if(mask & (1<<i))
                continue;
            
            int temp=cursum+ar[i];
            
            if(temp<=subsum)
            {
                int new_mask=mask|(1<<i);
                
                bool ans=dp(ar,k,subsum,new_mask,cnt,temp);
                if(ans)
                {
                    // return memo[mask][cnt]=1;
                    return mp[s]=1;
                }
            } 
            
        }
        
        // return memo[mask][cnt]=0;
        return mp[s]=0;

    }
    bool canPartitionKSubsets(vector<int>& ar, int k)
    {
        int n=ar.size();
        if(k==1)
            return 1;
        if(n<k)
            return 0;
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=ar[i];
        if(sum%k!=0)
            return 0;
        
        int subsum=sum/k;
        
        memset(memo,-1,sizeof(memo));
        return dp(ar,k,subsum,0,0,0);
    }
};