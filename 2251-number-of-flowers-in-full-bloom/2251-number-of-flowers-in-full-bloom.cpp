class Solution {
public:
    void print(vector<int>& ans)
    {
        for(int i:ans)
            cout<<i<<" ";
        cout<<endl;
    }
    vector<int> fullBloomFlowers(vector<vector<int>>& fr, vector<int>& tr) 
    {
        map<int,int> mp;
        
        for(int i=0;i<fr.size();i++)
        {
            mp[fr[i][0]]++;
            mp[fr[i][1]+1]--;
        }
        
        int cur=0,cnt=0;
        vector<int> ans(tr.size());
        vector<pair<int,int>> ar;
        
        vector<pair<int,int>> t;
        
        for(int i=0;i<tr.size();i++)
        {
            t.push_back({tr[i],i});
        }
        
        sort(t.begin(),t.end());
        
        for(auto i:mp)
        {
            ar.push_back({i.first,i.second});
            // cout<<i.first<<" "<<i.second<<endl;
        }
        
       while(cur<t.size() && t[cur].first<ar[0].first)
        {
            ans[t[cur].second]=cnt;
            cur++;
        }
        
        for(int i=0;i<ar.size()-1;i++)
        {
            cnt+=ar[i].second;
            while(cur<t.size() && t[cur].first<ar[i+1].first)
            {
                ans[t[cur].second]=cnt;
                cur++;
            }
            // print(ans);
        }
        
        return ans;
    }
};