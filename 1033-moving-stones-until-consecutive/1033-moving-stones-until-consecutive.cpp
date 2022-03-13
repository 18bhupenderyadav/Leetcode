class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) 
    {
        int x,y,z;
        x = min({a,b,c});
        z = max({a,b,c});
        if(a==x || a==z )
        {
            if(b==x || b==z)
                y=c;
            else
                y=b;
        }
        else
        {
            y=a;
        }
        
        vector<int> ans(2,0);
        
        
        int diff1=y-x , diff2=z-y;
        if(diff1==1 && diff2==1)
            ans[0]=0;
        else if(diff1==1 || diff2==1)
            ans[0]=1;
        else if(diff1==2 || diff2==2)
            ans[0]=1;
        else
            ans[0]=2;
        
        
        
        ans[1] = diff1 + diff2 -2;
        
        return ans;
    }
};

// x _ _ _ _ _ y _ _ _ _ z