class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        
        stack<int>st;
        
        int curr = 0;
        int i =0;
        
        for(int i=0;i<pushed.size();i++)
        {
            st.push(pushed[i]);
            while(!st.empty() && curr<popped.size() && st.top()==popped[curr] )
            {
                st.pop();
                curr++;
            }
        }
        
        return (curr==popped.size());
    }
};
