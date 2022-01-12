
class Solution {
public:
    const int inf=1e6;
    unordered_map<int,vector<int>> mp;
    vector<int> tree;
    int nm;
    int find(int node,int node_low,int node_high,int low,int high)
    {
        if(high<node_low || low>node_high)
            return inf;
        
        if(node_low>=low && node_high<=high)
            return tree[node];
        
        int mid=(node_low+node_high)/2;
        return min(find(2*node,node_low,mid,low,high),find(2*node+1,mid+1,node_high,low,high));
    }
    
    void sege(vector<int>& ar)
    {
        int n=ar.size();
        
        while((n&(n-1))!=0)
        {
            n++;
        }
        
        tree.resize(2*n,inf);
        
        for(int i=0;i<ar.size();i++)
        {
            tree[i+n]=ar[i];
        }
        
        for(int i=n-1;i>0;i--)
        {
            tree[i]=min(tree[2*i],tree[2*i+1]);
        }
    }
    
    int dp(vector<int>& ar,int st,int end,int lmin)
    {
        if(st==end)
            return ar[st]-lmin;
        if(st>end)
            return 0;
    
        int ans=0,mn=INT_MAX,ls=st;

        mn=find(1,0,nm-1,st,end);
        
        ans+=mn-lmin;
        
        for(int i:mp[mn])
        {
            if(i>=st && i<=end)
            {
                ans+=dp(ar,ls,i-1,mn);
                ls=i+1;
            }
        }
        
        
        ans+=dp(ar,ls,end,mn);
        
        return ans;
    }
    int minNumberOperations(vector<int>& ar) 
    {
        int n=ar.size();
        
        for(int i=0;i<n;i++)
            mp[ar[i]].push_back(i);
        
        sege(ar);
        
        while((n&(n-1))!=0)
            n++;
        
        nm=n;
        
        int mn=INT_MAX,ls=0;

        mn=find(1,0,nm-1,0,n-1);
        
        int ans=mn;
        
        for(int i:mp[mn])
        {
            ans+=dp(ar,ls,i-1,mn);
            ls=i+1;
        }

        ans+=dp(ar,ls,ar.size()-1,mn);

        return ans;
    }
};

// 1 2 3 2 1