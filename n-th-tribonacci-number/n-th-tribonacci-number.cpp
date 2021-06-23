class Solution {
public:
    int tribonacci(int n) 
    {
        int a,b,c,d;
        a=0;
        b=c=1;
        
        if(n<=2)
        {
            if(n<1)
                return 0;
            return 1;
        }
        
        n-=2;
        
        while(n--)
        {
            d=a+b+c;
            a=b;
            b=c;
            c=d;
        }
        
        return d;
    }
};