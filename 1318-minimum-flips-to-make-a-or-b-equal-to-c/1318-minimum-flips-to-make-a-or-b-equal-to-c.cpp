class Solution {
public:
    int minFlips(int a, int b, int c) 
    {
        int ans = 0;
        int x = a|b;
        
        for(int i=0;i<32;i++)
        {
            int y = (1<<i);
            if((c&y))
            {
                if((y&x) == 0)
                {
                    ans++;
                }
            }
            else
            {
                if((y&x))
                {
                    if((a&y))
                        ans++;
                    if((b&y))
                        ans++;
                }
            }
        }
        
        return ans;
    }
};