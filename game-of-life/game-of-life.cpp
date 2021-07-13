class Solution {
public:
    void gameOfLife(vector<vector<int>>& ans) 
    {
        for(int i=0;i<ans.size();i++)
        {
            for(int j=0;j<ans[0].size();j++)
            {
                int count=0;
                for(int k=-1;k<=1;k++)
                {
                    for(int m=-1;m<=1;m++)
                    {
                        if((k==0 && m==0) || i+k<0 || j+m<0 || i+k>=ans.size() || j+m>=ans[0].size())
                        {
                            continue;
                        }
                        else
                        {
                            if(ans[i+k][j+m]==1 || ans[i+k][j+m]==-1)
                            {
                                count++;
                            }
                        }
                    }
                }
                if(ans[i][j]==0 && count==3)
                {
                    ans[i][j]=2;
                }
                else if(ans[i][j]==1)
                {
                    if(count<2)
                    {
                        ans[i][j]=-1;
                    }
                    else if(count<=3)
                    {
                        ans[i][j]=1;
                    }
                    else
                    {
                        ans[i][j]=-1;
                    }
                }
                else
                {
                    ans[i][j]=0;
                }
            }
        }
        for(int i=0;i<ans.size();i++)
        {
            for(int j=0;j<ans[0].size();j++)
            {
                if(ans[i][j]==2)
                {
                    ans[i][j]=1;
                }
                else if(ans[i][j]==-1)
                {
                    ans[i][j]=0;
                }
            }
        }
    }
};