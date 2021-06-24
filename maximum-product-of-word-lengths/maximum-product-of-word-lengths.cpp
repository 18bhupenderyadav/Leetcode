class Solution {
public:
    int maxProduct(vector<string>& ar) 
    {
        int n=ar.size();
        vector<int> msk(n,0);
        
        for(int i=0;i<n;i++)
        {
            int mask=0;
            
            for(int j=0;j<ar[i].size();j++)
            {
                mask=mask|(1<<(ar[i][j]-'a'));
            }
            
            msk[i]=mask;
        }
        
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if((msk[i] & msk[j])==0)
                {
                    ans=max(ans,(int)ar[i].size()*(int)ar[j].size());
                }
            }
        }
        
        return ans;
    }
};

// Bitmasks