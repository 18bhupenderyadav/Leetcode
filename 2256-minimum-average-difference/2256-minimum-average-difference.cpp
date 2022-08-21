class Solution {
public:
    int minimumAverageDifference(vector<int>& ar) {
        
        long long int mn = INT_MAX;
        long long int ans = ar.size()-1;
        
        long long int sum = 0;
        for(int i:ar)
            sum+=i;
        
        long long int cur = 0;
        
        for(int i=0;i<ar.size();i++)
        {
            cur+=ar[i];
            long long int av1 = cur/(i+1);
            long long int av2 = 0;
            if((ar.size()-i-1)!=0)
                av2 = (sum-cur)/(ar.size()-i-1);
            
            // cout<<av1<<" "<<av2<<endl;
            
            long long int diff = abs(av1 - av2);
            
            if(diff<mn)
            {
                ans = i;
                mn = diff;
            }
        }
        
        return ans;
        
    }
};