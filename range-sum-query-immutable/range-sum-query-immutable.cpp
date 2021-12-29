class NumArray {
public:
    
    vector<int> tree;
    int n;
    
    NumArray(vector<int>& ar) 
    {
        n=ar.size();
        
        while(__builtin_popcount(n)!=1)
        {
            ar.push_back(0);
            n++;
        }
        
        tree.resize(2*n);
        
        for(int i=0;i<n;i++)
            tree[n+i]=ar[i];
        
        for(int i=n-1;i>=1;i--)
            tree[i]=tree[2*i]+tree[2*i+1];
    }
    
    
    int find(int node_left,int node_right,int left,int right,int node)
    {
        if(left<=node_left && node_right<=right)
            return tree[node];
        if(node_right<left || right<node_left)
            return 0;
        
        int mid = (node_left+node_right)/2;
        
        return find(node_left,mid,left,right,2*node)+
            find(mid+1,node_right,left,right,2*node+1);
    }
    
    int sumRange(int left, int right) 
    {
        return find(0,n-1,left,right,1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */