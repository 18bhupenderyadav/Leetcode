class Solution {
public:
    vector<pair<int,int>> twosum(vector<int>& ar,int st,int req)
    {
        vector<pair<int,int>> ans;
        
        int i=st,j=ar.size()-1;
        
        while(i<j)
        {
            if(ar[i]+ar[j]==req)
            {
                ans.push_back({ar[i],ar[j]});
                int a=ar[i];
                int b=ar[j];
                while(i<ar.size() && ar[i]==a)
                {
                    i++;
                }
                while(j>=0 && ar[j]==b)
                {
                    j--;
                }
            }
            else if(ar[i]+ar[j]>req)
                j--;
            else
                i++;
        }
        
        return ans;
    }
    vector<vector<int>> threeSum(vector<int>& ar) 
    {
        vector<vector<int>> ans;;
        
        sort(ar.begin(),ar.end());;
        
        for(int i=0;i<ar.size();i++)
        {
            vector<pair<int,int>> temp=twosum(ar,i+1,-1*ar[i]);
            for(auto it:temp)
            {
                ans.push_back({ar[i],it.first,it.second});
            }
            
            while(i+1<ar.size() && ar[i]==ar[i+1])
                i++;
        }
        
        
        return ans;
    }
};