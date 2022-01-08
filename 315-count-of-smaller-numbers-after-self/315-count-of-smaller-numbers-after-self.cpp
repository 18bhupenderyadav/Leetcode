class Solution {
public:
    vector<int> tree;
    
    int find(int node,int node_low,int node_high,int low,int high)
    {
        if(node_high<low || node_low>high)
            return 0;
        
        if(node_low>=low && node_high<=high)
            return tree[node];
        
        int mid=(node_high+node_low)/2;
        return find(2*node,node_low,mid,low,high)+
            find(2*node+1,mid+1,node_high,low,high);
    }
    
    void update(int node,int node_low,int node_high,int low,int high,int value)
    {
        if(node_high<low || node_low>high)
        {
            return;
        }
        
        if(node_low>=low && node_high<=high)
        {
            tree[node]=value;
            return;
        }
        
        int mid=(node_high+node_low)/2;
        update(2*node,node_low,mid,low,high,value);
        update(2*node+1,mid+1,node_high,low,high,value);
        
        tree[node]=tree[2*node]+tree[2*node+1];
        return;
    }
    
    vector<int> countSmaller(vector<int>& nums) 
    {
        int n=nums.size();
        // sort array with index
        vector<pair<int,int>> ar(n);
        for(int i=0;i<n;i++)
        {
            ar[i].first=nums[i];
            ar[i].second=i;
        }
        sort(ar.begin(),ar.end());
        
        // make segement tree
        while((n&(n-1)))
        {
            n++;
        }
        
        tree.resize(2*n,0);
        
        
        vector<int> ans(ar.size());
        
        for(int i=0;i<ar.size();i++)
        {
            int sum=find(1,0,ar.size()-1,ar[i].second+1,ar.size()-1);
            ans[ar[i].second]=sum;
            
            update(1,0,ar.size()-1,ar[i].second,ar[i].second,1);
        }
        
        return ans;
    }
};