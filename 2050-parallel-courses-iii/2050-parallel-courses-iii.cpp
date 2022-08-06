class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& rel, vector<int>& time) 
    {
        
        vector<int> in_deg(n+1,0);
        
        vector<vector<int>> adj(n+1);
        
        for(auto i:rel)
        {
            adj[i[0]].push_back(i[1]);
            in_deg[i[1]]++;
        }
        
        queue<int> q;
        vector<int> dp(n+1,0);
        for(int i=1;i<=n;i++)
        {
            if(in_deg[i]==0)
            {
                dp[i] = time[i-1];
                q.push(i);
            }
        }
        
        
        int ans = 0;
        
        
        while(q.size()>0)
        {
            queue<int> nq;
            int sol = 0,temp=-1;
            while(q.size()>0)
            {
                int top = q.front();
                q.pop();
                
                for(int i:adj[top])
                {   
                    in_deg[i]--;
                    dp[i] = max(dp[i],dp[top]+time[i-1]);
                    if(in_deg[i]==0)
                        nq.push(i);
                }
            }
            
            q=nq;

        }
        
        for(int i:dp)
            ans=max(i,ans);
        return ans;
        
        
        
    }
};