class Solution {
public:
    int minSetSize(vector<int>& ar) 
    {
        unordered_map<int,int> mp;
        int i,j,n=ar.size();
        for(i=0;i<n;i++)
        {
            mp[ar[i]]++;
        }
        vector<pair<int,int>> br;
        for(auto i:mp)
        {
            br.push_back({i.second,i.first});
        }
        sort(br.begin(),br.end());
        reverse(br.begin(),br.end());
        int ans=0,sum=0;
        i=0;
        while(1)
        {
            sum+=br[i].first;
            ans++;
            if(sum>=n/2)
                break;
            i++;
        }
        
        return ans;
    }
};