class Solution {
public:
    vector<int> num(int n)
    {
        vector<int> ans;
        
        while(n)
        {
            ans.push_back(n%2);
            n/=2;
        }
        
        while(ans.size()<=30)
            ans.push_back(0);
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    int find(vector<vector<int>>& nxt, int x)
    {
        int ans = 0;
        int node = 0;
        long long int cur = 1;
        
        
        for(int i=30;i>=0;i--)
        {
            int cur = ((x)&(1<<i));
            if(cur)
                cur=1;
            
            if(cur == 1)
            {
                if(nxt[node][0])
                {
                    node = nxt[node][0];
                }
                else
                {
                    ans |= (1<<i);
                    node = nxt[node][1];
                }
            }
            else
            {
                if(nxt[node][1])
                {
                    ans |= (1<<i);
                    node = nxt[node][1];
                }
                else
                {
                    node = nxt[node][0];
                }
            }

        }
        
        return ans;
    }
    
    int findMaximumXOR(vector<int>& ar) 
    {
        // build trie
        
        vector<vector<int>> nxt(1,vector<int>(2,0));
        
        int n = 0;
        
        for(int i=0;i<ar.size();i++)
        {
            int node = 0;
            vector<int> temp = num(ar[i]);
            
            for(int j=0;j<temp.size();j++)
            {
                int cur = temp[j];
                if(nxt[node][cur] == 0)
                {
                    n++;
                    nxt.push_back(vector<int>(2,0));
                    nxt[node][cur] = n;
                    
                }
                
                node = nxt[node][cur];
            }
        }
        
        
        int ans = 0;
        
        for(int i=0;i<ar.size();i++)
        {
            int y = find(nxt,ar[i]);
            ans = max(ans , (ar[i]^y));
            
        }
        
        return ans;
    }
};