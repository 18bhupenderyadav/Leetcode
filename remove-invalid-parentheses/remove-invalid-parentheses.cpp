class Solution {
public:
    vector<string>ans;
    unordered_set<string>brackets; 
 
    int min_del(string& s)
    { 
        
        int ans = 0;
        int depth = 0;
        
        for(int i=0;i<s.size();i++)
        {             
            if(s[i]=='(')
            {
                if(depth<0)
                {
                    ans += abs(depth);
                    depth = 1;
                }
                else
                {
                    depth++;
                }
            }
            else if(s[i]==')')
            {
                depth--; 
            }
        }
        
        ans += abs(depth);
        return ans; 
        
    }
    void cnt(string &s, int i, string &curr,int depth,int del)
    {
        
        if(depth<0)
        {
            return ;
        }
        
        if(i>=s.size())
        {
            if(depth==0 && del==0)
            {
                brackets.insert(curr);
            }
            return ;
        }
        
        if(s[i]=='(')
        {
            if(del)
            {
                cnt(s,i+1,curr,depth,del-1);
            }
            curr+=s[i];
            cnt(s,i+1,curr,depth+1,del);
            curr.pop_back();
        }
        
        else if(s[i]==')')
        {
            if(del)
            {
                cnt(s,i+1,curr,depth,del-1);
            }
            curr+=s[i];
            cnt(s,i+1,curr,depth-1,del);
            curr.pop_back();
        }
        
        else
        {
            curr += s[i];
            cnt(s,i+1,curr,depth,del);
            curr.pop_back();
        } 
        
        return ;
        
    }
    vector<string> removeInvalidParentheses(string s) 
    {
        
        brackets.clear();
        ans.clear();
        
        int del = min_del(s);
        
        string curr = "";
        cnt(s,0,curr,0,del);
        
        for(string it : brackets)
        {
            ans.push_back(it);
        }
        
        return ans;
    }
};