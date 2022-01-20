class Solution {
public:
    void print(vector<int>& ar)
    {
        for(int i=0;i<ar.size();i++)
            cout<<ar[i]<<" ";
        cout<<endl;
    }
    int minKBitFlips(vector<int>& ar, int k) 
    {
        int ans=0;
        
        int n=ar.size() , cnt=0 , i=0;
        
        vector<int> sum(n+10,0);
        
        for(i=0;i+k-1<ar.size();i++)
        {
            cnt+=sum[i];
            if((ar[i]+cnt)%2==0)
            {
                ans++;   
                cnt++;
                sum[i]++;
                sum[i+k]--;
                ar[i]=1;
            }
            else
                ar[i]=1;

        }
        
        for(;i<n;i++)
        {
            cnt+=sum[i];
            ar[i]=(ar[i]+cnt)%2;
        }
        
        for(int i=0;i<ar.size();i++)
        {
            if(ar[i]==0)
                return -1;
        }
        
        return ans;
    }
};