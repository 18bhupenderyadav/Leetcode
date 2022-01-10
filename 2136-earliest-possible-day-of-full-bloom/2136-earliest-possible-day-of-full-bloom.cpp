class Solution {
public:
    static bool cmp(pair<int,int>& a,pair<int,int>& b)
    {
        if(a.first==b.first)
            return a.second>b.second;
        return a.first>b.first;
    }
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) 
    {
        int n=plantTime.size();
        vector<pair<int,int>> ar(n);
        
        for(int i=0;i<n;i++)
        {
            ar[i].first=growTime[i];
            ar[i].second=plantTime[i];
        }
        
        sort(ar.begin(),ar.end(),cmp);
        
        int end=0,cur=0;
        
        for(int i=0;i<n;i++)
        {
            end=max(end,cur+ar[i].first+ar[i].second);
            cur+=ar[i].second;
        }
        
        return end;
    }
};