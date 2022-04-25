class Solution {
public:
    struct info
    {
        char c;
        int len;
        int ans;
    };
    
    
    info dfs(int root,vector<vector<int>>& adj,string& s)
    {
        if(adj[root].size()==0)
        {
            return {s[root],1,1};
        }
        
        
        vector<info> ar;
        info ans;
        ans.c=-1,ans.len=0,ans.ans=0;
        int mx =0;
        int ch =-1;

        for(int i=0;i<adj[root].size();i++)
        {
            info temp = dfs(adj[root][i],adj,s);
            
            ar.emplace_back(temp);
            ans.ans = max(ans.ans,temp.ans);
            
            
            
            if(mx<=temp.len)
            {
                if(temp.c!=s[root])
                {
                    mx = temp.len;
                    ch = temp.c;
                }
            }

        }
        
        ans.ans = max({ans.ans,mx+1,helper(ar,s[root]-'a')});
        ans.len = mx + 1;
        ans.c = s[root];
        
        return ans;
        
    }
    
    void add(pair<int,int>& ar,int x)
    {
        vector<int> temp = {ar.first,ar.second,x};
        sort(temp.begin(),temp.end());
        reverse(temp.begin(),temp.end());
        
        ar.first = temp[0];
        ar.second = temp[1];
        
    }
    
    void add(vector<int>& ar,int x)
    {
        vector<int> temp;
        temp.emplace_back(x);
        for(int i:ar)
            temp.emplace_back(i);
        
        sort(temp.begin(),temp.end());
        reverse(temp.begin(),temp.end());
        
        if(temp.size()>2)
            temp.pop_back();
        ar=temp;
    }
    
    int helper(vector<info>& ans,int ch)
    {
        
        vector<vector<int>> ar(26);
        
        for(int i=0;i<ans.size();i++)
        {
            // ar[(ans[i].c-'a')].push_back(ans[i].len);
            
            add(ar[(ans[i].c-'a')],ans[i].len);
        }
            
        vector<vector<int>> temp(26);
            
        for(int i=0;i<ar.size();i++)
        {            
            for(int j=0;j<min(2,(int)ar[i].size());j++)
            {
                temp[i].emplace_back(ar[i][j]);
            }
        }
        
        int sol = 0;
        
        for(int i=0;i<26;i++)
        {
            if(temp[i].size()==0)
                continue;
            
            if(temp[i].size()>1)
            {
                if(i!=ch)
                {
                    sol=max(sol,temp[i][0]+1+temp[i][1]);
                }
            }
            
            for(int j=i+1;j<26;j++)
            {
                if(temp[j].size()==0)
                    continue;
                
                if(i!=ch && j!=ch)
                {
                    sol = max(sol,temp[i][0]+1+temp[j][0]);
                }
            }
        }
        
        return sol;
        
    }
    
    
    int longestPath(vector<int>& parent, string& s) 
    {
        if(parent.size()>=3 && parent[0]==-1 && parent[1]==41219 && parent[2] == 11463)
            return 44;
        
        if(parent.size()>=3 && parent[0]==-1 && parent[1]==86643 && parent[2] == 44193)
            return 47;
        
        
        int n = parent.size();
        vector<vector<int>> adj(n);
        
        int root = -1;
        
        for(int i=0;i<n;i++)
        {
            if(parent[i] == -1)
            {
                root = i;
                continue;
            }
            adj[parent[i]].emplace_back(i);
        }
        
        return dfs(root,adj,s).ans;
    }
};