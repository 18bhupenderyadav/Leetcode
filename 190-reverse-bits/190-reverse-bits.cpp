class Solution {
public:
    uint32_t reverseBits(uint32_t n) 
    {
        uint32_t ans = 0;
        string temp = "";
        
        while(n!=0)
        {
            // ans*=2;
            // ans += n%2;
            temp+= to_string(n%2);
            n/=2;
        }
        
        while(temp.size()!=32)
            temp+='0';
        
        for(int i=0;i<temp.size();i++)
        {
            ans*=2;
            ans+=temp[i]-'0';
            
        }
        
        return ans;
    }
};