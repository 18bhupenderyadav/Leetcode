class Solution {
public:
    string frequencySort(string s) 
    {
        int i,n;
        string ans="";
        n=s.length();
        pair<int,char> ar[256];
        for(i=0;i<256;i++)
            ar[i].second=(char)(i);
        for(i=0;i<n;i++)
        {
            ar[(int)(s[i])].first++;
        }
        sort(ar,ar+256);
        for(i=0;i<256;i++)
        {
            if(ar[i].first!=0)
            {
                for(int j=0;j<ar[i].first;j++)
                {
                    ans+=ar[i].second;
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};