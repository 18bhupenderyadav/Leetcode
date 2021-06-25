class Solution {
public:
    string convertToBase7(int n) 
    {
        string ans="";
        
        int neg=0;
        if(n<0)
            neg++;
        n=abs(n);
        
        while(n!=0)
        {
            ans+=to_string(n%7);
            n/=7;
        }
        
        if(neg)
            ans+='-';
        
        if(ans.size()==0)
            ans+='0';
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};