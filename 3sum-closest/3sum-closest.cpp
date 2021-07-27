class Solution {
public:
    int closest(vector<int>& ar,int i,int t)
    {
        int l=i+1,r=ar.size()-1;
        
        int ans=1000000;
        while(l<r)
        {
            int sum=ar[l]+ar[r]+ar[i];
            
            if(abs(t-sum)<abs(t-ans))
                ans=sum;
            
            if(sum>t)
                r--;
            else
                l++;
        }
        
        return ans;
    }
    int threeSumClosest(vector<int>& ar, int t) 
    {
        int ans=100000;
        int n=ar.size();
        
        sort(ar.begin(),ar.end());
        
        for(int i=0;i<n;i++)
        {
            int a=ar[i];
            if(a>=t && t>0)
                continue;
            int new_ans=closest(ar,i,t);
            
            if(abs(t-new_ans)<abs(t-ans))
                ans=new_ans;
        }
        
        return ans;
        
    }
};