class Solution {
public:
    
    int countServers(vector<vector<int>>& ar) 
    {
        int n=ar.size(),m=ar[0].size();
        vector<int> row(n),col(m);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(ar[i][j])
                {
                    row[i]++;
                    col[j]++;
                }
            }
        }
        
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(ar[i][j])
                {
                    if(row[i]>1 || col[j]>1)
                        ans++;
                }
            }
        }
        
        return ans;
    }
};