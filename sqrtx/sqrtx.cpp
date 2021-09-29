class Solution {
public:
    int mySqrt(int x) 
    {
        int l=1;
        int r=x;
        for(int i=0;i<40;i++)
        {
            long long int mid=l+(r-l)/2;
            if(mid*mid==x)
                return mid;
            else if(mid*mid>x)
                r=mid-1;
            else
                l=mid+1;
        }
        
        return r;
    }
};