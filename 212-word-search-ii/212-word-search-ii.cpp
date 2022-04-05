class Solution {
public:

    vector<int> ans;
    void dfs(int i,int j,vector<vector<int>>& vis,vector<vector<char>>& br,vector<int>& isEnd ,int node,vector<vector<int>>& nxt)
    {
        if(isEnd[node]!=-1)
        {   
            ans[isEnd[node]] = 1;
        }
        
        if(i<0 || j<0 || i>=br.size() || j>=br[i].size())
            return;
        if(vis[i][j])
            return;
        
        int cur = br[i][j]-'a';
        if(nxt[node][cur] == 0)
            return;
        
        vis[i][j]=1;

        
        
        int new_node = nxt[node][cur];
        
        dfs(i+1,j,vis,br,isEnd,new_node,nxt);
        dfs(i-1,j,vis,br,isEnd,new_node,nxt);
        dfs(i,j+1,vis,br,isEnd,new_node,nxt);
        dfs(i,j-1,vis,br,isEnd,new_node,nxt);
        

        vis[i][j]=0;
        return;
        
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
    {
        // Build a trie
        
        vector<vector<int>> nxt(1,vector<int>(26,0));
        vector<int> isEnd(1,-1);
        
        int n = 0;
        
        for(int i=0;i<words.size();i++)
        {
            int node = 0;
            for(int j=0;j<words[i].size();j++)
            {
                int cur = words[i][j]-'a';
                if(nxt[node][cur] == 0)
                {
                    n++;
                    nxt[node][cur] = n;
                    nxt.push_back(vector<int>(26,0));
                    isEnd.push_back(-1);
                }
                node = nxt[node][cur];
            }
            isEnd[node] = i;
        }
        
        // DFS using the trie
        int sz = words.size();

        ans.resize(sz+1);
        
        vector<vector<int>> vis(board.size(),vector<int>(board[0].size(),0));
        
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                dfs(i,j,vis,board,isEnd,0,nxt);
            }
        }
        vector<string> sol;
        
        for(int i=0;i<words.size();i++)
        {
            if(ans[i])
                sol.push_back(words[i]);
        }
        
        return sol;
    }
};