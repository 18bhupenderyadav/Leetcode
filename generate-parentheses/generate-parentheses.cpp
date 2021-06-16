class Solution {
public:
    bool check(string& s)
    {
        int val=0;
        int i,n;
        n=s.length();
        for(i=0;i<n;i++)
        {
            if(s[i]=='(')
                val++;
            else
                val--;
            if(val<0)
                return false;
        }
        if(val==0)
            return true;
        return false;
    }
    set<string> sol;
    void dp(int n,string s,int sum)
    {
        //cout<<sum<<endl;
        if(s.length()==2*n)
        {
            if(sum==0||check(s)==true)
            {
                sol.insert(s);
                return;
            }
            else
                return;
        }
        
        if(sum<0||sum>n)
            return;
        dp(n,s+'(',sum+1);
        dp(n,s+')',sum-1);
        return;
    }
    vector<string> generateParenthesis(int n) 
    {
        string ss="";
        dp(n,ss,0);
        vector<string> ans;
        for(auto s: sol)
        {
            ans.push_back(s);
        }
        return ans;
    }
};