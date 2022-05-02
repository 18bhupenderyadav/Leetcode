class Solution {
public:
    long long int lcm(int x,int y)
    {
        return (long long)x*(long long)y/__gcd(x,y);
    }
    vector<int> replaceNonCoprimes(vector<int>& ar) 
    {
        stack<int> st;
        
        st.push(ar[0]);
        
        for(int i=1;i<ar.size();i++)
        {
            int x = ar[i];
            while(st.size()>0 && __gcd(x,st.top())>1)
            {
                int y = st.top();
                st.pop();
                x = lcm(x,y);
            }
            st.push(x);
        }
        
        vector<int> ans;
        
        while(st.size()>0)
        {
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};