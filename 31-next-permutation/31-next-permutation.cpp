class Solution {
public:
    void nextPermutation(vector<int>& ar) 
    {
        int pos = -1,n=ar.size();
        
        for(int i=n-2;i>=0;i--)
        {
            if(ar[i]<ar[i+1])
            {
                pos=i;
                break;
            }
        }
        
        // cout<<pos<<endl;
        if(pos==-1)
        {
            sort(ar.begin(),ar.end());
            return;
        }
        
        int pos2 = pos+1;
        
        for(int i=pos+1;i<n;i++)
        {
            if(ar[i]<ar[pos2] && ar[i]>ar[pos])
                pos2=i;
        }
        
        swap(ar[pos],ar[pos2]);
        sort(ar.begin()+pos+1,ar.end());
    }
};