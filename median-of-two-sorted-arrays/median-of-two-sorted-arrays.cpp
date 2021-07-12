class Solution {
public:
    
    int nth(int a[],int m,int b[],int n,int k)
    {
        if(m>n)
            return nth(b,n,a,m,k);
        
        if(m==0)
            return b[k-1];
        if(k==1)
            return min(a[0],b[0]);
        
        int la=min(m,k/2),lb=min(n,k/2);
        
        if(a[la-1]<b[lb-1])
            return nth(a+la,m-la,b,n,k-la);
        
        else
            return nth(a,m,b+lb,n-lb,k-lb);
        
        return 0;
    }
    

    double findMedianSortedArrays(vector<int>& ar, vector<int>& br) 
    {
        
        int n=ar.size();
        int m=br.size();
        
        if(n==0 || m==0)
        {
            if(n==0)
            {
                return ((double)(br[m/2] + br[(m+1)/2 -1]))/2;
            }
            
            return ((double)(ar[n/2] + ar[(n+1)/2 -1]))/2;
        }
        
        int a[n],b[m];
        for(int i=0;i<n;i++)
        {
            a[i]=ar[i];
        }
        
        for(int j=0;j<m;j++)
        {
            b[j]=br[j];
        }
        
        if((n+m)%2)
        {
            return (double)nth(a,n,b,m,(n+m+2)/2);
        }
        
        return ((double)nth(a,n,b,m,(n+m)/2)+(double)nth(a,n,b,m,(n+m+2)/2))/2;
    }
};

// search for (n+m)/2 th and (n+m)/2 +1th element
