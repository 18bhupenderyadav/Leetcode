class Solution {
public:
    int MOD = 1e9+7;
    int dp[1005][1005][5]; 
    int cnt(string&s, int i, int j, int ch){
        if(i>j){
            return 0;
        }
        else if(i==j){
            if(s[i]==ch+'a'){
                return 1;
            }
            return 0;
        }
        if(dp[i][j][ch]!=-1){
            return dp[i][j][ch];
        }
        
        int ans = 0;
        if(s[i]==s[j] && s[i]==ch+'a'){
            ans = 2;
            
            for(int k=0;k<4;k++){
                ans += cnt(s,i+1,j-1,k); 
                ans%=MOD;
            }
           
        }
        else{
            ans = cnt(s,i+1,j,ch) + cnt(s,i,j-1,ch) - cnt(s,i+1,j-1,ch); 
            ans%=MOD;
        }
        return dp[i][j][ch]=ans;
    }
    int countPalindromicSubsequences(string s) {
         
        int ans = 0;
        int n = s.size();
        
        memset(dp,-1,sizeof(dp));
        
        for(int i=0;i<4;i++){
            ans += cnt(s,0,n-1,i);
            ans%=MOD;
        }
        
        return ans;
    }
};
