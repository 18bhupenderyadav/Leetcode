class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        unsigned long int i,j,left,right,ans=0;
        i=0,j=0;
        unsigned long int n=s.length();
        unordered_set<char> st;
        while(i<n && j<n)
        {
            if(st.find(s[j])==st.end())
            {
                st.insert(s[j]);
                j++;
                ans=max(ans,st.size());
            }
            else
            {
                st.erase(s[i]);
                i++;
            }
        }
        return ans;
    }
};