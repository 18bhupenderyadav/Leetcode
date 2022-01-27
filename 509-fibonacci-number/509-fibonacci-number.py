class Solution:
    def fib(self, n: int) -> int:
        
        if(n==0):
            return 0
        
        memo=[0 for i in range(n+1)]
        def f(n):
            if(n<=2):
                return 1
            
            if n not in memo:
                memo[n]=f(n-1)+f(n-2)
            
            return memo[n]
        
        return f(n)
        