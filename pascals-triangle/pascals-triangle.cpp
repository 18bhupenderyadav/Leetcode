class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        if(numRows==0)
            return {};
        vector<int> push;
        vector<vector<int>> ans;
        push.push_back(1);
        ans.push_back(push);
        if(numRows==1)
            return ans;
        push.push_back(1);
        ans.push_back(push);
        if(numRows==2)
            return ans;
        push.clear();
        
        for(int i=2;i<numRows;i++)
        {
            push.push_back(1);
            for(int j=1;j<i;j++)
            {
                push.push_back(ans[i-1][j-1]+ans[i-1][j]);
            }
            push.push_back(1);
            ans.push_back(push);
            push.clear();
            
        }
        
        for(int i=0;i<numRows;i++)
        {
            for(int j=0;j<ans[i].size();j++)
                cout<<ans[i][j]<<" ";
            cout<<endl;
        }
        
        return ans;
            
    }
};