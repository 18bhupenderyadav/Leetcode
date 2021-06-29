class Solution {
public:
    int longestOnes(vector<int>& ar, int k) 
    {
        int cnt=0;
        int n=ar.size();
        int ans=0;

        int i=0;

        for(int j=0;j<n;j++)
        {
            if(ar[j]==0)
            {
                cnt++;
            }
            while(cnt>k)
            {

                if(ar[i]==0)
                {
                    cnt--;
                }
                i++;
            }

            ans=max(ans,j-i+1);
        }

        return ans;
    }
};