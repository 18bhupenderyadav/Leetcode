class Solution:       
    def climbStairs(self, n: int) -> int:
        @lru_cache(50)
        def dp(n):
            if(n==0):
                return 1
            if(n==1):
                return 1
            return dp(n-1)+dp(n-2)
        
        return dp(n)