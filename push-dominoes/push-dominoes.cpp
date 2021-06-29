class Solution {
public:
    string pushDominoes(string s) 
    {
        int n=s.length();
        int memo[n];
        memset(memo,0,sizeof(memo));
        
        int force=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='R')
                force=n;
            else if(s[i]=='L')
                force=0;
            else force=max(force-1,0);
            memo[i]+=force;
        }
        
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='L')
                force=-1*n;
            else if(s[i]=='R')
                force=0;
            else
                force=min(0,force+1);
            memo[i]+=force;
        }
        
        for(int i=0;i<n;i++)
        {
            if(memo[i]<0)
                s[i]='L';
            else if(memo[i]>0)
                s[i]='R';
            else
                s[i]='.';
        }
        return s;
    }
};
