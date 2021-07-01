class Solution {
public:
    string decodeString(string s) {
        
        stack<int>num;
        stack<char>st;
        
        string ans = "";
        
        int k = 0;
        
        for(int i=0;i<s.size();i++)
        {
            
            if(s[i]>='0' && s[i]<='9')
            {
                k *= 10;
                k += (s[i]-'0');
            
            }
            else
            {
                if(k!=0)
                {
                    num.push(k);
                    k = 0;
                }
                if(s[i]==']')
                {
                    
                    string temp = "";
                    while(st.top()!='[')
                    {
                        temp += st.top();
                        st.pop();
                    }
                    st.pop();
                    
                    reverse(temp.begin(),temp.end());
                    
                    int x = num.top();
                    num.pop();
                    
                    string curr = temp;
                    x--;
                    while(x--)
                    {
                        temp += curr;
                    }
                    
                    for(char c : temp)
                    {
                        st.push(c);
                    }
                    
                }
                else
                {
                    st.push(s[i]);
                }
            }
        }
        
        while(st.size())
        {
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
        
    }
};
