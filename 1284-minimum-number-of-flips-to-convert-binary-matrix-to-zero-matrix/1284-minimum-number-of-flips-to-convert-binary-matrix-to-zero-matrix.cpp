class Solution {
public:
    void add(vector<vector<int>>& ar,int i,int j)
    {
        int n=ar.size(),m=ar[0].size();
        ar[i][j]++;
        if(i+1<n)
            ar[i+1][j]++;
        if(i-1>=0)
            ar[i-1][j]++;
        if(j+1<m)
            ar[i][j+1]++;
        if(j-1>=0)
            ar[i][j-1]++;
    }
    
    bool set(int bit,int cnt)
    {
        return ((bit>>cnt) & 1);
    }
    
    int cnt(vector<vector<int>>& ar,int bit)
    {
        int ans=0;
        int cnt=0,n=ar.size(),m=ar[0].size();
        
        vector<vector<int>> temp(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(set(bit,cnt))
                {
                    add(temp,i,j);
                }
                cnt++;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(ar[i][j]==0)
                {
                    if(temp[i][j]%2==1)
                        return INT_MAX;
                }
                else
                {
                    if(temp[i][j]%2==0)
                        return INT_MAX;
                }
            }
        }
        
        while(bit)
        {
            ans+=bit%2;
            bit/=2;
        }
        
        return ans;
        
    }
    int minFlips(vector<vector<int>>& ar) 
    {
        int ans=INT_MAX;
        int n=ar.size();
        int m=ar[0].size();
        
        for(int bit=0;bit<=(int)pow(2,n*m);bit++)
        {
            ans=min(ans,cnt(ar,bit));
        }
        
        if(ans==INT_MAX)
            ans=-1;
        return ans;
    }
};