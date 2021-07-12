class Solution {
public:
    
    // Try to B.F and make all numbers 1-6 in tops and then 1-6 in bottoms TC:O(N*6*2) SC:O(1)
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) 
    {
        int n=tops.size();
        int ans=INT_MAX;
        bool can=1;
        for(int face=1;face<=6;face++)
        {
            int cnt=0;
            can=1;
            for(int i=0;i<n;i++)
            {
                if(tops[i]==face)
                    continue;
                else if(bottoms[i]==face)
                    cnt++;
                else
                {
                    can=0;
                    break;
                }
            }
            
            if(can)
                ans=min(ans,cnt);
        }
        
        
        for(int face=1;face<=6;face++)
        {
            int cnt=0;
            can=1;
            for(int i=0;i<n;i++)
            {
                if(bottoms[i]==face)
                    continue;
                else if(tops[i]==face)
                    cnt++;
                else
                {
                    can=0;
                    break;
                }
            }
            
            if(can)
                ans=min(ans,cnt);
        }
        
        if(ans==INT_MAX)
            ans=-1;
        
        return ans;
    }
};