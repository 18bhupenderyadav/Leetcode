class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) 
    {
        
        int ones = 0;
        
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]==1)
            {
                ones++;
            }
        }
        
        if(ones==0)
        {
            return {0,(int)arr.size()-1};
        }
        
        if(ones%3)
        {
            return {-1,-1};
        }
        
        int k = ones/3;
        
        int cnt = 0, start = 0 , mid = 0 , end = 0;
        
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i])
            {
                start = i;
                break;
            }
        }
        
        for(int i=0;i<arr.size();i++)
        {
            cnt+=arr[i];
            if(cnt==k+1)
            {
                mid = i;
                break;
            }
        }
        
        for(int i = mid+1;i<arr.size();i++)
        {
            cnt+=arr[i];
            if(cnt==2*k+1)
            {
                end = i;
                break;
            }
        }
        
        while(end<arr.size() && arr[start]==arr[mid] && arr[mid]==arr[end])
        {
            start++;
            mid++;
            end++;
        }
        
        if(end!=arr.size())
        {
            return {-1,-1};
        }
        
        return {start-1,mid}; 
    }
};