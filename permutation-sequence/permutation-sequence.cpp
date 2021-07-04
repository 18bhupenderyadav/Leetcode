class Solution {
public:
    string getPermutation(int n, int k) 
    {
        
        vector<int>factorial(n+1,1);
        set<int>s;
        
        for(int i=1;i<=n;i++)
        {
            s.insert(i);
        } 
            
        int sum = 1;
        for(int i=1;i<=n;i++)
        {
            
            sum *= i;
            factorial[i] = sum; 
            
        }
        
        string ans = "";
        
        k--;
        
        for(int i=1;i<=n;i++)
        {
            
            int curr = k/factorial[n-i];
            
            auto it = s.begin();
            
            for(int j=0;j<curr;j++)
            {
                it++;
            }
            
            ans += *(it)+'0'; 
            s.erase(it);
            
            k -= curr*factorial[n-i]; 
        }
        
        return ans;
    }
};