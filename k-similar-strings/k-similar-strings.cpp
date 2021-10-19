class Solution {
public:
    int kSimilarity(string s, string t) 
    {
        int n=s.size();
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==t[i])
                continue;
            
            vector<int> ar;
            
            int ans=n-1;
            
            for(int j=i+1;j<n;j++)
            {
                if(s[j]==t[i] && s[j]!=t[j])
                {
                    ar.push_back(j);
                    
                    if(s[i]==t[j])
                    {
                        // swap(s[i],s[j]);
                        // ans=min(ans,1+kSimilarity(s.substr(i+1),t.substr(i+1)));
                        // swap(s[i],s[j]);
                        swap(s[i],s[j]);
                        return 1+kSimilarity(s.substr(i+1),t.substr(i+1));
                    }
                }
            }
            
            for(int j=0;j<ar.size();j++)
            {
                swap(s[i],s[ar[j]]);
                ans=min(ans,1+kSimilarity(s.substr(i+1),t.substr(i+1)));
                swap(s[i],s[ar[j]]);
            }
            
            return ans;
        }
        
        return 0;
    }
};