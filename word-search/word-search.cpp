class Solution {
public:
    vector<int>dir = {-1,0,1,0,-1};
    bool check(int i,int j,int n,int m)
    {
        if(i>=n || j>=m || i<0 || j<0)
        {
            return 0;
        }
        return 1;
    }
    bool bfs(vector<vector<char>>& board, int i ,int j, string& word, int k)
    {
        if(k==word.size())
        {
            return 1;
        }
        
        bool ans = 0;
        for(int x=0;x<4;x++)
        {
            if(check(i+dir[x],j+dir[x+1],board.size(),board[0].size()) && word[k]==board[i+dir[x]][j+dir[x+1]])
            {
                char curr = board[i][j];
                board[i][j]='.';
                ans = ans | bfs(board,i+dir[x],j+dir[x+1],word,k+1);
                if(ans)
                {
                    return true;
                }
                board[i][j] = curr;
            }
        }
        
        return ans;
        
    }
    bool exist(vector<vector<char>>& board, string word) 
    {
        
        int n = board.size() , m = board[0].size();
        char first = word[0];
        bool ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==first)
                {
                    ans = ans | bfs(board,i,j,word,1);
                    if(ans)
                    {
                        return ans;
                    }
                }
            }
        }
        return ans; 
    }
};