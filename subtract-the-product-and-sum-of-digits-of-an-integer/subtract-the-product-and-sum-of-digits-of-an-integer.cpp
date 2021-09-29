class Solution {
public:
    int subtractProductAndSum(int n) 
    {
        string s=to_string(n);
        
        int pro=1,sum=0;
        
        for(int i=0;i<s.size();i++)
        {
            int dig=(int)(s[i] - '0');
            pro*=dig;
            sum+=dig; // sum=sum+dig
        }
//         0 1 2 ...  9 .. A B 
        // chars '2' -> (int)'2' -> ASCII 
        
        return pro-sum;
    }
};