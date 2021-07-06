class Solution {
public:
    int longestAwesome(string s)
    {
        int n=s.length();
        int memo[1025];
        for(int i=0;i<1025;i++)
            memo[i]=n;
        
        memo[0]=-1;
        
        int ans=0,cur=0;
        
        for(int i=0;i<n;i++)
        {
            cur^= 1<<(s[i]-'0');
            ans=max(ans,i-memo[cur]);
            
            for(int j=0;j<10;j++)
            {
                ans=max(ans,i-memo[cur ^ (1<<j)]);
            }
            memo[cur]=min(memo[cur],i);
        }
             
        return ans;
    }
};