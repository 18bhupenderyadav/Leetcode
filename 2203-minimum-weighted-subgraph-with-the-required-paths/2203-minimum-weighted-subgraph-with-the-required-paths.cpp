class Solution {
public:
    const long long int inf = 1e11;
    void dijkstra(int sr,vector<vector<vector<long long int>>>& adj,vector<long long int>& dis)
    {
        priority_queue<pair<long long int,long long int>,
            vector<pair<long long int,long long int>>,
                greater<pair<long long int,long long int>>> pq;
        
        dis[sr] = 0;
        pq.push({0,sr});
        
        while(pq.size()>0)
        {
            long long int u = pq.top().second;
            long long int di = pq.top().first;
            pq.pop();
            
            if(di>dis[u])
                continue;
            
            for(auto i:adj[u])
            {
                long long int v = i[0];
                long long int w = i[1];
                
                if(dis[v] > dis[u] + w)
                {
                    dis[v] = dis[u] + w;
                    pq.push({dis[v],v});
                }
            }
        }
        
        return;
    }
        
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) 
    {
        // make adj and rev_adj
        vector<vector<vector<long long int>>> adj(n);
        
        vector<vector<vector<long long int>>> rev_adj(n);
        
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            adj[u].push_back({v,w});
            rev_adj[v].push_back({u,w});
        }
        
        // make dis vectors
        vector<long long int> dis1(n, inf), dis2(n, inf), dis3(n, inf);
        
        // do dijkstra on src1
        dijkstra(src1,adj,dis1);
        
        // do dijkstra on src2
        dijkstra(src2,adj,dis2);
        
        // do dijkstra on dest
        dijkstra(dest,rev_adj,dis3);
        
        // get final answer
        long long int ans = inf;
        
        for(int i=0;i<n;i++)
        {
            long long int sol = dis1[i] + dis2[i] + dis3[i];
            ans = min(ans,sol);
        }
        
        if(ans == inf)
            ans = -1;
        
        return ans;
        
    }
};