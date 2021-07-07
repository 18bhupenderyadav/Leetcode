class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        int n = matrix.size();
        
        priority_queue<int>track;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                track.push(matrix[i][j]);
                if(track.size()>k) track.pop();
            }            
        }
                
        return track.top();
    }
};