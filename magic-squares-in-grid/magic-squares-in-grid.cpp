class Solution {
public:
    bool ismagicsquare(vector<vector<int>>& ar)
    {
        // check if all numbers are distinct
        
        set<int> s;
        for(auto i:ar)
        {
            for(auto j:i)
            { 
                if(j>9 || j<1)
                    return 0;
                s.insert(j);
            }
        }
        
        if(s.size()!=9)
            return 0;
        
        // check all sum values 
        // first all col
        s.clear();
        for(int i=0;i<3;i++)
        {
            int sum=0;
            for(int j=0;j<3;j++)
            {
                sum+=ar[i][j];
            }
            s.insert(sum);
        }
        
        // now all rows
        for(int j=0;j<3;j++)
        {
            int sum=0;
            for(int i=0;i<3;i++)
            {
                sum+=ar[i][j];
            }
            s.insert(sum);
        }
        
        // now the diagonals
        int sum1=ar[0][0]+ar[1][1]+ar[2][2];
        int sum2=ar[2][0]+ar[1][1]+ar[0][2];
        s.insert(sum1);
        s.insert(sum2);
        
        return s.size()==1;
    }
    int numMagicSquaresInside(vector<vector<int>>& ar) 
    {
        int ans=0;
        
        for(int i=0;i<max(0,(int)ar.size()-2);i++)
        {
            for(int j=0;j<max(0,(int)ar[0].size()-2);j++)
            {
                vector<vector<int>> temp(3,vector<int>(3,0));
                
                for(int x=0;x<3;x++)
                {
                    for(int y=0;y<3;y++)
                    {
                        temp[x][y]=ar[i+x][j+y];
                    }
                }
                
                if(ismagicsquare(temp))
                    ans++;
            }
        }
        
        // cout<<ans<<endl;
        
        return ans;
    }
};