class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) 
    {
        int mask = 0;
        vector<int>pre(s.size());
        
        for(int i=0;i<s.size();i++)
        {
            mask ^= (1<<(s[i]-'a'));
            pre[i] = mask;
        }
        
        vector<bool>ans;
        
        for(vector<int> q : queries)
        {
            int l = q[0];
            int r = q[1];
            int k = q[2];
            
            int curr = pre[r];
            if(l>0)
            {
                curr = curr^pre[l-1]; 
            }
            
            int cnt = 0; 
            for(int i=0;i<26;i++)
            {
                if((curr&(1<<i))!=0)
                {
                    cnt++;
                }
            }
            
            if((r-l+1)%2)
            {
                //odd
                if((cnt-1)/2<=k)
                {
                    ans.push_back(true);
                }
                else
                {
                    ans.push_back(false);
                }
            }
            else
            {
                //even
                if(cnt/2<=k)
                {
                    ans.push_back(true);
                }
                else
                {
                    ans.push_back(false);
                }
            }
        }
        return ans;
    }
};