class Solution {
public:
    int calPoints(vector<string>& ops) 
    {
        stack<int>s;
        
        for(int i=0;i<ops.size();i++)
        {
            if(ops[i]=="+")
            {
                int x = s.top();
                s.pop();
                int y = s.top();
                s.pop();
                s.push(y);
                s.push(x);
                s.push(x+y);
            }
            else if(ops[i]=="C")
            {
                s.pop();
            }
            else if(ops[i]=="D")
            {
                s.push(2*s.top());
                
            }
            else
            {
                int x = stoi(ops[i]);
                s.push(x);
            }
        }
        
        int ans = 0;
        while(s.size())
        {
            ans += s.top();
            s.pop();
        }
        return ans;
    }
};