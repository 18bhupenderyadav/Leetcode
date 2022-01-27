class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ar, vector<int>& t) 
    {
        int time = abs(t[0]) + abs(t[1]);
        
        for(vector<int> g:ar)
        {
            int nt= abs(t[0]-g[0]) + abs(t[1]-g[1]);
            
            if(nt<=time)
                return 0;
        }
        
        return 1;
    }
};