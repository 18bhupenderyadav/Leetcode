class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        def dfs(board,i,j,word):
            
            if(len(word)==0):
                return 1
            if(i<0 or j<0 or i>=len(board) or j>=len(board[0])):
                return 0
            if(board[i][j]!=word[0]):
                return 0
            
            c=board[i][j]
            board[i][j]='.'
            
            s=word[1:len(word)]
            
            ans=0
            ans=ans | dfs(board,i+1,j,s)
            ans=ans | dfs(board,i-1,j,s)
            ans=ans | dfs(board,i,j+1,s)
            ans=ans | dfs(board,i,j-1,s)
            
            board[i][j]=c
            
            return ans
        
        for i in range(0,len(board)):
            for j in range(0,len(board[0])):
                if(board[i][j]==word[0]):
                    ans=dfs(board,i,j,word)
                    if(ans==1):
                        return 1
        return 0