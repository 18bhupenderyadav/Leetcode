class MapSum {
public:
    /** Initialize your data structure here. */
    map<string,int> mp;
    MapSum() 
    {
        mp.clear();
    }
    
    void insert(string key, int val) 
    {
        mp[key]=val;
    }
    
    int sum(string prefix) 
    {
        int ans=0;
        
        for(auto i:mp)
        {
            if(i.first.substr(0,prefix.length())==prefix)
                ans+=i.second;
        }
        
        return ans;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */