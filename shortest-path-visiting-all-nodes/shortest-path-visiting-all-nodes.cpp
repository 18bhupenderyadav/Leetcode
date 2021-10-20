class Solution {
public:
    struct node
    {
        int mask;
        int cur;
    };
    int shortestPathLength(vector<vector<int>>& adj) 
    {
        long long int ans=0;
        
        queue<pair<int,int>> q;
        
        for(int i=0;i<adj.size();i++)
        {
            int mask=(1<<i);
            int cur=i;
            q.push({mask,cur});
        }
        
        set<string> s;
        
        while(q.size())
        {
            queue<pair<int,int>> nq;
            
            while(q.size())
            {
                auto t=q.front();
                q.pop();
                
                // cout<<t.second<<" "<<t.first<<endl;
                
                if(t.first+1==(1<<(adj.size())))
                    return ans;
                
                for(int v:adj[t.second])
                {
                    int mask=(t.first | (1<<v));
                    int cur=v;
                    
                    string st=to_string(mask)+'-'+to_string(cur);
                    
                    if(s.find(st)==s.end())
                    {
                        nq.push({mask,cur});
                        s.insert(st);
                    }
                }
            }
            ans++;
            q=nq;
            // cout<<endl;
        }
        
        // cout<<ans<<endl;
        
        return ans;
    }
};