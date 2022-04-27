vector<int> src;
bool cmp(int& a,int& b)
{
    if(src[a]<src[b])
        return 0;
    
    return 1;
}
class Solution {
public:
    
    int score(unordered_set<int>& s,vector<int>& sr)
    {
        int ans = 0;
        for(int i:s)
        {
            ans+=sr[i];
        }
        
        return ans;
    }
    
    int helper(int u,int v,vector<vector<int>>& top,vector<int>& sr)
    {
        
        int sum = sr[u] + sr[v];
        int ans = -1;
        int n = top[u].size() , m = top[v].size();
        for(int i=0;i<min(3,n);i++)
        {
            for(int j=0;j<min(3,m);j++)
            {
                int x = top[u][i];
                int y = top[v][j];
                if(x!=u && x!=v)
                {

                    if(y!=u && y!=v)
                    {
                        if(x!=y)
                        {
                            ans = max(ans, sum+sr[x]+sr[y]);
                        }
                    }
                }
            }
        }
        
        return ans;
    }
    
    void add(vector<int>& ar,int x,vector<int>& sr)
    {
        if(ar.size()<3)
        {
            ar.push_back(x);
            sort(ar.begin(),ar.end(),cmp);
            return;
        }
        
        
        if(sr[ar[0]]<sr[x])
        {
            ar[2]=ar[1];
            ar[1]=ar[0];
            ar[0]=x;
        }
        else if(sr[ar[1]]<sr[x])
        {
            ar[2]=ar[1];
            ar[1]=x;
        }
        else if(sr[ar[2]]<sr[x])
        {
            ar[2]=x;
        }
        
        return;
    }
    
    int maximumScore(vector<int>& sr, vector<vector<int>>& edges) 
    {
        int n = sr.size();
        
        
        vector<vector<int>> top(n);
        src = sr;
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            
            add(top[u],v,sr);
            add(top[v],u,sr);
        }
        
        int ans = -1;
        
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            
            int x = helper(u,v,top,sr);
            ans = max(ans,x);
        }
        
        return ans;
    }
};