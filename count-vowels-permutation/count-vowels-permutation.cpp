class Solution {
public:

    const int mod=1e9+7;
    unordered_map<char,vector<char>> mp;
    int memo[2*10000+10][6];
    map<char,int> ch;

    int dp(int pos,char last,int n)
    {
        if(pos==n)
        {
            return 1;
        }


        if(memo[pos][ch[last]]!=-1)
            return memo[pos][ch[last]];
        int ans=0;
        for(char c:mp[last])
        {
            ans+=dp(pos+1,c,n);
            ans%=mod;
        }

        return memo[pos][ch[last]]=ans;
    }
    int countVowelPermutation(int n) 
    {
        // mp.clear();
        mp['a'].push_back('e');

        mp['e'].push_back('a');
        mp['e'].push_back('i');

        mp['i'].push_back('a');
        mp['i'].push_back('e');
        mp['i'].push_back('o');
        mp['i'].push_back('u');

        mp['o'].push_back('i');
        mp['o'].push_back('u');

        mp['u'].push_back('a');

        ch['a']=0;
        ch['e']=1;
        ch['i']=2;
        ch['o']=3;
        ch['u']=4;

        memset(memo,-1,sizeof(memo));
        int ans=0;
        ans+=dp(1,'a',n);
        ans%=mod;
        ans+=dp(1,'e',n);
        ans%=mod;
        ans+=dp(1,'i',n);
        ans%=mod;
        ans+=dp(1,'o',n);
        ans%=mod;
        ans+=dp(1,'u',n);
        ans%=mod;

        
        return ans;
    }
};