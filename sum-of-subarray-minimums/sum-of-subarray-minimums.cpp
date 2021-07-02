class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) 
    {
        
        int n = arr.size();
        
        vector<int>left(n,0),right(n,0); 
        
        stack<int>st;
        
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()]>arr[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                left[i] = st.top();
            }
            else
            {
                left[i] = -1;
            }
            st.push(i);
        }
        
        while(!st.empty())
        {
            st.pop();
        }
        
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()]>=arr[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                right[i] = st.top();
            }
            else
            {
                right[i] = n;
            }
            st.push(i);
        }
        
        long long int sum = 0;
        long long int mod = 1e9+7;
        
        for(int i=0;i<n;i++)
        {
            
            sum += ((i-left[i])%mod*(right[i]-i)%mod*(arr[i])%mod)%mod;
            sum %= mod;
        }
        
        return sum;
    }
};