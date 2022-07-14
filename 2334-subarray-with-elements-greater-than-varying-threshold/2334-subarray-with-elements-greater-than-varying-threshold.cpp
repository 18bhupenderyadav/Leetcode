class Solution {
public:
    int validSubarraySize(vector<int>& ar, int threshold) 
    {
        stack<int> right,left;
        int n = ar.size();
        vector<int> rh(n) ,lf(n);
        
        for(int i=0;i<n;i++)
        {
            while(right.size() && ar[i]<ar[right.top()])
            {
                rh[right.top()] = i;
                right.pop();
            }
            
            right.push(i);
        }
        while(right.size())
        {
            rh[right.top()] = n;
            right.pop();
        }
        
        for(int i=n-1;i>=0;i--)
        {
            while(left.size() && ar[i]<ar[left.top()])
            {
                lf[left.top()] = i;
                left.pop();
            }
            
            left.push(i);
        }
        while(left.size())
        {
            lf[left.top()] = -1;
            left.pop();
        }
        
        for(int i=0;i<n;i++)
        {
            int len = rh[i] - lf[i] - 1;
            
            if((long long)len*ar[i] > (long long)threshold)
                return len;
        }
        
        return -1;
    }
};